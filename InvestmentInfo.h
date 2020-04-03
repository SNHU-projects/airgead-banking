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

    const vector<int> &getMYears() const;

    void setMYears(const vector<int> &mYears);

    const vector<double> &getMYearEndBalances() const;

    void setMYearEndBalances(const vector<double> &mYearEndBalances);

    const vector<double> &getMYearEndEarnedInterests() const;

    void setMYearEndEarnedInterests(const vector<double> &mYearEndEarnedInterests);

private:
    vector<int> m_years;

    vector<double> m_yearEndBalances;

    vector<double> m_yearEndEarnedInterests;

};


#endif //AIRGEAD_BANKING_INVESTMENTINFO_H
