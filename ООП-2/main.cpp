#include<iostream>
#include<Windows.h>

using namespace std;


void compress(char* str)
{
	char temp[256]{};
	temp[0] = '\0';
	int i{ 0 }, j{ 0 };
	int state = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ' && !state)
		{
			temp[j] = str[i];
			j++;
		}
		else if (str[i] != ' ' && state <= 1)
		{
			state = 1;
			temp[j] = str[i];
			j++;
		}
		else if (str[i] == ' ' && state == 1)
		{
			state = 2;
		}
		else if (str[i] != ' ' && state == 2)
		{
			state = 1;
			temp[j] = ' ';
			j++;
			temp[j] = str[i];
			j++;
		}
	}
	temp[j] = '\0';
	cout << "������������ �����: ";
	puts(temp);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char str_one[256];
	cout << "������� �����\t  : ";
	gets_s(str_one);

	compress(str_one);

	return 777;
}