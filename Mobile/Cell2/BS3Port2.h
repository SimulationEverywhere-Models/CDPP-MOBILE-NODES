 /**********************************************************
 *
 *  DESCRIPTION: Atomic Model Base Station with 3 Port (BS3)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 10/12/2012
 *
 **********************************************************/

 #ifndef __BS3Port2_H
 #define __BS3Port2_H

 #include "atomic.h"      // class Atomic
 #include "string.h"	  // class String

 class BS3Port2 : public Atomic
 {
   public:
	       BS3Port2( const std::string &name = "BS3Port2" );  //Default constructor
	       virtual std::string className() const {  return "BS3Port2" ;}
	       ~BS3Port2();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	        const Port &In1,&In2,&In3;
	        Port &Out1,&Out2,&Out3;
	        Time ProcessTime;
	        int PortName;
	        int PackNum;
	        int Temp;
         	enum State{
			            Idle,       //initial state
			            RecPack,    //Receiving Traffic Packet
		              };
		    State state;
 };

#endif   //__BS3Port2_H
