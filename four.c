
#include <stdio.h>

int main(void)
{
    int beds[2][3][2] = {0};
    int choice;

    do
    {
        printf("\n--- Hospital Bed Management ---\n");
        printf("1. Admit Patient\n");
        printf("2. Discharge Patient\n");
        printf("3. Occupancy Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int floor, patientID;
            int admitted = 0;

            printf("Enter floor (1-2): ");
            scanf("%d", &floor);

            if (floor < 1 || floor > 2)
            {
                printf("Invalid floor!\n");
                continue;
            }

            printf("Enter patient ID: ");
            scanf("%d", &patientID);

            if (patientID == 0)
            {
                printf("Patient ID cannot be 0.\n");
                continue;
            }

            int f = floor - 1;

            for (int w = 0; w < 3 && !admitted; w++)
            {
                for (int b = 0; b < 2; b++)
                {
                    if (beds[f][w][b] == 0)
                    {
                        beds[f][w][b] = patientID;

                        printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n",
                               patientID, floor, w + 1, b + 1);

                        admitted = 1;
                        break;
                    }
                }
            }

            if (!admitted)
                printf("Floor %d is full.\n", floor);
        }
        else if (choice == 2)
        {
            int patientID;
            int found = 0;

            printf("Enter patient ID to discharge: ");
            scanf("%d", &patientID);

            for (int f = 0; f < 2 && !found; f++)
            {
                for (int w = 0; w < 3 && !found; w++)
                {
                    for (int b = 0; b < 2; b++)
                    {
                        if (beds[f][w][b] == patientID &&
                            patientID != 0)
                        {
                            beds[f][w][b] = 0;

                            printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n",
                                   patientID, f + 1, w + 1, b + 1);

                            found = 1;
                            break;
                        }
                    }
                }
            }

            if (!found)
                printf("Patient ID %d not found.\n", patientID);
        }
        else if (choice == 3)
        {
            int highestFloor = 0;
            int highestWard = 0;
            int highestOccupied = -1;

            printf("\n--- Occupancy Report ---\n");

            for (int f = 0; f < 2; f++)
            {
                int floorOccupied = 0;

                printf("Floor %d\n", f + 1);

                for (int w = 0; w < 3; w++)
                {
                    int occupied = 0;

                    for (int b = 0; b < 2; b++)
                    {
                        if (beds[f][w][b] != 0)
                            occupied++;
                    }

                    int vacant = 2 - occupied;
                    floorOccupied += occupied;

                    printf("  Ward %d: Occupied %d, Vacant %d\n",
                           w + 1, occupied, vacant);

                    if (occupied > highestOccupied)
                    {
                        highestOccupied = occupied;
                        highestFloor = f;
                        highestWard = w;
                    }
                }

                float percentage = floorOccupied / 6.0f * 100;

                printf("  Floor occupancy: %.1f%%\n", percentage);

                if (percentage > 80.0f)
                {
                    printf("WARNING: Floor %d is more than 80%% full.\n",
                           f + 1);
                }
            }

            printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n",
                   highestFloor + 1, highestWard + 1,
                   highestOccupied);
        }
        else if (choice == 4)
        {
            printf("Exiting program.\n");
        }
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
