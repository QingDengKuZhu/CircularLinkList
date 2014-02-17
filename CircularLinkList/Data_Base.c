#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

PREAR InitList(void)
{
	PREAR pRear = NULL;	/*尾指针*/
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (!pHead)
	{
		printf("动态分配头结点失败!\n");
		exit(ERROR);
	}

	pHead->pNext  = pHead;	/*单循环链表尾指针指向头结点.*/
	pRear = pHead;	/*当单循环链表为空(刚初始化完成)时,头结点的指针域存放头结点地址.*/
	
	return pRear;
}



void DestroyList(PREAR *ppRear)
{
	PNODE p  = *ppRear;
	PNODE q = NULL;

	do 
	{
		q  = p->pNext;
		free(p);
		p = q;
	} while (p != *ppRear);
	
	*ppRear = NULL;

	return;
}



void ClearList(PREAR pRear)
{
	PNODE pHead = pRear->pNext;
	PNODE p = pHead->pNext;	/*指向首结点(如果有)*/
	PNODE q = NULL;

	while (p != pHead)	/*判断是否指向头结点,不能使用 "p != pRear->pNext"条件,因为在最后一次判断时,pRear指向的结点已经被释放,会导致内存泄漏.*/
	{
		q = p->pNext;
		free(p);
		p = q;
	}/*退出while循环时,p指向头结点*/
	
	p->pNext = p;
	pRear = p;

	return;
}



BOOL ListEmpty(PREAR pRear)
{
	if (pRear->pNext != pRear)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}



size_t ListLength(PREAR pRear)
{
	PNODE pHead = pRear->pNext;	
	PNODE p = pHead->pNext;	
	size_t cnt = 0;

	
	while (p != pHead)
	{
		++cnt;
		p = p->pNext;		
	}

	return cnt;
}



STATUS GetElem(PREAR pRear, const size_t pos, Elem *e)
{
	PNODE pHead = pRear->pNext;
	PNODE p = pHead->pNext;
	size_t i = 0;

	while ( p != pHead )
	{
		++i;
		if (pos == i)
		{
			*e = p->data;
			return OK;
		}
		else
		{
			p = p->pNext;
		}
	}

	return FAILE;
}



size_t LocateElem(PREAR pRear, const Elem v)
{
	PNODE pHead = pRear->pNext;
	PNODE p = pHead->pNext;
	size_t pos = 1;

	while (p != pHead)
	{
		if (v == p->data)
		{
			return pos;
		}
		else
		{
			++pos;
			p = p->pNext;
		}
	}

	return 0;
}



STATUS InsertList(PREAR *ppRear, const size_t pos, const Elem v)
{
	PNODE pHead = (*ppRear)->pNext;
	PNODE p = pHead;
	PNODE pNew = NULL;
	size_t cur = 1;

	if (pos < 1)	/*判断插入点是否合理.*/
	{
		return FAILE;
	}
	
	if (TRUE == ListEmpty(*ppRear))
	{
		if (pos == 1)
		{
			pNew = (PNODE)malloc(sizeof(NODE));
			if (!pNew)
			{
				printf("动态生成新结点失败!\n");
				exit(ERROR);
			}
			
			pNew->data = v;
			
			(*ppRear)->pNext = pNew;
			pNew->pNext = *ppRear;
			*ppRear = pNew;
			
			return OK;
		}
		else
		{
			return FAILE;
		}
	}

	/*
	**寻找插入点.
	*/
	while (p != pHead)	
	{
		if (pos == cur)	/*找到插入点.*/
		{
			/*
			**插入数据.
			*/
			pNew = (PNODE)malloc(sizeof(NODE));
			if (!pNew)
			{
				printf("动态生成新结点失败!\n");
				exit(ERROR);
			}
			
			pNew->data = v;
			
			pNew->pNext = p->pNext;
			p->pNext = pNew;

			/*
			**若在最末尾插入,需要移动尾指针.
			*/
			if (pNew->pNext == pHead)
			{
				(*ppRear) = pNew;
			}
			
			return OK;
		}
		p = p->pNext;
		++cur;
	}
	
	
	/*
	**未找到插入点.
	*/
	return FAILE;

}



STATUS DeleteList(PREAR pRear, const size_t pos, Elem *e)
{
	PNODE pHead = pRear->pNext;
	PNODE p = pHead->pNext;
	PNODE q = pHead;
	size_t cur = 1;

	if (pos < 1)	/*判断插入点是否合理.*/
	{
		return FAILE;
	}
	
	while (p != pHead)
	{
		if(cur == pos)	/*找到删除结点,此时p指向删除结点,q指向删除结点的前一个结*/
		{
			*e = p->data;
			q->pNext = p->pNext;
			free(p);

			return OK;
		}

		q = p;
		p = p->pNext;
		++cur;

	}

	return FAILE;

}



void TraveList(PREAR pRear)
{
	PNODE pHead = pRear->pNext;	/*指向头结点(若有). */
	PNODE p = pHead->pNext;
	
	while (p != pHead)
	{
		printf("%d", p->data);	
	}

	return;

}