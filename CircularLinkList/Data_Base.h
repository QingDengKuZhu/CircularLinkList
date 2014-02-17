/**********************
**单循环链表的基本操作.
***********************/
#ifndef DATA_BASE_H
#define DATA_BASE_H

#include "Main_First.h"
#include "Data.h"

/*
pRear为指向单循环链表末尾结点的尾指针,且pRear不为NULL.
*/

/*构造一个空的单循环链表.*/
PREAR InitList(void);

/*销毁单循环链表.*/
void DestroyList(PREAR *ppRear);

/*将单循环链表清空.*/
void ClearList(PREAR pRear);

/*判断单循环链表是否为空.若为空,函数返回TRUE;否者函数返回FALSE.*/
BOOL ListEmpty(PREAR pRear);

/*返回单循环链表的长度*/
size_t ListLength(PREAR pRear);

/*获取单循环链表中第pos个元素.若操作成功,函数返回OK,*e保存满足条件的结点的值;若操作失败,函数返回FAILE,*e为垃圾值.*/
STATUS GetElem(PREAR pRear, const size_t pos, Elem *e);

/*返回单循环链表中第一个与v相等的元素的位序(从1开始).若成功函数返回相应的位序;否者返回0.*/
size_t LocateElem(PREAR pRear, const Elem v);

/*在单循环链表中第pos个位置之前插入新的数据元素v(1 <= pos <= ListLength(pRear)+1).若成功,函数返回OK;否者返回FAILE.*/
STATUS InsertList(PREAR *ppRear, const size_t pos, const Elem v);

/*删除单循环链表中第pos个元素.若成功删除,函数返回OK,*e保存被删除元素的值;否者函数返回FAILE,*e为垃圾值.*/
STATUS DeleteList(PREAR *ppRear, const size_t pos, Elem *e);

/*遍历输出单循环链表.*/
void TraveList(PREAR pRear);

#endif