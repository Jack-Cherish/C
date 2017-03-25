/******************************************************************
 * Topic	:	用归并排序法对一组数据由小到大进行排序，数据分别为
 * 				695、458、362、789、12、15、163、23、2、986
 * File Name:	MergeSort
 * Author	:	Jack Cui
 * Created	:	4 April 2016
 * ****************************************************************/
#include <stdio.h>
/*归并排序函数声明*/
void MergeSort(int iSourceArr[],int iTempArr[],int iStartIndex,int iEndIndex);
void Merge(int iSourceArr[],int iTempArr[],int iStartIndex,int iMidIndex,int iEndIndex);

int main(void)
{
	int i,iArr_b[10],iArr_a[10];
	printf("请输入10个数：\n");
	for(i = 0;i < 10;i++)
		scanf("%d",&iArr_a[i]);
	MergeSort(iArr_a,iArr_b,0,9);
	printf("快速排序后的顺序为：\n");
	for(i = 0;i < 10;i++)
		printf("%5d",iArr_a[i]);
	printf("\n");
	return 0;
}
/**********************************
*函数名称：MergeSort
*参数说明：iSourceArr[] 原始数组
*         iTempArr[]   临时数组
*		  iStartIndex  起始位置索引值
*		  iEndIndex    结束位置索引值
*说明：    二路归并排序
***********************************/
void MergeSort(int iSourceArr[],int iTempArr[],int iStartIndex,int iEndIndex)
{
	int iMidIndex;
	if(iStartIndex < iEndIndex)
	{
		iMidIndex = (iStartIndex + iEndIndex) / 2;
		/*递归调用将iSourceArr[iStartIndex]~iSourceArr[iMidIndex]归并成有序的*/
		MergeSort(iSourceArr,iTempArr,iStartIndex,iMidIndex);
		/*递归调用将iSourceArr[iMidIndex+1]~iSourceArr[iEndIndex]归并成有序的*/
		MergeSort(iSourceArr,iTempArr,iMidIndex+1,iEndIndex);
		/*调用函数将前两部分归并到iSourceArr[iStartIndex]~iSourceArr[iEndIndex]*/
		Merge(iSourceArr,iTempArr,iStartIndex,iMidIndex,iEndIndex);
	}
}
/**********************************
*函数名称：Merge
*参数说明：iSourceArr[] 原始数组
*         iTempArr[]   临时数组
*		  iStartIndex  起始位置索引值
*		  iMidIndex    中间位置索引值
*		  iEndIndex    结束位置索引值
*说明：    归并排序
***********************************/
void Merge(int iSourceArr[],int iTempArr[],int iStartIndex,int iMidIndex,int iEndIndex)
{
	int i = iStartIndex,j = iMidIndex + 1,k = iStartIndex;
	while((i <= iMidIndex) && (j <= iEndIndex))		//当i和j都在要合并的部分中成立
	{
		if(iSourceArr[i] >= iSourceArr[j])
			iTempArr[k++] = iSourceArr[j++];
		else
			iTempArr[k++] = iSourceArr[i++];
	}
	while(i <= iMidIndex)				//将iStartIndex~iMidIndex内，未比较的数组顺次加到iTempArr数组中
		iTempArr[k++] = iSourceArr[i++];
	while(j <= iEndIndex)				//将iMidIndex+1~iStartIndex内，未比较的数组顺次加到iTempArr数组中
		iTempArr[k++] = iSourceArr[j++];
	for(i = iStartIndex; i <= iEndIndex; i++)
		iSourceArr[i] = iTempArr[i];
}

