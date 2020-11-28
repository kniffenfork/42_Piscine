#ifndef LEARN_C_FT_BTREE_H
#define LEARN_C_FT_BTREE_H

#include "../day06/ex00/include/libft.h"
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef int t_bool;

typedef struct          s_btree
{

    struct s_btree      *left;
    struct s_btree      *right;
    void                *item;

}                       t_btree;

// funcs
t_btree             *btree_create_node(void *item);
void                btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void                btree_apply_infix(t_btree *root, void (*applyf)(void *));
void                btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void                btree_insert_data(t_btree **root, void *item, int (*cmpf)());
void                *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)());
int                 btree_level_count(t_btree *root);
#endif //LEARN_C_FT_BTREE_H
