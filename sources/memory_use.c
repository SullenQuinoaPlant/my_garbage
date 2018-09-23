#include "inner.h"

int						summer(
	void 		*p_retsum,
	void 		*p_key,
	void *const	*p_entry)
{
	size_t *const		ret_sum = (size_t*)p_retsum;
	t_s_entry *const	entry = (t_s_entry*)*p_entry;

	ret_sum += entry->sz;
	return (RBT_SUCCESS);
}

int						gbg_mem_use(
	void *p_reg,
	size_t *ret_sum)
{
	int	r;

	*ret_sum = 0;
	r = rbt_apply_inord(&summer, (void*)ret_sum, p_reg);
	return (r);
}
