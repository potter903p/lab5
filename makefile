Lab5:HugeInt.o main.cpp
	g++ -o Lab5 HugeInt.o main.cpp 
HugeInt.o:HugeInt.h HugeInt.cpp
	g++ -c HugeInt.cpp
