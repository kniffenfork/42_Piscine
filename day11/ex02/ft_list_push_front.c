#include "../ft_list.h"

t_list          *ft_create_elem(void *data)
{
    t_list *list = (t_list *)malloc(sizeof(t_list));

    list->data = data;
    list->next = NULL;

    return list;
}

void ft_list_push_front(t_list **head, void *data)
{
    t_list *tmp;

    if (*head == NULL) // если у нас пустой список, то просто создаем узел -- он и будет началом
        ft_create_elem(data);

    else
    {
        tmp = ft_create_elem(data); // создали узел с нашей data
        tmp->next = *head; // сделали указатель на начало
        *head = tmp; // начало теперь наш новый узелок
    }
}

