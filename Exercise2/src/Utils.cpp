#include "Utils.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>


using namespace std;


//dimensione file non nota a compile time

bool ImportData(const string& inputfilePath, double& S, size_t& n, double*& w, double*& r) 
{
    ifstream fstr(inputfilePath);
    if (fstr.fail())
    {
        return false;
    }

    std::string line;  //temporary string 

	getline(fstr,line); // S;1000
    S = stod(line.substr(line.find(';') + 1));

    getline(fstr, line); // n;8
    n = stoi(line.substr(line.find(';') + 1));

    getline(fstr, line); // w;r

    w = new double[n];
    r = new double[n];

    for (size_t i = 0; i < n; ++i) {
        getline(fstr, line);
        stringstream ss(line);
        string wStr, rStr;
        getline(ss, wStr, ';');
        getline(ss, rStr);
        w[i] = stod(wStr);
        r[i] = stod(rStr);
    }

    return true;
}

double Compute(const size_t& n, 
               const double* const& w, 
               const double* const& r) 
{
    double sum = 0.0;
    for (size_t i = 0; i < n; ++i)
        sum += w[i] * r[i];
    return sum;
}

bool ExportResult(const string& outputFilePath, const double& S, 
                  const size_t& n, const double* const& w, 
                  const double* const& r, const double& R, 
                  const double& V)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << setprecision(2);
    file << "S = " << S << ", n = " << n << endl;

    file << "w = " << ArrayToString(n, w) << endl;
    file << "r = " << ArrayToString(n, r) << endl;

    file << setprecision(4);
    file << "Rate of return of the portfolio: " << R << endl;

    file << setprecision(2);
    file << "V: " << V << endl;

    return true;
}

string ArrayToString(const size_t& n, const 
                     double* const& v) 
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
