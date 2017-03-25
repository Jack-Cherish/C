#include "MazeMap.h"

/************************************************
*函数名称：MazeMap()
*函数功能：构造函数，初始化参数
*函数参数：wall 墙的表示符号
*修改时间：2016.7.18
*************************************************/
MazeMap::MazeMap(char wall):m_cWall(wall),m_cRoad(' ')
{
	m_pMap = NULL;
}
/************************************************
*函数名称：~MazeMap()
*函数功能：析构函数，释放动态申请的内存空间
*修改时间：2016.7.18
*************************************************/
MazeMap::~MazeMap()
{
	if(m_pMap)
	{
		for(int i = 0; i < m_iMapRow; i++)
		{
			delete m_pMap[i];
			m_pMap[i] = NULL;
		}
		delete m_pMap;
	}
}
/************************************************
*函数名称：setMazeMap()
*函数功能：设置迷宫地图，传递参数
*函数参数：*mazemap 存储地图数据的二维数组的指针
			row		二维数组的行数
			col		二维数组的列数
*修改时间：2016.7.18
*************************************************/
void MazeMap::setMazeMap(int *mazemap, int row, int col)
{
	m_iMapRow = row;
	m_iMapCol = col;
	//为存储迷宫地图的二维数组动态分配内存空间
	m_pMap = new int*[m_iMapRow];		//分配m_iMapRow个存储int类型指针的内存空间
	for(int i = 0; i < m_iMapRow; i++)	
		m_pMap[i] = new int[m_iMapCol];	//分配m_iMapCol个存储int类型的内存空间

	//将二维数组迷宫地图的数据拷贝给二级指针
	for(int i = 0; i < m_iMapRow; i++)
	{
		for(int j = 0; j < m_iMapCol; j++)
		{
			m_pMap[i][j] = *mazemap;
			mazemap++;
		}
	}
}
/************************************************
*函数名称：pintMazeMap()
*函数功能：打印迷宫地图
*修改时间：2016.7.18
*************************************************/
void MazeMap::pintMazeMap()
{
	system("cls");
	for(int i = 0; i < m_iMapRow; i++)	
	{
		for(int j = 0; j < m_iMapCol; j++)
		{
			if(m_pMap[i][j])			//数组元素为1，则打印代表墙的字符
				std::cout << m_cWall;
			else						//否则，打印代表路的字符
				std::cout << m_cRoad;
		}
		std::cout << std::endl;
	}
}

/************************************************
*函数名称：getMap()
*函数功能：返回地图二维数组指针
*返 回 值：二级指针
*修改时间：2016.7.18
*************************************************/
int** MazeMap::getMap()
{
	return m_pMap;
}
/************************************************
*函数名称：setExitPosition()
*函数功能：设置迷宫的出口
*函数参数：x 迷宫出口位置所在行数
		   y 迷宫出口位置所在列数
*修改时间：2016.7.18
*************************************************/
void MazeMap::setExitPosition(int x, int y)
{
	m_COORDExitPostion.X = x;
	m_COORDExitPostion.Y = y;
}


