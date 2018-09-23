#ifndef INNER_H
# define INNER_H

# include "libft.h"
# include "libmyrbtree.h"
# include "mygarbage.h"

typedef struct	s_gbg_entry
{
	size_t	sz;
	int		refct;
}				t_s_entry;

int				free_entry(
	void	*unused_arg,
	void	*addr,
	void	**p_entry);

#endif
