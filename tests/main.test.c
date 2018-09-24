#include <stdlib.h>
#include <stdio.h>
#include "libmygarbage.h"

int		main ()
{
	#define ALLOC_COUNT 10

	int		i;
	void	*allocs[ALLOC_COUNT];
	void	*p;
	void	*reg;
	size_t	gbg_total;


	reg = 0;
	if ((gbg_init(&reg)) != GBG_SUCCESS)
		return (1);
	printf("storing addresses:\n");
	for (i = 0; i < ALLOC_COUNT; i++)
		if ((p = malloc((size_t)i)) &&
			!gbg_register_alloc(p, (size_t)i, 1, reg))
		{
			allocs[i] = p;
			printf("%p,\n", p);
		}
	/*
	**reference count modifications greater than the stored count should be okay
	**	which is why we use '-i' in gbg_mod_refcount call.
	*/
	for (i = 0; i < ALLOC_COUNT; i++)
		gbg_mod_refcount(allocs[i], -i, reg);
	gbg_mem_use(reg, &gbg_total);
	if (gbg_total)
		printf("total : %zd\n", gbg_total);
	gbg_delete(&reg);

	return (0);
}
