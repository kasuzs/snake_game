#include <iostream>
#include <windows.h>
using namespace std;

const int WIDTH = 25;
const int HEIGHT = 15;

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

char snake = 'O';

int main()
{
	char arr[HEIGHT][WIDTH];

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (i == 0 || j == 0 || HEIGHT - 1 == i || WIDTH - 1 == j)
			{
				arr[i][j] = '#';
			}
			else
			{
				arr[i][j] = ' ';
			}
		}
	}

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j) 
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	
	
	return 0;
}