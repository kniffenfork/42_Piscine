#include "/Users/user/Desktop/Informatiks/learn_C/day13/ft_btree.h"


void            btree_apply_suffix(t_btree *root, void (*applyf)(void *)) // уфф
{
    if (root->left)
        btree_apply_prefix(root->left, applyf);

    if (root->right)
        btree_apply_prefix(root->right, applyf);

    applyf(root->item);
}