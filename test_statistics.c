#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#define N 7

int main(int argc, char *argv[]) {
	long total_allocated_memory = 0, allocated_memory;
	long total_free_memory = 0, free_memory;
	int i;

	printf("  Allocated memory      \t       Free memory\n");	
	for (i = 0; i < N; i++) {
		allocated_memory = syscall(__NR_slob_get_total_alloc_mem) ;
		free_memory = syscall(__NR_slob_get_total_free_mem);
		
		total_allocated_memory = total_allocated_memory + allocated_memory;
		total_free_memory = total_free_memory + free_memory;
		printf("%20ld\t%20ld\n", allocated_memory, free_memory);
		getchar();
	}
	
	printf("======================================================\n");
	printf("TOTALS:\n");
	printf("%20ld\t%20ld\n", total_allocated_memory, total_free_memory);

	printf("AVERAGE:\n");
	printf("%20ld\t%20ld\n", total_allocated_memory/N, total_free_memory/N);

	return 0;
}
