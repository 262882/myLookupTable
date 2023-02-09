#include <iostream>
#include <vector>
#include "../myLookup.h"

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<vector<double>> tab{
        { 3.144,  3.123,  3.079,  3.072,  3.022,  3.039,  3.071,  2.924,  2.783,  2.98},
        { 6.285,  6.192,  6.117,  6.119,  6.036,   5.88,  5.915,  5.834,  5.648, 5.658},
        { 9.127,  9.024,  8.895,  8.824,  8.745,  8.564,  8.485,  8.381,  8.33 , 8.226},
        {11.764, 11.625, 11.42 , 11.371, 11.151, 10.984, 10.825, 10.754, 10.613, 11.08},
        };

    vector<double> col{0., 10., 20., 30., 40., 50., 60., 70., 80., 90.};
    vector<double> row{2.,  4.,  6.,  8.};

    LookUpTable2D myTable(tab, row, col);

    double res;
    double *resptr = &res;

    // display result
    cout << "In bounds interpolation: " << endl;
    myTable.lookup(5, 35, resptr);
    cout << "Computed Result: " << *resptr << endl;
    cout << "Expected Result: " << "7.431" << endl;
    cout << endl;

    cout << "Beyond x interpolation: " << endl;
    myTable.lookup(4, 100, resptr);
    cout << "Computed Result: " << *resptr << endl;
    cout << "Expected Result: " << "5.658" << endl;
    cout << endl;

    cout << "Beyond y interpolation: " << endl;
    myTable.lookup(10, 50, resptr);
    cout << "Computed Result: " << *resptr << endl;
    cout << "Expected Result: " << "10.984" << endl;
    cout << endl;

    return 0;
}
