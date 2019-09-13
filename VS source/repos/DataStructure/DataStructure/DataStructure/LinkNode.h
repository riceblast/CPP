#ifndef LINKNODE_H
#define LINKNODE_H
#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	LNode* next;
} LinkNode;



//����Ԫ�أ�ͷ�巨
void InsertElement(LinkNode*& L, int a[], int n) {
	LinkNode* s;//����һ������ָ�����ڵ��ָ�룬�������봦��ǰһ������ָ��
	for (int i = 0; i <= n - 1; i += 1) {
		s = (LinkNode*)malloc(sizeof(LinkNode));//Ϊ�������Ԫ���½����
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}



void CreatListF(LinkNode*& L, int a[], int n) {
	L = (LinkNode*)malloc(sizeof(LNode));//�½���һ���ձ�Lָ��ͷ�ڵ�
	L->next= NULL;
	//����ȡ�������е�ֵ�����뵽�ڵ���
	InsertElement(L, a, n);//���ò��뷽��
	}



//����Ԫ�أ�β�巨
void CreatListR(LinkNode*& L, int a[], int n) {
	L = (LinkNode*)malloc(sizeof(LNode));//�½���һ���ձ�Lָ��ͷ�ڵ�
	L->next = NULL;
	LinkNode* r = L;//����һ��βָ��r������ָ�����Ԫ�ص�ǰһ�����
	LinkNode* s;//����һ��ָ�룬ָ�򱻲����Ԫ��
	for (int i = 0; i <= n - 1; i += 1) {
		s = (LinkNode*)malloc(sizeof(LinkNode));//�����½��
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;//β����ָ��ָ��null
}



//ɾ�����Ա�
void DestroyList(LinkNode* L) {
	LinkNode* pre = L;//ͷָ��
	LinkNode* head = L->next;//��ָ��
	while (head != NULL) {
		free(pre);
		pre = head;
		head = head->next;
	}

	free(pre);
}



//����������(���ݽ�����)
int ListLength(LinkNode* L) {
	LinkNode* p = L;
	int n = 0;
	while (p->next != NULL) {
		n += 1;
		p = p->next;
	}
	return n;
}



//�������������
void DispList(LinkNode* L) {
	LinkNode* p = L->next;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->next;
	}
}



//��������Ԫ��
bool ListInsert(LinkNode* L, int i,ElemType d) {
	int j = 0;//��ͷ��㿪ʼ��¼��ţ�ͷ�����Ϊ0
	LinkNode* temp = L;
	if (i <= 0)
		return false;//�Ϸ��Է���
	for (j; j < i - 1 && temp != NULL; j += 1) {
		temp = temp->next;
	}//forѭ��������tempָ��Ҫôָ��i-1����㣬Ҫôָ��Ľ��Ϊ�գ��޷�����Ԫ��
	if (temp == NULL) {
		return false;
	}
	//����Ԫ��
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = d;
	s->next = temp->next;
	temp->next = s;
	return true;
}



//����ɾ��
bool ListDelete(LinkNode* L, int i, ElemType& e) {
	if (i <= 0)
		return false;
	LinkNode* p = L;
	int count = 0;//ͷ�����Ϊ0
	while (count < i - 1 && p != NULL) {
		count += 1;
		p = p->next;
	}
	if (p == NULL)
		return false;
	LinkNode* temp = p->next;//ʹ��һ����ʱָ��ָ�򼴽���ɾ���Ľ��
	if (temp == NULL)
		return false;//���������ɾ���Ľ��ΪNULL��ͬ������ɾ��ʧ��444 
	e = temp->data;
	p->next = temp->next;
	free(temp); 
	return true;
}



//����2.6��P52��
void split(LinkNode* L, LinkNode*& L1, LinkNode*& L2) {
	LinkNode* r1,//r1ָ��L1��β���
		*p,//����ͷ�巨��β�巨
		*q;//������ͷ�巨ʱ��ʱ�洢����ֹ��㶪ʧ
	L1 = L;//L��ͷ������L1��ͷ���
	r1 = L1;
	L2 = (LinkNode*)malloc(sizeof(LinkNode));//����L2ͷ���
	L2->next = NULL;
	p = L->next;
	while (p == NULL) {
		//β�巨
		r1->next = p;//p��ʱΪai
		r1 = p;  //r1�ƶ���β���

		//β�巨��������ʼͷ�巨
		p = p->next;//p��ʱΪbi
		q = p->next;//����ͷ�巨��ı�p->next������q���洢����ֹ��㶪ʧ
		p->next = L2->next;
		L2->next = p;
		p = q;//��p���õ���һ��ai����ʼ��һ��ѭ��
	}
	r1->next = NULL;
}



//����2.7��P53��
void DelMaxNode(LinkNode* L) {
	LinkNode* pre, * p, * maxpre, * maxp;
	pre = L;
	p = L->next;
	maxpre = pre;
	maxp = p;
	while (p != NULL) {//�ҵ�maxp
		if (maxp->data < p->data) {
			maxp = p;
			maxpre = pre;
		}
		pre = pre->next;
		p = p->next;
	}
	//ɾ��maxp
	maxpre->next = maxp->next;
	free(maxp);
}



//��2.8(p53)
void Sort(LinkNode* L) {
	//���Ƚ����Ա��ɣ�ͷ���+�׽ڵ㣩��ʣ��Ԫ����������
	LinkNode* pre ;//pre��������ǰ�����
	LinkNode* p = L->next->next;//pָ�����Ա���һ���ֵĵ�һ��Ԫ��
	LinkNode* q;//���ڴ洢p�ĺ�̽��
	L->next->next = NULL;//�����Ա�Ͽ�
	//��Ԫ��������뵽����
	while (p != NULL) {
		pre = L;//���봦��ǰ�����ÿ�ζ�Ҫ��ͷ��㿪ʼ����
		while (pre->next!=NULL &&  pre->next->data < p->data) {
			pre = pre->next;
		}//ѭ��������pre���ǲ��봦��ǰ�����
		//ǰ�巨
		q = p->next;//��ֹp�ĺ�̽ڵ㶪ʧ
		p->next = pre->next; 
		pre->next = p;
		p = q;
	}

}

#endif