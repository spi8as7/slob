#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#define N 7

int main(int argc, char *argv[]) {
	long total_free_memory = 0, free_memory;
	int i;

	printf("Free memory\n");	
	for (i = 0; i < N; i++) {
		free_memory = syscall(__NR_slob_get_total_free_mem);

		total_free_memory = total_free_memory + free_memory;
		printf("%20ld\n", free_memory);
		getchar();
	}
	
	printf("======================================================\n");
	printf("TOTALS:\n");
	printf("%20ld\n", total_free_memory);

	printf("AVERAGE:\n");
	printf("%20ld\n", total_free_memory/N);

	return 0;
