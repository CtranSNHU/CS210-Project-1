#define _CRT_SECURE_NO_WARNINGS  // Disable localtime deprecation warning

#include <iostream>
#include <ctime>
#include <iomanip>

// Function to display the 12-hour clock
void display12HourClock(const struct tm& timeInfo) {
    std::cout << "**************************\t**************************\n";
    std::cout << "*\t12-Hour Clock    *\t*       24-Hour Clock    *\n";
    std::cout << "*\t" << std::put_time(&timeInfo, " %I:%M:%S %p") << "\t *\t*\t    " << std::put_time(&timeInfo, "%H:%M:%S") << "\t *\n";
    std::cout << "**************************\t**************************\n";
}
//std::left << std::setw(28) <<
// Function to add one hour, minute, or second to the time
void addTime(struct tm& timeInfo, int hours, int minutes, int seconds) {
    timeInfo.tm_hour += hours;
    timeInfo.tm_min += minutes;
    timeInfo.tm_sec += seconds;
    std::mktime(&timeInfo); // Normalize the time
}

int main() {
    struct tm currentTime;
    std::time_t t = std::time(nullptr);
    currentTime = *std::localtime(&t);

    char choice;

    do {
        display12HourClock(currentTime);

        std::cout << "\n**************************\n";
        std::cout << "* 1 - Add One Hour       *\n";
        std::cout << "* 2 - Add One Minute     *\n";
        std::cout << "* 3 - Add One Second     *\n";
        std::cout << "* 4 - Exit Program       *\n";
        std::cout << "**************************\n";

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            addTime(currentTime, 1, 0, 0);
            break;
        case '2':
            addTime(currentTime, 0, 1, 0);
            break;
        case '3':
            addTime(currentTime, 0, 0, 1);
            break;
        case '4':
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
