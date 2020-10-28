int ft_str_is_lowercase(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123)
            continue;
        else
            return 0;
    }
    return 1;
}