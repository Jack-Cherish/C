/******************************************************************
 * Topic	:	杨辉三角
 * File Name:	Triangle.c
 * Author	:	Jack Cui
 * Created	:	9 April 2016
 * ****************************************************************/
#include <stdio.h>
#include <stdlib.h>
/*声明杨辉三角打印函数*/
int Triangle(int iHeigh);

void main(void)
{
	int iHeigh,flag = 1;	//高度，循环标志位
	while(flag)
	{
		printf("请输入杨辉三角的层数：\n");
		scanf("%d",&iHeigh);
		flag = Triangle(iHeigh);
	}
}
/**********************************
*函数名称：Triangle
*参数说明：iHeigh 	杨辉三角需要打印的高度
*说明：    杨辉三角打印
***********************************/
int Triangle(int iHeigh)
{
	int iNum,iLine,iColumn;													//数值、行数为1代表第一行、列数为1代表第一列
	if(iHeigh <= 0)
	{
		printf("输入层数错误(正整数)--");									//打印错误信息
		return 1;															//输入错误，重新输入
	}
	else
	{
		printf("1\n");														//输出第一行1
		for(iLine = 2;iLine <= iHeigh;iNum = 1,iLine++)						//行数i从第二行开始每次加一层直到第iNum层为止
		{
			printf("1 ");													//输出每行的行首的1，结尾空格
			for(iColumn = 1; iColumn <= iLine - 2;iColumn++)				//列数j：从第三行的第二列开始，每次都跳过第一列
			{
				printf("%d ",(iNum = (iLine - iColumn) * iNum / iColumn));
			}
			printf("1\n");													//输出每行的行尾的1，结尾换行
		}
	}
	return 0;
}

