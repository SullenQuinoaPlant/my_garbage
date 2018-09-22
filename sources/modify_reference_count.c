#include <limits.h>
#include "inner.h"

int						gbg_mod_refcount(
	void *addr,
	int inc)
{
	t_s_entry	*ref;
	int			r;

	r = rbtn_retrieve(&addr, &g_gbg_registry, &ref);
	if (r == RBT_KEY_NOT_FOUND)
		return (GBG_NOT_REG);
	else if (r =! RBT_SUCCESS)
		return (GBG_SYS_ERR);
	else if (inc > 0 && INT_MAX - inc < ref->refct)
		return (GBG_REFCT_TOO_BIG);
	else if ((r = (ref->refct += inc)) > 0)
		return (GBG_SUCCESS);
	rbtn_remove(&addr, g_gbg_registry);
	ft_cleanfree(addr, ref->sz);
	ft_cleanfree(ref, sizeof(t_s_entry);
	return (r < 0 ? GBG_NEG_REFCT : GBG_SUCCESS);
}
