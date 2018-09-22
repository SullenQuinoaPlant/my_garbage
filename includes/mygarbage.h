#ifndef MYGARBAGE_H
# define MYGARBAGE_H

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
int				gbg_init(void);

void			gbg_delete(void);

int				gbg_mod_refcount(
	void	*for_address,
	int		ref_count_change);

int				gbg_register_alloc(
	void	*address,
	size_t	alloc_sz,
	int		initial_refcount);

void			gbg_unregister_address(
	void	*for_address,
	size_t	*ret_alloc_sz,
	int		*ret_refcount);

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
# define GBG_REFCT_TOO_BIG

#endif
