[top]
components : BS5Port1@BS5Port1 UE3@UE3 UE4@UE4
in : In1 
in : In2
in : In3 
out : Out1 
out : Out2
out : Out3 

Link : In1 In3@BS5Port1
Link : In2 In4@BS5Port1
Link : In3 In5@BS5Port1
Link : Out1@BS5Port1 In@UE3
Link : Out2@BS5Port1 In@UE4
Link : Out@UE3 In1@BS5Port1
Link : Out@UE4 In2@BS5Port1
Link : Out3@BS5Port1 Out1
Link : Out4@BS5Port1 Out2
Link : Out5@BS5Port1 Out3
