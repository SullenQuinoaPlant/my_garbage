/*


mygarbage.h






*/

#ifndef MYGARBAGE_H
# define MYGARBAGE_H

# include <stddef.h>
# include <stdint.h>
/*
**NOTE : casts (void*)s to (uintptr_t)s for ordering.
**Which, as far as I can tell isn't really compliant.
**
**Bottom line : 
** - don't use if binary representation
**of pointers are liable to change over time.
** - don't use if (uintptr_t) isn't available.
*/

/*
**functions:
*/
int				gbg_init(
	void	**p_registry);

void			gbg_delete(
	void	**p_registry);

void			gbg_dirtydelete(
	void	**p_registry);

/*
**Can fail if (size_t) may be too small to store size of
**several memory allocations:
*/
int				gbg_mem_use(
	void	*p_registry,
	size_t	*ret_sz_sum);

int				gbg_mod_refcount(
	void	*for_address,
	int		ref_count_change,
	void	*p_registry);

int				gbg_register_alloc(
	void	*address,
	size_t	alloc_sz,
	int		initial_refcount,
	void	*p_registry);

/*
**unregister address:
*/
int				gbg_unreg(
	void	*address,
	size_t	*ret_alloc_sz,
	int		*ret_refcount,
	void	*p_registry);

/*
**return codes
*/
# define GBG_SYS_ERR -1
# define GBG_SUCCESS 0
/*
**GBG_NOT_REG as in not_registered
*/
# define GBG_NOT_REG 1
# define GBG_DOUBLE_INIT 2
# define GBG_REFCT_TOO_BIG 3
# define GBG_NEG_REFCT 4
# define GBG_NO_ADDR 5

#endif
