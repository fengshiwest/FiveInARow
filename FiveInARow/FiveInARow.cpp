// FiveInARow.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h> //键盘对应操作库文件
using namespace std;
char board[10][10];
char o;

void init() 
{
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 19; j++)
			board[i][j] = '+';
	for (int i = 1, ii = 0; ii <= 27; i++, ii += 3)
		board[0][i] = i + 64;
	for (int j = 1, jj = 0; jj <= 27; j++, jj += 3)
		board[j][0] = j + 64;
	board[0][0] = '*';
}

void display()
{
	cout << "|========================================|" << endl;
	for (int i = 0; i <= 9; i++)
	{
		cout << "|";
		for (int j = 0; j <= 9; j++)
		{
			cout << board[i][j];
			if (j != 9 && i != 0)
				cout << "---";
			else
				cout << "   ";
		}
		cout << "|" << endl;
		cout << " |   |   |   |   |   |   |   |   |   |   |" << endl;
	}
	cout << "|========================================|" << endl;
}

void place(bool color)
{
	string colour;
	char x, y;
	x = y = ' ';
	system("cls");  //调用DOS下的清屏命令
	display();
	if (!color)
		colour = "黑";
	if (color)
		colour = "白";
	cout << colour << "方放置棋子（请输入大写坐标）：";
	cin >> x >> y;
	if (x - 64 > 10 || y - 64 > 10 || x-64 < 1 || y-64 < 1)
	{
		cout << "坐标超出棋盘范围，请重新放置！" << endl;
		system("pause");
		place(color);
	}
	if (board[x - 64][y - 64] == 'B' || board[x - 64][y - 64] == 'W')
	{
		cout << "该位置已有棋子，请重新放置！" << endl;
		system("pause");
		place(color);
	}
	if (!color)
		board[x - 64][y - 64] = 'B';
	if (color)
		board[x - 64][y - 64] = 'W';
}

int compute()
{
	int num = 0;
	for(int i=1;i<10;i++)
		for (int j = 1; j < 10; j++)
		{
			if (board[i][j] == 'B' || board[i][j] == 'W')
				num++;
		}
	if (num == 81)
	{
		cout << "棋盘已满，请重新开始！" << endl;
		return 2;
	}
	for (int i = 1; i<10; i++)
		for (int j = 1; j < 10; j++)
		{
			if (board[i][j] == 'B'&&board[i][j + 1] == board[i][j] && board[i][j + 2] == board[i][j] && board[i][j + 3] == board[i][j] && board[i][j + 4] == board[i][j])
				return 0;
			if (board[i][j] == 'W'&&board[i][j + 1] == board[i][j] && board[i][j + 2] == board[i][j] && board[i][j + 3] == board[i][j] && board[i][j + 4] == board[i][j])
				return 1;
			if (board[i][j] == 'B'&&board[i + 1][j] == board[i][j] && board[i + 2][j] == board[i][j] && board[i + 3][j] == board[i][j] && board[i + 4][j] == board[i][j])
				return 0;
			if (board[i][j] == 'W'&&board[i + 1][j] == board[i][j] && board[i + 2][j] == board[i][j] && board[i + 3][j] == board[i][j] && board[i + 4][j] == board[i][j])
				return 1;
			if (board[i][j] == 'B'&&board[i + 1][j + 1] == board[i][j] && board[i + 2][j + 2] == board[i][j] && board[i + 3][j + 3] == board[i][j] && board[i + 4][j + 4] == board[i][j])
				return 0;
			if (board[i][j] == 'W'&&board[i + 1][j + 1] == board[i][j] && board[i + 2][j + 2] == board[i][j] && board[i + 3][j + 3] == board[i][j] && board[i + 4][j + 4] == board[i][j])
				return 1;
			if (board[i][j] == 'B'&&board[i + 1][j - 1] == board[i][j] && board[i + 2][j - 2] == board[i][j] && board[i + 3][j - 3] == board[i][j] && board[i + 4][j - 4] == board[i][j])
				return 0;
			if (board[i][j] == 'W'&&board[i + 1][j - 1] == board[i][j] && board[i + 2][j - 2] == board[i][j] && board[i + 3][j - 3] == board[i][j] && board[i + 4][j - 4] == board[i][j])
				return 1;
		}
		
}

int main()
{
	init();
	system("cls");
	cout << "双人五子棋小游戏" << endl;
	while (true)
	{
		place(0);
		if (compute() == 0)
		{	
			display();
			cout << "黑方胜！"<<endl;
			system("pause");		
			break;
		}
		if (compute() == 2)
		{
			display();
			cout << "平局！" << endl;
			system("pause");
			break;
		}
		place(1);
		if (compute() == 1)
		{
			display();
			cout << "白方胜！" << endl;
			system("pause");			
			break;
		}
		if (compute() == 2)
		{
			display();
			cout << "平局！" << endl;
			system("pause");			
			break;
		}
	}
    return 0;
}

