#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctype.h>
#include<Windows.h>


using namespace std;
using std::cin;
using std::cout;
using std::endl;

int StringLength(const char str[]); // считает количество символов в строке
char* To_lower(char str[]); //переводит строку в нижний регистр
char* To_upper(char str[]); //переводит строку в верхний регистр
char* Shrink(char str[]); //удаляет из строки лишние пробелы

// типа bool являются только true и false
bool Is_palindrome(const char str[]); // oпределяет, является ли строка палиндромом
char* remove_symbol(char str[], char symbol); // удаление символов
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
	char str[SIZE] = "Аргентина манит негра";
	//cout << "Введите строку: "; /*cin >> str;*/
	//SetConsoleCP(1251);
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	////cout << str << endl;

	cout << "Размер введенной строки: " << StringLength(str) << endl;
	cout << "Строка в нижний регистр: " << To_lower(str) << endl;
	cout << "Строка в верхний регистр:" << To_upper(str) << endl;
	cout << "Удаляет из строки лишние пробелы: " << Shrink(str) << endl;
	cout << "Строка является палиндромом? " << (Is_palindrome(str) ? "Да" : "Нет") << endl;


	cout << "Определяет, является ли строка целым числом: " << (Is_int_number(str) ? "Число" : "Не число") << endl;


}

int StringLength(const char str[]) // считает количество символов в строке
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* To_lower(char str[]) //переводит строку в нижний регистр
{
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		//{
		//	str[i] += 32; // Разница между строчными и прописными буквами всегда равна 32. ASCII для «a» равно 97, для «A» - 65. (a - A = 32)
		//}
		//if (str[i] == 'Ё')
		//{
		//	str[i] += 16;
		//}
		str[i] = tolower(str[i]);
	}
	return str;
}

char* To_upper(char str[]) //переводит строку в верхний регистр
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
		{
			str[i] -= 32;
		}
		if (str[i] == 'ё')
		{
			str[i] -= 16;
		}*/
		str[i] = toupper(str[i]);
	}
	return str;
}

char* Shrink(char str[]) //удаляет из строки лишние пробелы
{
	for (int i = 0; str[i]; i++) // основной счетчик
	{
		while (str[i] == ' ' && str[i + 1] == ' ') // поиск пробелов
		{
			for (int j = i + 1; str[j]; j++) // сдвиг влево
			{
				str[j] = str[j + 1];
			}
		}
	}
	while (str[0] == ' ')
	{
		for (int i = 0; str[i]; i++)
		{
			str[i] = str[i + 1];
		}
	}
	return str;
}

bool Is_palindrome(const char str[]) // oпределяет, является ли строка палиндромом
{
	// cout << typeid(str).name() << endl;
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	To_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - i - 1])
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}

char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
	return str;
}

int Is_int_number(char str[])	//определяет, является ли строка целым числом
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}
