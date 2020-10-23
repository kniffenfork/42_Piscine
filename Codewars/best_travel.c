#include <stdio.h>

int append_to_arr(int count_of_towns, const int *ls, int szls, int array[])
{
    int z=0, array;
    while (z != count_of_towns)
    {
        array[z] = ls[z];
        z++;
     0yfcvgi- ivcbjklv njklv m;/.,m
    return array[];
}
int chooseBestSum(int length, int count_of_towns, const int ls[], int szls)
{
    int result=0, count=0, z = 0;
    while (count != count_of_towns && (z != szls))
    {
        if ((length - result) > (length - (result + ls[z])))
        {
            result = result + ls[z];
            count++;
        }
        z++;
    }
    return result;
}


int main()
{
    int list[] = {50, 55, 57, 58, 60}, array[3];
    append_to_arr(3, list, 5);
    for (int i=0; i<3; i++)
    {
        printf("%d", array[i]);
    }
    return 0;
}