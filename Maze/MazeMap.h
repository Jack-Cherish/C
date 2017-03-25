#ifndef MAZEMAP_H
#define MAZEMAP_H

#include <iostream>
#include <Windows.h>	//COORD

//�ڶ�ά�����1����ǽ��0����·
#define WALL 1
#define ROAD 0

class MazeMap
{
public:
	MazeMap(char wall  = 'X');
	~MazeMap();
	/*�����Թ���ͼ*/
	void setMazeMap(int *mazemap, int row, int col);
	void pintMazeMap();
	int** getMap();							//���ص�ͼ��ά����ָ��
	const char m_cRoad;						//�����ݳ�Ա��·
	void setExitPosition(int x,int y);		//�����Թ�����
	COORD m_COORDExitPostion;	//�Թ��ĳ���
private:
	const char m_cWall;			//�����ݳ�Ա��ǽ
	int** m_pMap;				//ָ���Թ���ͼ��ά����Ķ���ָ��
	int m_iMapRow;				//��ά���������
	int m_iMapCol;				//��ά���������
};

#endif