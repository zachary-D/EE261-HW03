#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

vector<int> values;

float calculateMean(vector<int> & values)		//Returns the sum of the values stored in 'values'
{
	int sum = 0;	//The sum of all elements in 'values'

	//Loop over each element in 'values' and add them into 'sum'
	for (auto iter = values.begin(); iter != values.end(); iter++)
	{
		sum += *iter;
	}

		//sum is converted to a float before the division is done so the result is a float, instead of being calculated as an int then converted to a float, preventing data loss
	return (float)sum / values.size();		//Finish calculating the mean, and return it
}

float calculateStandardDeviation(vector<int> & values)	//Calculates the standard deviation for 'values'  using the formula given in the homework (too complex to write here)
{
	float mean = calculateMean(values);

	float numerator = 0;		//The numerator of the fraction

	//Calculate the numerator of the fraction
	for (auto iter = values.begin(); iter != values.end(); iter++)
	{
		numerator += powf( (*iter) - mean, 2.0f);	//The numerator is the sum of (x_i - x_avg)^2 over i=1,n
	}

	return sqrt( numerator / (values.size() - 1) );		//Finish calculating the standard deviation, and return it
}

int main()
{
	vector<int> values;		//Values from the user

	cout << "Enter values by entering the value and pressing enter, and repeating,\n and type \"done\" and press enter when you're done." << endl;	//Prompt the user for input and explain how they enter it
	cout << "Please enter the values you would like the standard deviation for:" << endl;
	string input;
	do
	{
		int valueIn;	//The numerical equivalent of the input, if it was supplied

		std::getline(cin, input);	//Read a line from the console
		
		//Convert the input to a integer, if possible
		std::stringstream convert;
		convert << input;
		convert >> valueIn;

		if (convert.fail() == false)	//If the conversion was successful, add it to 'values'
		{
			values.push_back(valueIn);
		}

	} while (input != "done");


	if (values.size() == 0)	//We can't take the standard deviation of nothing, so make sure there is data before we calculate it
	{
		cout << "We can't calculate the standard deviation of nothing!  Try entering some data next time!" << endl;
	}
	else cout << "Standard deviation for dataset:" << calculateStandardDeviation(values) << endl;

	cin.get();
	return 0;
}