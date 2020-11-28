// #include "/Users/user/Desktop/Informatiks/learn_C/day13/ft_btree.h" // да ты уебан что ли, говорил не использовать
// абсолютные пути. по умолчанию можно использовать . , это будет текущая директория файла. надо другой - используй
// переменные среды
//у меня путь другой например к файлу, и у меня не скомпилится твое говно
// делай так:
#include "../ft_btree.h"

t_btree             *btree_create_node(void *item)//вроде ок
{
    t_btree *node = (t_btree *)malloc(sizeof(t_btree));

    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}