/*
 * Name: Maximiliano Neaves
 * Section: COSC/ITSE 1307
 * Homework: TimeConversion2
 * This is a remake of the first TimeConversion project.
 */

/*
 * Pseudocode
 * Get input for hours
 * Get input for minutes
 * Get input for format (12 hr or 24 hr)
 * If format input is equal to 12
 *     Convert time to 12 hr format
 * Else
 *     Convert time to 24 hr format
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function to get number input
int getIntInput(string strMessage, int intMin, int intMax)
{
	int intNumber = 0;
	
	//Loop until it is within the min and max
	do
	{
		cout << strMessage << ": (" << intMin << "-" << intMax << ") ";
		cin >> intNumber;
	}
	while (intNumber < intMin || intNumber > intMax);
	
	return intNumber;
}

//Function to get format input
int getFormatInput(string strMessage, int intMin, int intMax)
{
	int intNumber = 0;
	
	//Loop until it is equal to min or max
	do
	{
		cout << strMessage << ": (" << intMin << " or " << intMax << ") ";
		cin >> intNumber;
	}
	while (intNumber != intMin && intNumber != intMax);
	
	return intNumber;
}

//Function to print the time
void printTime(int intHours, int intMinutes, int intFormat12or24)
{
	//12 hr conversion
	if (intFormat12or24 == 12)
	{
		if (intHours >= 13)
		{
			intHours -= 12;
		}

		cout << setw(2) << intHours;
		cout << ":";
		cout << setw(2) << setfill('0') << intMinutes; 
		cout << (intHours >= 12 ? " PM" : " AM");
		cout << endl;
	}
	//24 hr conversion
	else
	{
		cout << setw(2) << setfill('0') << intHours; 
		cout << ":"; 
		cout << setw(2) << setfill('0') << intMinutes << endl;
	}
}

//Main function
int main()
{
	//Calling printTime function
	printTime(getIntInput("Enter number of hours", 1, 24), 
	getIntInput("Enter number of minutes", 0, 59), 
	getFormatInput("Enter format", 12, 24));
	
    return 0;
}
