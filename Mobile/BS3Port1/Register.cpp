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

 #include "BS3Port1.h"

 void MainSimulator::registerNewAtomics()
 {
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BS3Port1>() , "BS3Port1" ) ;
 }
