
#include <stdio.h>

int main(void)
{
    int seats[5][6] = {0};
    int row, col;
    int booked = 0;
    int rowBookings[5] = {0};
    int bestRow = 0;

    while (1)
    {
        printf("Enter row (1-5, -1 to stop): ");
        scanf("%d", &row);

        if (row == -1)
            break;

        printf("Enter column (1-6): ");
        scanf("%d", &col);

        if (row < 1 || row > 5 || col < 1 || col > 6)
        {
            printf("Error: Invalid row or column!\n");
            continue;
        }

        row--;
        col--;

        if (seats[row][col] == 1)
        {
            printf("Error: Seat already booked!\n");
        }
        else
        {
            seats[row][col] = 1;
            printf("Seat booked successfully.\n");
        }
    }

    printf("\nSeating Chart:\n    1 2 3 4 5 6\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Row %d ", i + 1);

        for (int j = 0; j < 6; j++)
        {
            if (seats[i][j] == 1)
            {
                printf("X ");
                booked++;
                rowBookings[i]++;
            }
            else
            {
                printf("O ");
            }
        }

        printf("\n");
    }

    for (int i = 1; i < 5; i++)
    {
        if (rowBookings[i] > rowBookings[bestRow])
            bestRow = i;
    }

    printf("\nTotal booked seats: %d\n", booked);
    printf("Total empty seats: %d\n", 30 - booked);
    printf("Row with most bookings: Row %d\n", bestRow + 1);

    return 0;
}
