#include<iostream>
#include<Windows.h>


using namespace std;
using std::cin;
using std::cout;
using std::endl;

int StringLength(const char str[]); // считает количество символов в строке
void To_lower(char str[]); //переводит строку в нижний регистр
void To_upper(char str[]); //переводит строку в верхний регистр
void Shrink(char str[]); //удаляет из строки лишние пробелы

void Is_palindrome(char str[]); // oпределяет, является ли строка палиндромом
int Is_int_number(char str[]);	//определяет, является ли строка целым числом





void main()
{

	setlocale(LC_ALL, "");

	/*char str[] = { 'H', 'e', 'l','l', 'o', 0 };
	char str[] = "Hello";
	cout << str << endl;*/

	/*char str1[] = "Hello";
	cout << str1 << endl;*/

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: "; /*cin >> str;*/
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	//cout << str << endl;

	cout << "Размер введенной строки: " << StringLength(str) << endl;
	cout << "Строка в нижний регистр: "; To_lower(str);
	cout << str << endl;
	cout << "Строка в верхний регистр: "; To_upper(str);
	cout << str << endl;
	cout << "Удаляет из строки лишние пробелы: "; Shrink(str);
	cout << str << endl;

	cout << "Определяет, является ли строка целым числом: ";
	cout << (Is_int_number(str) ? "Число" : "Не число") << endl; 


}

int StringLength(const char str[]) // считает количество символов в строке
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void To_lower(char str[]) //переводит строку в нижний регистр
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		{
			str[i] += 32; // Разница между строчными и прописными буквами всегда равна 32. ASCII для «a» равно 97, для «A» - 65. (a - A = 32)
		}
	}
}

void To_upper(char str[]) //переводит строку в верхний регистр
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
		{
			str[i] -= 32;
		}
	}
}

void Shrink(char str[]) //удаляет из строки лишние пробелы
{
	for (int i = 0; str[i]; i++) // основной счетчик
	{
		while (str[i] == ' ' && str[i + 1] == ' ') // поиск пробелов
		{
			for (int j = i; str[j]; j++) // сдвиг влево
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void Is_palindrome(char str[]) // oпределяет, является ли строка палиндромом
{

}

int Is_int_number(char str[])	//определяет, является ли строка целым числом
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			return true;
		}
		return false;
	}
}
