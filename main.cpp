#include <string>
#include <vector>
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
            DataInput dataInput; // Prompt user for input
            vector<double> userData = dataInput.promptUser();
//            dataInput.displayUserInput(userData); // Display transaction details back to user

            // User Calculations objects to manipulate the user data
            Calculations calculations;
            InvestmentInfo acctWithNoMonthlyDep = calculations.calculateAnnualInvestment(userData);
            InvestmentInfo acctWithMonthlyDep = calculations.calculateAnnualInvestment(userData, true);

            // User ReportGenerator objects to relay interest info back to the user
            ReportGenerator balanceAndInterestReport;
            balanceAndInterestReport.reportGenerator(acctWithNoMonthlyDep, acctWithMonthlyDep);
            restart = balanceAndInterestReport.additionalSessionCheck();
        } while (restart);
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}

int main() {

    startApp();

    return 0;
}
