//
// Created by Jef DeWitt on 3/27/20.
//
#include <string_view>
#include <iostream>
#include <iomanip>
#include "ReportGenerator.h"
#include "Calculations.h"

using namespace std;

const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

// Constructor
ReportGenerator::ReportGenerator() {}

// Private
void ReportGenerator::printColHeader() {
    cout << string(66, '=') << endl;
    cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST << endl;
    cout << string(66, '-') << endl;
}

void ReportGenerator::reportGenerator(InvestmentInfo  &t_dataOne, InvestmentInfo  &t_dataTwo) {
    cout <<"     Balance and Interest Without Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataOne);

    cout <<"     Balance and Interest With Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataTwo);
}

void ReportGenerator::annualReport(InvestmentInfo  &data) {
    printColHeader();
    // TODO: Fix by referencing Investment object getters.
    vector<int> years = data.getMYears();
    vector<double> yearEndBalances = data.getMYearEndBalances();
    vector<double> yearEndEarnedInterests = data.getMYearEndEarnedInterests();

    for (int i = 0; i < years.size(); ++i) {
        cout << setw(9) << years.at(i);
        cout << setw(26) << yearEndBalances.at(i) << fixed << setprecision(2);
        cout << setw(27) << yearEndEarnedInterests.at(i) << fixed << setprecision(2)<< endl;
    }
    cout << endl << endl;
}

bool ReportGenerator::additionalSessionCheck() {
    string text;

    cout << "Press enter to try more values (press 'q' to quit)\n";
    getline(cin, text);

    if (text.empty()) {
        return true;
    }
    else {
        return false;
    }
}



