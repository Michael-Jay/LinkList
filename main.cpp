/*************************************************************************
> File Name: main.cpp
> Author: Michael Jay
> mail: xuchuanwork@foxmail.com
> Created Time: 2016年07月13日 星期三 16时24分39秒
> Function: 
 ************************************************************************/

#include "LinkList.h"
#include <iostream>
using namespace std;

void fun(LinkList* test);

int main(int argc, char* argv[])
{

	LinkList test;	
	test.createHead();
	test.init();

	fun(&test);

	for(int i =1; i<10; i++){
		test.insert(i, 10* i);
	}
	fun(&test);
	
	cout<< "after insert...."<<endl;
	test.insert(10, 1314);
	fun(&test);

	cout<< "after delete.5.."<<endl;
	test.delPos(5);
	fun(&test);
	
	cout<< "after delete 30..."<<endl;
	test.delData(30);
	fun(&test);

	cout<< "after clean..."<<endl;
	test.clean();
	fun(&test);

	return 0;
}

void fun(LinkList* test){

	if( test->isEmpty() )
		cout<< "test is empty." << endl;
	else{
		cout << "test has " << test->getLength() << "elements"<< endl;
		test->show();
	}
}
