#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    int MonthstoDays(int m, int y) const {switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // leap
            if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
                return 29;
            }
            return 28;
        default:
            return 30;
    }}
public:
    Date(): year(1), month(1), day(1) {}
    Date(int m, int d, int y): month(m), day(d), year(y) {}
    // methods you can use in a way...........someway
    int getYear() const {return year;}
    int getMonth() const {return month;}
    int getDay() const {return day;}

    // add more days to teh day
    void addDays(int n) {
        day += n;
        while (day > MonthstoDays(month, year)) {
            day -= MonthstoDays(month, year);
            month += 1;
        }
        if (month > 12) {
            month -= 12;
            year++;
        }
    }
    Date operator+(int n) const {
        Date temp = *this;
        temp.addDays(n);
        return temp;
    }
    string toString() const {
        static const string months[] = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };

        return months[month - 1] + " " + to_string(day) + ", " + to_string(year);
    }

    // Output stream operator
    friend ostream& operator<<(ostream& os, const Date& d) {
        os << d.toString();
        return os;
    }
};



int main() {
    int year, month, day, daysToAdd;

    cout << "=== Appointment Scheduler ===\n\n";

    cout << "Enter appointment year: ";
    cin >> year;

    cout << "Enter appointment month: ";
    cin >> month;

    cout << "Enter appointment day: ";
    cin >> day;

    Date appointment(month, day, year);

    cout << "\nHow many days until the next appointment? ";
    cin >> daysToAdd;

    Date nextAppointment = appointment + daysToAdd;

    cout << "\nYour next appointment will be on:\n";
    cout << nextAppointment << endl;

    return 0;

}