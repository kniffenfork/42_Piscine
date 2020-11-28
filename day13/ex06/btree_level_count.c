#include "/Users/user/Desktop/Informatiks/learn_C/day13/ft_btree.h"

int             btree_level_count(t_btree *root)
{
    if (root == NULL)
        return 0;

    int left = 0;
    int right = 0;

    left = btree_level_count(root->left);
    right = btree_level_count(root->right);
    return (left > right ? left + 1 : right + 1);
}