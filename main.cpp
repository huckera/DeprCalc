#include <iostream>
#include <iomanip> //setw
#include "Asset.h"

int get_int (int low, int high)
{
std::cout << "Please enter an integer in the range " << low << " to " << high << " (inclusive):\n";
int n=0;
while (true)
    {

    std::cin >> n;


        //range check

        if (std::cin)
           {
           if (low <= n && n<= high) return n;
           std::cout << "Sorry, your input is not in the required range! Please try again!\n";
           }

         else if (std::cin.fail())
           {
            std::cout << "Sorry, that was not a number! Please try again!\n";
            std::cin.clear();
            char ch;

            while (std::cin >>ch && !isdigit(ch));
            if (!std::cin) std::cout << "I give up";
            std::cin.unget();

            }

    }
return n;
}


int main()
{

    float  a_cost, s_value, mult = 2.0;
    int ulife, method;

    while (true)
    {
        std::cout << "\n\n\nDepreciation Calculator\n\n\n";

        std::cout << "Please enter cost of the asset (entering 0 will end the program): ";
        std::cin >> a_cost;

        if (a_cost == 0)
            {
            std::cout << "\n\nThank you for using my program!\n\n";
            return 0;
            }

        std::cout << "\nPlease enter salvage value: ";
        std::cin >> s_value;

        std::cout << "\nPlease enter useful life (entering 0 will end the program): ";
        std::cin >> ulife;

        if (ulife == 0)
            {
            std::cout << "\n\nThank you for using my program!\n\n";
            return 0;
            }

        std::cout << "\nWhich method would you like to use?" << std::endl;
        std::cout << "1 - Straight line method" << std::endl;
        std::cout << "2 - Sum-of-year-digits" << std::endl;
        std::cout << "3 - Net value based, fixed rate method" << std::endl;
        std::cout << "4 - Double-declining method" << std::endl;
        std::cout << "5 - End program" << std::endl << std::endl;

        method = get_int(1, 5);

        if (method == 5)
            {
            std::cout << "\n\nThank you for using my program!\n\n";
            return 0;
            }

        if (method == 4)
        {
            std::cout << "Please enter the multiplier value: ";
            std::cin >> mult;
        }


        Asset shed01 (a_cost, s_value, ulife);

        depr_table (shed01, method, mult);

    }

    return 0;
}


