#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include <stdlib.h>
#include "libmygarbage.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	#define ALLOC_COUNT 10
	T(ten_allocations,
		int		i;
		void	*p;
		void	*reg;
		size_t	total;
		size_t	gbg_total;


		reg = 0;
		if ((gbg_init(&reg)) != GBG_SUCCESS)
			skip();
		total = 0;
		for (i = 0; i < ALLOC_COUNT; i++)
			if ((p = malloc((size_t)i)) &&
				!gbg_register_alloc(p, (size_t)i, 1, reg))
				total += (size_t)i;
		gbg_mem_use(reg, &gbg_total);
		assert_true(gbg_total == total);
		gbg_delete(&reg);
	)

	T(ten_allocations_and_deallocs,
		int		i;
		void	*allocs[ALLOC_COUNT];
		void	*p;
		void	*reg;
		size_t	gbg_total;


		reg = 0;
		if ((gbg_init(&reg)) != GBG_SUCCESS)
			skip();
		for (i = 0; i < ALLOC_COUNT; i++)
			if ((p = malloc((size_t)i)) &&
				!gbg_register_alloc(p, (size_t)i, 1, reg))
				allocs[i] = p;
		/*
		**allocation of size 0 should not have been registered
		**reference count modifications greater than the stored count should be okay
		**	which is why we use '-i' in gbg_mod_refcount call.
		*/
		for (i = 0; i < ALLOC_COUNT; i++)
			gbg_mod_refcount(allocs[i], -i, reg);
		gbg_mem_use(reg, &gbg_total);
		assert_true(gbg_total == 0);
		gbg_delete(&reg);
	)

	T(ten_allocations_unregistered,
		int		i;
		void	*allocs[ALLOC_COUNT];
		void	*p;
		void	*reg;
		size_t	gbg_total;
		size_t	sz;
		int		ref_count;


		reg = 0;
		if ((gbg_init(&reg)) != GBG_SUCCESS)
			skip();
		for (i = 0; i < ALLOC_COUNT; i++)
			if ((p = malloc((size_t)i)) &&
				!gbg_register_alloc(p, (size_t)i, 1, reg))
				allocs[i] = p;
		/*
		**allocation of size 0 should not have been registered
		**reference count modifications greater than the stored count should be okay
		**	which is why we use 'i' in gbg_mod_refcount call.
		*/
		for (i = 0; i < 10; i++)
			gbg_unreg(allocs[i], &sz, &ref_count, reg);
		gbg_mem_use(reg, &gbg_total);
		assert_true(gbg_total == 0);
		gbg_delete(&reg);
		for (i = 0; i < ALLOC_COUNT; i++)
			free(allocs[i]);
	)

	return(run_test_arr(all_of, these));
}
