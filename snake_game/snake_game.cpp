#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void gotoxy(int x, int y) {						     //
	COORD pos = { x, y };						     //
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE); // display clear
	SetConsoleCursorPosition(output, pos);           // 
}													 //

const int HEIGHT = 30;
const int WIDTH = 50;

char snake = 'O';

int snake_X = WIDTH / 2;
int snake_Y = HEIGHT / 2;

bool isRunning = true;

void LoadingMenu()
{
	string text = "Loading";
	for (int i = 0; i < 4; ++i)
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\t\tOptimize the system\n\n";
		cout << "\t\t     " << text << "\n\n\n\n\n\n\n\n\n\n";
		Sleep(500);
		gotoxy(0, 0);
		text += ".";
	}
}

void isEnd()
{
	if (snake_X == 0 || snake_Y == 0 || WIDTH - 1 == snake_X || HEIGHT - 1 == snake_Y)
	{
		isRunning = false;
	}
}


void createArea(char arr[HEIGHT][WIDTH])
{
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
}

void printArea(char arr[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}




int UP = 0;     // W
int DOWN = 1;	// S
int LEFT = 2;   // A
int RIGHT = 3;  // D

int direction = RIGHT;



int main()
{
	LoadingMenu();

	char arr[HEIGHT][WIDTH];

	createArea(arr);

	while (isRunning)
	{
		if (GetKeyState('W') & 0x8000)
		{
			if (direction != DOWN)
			{
				direction = UP;
			}
		}
		if (GetKeyState('S') & 0x8000)
		{
			if (direction != UP)
			{
				direction = DOWN;
			}
		}
		if (GetKeyState('A') & 0x8000)
		{
			if (direction != RIGHT)
			{
				direction = LEFT;
			}
		}
		if (GetKeyState('D') & 0x8000)
		{
			if (direction != LEFT)
			{
				direction = RIGHT;
			}
		}

		if (direction == UP)
		{
			arr[snake_Y][snake_X] = ' ';
			snake_Y--;
		}

		if (direction == DOWN)
		{
			arr[snake_Y][snake_X] = ' ';
			snake_Y++;
		}

		if (direction == LEFT)
		{
			arr[snake_Y][snake_X] = ' ';
			snake_X--;
		}

		if (direction == RIGHT)
		{
			arr[snake_Y][snake_X] = ' ';
			snake_X++;
		}
		

		arr[snake_Y][snake_X] = snake;

		printArea(arr);

		cout << "X pos: " << snake_X << endl;
		cout << "Y pos: " << snake_Y << endl;

		

		gotoxy(0, 0);

		isEnd();
		if (isRunning == false)
		{
			system("CLS");
			system("color 2");
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\tGame Over\n\n\n\n\n\n\n\n\n\n" << endl;
			return 0;
		}
		
	}
	

	
	
	return 0;
}