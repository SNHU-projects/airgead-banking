//
// Created by Jef DeWitt on 3/27/20.
//

#ifndef AIRGEAD_BANKING_BALANCEANDINTEREST_H
#define AIRGEAD_BANKING_BALANCEANDINTEREST_H

#include <vector>
#include "Calculations.h"
#include "InvestmentInfo.h"

using namespace std;

class BalanceAndInterest {
public:
    BalanceAndInterest();

    void noAdditionalPayments(InvestmentInfo  &data);

    void additionalPayments(InvestmentInfo  &data);

private:
    void printColHeader();

};


#endif //AIRGEAD_BANKING_BALANCEANDINTEREST_H
