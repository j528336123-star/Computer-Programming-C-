// Name: MUHAMMAD JAVED
// Department: Electrical Engineering (Power)
// Registration No: BF25NWELE0722
// Section: A
// CEP 
// SEMESTER : 2ND


#include <iostream>
using namespace std;

int main()
{
    int lines;

    cout << "Enter number of power lines: ";
    cin >> lines;

    string lineName[50];
    float normalCurrent[50];
    float current[50];

    int faultCount = 0;

    // STEP 1: Normal values
    cout << "\n--- NORMAL GRID DATA ---\n";

    for(int i = 0; i < lines; i++)
    {
        cout << "Enter line name: ";
        cin >> lineName[i];

        cout << "Normal current of " << lineName[i] << " (A): ";
        cin >> normalCurrent[i];
    }

    // STEP 2: Current readings
    cout << "\n--- LIVE GRID DATA ---\n";

    for(int i = 0; i < lines; i++)
    {
        cout << "Current of " << lineName[i] << " (A): ";
        cin >> current[i];
    }

    cout << "\n========== FAULT REPORT ==========\n";

    // STEP 3: Detection
    for(int i = 0; i < lines; i++)
    {
        float drop = normalCurrent[i] - current[i];

        cout << lineName[i]
             << " Drop: " << drop << " A\n";

        if(drop > 15)
        {
            cout << "? FAULT DETECTED in " << lineName[i] << endl;
            faultCount++;
        }
    }

    // STEP 4: System status
    cout << "\nTotal Faulty Lines: " << faultCount << endl;

    if(faultCount == 0)
    {
        cout << "System Stable\n";
    }
    else
    {
        cout << "System Unstable - Maintenance Required\n";
    }

    return 0;
}