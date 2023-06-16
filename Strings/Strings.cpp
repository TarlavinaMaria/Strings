#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctype.h>
#include<Windows.h>

#define delimiter "\n-------------------------------------------------------------------------------------------------\n"


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
char* remove_symbol(char str[], char symbol); // удаление символов для палиндромома

bool Is_int_number(char str[]);	//определяет, является ли строка целым числом
int Int_to_number(char str[]); //Если строка является целым числом, возвращает его значение

bool Is_bin_number(char str[]); //определяет, является ли строка двоичным числом
int Bin_to_number(char str[]); //Если строка является двоичным числом, возвращает его десятичное значение

bool Is_hex_number(char str[]); //определяет, является ли строка шестнадцатеричным числом
int Hex_to_number(char str[]); // Если строка является шестнадцатеричным числом, возвращает его десятичное значение




void main()
{

	setlocale(LC_ALL, "");

	/*char str[] = { 'H', 'e', 'l','l', 'o', 0 };
	char str[] = "Hello";
	cout << str << endl;*/

	/*char str1[] = "Hello";
	cout << str1 << endl;*/

	const int SIZE = 256;
	char str[SIZE] = "3415146";
	//cout << "Введите строку: "; /*cin >> str;*/
	//SetConsoleCP(1251);
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	////cout << str << endl;
	
	cout << "Размер введенной строки: " << StringLength(str) << endl;
	cout << delimiter << endl;
	cout << "Строка в нижний регистр: " << To_lower(str) << endl;
	cout << "Строка в верхний регистр:" << To_upper(str) << endl;
	cout << "Удаляет из строки лишние пробелы: " << Shrink(str) << endl;
	cout << "Строка является палиндромом? " << (Is_palindrome(str) ? "Да" : "Нет") << endl;
	cout << delimiter << endl;


	cout << "Определяет, является ли строка целым числом: " << (Is_int_number(str) ? "Да" : "Нет") << endl;
	cout << "Если строка является целым числом, возвращает его значение: " << Int_to_number(str) << endl;
	cout << delimiter << endl;

	cout << "Определяет, является ли строка двоичным числом: " << (Is_bin_number(str) ? "Да" : "Нет") << endl;
	cout << "Если строка является двоичным числом, возвращает его десятичное значение: " << Bin_to_number(str) << endl;
	cout << delimiter << endl;

	cout << "Определяет, является ли строка шестнадцатеричным числом: " << (Is_hex_number(str) ? "Да" : "Нет") << endl;
	cout << "Если строка является шестнадцатеричным числом, возвращает его десятичное значение: " << Hex_to_number(str) << endl;
	
	cout << delimiter << endl;
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

char* remove_symbol(char str[], char symbol) // удаление символов для палиндромома
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
bool Is_int_number(char str[])	//определяет, является ли строка целым числом
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return false;
		}
		if (!(str[i] >= ' ' && str[i + 1] <= ' '))
		{
			return false;
		}
	}
	return true;
}

int Int_to_number(char str[]) //Если строка является целым числом, возвращает его значение
{
	if (!Is_int_number(str)) return 0;
	int number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') continue;
		number *= 10; // сдвиг на разряд влево (освобождение младшего разряда)
		number += str[i] - 45;
	}
	return number;
}


bool Is_bin_number(char str[]) //определяет, является ли строка двоичным числом
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
		{
			return false;
		}
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			return false;
		}
	}
	return true;
}
int Bin_to_number(char str[]) //Если строка является двоичным числом, возвращает его десятичное значение
{
	if (!Is_bin_number(str)) return 0;
	int n = strlen(str);
	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		decimal += (str[i] - 48) * weight; // ASCII символах 0
		weight *= 2;
	}
	return decimal;
}


bool Is_hex_number(char str[]) //определяет, является ли строка шестнадцатеричным числом
{
	for (int i = 0; str[i]; i++) // все элементы шестнадцатеричного числа лежат между символами от A до F или между целыми числами от 0 до 9
	{
		if (!str[i] >= '0' && str[i] <= '9')
		{
			return false;
		}
		if (!str[i] >= 'a' && str[i] <= 'f')
		{
			return false;
		}
		if (!str[i] >= 'A' && str[i] <= 'F')
		{
			return false;
		}
	}
	return true;
}

int Hex_to_number(char str[]) // Если строка является шестнадцатеричным числом, возвращает его десятичное значение
{
	int decimal_number = 0; // возвращаемая переменная
	for (int i = 0; i < strlen(str); i++)
	{
		int number = 0;
		if (str[i] == '0') continue; // убираем лишние итерации, при умножении на 0
		int temp = 1;
		for (int j = 0; j < (strlen(str) - i - 1); j++)
		{
			temp *=16;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = str[i] - 48; // для цифр от 0 до 48
		}
		if (str[i] >= 'A' && str[i] <= 'F')
		{
			number = str[i] - 55; // для букв от A до F
		}
		if (str[i] >= 'a' && str[i] <= 'f')
		{
			number = str[i] - 87; // для букв от a до f
		}
		decimal_number += number * temp;
	}
	return decimal_number;
}
