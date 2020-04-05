#include <string>
#include <iostream>
#include "DataInput.h"
#include "Calculations.h"
#include "ReportGenerator.h"
#include "InvestmentInfo.h"

using namespace std;

void startApp() {
    bool restart = true;

    try {
        do {
            // Prompt user for input and store results
            DataInput userData;
            userData.promptUser();

            // Pass the user input on to make appropriate calculations
            Calculations calculations;
            InvestmentInfo acctWithNoMonthlyDep = calculations.calculateAnnualInvestment(userData);
            InvestmentInfo acctWithMonthlyDep = calculations.calculateAnnualInvestment(userData, true);

            // User ReportGenerator objects to relay interest info back to the user
            ReportGenerator balanceAndInterestReport;
            balanceAndInterestReport.reportGenerator(acctWithNoMonthlyDep, acctWithMonthlyDep);

            // Prompt the user to continue or exit program
            restart = balanceAndInterestReport.additionalSessionCheck();
        } while (restart);
    }
    catch (runtime_error& except) {
        cout << "Oops! Something went wrong. Exception: " <<  except.what() << endl;
    }
}

int main() {

    startApp();

    return 0;
}
