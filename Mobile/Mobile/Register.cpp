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

 #include "BS5Port1.h"    //New libraries Should be copied.
 #include "BS3Port1.h"
 #include "BS3Port2.h"
 #include "UE1.h"
 #include "UE2.h"
 #include "UE3.h"
 #include "UE4.h"


 void MainSimulator::registerNewAtomics()
 {
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BS5Port1>() , "BS5Port1" ) ;  // New Models Regsiteraiton
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BS3Port1>() , "BS3Port1" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BS3Port2>() , "BS3Port2" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UE1>() , "UE1" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UE2>() , "UE2" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UE3>() , "UE3" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UE4>() , "UE4" ) ;
 }
