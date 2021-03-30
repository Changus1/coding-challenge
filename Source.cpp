#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int BasicValue(char value) //Function to return the values of the basic roman numerals
{
	switch (value)
	{
	case 'I':
		return 1;

	case 'V':
		return 5;

	case 'X':
		return 10;

	case 'L':
		return 50;

	case 'C':
		return 100;

	case 'D':
		return 500;

	case 'M':
		return 1000;

	default:
		return 0;
	}
}

bool romanNumeralCheck(char numeral) //Check to see if the input is a valid roman numeral
{
if (numeral != 'I' && numeral != 'V' && numeral != 'X' && numeral != 'L' && numeral != 'C' && numeral != 'D' && numeral != 'M')
{
	return false;
}

return true;
}

bool isValid(vector<char> myValue) //Further check to confirm the order of the roman numerals are valid
{
	int i = 0;
	for (i = 0; i < myValue.size(); ++i)
	{
		if (myValue.size() > 1)
		{
			if (romanNumeralCheck(myValue.at(i)) != false)
			{
				if (i != 0)
				{

					if (myValue.at(i) == 'L')
					{
						if (myValue.at((i - 1)) == 'I')
						{
							return false;
						}
					}

					else if (myValue.at(i) == 'C')
					{
						if (myValue.at((i - 1)) == 'I' || myValue.at((i - 1)) == 'V')
						{
							return false;
						}
					}

					else if (myValue.at(i) == 'D')
					{
						if (myValue.at((i - 1)) == 'I' || myValue.at((i - 1)) == 'V' || myValue.at((i - 1)) == 'X')
						{
							return false;
						}
					}

					else if (myValue.at(i) == 'M')
					{
						if (myValue.at((i - 1)) == 'I' || myValue.at((i - 1)) == 'V' || myValue.at((i - 1)) == 'X' || myValue.at((i - 1)) == 'L')
						{
							return false;
						}

					}


				}

			}
			else
			{
				return false;
			}
		}
		else
		{
			if (romanNumeralCheck(myValue.at(i)) != false)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}

	return true;
}

int addition(char value1, char value2) //Function to add two numbers
{
	return (BasicValue(value1) + BasicValue(value2));
}

int subtraction(char value1, char value2) //Function to subtract two numbers
{
	return (BasicValue(value1) - BasicValue(value2));
}

int convert(vector<char> myValue) //Function to calculate the final total of roman numerals
{
	int finalTotal = 0;

	while (myValue.size() > 0)
	{
		if (myValue.size() != 1)
		{
			if ((BasicValue(myValue.at(0)) > BasicValue(myValue.at(1))) || (BasicValue(myValue.at(0)) == BasicValue(myValue.at(1))))
			{
				if (myValue.size() > 2 && (BasicValue(myValue.at(2)) > BasicValue(myValue.at(1))))
				{
					finalTotal = (finalTotal + BasicValue(myValue.at(0)) + subtraction(myValue.at(2), myValue.at(1)));
					myValue.erase(myValue.begin());
				}

				else
				{
					finalTotal = (finalTotal + addition(myValue.at(0), myValue.at(1)));
				}
			}

			else
			{
				finalTotal = (finalTotal + subtraction(myValue.at(1), myValue.at(0)));
			}

			myValue.erase(myValue.begin());
			myValue.erase(myValue.begin());
		}

		else
		{
			return (finalTotal + BasicValue(myValue.front()));
		}
	}

	return finalTotal;
}

int main()
{
	vector<char> letters; //Seperation of each roman numeral
	string userInput;

	cout << "     Roman Numeral Utility \n" << endl; //Initial user input
	cout << "Please enter a variable" << endl;
	getline(cin, userInput);

	int i = 0;
	for (i = 0; i < userInput.length(); i++) //Seperate string of roman numerals into a vector of individual char values
	{
		userInput[i] = toupper(userInput[i]);
		letters.push_back(userInput[i]);
	}

	if (isValid(letters) != false) //Converted value function and prompt
	{
		cout << endl << "Your converted value is: " << convert(letters) << endl;
	}

	else //Invalid entry prompt
	{
		cout << endl << "Invalid entry, please check values and syntax before trying again. \n" << endl;
	}

	return 0;
}