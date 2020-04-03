//
// Created by Jef DeWitt on 3/27/20.
//

#ifndef AIRGEAD_BANKING_DATAINPUT_H
#define AIRGEAD_BANKING_DATAINPUT_H

#include <vector>
#include "Calculations.h"

using namespace std;

class DataInput {
public:
    const vector<string> &getMUserPrompts() const;

    double getMInitialInvestAmt() const;

    void setMInitialInvestAmt(double mInitialInvestAmt);

    double getMMonthlyDep() const;

    void setMMonthlyDep(double mMonthlyDep);

    double getMAnnualInt() const;

    void setMAnnualInt(double mAnnualInt);

    double getMNumYears() const;

    void setMNumYears(double mNumYears);

    DataInput();

    void printHeader();

    vector<double> promptUser();

    vector<double> inputCapture();

    bool enterCheck();

private:
    // Store our user prompts
    vector<string> m_userPrompts = {
            "Initial Investment Amount:  ",
            "Monthly Deposit:  ",
            "Annual Interest:  ",
            "Number of Years:  "
    };

    double m_initialInvestAmt;

    double m_monthlyDep;

    double m_annualInt;

    double m_numYears;

};


#endif //AIRGEAD_BANKING_DATAINPUT_H
