//
// Created by Jef DeWitt on 3/28/20.
//

#ifndef AIRGEAD_BANKING_INVESTMENTINFO_H
#define AIRGEAD_BANKING_INVESTMENTINFO_H

#include <vector>

using namespace std;

class InvestmentInfo {

public:
    InvestmentInfo();
    InvestmentInfo(vector<int> t_months, vector<double> t_yearEndBalances, vector<double> t_yearEndEarnedInterests);

    vector<int> years;
    vector<double> yearEndBalances;
    vector<double> yearEndEarnedInterests;
};


#endif //AIRGEAD_BANKING_INVESTMENTINFO_H
