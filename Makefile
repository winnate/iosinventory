all: hello
	
hello: main.o classfunctions.o functions.o
		g++ main.o classfunctions.o functions.o -o hello
		
main.o: main.cpp 
		g++ -c main.cpp
		
classfunctions.o: classfunctions.cpp
		g++ -c classfunctions.cpp
		
functions.o: functions.cpp
		g++ -c functions.cpp
		
clean:
		rm -rf *o hello