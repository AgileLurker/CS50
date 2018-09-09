#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("how tall is the pyramid ? ");
    }
    while (height <0 || height>23);

    for (int i = 0; i < height; i++)
    {
        for (int j = i; j<height-1; j++)
        {
            printf(" ");
        }
        for (int m = 0; m <i+1; m++)
        {
            printf("#");
        }
        printf("  ");
        for(int k = 0; k<i+1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
