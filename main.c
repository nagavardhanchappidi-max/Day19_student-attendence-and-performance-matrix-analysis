#include <stdio.h>

int main() {

    char studentNames[5][20];
    int att[5][5];
    int score[5][5];
    int row, col, menuChoice;

    printf("Enter names of 5 students:\n");
    for (row = 0; row < 5; row++) {
        scanf("%s", studentNames[row]);
    }

    printf("\nEnter Attendance (1 for Present, 0 for Absent):\n");
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            scanf("%d", &att[row][col]);
        }
    }

    printf("\nEnter Marks (0-100):\n");
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            scanf("%d", &score[row][col]);
        }
    }

    do {
        printf("\n========= MENU =========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

    
        if (menuChoice == 1) {
            printf("\nAttendance Matrix:\n");
            for (row = 0; row < 5; row++) {
                for (col = 0; col < 5; col++) {
                    printf("%d ", att[row][col]);
                }
                printf("\n");
            }
        }

        else if (menuChoice == 2) {
            printf("\nMarks Matrix:\n");
            for (row = 0; row < 5; row++) {
                for (col = 0; col < 5; col++) {
                    printf("%d ", score[row][col]);
                }
                printf("\n");
            }
        }

        else if (menuChoice == 3) {

            int presentCount[5];
            int absentCount[5];
            int maxAtt = 0, minAtt = 5;
            int maxIndex = 0, minIndex = 0;

            for (row = 0; row < 5; row++) {
                presentCount[row] = 0;
                absentCount[row] = 0;
            }

            for (row = 0; row < 5; row++) {
                for (col = 0; col < 5; col++) {
                    if (att[row][col] == 1)
                        presentCount[row]++;
                    else
                        absentCount[row]++;
                }
            }

            for (row = 0; row < 5; row++) {
                if (presentCount[row] > maxAtt) {
                    maxAtt = presentCount[row];
                    maxIndex = row;
                }
                if (presentCount[row] < minAtt) {
                    minAtt = presentCount[row];
                    minIndex = row;
                }
            }

            printf("\nAttendance Report:\n");
            for (row = 0; row < 5; row++) {
                printf("%s -> Present: %d, Absent: %d\n",
                       studentNames[row], presentCount[row], absentCount[row]);
            }

            printf("Highest Attendance : %s (%d)\n", studentNames[maxIndex], maxAtt);
            printf("Lowest Attendance  : %s (%d)\n", studentNames[minIndex], minAtt);
        }

        else if (menuChoice == 4) {

            int totalScore[5];
            float avgScore[5];
            int topper = 0, low = 0;

            for (row = 0; row < 5; row++) {
                totalScore[row] = 0;
            }

            for (row = 0; row < 5; row++) {
                for (col = 0; col < 5; col++) {
                    totalScore[row] += score[row][col];
                }
                avgScore[row] = totalScore[row] / 5.0;
            }

            for (row = 1; row < 5; row++) {
                if (totalScore[row] > totalScore[topper]) {
                    topper = row;
                }
                if (totalScore[row] < totalScore[low]) {
                    low = row;
                }
            }

            printf("\nPerformance Report:\n");
            for (row = 0; row < 5; row++) {
                printf("%s -> Total: %d, Average: %.2f\n",
                       studentNames[row], totalScore[row], avgScore[row]);
            }

            printf("Class Topper     : %s (%d)\n",
                   studentNames[topper], totalScore[topper]);
            printf("Lowest Performer : %s (%d)\n",
                   studentNames[low], totalScore[low]);
        }

        else if (menuChoice == 5) {

            int totalScore[5];
            float avg[5];
            char grade;

            for (row = 0; row < 5; row++) {
                totalScore[row] = 0;
                for (col = 0; col < 5; col++) {
                    totalScore[row] += score[row][col];
                }
                avg[row] = totalScore[row] / 5.0;
            }

            printf("\nGrade Report:\n");
            for (row = 0; row < 5; row++) {

                if (avg[row] >= 90) grade = 'A';
                else if (avg[row] >= 80) grade = 'A';
                else if (avg[row] >= 70) grade = 'B';
                else if (avg[row] >= 60) grade = 'C';
                else if (avg[row] >= 50) grade = 'D';
                else grade = 'F';

                printf("%s -> Average: %.2f, Grade: %c\n",
                       studentNames[row], avg[row], grade);
            }
        }

    } while (menuChoice != 6);

    printf("\nExiting Program...\n");
    return 0;
}