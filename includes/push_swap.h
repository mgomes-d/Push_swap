/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:46:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/25 10:02:03 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		qtx;

}	t_data;

int		ft_start_data(int ac, char **av, t_data *data);

void	ft_algo(t_data *data);

void	ft_sb(t_data *data, int i);
void	ft_sa(t_data *data, int i);
void	ft_ss(t_data *data);

void	ft_ra(t_data *data, int i);
void	ft_rb(t_data *data, int i);
void	ft_rr(t_data *data);

void	ft_rra(t_data *data, int i);
void	ft_rrb(t_data *data, int i);
void	ft_rrr(t_data *data);

void	ft_pa(t_data *data);
void	ft_pb(t_data *data);

/*
	struct utils
*/

t_stack	*ft_lstnewstack(int content);
t_stack	*ft_lstlaststack(t_stack *lst);
void	ft_lstadd_frontstack(t_stack **lst, t_stack *new);
void	ft_lstadd_backstack(t_stack **lst, t_stack *new);
int		ft_lstsizestack(t_stack *lst);
t_stack	*ft_navigatelist(t_stack *lst, int size);
int		ft_isdigitsymbol(char c);
int		ft_verifynotsame(t_data *data);
void	ft_4numbers(t_data *data, t_stack *stack);
t_stack	*ft_smallest(int *size, t_stack *temp);
void	ft_3numbers(t_data *data, t_stack *stack);

int		ft_done(t_data *data);
int		ft_put_int_str_utils(char *str, int j, t_stack **listall);
void	ft_free_stack(t_data *data);

// Raditz
void	ft_raditz(t_data *data);
void	ft_sort_struct(t_data *data);

#endif
