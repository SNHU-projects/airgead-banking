#include <string>
#include <vector>
#include "DataInput.h"
#include "Calculations.h"
#include "BalanceAndInterest.h"
#include "InvestmentInfo.h"

using namespace std;

int main() {

    // TODO: Delete me, but control g is multi cursors!!!

    DataInput dataInput; // Prompt user for input
    vector<double> userData = dataInput.promptUser();
    dataInput.displayUserInput(userData); // Display transaction details back to user

    // User Calculations objects to manipulate the user data
    Calculations calculations;
    InvestmentInfo acctWithNoMonthlyDep = calculations.calculateAnnualInvestment(userData);
    InvestmentInfo acctWithMonthlyDep = calculations.calculateAnnualInvestment(userData, true);

    // User BalanceAndInterest objects to relay interest info back to the user
    BalanceAndInterest balanceAndInterestReport;
    balanceAndInterestReport.reportGenerator(acctWithNoMonthlyDep, acctWithMonthlyDep);

    return 0;
}
