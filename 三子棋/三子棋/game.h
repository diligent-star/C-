#define  _CRT_SECURE_NO_WARNINGS 1
#define ROW 3//控制行
#define COL 3//控制列

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InitBoard (char Board[ROW][COL],int row,int col);
void DisplayBoard (char Board[ROW][COL],int row,int col);
void Playermove (char Board[ROW][COL],int row,int col);
void AiMove(char Board[ROW][COL], int row, int col);
char IsWin(char Board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);