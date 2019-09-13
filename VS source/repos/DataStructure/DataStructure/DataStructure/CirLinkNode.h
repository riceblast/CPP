#ifndef CIRLINKNODE_H
#define CIRLINKNODE_H
#include "LinkNode.h"
#include "DLinkNode.h"

typedef int ElemType;

//��2.11(P60)
int count(LinkNode* L, ElemType m) {
	LinkNode* p; p = L;
	int j = 0;//���ڼ���
	while (p->next!= L) {
		p = p->next;
		if (p->data == m)
			 j += 1;
	}
	return j; 
}



//��2.12(P60)
bool deletem(DLinkNode* L, ElemType m) {
	DLinkNode* p, * q;
	p = L->next;
	while (p != L) {
		if (p->data == m) {//����ҵ��ˣ�����ɾ�����˳�ѭ��
			q = p;
			p->prior->next = p->next;
			p->next->prior = p->prior;
			free(q);
			return true;
		}
		p = p->next;
	}
	return false;//���ѭ��������ûɾ���ɹ����򷵻�false
}



//��2.13(P60)
bool Symm(DLinkNode* L) {
	DLinkNode* p, * q;//һ����ǰ�����ң�һ���Ӻ���ǰ��
	p = L->next;//p���׽������
	q = L->prior;//q��β�������
	while (true) {
		if (p->data != q->data)//��Ӧ��ֵ��ͬ������false
			return false;
		if (p == q || p == q->prior)
			break;
		p = p->next;
		q = q->prior;
	}
	return true;
}
#endif // !CIRLINKNODE_H