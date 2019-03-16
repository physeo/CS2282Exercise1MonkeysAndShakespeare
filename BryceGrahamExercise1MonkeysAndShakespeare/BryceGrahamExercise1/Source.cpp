/**********************************************
Bryce Graham
CS 2282
Dr. Beard
Exercise 1: A program that consists of several demonstrations
including a use for dynamically allocated arrays and performs
an experiment to see how long it takes to create a certain string
out of randomly generated characters.
**********************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int * createArray(int length);
void fillArray(int intArray[], int length);
int * count(const string &s);
string monkeys(const string &shakespeare);
void displayResults(string &finalString);

// Handles user input and output from the console.
int main()
{
	cout << "Enter length of array: ";
	int length;
	cin >> length;
	int* intArray = createArray(length);
	cout << "Your array:\n";
	for (int i = 0; i < length; ++i)
		cout << intArray[i] << "\n";

	cout << "Enter a string: ";
	string s = "";
	cin.ignore();
	getline(cin, s);
	int* freqArray = count(s);
	cout << "String frequency count:\n";
	for (int i = 0; i < 10; ++i)
		cout << i << ": " << freqArray[i] << "\n";

	const string shakespeare = "now is the winter";
	string finalString = monkeys(shakespeare);
	displayResults(finalString);
}
// Creates a new array of a specified length.
int * createArray(int length)
{
	int* intArray = new int[length];
	fillArray(intArray, length);
	return intArray;
	
}
// Fills an array with values input from the user.
void fillArray(int intArray[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << "Enter an integer for the array: ";
		int myInt;
		cin >> myInt;
		intArray[i] = myInt;
	}
}
// Counts the number of instances of a number in an array.
int * count(const string &s)
{
	int* freqArray = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		freqArray[i] = 0;
		for (unsigned j = 0; j < s.length(); ++j)
			if (i == (s[j] - '0'))
				freqArray[i] = freqArray[i] + 1;
	}
	return freqArray;
}
// Randomly generates a 17 character long string until it matches "now is the winter".
string monkeys(const string &shakespeare)
{
char allowedChars[28] = " abcdefghijklmnopqrstuvwxyz";
	char monkeyArray[17];
	bool equalStrings = false;
	for (int i = 0; i < 17; i++)
		monkeyArray[i] = '0';
	long count = 0;
	srand(time(NULL));
	do
	{
		for (int i = 0; i < 17; i++)
		{
			char randChar = allowedChars[rand() % 26];
			monkeyArray[i] = randChar;
		}
		string monkeyString(monkeyArray);
		equalStrings = monkeyString.substr(0, 17) == shakespeare.substr(0, 17);
		count++;
		if (count >= pow(10, 6))
			return "-1";
	} while (count < pow(10,6) && !equalStrings);
	cout << "the count: " << count << "\n";

	return monkeyArray;
}
// Tells the user if the randomly generated number was "now is the winter". Returns -1 if not.
void displayResults(string &finalString)
{
	cout << "The monkeys typed: ";
	if (finalString != "-1")
		cout << finalString.substr(0, 17);
	else
		cout << "-1";

	cout << "\n";
}