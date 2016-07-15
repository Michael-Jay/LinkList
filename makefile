main : main.o LinkList.o
	g++ main.o LinkList.o -o test

main.o : main.cpp
	g++ -c main.cpp -o main.o

LinkList.o : LinkList.cpp
	g++ -c LinkList.cpp -o  LinkList.o

##LinkList.ho: LinkList.h
##	g++ -c LinkList.h -o LinkList.ho

LinkList.o: LinkList.h

clean :
	rm *.o
