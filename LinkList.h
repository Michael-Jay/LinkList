/*************************************************************************
> File Name: LinkList.h
> Author: Michael Jay
> mail: xuchuanwork@foxmail.com
> Created Time: 2016年07月13日 星期三 13时28分04秒
> Function: 
 ************************************************************************/

#ifndef _MY_LINK_LIST_H
#define _MY_LINK_LIST_H

typedef int dtype;

struct LinkList{

	struct Node{
		dtype data;
		Node* next;
		void init(dtype data=0, Node* nxt=0);
	}*head;

	void init();	//初始化为空head=0
	bool isEmpty();
	void clean();
	void createHead();	//利用头插法创建
	void createTail();
	//(LinkList::struct Node*) getPointPos(int pos);	//找到指定位置的前一个元素的指针，方便插入
	int getLength();
	void insert(int pos, dtype  addata);
	void delPos(int pos);
	void delData(dtype deldata);
	dtype getPos(int pos);
	void show();
};


#endif
