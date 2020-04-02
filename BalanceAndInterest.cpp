//
// Created by Jef DeWitt on 3/27/20.
//
#include <string_view>
#include <iostream>
#include <iomanip>
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
    cout << "==================================================================\n" << endl;
    cout << "     " << YEAR << "          " << YEAR_END_BAL << "          " << YEAR_END_INTEREST << endl;
    cout << "------------------------------------------------------------------\n" << endl;
}

void BalanceAndInterest::reportGenerator(InvestmentInfo  &t_dataOne, InvestmentInfo  &t_dataTwo) {
    cout <<"     Balance and Interest Without Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataOne);

    cout <<"     Balance and Interest With Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataTwo);
}

void BalanceAndInterest::annualReport(InvestmentInfo  &data) {
    printColHeader();
    for (int i = 0; i < data.years.size(); ++i) {
        cout << setw(9) << data.years.at(i);
        cout << setw(26) << data.yearEndBalances.at(i) << fixed << setprecision(2);
        cout << setw(27) << data.yearEndEarnedInterests.at(i) << fixed << setprecision(2)<< endl;
    }
    cout << endl << endl;
}

bool BalanceAndInterest::additionalSessionCheck() {
    string text;
    try {
        cout << "Press enter to try more values (press 'q' to quit)\n";
        getline(cin, text);
        if (text.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}



