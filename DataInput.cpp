//
// Created by Jef DeWitt on 3/27/20.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <regex>
#include "DataInput.h"

using namespace std;

// Store our user prompts
vector<string> userPrompts = {
        "Initial Investment Amount:  ",
        "Monthly Deposit:  ",
        "Annual Interest:  ",
        "Number of Years:  ",
        "Press any key to continue . . ."
};

// Default constructor
DataInput::DataInput() {};

/**
 * Prompt user for deposit info
 * @return depositDetails
 */
vector<double> DataInput::promptUser() {
    char max[100];
    vector<double> depositDetails;

    try {
        // User prompt header
        cout << string(36, '*') << endl;
        cout << string(12, '*') << " Data Input " << string(12, '*') << endl;

        // Collect user input and organize in a tidy vector
        for (int i = 0; i < userPrompts.size(); ++i) {
            string prompt = userPrompts.at(i);
            cout << prompt;
            double userInput = 0.0;
            cin >> userInput;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
            if (!cin) {
                throw runtime_error("Not a valid number.");
            }
            if (!cin) {
                throw runtime_error("Not a valid number.");
            }
            depositDetails.push_back(userInput);
        }

        cout << endl;

        return depositDetails;
    } catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}

/**
 * Display formatted user input
 * @param itemInfo
 */
void DataInput::displayUserInput(vector<double> itemInfo) {
    for (int i = 0; i < userPrompts.size(); ++i) {
        string prompt = userPrompts.at(i);
        if (i < 2) {
            cout << prompt << "$" << itemInfo.at(i) << setprecision(2) << fixed << endl;
        } else if (i == 2) {
            cout << prompt << "%" << itemInfo.at(i) << endl;
        } else {
            cout << prompt << itemInfo.at(i) << endl;
        }
    }
    cout << endl;
}

