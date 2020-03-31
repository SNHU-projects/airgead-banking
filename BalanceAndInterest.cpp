//
// Created by Jef DeWitt on 3/27/20.
//
#include <string_view>
#include "BalanceAndInterest.h"
#include "Calculations.h"

using namespace std;

//const int MAX_CHARACTERS = 60;
const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

// Default constructor
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

void BalanceAndInterest::noAdditionalPayments(InvestmentInfo  &data) {
    printf("     Balance and Interest Without Additional Monthly Deposits     \n");
    printColHeader();
    for (int i = 0; i < data.years.size(); ++i) {
        printf("\t%-10i %23.2f %30.2f\n", data.years.at(i), data.yearEndBalances.at(i), data.yearEndEarnedInterests.at(i));
    }
    printf("\n\n");
}

void BalanceAndInterest::additionalPayments(InvestmentInfo  &data) {
    printf("       Balance and Interest With Additional Monthly Deposits      \n");
    printColHeader();
    for (int i = 0; i < data.years.size(); ++i) {
        printf("\t%-10i %23.2f %30.2f\n", data.years.at(i), data.yearEndBalances.at(i), data.yearEndEarnedInterests.at(i));
    }
    printf("\n\n");
}



