#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace name
{
	string first;
	string middle;
	string last;

	void printName()
	{
		cout << "First name  :" << first << endl;
		cout << "Middle name :" << middle << endl;
		cout << "Last name   :" << last << endl;
	}
}

int main()
{
	string input;

	cout << "Please enter your name:" << endl;
	
	std::getline(cin, input);
		
	std::vector<string> extractedStrings;

	//Loop until 'input' contains no more spaces (and is therefore the final string to be extracted)
	while (input.find(' ') != string::npos)
	{
		string extract = input.substr(0, input.find(' '));	//Extract the word from the string

		input = input.substr(input.find(' ') + 1, input.length());	//remove the extracted work from the remainder

		extractedStrings.push_back(extract);		//Add the extracted string to the vector
	}

	extractedStrings.push_back(input);		//Add the remaining string to the data vector

	//Move the data to name{}
	if (extractedStrings.size() == 1)
	{	//If only the first name is given
		name::first = extractedStrings[0];
	}
	else if (extractedStrings.size() == 2)
	{	//If the first and last names were given
		name::first = extractedStrings[0];
		name::last = extractedStrings[1];
	}
	else if (extractedStrings.size() >= 3)
	{	//If the first, middle, and last names are given
		name::first = extractedStrings[0];
		name::middle = extractedStrings[1];
		name::last = extractedStrings[2];
	}

	name::printName();

	cin.get();
	return 0;
}