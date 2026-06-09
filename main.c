#include "push_swap.h"

void	stack_printer(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("[%d], ", current->value);
		if ((current->previous) != NULL)
		{
			ft_printf("previous is: [%d], ", current->previous->value);
		}
		else
		{
			ft_printf("(Previous = NULL), ");
		}
		current = current->next;
	}
	ft_printf("-> NULL\n");
}

int	main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_arguments(argc, argv))
		error_exit;
	init_stack_a(&stack_a, argc, argv);


	stack_a = node_builder(2);
	stack_a->next = node_builder(5);
	stack_a->next->previous = stack_a;
	stack_a->next->next = node_builder(8);
	stack_a->next->next->previous = stack_a->next;

	printf("stack_a's initial state: \n");
	stack_printer(stack_a);
	printf("stack_a after sa: \n");
	sa(&stack_a);
	stack_printer(stack_a);
}
