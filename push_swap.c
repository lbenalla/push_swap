/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:01:16 by labenall          #+#    #+#             */
/*   Updated: 2022/03/15 18:58:06 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//function exit 
void ft_exit(int a)
{
	write(1,"Error\n",6);
	exit(a);
}
//functin atoi
int ft_atoi(char *a)
{
	int long long res;
	int s;

	res = 0;
	s = 1;
	if(*a == ' ' || (*a >= 9 && *a <= 13))
		a++;
	if(*a == '-')
	{
		s = -1;
		a++;
	}
	else if (*a == '+')
		a++;
	while (*a)
	{
		if (*a > '9' || *a < '0')
			ft_exit(1);
		res = res * 10 + *a - '0';
		if (s == 1 && res > 2147483647)
			ft_exit(1);
		else if (s == -1 && res > 2147483648)
			ft_exit(1);
		a++;
	}
	return (res * s);
}
//remilre _tab
void remplire_tab(int *tab,char **av, int ac)
{
	int a = 0;
	int b = 1;
	while (a < ac - 1)
	{
		tab[a] = ft_atoi(av[b]);
		a++;
		b++;
	}
}
t_list	*ft_lstnew(int data,int position)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof (struct s_list));
	if (!t)
		return (NULL);
	t->data = data;
	t->next = NULL;
	return (t);
}

//function de lst
void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*t;

	t = *lst;
	if (*lst == NULL)
	{
		*lst = n;
		return ;
	}
	while (t->next)
		t = t->next;
	t->next = n;
}
void remplire_stack_a(t_list **a,int *tab,int size)
{
	t_list *n;
	int i = 0;
	while (i < size)
	{
		n = ft_lstnew(tab[i], i);
		ft_lstadd_back(a,n);
		i++;
	}
}
void printList(t_list *ptr) {
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//function de rules
t_list *ft_s(t_list *a)
{
	t_list *t;
	t_list *tmp;

	if (a == NULL)
	return (NULL);
	t = a;
	tmp = a;
	a = a->next->next;
	while(t->next)
		t = t->next;
	t->next = tmp;
	tmp->next->next = NULL;
	return a;
}
t_list *ft_sa(t_list *a)
{
	
	write(1,"sa\n",3);
	return (ft_s(a));
}
t_list *ft_sb(t_list *a)
{
	
	write(1,"sb\n",3);
	return (ft_s(a));
}
void	ft_ss(t_list **a,t_list **b)
{
	*a = ft_s(*a);
	*b = ft_s(*b);
	write(1,"ss\n",3);
}
void ft_p(t_list **a,t_list **b)
{
	t_list *a1;
	t_list *b1;
	t_list *tmp;

	a1 = *a;
	b1 = *b;
	while (a1->next->next)
		a1 = a1->next;
	tmp = a1->next;
	a1->next = NULL;
	while (b1->next)
		b1 = b1->next;
	b1->next = tmp;
}
void ft_pa(t_list **a,t_list **b)
{
	if (*b == NULL)
	return ;
	ft_p(b,a);
	write(1,"pa\n",3);
}
void ft_pb(t_list **a,t_list **b)
{
	if (*a == NULL)
	return ;
	ft_p(a,b);
	write(1,"pb\n",3);
}
t_list *ft_r(t_list *a)
{
	t_list *a1;
	t_list *tmp;

	tmp = a;
	a = a->next;
	a1 = a;
	while (a1->next)
		a1 = a1->next;
	a1->next = tmp;
	tmp->next = NULL;
	return (a);
}
t_list	*ft_ra(t_list *a)
{
	//printf("%d\n",(a)->data);
	if (!a)
	return NULL;
	write(1,"ra\n",3);
	return (ft_r(a));
}

t_list	*ft_rb(t_list *a)
{
	if (!a)
	return NULL;
	write(1,"rb\n",3);
	return (ft_r(a));
}
void  ft_rr(t_list **a,t_list **b)
{
	if (*a || *b)
	return ;
	*a = ft_r(*a);
	*b = ft_r(*b);
	write(1,"rr\n",1);
}

t_list *ft_rr_(t_list *a)
{
	t_list *a1;
	t_list *tmp;

	a1 = a;
	while (a1->next->next)
		a1 = a1->next;
	tmp = a1->next;
	a1->next = NULL;
	tmp->next = a;
	return (tmp);
}
t_list *ft_rra(t_list *a)
{
	if (a == NULL)
		return NULL;
	
	write(1,"rra\n",4);
	return (ft_rr_(a));
}
t_list *ft_rrb(t_list *a)
{
	if (a == NULL)
	return NULL;
	write(1,"rrb\n",4);
	return (ft_rr_(a));
}
void ft_rrr(t_list **a,t_list **b)
{
	if (*a == NULL || *b == NULL)
	return ;
	*a = ft_rr_(*a);
	*b = ft_rr_(*b);
	write(1,"rrr\n",4);
}
//functin de sort
void sort_2(t_list **a)
{
	//printf("%d\n",(*a)->data);
	//printf("%d\n",(*a)->next->data);
	if ((*a)->data > (*a)->next->data)
		*a = ft_ra(*a);
	
}
void sort_3(t_list **a)
{
	 
}
//main
int main(int ac,char**av)
{
	t_list	*a;
	t_list	*b;
	int		*tab;
	
	
	if (ac < 3)
	exit(0);
	tab = malloc(sizeof(t_list) * (ac - 1));
	remplire_tab(tab,av,ac);
	remplire_stack_a(&a,tab,ac - 1);
	if (ac == 3)
		sort_2(&a);
	else if (ac == 4)
		sort_3(&a);
	
	
	//remplire_stack_a(&b,tab,ac - 1);
	//printList(a);
	return (0);
}