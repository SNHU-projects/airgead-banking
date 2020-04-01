//
// Created by Jef DeWitt on 3/27/20.
//
#include <string_view>
#include <iostream>
#include "BalanceAndInterest.h"
#include "Calculations.h"

using namespace std;

//const int MAX_CHARACTERS = 60;
const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

// Constructor
BalanceAndInterest::BalanceAndInterest() {}

// Private
void BalanceAndInterest::printColHeader() {
    printf("==================================================================\n");
    printf("\t%-10s %23s %30s\n", // adds appropriate spacing to align columns & rows
           YEAR,
           YEAR_END_BAL,
           YEAR_END_INTEREST);
    printf("------------------------------------------------------------------\n");
}

void BalanceAndInterest::reportGenerator(InvestmentInfo  &t_dataOne, InvestmentInfo  &t_dataTwo) {
    printf("     Balance and Interest Without Additional Monthly Deposits     \n");
    annualReport(t_dataOne);

    printf("     Balance and Interest With Additional Monthly Deposits     \n");
    annualReport(t_dataTwo);

    additionalSessionCheck();
}

void BalanceAndInterest::annualReport(InvestmentInfo  &data) {
    printColHeader();
    for (int i = 0; i < data.years.size(); ++i) {
        printf("\t%-10i %23.2f %30.2f\n", data.years.at(i), data.yearEndBalances.at(i), data.yearEndEarnedInterests.at(i));
    }
    printf("\n\n");
}

void BalanceAndInterest::additionalSessionCheck() {
    try {
        cout << "Press enter to try more values (press 'q' to quit)\n";
        if (cin.get() == '\n') {
            DataInput dataInput;
            dataInput.promptUser();
        }
        else if (cin.get() == 'q') {
            exit(0);
        }
        else {
            throw runtime_error("\n\nCommand not recognized. Goodbye.\n\n");
        }
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}



