#include "MazeMap.h"
#include "MazeMan.h"

#define MapRow 11		//�Թ���ͼ������
#define MapCol 11		//�Թ���ͼ������

int main()
{
	//���岢��ʼ���洢��ͼ���ݵĶ�ά����
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
	//�Ӷ���ʵ������ͼ����
	MazeMap *mm = new MazeMap();
	mm->setMazeMap(&map[0][0],MapRow,MapCol);
	mm->setExitPosition(10,1);
	mm->pintMazeMap();
	//�Ӷ���ʵ������Ϸ��ɫ����
	MazeMan *man = new MazeMan();
	//���ý�ɫ��ʼλ��
	man->setPosition(0,9);
	//������ϷҪ�ߵĵ�ͼ
	man->setMap(mm);
	//��new�ķ�ʽ�Ӷ���ʵ�����Ķ���ʹ�����֮����Ҫ�ֶ��ͷ��ڴ�
	man->start();
	delete mm;
	mm = NULL;
	delete man;
	man = NULL;
	std::cout << "���سɹ���" << std::endl;
	system("pause");
}
