//  22ВП3
//  Сафронов Алексей
//  Найти в предложении все слова, которые не являются палиндромами. (char[])

// ПРОГА ЛОМАЕТ КОМП!!!!!!!!!

#include <iostream>

using namespace std;

int getSimpleWords(char[], char*[]);
int getFirstWord(char[], char[]);
bool checkWord(char[]);
void reverseCharArray(char[]);

int main()
{
	setlocale(LC_ALL, "Russian");

	char a[] = "Какое-то предложение gfggfg со словами.. авыва аопоа g";
	const int length = size(a);

	cout << "Входящее предложение: " << a << "\n";

    char* simpleWords[100];

    int wordsAmount = getSimpleWords(a, simpleWords);

    for (int i = 0; i < wordsAmount; i++)
    {
        cout <<  simpleWords[i] << " ";
    }
}

int getSimpleWords(char str[], char* destination[])
{
    int counter = 0;

    while (strlen(str) > 0)
    {
        char temp[100];
        int wordLength = getFirstWord(str, temp);

        if (!checkWord(temp))
            destination[counter++] = temp;
    }

    return counter;
}

int getFirstWord(char str[], char destination[])
{
    int i = 0;
    cout << strlen(str);
    for (; i < strlen(str); i++)
    {
        if (str[i] == ' ' || i <= strlen(str))
        {
            strncpy_s(destination, i + 1, str, i);
            strcpy_s(str, strlen(str) - i, &str[i + 1]);
            break;
        }
    }

    return i;
}

bool checkWord(char word[])
{
    char reversedWord[100];

    strncpy_s(reversedWord, word, strlen(word));

    reverseCharArray(reversedWord);
    
    return reversedWord == word;
}

void reverseCharArray(char arr[])
{
    for (int i = 0; i < strlen(arr) / 2; i++)
    {
        char temp = arr[i];
        arr[i] = arr[strlen(arr) - i - 1];
        arr[strlen(arr) - i - 1] = temp;
    }
}
