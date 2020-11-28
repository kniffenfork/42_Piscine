#include "../ft_btree.h"

int             btree_level_count(t_btree *root)// код выглядит впорядке, но я всегда рекурсию хуево читаю, так что
//													надеюсь, что оно работает))0)0
{
    if (root == NULL)
        return 0;

    int left;
    int right; // clion сам подчеркивает, что значение 0 не используются

    left = btree_level_count(root->left);
    right = btree_level_count(root->right);
    return (left > right ? left + 1 : right + 1);
}