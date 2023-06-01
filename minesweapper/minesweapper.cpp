#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <string>
#include <iomanip>

#define closedCell 0
#define freeCell 0
#define explodedMine 1
#define uncheckedCell 2
#define openedCell 3
#define flagMine 4
#define mine 9

using namespace std;

void recordInResultsList(int minutes, int seconds, string selectedPreset)
{
	void callGameMenu();

	string name;
	ofstream out;

	system("cls");
	cout << "#######################################" << endl;
	cout << "###        Запись результата        ###" << endl;
	cout << "#######################################" << endl;

	if (minutes < 10)
		cout << "### Ваше время - 0" << minutes << " минут ";
	else
		cout << "### Ваше время - " << minutes << " минут ";
	if (seconds < 10)
		cout << "0" << seconds << " секунд ###" << endl;
	else
		cout << seconds << " секунд ###" << endl;

	cout << "### Введите ваше имя: ";
	cin >> name;

	out.open("G:/УП/minesweapper/Rating.txt", std::ios::binary | std::ios::app);
	if (out.is_open())
	{
		out << "\n" << name << " " << selectedPreset;
		if (minutes < 10)
			out << " 0" << minutes;
		else
			out << " " << minutes;
		if (seconds < 10)
			out << " 0" << seconds;
		else
			out << " " << seconds;
	}
	else
	{
		cout << "#######################################" << endl;
		cout << "###   Файл для записи отсутствует   ###" << endl;
		cout << "#######################################" << endl;

	}
	out.close();

	cout << "#######################################" << endl;
	cout << "###  Ваши данные  успешно записаны  ###" << endl;
	cout << "#######################################" << endl;
	Sleep(500);

	callGameMenu();
}

void printResultsList()
{
	ifstream in;
	string word;
	int counter = 1;

	system("cls");
	cout << "###########################################################################" << endl;
	cout << "###                         Список  результатов                         ###" << endl;
	cout << "###########################################################################" << endl;

	in.open("G:/УП/minesweapper/Rating.txt");
	if (in.is_open())
	{
		for (int i = 0; i < 75; i++)
		{
			if (i >= 0 && i <= 2)
				cout << "#";
			else if (i == 3)
				cout << " ";
			else if (i == 4)
				cout << "+";
			else if (i == 30)
				cout << "+";
			else if (i == 49)
				cout << "+";
			else if (i == 70)
				cout << "+";
			else if (i == 71)
				cout << " ";
			else if (i >= 72 && i <= 74)
				cout << "#";
			else
				cout << "-";
		}

		cout << endl << "### |";
		cout << setw(14) << right << "Имя" << setw(12) << "|" << setw(11) << right << "Режим" << setw(8) << "|" << setw(13) << right << "Время" << setw(12) << "| ###" << endl;

		for (int i = 0; i < 75; i++)
		{
			if (i >= 0 && i <= 2)
				cout << "#";
			else if (i == 3)
				cout << " ";
			else if (i == 4)
				cout << "+";
			else if (i == 30)
				cout << "+";
			else if (i == 49)
				cout << "+";
			else if (i == 70)
				cout << "+";
			else if (i == 71)
				cout << " ";
			else if (i >= 72 && i <= 74)
				cout << "#";
			else
				cout << "-";
		}
		cout << endl;

		while (in >> word)
		{
			if (counter % 10 == 1)
				cout << "### | " << setw(24) << left << word << "| ";
			else if (counter % 10 == 2)
				cout << setw(17) << word << "| ";
			else if (counter % 10 == 3)
				cout << word << " минут ";
			else if (counter % 10 == 4)
			{
				cout << word;
				cout << " секунд | ###" << endl;
				counter = 0;
			}

			counter++;
		}

		for (int i = 0; i < 75; i++)
		{
			if (i >= 0 && i <= 2)
				cout << "#";
			else if (i == 3)
				cout << " ";
			else if (i == 4)
				cout << "+";
			else if (i == 30)
				cout << "+";
			else if (i == 49)
				cout << "+";
			else if (i == 70)
				cout << "+";
			else if (i == 71)
				cout << " ";
			else if (i >= 72 && i <= 74)
				cout << "#";
			else
				cout << "-";
		}

		cout << endl << "###########################################################################" << endl;

	}
	else
	{
		cout << "###                         Записи  отсутствуют                         ###" << endl;
		cout << "###########################################################################" << endl;
	}

	in.close();
}

