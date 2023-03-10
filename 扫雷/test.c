#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()
{
	//雷的信息存储 
	//写两个数组：
	//1个数组存放布置好的雷的信息
	//1个数组存放排查出的雷的信息
	//如果想实现9 * 9的棋盘，数组的大小设计成11 * 11比较好
	char mine[ROWS][COLS]={0};//存放布置好的雷的信息
	char show[ROWS][COLS]={0};//存放排查出的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印下棋盘

	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}
void menu()
{
	printf("*******************************\n");
	printf("******     1.play   ***********\n");
	printf("******     0.exit   ***********\n");
	printf("*******************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}