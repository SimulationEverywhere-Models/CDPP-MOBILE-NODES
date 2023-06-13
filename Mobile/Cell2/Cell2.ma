[top]
components : BS3Port2@BS3Port2 UE2@UE2
in : In1 
in : In2 
out : Out1 
out : Out2 

Link : In1 In2@BS3Port2
Link : In2 In3@BS3Port2
Link : Out@UE2 In1@BS3Port2
Link : Out1@BS3Port2 In@UE2
Link : Out2@BS3Port2 Out1
Link : Out3@BS3Port2 Out2

