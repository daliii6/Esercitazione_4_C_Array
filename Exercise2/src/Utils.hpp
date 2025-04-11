#pragma once
#include <iostream>
#include <string>

using namespace std;


bool ImportData(const string& inputfilePath, double& S, size_t& n, double*& w, double*& r);

double Compute(const size_t& n, const double* const& w, const double* const& r);

bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& R, const double& V);

string ArrayToString(const size_t& n, const double* const& v);


