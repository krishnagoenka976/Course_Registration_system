// cocomo.cpp
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double estimate_effort(double KLOC, const string& mode) {
    double a, b;
    if (mode == "Organic" || mode == "organic") { a = 2.4; b = 1.05; }
    else if (mode == "Semi-detached" || mode == "semi-detached") { a = 3.0; b = 1.12; }
    else if (mode == "Embedded" || mode == "embedded") { a = 3.6; b = 1.20; }
    else { cerr << "Unsupported project mode: " << mode << endl; return 0.0; }
    return a * pow(KLOC, b);
}

double estimate_schedule(double effort, const string& mode) {
    double c, d;
    if (mode == "Organic" || mode == "organic") { c = 2.5; d = 0.38; }
    else if (mode == "Semi-detached" || mode == "semi-detached") { c = 2.5; d = 0.35; }
    else if (mode == "Embedded" || mode == "embedded") { c = 2.5; d = 0.32; }
    else { cerr << "Unsupported project mode: " << mode << endl; return 0.0; }
    return c * pow(effort, d);
}

int main() {
    double KLOC;
    string mode;

    cout << "Enter size of project in KLOC: ";
    if (!(cin >> KLOC)) return 0;
    cout << "Enter project mode (Organic / Semi-detached / Embedded): ";
    cin >> ws; // eat whitespace
    getline(cin, mode);

    double effort = estimate_effort(KLOC, mode);
    double schedule = (effort > 0.0) ? estimate_schedule(effort, mode) : 0.0;
    double staffing = (schedule > 0.0) ? effort / schedule : 0.0;

    cout << fixed << setprecision(2);
    cout << "\nEstimated Effort: " << effort << " Person-Months" << endl;
    cout << "Estimated Development Time: " << schedule << " Months" << endl;
    cout << "Estimated Average Staff Required: " << staffing << " Persons" << endl;

    return 0;
}

