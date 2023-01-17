#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main() {
    const short minValue = 1;
    const short maxValue = 6;

    srand(time(nullptr));
    // int randDice = rand() % 6;
    short randDice1 = (rand() % (maxValue - minValue + 1)) + minValue;
    short randDice2 = (rand() % (maxValue - minValue + 1)) + minValue;
    cout << randDice1 <<","<< randDice2 << endl;
    return 0;
}