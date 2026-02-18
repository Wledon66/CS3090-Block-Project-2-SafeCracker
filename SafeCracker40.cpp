/*
 * Author: William Ledon
 * Date: 02/18/26
 * University of Utah
 * License: BSD 2-Clause
 *
 */

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>


using namespace std;
using std::vector;

const double NA_VAL = numeric_limits<double>::quiet_NaN();
const int SIZE = 16;

double getRotatedValue(const vector<double>& wheel, int position, int rotationNum) {
    return wheel[(position + rotationNum) % SIZE];
}

int main() {

    // Level 1
    vector<double> levelOneLower = {2, 15, 23, 19, 3, 2, 3, 27, 20, 11, 27, 10, 19, 10, 13, 10};
    vector<double> LevelOneHigher = {22, 9, 5, 10, 5, 1, 24, 2, 10, 9, 7, 3, 12, 24, 10, 9};

    // Level 2
    vector<double> levelTwoLower = {16, NA_VAL, 17, NA_VAL, 2, NA_VAL, 2, NA_VAL,
                                    10, NA_VAL, 15, NA_VAL, 6, NA_VAL, 9, NA_VAL};
    vector<double> levelTwoHigher = {11, 27, 14, 5, 5, 7, 8, 24,
                                     8, 3, 6, 15, 22, 6, 1, 1};

    // Level 3
    vector<double> levelThreeLower = {10, NA_VAL, 2, NA_VAL, 22, NA_VAL, 2, NA_VAL,
                                      17, NA_VAL, 15, NA_VAL, 14, NA_VAL, 5, NA_VAL};
    vector<double> levelThreeHigher = {1, 6, 10, 6, 10, 2, 6, 10,
                                       4, 1, 5, 5, 4, 8, 6, 3};

    // Level 4
    vector<double> levelFourHigher = {6, NA_VAL, 13, NA_VAL, 3, NA_VAL, 3, NA_VAL,
                                      6, NA_VAL, 10, NA_VAL, 10, NA_VAL, 10, NA_VAL};

    // Brute-force search
    for(int wheelOne = 0; wheelOne < SIZE; wheelOne++) {
        for(int wheelTwo = 0; wheelTwo < SIZE; wheelTwo++) {
            for(int wheelThree = 0; wheelThree < SIZE; wheelThree++) {
                for(int wheelFour = 0; wheelFour < SIZE; wheelFour++) {

                    bool validCombo = true;

                    for(int i = 0; i < SIZE; i++) {

                        // Column 1 (Level one is fixed on the puzzle with no values ever covered)
                        double c1 = getRotatedValue(levelOneLower, i, wheelOne);

                        // Column 2
                        double c2 = getRotatedValue(LevelOneHigher, i, wheelOne);
                        double temp2 = getRotatedValue(levelTwoLower, i, wheelTwo);
                        if (!isnan(temp2)) c2 = temp2;

                        // Column 3
                        double c3 = getRotatedValue(levelTwoHigher, i, wheelTwo);
                        double temp3 = getRotatedValue(levelThreeLower, i, wheelThree);
                        if (!isnan(temp3)) c3 = temp3;

                        // Column 4
                        double c4 = getRotatedValue(levelThreeHigher, i, wheelThree); 
                        double temp4 = getRotatedValue(levelFourHigher, i, wheelFour);
                        if (!isnan(temp4)) c4 = temp4;

                        double sum = c1 + c2 + c3 + c4;

                        if (sum != 40) {
                            validCombo = false;
                            break;
                        }
                    }

                    if (validCombo) {
                        cout << "Solution found!\n";
                        cout << " Wheel 1 = " << wheelOne
                             << " Wheel 2 = " << wheelTwo
                             << " Wheel 3 = " << wheelThree
                             << " Wheel 4 = " << wheelFour << endl;
                        return 0; 
                    }

                }
            }
        }
    }

    cout << "No solution found." << endl;
    return 0;
}
