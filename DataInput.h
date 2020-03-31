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
    DataInput();

    vector<double> promptUser();

    void displayUserInput(vector<double> itemInfo);

};


#endif //AIRGEAD_BANKING_DATAINPUT_H
