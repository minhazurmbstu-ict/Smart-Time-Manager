#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "timer.h"

#define CYCLE 60


/* ---------- Common Functions ---------- */

void clearScreen()
{
    system("cls");
}

void beepSound()
{
    Beep(1000, 500);
}

void printTime(int h, int m, int s)
{
    printf("%02d:%02d:%02d", h, m, s);
}

void waitOneSecond()
{
    Sleep(1000);
}


/* ---------- 1. Infinite Stopwatch ---------- */

void infiniteStopwatch()
{
    int h = 0, m = 0, s = 0;
    int paused = 0;
    char key;

    while (1)
    {
        clearScreen();

        printf("========== INFINITE STOPWATCH ==========\n\n");

        printf("Time: ");
        printTime(h, m, s);

        printf("\n\n");

        if (paused)
            printf("[PAUSED]\n");
        else
            printf("[RUNNING]\n");

        printf("\nP = Pause   R = Resume   S = Stop\n");

        if (_kbhit())
        {
            key = _getch();

            if (key == 'p' || key == 'P')
            {
                paused = 1;
            }
            else if (key == 'r' || key == 'R')
            {
                paused = 0;
            }
            else if (key == 's' || key == 'S')
            {
                break;
            }
        }

        if (!paused)
        {
            waitOneSecond();

            s++;

            if (s == CYCLE)
            {
                s = 0;
                m++;
            }

            if (m == CYCLE)
            {
                m = 0;
                h++;
            }
        }
        else
        {
            Sleep(100);
        }
    }

    printf("\nStopwatch Stopped!\n");

    printf("Final Time: ");
    printTime(h, m, s);

    printf("\n\n");

    system("pause");
}


/* ---------- 2. Count-up + Count-down Timer ---------- */

void countTimer()
{
    int targetH, targetM, targetS;

    int elapsedH = 0;
    int elapsedM = 0;
    int elapsedS = 0;

    int paused = 0;
    char key;

    printf("\n========== COUNT-UP + COUNT-DOWN TIMER ==========\n\n");

    printf("Enter Target Time (Hour Minute Second): ");
    scanf("%d %d %d", &targetH, &targetM, &targetS);

    int totalTarget = targetH * 3600 +
                      targetM * 60 +
                      targetS;

    while (1)
    {
        int elapsedTotal = elapsedH * 3600 +
                           elapsedM * 60 +
                           elapsedS;

        int remainingTotal = totalTarget - elapsedTotal;

        if (remainingTotal < 0)
            remainingTotal = 0;

        int rh = remainingTotal / 3600;
        int rm = (remainingTotal % 3600) / 60;
        int rs = remainingTotal % 60;

        clearScreen();

        printf("========== COUNT-UP + COUNT-DOWN ==========\n\n");

        printf("Target Time : ");
        printTime(targetH, targetM, targetS);

        printf("\nElapsed     : ");
        printTime(elapsedH, elapsedM, elapsedS);

        printf("\nRemaining   : ");
        printTime(rh, rm, rs);

        printf("\n\n");

        if (paused)
            printf("[PAUSED]\n");
        else
            printf("[RUNNING]\n");

        printf("\nP = Pause   R = Resume   S = Stop\n");

        if (elapsedTotal >= totalTarget)
        {
            beepSound();
            beepSound();

            printf("\n\nTIME COMPLETED!\n");

            break;
        }

        if (_kbhit())
        {
            key = _getch();

            if (key == 'p' || key == 'P')
                paused = 1;

            else if (key == 'r' || key == 'R')
                paused = 0;

            else if (key == 's' || key == 'S')
                break;
        }

        if (!paused)
        {
            waitOneSecond();

            elapsedS++;

            if (elapsedS == CYCLE)
            {
                elapsedS = 0;
                elapsedM++;
            }

            if (elapsedM == CYCLE)
            {
                elapsedM = 0;
                elapsedH++;
            }
        }
        else
        {
            Sleep(100);
        }
    }

    system("pause");
}


/* ---------- 3. Alarm / Time Reminder ---------- */

void alarmReminder()
{
    int alarmH, alarmM;

    printf("\n========== ALARM / TIME REMINDER ==========\n\n");

    printf("Enter Alarm Time (Hour Minute): ");
    scanf("%d %d", &alarmH, &alarmM);

    printf("\nAlarm set for %02d:%02d\n", alarmH, alarmM);

    printf("Waiting...\n");

    while (1)
    {
        time_t now = time(NULL);

        struct tm *current = localtime(&now);

        int currentH = current->tm_hour;
        int currentM = current->tm_min;

        clearScreen();

        printf("========== ALARM ==========\n\n");

        printf("Current Time : %02d:%02d:%02d\n",
               currentH,
               currentM,
               current->tm_sec);

        printf("Alarm Time   : %02d:%02d\n",
               alarmH,
               alarmM);

        if (currentH == alarmH && currentM == alarmM)
        {
            printf("\n\n******** TIME IS UP! ********\n");

            for (int i = 0; i < 5; i++)
            {
                beepSound();
                Sleep(300);
            }

            break;
        }

        Sleep(500);
    }

    system("pause");
}


/* ---------- 4. Periodic Reminder ---------- */

void periodicReminder()
{
    int totalMinutes;
    int reminderEvery;

    printf("\n========== PERIODIC REMINDER ==========\n\n");

    printf("Enter Total Time (minutes): ");
    scanf("%d", &totalMinutes);

    printf("Reminder Every (minutes): ");
    scanf("%d", &reminderEvery);

    int totalSeconds = totalMinutes * 60;
    int reminderSeconds = reminderEvery * 60;

    int elapsed = 0;

    while (elapsed < totalSeconds)
    {
        clearScreen();

        printf("========== PERIODIC REMINDER ==========\n\n");

        printf("Total Time     : %d minutes\n",
               totalMinutes);

        printf("Reminder Every : %d minutes\n",
               reminderEvery);

        printf("\nElapsed   : %02d:%02d\n",
               elapsed / 60,
               elapsed % 60);

        int remaining = totalSeconds - elapsed;

        printf("Remaining : %02d:%02d\n",
               remaining / 60,
               remaining % 60);

        Sleep(1000);

        elapsed++;

        if (elapsed % reminderSeconds == 0)
        {
            clearScreen();

            printf("\n\n");
            printf("************************************\n");
            printf("             REMINDER!              \n");
            printf("************************************\n");

            beepSound();
            beepSound();

            if (elapsed % reminderSeconds == 0)
{
    printf("\n\n");
    printf("************************************\n");
    printf("             REMINDER!              \n");
    printf("************************************\n");

    beepSound();
    beepSound();
}
        }
    }

    clearScreen();

    printf("\n\n");
    printf("************************************\n");
    printf("         TIME COMPLETED!            \n");
    printf("************************************\n");

    beepSound();
    beepSound();
    beepSound();

    system("pause");
}