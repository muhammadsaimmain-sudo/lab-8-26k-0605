
#include <stdio.h>

int main(void)
{
    int stock[3][4];
    int aisleTotal[3] = {0};
    int emptyShelves = 0;
    int bestAisle = 0;

    for (int i = 0; i < 3; i++)
    {
        printf("Enter stock for Aisle %d:\n", i + 1);

        for (int j = 0; j < 4; j++)
        {
            do
            {
                scanf("%d", &stock[i][j]);

                if (stock[i][j] < 0)
                    printf("Stock cannot be negative. Try again: ");

            } while (stock[i][j] < 0);

            aisleTotal[i] += stock[i][j];
        }
    }

    printf("\nOriginal Stock:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Aisle %d: ", i + 1);

        for (int j = 0; j < 4; j++)
            printf("%d ", stock[i][j]);

        printf("\n");
    }

    for (int i = 1; i < 3; i++)
    {
        if (aisleTotal[i] > aisleTotal[bestAisle])
            bestAisle = i;
    }

    printf("\nAisle with most stock: Aisle %d (%d units)\n",
           bestAisle + 1, aisleTotal[bestAisle]);

    printf("\nLow Stock Alerts:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
            {
                printf("Aisle %d, Position %d -> %d units\n",
                       i + 1, j + 1, stock[i][j]);

                if (stock[i][j] == 0)
                    emptyShelves++;
            }
        }
    }

    printf("\nEmpty shelves: %d\n", emptyShelves);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
                stock[i][j] += 10;
        }
    }

    int grandTotal = 0;

    printf("\nStock After Restocking:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Aisle %d: ", i + 1);

        for (int j = 0; j < 4; j++)
        {
            printf("%d ", stock[i][j]);
            grandTotal += stock[i][j];
        }

        printf("\n");
    }

    printf("\nNew grand total: %d units\n", grandTotal);

    return 0;
}
