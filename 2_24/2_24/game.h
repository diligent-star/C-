#define  _CRT_SECURE_NO_WARNINGS 1
#define ROW 5 /* 棋盘行 */
#define COL 5 /* 棋盘列 */
#define ROWS ROW+2
#define COLS COL+2
#define EASY_SET 3 /* 雷的个数 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 将棋盘初始化为set */
void InitBoard(char board[ROWS][COLS] , int rows, int cols, char set);
/*
** board[ROWS][COLS] 初始化的棋盘
** rows 初始化的行
** cols 初始化的列
** set 初始化后内容
*/

/*棋盘的打印*/
void DisplayBoard(char board[ROWS][COLS], int row, int col);
/*
** board[ROWS][COLS] 打印的棋盘 
** row 打印的行
** col 打印的列
*/

/*雷的设置*/
void SetMine(char mine[ROWS][COLS], int row, int col, int set_count);
/*
** board[ROWS][COLS] 带设置的棋盘
** row 设置行的范围上限
** col 设置列的范围上限
** set_count 设置雷的个数
*/

/*排查雷*/
FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
/*
** mine[ROWS][COLS] 雷的棋盘
** show[ROWS][COLS] 展示的棋盘
** row 排查行的范围
** col 排查列的范围
*/