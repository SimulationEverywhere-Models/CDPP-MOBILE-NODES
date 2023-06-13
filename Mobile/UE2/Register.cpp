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

 #include "UE2.h"

 void MainSimulator::registerNewAtomics()
 {
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UE2>() , "UE2" ) ;
 }
