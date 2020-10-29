int power(int n, int k)
{
    int j = n;
    if (k == 0)
        return 1;
    for (int i = 1; i < k; i++)
        n *= j;
    return n;
}