//
// Created by Jef DeWitt on 3/28/20.
//
#include <vector>
#include "InvestmentInfo.h"

using namespace std;

vector<int> years;
vector<double> yearEndBalances;
vector<double> yearEndEarnedInterests;

// Constructors
InvestmentInfo::InvestmentInfo() {}

InvestmentInfo::InvestmentInfo(vector<int> t_years, vector<double> t_yearEndBalances, vector<double> t_yearEndEarnedInterests) {
    this->years = t_years;
    this->yearEndBalances = t_yearEndBalances;
    this->yearEndEarnedInterests = t_yearEndEarnedInterests;
}
