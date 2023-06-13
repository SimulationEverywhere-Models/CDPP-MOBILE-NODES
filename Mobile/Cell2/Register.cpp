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

 #include "BS3Port2.h"    //New libraries Should be copied.
 #include "UE2.h"


 void MainSimulator::registerNewAtomics()
 {
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BS3Port2>() , "BS3Port2" ) ;  // New Models Regsiteraiton
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UE2>() , "UE2" ) ;
 }
