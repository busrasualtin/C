#include <stdio.h>
int main()
{
    int a[4][2][5] = {
        {{1, 2}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12, 13, 14}},
        {{15, 16, 17, 18, 19}, {20, 21, 22}}};

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                printf("%2d ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}