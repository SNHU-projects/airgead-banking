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
        "Number of Years:  "
};

// Default constructor
DataInput::DataInput() {};

/**
 * Prompt user for deposit info
 * @return depositDetails
 */
vector<double> DataInput::promptUser() {
    vector<double> depositDetails;
    char quitCmd = 'a';  // Indicates infinite loop till user satisfies input requirements

    while (quitCmd != 'q') {

        try {
            // Clear any previously unfinished collections of user input
            depositDetails.clear();

            // User prompt header
            cout << string(36, '*') << endl;
            cout << string(12, '*') << " Data Input " << string(12, '*') << endl;

            // Collect user input and organize in a tidy vector
            for (int i = 0; i < userPrompts.size(); ++i) {
                string prompt = userPrompts.at(i);
                double userInput;
                cout << prompt;
                cin >> userInput;

                // Check for valid user input
                if (!cin || userInput < 0) {
                    throw runtime_error("\n\nAlphabetical characters and negative amounts not allowed. \n\n"
                                        "Please try again.\n\n");
                }

                depositDetails.push_back(userInput);
            }

        }
        catch (runtime_error& except) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
            cout << except.what() << endl;
        }

        // Check that depositDetails vector is full and user decides to continue
        if (depositDetails.size() == 4 && enterCheck()) {
            return depositDetails;
        }
    }
}

/**
 *
 * @return bool
 */
bool DataInput::enterCheck() {
    cout << "Press enter to continue . . .\n";
    return cin.get() == '\n';
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

