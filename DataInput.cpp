//
// Created by Jef DeWitt on 3/27/20.
//
#include <iostream>
#include <vector>
#include "DataInput.h"

using namespace std;

// Default constructor
DataInput::DataInput() {};

const vector<string> &DataInput::getMUserPrompts() const {
    return m_userPrompts;
}

// Getters & Setters
double DataInput::getMInitialInvestAmt() const {
    return m_initialInvestAmt;
}

void DataInput::setMInitialInvestAmt(double mInitialInvestAmt) {
    m_initialInvestAmt = mInitialInvestAmt;
}

double DataInput::getMMonthlyDep() const {
    return m_monthlyDep;
}

void DataInput::setMMonthlyDep(double mMonthlyDep) {
    m_monthlyDep = mMonthlyDep;
}

double DataInput::getMAnnualInt() const {
    return m_annualInt;
}

void DataInput::setMAnnualInt(double mAnnualInt) {
    m_annualInt = mAnnualInt;
}

double DataInput::getMNumYears() const {
    return m_numYears;
}

void DataInput::setMNumYears(double mNumYears) {
    m_numYears = mNumYears;
}

/**
 * Print header for user input prompt
 */
void DataInput::printHeader() {
    cout << string(36, '*') << endl;
    cout << string(12, '*') << " Data Input " << string(12, '*') << endl;
}

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
            // Display interface header
            printHeader();
            // Collect user input
            depositDetails = inputCapture();

        }
        // Catch any invalid arguments and handle them gracefully
        catch (invalid_argument& except) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
            cout << except.what() << endl;
        }

        // Set our class's private members
        setMInitialInvestAmt(depositDetails.at(0));
        setMMonthlyDep(depositDetails.at(1));
        setMAnnualInt(depositDetails.at(2));
        setMNumYears(depositDetails.at(3));

        // Check that depositDetails vector is full and user decides to continue
        if (depositDetails.size() == 4 && enterCheck()) {
            return depositDetails;
        }
    }
}

vector<double> DataInput::inputCapture() {
    // Collect user input and organize in a tidy vector
    vector<double> responses;
    vector<string> prompts = getMUserPrompts();

    for (int i = 0; i < prompts.size(); ++i) {
        string prompt = prompts.at(i);
        double userInput;
        cout << prompt;
        cin >> userInput;

        // Check for valid user input
        if (!cin || userInput < 0) {
        throw invalid_argument("\n\nAlphabetical characters and negative amounts not allowed. \n\n"
        "Please try again.\n\n");
        }

        // Add user input to our vector
        responses.push_back(userInput);
    }
    return responses;
}

/**
 *
 * @return bool
 */
bool DataInput::enterCheck() {
    cout << "Press enter to continue . . .\n\n\n";
    return cin.get() == '\n';
}
