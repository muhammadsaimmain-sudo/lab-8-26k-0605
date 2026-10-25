
#include <stdio.h>

int main(void)
{
    int marks[4][3];
    int total[4] = {0};
    float average[4];
    char grade[4];
    char subjects[3][20] = {
        "Programming", "Calculus", "Physics"
    };

    int topStudent = 0;
    int worstSubject = 0;

    for (int i = 0; i < 4; i++)
    {
        printf("\nEnter marks for Student %d:\n", i + 1);

        for (int j = 0; j < 3; j++)
        {
            do
            {
                printf("%s: ", subjects[j]);
                scanf("%d", &marks[i][j]);

                if (marks[i][j] < 0 || marks[i][j] > 100)
                    printf("Invalid mark! Enter 0-100.\n");

            } while (marks[i][j] < 0 || marks[i][j] > 100);

            total[i] += marks[i][j];
        }

        average[i] = total[i] / 3.0f;

        if (average[i] >= 80)
            grade[i] = 'A';
        else if (average[i] >= 65)
            grade[i] = 'B';
        else if (average[i] >= 50)
            grade[i] = 'C';
        else
            grade[i] = 'F';

        if (average[i] > average[topStudent])
            topStudent = i;
    }

    printf("\nStudent Results:\n");
    printf("%-10s %5s %5s %5s %6s %8s %5s\n",
           "Student", "Prog", "Calc", "Phys",
           "Total", "Average", "Grade");

    for (int i = 0; i < 4; i++)
    {
        printf("%-10d %5d %5d %5d %6d %8.2f %5c\n",
               i + 1, marks[i][0], marks[i][1],
               marks[i][2], total[i], average[i], grade[i]);
    }

    float subjectAverage[3];

    printf("\nSubject Statistics:\n");
    printf("%-15s %7s %7s %8s\n",
           "Subject", "Highest", "Lowest", "Average");

    for (int j = 0; j < 3; j++)
    {
        int highest = marks[0][j];
        int lowest = marks[0][j];
        int sum = 0;

        for (int i = 0; i < 4; i++)
        {
            if (marks[i][j] > highest)
                highest = marks[i][j];

            if (marks[i][j] < lowest)
                lowest = marks[i][j];

            sum += marks[i][j];
        }

        subjectAverage[j] = sum / 4.0f;

        printf("%-15s %7d %7d %8.2f\n",
               subjects[j], highest, lowest,
               subjectAverage[j]);

        if (j == 0 ||
            subjectAverage[j] < subjectAverage[worstSubject])
        {
            worstSubject = j;
        }
    }

    printf("\nTop student: Student %d (Average %.2f)\n",
           topStudent + 1, average[topStudent]);

    printf("Worst subject: %s (Average %.2f)\n",
           subjects[worstSubject],
           subjectAverage[worstSubject]);

    return 0;
}
