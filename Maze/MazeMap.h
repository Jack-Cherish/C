#ifndef MAZEMAP_H
#define MAZEMAP_H

#include <iostream>
#include <Windows.h>	//COORD

//在二维数组里，1代表墙，0代表路
#define WALL 1
#define ROAD 0

class MazeMap
{
public:
	MazeMap(char wall  = 'X');
	~MazeMap();
	/*设置迷宫地图*/
	void setMazeMap(int *mazemap, int row, int col);
	void pintMazeMap();
	int** getMap();							//返回地图二维数组指针
	const char m_cRoad;						//常数据成员：路
	void setExitPosition(int x,int y);		//设置迷宫出口
	COORD m_COORDExitPostion;	//迷宫的出口
private:
	const char m_cWall;			//常数据成员：墙
	int** m_pMap;				//指向迷宫地图二维数组的二级指针
	int m_iMapRow;				//二维数组的行数
	int m_iMapCol;				//二维数组的列数
};

#endif