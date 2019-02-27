#include <iostream>
#include <string>
#include <sstream>
#include <regex>


std::string goodDivisionMade = "true";
double value = 0.0;
double valueDenom = 0.0;
double success = 0.0;
double successDenom = 0.0;
int numerator , denomenator;
bool wasNumerNegative, wasDenomNegative;


void testTwo(int numer, int denom, std::string valueAsString, std::string valueDenomAsString)
{
	//Now we now that either the value returned from the divsion can only be a decimal(56.787,67.888) or whole number(56.000,67.000,12.000)
	std::regex rgxTwo("[[:d:]]+\.0+");
	bool matchTestTwo = regex_match(valueAsString, rgxTwo);//0 if no match is found or 1 if a match is found
	bool matchTestDenomTwo = regex_match(valueDenomAsString, rgxTwo);//0 if no match is found or 1 if a match is found

	if (matchTestTwo == 0 || matchTestDenomTwo == 0) { std::cout << "This is a bad divsion\n\n"; }
	else if (matchTestTwo == 1 && matchTestDenomTwo == 1) 
	{
		numer = value, success = numer;
		denom = valueDenom, successDenom = denom;

		std::cout << "This is a good division\n";
		std::cout << valueAsString << "\n\n";
		std::cout << valueDenomAsString << "\n\n";
	}
}

void runPass(int numer,int denom) 
{
	int i = 2;

	while (i < 8) 
	{
		std::cout << "i is: " << i << "\n\n";

		value = (double)numer / i, valueDenom = (double)denom / i;// First convert the integers to double(because we wanna see the decimal values when dividing them)

		std::string valueAsString = std::to_string(value), valueDenomAsString = std::to_string(valueDenom);
		std::regex rgxOne("^0");//check if zero is at the front of the value

		bool matchTestOne = regex_search(valueAsString, rgxOne);
		bool matchTestDenomOne = regex_search(valueDenomAsString, rgxOne);

		if (matchTestOne == 0 && matchTestDenomOne == 0){ testTwo(numer,denom, valueAsString,valueDenomAsString); }
		if (i != 2) { i += 2; }//so it jumps to i = 3,5,7
		else if (i == 2) { i++; }//go to 3
	}
}

void lastCheck()
{
	if (success == 0 || successDenom == 0)
	{
		std::cout << "These numbers are already in there simplest form!\n\n";
	}
	else
	{
		if (wasNumerNegative == true ^ wasDenomNegative == true) { success *= -1; }//If only one of the numbers entered was a negative then make the final numerator negative!
		std::cout << "Simplified Numerator: " << success << "\n";
		std::cout << "Simplified Denomenator: " << successDenom << "\n\n";
	}
}

void negativeCheck()
{
	std::string NumerAsString = std::to_string(numerator);
	std::string DenomAsString = std::to_string(denomenator);
	if (NumerAsString.find("-") != std::string::npos) 
	{
		wasNumerNegative = true;
		numerator = numerator * -1; 
	}
	if (DenomAsString.find("-") != std::string::npos) 
	{ 
		wasDenomNegative = true;
		denomenator = denomenator * -1; 
	}
}

int main()
{
	numerator = 5286, denomenator = -4572;// ENTER NUMERATOR AND DEMONATOR HERE, RESPECTIVILY
	negativeCheck();
	while (goodDivisionMade == "true") 
	{
		int preSuccess = success, preSuccessDenom = successDenom;

		if (success != 0.0 || successDenom != 0.0) {runPass(success, successDenom);}
		else { runPass(numerator, denomenator); }

		if (preSuccess == success || success == 2 || preSuccessDenom == successDenom || successDenom == 2) {
			goodDivisionMade = "false";
		}
	}

	lastCheck();
	std::cout << "Press enter to exit the program" << std::endl;
	std::cin.get();
	return 0;
}