#ifndef LEARN_C_LIBFT_H
#define LEARN_C_LIBFT_H

#define ABS(nbr) (((nbr) >= 0) ? (nbr) : ((nbr) * (-1)))

int             ft_power(int n, int k);

void            ft_putchar(char c);

void            ft_putnbr(int nbr);

void            ft_putstr(char *str);

int             ft_sqrt(int nb);

int             ft_str_is_alpha(const char *str);

int             ft_str_is_lowercase(const char *str);

int             ft_str_is_numeric(char *str);

int             ft_str_is_printable(const char *str);

int             ft_str_is_uppercase(const char *str);

char            *ft_strcapitalize(char *str);

char            *ft_strcat(char *dest, char *src);

int             ft_strcmp(char *s1, char *s2);

char            *ft_strcpy(char *dest, char *src);

char            *ft_strlowcase(char *str);

int             ft_strlen(char *str);

char            *ft_strncat(char *dest, char *src, int nb);

char            *ft_strncpy(char *dest, char *src, unsigned int n);

char            *ft_strrev(char str[]);

char            *ft_strstr(char *str, const char *to_find);

char            *ft_strupcase(char *str);

void            ft_swap(int *a, int*b);

char            **ft_split_whitespaces(char *str);

int             ft_atoi(char *str);

#endif //LEARN_C_LIBFT_H
