#include <iostream>
#include <string>
#include <locale>

using namespace std;

const int NumberOfRows = 99, NumberOfColumns = 99;

int GetStringLenght(char* line);
bool  IsLetter(char n);
int ParseStringByWords(char* stringToParse, char wordsArray[NumberOfRows][NumberOfColumns]);

int main() 
{
	char myString[100];
	cin.getline(myString, 99);

	int numberOfSymbols = GetStringLenght(myString);

	char wordsArray[NumberOfRows][NumberOfColumns] = { {'\0'} };
	int numberOfWords = ParseStringByWords(myString, wordsArray);

	cout << "NumberOfWords = " << numberOfWords << endl;

	for (int i = 0; i < numberOfWords; i++) {
		cout << "[" << i + 1 << "]: " << wordsArray[i] << endl;
	} 
	
	system("pause");
	return 0;
}


int GetStringLenght(char* line) {
	int amountOfSymbols = 0;
	while (line[amountOfSymbols] != '\0')
	{
		amountOfSymbols++;
	}

	return amountOfSymbols;
}

bool IsLetter(char n)
{
	if (n != '\0' && n != ' ')
	{
		 return true;
	}
	else return false;
}

int ParseStringByWords(char* stringToParse, char wordsArray[NumberOfRows][NumberOfColumns])
{
	int wordRowIndex = 0;
	int wordColumnIndex = 0;

	int stringLenght = GetStringLenght(stringToParse);
	for (int i = 0; i <= stringLenght; i++)
	{
		if (IsLetter(stringToParse[i]))
		{
			wordsArray[wordRowIndex][wordColumnIndex] = stringToParse[i];
			wordColumnIndex++;
		}
		else
		{
			 wordRowIndex++;
			 wordColumnIndex = 0;
		}
	}	

	return wordRowIndex;
}