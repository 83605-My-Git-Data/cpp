// Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
// Date is having data members day, month, year. Implement the following functions.
// void initDate();
// void printDateOnConsole();
// void acceptDateFromConsole();
// bool isLeapYear();


#include<iostream>
using namespace std;

struct dateStruct{
    int day;
    int month;
    int year;
};

class Date{
    private:
        int day;
        int month;
        int year;

    public:
        void initDate(){
            day = 01;
            month = 01;
            year = 2000;

        }
        void printDateOnConsole(){
            cout<<"Entered date is:"<<endl;
            cout<<day<<"-"<<month<<"-"<<year<<endl;


        }
        void acceptDateFromConsole(){
            cout<<"Enter the date: "<<endl;
            cin>>day;
            cout<<"Enter the month: "<<endl;
            cin>>month;
            cout<<"Enter the year: "<<endl;
            cin>>year;


        }
        bool isLeapYear(){
            if(year % 4 == 0 && year%100 !=0 || year % 400 ==0){
                return true;
            }
            else{
                return false;
            }


        }

};

int main() {
    int choice;
    Date d;
    dateStruct date;

    do {
        cout << "Hello,\nPress 0: To exit\nPress 1: To enter date\nPress 2: To check for leap year\nPress 3: To print date\nPress 4: To enter date (struct)\nPress 5: To check for leap year (struct)\nPress 6: To print date (struct)\n";

        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Thanks for using" << endl;
                break;
            case 1:
                d.acceptDateFromConsole();
                break;
            case 2:
                if (d.isLeapYear()) {
                    cout << "This is a leap year" << endl;
                } else {
                    cout << "This is not a leap year" << endl;
                }
                break;
            case 3:
                d.printDateOnConsole();
                break;
            case 4:
                cout << "Enter the whole date (day month year): ";
                cin >> date.day >> date.month >> date.year;
                break;
            case 5:
                if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0) {
                    cout << "Leap year" << endl;
                } else {
                    cout << "Not leap year" << endl;
                }
                break;
            case 6:
                cout << "Entered date is: " << date.day << "-" << date.month << "-" << date.year << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
