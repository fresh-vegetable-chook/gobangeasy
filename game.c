#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void InitBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';

		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		if (i == 0) {
			for (int j = 0; j < col; j++) {
				if (j == col - 1) {
					printf(" ___ \n");
				}
				else
					printf(" ___");
			}
		}
		for (int j = 0; j < col; j++) {
			if (j == 0) {
				//打印一行的数据
				printf("|");
				printf(" %c ", board[i][j]);
				printf("|");
			}
			else if (j == col - 1) {
				printf(" %c ", board[i][j]);
				printf("|\n");
			}
			else {
				printf(" %c ", board[i][j]);
				printf("|");
			}

		}
		for (int k = 0; k < col; k++) {
			if (k == col - 1) {
				printf("|___|\n");
			}
			else
				printf("|___");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");

	while (1) {
		printf("请输入要走的坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row) {
			if (board[row - y][x - 1] == ' ') {
				board[row - y][x - 1] = '*';
				break;
			}
			else {
				printf("该坐标被占用！\n");
			}
		}
		else {
			printf("输入坐标有误，请重新输入！\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");

	while (1) {
		x = rand() % col;
		y = rand() % row;
		if (board[y][x] == ' ') {
			board[y][x] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col) {
	int i, j, k;
	const int step[4][2] = { {1,-0},{0,1},{1,1},{1,-1} };//四个方向
	for (i = 0; i < 4; i++) {
		int count = 0;
		const int d[2] = { 1,-1 };//方向正负
		for (j = 0; j < 2; j++) {
			for (k = 1; k <= 4; k++) {
				int r = row + k * d[j] * step[i][0];
				int c = col + k * d[j] * step[i][1];
				if (r >= 0 && r < ROW && c >= 0 && c < COL && board[row][col] == board[r][c]) {
					if (board[row][col] == '*') {
						count++;
					}
					if (board[row][col] == '#') {
						count--;
					}
				}
				else
					break;
			}
		}
			if (count == 4) {
				return '*';
			}
			
			if (count == -4) {
				return '#';
			}
	}
	if (CheckFull(board, ROW, COL) == 1)
		return 'Q';
	else
		return 'C';

}

int CheckFull(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
 }