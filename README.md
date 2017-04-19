# ppl-assignment-ritikamotwani
ppl-assignment-ritikamotwani created by GitHub Classroom
##Ritika Motwani - IIT2015096
###Language Used
```
C++
```
```
The project was made using Linux Ubuntu and the documentation was made through doxygen and latex with the class diagram
converted to pdf format
```
### Files
```
.h files are the header files made and .cpp contain functions
.txt files contain the output,the randomly generated list of the input parameters
.pdf is for the documentation and Class diagram
```
### For Execution 
```

To  execute Question1 and Question2:
      g++ -c girl.cpp
      g++ -c boy.cpp
      g++ -c couple.cpp
      g++ -c make_pair.cpp
      g++ -c boy_list.cpp
      g++ -c girl_list.cpp
      g++ -c gift_list.cpp
      ar rvs ritika_file.a boy.o couple.o girl.o boy_list.o gift_list.o girl_list.o make_pair.o
 Then 
 g++ ques1.cpp ritika_file.a
 ./a.out
 g++ ques2_main.cpp ritika_file.a
 ./a.out
 and input the value of k
 Output will be there in couple.txt and happ_comp_gift.

For all the questions from three to ten 
		The List of couples , randomly generated girls, boys and gifts should exist That Is 
		#### Question1 should be complied once before following the execution steps of any of the below questions. 
 Question3 :
 	For compilation-    g++ ques3.cpp inh_pair.cpp couple.cpp boy.cpp girl.cpp Fill.cpp
 	For execution- ./a.out
 	Give the value of k as input.
 	Output-  happ_comp.txt

 Question4 :
 	For compilation- g++ ques4.cpp inh_pair.cpp couple.cpp boy.cpp girl.cpp Fill.cpp  
 	For execution-   ./a.out
 	Give the value of k as input.
 	Output- new_couple.txt

 Question5  :
 	For compilation-    g++ ques5.cpp girl.cpp boy.cpp couple.cpp new_order_couple.h 
 	Execution-  ./a.out
 	Output-   order_couple.txt
 	For k happy couples compile and execute question2.

 Question6 :
 	For compilation-   g++ ques6.cpp inh_pair.cpp couple.cpp boy.cpp girl.cpp Fill.cpp t_days.cpp
 	Execution- ./a.out
 	Output- ques6.txt

 Question7 :
 	For compilation-   g++ ques7.cpp inh_pair.cpp couple.cpp boy.cpp girl.cpp Fill.cpp Sorted_Class.cpp hash.cpp
 	Execution-  ./a.out
 	Output-  Three_Ways.txt

 Question8 :
 	For compilation-  g++ ques8.cpp make_pair.cpp NewWay.cpp girl.cpp boy.cpp couple.cpp 
 	For execution-  ./a.out
 	Output-  happ_comp_gift

Question9 :
      For Compilation-  g++ ques9.cpp secondary.cpp girl.cpp boy.cpp
      Execution- ./a.out
      Output-  ques9.txt and ques9_gifts.txt
Question 11 :
	Exception Handling shown in all questions 
	Run all the questions as the commands are written for them 

 ```
      
