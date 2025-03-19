/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:54:58 by abmasnao          #+#    #+#             */
/*   Updated: 2025/03/15 02:52:19 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define RED_COLOR "\033[31m"
# define END_COLOR "\033[0m"

typedef struct s_stack {
	int	*arr;
	int	size;
}				t_stack;

int		ft_atoi(char *str, char **args, int *arr);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	parser(int ac, char **av, t_stack *stack_a);
int		is_sorted(t_stack *stack_x);
void	free_f(char **arr);
void	print_error(void);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		main(int ac, char **av);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
void	move(char *move, t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack_x);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_x);
void	rev_r(t_stack *stack_x);
void	ft_bzero(void *s, size_t n);
void	empty_check(int ac, char **av);
void	plus_minus_check(int ac, char **av);
void	invalid_char(int ac, char **av);
int		*stoi(char **args);
void	dup_check(int *arr, int end);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char	*join(char *str, char *buf);
char	*cleanup(char **str, char **buf);
char	*inc_line(char *str);
char	*gnl(char **str);
char	*get_next_line(int fd);
char	*s_join(char **str, char *buf);

#endif