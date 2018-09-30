#include "inner.h"

int				free_entry(
	void *unused_arg,
	void *p_addr,
	void **p_entry)
{
	t_s_entry *const	entry = (t_s_entry*)*p_entry;
	void *const			addr = *(void**)p_addr;

	(void)unused_arg;
	ft_cleanfree(addr, entry->sz);
	ft_cleanfree(entry, sizeof(t_s_entry));
	return (RBT_SUCCESS);
}

void					gbg_delete(
	void **p_registry)
{
	rbt_delete_apply_postord(free_entry, (void*)0, p_registry);
}

/*
**Doesn't free the registered addresses:
*/
static int		free_entry_dirty(
	void *unused_arg,
	void *unused_p_addr,
	void **p_entry)
{
	t_s_entry *const	entry = (t_s_entry*)*p_entry;
	(void)unused_arg;
	(void)unused_p_addr;
	ft_cleanfree(entry, sizeof(t_s_entry));
	return (RBT_SUCCESS);
}

void					gbg_dirtydelete(
	void **p_registry)
{
	rbt_delete_apply_postord(free_entry_dirty, (void*)0, p_registry);
}