void printRules()
{
	system("cls");
	cout << "########################################################################" << endl;
	cout << "###                          Описание  игры                          ###" << endl;
	cout << "########################################################################" << endl;
	cout << "### Целью игры является открытие всех ячеек, не содержащих мины.     ###" << endl;
	cout << "### После выбора режима игры, на поле рандомно расставляются мины,   ###" << endl;
	cout << "### на которые игрок не должен попасться.                            ###" << endl;
	cout << "### Для начала игры необходимо наугад открыть первую ячейку.         ###" << endl;
	cout << "### Если рядом с этой ячейкой располагаются несколько свободных      ###" << endl;
	cout << "### ячеек, то они все откроются.                                     ###" << endl;
	cout << "### Числовые значения в ячейках указывают на количество мин в        ###" << endl;
	cout << "### соседних.                                                        ###" << endl;
	cout << "### С помощью этих подсказок можно определить, где расположены мины: ###" << endl;
	cout << "### число 1 указывает, что из ячеек сверху, слева, снизу, справа и   ###" << endl;
	cout << "### по диагонали от открытой лишь одна содержит мину;                ###" << endl;
	cout << "### вокруг ячеек с числом 2 находится по 2 мины и так далее до 8.    ###" << endl;
	cout << "### Если игрок попадется на ячейку с миной, то игра завершается.     ###" << endl;
	cout << "### Для удобства игры ячейки с минами можно отмечать щелчком правой  ###" << endl;
	cout << "### кнопки мыши - на данной ячейке появится указатель. Если отметка  ###" << endl;
	cout << "### была ошибочной, то указатель можно снять повторным щелчком.      ###" << endl;
	cout << "### Для победы необходимо открыть все ячейки без мин.                ###" << endl;
	cout << "########################################################################" << endl;
	cout << "###                  Приятной игры и удачи на поле!                  ###" << endl;
	cout << "########################################################################" << endl;
}

void callGameMenu()
{
	void selectPreset();

	char option;
	char toMainMenu;

	do {
		system("cls");
		cout << "#################################################" << endl;
		cout << "###       Добро пожаловать в игру САПЁР       ###" << endl;
		cout << "#################################################" << endl;
		cout << "###     Управление в  меню осуществляется     ###" << endl;
		cout << "###     с помощью ввода  номеров  команд,     ###" << endl;
		cout << "###     представленных     на     экране.     ###" << endl;
		cout << "#################################################" << endl;
		cout << "###     1 - Начать игру                       ###" << endl;
		cout << "###     2 - Правила игры                      ###" << endl;
		cout << "###     3 - Список победных результатов       ###" << endl;
		cout << "###     0 - Выход из игры                     ###" << endl;
		cout << "#################################################" << endl;
		cout << "> ";
		cin >> option;

		switch (option)
		{
		case '1': {
			selectPreset();
			break;
		}
		case '2': {
			printRules();

			cout << "###            Введите 0,  чтобы вернуться в главное меню            ###" << endl;
			cout << "########################################################################" << endl;
			cout << "> ";
			cin >> toMainMenu;

			if (toMainMenu == '0')
				break;
		}
		case '3': {
			printResultsList();
			cout << "###              Введите 0, чтобы вернуться в главное меню              ###" << endl;
			cout << "###########################################################################" << endl;
			cout << "> ";
			cin >> toMainMenu;

			if (toMainMenu == '0')
				break;
		}
		case '0': {
			cout << "#################################################" << endl;
			cout << "###             Вы покинули  игру             ###" << endl;
			cout << "#################################################" << endl;
			break;
		}
		default: {
			callGameMenu();
			break;
		}
		}
	} while (option != '0');
	system("pause");
}

