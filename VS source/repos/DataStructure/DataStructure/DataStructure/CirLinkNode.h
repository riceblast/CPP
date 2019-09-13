#ifndef CIRLINKNODE_H
#define CIRLINKNODE_H
#include "LinkNode.h"
#include "DLinkNode.h"

typedef int ElemType;

//例2.11(P60)
int count(LinkNode* L, ElemType m) {
	LinkNode* p; p = L;
	int j = 0;//用于计数
	while (p->next!= L) {
		p = p->next;
		if (p->data == m)
			 j += 1;
	}
	return j; 
}



//例2.12(P60)
bool deletem(DLinkNode* L, ElemType m) {
	DLinkNode* p, * q;
	p = L->next;
	while (p != L) {
		if (p->data == m) {//如果找到了，则将其删除并退出循环
			q = p;
			p->prior->next = p->next;
			p->next->prior = p->prior;
			free(q);
			return true;
		}
		p = p->next;
	}
	return false;//如果循环结束还没删除成功，则返回false
}



//例2.13(P60)
bool Symm(DLinkNode* L) {
	DLinkNode* p, * q;//一个从前往后找，一个从后往前找
	p = L->next;//p从首结点往右
	q = L->prior;//q从尾结点往左
	while (true) {
		if (p->data != q->data)//对应点值不同，返回false
			return false;
		if (p == q || p == q->prior)
			break;
		p = p->next;
		q = q->prior;
	}
	return true;
}
#endif // !CIRLINKNODE_H