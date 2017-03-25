#include "MazeMan.h"

/************************************************
*函数名称：MazeMan()
*函数功能：构造函数，初始化数据成员
*函数参数：man 表示游戏角色的字符
		   manface 游戏角色的朝向
*修改时间：2016.7.18
*************************************************/
MazeMan::MazeMan(char man,char manface)
{
	m_cMan = man;
	m_cManFace = manface;
	m_iSteps = 0;
}
/************************************************
*函数名称：setMap()
*函数功能：设置地图对象中的地图
*函数参数：*map 地图对象的指针
*修改时间：2016.7.18
*************************************************/
void MazeMan::setMap(MazeMap *map)
{
	m_pMap = map;
}

/************************************************
*函数名称：setPosition()
*函数功能：设置游戏角色位置
*函数参数：x 角色所在位置的横坐标
		   y 角色所在位置的纵坐标
*修改时间：2016.7.18
*************************************************/
void MazeMan::setPosition(int x, int y)
{
	unsigned long numWritten;
	//获得命令行窗口的窗口句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_COORDManCurrentPosition.X = x;
	m_COORDManCurrentPosition.Y = y;
	//在指定坐标位置填充指定的字符,这里我们在游戏角色的当前位置填充代表游戏角色的字符，使游戏角色采出现
	FillConsoleOutputCharacter(handle,m_cMan,1,m_COORDManCurrentPosition,&numWritten);
	//参数说明：控制台屏幕缓冲区句柄，要向控制台缓冲区写入的字符；应写入的字符单元数；
	//一个COORD结构，它指定字符的字符是要写的第一个单元格的坐标；
	//指向接收的实际写入控制台屏幕缓冲区的字符数的变量的指针。
}
/************************************************
*函数名称：moveForward()
*函数功能：根据传入的方向让游戏角色前进一步
*函数参数：direct 移动的方向
*修改时间：2016.7.18
*************************************************/
void MazeMan::moveForward(direction direct)
{
	unsigned long numWritten;
	//获取命令行窗口的窗口句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//在指定坐标位置填充指定的字符,这里我们在游戏角色的当前位置填充空格，使游戏角色消失
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
	//游戏角色坐标更新，在新的坐标
	FillConsoleOutputCharacter(handle,m_cMan,1,m_COORDManCurrentPosition,&numWritten);
	//移动完成后跟新游戏角色的朝向
	m_cManFace = direct;
}

/************************************************
*函数名称：walkUp()
*函数功能：向上走一步，若成功，则返回ture；若失败，则返回false
*修改时间：2016.7.18
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
*函数名称：walkDown()
*函数功能：向下走一步，若成功，则返回ture；若失败，则返回false
*修改时间：2016.7.18
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
*函数名称：walkLeft()
*函数功能：向左走一步，若成功，则返回ture；若失败，则返回false
*修改时间：2016.7.18
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
*函数名称：walkRight()
*函数功能：向右走一步，若成功，则返回ture；若失败，则返回false
*修改时间：2016.7.18
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
*函数名称：start()
*函数功能：游戏开始函数
*修改时间：2016.7.18
*************************************************/
void MazeMan::start()
{
	while(true)
	{
		m_pMap->pintMazeMap();
		switch(m_cManFace)
		{
		case U:
			//游戏角色朝上时，先向右，再向上，再向左，最后向下（右手原则）
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
		std::cout << "已经走了" << m_iSteps - 1 << "步";
		Sleep(500);
	}
}