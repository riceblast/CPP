#ifndef  DINKNODE_H
#define DLINKNODE_H
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;//用于存放数据
	DNode* prior;//指向前驱的指针
	DNode* next;//指向后继的指针
}DLinkNode;



//建立双链表——头插法
void CreateDListF(DLinkNode* &L, ElemType a[], int n){
	L = (DLinkNode*)malloc(sizeof(DLinkNode));//创建头指针
	//初始化头指针,前后指针置为空
	L->next = NULL;
	L->prior = NULL;

	//开始插入结点	
	DLinkNode* s;//用于辅助插入结点
	for (int i = 0; i < n; i += 1) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];

		//开始插入
		s->next = L->next;
		//判断L是否有后继结点，如果有，还需要改变后继结点的前驱指针
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;//还要记得让s的前驱指针指向L;
	}
}



//建立双链表——尾插法
void CreateDListR(DLinkNode*& L, ElemType a[], int n) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));//建立头结点
	//初始化头指针
	L->prior = NULL; L->next = NULL;//前后指针域设置为NULL

	//尾插法建立双链表
	DLinkNode* s;//指针s用于辅助新结点的插入
	DLinkNode* r = L;//建立尾指针，初始时，尾结点即头结点
	for (int i = 0; i < n; i += 1) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;//将尾结点r的后继指针指向新插入的结点s
		s->prior = r;//将新插入结点的前驱指针指向尾结点r
		r = s;//移动尾指针
	}
	r->next = NULL;//将最后一个结点的后继指针设置为NULL
}



//在双链表第i个结点之前插入一个新结点
bool DListInsert(DLinkNode* L, int i,ElemType e) {
	DLinkNode* p, * s;//s用来指向新结点
	p = L;//p用于遍历和新结点插入
	int j = 0;//用于记录结点编号

	//数据合法性判断
	if (i <= 0) return false;

	//遍历查找元素
	while (j < i - 1 && p != NULL) {
		p = p->next;
		j += 1;
	}
	if (p == NULL) return false;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));

		//开始插入元素，当前p指针在i-1结点，即新插入结点的前驱结点
		//首先让“新来”的结点指向原有结点
		s->data = e;
		s->prior = p;//新结点s的前驱结点指向原有
		s->next = p->next;//新结点s的后继节点指向原有结点
		//判断p是否有后继结点，如有，则将后继结点前驱指针指向新插入节点
		if (p->next != NULL) p->next->prior = s;
		p->next = s;
		return true;
	}
}



//删除第i个结点
bool DListDelete(DLinkNode* L, int i, ElemType& e) {
	DLinkNode* p = L;//用于指向第i个结点
	int j = 0;

	//输入合法性分析
	if (i <= 0) {
		return false;
	}

	//开始遍历
	while (j < i && p != NULL) {
		p = p->next;
		j += 1;
	}

	if (p == NULL) return false;
	else {
		
		//开始删除第i个元素
		p->prior->next= p->next;
		if (p->next != NULL) //如果p的后继元素非空，则还需修改p后继元素的前驱指针
			p->next->prior = p->prior;
		e = p->data;//将p中data的值存在e中，以便后续使用
		free(p);
		return true;
	}
}



//例2.9(P58)
void DReverse(DLinkNode* L) {
	DLinkNode* p,*q;

	//将链表分成两部分
	p = L->next; 
	L->next = NULL;

	//遍历然后用头插法插入
	while (p != NULL) {
		q = p->next;

		//头插法
		p->next = L->next;
		p->prior = L;
		if (p->next != NULL) p->next->prior = p;
		L->next = p;

		//移动指针
		p = q;
	}
}



//例2.10(P58)
void DSort(DLinkNode* L) {
	DLinkNode* p, * pre, * q;
	
	//将链表拆成只有头结点和首结点的部分
	p = L->next->next;
	L->next->next = NULL;

	while (p != NULL) {
		q = p->next;
		pre = L;
		while (pre->next->data < p->data && pre->next != NULL)
			pre = pre->next;
		//循环结束后，pre是待插入结点的前置结点
		//开始插入结点
		p->next = pre->next;
		p->prior = pre;
		if (pre->next != NULL)
			pre->next->prior = p;
		pre->next = p;
		//移动结点
		p = q;
	}

} 
#endif //  DINKNODE_H