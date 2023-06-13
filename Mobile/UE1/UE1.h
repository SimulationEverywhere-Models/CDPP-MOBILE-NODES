 /***********************************************
 *
 *  DESCRIPTION: Atomic Model User Equipment (UE)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 10/12/2012
 *
 ***********************************************/

 #ifndef __UE1_H
 #define __UE1_H

 #include "atomic.h"   // class Atomic
 #include "string.h"	  // class String

 class UE1 : public Atomic
 {
   public:
	       UE1 ( const std::string &name = "UE1" );  //Default constructor
	       virtual std::string className() const {  return "UE1" ;}
	       ~UE1();

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

#endif   //__UE1_H
