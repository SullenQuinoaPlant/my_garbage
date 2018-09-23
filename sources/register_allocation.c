#include "inner.h"

int					gbg_register_alloc(
	void *addr,
	size_t sz,
	int refct,
	void *p_reg)
{
	t_s_entry	*new;

	if (!addr)
		return (GBG_NO_ADDR);
	if ((new = malloc(sizeof(t_s_entry))) &&
		rbtn_insert(new, &addr, p_reg) == RBT_SUCCESS)
	{
		*new = (t_s_entry){sz, refct};
		return (GBG_SUCCESS);
	}
	else if (new)
		free(new);
	return (GBG_SYS_ERR);
}
