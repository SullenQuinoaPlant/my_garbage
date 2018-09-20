#ifndef INNER_H
# define INNER_H

# include mygarbage.h

typedef struct	s_gbg_entry
{
	size_t	sz;
	int		refct;
}				t_s_entry;

extern void		*g_gbg_registry;

#endif
