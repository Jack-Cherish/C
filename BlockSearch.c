/******************************************************************
 * Topic	:	分块查找
 * File Name:	BlockSearch.c
 * Author	:	Jack Cui
 * Created	:	12 April 2016
 * ****************************************************************/
#include <stdio.h>
#include <stdlib.h>
/*声明分块查找函数*/
int block_search(int iKey,int iArr[]);

/*定义块的结构体*/
struct index
{
	int iKey;		//关键字
	int iStart;		//起始位置
	int iEnd;		//结束位置
}index_table[4];	//结构体数组

/**********************************
*函数名称：block_search
*参数说明：iKey 		查询的关键字
*		  iArr		有序数列保存的数组
*说明：    分块查找
***********************************/
int block_search(int iKey,int iArr[])
{
	int i = 1,j;
	while((i < 4) && (iKey > index_table[i].iKey))	//确定要查找的元素在哪个块里
	{
		i++;
	}
	if(i > 3)										//当大于最大块数的时候表明没有查找到，返回0
	{
		return 0;
	}
	else
	{
		j = index_table[i].iStart;						//j为块范围的起始位置
		while((j <= index_table[i].iEnd) && (iArr[j] != iKey))
		{
			j++;
		}
		if(j > index_table[i].iEnd)						//超出块的范围
		{
			return 0;
		}
		return j;
	}
}

void main(void)
{
	int i,j = 0,iRet,iKey,iArr[16];
	printf("请输入15个有序数：");
	for(i = 1;i < 16;i++)
		scanf("%d",&iArr[i]);
	for(i = 0;i < 3;i++)
	{
		index_table[i].iStart = j + 1;		//确定每个块范围的起始位置
		j = j + 1;
		index_table[i].iEnd = j + 4;		//确定每个块范围的结束位置
		j = j + 4;
		index_table[i].iKey = iArr[j];		//确定每个块范围的元素最大值
	}
	printf("请输入您要查询的数字：");
	scanf("%d",&iKey);
	iRet = block_search(iKey,iArr);
	if(iRet != 0)
		printf("查找成功，其位置是：%d\n",iRet);
	else
		printf("查找失败!\n");
}


