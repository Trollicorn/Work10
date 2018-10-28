#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(){

	int fd = open("/dev/random",O_RDONLY);
	printf("%d\n", fd);
	int nums[10];
	int num;
	read(fd,nums,sizeof(int)*10);
	close(fd);
	
	printf("Generating random numbers:\n");
	for (int i = 0; i < 10; i++){
		printf("random %d: %d\n", i, nums[i]);
	}

	printf("Writing numbers to file...\n");
	fd = open("nums.txt",O_RDWR | O_CREAT);
	printf("%d\n", fd);
	write(fd,nums,40);
	
	int n[10];
	printf("Reading numbers to file...\n");
	read(fd,n,40);

	printf("Verification that written values were the same:\n");
	for (int i = 0; i < 10; i++){
		printf("random %d: %d\n", i, n[i] );
	}

	close(fd);

	return 0;
}