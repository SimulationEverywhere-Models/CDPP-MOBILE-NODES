[top]
components : Cell1 Cell2 Cell3
in : In
out : Out

Link : In In4@BS5Port1
Link : Out3@BS5Port1 Out
Link : Out4@BS5Port1 In2@BS3Port2
Link : Out5@BS5Port1 In2@BS3Port1
Link : Out3@BS3Port1 In3@BS3Port2
Link : Out2@BS3Port1 In5@BS5Port1
Link : Out2@BS3Port2 In3@BS5Port1
Link : Out3@BS3Port2 In3@BS3Port1


[Cell1]
components : BS3Port1@BS3Port1 UE1@UE1
in : In1 
in : In2 
out : Out1 
out : Out2 

Link : In1 In3@BS3Port1
Link : In2 In2@BS3Port1
Link : Out@UE1 In1@BS3Port1
Link : Out1@BS3Port1 In@UE1
Link : Out2@BS3Port1 Out2
Link : Out3@BS3Port1 Out1

[Cell2]
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

[Cell3]
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
