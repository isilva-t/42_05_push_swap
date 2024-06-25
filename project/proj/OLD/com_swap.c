#include "../push_swap.h"

static void	swap(t_list **head) //Define a function that swaps the positions of the top node and second node of a stack
{
	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
	(*head)->prev->prev = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
	(*head)->prev->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*head)->next) //Check if there's a `next` node after the `new head` and
		(*head)->next->prev = (*head)->prev; //If so, update its `prev` pointer to point back to the `new head`
	(*head)->next = (*head)->prev; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
	(*head)->prev = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
}

void	sa(t_list	**a) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
		ft_printf("sa\n");
}

void	sb(t_list **b) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
		ft_printf("ss\n");
}
