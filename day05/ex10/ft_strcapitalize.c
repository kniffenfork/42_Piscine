int not_letter(char c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        return 0;
    return 1;
}
char *ft_strcapitalize(char *str)
{
    int flag = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (not_letter(str[i]))
        {
            flag = 1;
            continue;
        }
        else if ((str[i] >= 97 && str[i] <= 122) && flag == 1) // делаем заглавные букавы
            str[i] -= 32;
        else if (str[i] >= 65 && str[i] <= 90 && flag == 0) // уменьшаем маленькие
            str[i] += 32;
        flag = 0;
    }
    return str;
}

