#include "MazeMan.h"

/************************************************
*�������ƣ�MazeMan()
*�������ܣ����캯������ʼ�����ݳ�Ա
*����������man ��ʾ��Ϸ��ɫ���ַ�
		   manface ��Ϸ��ɫ�ĳ���
*�޸�ʱ�䣺2016.7.18
*************************************************/
MazeMan::MazeMan(char man,char manface)
{
	m_cMan = man;
	m_cManFace = manface;
	m_iSteps = 0;
}
/************************************************
*�������ƣ�setMap()
*�������ܣ����õ�ͼ�����еĵ�ͼ
*����������*map ��ͼ�����ָ��
*�޸�ʱ�䣺2016.7.18
*************************************************/
void MazeMan::setMap(MazeMap *map)
{
	m_pMap = map;
}

/************************************************
*�������ƣ�setPosition()
*�������ܣ�������Ϸ��ɫλ��
*����������x ��ɫ����λ�õĺ�����
		   y ��ɫ����λ�õ�������
*�޸�ʱ�䣺2016.7.18
*************************************************/
void MazeMan::setPosition(int x, int y)
{
	unsigned long numWritten;
	//��������д��ڵĴ��ھ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_COORDManCurrentPosition.X = x;
	m_COORDManCurrentPosition.Y = y;
	//��ָ������λ�����ָ�����ַ�,������������Ϸ��ɫ�ĵ�ǰλ����������Ϸ��ɫ���ַ���ʹ��Ϸ��ɫ�ɳ���
	FillConsoleOutputCharacter(handle,m_cMan,1,m_COORDManCurrentPosition,&numWritten);
	//����˵��������̨��Ļ�����������Ҫ�����̨������д����ַ���Ӧд����ַ���Ԫ����
	//һ��COORD�ṹ����ָ���ַ����ַ���Ҫд�ĵ�һ����Ԫ������ꣻ
	//ָ����յ�ʵ��д�����̨��Ļ���������ַ����ı�����ָ�롣
}
/************************************************
*�������ƣ�moveForward()
*�������ܣ����ݴ���ķ�������Ϸ��ɫǰ��һ��
*����������direct �ƶ��ķ���
*�޸�ʱ�䣺2016.7.18
*************************************************/
void MazeMan::moveForward(direction direct)
{
	unsigned long numWritten;
	//��ȡ�����д��ڵĴ��ھ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ָ������λ�����ָ�����ַ�,������������Ϸ��ɫ�ĵ�ǰλ�����ո�ʹ��Ϸ��ɫ��ʧ
	FillConsoleOutputCharacter(handle,m_pMap->m_cRoad,1,m_COORDManCurrentPosition,&numWritten);
	switch(direct)
	{
	case U:
		m_COORDManCurrentPosition.Y -= 1;
		break;
	case D:
		m_COORDManCurrentPosition.Y += 1;
		break;
	case L:
		m_COORDManCurrentPosition.X -= 1;
		break;
	case R:
		m_COORDManCurrentPosition.X += 1;
		break;
	default:
		break;
	}
	//��Ϸ��ɫ������£����µ�����
	FillConsoleOutputCharacter(handle,m_cMan,1,m_COORDManCurrentPosition,&numWritten);
	//�ƶ���ɺ������Ϸ��ɫ�ĳ���
	m_cManFace = direct;
}

/************************************************
*�������ƣ�walkUp()
*�������ܣ�������һ�������ɹ����򷵻�ture����ʧ�ܣ��򷵻�false
*�޸�ʱ�䣺2016.7.18
*************************************************/
bool MazeMan::walkUp()
{
	if(m_pMap->getMap()[m_COORDManCurrentPosition.Y - 1][m_COORDManCurrentPosition.X])
		return false;
	else 
		moveForward(U);
		return true;
}
/************************************************
*�������ƣ�walkDown()
*�������ܣ�������һ�������ɹ����򷵻�ture����ʧ�ܣ��򷵻�false
*�޸�ʱ�䣺2016.7.18
*************************************************/
bool MazeMan::walkDown()
{
	if(m_pMap->getMap()[m_COORDManCurrentPosition.Y + 1][m_COORDManCurrentPosition.X])
		return false;
	else 
		moveForward(D);
		return true;
}
/************************************************
*�������ƣ�walkLeft()
*�������ܣ�������һ�������ɹ����򷵻�ture����ʧ�ܣ��򷵻�false
*�޸�ʱ�䣺2016.7.18
*************************************************/
bool MazeMan::walkLeft()
{
	if(m_pMap->getMap()[m_COORDManCurrentPosition.Y][m_COORDManCurrentPosition.X - 1])
		return false;
	else 
		moveForward(L);
		return true;
}
/************************************************
*�������ƣ�walkRight()
*�������ܣ�������һ�������ɹ����򷵻�ture����ʧ�ܣ��򷵻�false
*�޸�ʱ�䣺2016.7.18
*************************************************/
bool MazeMan::walkRight()
{
	if(m_pMap->getMap()[m_COORDManCurrentPosition.Y][m_COORDManCurrentPosition.X + 1])
		return false;
	else 
		moveForward(R);
		return true;
}
/************************************************
*�������ƣ�start()
*�������ܣ���Ϸ��ʼ����
*�޸�ʱ�䣺2016.7.18
*************************************************/
void MazeMan::start()
{
	while(true)
	{
		m_pMap->pintMazeMap();
		switch(m_cManFace)
		{
		case U:
			//��Ϸ��ɫ����ʱ�������ң������ϣ�������������£�����ԭ��
			walkRight() || walkUp() || walkLeft() || walkDown();
			break;
		case D:
			walkLeft() || walkDown() || walkRight() || walkUp();
			break;
		case L:
			walkUp() || walkLeft() || walkDown() || walkRight();
			break;
		case R:
			walkDown() || walkRight() || walkUp() || walkLeft();
			break;
		default:
			break;
		}
		m_iSteps++;
		if(m_COORDManCurrentPosition.X == m_pMap->m_COORDExitPostion.X && m_COORDManCurrentPosition.Y == m_pMap->m_COORDExitPostion.Y)
			break;
		std::cout << "�Ѿ�����" << m_iSteps - 1 << "��";
		Sleep(500);
	}
}