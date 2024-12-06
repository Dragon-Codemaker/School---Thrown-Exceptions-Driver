//Name: Alexandra Smith
//Class: CIS 1202.501
//Project Name: Thrown Exceptions Driver
//Project Description: This project is designed to practice handling thrown exceptions
//Date: 12/05/2024

#include<iostream>
#include<string>

using namespace std;

char Character(char, int); //Prototype for Character calculation function

int main()
{
	char newChar; //Variables for holding user input data
	char newTarget;
	int newOffset;

	cout << "Enter a character: ";
	cin >> newChar;

	cout << "Enter an offset integer: ";
	cin >> newOffset;

	try //Try block to call Character function, prints newTarget if sucessful
	{
		newTarget = Character(newChar, newOffset);
		cout << "The new character is: " << newTarget << endl;
		cout << endl;
	}
	catch (string invalidCharacterException) //Catches invalid character exception error
	{
		cout << invalidCharacterException << endl;
	}
	catch (int invalidRangeException) //Catches invalid range exception error. Prints is string literal over a string variable to avoid an error with multiple catch blocks of the same type
	{
		cout << "The target character is out of range." << endl;
	}


	system("pause");
	return 0;
}

char Character(char start, int offset) //Character caclulation function
{
	char target = start + offset; //Calculates target character

	if (start < 'A' || start > 'Z' && start < 'a' || start > 'z') //If user entered char is out of range, throw exception
	{
		string invalidCharacterException = "ERROR: You have entered an invalid character";
		throw invalidCharacterException;
	}

	if (start >= 'A' && start <= 'Z' && (target < 'A' || target > 'Z')) //If user entered char is in range, but target is out of range, throw exception
	{
		int invalidRangeException = -1;
		throw invalidRangeException;
	}

	if (start >= 'a' && start <= 'z' && (target < 'a' || target > 'z')) //Same as above but for lower case letters
	{
		int invalidRangeException = -1;
		throw invalidRangeException;
	}

	return target; //Returns target to main
}