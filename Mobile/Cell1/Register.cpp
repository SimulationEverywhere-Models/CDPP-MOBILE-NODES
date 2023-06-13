 /**********************************************
 *
 *  DESCRIPTION: Simulator::registerNewAtomics()
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 10/12/2012
 *
 **********************************************/

 #include <modeladm.h>
 #include <mainsimu.h>

 #include "BS3Port1.h"    //New libraries Should be copied.
 #include "UE1.h"


 void MainSimulator::registerNewAtomics()
 {
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BS3Port1>() , "BS3Port1" ) ;  // New Models Regsiteraiton
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UE1>() , "UE1" ) ;
 }
