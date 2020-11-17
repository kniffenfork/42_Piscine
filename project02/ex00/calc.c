#include "calc.h"

/*

Рассматриваем поочередно каждый символ:
1. Если этот символ - число (или переменная), то просто помещаем его в стек-ответ.
2. Если символ - знак операции (+, -, *, / ), то проверяем приоритет операции.
Наименьший приоритет (равен 1) имеет открывающая скобка.
Получив один из этих символов, мы должны проверить стек:

 а) Если стек все еще пуст, или находящиеся в нем символы (а находится в нем могут только знаки операций и открывающая скобка) имеют меньший приоритет,
 чем приоритет текущего символа, то помещаем текущий символ в стек.
б) Если символ, находящийся на вершине стека имеет приоритет, больший или равный приоритету текущего символа, то извлекаем символы из стека в
 выходную строку до тех пор, пока выполняется это условие; затем переходим к пункту а).
3. Если текущий символ - открывающая скобка, то помещаем ее в стек.
4. Если текущий символ - закрывающая скобка, то извлекаем символы из стека в выходную строку до тех пор, пока не встретим в стеке открывающую скобку
   которую также следует просто уничтожить.

 Если вся входная строка разобрана, а в стеке еще остаются знаки операций, извлекаем их из стека в выходную строку.
 */

void            print_polish_notation(t_calc *expression)
{
    int k = 0;
    while (expression->polish_notation[k])
    {
        ft_putstr(expression->polish_notation[k]);
        ft_putchar(' ');
        k++;
    }
}

int             get_priority_of_operation(char *operation)
{
    if (operation[0] == '+')
        return plus;

    else if (operation[0] == '-')
        return minus;

    else if (operation[0] == '*')
        return multiply;

    else if (operation[0] == '/')
        return division;

    else if (operation[0] == '%')
        return reminder;

    else
        return 0;
}

void             create_polish_notation(t_calc *expression)
{
    Stack_t *operations = createStack();
    Stack_t *polish = createStack();

    int i = 0;
    while (expression->expression_split[i])
    {
        if (is_digit(expression->expression_split[i]))
        {
            push(polish, expression->expression_split[i]);
        }
        else
        {
            if (expression->expression_split[i][0] == '(')
            {
                push(operations, "(");

            }
            else if (expression->expression_split[i][0] == ')')
            {
                while (peek(operations)[0] != '(')
                {
                    push(polish, pop(operations));
                }
                pop(operations); // чтобы и саму скобку удалить
            }
            else
            {
                if (operations->top == 0 || get_priority_of_operation(expression->expression_split[i]) > get_priority_of_operation(peek(operations)))
                    push(operations, expression->expression_split[i]);

                else if (get_priority_of_operation(peek(operations)) >= get_priority_of_operation(expression->expression_split[i]))
                {
                    while (get_priority_of_operation(peek(operations)) >= get_priority_of_operation(expression->expression_split[i]))
                    {
                        push(polish, pop(operations));
                        if (operations->top == 0)
                            break;
                    }

                    if (operations->top == 0 || get_priority_of_operation(peek(operations)) < get_priority_of_operation(expression->expression_split[i]))
                    {
                        push(operations, expression->expression_split[i]);
                    }
                }
            }
        }
        i++;
    }
    if (operations->top != 0)
    {
        while (operations->top != 0)
        {
            push(polish, pop(operations));
        }
    }

    int j = 0;
    while (polish->top != 0) // переводим стек-ответ в строку
    {
        expression->polish_notation[j] = pop(polish);
        j++;
    }

    expression->size_of_polish = j;
}

void calculate_polish_notation(t_calc *expression)
{
    int i = expression->size_of_polish - 1;
    Stack_t *counting = createStack();
    while (i >= 0) // пробегаемся с конца стек-ответа (он же развернут)
    {
        if (is_digit(expression->polish_notation[i]))
        {
            push(counting, expression->polish_notation[i]);
        }
        else if (is_operation(expression->polish_notation[i]))
        {
            int num_2 = ft_atoi(pop(counting));
            int num_1 = ft_atoi(pop(counting));
            char *result_of_operation = malloc(100);

            if (expression->polish_notation[i][0] == '+')
            {
                result_of_operation[0] = ((num_1 + num_2) + '0');
                push(counting, result_of_operation);
            }
            else if (expression->polish_notation[i][0] == '-')
            {
                result_of_operation[0] = ((num_1 - num_2) + '0');
                push(counting, result_of_operation);
            }
            else if (expression->polish_notation[i][0] == '*')
            {
                result_of_operation[0] = ((num_1 * num_2) + '0');
                push(counting, result_of_operation);
            }
            else if (expression->polish_notation[i][0] == '/')
            {
                result_of_operation[0] = ((num_1 / num_2) + '0');
                push(counting, result_of_operation);
            }
            else if (expression->polish_notation[i][0] == '%')
            {
                result_of_operation[0] = ((num_1 % num_2) + '0');
                push(counting, result_of_operation);
            }
        }
        i--;
    }
    printStack(counting);
}
