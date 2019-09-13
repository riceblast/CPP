#ifndef  DINKNODE_H
#define DLINKNODE_H
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;//���ڴ������
	DNode* prior;//ָ��ǰ����ָ��
	DNode* next;//ָ���̵�ָ��
}DLinkNode;



//����˫������ͷ�巨
void CreateDListF(DLinkNode* &L, ElemType a[], int n){
	L = (DLinkNode*)malloc(sizeof(DLinkNode));//����ͷָ��
	//��ʼ��ͷָ��,ǰ��ָ����Ϊ��
	L->next = NULL;
	L->prior = NULL;

	//��ʼ������	
	DLinkNode* s;//���ڸ���������
	for (int i = 0; i < n; i += 1) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];

		//��ʼ����
		s->next = L->next;
		//�ж�L�Ƿ��к�̽�㣬����У�����Ҫ�ı��̽���ǰ��ָ��
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;//��Ҫ�ǵ���s��ǰ��ָ��ָ��L;
	}
}



//����˫������β�巨
void CreateDListR(DLinkNode*& L, ElemType a[], int n) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));//����ͷ���
	//��ʼ��ͷָ��
	L->prior = NULL; L->next = NULL;//ǰ��ָ��������ΪNULL

	//β�巨����˫����
	DLinkNode* s;//ָ��s���ڸ����½��Ĳ���
	DLinkNode* r = L;//����βָ�룬��ʼʱ��β��㼴ͷ���
	for (int i = 0; i < n; i += 1) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;//��β���r�ĺ��ָ��ָ���²���Ľ��s
		s->prior = r;//���²������ǰ��ָ��ָ��β���r
		r = s;//�ƶ�βָ��
	}
	r->next = NULL;//�����һ�����ĺ��ָ������ΪNULL
}



//��˫�����i�����֮ǰ����һ���½��
bool DListInsert(DLinkNode* L, int i,ElemType e) {
	DLinkNode* p, * s;//s����ָ���½��
	p = L;//p���ڱ������½�����
	int j = 0;//���ڼ�¼�����

	//���ݺϷ����ж�
	if (i <= 0) return false;

	//��������Ԫ��
	while (j < i - 1 && p != NULL) {
		p = p->next;
		j += 1;
	}
	if (p == NULL) return false;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));

		//��ʼ����Ԫ�أ���ǰpָ����i-1��㣬���²������ǰ�����
		//�����á��������Ľ��ָ��ԭ�н��
		s->data = e;
		s->prior = p;//�½��s��ǰ�����ָ��ԭ��
		s->next = p->next;//�½��s�ĺ�̽ڵ�ָ��ԭ�н��
		//�ж�p�Ƿ��к�̽�㣬���У��򽫺�̽��ǰ��ָ��ָ���²���ڵ�
		if (p->next != NULL) p->next->prior = s;
		p->next = s;
		return true;
	}
}



//ɾ����i�����
bool DListDelete(DLinkNode* L, int i, ElemType& e) {
	DLinkNode* p = L;//����ָ���i�����
	int j = 0;

	//����Ϸ��Է���
	if (i <= 0) {
		return false;
	}

	//��ʼ����
	while (j < i && p != NULL) {
		p = p->next;
		j += 1;
	}

	if (p == NULL) return false;
	else {
		
		//��ʼɾ����i��Ԫ��
		p->prior->next= p->next;
		if (p->next != NULL) //���p�ĺ��Ԫ�طǿգ������޸�p���Ԫ�ص�ǰ��ָ��
			p->next->prior = p->prior;
		e = p->data;//��p��data��ֵ����e�У��Ա����ʹ��
		free(p);
		return true;
	}
}



//��2.9(P58)
void DReverse(DLinkNode* L) {
	DLinkNode* p,*q;

	//������ֳ�������
	p = L->next; 
	L->next = NULL;

	//����Ȼ����ͷ�巨����
	while (p != NULL) {
		q = p->next;

		//ͷ�巨
		p->next = L->next;
		p->prior = L;
		if (p->next != NULL) p->next->prior = p;
		L->next = p;

		//�ƶ�ָ��
		p = q;
	}
}



//��2.10(P58)
void DSort(DLinkNode* L) {
	DLinkNode* p, * pre, * q;
	
	//��������ֻ��ͷ�����׽��Ĳ���
	p = L->next->next;
	L->next->next = NULL;

	while (p != NULL) {
		q = p->next;
		pre = L;
		while (pre->next->data < p->data && pre->next != NULL)
			pre = pre->next;
		//ѭ��������pre�Ǵ��������ǰ�ý��
		//��ʼ������
		p->next = pre->next;
		p->prior = pre;
		if (pre->next != NULL)
			pre->next->prior = p;
		pre->next = p;
		//�ƶ����
		p = q;
	}

} 
#endif //  DINKNODE_H