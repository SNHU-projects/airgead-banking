//
// Created by Jef DeWitt on 3/27/20.
//
#include <vector>
#include <string>
#include <math.h>
#include "Calculations.h"
#include "InvestmentInfo.h"

using namespace std;

// Constructors
Calculations::Calculations() {}

/**
 * Takes user input vector and builds InvestmentInfo object that contains user balance & interest info.
 * @param data
 * @param monthlyDep
 * @return investmentSansMonthlyDep
 */
InvestmentInfo Calculations::calculateAnnualInvestment(vector<double> data, bool monthlyDep) {
    // For ease of use, let's sort our user input
    double openAmt =  data.at(0);
    double depAmt =  data.at(1);
    int intRate =  data.at(2);
    int numYears =  data.at(3);
    vector<int> years;
    vector<vector<double>> yearEndBals;

    // Create an object to store our user feedback
    InvestmentInfo investmentSansMonthlyDep;

    // Return years as array of ints for display
    for (int i = 0; i < numYears; ++i) {
        years.push_back(i+1);
    }

    if (monthlyDep == false) {
        // Calculate without monthly deposit
        yearEndBals = annualBalWithInt(openAmt, 0, intRate, numYears);
    }
    else {
        // Calculate with monthly deposits
        yearEndBals = annualBalWithInt(openAmt, depAmt, intRate, numYears);
    }

    // Populate Investment object properties
    investmentSansMonthlyDep.years = years;
    investmentSansMonthlyDep.yearEndEarnedInterests = yearEndBals.at(0);
    investmentSansMonthlyDep.yearEndBalances = yearEndBals.at(1);

    return investmentSansMonthlyDep;

}

/**
 * Calculates annual account balance & earned interest
 * @param t_openAmount
 * @param t_depositAmount
 * @param t_intRate
 * @param t_years
 * @return balanceAndInts
 */
vector<vector<double>> Calculations::annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years) {
    vector<vector<double>> balanceAndInts;
    vector<double> annualInterestOnly;
    vector<double> annualBalWithInterest;
    double newBal;
    double yearEndInt;
    double precIntRate = (t_intRate/100.00)/12.00;
    double intTracker = 0;

    // Loop over months in requested timeframe and calculate annual balance & earned interest
    for (int i = 0; i < (t_years * 12); ++i) {
        yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i+1))) * precIntRate;
        intTracker = yearEndInt;
        if (((i+1) % 12) == 0) {
            annualInterestOnly.push_back(yearEndInt); // add just the annual interest to one vector first
            newBal = t_openAmount + (t_depositAmount * (i+1)) + yearEndInt;
            annualBalWithInterest.push_back(newBal); // add annual bal with interest to a second vector
        }
    }
    // Used in building out InvestmentInfo objects
    balanceAndInts.push_back(annualInterestOnly);
    balanceAndInts.push_back(annualBalWithInterest);

    return balanceAndInts;
}











