// Queens_1D.cpp : Defines the entry point for the console application.
//Jonathan Persaud
//Homework#6
//CS211

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int board[8] = { 0 };
	int c = 0;
	int count = 0;

nextColumn:
	c++;
	if (c == 8)
		goto print;
	board[c]--;

nextRow:
	board[c]++;
	if (board[c] == 8)
	{
		board[c] = 0;
		goto backTrack;
	}

	//Row test, up and down diagonal test
	for (int i = 0;i < c;i++)
		if (board[i] == board[c])
			goto nextRow;


	for (int i = 1;board[c] - i >= 0 && c - i >= 0;i++)
		if (board[c - i] == board[c] - i)
			goto nextRow;

	for (int i = 1;board[c] + i < 8 && c - i >= 0;i++)
		if (board[c - i] == board[c] + i)
			goto nextRow;

	goto nextColumn;

backTrack:
	c--;
	if (c == -1)
	{
		cout << count << endl;
		return 0;
	}
	goto nextRow;

print:
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
			if (board[j] == i)
				cout << 1;
			else cout << 0;
			cout << endl;
	}
	count++;
	cout<<endl;
	goto backTrack;
}

	
	
		


