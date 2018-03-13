#include"header.h"
#include"declaration.h"

int trimDev(Device * ldev)
{
	#ifdef DEBUG
	printk(KERN_INFO "%s: Begins\n",__FUNCTION__);
	#endif
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR "Device not found!\n");
		#endif
		goto OUT;
	}
	if(!ldev->first)
	{
		#ifdef DEBUG
		printk(KERN_ERR "Nothing to trim!\n");
		#endif
		goto RET;
	}
RET :
	#ifdef DEBUG
	printk(KERN_INFO "%s: Ends\n",__FUNCTION__);
	#endif
	return 0;
OUT :
	return -1;
}
