#include"header.h"
#include"declaration.h"

int main(void)
{
	int choice;
	int fd;
	while(1)
	{
		choice = getChoice();
		switch(choice)
		{
			case 1:
				fd = openDev();
				break;
			case 2:
				close(fd);
				printf("Device released successfully!\n");
				break;
			case 3:
				readDev(fd);
				break;
			case 4:
				writeDev(fd);
				break;	
			case 5:
				lseekDev(fd);
				break;	
			case 0:
				exit(EXIT_SUCCESS);
			default:
				printf("Invalid Choice");


		}

	}
}
