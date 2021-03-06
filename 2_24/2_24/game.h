#define  _CRT_SECURE_NO_WARNINGS 1
#define ROW 5 /* ������ */
#define COL 5 /* ������ */
#define ROWS ROW+2
#define COLS COL+2
#define EASY_SET 3 /* �׵ĸ��� */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* �����̳�ʼ��Ϊset */
void InitBoard(char board[ROWS][COLS] , int rows, int cols, char set);
/*
** board[ROWS][COLS] ��ʼ��������
** rows ��ʼ������
** cols ��ʼ������
** set ��ʼ��������
*/

/*���̵Ĵ�ӡ*/
void DisplayBoard(char board[ROWS][COLS], int row, int col);
/*
** board[ROWS][COLS] ��ӡ������ 
** row ��ӡ����
** col ��ӡ����
*/

/*�׵�����*/
void SetMine(char mine[ROWS][COLS], int row, int col, int set_count);
/*
** board[ROWS][COLS] �����õ�����
** row �����еķ�Χ����
** col �����еķ�Χ����
** set_count �����׵ĸ���
*/

/*�Ų���*/
FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
/*
** mine[ROWS][COLS] �׵�����
** show[ROWS][COLS] չʾ������
** row �Ų��еķ�Χ
** col �Ų��еķ�Χ
*/