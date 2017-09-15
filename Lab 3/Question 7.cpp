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

	for (auto iter = input.begin(); iter != input.end(); iter++)	//Loop over every character in the string
	{
		static string extracted;  //Used to store the data of the string being extracted

		if (*iter == ' ')	//If the current character is a space
		{
			if (extracted.length() > 0)
			{		// If the current extracted string has data in it, push it to the extracted strings vector, and empty the string
				extractedStrings.push_back(extracted);
				extracted = "";
			}
		}
		else
		{

		}


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