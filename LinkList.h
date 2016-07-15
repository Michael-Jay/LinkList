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


class LinkList{

public:
	LinkList(dtype dat);
	~LinkList();
	bool isEmpty() const;
	int getLength() const;
	void insert(int pos, dtype  addata);
	void delPos(int pos);
	void delData(dtype deldata);
	dtype getPos(int pos);
	void show() const;

private:

	class Node{
		private:
			dtype m_data;
			Node* m_next;
		public:
			Node(dtype dat =0, Node* nxt = 0);
			~Node();
	};

	Node* m_head;

};


#endif
