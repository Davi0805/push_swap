#include "push_swap.h"

int parse_error(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < ac)
    {
        //CHECAGEM MAIOR QUE INT MAX
        if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
            return (1);
        // CHECAGEM POR ALGO QUE NAO SEJA DIGITO
        while(av[i][j] != '\0')
        {
            if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
                return (1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int equal_number(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac - 1)
    {
        if (ft_atol(av[i]) == ft_atol(av[i + 1]))
            return (1);
        i++;
    }
    return (0);
}

// Caso seja varios argumentos
/* t_stack *fill_from_av(int ac, char **av)
{
    int i;
    t_stack *start;
    t_stack *stack;

    i = 1;
    stack = ft_stacknew((int)ft_atoi(av[i]));

    start = stack;

    while(i < ac - 1)
    {
        i++;
        stack->next = ft_stacknew((int)ft_atoi(av[i]));
        stack = stack->next;
    }
    return (start);
} */

t_stack *fill_from_av(int argc, char **argv)
{
    t_stack *stack = NULL;
    t_stack *new_node;
    t_stack *current;
    int i = 1;

    while (i < argc)
    {
        new_node = ft_stacknew(ft_atol(argv[i]));
        if (!new_node)
        {
            free_stack(stack);
            return NULL;
        }
        if (!stack)
        {
            stack = new_node;
        }
        else
        {
            current = stack;
            while (current->next != NULL)
                current = current->next;
            current->next = new_node;
        }
        i++;
    }
    return stack;
}

t_stack *fill_from_split(char *str)
{
    ft_printf("RODANDO SPLIT: %s\n", str);
    t_stack *result = NULL;
    char **args;
    args = NULL;
    args = ft_split(str, ' ');
    if (args == NULL)
        return (NULL);
    for (int i = 0; i < 3; i++)
        ft_printf("%s\n", args[i]);
    return (result);
}