 /**********************************************************
 *
 *  DESCRIPTION: Atomic Model Base Station with 5 Port (BS5)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 10/12/2012
 *
 **********************************************************/

 #ifndef __BS5Port1_H
 #define __BS5Port1_H

 #include "atomic.h"      // class Atomic
 #include "string.h"	  // class String

 class BS5Port1 : public Atomic
 {
   public:
	       BS5Port1( const std::string &name = "BS5Port1" );  //Default constructor
	       virtual std::string className() const {  return "BS5Port1" ;}
	       ~BS5Port1();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	        const Port &In1,&In2,&In3,&In4,&In5;
	        Port &Out1,&Out2,&Out3,&Out4,&Out5;
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

#endif   //__BS5Port1_H
