#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // long elapsedSecond = time(nullptr);
    // srand(elapsedSecond);
    srand(time(nullptr));
    int randNum = rand() % 1000;
    cout << randNum << endl;
    // cout << elapsedSecond << endl;
    return 0;
}