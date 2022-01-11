#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#define N 7

int main(int argc, char *argv[]) {
	long total_allocated_memory = 0, allocated_memory;
	int i;

	printf("  Allocated memory\n");	
	for (i = 0; i < N; i++) {
		allocated_memory = syscall(__NR_slob_get_total_alloc_mem) ;

		
		total_allocated_memory = total_allocated_memory + allocated_memory;
		printf("%20ld\n", allocated_memory);
		getchar();
	}
	
	printf("======================================================\n");
	printf("TOTALS:\n");
	printf("%20ld\n", total_allocated_memory);

	printf("AVERAGE:\n");
	printf("%20ld\n", total_allocated_memory/N);

	return 0;
}