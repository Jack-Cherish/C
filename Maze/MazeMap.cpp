#include "MazeMap.h"

/************************************************
*�������ƣ�MazeMap()
*�������ܣ����캯������ʼ������
*����������wall ǽ�ı�ʾ����
*�޸�ʱ�䣺2016.7.18
*************************************************/
MazeMap::MazeMap(char wall):m_cWall(wall),m_cRoad(' ')
{
	m_pMap = NULL;
}
/************************************************
*�������ƣ�~MazeMap()
*�������ܣ������������ͷŶ�̬������ڴ�ռ�
*�޸�ʱ�䣺2016.7.18
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
*�������ƣ�setMazeMap()
*�������ܣ������Թ���ͼ�����ݲ���
*����������*mazemap �洢��ͼ���ݵĶ�ά�����ָ��
			row		��ά���������
			col		��ά���������
*�޸�ʱ�䣺2016.7.18
*************************************************/
void MazeMap::setMazeMap(int *mazemap, int row, int col)
{
	m_iMapRow = row;
	m_iMapCol = col;
	//Ϊ�洢�Թ���ͼ�Ķ�ά���鶯̬�����ڴ�ռ�
	m_pMap = new int*[m_iMapRow];		//����m_iMapRow���洢int����ָ����ڴ�ռ�
	for(int i = 0; i < m_iMapRow; i++)	
		m_pMap[i] = new int[m_iMapCol];	//����m_iMapCol���洢int���͵��ڴ�ռ�

	//����ά�����Թ���ͼ�����ݿ���������ָ��
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
*�������ƣ�pintMazeMap()
*�������ܣ���ӡ�Թ���ͼ
*�޸�ʱ�䣺2016.7.18
*************************************************/
void MazeMap::pintMazeMap()
{
	system("cls");
	for(int i = 0; i < m_iMapRow; i++)	
	{
		for(int j = 0; j < m_iMapCol; j++)
		{
			if(m_pMap[i][j])			//����Ԫ��Ϊ1�����ӡ����ǽ���ַ�
				std::cout << m_cWall;
			else						//���򣬴�ӡ����·���ַ�
				std::cout << m_cRoad;
		}
		std::cout << std::endl;
	}
}

/************************************************
*�������ƣ�getMap()
*�������ܣ����ص�ͼ��ά����ָ��
*�� �� ֵ������ָ��
*�޸�ʱ�䣺2016.7.18
*************************************************/
int** MazeMap::getMap()
{
	return m_pMap;
}
/************************************************
*�������ƣ�setExitPosition()
*�������ܣ������Թ��ĳ���
*����������x �Թ�����λ����������
		   y �Թ�����λ����������
*�޸�ʱ�䣺2016.7.18
*************************************************/
void MazeMap::setExitPosition(int x, int y)
{
	m_COORDExitPostion.X = x;
	m_COORDExitPostion.Y = y;
}


