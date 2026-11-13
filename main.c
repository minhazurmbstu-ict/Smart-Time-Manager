#include <stdio.h>
#include <stdlib.h>
#include "timer.h"


int main()
{
    int choice;

    while (1)
    {
        system("cls");

        printf("============================================\n");
        printf("             SMART TIME MANAGER             \n");
        printf("============================================\n\n");

        printf("1. Infinite Stopwatch\n");
        printf("2. Count-up + Count-down Timer\n");
        printf("3. Alarm / Time Reminder\n");
        printf("4. Periodic Reminder\n");
        printf("5. Exit\n");

        printf("\n============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:
                infiniteStopwatch();
                break;

            case 2:
                countTimer();
                break;

            case 3:
                alarmReminder();
                break;

            case 4:
                periodicReminder();
                break;

            case 5:
                printf("\nThank you for using Smart Time Manager!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
                system("pause");
        }
    }

    return 0;
}