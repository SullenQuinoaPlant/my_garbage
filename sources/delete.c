#include "inner.h"

int				free_entry(
	void *unused,
	void *addr,
	void **p_entry)
{
	t_s_entry *const	entry = (t_s_entry*)*p_entry;

	(void)unused;
	ft_cleanfree(addr, entry->sz);
	ft_cleanfree(entry, sizeof(t_s_entry));
	return (RBT_SUCCESS);
}

void					gbg_delete(
	void **p_registry)
{
	rbt_delete_apply_postord(free_entry, (void*)0, p_registry);
}