char** generateField(char** field, int fieldHeight, int fieldWidth, int mines)
{
	int usedSpace = 0;
	int mineSpace = 0;

	field = new char* [fieldHeight];
	//Создание поля с пустыми ячейками
	for (int i = 0; i < fieldHeight; i++)
	{
		field[i] = new char[fieldWidth];

		for (int j = 0; j < fieldWidth; j++)
			field[i][j] = freeCell;
	}
	//Размещение мин на поле
	for (int i = 0; i < fieldHeight; i++)
	{
		for (int j = 0; j < fieldWidth; j++)
		{
			if (mines <= 0)
				break;

			if (field[i][j] == mine)
			{
				mineSpace++;
				continue;
			}

			if (rand() % ((fieldHeight * fieldWidth) - (i * fieldWidth) - j - usedSpace + mineSpace) == 0)
			{
				field[i][j] = mine;
				mines--;
				usedSpace++;
				mineSpace = i = 0;
				j = -1;
			}
		}
	}
	//Размещение цифр
	for (int i = 0; i < fieldHeight; i++)
	{
		for (int j = 0; j < fieldWidth; j++)
		{
			if (field[i][j] > 8)
			{
				if (i - 1 >= 0 && field[i - 1][j] != mine)
					field[i - 1][j]++;
				if (i + 1 < fieldHeight && field[i + 1][j] != mine)
					field[i + 1][j]++;
				if (j - 1 >= 0 && field[i][j - 1] != mine)
					field[i][j - 1]++;
				if (j + 1 < fieldWidth && field[i][j + 1] != mine)
					field[i][j + 1]++;
				if (i - 1 >= 0 && j - 1 >= 0 && field[i - 1][j - 1] != mine)
					field[i - 1][j - 1]++;
				if (i - 1 >= 0 && j + 1 < fieldWidth && field[i - 1][j + 1] != mine)
					field[i - 1][j + 1]++;
				if (i + 1 < fieldHeight && j - 1 >= 0 && field[i + 1][j - 1] != mine)
					field[i + 1][j - 1]++;
				if (i + 1 < fieldHeight && j + 1 < fieldWidth && field[i + 1][j + 1] != mine)
					field[i + 1][j + 1]++;
			}
		}
	}

	cout << "#################################################" << endl;
	cout << "###    Игровое поле  успешно сгенерировано    ###" << endl;
	cout << "#################################################" << endl;

	Sleep(1000);

	return field;
}

int checkNearCell(char** field, char** playerView, int check, int i, int j)
{
	if (field[i][j] == freeCell && playerView[i][j] == closedCell)
	{
		playerView[i][j] = uncheckedCell;
		check++;
	}

	if (field[i][j] > 0 && field[i][j] < 9 && playerView[i][j] == closedCell)
	{
		playerView[i][j] = openedCell;
	}

	return check;
}

void openSpace(char** field, char** playerView, int fieldHeight, int fieldWidth, int x, int y)
{
	int checkedCells = 0;
	int xDiv2 = x / 2 - 2;
	//Берутся только нечетные координаты, так как после каждой ячейки идет пробел
	if (!(x % 2))
	{
		if (y - 1 < fieldHeight && xDiv2 < fieldWidth)
		{
			if (playerView[y - 1][xDiv2] == closedCell && field[y - 1][xDiv2] != 0)
				playerView[y - 1][xDiv2] = openedCell;

			if (playerView[y - 1][xDiv2] == closedCell && field[y - 1][xDiv2] == freeCell)
			{
				playerView[y - 1][xDiv2] = uncheckedCell;
				checkedCells++;
				// i = 1 и j = 4, из-за рамки в консоли
				for (int i = 1; i < fieldHeight + 1; i++)
				{
					for (int j = 4; j < fieldWidth + 4; j++)
					{
						if (playerView[i - 1][j - 4] == uncheckedCell)
						{
							playerView[i - 1][j - 4] = openedCell;
							checkedCells--;
							//Проверка ячеек вокруг выбранной
							if (i - 1 - 1 >= 0)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1 - 1, j - 4);
							if (i - 1 - 1 >= 0 && j - 4 - 1 >= 0)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1 - 1, j - 4 - 1);
							if (j - 4 - 1 >= 0)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1, j - 4 - 1);
							if (i - 1 + 1 < fieldHeight && j - 4 - 1 >= 0)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1 + 1, j - 4 - 1);
							if (i - 1 + 1 < fieldHeight)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1 + 1, j - 4);
							if (i - 1 + 1 < fieldHeight && j - 4 + 1 < fieldWidth)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1 + 1, j - 4 + 1);
							if (j - 4 + 1 < fieldWidth)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1, j - 4 + 1);
							if (i - 1 - 1 >= 0 && j - 4 + 1 < fieldWidth)
								checkedCells = checkNearCell(field, playerView, checkedCells, i - 1 - 1, j - 4 + 1);
							if (checkedCells > 0)
								i = 1;

							j = 3;
						}
					}
				}
			}

			if (field[y - 1][xDiv2] == mine && playerView[y - 1][xDiv2] != flagMine)
				playerView[y - 1][xDiv2] = explodedMine;
		}
	}
}

