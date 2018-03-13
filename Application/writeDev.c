#include"header.h"
#include"declaration.h"

int writeDev(int fd)
{
	int ret;
	char input[100] = "Hello world! This is my program!";
	ret = write(fd,input,strlen(input));
	if(ret == -1)
	{
		perror("Write");
		exit(-1);
	}
	printf("App : Wrote %d byte\n",ret);
	return 0;
}
