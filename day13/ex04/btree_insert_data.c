#include "../ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmp)())//вроде ок
{
    //if (!*root) пиши нормально, а то будешь как борщехлебы на плюсах за еду работать
    if ((*root) == null)
        *root = btree_create_node(item);
    else if (cmp((*root)->item, item) > 0)
        btree_insert_data(&((*root)->left), item, cmp);
    else
        btree_insert_data(&((*root)->right), item, cmp);
}