#define  _CRT_SECURE_NO_WARNINGS 1
#define ROW 3 //行
#define COL 3 //列

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//board[ROW][COL] 数组首元素地址
//row 数组行数
//col 数组列数
void InitBoard(char board[ROW][COL], int row, int col);


//board[ROW][COL] 数组首元素地址
//row 数组行数
//col 数组列数
void DisplayBoard(char board[ROW][COL], int row, int col);


// board[ROW][COL] 数组首元素地址
//row 数组行数
//col 数组列数
void PlayerMove(char board[ROW][COL], int row, int col);

// board[ROW][COL] 数组首元素地址
//row 数组行数
//col 数组列数
void ComputerMove(char board[ROW][COL], int row, int col);


// board[ROW][COL] 数组首元素地址
//row 数组行数
//col 数组列数
char IsWin (char board[ROW][COL], int row, int col);