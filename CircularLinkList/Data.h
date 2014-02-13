﻿/*****************
**单循环链表数据结构
*****************/
#ifndef DATA_H
#define DATA_H

#include "Main_First.h"

typedef int Elem;

typedef struct Node
{
	Elem data;	/*数据域*/
	struct Node *pNext;	/*指针域*/ 

} NODE, *PNODE, CIRCULARLINKLIST, *PCIRCULARLINKLIST, *PREAR;


#endif