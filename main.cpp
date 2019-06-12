#include <iostream>
#include <string>
#include <vector>

void euclidianAlgorithmToSimplifyFractions(int numer, int denom)
{
    int intialNumer = numer, intialDenom = denom;
    
    if(numer == 0 || denom == 0 ){std::cout << "HOW DARE YOU!\n"; exit(0);}
    numer = std::abs (numer); denom = std::abs (denom);
    
    int r = std::max(numer, denom) / std::min(numer, denom);
    int remainder = (std::max(numer, denom)) - (std::min(numer, denom) * r);
    int GCD = 0;
    
    std::vector<int> listOfRemainders;
    listOfRemainders.push_back(remainder);
    
    while(remainder != 0)
    {
        numer = denom;
        denom = remainder;
        r = std::max(numer, denom) / std::min(numer, denom);
        remainder = (std::max(numer, denom)) - (std::min(numer, denom) * r);
        listOfRemainders.push_back(remainder);
    }
    if(listOfRemainders.size() > 2)
    {
        GCD = listOfRemainders.at((listOfRemainders.size()-2));
    }
    else
    {
        GCD = (std::min(numer, denom));
    }
    
    std::cout << "Greatest Common Divisor: " << GCD << "\n";
    std::cout << "Intial Fraction: " << intialNumer << "/" << intialDenom << "  ->  " << "Simplified Fraction: : " << (intialNumer/GCD) << "/" << (intialDenom/GCD) << "\n";
}

int main()
{
   euclidianAlgorithmToSimplifyFractions(2, -6);
   std::cout << "Press enter to exit the program" << std::endl;
   std::cin.get();
   return 0;
}


