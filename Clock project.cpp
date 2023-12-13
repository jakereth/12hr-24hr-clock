//Jacob Rethmeier
// 11/12/2023


#include <iostream>

using namespace std;

int hour;
int minute;
int second;
int menuInput = -1;

// Function to convert military time to standard time
string convertToStandardTimeSuffix(int h) {
    return (h >= 12) ? " PM" : " AM";
}

// Function to display time in standard format
void display12HourTime(int h, int m, int s) {
    cout << "************************" << endl;
    cout << "*    12 Hour clock     *" << endl;

    int displayHour = (h % 12 == 0) ? 12 : h % 12;
    if (displayHour < 10) cout << "*     0" << displayHour << ":";
    else cout << "*     " << displayHour << ":";

    if (m < 10) cout << "0";
    cout << m << ":";

    if (s < 10) cout << "0";
    cout << s << convertToStandardTimeSuffix(h) << "      *" << endl;

    cout << "************************" << endl;
}

void display24HourTime(int h, int m, int s) {
    cout << "************************" << endl;
    cout << "*    24 Hour clock     *" << endl;

    // Add leading zeros if needed
    cout << "*       " << (h < 10 ? "0" : "") << h << ":"
        << (m < 10 ? "0" : "") << m << ":"
        << (s < 10 ? "0" : "") << s << "       *" << endl;

    cout << "************************" << endl;
}

int main() {
    cout << "Please enter the current hour (0-23): ";  //check parameters of entered value 
    cin >> hour;
    while (hour < 0 || hour > 23) {
        cout << "Invalid value. Please enter hours between 0 and 23: ";
        cin >> hour;
    }
    cout << endl;

    cout << "Please enter the current minute (0-59): ";  //check parameters of entered value 
    cin >> minute;
    while (minute < 0 || minute > 59) {
        cout << "Invalid value. Please enter minutes between 0 and 59: ";
        cin >> minute;
    }
    cout << endl;

    cout << "Please enter the current second (0-59): "; //check parameters of entered value 
    cin >> second;
    while (second < 0 || second > 59) {
        cout << "Invalid value. Please enter seconds between 0 and 59: ";
        cin >> second;
    }
    cout << endl;

    display12HourTime(hour, minute, second); //call functions to display clock
    display24HourTime(hour, minute, second);

    while (menuInput != 4) {        //reiterate loop until 4 is entered to exit
        cout << "If you want to add:\n"
            << "1. 1 hour\n"
            << "2. 1 minute\n"
            << "3. 1 second\n"
            << "4. Exit the program\n";
        cin >> menuInput;

        switch (menuInput) {        //increment and check parameters of updated value 
        case 1: {
            hour += 1;
            if (hour >= 24) {
                hour = 0;
            }
            break;
        }

        case 2: {       //increment and check parameters of updated value 
            minute += 1;
            if (minute >= 60) {
                hour += 1;
                minute = 0;
                if (hour >= 24) {
                    hour = 0;
                }
            }
            break;
        }

        case 3: {       //increment and check parameters of updated value 
            second += 1;
            if (second >= 60) {
                minute += 1;
                second = 0;
                if (minute >= 60) {
                    hour += 1;
                    minute = 0;
                    if (hour >= 24) {
                        hour = 0;
                    }
                }
            }
            break;
        }

        case 4: {
            cout << "Exiting the program." << endl;
            break;
        }

        default: {
            cout << "Invalid input. Please try again." << endl;
            break;
        }
        }

        display12HourTime(hour, minute, second); //call functions to display updated clock
        display24HourTime(hour, minute, second);
    }

    return 0;
}