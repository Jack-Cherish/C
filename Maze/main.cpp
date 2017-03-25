#include "MazeMap.h"
#include "MazeMan.h"

#define MapRow 11		//迷宫地图的行数
#define MapCol 11		//迷宫地图的列数

int main()
{
	//定义并初始化存储地图数据的二维数组
	int map[MapRow][MapCol] = {
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD},
		{WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, WALL},
		{WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
		{WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, WALL},
		{ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
	};
	//从堆中实例化地图对象
	MazeMap *mm = new MazeMap();
	mm->setMazeMap(&map[0][0],MapRow,MapCol);
	mm->setExitPosition(10,1);
	mm->pintMazeMap();
	//从堆中实例化游戏角色对象
	MazeMan *man = new MazeMan();
	//设置角色起始位置
	man->setPosition(0,9);
	//设置游戏要走的地图
	man->setMap(mm);
	//用new的方式从堆中实例化的对象，使用完毕之后需要手动释放内存
	man->start();
	delete mm;
	mm = NULL;
	delete man;
	man = NULL;
	std::cout << "闯关成功！" << std::endl;
	system("pause");
}
