#ifndef LINKNODE_H
#define LINKNODE_H
#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	LNode* next;
} LinkNode;



//插入元素：头插法
void InsertElement(LinkNode*& L, int a[], int n) {
	LinkNode* s;//创建一个用于指向插入节点的指针，即被插入处的前一个结点的指针
	for (int i = 0; i <= n - 1; i += 1) {
		s = (LinkNode*)malloc(sizeof(LinkNode));//为插入的新元素新建结点
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}



void CreatListF(LinkNode*& L, int a[], int n) {
	L = (LinkNode*)malloc(sizeof(LNode));//新建了一个空表，L指向头节点
	L->next= NULL;
	//依次取出数组中的值并填入到节点中
	InsertElement(L, a, n);//调用插入方法
	}



//插入元素：尾插法
void CreatListR(LinkNode*& L, int a[], int n) {
	L = (LinkNode*)malloc(sizeof(LNode));//新建了一个空表，L指向头节点
	L->next = NULL;
	LinkNode* r = L;//创建一个尾指针r，用于指向插入元素的前一个结点
	LinkNode* s;//创建一个指针，指向被插入的元素
	for (int i = 0; i <= n - 1; i += 1) {
		s = (LinkNode*)malloc(sizeof(LinkNode));//创建新结点
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;//尾结点的指针指向null
}



//删除线性表
void DestroyList(LinkNode* L) {
	LinkNode* pre = L;//头指针
	LinkNode* head = L->next;//首指针
	while (head != NULL) {
		free(pre);
		pre = head;
		head = head->next;
	}

	free(pre);
}



//返回链表长度(数据结点个数)
int ListLength(LinkNode* L) {
	LinkNode* p = L;
	int n = 0;
	while (p->next != NULL) {
		n += 1;
		p = p->next;
	}
	return n;
}



//依次输出单链表
void DispList(LinkNode* L) {
	LinkNode* p = L->next;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->next;
	}
}



//插入数据元素
bool ListInsert(LinkNode* L, int i,ElemType d) {
	int j = 0;//从头结点开始记录编号，头结点编号为0
	LinkNode* temp = L;
	if (i <= 0)
		return false;//合法性分析
	for (j; j < i - 1 && temp != NULL; j += 1) {
		temp = temp->next;
	}//for循环结束后，temp指针要么指向i-1个结点，要么指向的结点为空，无法插入元素
	if (temp == NULL) {
		return false;
	}
	//插入元素
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = d;
	s->next = temp->next;
	temp->next = s;
	return true;
}



//数据删除
bool ListDelete(LinkNode* L, int i, ElemType& e) {
	if (i <= 0)
		return false;
	LinkNode* p = L;
	int count = 0;//头结点编号为0
	while (count < i - 1 && p != NULL) {
		count += 1;
		p = p->next;
	}
	if (p == NULL)
		return false;
	LinkNode* temp = p->next;//使用一个临时指针指向即将被删除的结点
	if (temp == NULL)
		return false;//如果即将被删除的结点为NULL，同样视作删除失败444 
	e = temp->data;
	p->next = temp->next;
	free(temp); 
	return true;
}



//例：2.6（P52）
void split(LinkNode* L, LinkNode*& L1, LinkNode*& L2) {
	LinkNode* r1,//r1指向L1的尾结点
		*p,//辅助头插法和尾插法
		*q;//用来在头插法时临时存储，防止结点丢失
	L1 = L;//L的头结点就是L1的头结点
	r1 = L1;
	L2 = (LinkNode*)malloc(sizeof(LinkNode));//创建L2头结点
	L2->next = NULL;
	p = L->next;
	while (p == NULL) {
		//尾插法
		r1->next = p;//p此时为ai
		r1 = p;  //r1移动到尾结点

		//尾插法结束，开始头插法
		p = p->next;//p此时为bi
		q = p->next;//由于头插法会改变p->next，故用q来存储，防止结点丢失
		p->next = L2->next;
		L2->next = p;
		p = q;//将p设置到下一个ai处开始下一次循环
	}
	r1->next = NULL;
}



//例：2.7（P53）
void DelMaxNode(LinkNode* L) {
	LinkNode* pre, * p, * maxpre, * maxp;
	pre = L;
	p = L->next;
	maxpre = pre;
	maxp = p;
	while (p != NULL) {//找到maxp
		if (maxp->data < p->data) {
			maxp = p;
			maxpre = pre;
		}
		pre = pre->next;
		p = p->next;
	}
	//删除maxp
	maxpre->next = maxp->next;
	free(maxp);
}



//例2.8(p53)
void Sort(LinkNode* L) {
	//首先将线性表拆成（头结点+首节点）和剩下元素两个部分
	LinkNode* pre ;//pre代表插入的前驱结点
	LinkNode* p = L->next->next;//p指向线性表另一部分的第一个元素
	LinkNode* q;//用于存储p的后继结点
	L->next->next = NULL;//将线性表断开
	//将元素有序插入到表中
	while (p != NULL) {
		pre = L;//插入处的前驱结点每次都要从头结点开始找起
		while (pre->next!=NULL &&  pre->next->data < p->data) {
			pre = pre->next;
		}//循环结束后，pre就是插入处的前驱结点
		//前插法
		q = p->next;//防止p的后继节点丢失
		p->next = pre->next; 
		pre->next = p;
		p = q;
	}

}

#endif