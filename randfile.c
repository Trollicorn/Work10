#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(){

	int fd = open("/dev/random",O_RDONLY);
	
	int nums[10];
	int num;
	read(fd,nums,sizeof(int)*10);
	close(fd);
	
	printf("Generating random numbers:\n");
	for (int i = 0; i < 10; i++){
		printf("random %d: %d\n", i, nums[i]);
	}

	printf("Writing numbers to file...\n");
	fd = open("nums.txt",O_WRONLY | O_CREAT);
	printf("%d\n", fd);
	write(fd,nums,40);
	close(fd);
	
	printf("Reading numbers to file...\n");
	int n[10];	
	fd = open("nums.txt", O_RDONLY);
	read(fd,n,40);

	printf("Verification that written values were the same:\n");
	
	for (int i = 0; i < 10; i++){
		printf("random %d: %d\n", i, n[i] );
	}

	close(fd);

	return 0;
}
