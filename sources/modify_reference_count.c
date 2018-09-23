#include <limits.h>
#include "inner.h"

int						gbg_mod_refcount(
	void *addr,
	int inc,
	void *p_registry)
{
	t_s_entry	*entry;
	int			r;

	r = rbtn_retrieve(&addr, p_registry, &entry);
	if (r == RBT_KEY_NOT_FOUND)
		return (GBG_NOT_REG);
	else if (r =! RBT_SUCCESS)
		return (GBG_SYS_ERR);
	else if (inc > 0 && INT_MAX - inc < entry->refct)
		return (GBG_REFCT_TOO_BIG);
	else if ((r = (entry->refct += inc)) > 0)
		return (GBG_SUCCESS);
	rbtn_remove(&addr, p_registry);
	free_entry(addr, &entry);
	return (r < 0 ? GBG_NEG_REFCT : GBG_SUCCESS);
}