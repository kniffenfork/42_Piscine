#include "/Users/user/Desktop/Informatiks/learn_C/day13/ft_btree.h"

t_btree             *btree_create_node(void *item)
{
    t_btree *node = (t_btree *)malloc(sizeof(t_btree));

    node->item = item;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}