#include "LinkList.h"
#include <iostream>


/*father class*/
LinkList::LinkList(){
	m_head = new Node(0,0);
}

LinkList::LinkList(dtype dat){
	m_head = new Node(dat,0);
}

LinkList::~LinkList(){
	delete m_head;
}

/*child class*/
LinkList::Node::Node(dtype dat, Node* nxt)
{
	m_data = dat;
	m_next = nxt;
}
		
LinkList::Node::~Node()
{

}


bool LinkList::isEmpty() const
{
	return (getLength() == 0) ? true: false;
}

int LinkList::getLength() const
{
	int len = 0;
	Node* tmpNode = m_head->m_next;
	while(tmpNode != 0){
		len ++;
		tmpNode = tmpNode->m_next;
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
	tmpNode = m_head;
	while(tmpNode != 0){
		if(++count == pos)
			break;
		tmpNode = tmpNode->m_next;
	}

	addNode->m_data = addata;
	addNode->m_next = tmpNode->m_next;
	tmpNode->m_next = addNode;
	tmpNode = 0;
}



void LinkList::delData(dtype deldata)
{
	using namespace std;
	Node* tmpNode = m_head;
	int pos = 0;
	while((tmpNode->m_data != deldata) && (tmpNode != 0))
	{
		pos++;
		tmpNode = tmpNode->m_next;
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
	tmpNode = m_head;
	while(tmpNode != 0){
		if(count++ == pos)
			break;
		tmpNode = tmpNode->m_next;
	}
	return tmpNode->m_data;

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
	tmpNode = m_head;
	while(tmpNode != 0){
		if(++count == pos)
			break;
		tmpNode = tmpNode->m_next;
	}

	delNode = tmpNode->m_next;
	tmpNode->m_next = delNode->m_next;
	delNode->m_next = 0;
	delete delNode;
	delNode = 0;
}
void LinkList::show() const
{
	using namespace std;
	if( isEmpty()){
		cout << "LinkList is Empty." << endl;
		return;
	}

	Node* tmpNode = m_head->m_next;
	cout<< "LinkList: "<<endl;
	while(tmpNode != 0){
		cout<< tmpNode->m_data <<", ";
		tmpNode = tmpNode->m_next;
	}
	cout << endl;
}
