#include "inner.h"

int						gbg_unreg(
	void *addr,
	size_t *ret_sz,
	int *ret_refct,
	void *p_reg)
{
	t_s_entry	*entry;
	int			r;

	r = rbtn_remove_retrieve(&addr, p_reg, (void**)&entry);
	if (r == RBT_KEY_NOT_FOUND)
		return (GBG_NOT_REG);
	else if (r != RBT_SUCCESS)
		return (GBG_SYS_ERR);
	*ret_sz = entry->sz;
	*ret_refct = entry->refct;
	ft_cleanfree(entry, sizeof(t_s_entry));
	return (GBG_SUCCESS);
}
