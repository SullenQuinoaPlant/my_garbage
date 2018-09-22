#include "inner.h"

void					gbg_delete(void)
{
	rbt_delete_free(sizeof(t_s_entry), g_gbg_registry);
}
