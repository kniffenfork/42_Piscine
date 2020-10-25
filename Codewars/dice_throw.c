#include <stdio.h>

/*
 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point

 5 3 5 5 5
 */

int score(const int dice[5])
{
    int flag_1 = 0;
    int flag_2 = 0;
    int flag_3 = 0;
    int flag_4 = 0;
    int flag_5 = 0;
    int flag_6 = 0;
    int res = 0;
    for (int i = 0; i < 5; i++)
    {
        if (dice[i] == 1)
            flag_1++;
        else if (dice[i] == 2)
            flag_2++;
        else if (dice[i] == 3)
            flag_3++;
        else if (dice[i] == 4)
            flag_4++;
        else if (dice[i] == 5)
            flag_5++;
        else if (dice[i] == 6)
            flag_6++;
    }
    if (flag_1 >= 3)
        res = res + 1000;
    if (flag_2 >= 3)
        res = res + 200;
    if (flag_3 >= 3)
        res = res + 300;
    if (flag_4 >= 3)
        res = res + 400;
    if (flag_5 >= 3)
        res = res + 500;
    if (flag_6 >= 3)
        res = res + 600;
    if (flag_1 < 3 && flag_1 > 0)
        res = res + 100;
    if ((flag_5 < 3) && flag_5 > 0)
        res = res + 50;

    for (int i = 0; i < 5; i++)
    {
        if (i < 4)
            printf("%d ", dice[i]);
        else
            printf("%d\n", dice[i]);
    }
    return res;
}

int main()
{
    const int dice[5] = {1, 1, 5, 5, 1};
    printf("%d", score(dice));
    return 0;
}