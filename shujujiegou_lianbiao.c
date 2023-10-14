#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)//VS
//typedef的用法
/*
#include<stdio.h>
typedef struct Student
{
	int sid;
	char name[100];
	char courge;
}* PST,ST;//PST 等价于student Student*,ST 等价于struct Student
int main(void)
{
	ST st;//相当于struct Student st；
	PST ps = &st;//等价于student Student* ps=&st;
	ps->sid = 66;
	printf("%d\n", ps->sid);
	return 0;
}
*/
# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
//一个节点的生成
typedef struct Node
{
	int data;//数据域
	struct Node * pNext;//指针域
}NODE,*PNODE;//NODE等价于struct Node,PNODE等价于struct Node*
PNODE create_list(void);//生成链表
void traverse_list(PNODE pHead);//遍历链表
int main(void)
{
	PNODE pHead = NULL;//等价于 struct Node * pHead = NULL;
	pHead = create_list();//create_list()功能：创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
	traverse_list(pHead);
	return 0;
}
PNODE create_list(void)
{
	int len;//用来存放有效节点的个数
	int i;
	int val;//用来临时存放用户输入的节点的值
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//分配了一个不存放有效数据的头节点
	if (NULL == pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入您需要生成的链表节点的个数：len=");
	scanf("%d", &len);
	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值：",i + 1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//pNew指向每一个新的节点
		if (NULL == pNew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	 }
	while (NULL == p)
	{
		free(p);
	}
	printf("\n");
}