void gameplay(char** field, int fieldHeight, int fieldWidth, int mines, string selectedPreset)
{
	HANDLE hIn;
	HANDLE hOut;
	INPUT_RECORD inRec;
	DWORD numRead;
	CONSOLE_CURSOR_INFO curs;
	CONSOLE_SCREEN_BUFFER_INFO buffer;
	COORD zero = { 0,0 };
	boolean isGameOver = false;
	boolean isWin = false;
	int x;
	int y;
	int xDiv2;
	int flag = 0;
	int cleanSpace = 2;
	int markedMines = 0;
	int openedCells = 0;
	int minesAtBeginning = mines;
	char** playerView = new char* [fieldHeight];

	clock_t startTime = clock();
	//Скрытие игрового поля для игрока
	for (int i = 0; i < fieldHeight; i++)
	{
		playerView[i] = new char[fieldWidth];

		for (int j = 0; j < fieldWidth; j++)
			playerView[i][j] = closedCell;
	}
	//Определение длины количествава мин для вывода в консоль
	for (int i = mines; (i /= 10) > 0;)
		cleanSpace++;

	system("cls");
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hOut, &curs);
	SetConsoleMode(hIn, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	// пока игра не кончилась
	while (!isGameOver)
	{
		curs.bVisible = false;
		SetConsoleCursorInfo(hOut, &curs);
		SetConsoleCursorPosition(hOut, zero);
		// вывод игрового поля
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29; i++)
				cout << "#";
		}
		else
		{
			for (int i = 0; i < fieldWidth * 2 + 7; i++)
				cout << "#";
		}
		cout << endl;

		for (int i = 0; i < fieldHeight; i++)
		{
			cout << "### ";
			for (int j = 0; j < fieldWidth; j++)
			{
				switch (playerView[i][j])
				{
				case closedCell: {
					SetConsoleTextAttribute(hOut, (WORD)(0 | 8));
					WriteConsoleW(hOut, L"■ ", wcslen(L"■ "), NULL, NULL);
					SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
					break;
				}
				case explodedMine: {
					SetConsoleTextAttribute(hOut, (WORD)(0 | 4));
					WriteConsoleW(hOut, L"☼ ", wcslen(L"☼ "), NULL, NULL);
					SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
					isGameOver = true;
					break;
				}
				case openedCell: {
					openedCells++;

					switch (field[i][j])
					{
					case freeCell: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 8));
						WriteConsoleW(hOut, L"□ ", wcslen(L"□ "), NULL, NULL);
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 1: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 9));
						cout << "1 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 2: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 10));
						cout << "2 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 3: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 12));
						cout << "3 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 4: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 5));
						cout << "4 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 5: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 4));
						cout << "5 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 6: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 1));
						cout << "6 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 7: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 2));
						cout << "7 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 8: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 8));
						cout << "8 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case mine: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						WriteConsoleW(hOut, L"☼ ", wcslen(L"☼ "), NULL, NULL);
					}
					}
					break;
				}
				case flagMine: {
					SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
					WriteConsoleW(hOut, L"X ", wcslen(L"X "), NULL, NULL);
					SetConsoleTextAttribute(hOut, (WORD)(0 | 15));

					if (field[i][j] == mine)
						markedMines++;
					else
						markedMines--;
				}
				}
			}

			if (fieldWidth * 2 + 7 < 29)
			{
				for (int i = 0; i < 29 / 2 - fieldWidth * 2 + 8; i++)
					cout << " ";
			}
			cout << "###";
			cout << endl;
		}
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29; i++)
				cout << "#";
		}
		else
		{
			for (int i = 0; i < fieldWidth * 2 + 7; i++)
				cout << "#";
		}
		cout << endl;
		// проверка условий для победы
		if (markedMines == minesAtBeginning || openedCells >= (fieldHeight * fieldWidth - minesAtBeginning))
			isWin = isGameOver = true;

		openedCells = 0;
		markedMines = 0;
		// вывод рамки снизу
		cout << "###";
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29 / 2 - 11; i++)
				cout << " ";
		}
		for (int i = 0; i < fieldWidth - 9; i++)
			cout << " ";
		cout << " Осталось ";
		for (int i = cleanSpace; i != 0; i--)
			cout << " ";
		GetConsoleScreenBufferInfo(hOut, &buffer);
		buffer.dwCursorPosition.X -= cleanSpace;
		SetConsoleCursorPosition(hOut, buffer.dwCursorPosition);
		cout << mines;
		if (mines < 10)
			cout << "  ";
		if (mines / 10 >= 1)
			cout << " ";
		cout << " мин";
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29 / 2 - 11; i++)
				cout << " ";
		}
		for (int i = 0; i < fieldWidth - 8; i++)
			cout << " ";
		cout << "###" << endl;
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29; i++)
				cout << "#";
		}
		else
		{
			for (int i = 0; i < fieldWidth * 2 + 7; i++)
				cout << "#";
		}
		cout << endl;
		cout << "### ";
		for (int i = 0; i < fieldWidth - 11; i++)
			cout << " ";
		cout << "Нажмите 0  для выхода";
		for (int i = 0; i < fieldWidth - 11; i++)
			cout << " ";
		cout << " ###" << endl;
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29; i++)
				cout << "#";
		}
		else
		{
			for (int i = 0; i < fieldWidth * 2 + 7; i++)
				cout << "#";
		}
		cout << endl;
		curs.bVisible = true;
		SetConsoleCursorInfo(hOut, &curs);
		ReadConsoleInput(hIn, &inRec, 1, &numRead);

		// обработка нажатия кнопок мыши
		switch (inRec.EventType)
		{
		case MOUSE_EVENT: {
			// открытие ячейки
			if (inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				x = inRec.Event.MouseEvent.dwMousePosition.X;
				y = inRec.Event.MouseEvent.dwMousePosition.Y;
				if (x <= 3 || y <= 0)
					continue;
				else
					openSpace(field, playerView, fieldHeight, fieldWidth, x, y);
			}
			// установка флажка
			if (inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				x = inRec.Event.MouseEvent.dwMousePosition.X;
				y = inRec.Event.MouseEvent.dwMousePosition.Y;
				if (x <= 3 || y <= 0)
					continue;
				else
				{
					xDiv2 = x / 2 - 2;

					if (y - 1 < fieldHeight && xDiv2 < fieldWidth && !(x % 2))
					{
						if (playerView[y - 1][xDiv2] == closedCell)
							flag = 1;
						if (playerView[y - 1][xDiv2] == flagMine)
							flag = 2;
						if (flag == 1)
						{
							playerView[y - 1][xDiv2] = flagMine;
							mines--;
						}
						if (flag == 2)
						{
							playerView[y - 1][xDiv2] = closedCell;
							mines++;
						}

						flag = 0;
					}
				}
				break;
			}
		}
		case KEY_EVENT: {
			if (inRec.Event.KeyEvent.uChar.AsciiChar == '0')
				isGameOver = true;
		}
		}
	}
	// конец игры
	if (isGameOver)
	{
		clock_t endTime = clock();

		system("cls");
		SetConsoleCursorPosition(hOut, zero);
		// вывод открытого игрового поля
		for (int i = 0; i < fieldHeight; i++)
		{
			playerView[i] = new char[fieldWidth];

			for (int j = 0; j < fieldWidth; j++)
				playerView[i][j] = openedCell;
		}
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29; i++)
				cout << "#";
		}
		else
		{
			for (int i = 0; i < fieldWidth * 2 + 7; i++)
				cout << "#";
		}
		cout << endl;
		for (int i = 0; i < fieldHeight; i++)
		{
			cout << "### ";
			for (int j = 0; j < fieldWidth; j++)
			{
				switch (playerView[i][j])
				{
				case openedCell: {

					switch (field[i][j])
					{
					case freeCell: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 8));
						WriteConsoleW(hOut, L"□ ", wcslen(L"□ "), NULL, NULL);
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 1: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 9));
						cout << "1 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 2: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 10));
						cout << "2 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 3: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 12));
						cout << "3 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 4: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 5));
						cout << "4 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 5: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 4));
						cout << "5 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 6: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 1));
						cout << "6 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 7: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 2));
						cout << "7 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case 8: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 8));
						cout << "8 ";
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
						break;
					}
					case mine: {
						SetConsoleTextAttribute(hOut, (WORD)(0 | 4));
						WriteConsoleW(hOut, L"☼ ", wcslen(L"☼ "), NULL, NULL);
						SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
					}
					}
					break;
				}
				}
			}

			if (fieldWidth * 2 + 7 < 29)
			{
				for (int i = 0; i < 29 / 2 - fieldWidth * 2 + 8; i++)
					cout << " ";
			}
			cout << "###";
			cout << endl;
		}
		if (fieldWidth * 2 + 7 < 29)
		{
			for (int i = 0; i < 29; i++)
				cout << "#";
		}
		else
		{
			for (int i = 0; i < fieldWidth * 2 + 7; i++)
				cout << "#";
		}
		cout << endl << endl;
		// при победе
		if (isWin)
		{
			int time = (int)(endTime - startTime) / CLOCKS_PER_SEC;
			int minutes = 0;
			int seconds = 0;
			char option;

			do
			{
				minutes = time / 60;
				seconds = time % 60;

				cout << "#########################################" << endl;
				SetConsoleTextAttribute(hOut, (WORD)(0 | 10));
				cout << "###             !ПОБЕДА!              ###" << endl;
				SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
				cout << "#########################################" << endl;
				cout << "###  Ваше время -";
				if (minutes < 10)
					cout << " 0" << minutes << " минут";
				else
					cout << " " << minutes << " минут";
				if (seconds < 10)
					cout << " 0" << seconds << " секунд  ###" << endl;
				else
					cout << " " << seconds << " секунд  ###" << endl;
				cout << "#########################################" << endl;
				cout << "### Желаете сохранить свой результат? ###" << endl;
				cout << "#########################################" << endl;
				cout << "###     1 - Сохранить результат       ###" << endl;
				cout << "###     0 - Выход в главное меню      ###" << endl;
				cout << "#########################################" << endl;
				cout << "> ";
				cin >> option;

				switch (option)
				{
				case '1':
					recordInResultsList(minutes, seconds, selectedPreset);
					break;
				case '0':
					callGameMenu();
					break;
				default:
					callGameMenu();
					break;
				}
			} while (option != '0');
		}
		// при поражении
		else
		{
			cout << "#########################################" << endl;
			SetConsoleTextAttribute(hOut, (WORD)(0 | 4));
			cout << "###             ПОРАЖЕНИЕ             ###" << endl;
			SetConsoleTextAttribute(hOut, (WORD)(0 | 15));
			cout << "#########################################" << endl;
			cout << "### Нажмите любую  клавишу для выхода ###" << endl;
			cout << "#########################################" << endl;

			do {
				ReadConsoleInput(hIn, &inRec, 1, &numRead);
			} while (inRec.EventType != KEY_EVENT);

			callGameMenu();
		}
	}
}

