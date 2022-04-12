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

//function utilise pluseur fois
int nbr_arg_str(char *s);




//functin atoi
int ft_atoi(t_tab *my_tab,t_lists *t,char *a)
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
			ft_exit(my_tab,t);
		res = res * 10 + *a - '0';
		if (s == 1 && res > 2147483647)
			ft_exit(my_tab,t);
		else if (s == -1 && res > 2147483648)
			ft_exit(my_tab,t);
		a++;
	}
	return (res * s);
}

//remilre _tab
void cheak_tab(t_tab *my_tab,t_lists *t,int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (my_tab->tab[i] == my_tab->tab[size])
			ft_exit(my_tab,t);
		i++;
	}
}

char *ft_strncpy(char *from,char *dest,int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char **ft_split(t_tab *my_tab,t_lists *t,char *s)
{
	char **res;
	int n;
	int i;
	int j;

	n = nbr_arg_str(s);
	j = 0;
	if(!(res = (char **)malloc(sizeof(char *) * (n + 1))))
		ft_exit(my_tab,t);
	res[n] = NULL;
	while(*s)
	{
		i = 0;
		while(is_digit(s[i]) && !is_digit(s[i + 1]))
			i++;
		if(!(res[j] = malloc(sizeof(char) * (j + 1))))
			ft_exit(my_tab,t);
		res[j][i] = 0;
		res[j] = ft_strncpy(s,res[j],i);
		s++;
	}
	return res;
}
int *ft_multi_atoi(t_tab *my_tab,t_lists *t,char *s)
{
	int *tab;
	char **split;
	int n;
	int i;

	n = nbr_arg_str(s);
	i = 0;
	split = ft_split(my_tab,t,s);
	if(!(tab = malloc(sizeof(int) * n)))
		ft_exit(my_tab,t);
	while(i < n)
	{
		tab[i] = ft_atoi(my_tab,t,split[i]);
		i++;
	}
	return tab;
}


void remplire_tab(t_tab *my_tab,t_lists *t,char **av, int ac)
{
	int a;
	int b;
	int c;
	int *new_tab;
	int nbr_arg;

	a = 0;
	b = 1;
	while (a < ac - 1)
	{
		c = 0;
		nbr_arg = nbr_arg_str(av[b]);
		if(!(new_tab = malloc(sizeof(int) * nbr_arg)))
			ft_exit(my_tab,t);
		new_tab = ft_multi_atoi(my_tab,t,av[b]);
		
		while(c < nbr_arg)
		{
			my_tab->tab[a + c] = new_tab[c];
			c++;
		}
		free(new_tab);
		cheak_tab(my_tab,t,a);
		a += c;
		b++;
	}
}


t_list	*ft_lstnew(int data)
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
		n = ft_lstnew(tab[i]);
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
	int i;
	int j;
	int k;
	
	//sort_2(&a);
	i = (*a)->data;
	j = (*a)->next->data;
	k = (*a)->next->next->data;
	
	if (i > j && j > k)
	{
		*a = ft_ra(*a);
		*a = ft_sa(*a);
	}
	else if (i > k && k > j)
	 	*a = ft_ra(*a);
	else if (k > i && i >j)
	 	*a = ft_sa(*a);
	else if (j > k && k > i)
	{
		*a = ft_sa(*a);
		*a = ft_ra(*a);
	}
	else if (j > i && i > k)
		*a = ft_rra(*a);
}
void sort_100(t_list **a,t_list **b,int size)
{
	int i;
	int min;
	int position;
	t_list *tmp;
	
	while(size > 3)
	{
		//printf("size:%d\n",size);
		tmp = *a;
		min = (tmp)->data;
		//printf("min:%d\n",min);
		i = 0;
		while (tmp)
		{
			if (tmp ->data <= min)
			{
				position = i;
				min = tmp->data;
			}
			i++;
			tmp = tmp ->next;
			//printf("1\n");
			//sleep(1);
		}
		//printList(*a);
		//printList(*b);
		if (position < size/2)
		{
			while (position)
			{
				*a = ft_ra(*a);
				position--;
				//printf("2\n");
				//sleep(1);
			}
		}
		else
		{
			//printf("pos:%d\n",position);
			while (size - position)
			{
				*a = ft_rra(*a);
				position++;
				//printf("3\n");
				//sleep(1);
			}
		}
		ft_pb(a,b);
		size--;
		//printList(*a);
		//printList(*b);
	}
	sort_3(a);
	//printList(*a);
	while (*b)
	{
		ft_pa(a,b);
		
		//sleep(1);
	}
	
}

//nbr_arg
int nbr_arg_str(char *s)
{
	int res;

	res = 0;
	while(*s)
	{
		if(is_digit(*s) && !is_digit(*(s + 1)))
			res++;
		s++;
	}
	return res;
}

int nbr_arg(int ac,char **av)
{
	int res;
	int i;

	i = 1;
	res =0;
	while(i < ac)
	{
		res += nbr_arg_str(av[i]);
		i++;
	}
	return res;
}

//main
int main(int ac,char**av)
{
	t_lists	*t;
	t_tab	*my_tab;
	int		n;

	t = NULL;
	my_tab = NULL;
	if (ac > 2)
	{
		validation(av,ac);
		n = nbr_arg(ac,av);
		ft_malloc(my_tab,t,n);		
		remplire_tab(my_tab,t,av,ac);
		remplire_stack_a(&t->a,my_tab->tab,ac - 1);
		if (n == 2)
			sort_2(&t->a);
		else if (n == 3)
			sort_3(&t->a);
		else if (n <= 11)
			sort_100(&t->a,&t->b,ac - 1);
		ft_free(my_tab,t);
	}
	
	
	/*if (ac < 3)
	exit(0);
	if (!(tab = malloc(sizeof(t_list) * (ac - 1))))
		ft_exit(1);
	remplire_tab(tab,av,ac);
	remplire_stack_a(&a,tab,ac - 1);
	if (ac == 3)
		sort_2(&a);
	else if (ac == 4)
		sort_3(&a);
	else if (ac <= 11)
		sort_100(&a,&b,ac - 1);
	
	//remplire_stack_a(&b,tab,ac - 1);
	//ft_ss(&a,&b);
	//printList(a);
	//printList(b);
	free(tab);*/
	return (0);
}