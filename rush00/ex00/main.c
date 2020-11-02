void rush(int x, int y);

int main(void)
{
    rush(10, 5);
    rush(1, 5);
    rush(5, 1);
    rush(1, 1);
    rush(1, 0);
    rush(0, 1);
    rush(-1, 5);
    rush(-2, 0);
    rush(0, -1);
    rush(3, -10);
    rush(-1, 0);
//да, вроде заебись, я ток 00 проверил, остальные аналогичные так что смысла нет
    return 0;
}