#include"header.h"
#include"declaration.h"

int readDev(int fd)
{
	int ret;
	char output[100];
	ret = read(fd,output,100);
	if(ret == -1)
	{
		perror("Read");
		exit(-1);
	}
	output[ret] = '\0';
	printf("App : read %d byte\n",ret);
	printf("App : %s\n",output);
	return 0;
}
