/******************************************************************
 * Topic	:	采用二分查找法查找特定关键字的元素。
 * File Name:	BinarySearch.c
 * Author	:	Jack Cui
 * Created	:	6 April 2016
 * ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
/*归并排序函数声明*/
void BinarySearch(int iKey,int *pArr,int iNum);

void main(void)
{
	int i,iKey,*pArr,iNum;
	printf("请输入数组的长度：\n");
	scanf("%d",&iNum);
	printf("请输入数组元素：\n");
	pArr = (int *)malloc(sizeof(int) *iNum);
	for(i = 0;i < iNum;i++)
		scanf("%d",&pArr[i]);
	printf("请输入你想查找的元素：\n");
	scanf("%d",&iKey);
	BinarySearch(iKey,pArr,iNum);
}

/**********************************
*函数名称：BinarySearch
*参数说明：iKey 		要查找的数
*         *pArr  	数组
*		  iNum  	数组大小
*说明：    二分查找
***********************************/
void BinarySearch(int iKey,int *pArr,int iNum)
{
	int iLeft,iRight,iMid,iCount,iFlag;
	iCount = 0;							//记录查找次数
	iFlag = 0;							//查找正确标志位
	iLeft = 0;							//左侧最小值
	iRight = iNum - 1;					//右侧最大值
	while(iLeft <= iRight)				//范围正确的时候，进行查询。
	{
		iCount++;						//查找次数+1
		iMid = (iLeft + iRight) / 2;	//二分
		if(iKey < pArr[iMid])
			iRight = iMid - 1;
		else if(iKey > pArr[iMid])
			iLeft = iMid + 1;
		else if(iKey == pArr[iMid])
		{
			printf("查找成功！\n查找%d次！pArr[%d]=%d\n",iCount,iMid,iKey);
			iFlag = 1;
			break;
		}
	}
	if(iFlag == 0)
		printf("查找失败！\n");
}


