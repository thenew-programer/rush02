#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_SIZE 4096
# define TRUE 1
# define FALSE 0
# define ATOI_ERROR 3
# define IO_ERROR 4
# define PARSING_ERROR 5
# define MEMORY_ERROR 6
# define ARGS_ERROR 7

extern int	g_error;

typedef unsigned __int128	t_ui128;

typedef struct s_stock_nbr
{
	unsigned __int128 	nbr;
	char			*str;
	int				end;
}	t_stock_nbr;

t_ui128	ft_atoi(char *str);
t_stock_nbr	*parse_dict(char *filename);

/* Utils */
void	ft_puterror(char *str);
void	ft_putstr(char *str);
void	print_dict(t_stock_nbr *stock);
void	free_stock(t_stock_nbr	*stock);
void	ft_putchar(char c);
void	ft_putnbr(__int128 nbr);
char	*ft_clean_strdup(char *str, int size);
int		open_file(char *filename);
int		read_file(int fd, char *buffer);
int		is_space(char c);
void	ft_swap(t_stock_nbr *ptr1, t_stock_nbr *ptr2);
char	*search_stock(t_stock_nbr *stock, t_ui128 nbr);



void	ft_print_to_fd(char *str, int fd);
void	ft_print(char *str);
void	ft_print_line(char *str);
void	ft_print_error(char *str);


char	**get_multiplier(t_stock_nbr *stock);
char	**get_first_twenty(void);
char	**get_tens(void);

int				ft_strlen(char *str);
char			*ft_strdup(char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcat(char *dest, char *src);
char			*ft_tricat(char *dest, char *src1, char *src2);


char	*number_to_words(t_ui128 n, t_stock_nbr *stock);
char	*converter(char *answer, t_ui128 *curr_hun, int *t, t_stock_nbr *stock);
int		check_max(t_stock_nbr *stock, t_ui128 nbr);
#endif

