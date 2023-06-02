#include <iostream>
#include <Windows.h>

using namespace std;

void fillRand(bool**& arr, const int size, int num);

void setupCell(bool** arr, const int size);

void printFild(bool** arr, const int size);

int main()
{
	//setlocale(LC_ALL, "ru");
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	int fildSize;

	cout << char(176);

	cout << "Игра \"Жизнь\"\n";
	cout << "Укажите размер игрового поля указав число. Поля должно быть квадратным не менее 10: ";
	cin >> fildSize;
	if (fildSize < 10)
	{
		cout << "Вы указали поле меньше 10 поэтому оно по умочанию будет размером 10х10\n";
		fildSize = 10;
	}

	bool** newGener = new bool*[fildSize];
	for (int i = 0; i < fildSize; i++)
		newGener[i] = new bool[fildSize];

	cout << "нажмите 1 что бы заполнить поле самостоятельно или любое другое число, чтобы заполнить случайно: ";
	int chose;
	cin >> chose;
	if (chose == 1)
	{
		setupCell(newGener, fildSize);
	}
	else
	{
		int aliveCell;
		cout << "Введите количество живых клеток: ";
		cin >> aliveCell;
		fillRand(newGener, fildSize, aliveCell);
	}

	printFild(newGener, fildSize);


	for (int i = 0; i < fildSize; i++)
		delete[] newGener[i];

	delete[] newGener;


	return 0;
}

void fillRand(bool**& arr,const int size, int num)
{
	for (int i = 0; i < size && num != 0; i++)
		for (int j = 0; j < size && num != 0; j++)
		{
			bool tmp = rand() % 2;
			arr[i][j] = tmp;
			if (tmp)
				num--;
		}
}

void setupCell(bool** arr, const int size)
{
	int row = 0, col = 0;
	bool is_fill = true;
	do
	{
		cout << "Укажите номер строки и номер столбца через пробел, для заполнения: ";
		cin >> row >> col;
		bool tmp = true;
		arr[row][col] = tmp;

		cout << "Если хотите заполнить ещё, укажите любое число если нет, то нажмите 0 : ";
		cin >> is_fill;

	} while (is_fill);

}

void printFild(bool** arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == true)
			{
				cout << char(127);
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;

	}
}
