#include <string.h>
#include <stdio.h>

int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;

}

char *ft_strstr(char *str, const char *to_find)
{
    char *res;
    /*
     * если хочется пооптимизировать:
     * for (int i = 0; i < strlenght(str) - strlenght(to_find), но надо считать, не уверен
     */
    for (int i = 0; i < strlength(str); i++) {
        if (str[i] == to_find[0]) {
            int j = 0;
            int k = i;
            while (to_find[j]) {
                if (to_find[j] != str[k])
                    break;
            }
            res = str[i];
            return res;
        }
    }
    return res;
}

int main()
{
    char str[] = "123456";
    char find[] = "345";
    char *istr;
    istr = strstr(str, find);
    printf("%s", istr);
}