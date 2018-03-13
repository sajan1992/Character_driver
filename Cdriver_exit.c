#include"header.h"
#include"declaration.h"
static void cdriver_end(void)
{
	int i;
	printk(KERN_INFO "%s : Bye Kernel!\n",__FUNCTION__);
	for(i=0;i<nod;i++)
	{
		cdev_del(&device[i].c_dev);
	}
	kfree(device); //freeing memory allocated memory.
	unregister_chrdev_region(devid,nod); //this function unregister_chrdev_region(dev_t*,unsigned) is used to register device in device table.
}

module_exit(cdriver_end);
