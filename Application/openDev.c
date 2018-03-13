#include"header.h"
#include"declaration.h"

int openDev(void)
{
	int fd,ch;
	printf("Enter the mode:\n3.Read Mode\n4.Write Mode\n");
	scanf("%d",&ch);
	if(ch == 3)
		fd = open("/home/rajan/sk/project/Kdriver/character_driver/char_drv/MyDev",O_RDONLY);
	if(ch == 4)
		fd = open("/home/rajan/sk/project/Kdriver/character_driver/char_drv/MyDev",O_WRONLY);
	if(fd == -1)
	{
		printf("Unable to open\n");
		exit(EXIT_FAILURE);
	}

	printf("Success : fd = %d\n",fd);
	return fd;
}
