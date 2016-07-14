#include "LinkList.h"
#include <iostream>

void LinkList::createHead()	//利用头插法创建
{
	head->init();		
}

void LinkList::Node::init(dtype dat, Node* nxt)
{
	data = dat;
	next = nxt;
}

void LinkList::init()
{
	head->data = 0;
	head->next = 0;
}

bool LinkList::isEmpty()
{	
	return (getLength() == 0) ? true: false;
}

void LinkList::clean()
{
	using namespace std;
	if(this->isEmpty()){
		cout<<"List is already clear..." << endl;
		return;
	}else{
		cout<< "cleaning..."<< endl;
	}

	int len = getLength();
	for(int i = 1; i<= len; i++)
	{
		cout << "cleaning : " << getPos(1) << endl;
		delPos(1);

	}
	cout<<"List cleaned complet." << endl;
	return;
}

int LinkList::getLength()
{
	int len = 0;
	Node* tmpNode = head->next;
	while(tmpNode != 0){
		len ++;
		tmpNode = tmpNode->next;
	}
	return len;
}

void LinkList::insert(int pos, dtype  addata)
{
	using namespace std;
	if(pos<1 || (pos > (getLength()+1)) ){
		cout<<"insert: Invalid Position." << endl;
		return ;
	}
	int count = 0;
	Node* addNode = new Node;	//要插入的数据指针
	Node* tmpNode;	//保存要插入位置的前一个节点指针
	tmpNode = head;
	while(tmpNode != 0){
		if(++count == pos)
			break;
		tmpNode = tmpNode->next;
	}

	addNode->init(addata, 0);
	addNode->next = tmpNode->next;
	tmpNode->next = addNode;
	tmpNode = 0;
}



void LinkList::delData(dtype deldata)
{
	using namespace std;
	Node* tmpNode = head;
	int pos = 0;
	while((tmpNode->data != deldata) && (tmpNode != 0))
	{
		pos++;
		tmpNode = tmpNode->next;
	}

	delPos(pos);
	tmpNode =  0;
}

dtype LinkList::getPos(int pos)
{
	using namespace std;
	if(pos<1 || pos>getLength() ){
		cout<<"insert: Invalid Position." << endl;
		return -1;
	}
	int count = 0;
	Node* tmpNode;
	tmpNode = head;
	while(tmpNode != 0){
		if(count++ == pos)
			break;
		tmpNode = tmpNode->next;
	}
	return tmpNode->data;

}

void LinkList::delPos(int pos)
{
	using namespace std;
	//只能删除第1个到最后一个
	if(pos<1 || (pos > getLength()) ){
		cout<<"delPos: Invalid Position." << endl;
		return ;
	}

	int count = 0;
	Node* delNode;	//要删除的数据指针
	Node* tmpNode;	//保存要删除位置的前一个节点指针
	tmpNode = head;
	while(tmpNode != 0){
		if(++count == pos)
			break;
		tmpNode = tmpNode->next;
	}

	delNode = tmpNode->next;
	tmpNode->next = delNode->next;
	delNode->next = 0;
	delete delNode;
	delNode = 0;
}
void LinkList::show()
{
	using namespace std;
	if( isEmpty()){
		cout << "LinkList is Empty." << endl;
		return;
	}
	using namespace std;
	Node* tmpNode = head->next;
	cout<< "LinkList: "<<endl;
	while(tmpNode != 0){
		cout<< tmpNode->data <<", ";
		tmpNode = tmpNode->next;
	}
	cout << endl;
}
