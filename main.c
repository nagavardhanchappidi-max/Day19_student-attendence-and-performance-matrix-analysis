#include <stdio.h>

int main() {

    char studentNames[5][20];
    int attendanceRecord[5][5];
    int marksRecord[5][5];
    int row, col, menuChoice;

    printf("Enter names of 5 students:\n");
    for (row = 0; row < 5; row++) {
        scanf("%s", studentNames[row]);
    }

    printf("\nEnter Attendance (1 for Present, 0 for Absent):\n");
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            scanf("%d", &attendanceRecord[row][col]);
        }
    }

    printf("\nEnter Marks (0-100):\n");
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            scanf("%d", &marksRecord[row][col]);
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

        switch(menuChoice) {

            case 1:
                printf("\nAttendance Matrix:\n");
                for (row = 0; row < 5; row++) {
                    for (col = 0; col < 5; col++) {
                        printf("%d ", attendanceRecord[row][col]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("\nMarks Matrix:\n");
                for (row = 0; row < 5; row++) {
                    for (col = 0; col < 5; col++) {
                        printf("%d ", marksRecord[row][col]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                int presentCount[5], absentCount[5];
                int maxAttendance = 0, minAttendance = 5;
                int maxIndex = 0, minIndex = 0;

                for (row = 0; row < 5; row++) {
                    presentCount[row] = 0;
                    absentCount[row] = 0;
                }

                for (row = 0; row < 5; row++) {
                    for (col = 0; col < 5; col++) {
                        if (attendanceRecord[row][col] == 1)
                            presentCount[row]++;
                        else
                            absentCount[row]++;
                    }
                }

                for (row = 0; row < 5; row++) {
                    if (presentCount[row] > maxAttendance) {
                        maxAttendance = presentCount[row];
                        maxIndex = row;
                    }
                    if (presentCount[row] < minAttendance) {
                        minAttendance = presentCount[row];
                        minIndex = row;
                    }
                }

                printf("\nAttendance Report:\n");
                for (row = 0; row < 5; row++) {
                    printf("%s -> Present: %d, Absent: %d\n",
                           studentNames[row], presentCount[row], absentCount[row]);
                }

                printf("Highest Attendance: %s (%d)\n", studentNames[maxIndex], maxAttendance);
                printf("Lowest Attendance : %s (%d)\n", studentNames[minIndex], minAttendance);
                break;
            }

            case 4: {
                int totalMarks[5];
                float avgMarks[5];
                int topper = 0, lowest = 0;

                for (row = 0; row < 5; row++) {
                    totalMarks[row] = 0;
                    for (col = 0; col < 5; col++) {
                        totalMarks[row] += marksRecord[row][col];
                    }
                    avgMarks[row] = totalMarks[row] / 5.0;
                }

                for (row = 1; row < 5; row++) {
                    if (totalMarks[row] > totalMarks[topper])
                        topper = row;
                    if (totalMarks[row] < totalMarks[lowest])
                        lowest = row;
                }

                printf("\nPerformance Report:\n");
                for (row = 0; row < 5; row++) {
                    printf("%s -> Total: %d, Average: %.2f\n",
                           studentNames[row], totalMarks[row], avgMarks[row]);
                }

                printf("Class Topper     : %s (%d)\n", studentNames[topper], totalMarks[topper]);
                printf("Lowest Performer : %s (%d)\n", studentNames[lowest], totalMarks[lowest]);
                break;
            }

            case 5: {
                int totalMarks[5];
                float avgMarks[5];
                char grade;

                for (row = 0; row < 5; row++) {
                    totalMarks[row] = 0;
                    for (col = 0; col < 5; col++) {
                        totalMarks[row] += marksRecord[row][col];
                    }
                    avgMarks[row] = totalMarks[row] / 5.0;
                }

                printf("\nGrade Report:\n");
                for (row = 0; row < 5; row++) {

                    if (avgMarks[row] >= 90) grade = 'A';
                    else if (avgMarks[row] >= 80) grade = 'A';
                    else if (avgMarks[row] >= 70) grade = 'B';
                    else if (avgMarks[row] >= 60) grade = 'C';
                    else if (avgMarks[row] >= 50) grade = 'D';
                    else grade = 'F';

                    printf("%s -> Average: %.2f, Grade: %c\n",
                           studentNames[row], avgMarks[row], grade);
                }
                break;
            }

            case 6:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }

    } while (menuChoice != 6);

    return 0;
}
