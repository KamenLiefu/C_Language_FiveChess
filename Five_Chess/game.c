#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col) {
	//int i;
	//for (i = 0; i < row; i++) {
	//	//1.打印一行的数据
	//	printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
	//	//2.打印分割行
	//	if (i < row - 1) {
	//		printf("---|---|---\n");
	//	}

	//优化算法
	int i,j;
	for (i = 0; i < row; i++) {
		//1.打印一行的数据
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		// 2.打印分割行
			if (i < row - 1) {
				for (j = 0; j < col; j++) {
					printf("---");
					if (j < col - 1) {
						printf("|");
					}
				}
				printf("\n");
			}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x, y;
	printf("玩家走：\n");
	printf("请输入坐标:");
	while (1) {
		scanf("%d%d", &x, &y);
		//判断x,y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("该坐标被占用\n");
			}
		}
		else {
			printf("坐标非法,请重新输入!\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	int x=0, y=0;
	printf("电脑走:\n");
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}
//1.表示满了，0.表示没满
int IsFull(char board[ROW][COL], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col) {
	int i;
	//横三行
	for (i = 0; i < row; i++) {
		if ( board[i][0] == board[i][1] && board[i][1] ==board[i][2]&& board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][2] != ' ') {
			return board[i][2];
		}
	}
	//竖三列
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]&& board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[i][1] != ' ') {
			return board[2][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]&& board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[2][2] != ' ') {
		return board[2][2];
	}
	if (board[5][0] == board[4][1] && board[4][1] == board[3][2]&& board[3][3] == board[2][3] && board[2][3] == board[1][4] && board[2][2] != ' ') {
		return board[2][2];
	}
	//判断是否平局
	if (1 == IsFull(board, ROW, COL)) {
		return 'Q';
	}
	return 'C';
}
