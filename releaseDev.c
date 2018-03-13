#include"header.h"
#include"declaration.h"
int  releaseDev(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "%s : File released Successfully.\n",__FUNCTION__);
	return 0;
}

