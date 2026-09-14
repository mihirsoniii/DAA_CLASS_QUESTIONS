#include <stdio.h>
int findCelebrity(int C[4][4], int n)
{
    int candidate = 0;
    int i;
    // Find a possible celebrity
    for (i = 1; i < n; i++)
    {
        if (C[candidate][i] == 1)
        {
            candidate = i;
        }
    }
    // Verify the candidate
    for (i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            if (C[candidate][i] == 1 || C[i][candidate] == 0)
            {
                return -1;
            }
        }
    }
    return candidate;
}
int main()
{
    int C[4][4] = {
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 1}
    };
    int n = 4;
    int celebrity;
    celebrity = findCelebrity(C, n);
    if (celebrity == -1)
    {
        printf("No Celebrity exists\n");
    }
    else
    {
        printf("Celebrity is Person %d\n", celebrity + 1);
    }
    return 0;
}