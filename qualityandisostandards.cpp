#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to calculate overall quality score
float calculateQuality(float reliability, float usability, float efficiency, float maintainability, float security) {
    return (reliability + usability + efficiency + maintainability + security) / 5;
}

// Function to get quality level as per ISO standards
string qualityLevel(float score) {
    if (score >= 9)
        return "Excellent Quality - Fully ISO 9001 & ISO 25010 Compliant";
    else if (score >= 7)
        return "Good Quality - Meets ISO 9001 Standards";
    else if (score >= 5)
        return "Moderate Quality - Needs Improvement";
    else
        return "Poor Quality - Below ISO Standard";
}

int main() {
    cout << "=========================================\n";
    cout << " STUDENT REGISTRATION SYSTEM - QUALITY PLANNING\n";
    cout << " Based on ISO 9001 (Process) & ISO 25010 (Product)\n";
    cout << "=========================================\n\n";

    cout << "Enter software quality attribute ratings (1 to 10):\n\n";

    float reliability, usability, efficiency, maintainability, security;

    cout << "1. Reliability (System Stability): ";
    cin >> reliability;
    cout << "2. Usability (Ease of use, UI Design): ";
    cin >> usability;
    cout << "3. Efficiency (Performance, Response Time): ";
    cin >> efficiency;
    cout << "4. Maintainability (Ease of Fix/Update): ";
    cin >> maintainability;
    cout << "5. Security (Protection of Student Data): ";
    cin >> security;

    float score = calculateQuality(reliability, usability, efficiency, maintainability, security);
    string level = qualityLevel(score);

    cout << "\n-----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Average Quality Score: " << score << " / 10\n";
    cout << "Quality Assessment: " << level << endl;
    cout << "-----------------------------------------\n\n";

    cout << "Note:\n";
    cout << "- ISO 9001 ensures the development *process* follows quality management.\n";
    cout << "- ISO 25010 ensures the *software product* meets functional quality attributes.\n";
    cout << "- Maintain documentation, testing, and continuous improvement for compliance.\n";

    return 0;
}

