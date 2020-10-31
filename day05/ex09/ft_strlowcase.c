char *ft_strlowcase(char *str)
{
	/* потесть на строках:
	 * 'aSd'
	 * '0009'
	*/
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] += 32;
    }
    return str;
}
