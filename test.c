#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//������������Ϸ

void menu() {
	printf("****************************************************\n");
	printf("************     1. play    0. exit    *************\n");
	printf("****************************************************\n");

}

//��Ϸ�����岿��
void game() {
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1) {
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		for (int i = ROW - 1; i >= 0; i--) {
			for (int j = 0; j < COL; j++) {
				ret = IsWin(board, i, j);
				if (ret != 'C') {
					goto A;
				}
			}
		}

		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
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
		printf("���Ӯ��\n");
	}
	else if (ret == '#') {
		printf("����Ӯ��\n");
	}
	else {
		printf("ƽ�֣�\n");
	}
}

void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������������ѡ��:\n");
			break;
		}
	} while (input);
}

int main() {

	test();
	return 0;
}