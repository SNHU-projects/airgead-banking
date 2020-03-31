//
// Created by Jef DeWitt on 3/27/20.
//

#ifndef AIRGEAD_BANKING_CALCULATIONS_H
#define AIRGEAD_BANKING_CALCULATIONS_H

#include <vector>
#include "InvestmentInfo.h"

using namespace std;

class Calculations {

public:
    Calculations();

    InvestmentInfo calculateAnnualInvestment(vector<double> data, bool monthlyDep = false);

    vector<vector<double>> annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years);
};


#endif //AIRGEAD_BANKING_CALCULATIONS_H
