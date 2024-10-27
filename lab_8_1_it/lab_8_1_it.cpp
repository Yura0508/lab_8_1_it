// lab_8_1_it.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(const char* s, const char* cs)
{
	int count = 0;
	int j, k;
	for (int i = 0; s[i] != '\0'; i++)
	{
		j = 0;
		k = i;
		while (cs[j] != '\0')
		{
			if (s[k] == cs[j] && s[k] != '\0')
			{
				j++;
				k++;
			}
			else
				break;
		}
		if (cs[j] == '\0')
			count++;
	}
	return count;
}

char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 5)
		return str;
	char* tmp = new char[len * 3.0 / 5 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
	while (i < len && str[i + 4] != 0)
	{
		if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
		{
			strcat(t, "***");
			t += 3;
			i += 5;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char cs[] = "while";
	cout << Count(str, cs) << endl;

	char* dest = new char[101];
	dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	cin.get();
	return 0;
}
