#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//测试三子棋游戏

void menu() {
	printf("****************************************************\n");
	printf("************     1. play    0. exit    *************\n");
	printf("****************************************************\n");

}

//游戏的主体部分
void game() {
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1) {
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		for (int i = ROW - 1; i >= 0; i--) {
			for (int j = 0; j < COL; j++) {
				ret = IsWin(board, i, j);
				if (ret != 'C') {
					goto A;
				}
			}
		}

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		for (int i = ROW  - 1; i >= 0; i--) {
			for (int j = 0; j < COL; j++) {
				ret = IsWin(board, i, j);
				if (ret != 'C') {
					goto A;
				}
			}
		}
	}
	A:
	if (ret == '*') {
		printf("玩家赢！\n");
	}
	else if (ret == '#') {
		printf("电脑赢！\n");
	}
	else {
		printf("平局！\n");
	}
}

void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新选择:\n");
			break;
		}
	} while (input);
}

int main() {

	test();
	return 0;
}