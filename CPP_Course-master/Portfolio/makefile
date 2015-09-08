Portfolio_object = Portfolio.o Read_Calculate_Method.o 
Markowitz_object = Markowitz.o Markowitz_Method.o Read_Calculate_Method.o Back_Test_Method.o RM_Method.o 
all : Portfolio Markowitz
Portfolio : $(Portfolio_object)
	g++ -o Portfolio $(Portfolio_object)
Markowitz : $(Markowitz_object)
	g++ -o Markowitz $(Markowitz_object)
Portfolio : Portfolio.cpp
Markowitz : Markowitz.cpp
Read_Calculate_Method : Read_Calculate_Method.o  
Markowitz_Method : Markowitz_Method.o
Back_Test_Method : Back_Test_Method.o
RM_Method : RM_Method.o
