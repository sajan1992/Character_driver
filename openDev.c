#include"header.h"
#include"declaration.h"
int  openDev(struct inode *inodep, struct file *filep)
{
	Device *ldev;
	int ret;
	#ifdef DEBUG
	printk(KERN_INFO "%s : Begins\n",__FUNCTION__);
	#endif
	ldev = container_of(inodep->i_cdev,Device,c_dev);
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR "ldev failed");
		#endif
	}
	if((filep->f_flags & O_ACCMODE) == O_WRONLY)
	{
		ret = trimDev(ldev);
		if(ret == -1)
		{
			#ifdef DEBUG
			printk(KERN_ERR "trimDev failed");
			#endif
		}
	}
	filep->private_data = ldev;
	#ifdef DEBUG
	printk(KERN_INFO "%s : Ends\n",__FUNCTION__);
	#endif
	return 0;
}

