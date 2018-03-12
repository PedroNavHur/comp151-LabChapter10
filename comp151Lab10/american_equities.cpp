// This program tests a password for the American Equities
// web page to see if the format is correct

// Pedro J. Navarrete
// V1.00

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//function prototypes 

bool testPassWord(char[]);
bool hasUpperCase(char*);
int countLetters(char*);
int countDigits(char*);

// password validation
int const MAX_PASS_SIZE = 10;
int const MAX_LETTERS = 4;
int const MAX_DIGITS = 6;

int main()
{
	char passWord[20];

	cout << "Enter a password consisting of exactly "
		<< MAX_LETTERS << " lowercase letters and "
		<< MAX_DIGITS << " digits:" << endl;
	cin.getline(passWord, 20);

	if (testPassWord(passWord))
		cout << "Please wait - your password is being verified" << endl;
	else
	{
		cout << "Invalid password. Please enter a password "
			<< "with exactly "
			<< MAX_LETTERS << " lowercase letters and "
			<< MAX_DIGITS << " digits" << endl;
		cout << "For example, 123456abcd is valid" << endl;
	}

	int passLetters;
	int passDigits;

	// FILL IN THE CODE THAT WILL CALL countLetters and 
	// countDigits and will print to the screen both the number of
	// letters and digits contained in the password.  
	passLetters = countLetters(passWord);
	passDigits = countDigits(passWord);

	cout << "Letters: " << passLetters << endl;
	cout << "Digits: " << passDigits << endl;

	return 0;
}


//**************************************************************
//                       testPassWord
//
// task:			determines if the word contained in the
//				    character array passed to it, contains
//					exactly MAX_LETTERS letters and MAX_DIGITS digits.
// data in:			a word contained in a character array
// data returned:   true if the word contains MAX_LETTERS letters & MAX_DIGITS
//					digits, false otherwise
//
//**************************************************************
bool testPassWord(char custPass[])
{
	int numLetters, numDigits, length;

	length = strlen(custPass);
	numLetters = countLetters(custPass);
	numDigits = countDigits(custPass);
	
	if (hasUpperCase(custPass)) {
		return false;
	}

	if (numLetters == MAX_LETTERS && numDigits == MAX_DIGITS && length == MAX_PASS_SIZE)
		return true;
	else
		return false;


}

bool hasUpperCase(char *strPtr) {
	while (*strPtr != '\0') {
		if (isupper(*strPtr)) {
			return true;
		}
		strPtr++;
	}
	return false;
}


// the next 2 functions are from Sample Program 10.5
//**************************************************************
//                       countLetters
//
// task:			counts the number of letters (both
//                  capital and lower case in the string
// data in:			a string 
// data returned:   the number of letters in the string
//
//**************************************************************
int countLetters(char *strPtr)
{
	int occurs = 0;

	while (*strPtr != '\0')

	{
		if (isalpha(*strPtr))
			occurs++;
		strPtr++;
	}

	return occurs;
}

//**************************************************************
//                       countDigits
//
// task:			counts the number of digitts in the string
// data in:			a string 
// data returned:   the number of digits in the string
//
//**************************************************************
int countDigits(char *strPtr)  // this function counts the
							   // number of digits
{
	int occurs = 0;

	while (*strPtr != '\0')
	{
		if (isdigit(*strPtr))  // isdigit determines if
							   // the character is a digit
			occurs++;
		strPtr++;
	}

	return occurs;
}