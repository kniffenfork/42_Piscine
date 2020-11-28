#include "/Users/user/Desktop/Informatiks/learn_C/day13/ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmp)())
{
    if (!*root)
        *root = btree_create_node(item);
    else if (cmp((*root)->item, item) > 0)
        btree_insert_data(&((*root)->left), item, cmp);
    else
        btree_insert_data(&((*root)->right), item, cmp);
}