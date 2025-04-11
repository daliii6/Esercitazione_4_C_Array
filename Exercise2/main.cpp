//trailling zeros : devo preservare lo zero dopo la virgola

#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main() 
{
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportData("data.txt", S, n, w, r)) 
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout<< "Import successful"<< endl; //RIVEDI STAMPA RESULTAT

    double R = Compute(n, w, r);
    double V = S * (1 + R);

    cout << fixed;
    cout.precision(2);
    cout << "S = " << S << ", n = " << n << endl;
    cout << "w = " << ArrayToString(n, w) << endl;
    cout << "r = " << ArrayToString(n, r) << endl;

    cout.precision(4);
    cout << "Rate of return of the portfolio: " << R << endl;

    cout.precision(2);
    cout << "V: " << V << endl;

    if (!ExportResult("result.txt", S, n, w, r, R, V))  
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}
