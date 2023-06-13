 /**********************************************************
 *
 *  DESCRIPTION: Atomic Model Base Station with 3 Port (BS3)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 10/12/2012
 *
 **********************************************************/

 #include "BS3Port1.h"            // base header
 #include "message.h"       // class ExternalMessage, InternalMessage

 BS3Port1::BS3Port1( const std::string &name )
 : Atomic( name )
 , In1( addInputPort( "In1" ) )
 , In2( addInputPort( "In2" ) )
 , In3( addInputPort( "In3" ) )
 , Out1( addInputPort( "Out1" ) )
 , Out2( addInputPort( "Out2" ) )
 , Out3( addInputPort( "Out3" ) )
 , ProcessTime (00,00,00,10)
 {
 }

 Model &BS3Port1::initFunction()
  {
    state = Idle;	// idle
    passivate();
	return *this ;
  }

 Model &BS3Port1::externalFunction( const ExternalMessage &msg )
  {
	Temp = msg.value();
	Temp = Temp % 2;
	if (Temp == 0)                    // This is Traffic Packet from Src to Des then forward it for Des
	   {
		 Temp = msg.value();
		 PortName = (Temp / 10000) % 10;   //Ex: ((120110 / 10000) % 10) ==> (12 % 10) ==> 2
	   }
	 else                                       //This is Ack Pack from Des to Src then forward it for Src
	     {
		   Temp = msg.value();
		   PortName = Temp / 100000;       //Ex: 120111 / 100000 = 1
	     }
	PackNum = msg.value();
	state = RecPack;
	holdIn(Atomic::active, ProcessTime);
    return *this;
  }

 Model &BS3Port1::internalFunction( const InternalMessage & )
 {
	if (state == RecPack)
	   {
		 state = Idle;
		 passivate();
       }
    return *this;
 }

 Model &BS3Port1::outputFunction( const InternalMessage &msg )
 {
	if (state == RecPack)
	   {
		 if (PortName == 1) sendOutput( msg.time(), Out1, PackNum) ;
		   else if (PortName == 2) sendOutput( msg.time(), Out3, PackNum) ;
		        else if ((PortName == 9) || (PortName == 3) || (PortName == 4)) sendOutput( msg.time(), Out2, PackNum) ;
	   }
	return *this ;
 }

BS3Port1::~BS3Port1()
{
}
