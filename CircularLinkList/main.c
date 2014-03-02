/**********************
**主函数, 测试
***********************/

#include "Main_First.h"
#include "Data.h"
#include "Data_Base.h"
#include "Test.h"
#include <time.h> /*随机数*/

int main(void)
{
	int select;		/*保存选择变量*/
	size_t pos;		/*位序*/
	Elem e;			/*保存从函数返回的结点的值*/
	Elem v;			/*保存传递给函数的结点的值*/
	
	size_t i= 0;
	PREAR pRear = InitList();
	srand((int)time(NULL));
	while (i < 10)
	{

		InsertList(&pRear, i, i);
		++i;
	}

	while (1)	/*while_@1*/
	{
		if (!pRear)
		{
			printf("表不存在!\n");
			break;
		}

		system("cls");
		Menu();

		printf("请输入您的选择(1~10):");
		scanf("%d", &select);
		getchar();

		switch (select)	/*switch_@1*/
		{
		case 1:			/*插入数据*/
			pos = InputPos("插入位置为:");
			v = InputValue("结点元素为:");
			if (FAILE == InsertList(&pRear, pos, v))
			{
				printf("插入失败!\n");
			}
			else
			{
				printf("插入成功!\n");
			}
			
			getchar();
			break;
		case 2:			/*整表输出*/
			printf("整表为:");
			TraveList(pRear);
			
			getchar();
			break;
		case 3:			/*删除结点*/
			pos = InputPos("删除的结点位置是:");
			if (OK == DeleteList(&pRear, pos, &e))
			{
				printf("删除成功,删除的元素是%d!\n", e);
			}
			else
			{
				printf("删除失败!\n");
			}

			getchar();
			break;

		case 4:			/*输出表的长度*/
			printf("表长为: %d \n", ListLength(pRear));
			
			getchar();
			break;

		case 5:			/*清空表*/
			ClearList(pRear);
			printf("该表已经清空!\n");
			
			getchar();
			break;

		case 6:			/*判断链表是否存在特定结点*/
			v =InputValue("要查找的数值为:");
			printf("要查找的元素在链表的第%d位!(第0位表示不存在)\n", LocateElem(pRear, v));

			getchar();
			break;

		case 7:			/*返回特定位序结点*/
			pos = InputPos("获取位置为:");
			if (OK == GetElem(pRear, pos, &e))
			{
				printf("该结点为:%d\n", e);
			}
			else
			{
				printf("不存在!\n");
			}

			getchar();	
			break;

		case 8:			/*判断链表*/
			if (ListEmpty(pRear) == TRUE)
			{
				printf("表为空!\n");
			}
			else
			{
				printf("表非空!\n");
			}

			getchar();	
			break;
		
		case 9:			/*销毁整表*/
			DestroyList(&pRear);
			printf("表已删除!\n");

			getchar();	
			break;
		

		default:
			printf("请重新选择!\n");
			
			getchar();
			break;
		}/*switch_@1*/

	}	/*while_@1*/
	
	return EXIT_SUCCESS;
}