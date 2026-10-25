
#include <stdio.h>

void printImage(int image[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%4d ", image[i][j]);

        printf("\n");
    }
}

int main(void)
{
    int image[4][4];
    int brightnessImage[4][4];
    int bwImage[4][4];
    int flippedImage[4][4];
    int result[4][4];

    int brightness, threshold;

    printf("Enter 16 pixel values (0-255):\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            do
            {
                scanf("%d", &image[i][j]);

                if (image[i][j] < 0 || image[i][j] > 255)
                    printf("Invalid pixel! Enter 0-255: ");

            } while (image[i][j] < 0 || image[i][j] > 255);
        }
    }

    printf("Enter brightness amount: ");
    scanf("%d", &brightness);

    printf("Enter threshold value: ");
    scanf("%d", &threshold);

    printf("\nOriginal Image:\n");
    printImage(image);

    // 1. Brightness adjustment
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int value = image[i][j] + brightness;

            if (value > 255)
                value = 255;

            if (value < 0)
                value = 0;

            brightnessImage[i][j] = value;
        }
    }

    printf("\nBrightness Adjusted:\n");
    printImage(brightnessImage);

    // 2. Black-and-white threshold
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (image[i][j] >= threshold)
                bwImage[i][j] = 255;
            else
                bwImage[i][j] = 0;
        }
    }

    printf("\nBlack and White:\n");
    printImage(bwImage);

    // 3. Horizontal flip
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            flippedImage[i][j] = image[i][3 - j];
        }
    }

    printf("\nFlipped Horizontally:\n");
    printImage(flippedImage);

    // 4. Smoothing
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // Border pixels stay unchanged
            if (i == 0 || i == 3 || j == 0 || j == 3)
            {
                result[i][j] = image[i][j];
            }
            else
            {
                int sum = 0;

                // Add the pixel and its 8 neighbours
                for (int r = i - 1; r <= i + 1; r++)
                {
                    for (int c = j - 1; c <= j + 1; c++)
                    {
                        sum += image[r][c];
                    }
                }

                result[i][j] = sum / 9;
            }
        }
    }

    printf("\nSmoothed Image:\n");
    printImage(result);

    return 0;
}
