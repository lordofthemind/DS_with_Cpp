#include <iostream>
using namespace std;

int main() {
    double sales =95000;
    double stateTaxRate =4;
    double countyTaxRate =2;

    double totalStateTax = sales * ( stateTaxRate / 100 );
    double totalCountyTax = sales * ( countyTaxRate / 100 );
    
    cout <<"Total State tax is " << totalStateTax << endl
         <<"Total County tax is " << totalCountyTax << endl
         <<"Total Tax is " << totalCountyTax + totalStateTax << endl;
    
    return 0;
}