// COMP 151
// @author: Pedro J. Navarrete
// V 1.00

#include <iostream>
#
using namespace std;

const int MAX_SIZE = 50;

bool reverseStr(char []);

int main() {
	char sentence[MAX_SIZE + 1];

	cout << "Palindrome Tester" << endl << endl;
	cout << "Input a string with at most " << MAX_SIZE << " characters" << endl;
	cin.getline(sentence, MAX_SIZE + 1);
	
	if(reverseStr(sentence)){
		cout << sentence << " is a palindrome\n";
	} else {
		cout << sentence << " is not a palindrome\n";
	}

}

bool reverseStr(char str[]){
	int hold;
	int i = 0;
	int j = strlen(str) -1;
	while (i < j){
		if (str[i] != str[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}