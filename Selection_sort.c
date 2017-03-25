/***********************************************************************
 * Topic	:	用选择排序法对一组数据由小到大进行排序，数据分别
 			为526、36、2、369、56、45、78、92、125、52
 * File Name	:	Selection_sort
 * Author	:	Jack Cui
 * Created	:	31 March 2016
 * *********************************************************************/
#include <stdio.h>
/*选择排序函数声明*/
int* Selection_sort(int* pDataArray,int iDataNum);

void main(void)
{
	int i;
	int iArray[10];
	printf("请输入10个数：\n");
	for(i = 0;i < 10;i++)
		scanf("%d",&iArray[i]);
	Selection_sort(iArray,10);
	printf("快速排序后的顺序为：\n");
	for(i = 0;i < 10;i++)
		printf("%5d",iArray[i]);
	printf("\n");
}
/**********************************
*函数名称：Selection_sort
*参数说明：pDataArray 无序数组
*          iDataNum为无序数据个数
*说明：    快速排序
***********************************/
int* Selection_sort(int* pDataArray,int iDataNum)
{
	int i,j,iDataTemp;
	for(i = 0;i < 9;i++)
		for(j = i + 1;j < 10;j++)
			if(pDataArray[i] > pDataArray[j])
			{
				iDataTemp = pDataArray[i];
				pDataArray[i] = pDataArray[j];
				pDataArray[j] = iDataTemp;
			}
	return pDataArray;
}

