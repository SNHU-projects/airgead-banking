//
// Created by Jef DeWitt on 3/28/20.
//
#include <vector>
#include "InvestmentInfo.h"

using namespace std;


// Constructor
InvestmentInfo::InvestmentInfo() {}

const vector<int> &InvestmentInfo::getMYears() const {
    return m_years;
}

void InvestmentInfo::setMYears(const vector<int> &mYears) {
    m_years = mYears;
}

const vector<double> &InvestmentInfo::getMYearEndBalances() const {
    return m_yearEndBalances;
}

void InvestmentInfo::setMYearEndBalances(const vector<double> &mYearEndBalances) {
    m_yearEndBalances = mYearEndBalances;
}

const vector<double> &InvestmentInfo::getMYearEndEarnedInterests() const {
    return m_yearEndEarnedInterests;
}

void InvestmentInfo::setMYearEndEarnedInterests(const vector<double> &mYearEndEarnedInterests) {
    m_yearEndEarnedInterests = mYearEndEarnedInterests;
}
