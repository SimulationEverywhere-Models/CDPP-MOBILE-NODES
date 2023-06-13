 /***********************************************
 *
 *  DESCRIPTION: Atomic Model User Equipment (UE)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 10/12/2012
 *
 ***********************************************/

 #ifndef __UE2_H
 #define __UE2_H

 #include "atomic.h"   // class Atomic
 #include "string.h"	  // class String

 class UE2 : public Atomic
 {
   public:
	       UE2 ( const std::string &name = "UE2" );  //Default constructor
	       virtual std::string className() const {  return "UE2" ;}
	       ~UE2();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	        const Port &In;
	        Port &Out;
	        Time ProcessTime;
	        Time GenerateTime;
         	int SentPacketNum;
         	int ReceivedPacketNum;
         	int AckSent;
	        int AckReceived;
	        int Temp;
         	enum State{
			            Idle,       //initial state
			            SendPack,   //Sending Packet
			            RecPack,    //Receiving Traffic Packet
			            RecAck,     //Receiving Ack Packet for sent Packet.
		              };
		    State state;
 };

#endif   //__UE2_H
