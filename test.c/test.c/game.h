#define  _CRT_SECURE_NO_WARNINGS 1
#define ROW 3 //��
#define COL 3 //��

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//board[ROW][COL] ������Ԫ�ص�ַ
//row ��������
//col ��������
void InitBoard(char board[ROW][COL], int row, int col);


//board[ROW][COL] ������Ԫ�ص�ַ
//row ��������
//col ��������
void DisplayBoard(char board[ROW][COL], int row, int col);


// board[ROW][COL] ������Ԫ�ص�ַ
//row ��������
//col ��������
void PlayerMove(char board[ROW][COL], int row, int col);

// board[ROW][COL] ������Ԫ�ص�ַ
//row ��������
//col ��������
void ComputerMove(char board[ROW][COL], int row, int col);


// board[ROW][COL] ������Ԫ�ص�ַ
//row ��������
//col ��������
char IsWin (char board[ROW][COL], int row, int col);