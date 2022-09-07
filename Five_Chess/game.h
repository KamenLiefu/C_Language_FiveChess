#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 5
#define COL 5
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL], int row, int col);
//判断电脑四种游戏状态,电脑赢#，玩家赢*，平局Q，继续C
char IsWin(char board[ROW][COL],int row,int col);
#endif

