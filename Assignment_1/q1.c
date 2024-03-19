// Write a menu driven program for Date in a C. Declare a structure Date having data members 
// day, month, year. Implement the following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate)

#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}

void printDateOnConsole(struct Date *ptrDate) {
    printf("Entered date is: %d-%d-%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate) {
    printf("Enter the date: ");
    scanf("%d", &ptrDate->day);
    printf("Enter the month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter the year: ");
    scanf("%d", &ptrDate->year);
}

int main() {
    struct Date date;
    int choice;

    do {
        printf("\nHello,\nPress 0: To exit\nPress 1: To enter date\nPress 2: To print date\n");

        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thanks for using\n");
                break;
            case 1:
                acceptDateFromConsole(&date);
                break;
            case 2:
                printDateOnConsole(&date);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
