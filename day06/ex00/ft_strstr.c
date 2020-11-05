int ft_strlen(char *str);

char *ft_strstr(char *str, const char *to_find)
{
    char *res;
    for (int i = 0; i < ft_strlen(str); i++) {
        if (str[i] == to_find[0]) {
            int j = 0;
            int k = i;
            while (to_find[j]) {
                if (to_find[j] != str[k])
                    break;
                j++;
            }
            res = &str[i];
        }
    }
    return res;
}

