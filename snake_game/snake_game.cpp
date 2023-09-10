#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>

using namespace std;

void gotoxy(short int x, short int y) {				 //
	COORD pos = { x, y };						     //
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE); // Display clear
	SetConsoleCursorPosition(output, pos);           // 
}													 //

const int HEIGHT = 30; // Area Height
const int WIDTH = 50;  // Area Width

int score = 0; // Game score

char snake = 'O'; // Snake
char apple = '*';



int snake_X = WIDTH / 2;  // Position of the snake in width
int snake_Y = HEIGHT / 2; // Position of the snake in height

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

int direction = RIGHT; // initial snake direction



int main()
{
	LoadingMenu();
	std::srand(time(nullptr));

	char arr[HEIGHT][WIDTH]{};

	int apple_X = rand() % WIDTH / 2;
	int apple_Y = rand() % HEIGHT / 2;

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

		arr[apple_Y][apple_X] = apple;

		if (snake_Y == apple_Y && snake_X == apple_X)
		{
			++score;
			arr[apple_Y][apple_X] = ' ';
			apple_X = 2 + rand() % ((WIDTH - 3));
			apple_Y = 2 + rand() % ((HEIGHT - 3));
		}

		printArea(arr);

		cout << "X pos: " << snake_X << endl;
		cout << "Y pos: " << snake_Y << endl;
		cout << "Score: " << score << endl;

		gotoxy(0, 0);

		isEnd();
		if (isRunning == false)
		{
			system("CLS");
			system("color 6");
			cout << "\n\n\n\n\n\n\n\n\n\n\t\tGame Over\n\n";
			cout << "\t      Total score: " << score << "\n\n\n\n\n\n\n\n\n" << endl;
			return 0;
		}
		
	}
	

	
	
	return 0;
}