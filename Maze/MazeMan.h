#ifndef MAZEMAN_H
#define MAZEMAN_H

#include <Windows.h>
#include "MazeMap.h"

enum direction{U,D,L,R};

class MazeMan
{
public:
	MazeMan(char man = 'T',char manface = R);
	void setPosition(int x, int y);		//������Ϸ��ɫλ��
	void setMap(MazeMap *map);			//���õ�ͼ����
	bool walkUp();						//������
	bool walkDown();					//������
	bool walkLeft();					//������
	bool walkRight();					//������
	void moveForward(direction direct);	//���ݴ���ķ�������Ϸ��ɫǰ��һ��	
	void start();						//��Ϸ��ʼ����
private:
	char m_cMan;						//������Ϸ��ɫ���ַ�
	char m_cManFace;					//��Ϸ��ɫ�ĳ���
	int m_iSteps;						//��¼��Ϸ��ɫ�Ѿ��ߵĲ���
	COORD m_COORDManCurrentPosition;	//��Ϸ��ɫ�ĵ�ǰλ��
	MazeMap *m_pMap;					//��ͼ����
};
#endif