void selectPreset()
{
	int fieldHeight, fieldWidth, minesCheck;
	int mines = 0;
	char option;
	char** field = new char*;
	boolean fieldWasGenerated = false;
	string selectedPreset;

	system("cls");
	do
	{
		cout << "#################################################" << endl;
		cout << "###            Выберите режим игры            ###" << endl;
		cout << "#################################################" << endl;
		cout << "###     1 - Легкий - поле 8x8, 12 мин         ###" << endl;
		cout << "###     2 - Средний - поле 11x11, 24 мины     ###" << endl;
		cout << "###     3 - Сложный - поле 16x16, 50 мин      ###" << endl;
		cout << "###     4 - Настраиваемый                     ###" << endl;
		cout << "###     0 - Вернуться в главное меню          ###" << endl;
		cout << "#################################################" << endl;
		cout << "> ";
		cin >> option;

		switch (option)
		{
		case '1': {
			fieldHeight = fieldWidth = 8;
			mines = 12;
			field = generateField(field, fieldHeight, fieldWidth, mines);
			fieldWasGenerated = true;
			selectedPreset = "Easy_8x8_12";
			break;
		}
		case '2': {
			fieldHeight = fieldWidth = 11;
			mines = 24;
			field = generateField(field, fieldHeight, fieldWidth, mines);
			fieldWasGenerated = true;
			selectedPreset = "Normal_11x11_24";
			break;
		}
		case '3': {
			fieldHeight = fieldWidth = 16;
			mines = 50;
			field = generateField(field, fieldHeight, fieldWidth, mines);
			fieldWasGenerated = true;
			selectedPreset = "Hard_16x16_50";
			break;
		}
		case '4': {
			system("cls");
			cout << "#################################################" << endl;
			cout << "###           Настройка режима игры           ###" << endl;
			cout << "#################################################" << endl;
			cout << "### Введите высоту поля (max 30, min 5): ";
			cin >> fieldHeight;

			if (fieldHeight > 30)
			{
				cout << "###                                           ###" << endl;
				cout << "###      Будет применена  высота поля 30      ###" << endl;
				fieldHeight = 30;
			}
			if (fieldHeight < 5)
			{
				cout << "###                                           ###" << endl;
				cout << "###      Будет применена  высота поля 5       ###" << endl;
				fieldHeight = 5;
			}

			cout << "###                                           ###" << endl;
			cout << "### Введите ширину поля (max 30, min 5): ";
			cin >> fieldWidth;

			if (fieldWidth > 30)
			{
				cout << "###                                           ###" << endl;
				cout << "###      Будет применена  ширина поля 30      ###" << endl;
				fieldWidth = 30;
			}
			if (fieldWidth < 5)
			{
				cout << "###                                           ###" << endl;
				cout << "###      Будет применена  ширина поля 5       ###" << endl;
				fieldWidth = 5;
			}

			minesCheck = fieldHeight * fieldWidth / 5;
			cout << "###                                           ###" << endl;
			cout << "### Введите количество мин (max " << minesCheck << ", min 1): ";
			cin >> mines;

			if (mines > minesCheck)
			{
				cout << "###                                           ###" << endl;
				cout << "###    Будет применено количество мин " << minesCheck << "     ###" << endl;
				mines = minesCheck;
			}
			if (mines <= 0)
			{
				cout << "###                                           ###" << endl;
				cout << "###     Будет применено  количество мин 1     ###" << endl;
				mines = 1;
			}

			field = generateField(field, fieldHeight, fieldWidth, mines);
			fieldWasGenerated = true;
			selectedPreset = "Custom_";
			selectedPreset += to_string(fieldWidth) + "x" + to_string(fieldHeight) + "_" + to_string(mines);
			break;
		}
		case '0': {
			callGameMenu();
			break;
		}
		default:
			callGameMenu();
			break;
		}

		if (fieldWasGenerated == true)
		{
			gameplay(field, fieldHeight, fieldWidth, mines, selectedPreset);
			break;
		}
	} while (option != '0');
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	callGameMenu();

	return 0;
}