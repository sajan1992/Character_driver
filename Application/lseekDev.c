#include"header.h"
#include"declaration.h"

int lseekDev(int fd)
{
	int val,offset,ret;
	printf("Enter the Whence :\n1.SEEK_SET\n2.SEEK_CUR\n3.SEEK_END\n");
	scanf(" %d",&val);
	printf("Enter the offset :\n");
	scanf(" %d",&offset);
	ret = lseek(fd,offset,val);
	if(ret == -1)
	{
		printf("offset greater the data_size!\n");
		return -1;
	}
	printf("offset = %d\n",ret);
	return 0;
}
