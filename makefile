target: main.o Customer.o Node.o SinglyLL.o
	g++ -o main main.o Customer.o Node.o SinglyLL.o

main.o: main.cpp Customer.cpp Customer.h Node.cpp Node.h SinglyLL.cpp SinglyLL.h
	g++ -c main.cpp Customer.h Customer.cpp Node.h Node.cpp SinglyLL.h SinglyLL.cpp

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp Customer.h

Node.o: Node.cpp Node.h Customer.cpp Customer.h
	g++ -c Node.cpp Node.h Customer.cpp Customer.h

SinglyLL.o: SinglyLL.cpp SinglyLL.h Node.cpp Node.h
	g++ -c SinglyLL.cpp Singly.h Node.cpp Node.h


run: 
	./main


clean: 
	rm *.o
	rm *.gch
	rm main

valgrind: main.o Customer.o Node.o SinglyLL.o
	g++ -o main -g main.o Customer.o Node.o SinglyLL.o 
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main


