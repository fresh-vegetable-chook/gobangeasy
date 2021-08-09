#define ROW 10
#define COL 10

#include<stdio.h>
#include<time.h>
#include<stdlib.h>


//����
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//��������������Ϸ״̬
//���Ӯ - '*'
//����Ӯ - '#'
//ƽ��   - 'Q'
//����   - 'C'

char IsWin(char board[ROW][COL], int row, int col);

int CheckFull(char board[ROW][COL], int row, int col);