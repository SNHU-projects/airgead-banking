//
// Created by Jef DeWitt on 3/27/20.
//

#ifndef AIRGEAD_BANKING_BALANCEANDINTEREST_H
#define AIRGEAD_BANKING_BALANCEANDINTEREST_H

#include <vector>
#include "DataInput.h"
#include "Calculations.h"
#include "InvestmentInfo.h"

using namespace std;

class BalanceAndInterest {
public:
    BalanceAndInterest();

    void reportGenerator(InvestmentInfo  &t_dataOne, InvestmentInfo  &dataTwo);

    void annualReport(InvestmentInfo  &data);

    bool additionalSessionCheck();

private:
    void printColHeader();

};


#endif //AIRGEAD_BANKING_BALANCEANDINTEREST_H
