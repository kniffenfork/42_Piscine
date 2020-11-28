#include "ft_btree.h"

void            print_btree(t_btree *root)
{
    ft_putstr(root->item);
    if ((*root).left)
    {
        ft_putchar(' ');
        print_btree((*root).left);
    }
    if ((*root).right)
    {
        ft_putchar(' ');
        print_btree((*root).right);
    }
}

int main()
{
    t_btree **root = (t_btree **)malloc(sizeof(t_btree *));
    *root = NULL;
    btree_insert_data(root, "1", strcmp);
    btree_insert_data(root, "2", strcmp);
    btree_insert_data(root, "3", strcmp);
    btree_insert_data(root, "4", strcmp);
    btree_insert_data(root, "5", strcmp);
    btree_insert_data(root, "6", strcmp);
    btree_insert_data(root, "7", strcmp);


    print_btree(*root);
    ft_putchar('\n');
    ft_putstr(btree_search_item(*root, "3", strcmp));
    ft_putchar('\n');
    ft_putnbr(btree_level_count(*root));
}