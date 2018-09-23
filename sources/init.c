#include "inner.h"

static t_e_comp		natural_order(
	void *addr1,
	void *addr2)
{
	if (addr1 != addr2)
		return ((uintptr_t)addr1 < (uintptr_t)addr2 ? e_lt : e_gt)
	return (e_eq);
}

int					gbg_init(
	void	**p_registry)
{
	int		r;

	if (*p_registry)
		return (GBG_DOUBLE_INIT);
	r = rbt_init(&natural_order, sizeof(void*), p_registry);
	if (r != RBT_SUCCESS)
		return (GBG_SYS_ERR);
	return (GBG_SUCCESS);
}
