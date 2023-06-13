 /***********************************************
 *
 *  DESCRIPTION: Atomic Model User Equipment (UE)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 10/12/2012
 *
 ***********************************************/

 #include "UE4.h"
 #include "message.h"       // InternalMessage ....

 UE4::UE4( const std::string &name ) : Atomic( name )
 , In( addInputPort( "In" ) )
 , Out( addInputPort( "Out" ) )
 , ProcessTime (00,00,00,10)
 , GenerateTime(00,00,00,50)
 {
 }

 Model &UE4::initFunction()
  {
    state = Idle;	// idle
    SentPacketNum ++;
    holdIn(Atomic::active, 0);  //Programmed to have an instantaneous internal transition.
	return *this ;
  }

 Model &UE4::externalFunction( const ExternalMessage &msg )
  {
	if (msg.port() == In )//&& state == Idle)
	   {
		 Temp = msg.value();
		 Temp = Temp % 2;
		 if (Temp == 0)
			{
			  state = RecPack;  // If the received packet is a Traffic Packet
			  Temp = msg.value()+1;                 //Ack for received packet.
			}
		  else
			  {
			    state = RecAck;           // If the received packet is a Ack Packet
			    Temp = msg.value() - 1;
			    Temp = Temp % 10000;
			    Temp = Temp / 2;
			  }

		 holdIn(Atomic::active, ProcessTime);
	   }
		return *this;
  }

 Model &UE4::outputFunction( const InternalMessage &msg )
 {
	if (state == RecPack)
	   {
		 sendOutput( msg.time(), Out, Temp) ;  //Send ACK to source of received packet.
	   }
	   else if (state == RecAck)
		       {
		         sendOutput( msg.time(), Out, Temp) ;  //Send out the real packet number of received Ack
		       }
	        else if (state == SendPack)
	                {
	        	      sendOutput( msg.time(), Out, Temp) ;  //Send Packet for Destination (In this sample Des is UE2)
	                }
	return *this ;
 }

 Model &UE4::internalFunction( const InternalMessage & )
 {
	switch (state){
				    case Idle:
				    	       Temp = 430000 + (SentPacketNum * 2);  // Src = 4 , Des = 3 ==> 430000
				    	       state = SendPack;
					           holdIn( Atomic::active, GenerateTime);
					           break;

				    case RecPack:
				    	          ReceivedPacketNum ++;
				    	          state = Idle;
					              break;

				    case RecAck:
					              state = Idle;
					              break;

			    	case SendPack:
			    		           SentPacketNum ++;
			    		           state = Idle;
					               break;
        		  }
    return *this;
 }

UE4::~UE4()
{
}
