#include<iostream>
#include<cmath>
#include<string>
#include<sstream>

using std::cout;
using std::endl;

const double PI = (4*atan(1));		//4atan(1) evaluates to pi, exactly.  It can't be defined using #define, and is defined this way because of it


double calculateFactorial(int value)	//Calculate the exact factorial for 'value'
{
	double factorial = (value == 0) ? 0 : 1;	//The final value for the factorial, after it is calculated.  The conditional statement based on value is in there so that if the value passed is 0, the factorial will be 0.

	for (int i = value; i > 0; i--)
	{
		factorial *= i;
	}
	return factorial;
}

double approximateFactorial(int value)	//Calculate the approximate factorial for 'value'
{
	return (exp(-value) * pow(value, value) * sqrt(2 * (PI) * value));
}


int main()
{
//#define USER_INPUT
	//uncomment the line above this to enable user input, instead of a constant input every time

#ifdef USER_INPUT
	int value;	//The value to calcualte the factorial of
	std::stringstream convert;

	cout << "Please enter a number to calculate the factorial of:" << endl;
	
	do
	{
		std::string input;	//The user input as a string

		//Reset the stringstream
		convert = std::stringstream();
		convert.clear();

		std::getline(std::cin, input);	//Get a line from the console

		//Attempt to convert the input to a number
		convert << input;
		convert >> value;

	} while (convert.fail());		//Loop until we get a valid input
#else
	const int value = 15;		//The value to calculate the factorial of
#endif

	double fac_calc = calculateFactorial(value);	//The calculated factorial
	double fac_approx = approximateFactorial(value);	//The approximated factorial

	cout << "Factorial of " << value << " is " << fac_calc << " and the approximation is " << fac_approx << endl;
	cout << "The difference between the two is " << abs(fac_calc - fac_approx) << endl;

	std::cin.get();

	return 0;
}