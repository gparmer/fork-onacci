#include <stdio.h>
#include <assert.h>

#include <cycles.h>

const int iter = 1000;
const int N    = 20;

typedef int (*computation_fn_t)(int);

int
fib(int n)
{
	(void)n;

	return n;
}

int
fibork(int n)
{
	(void)n;

	return 0;
}

ps_tsc_t
benchmark(computation_fn_t fn, int arg, int *retval)
{
	ps_tsc_t start;
	int i;

	start = ps_tsc();
	for (i = 0; i < iter; i++) {
		 *retval = fn(arg);
	}

	return (ps_tsc() - start) / iter;
}

int
main(int argc, char *argv[])
{
	ps_tsc_t cycles;
	int ret;

	(void)argc;
	(void)argv;

	cycles = benchmark(fib, N, &ret);
	printf("fib(%d) = %d takes %lld cycles\n", N, ret, cycles);
	cycles = benchmark(fibork, N, &ret);
	printf("fibork(%d) = %d takes %lld cycles\n", N, ret, cycles);

	return 0;
}
