#ifndef MAZEMAN_H
#define MAZEMAN_H

#include <Windows.h>
#include "MazeMap.h"

enum direction{U,D,L,R};

class MazeMan
{
public:
	MazeMan(char man = 'T',char manface = R);
	void setPosition(int x, int y);		//设置游戏角色位置
	void setMap(MazeMap *map);			//设置地图对象
	bool walkUp();						//向上走
	bool walkDown();					//向下走
	bool walkLeft();					//向左走
	bool walkRight();					//向右走
	void moveForward(direction direct);	//根据传入的方向让游戏角色前进一步	
	void start();						//游戏开始函数
private:
	char m_cMan;						//代表游戏角色的字符
	char m_cManFace;					//游戏角色的朝向
	int m_iSteps;						//记录游戏角色已经走的步数
	COORD m_COORDManCurrentPosition;	//游戏角色的当前位置
	MazeMap *m_pMap;					//地图对象
};
#endif