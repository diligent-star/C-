#define  _CRT_SECURE_NO_WARNINGS 1
//玩家棋盘
#define ROW 9 //行
#define COL 9 //列
//放雷的棋盘
#define ROWS ROW+2 //行
#define COLS COL+2 //列
#define Easy_Count 10

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);