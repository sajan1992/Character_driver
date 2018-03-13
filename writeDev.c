#include"header.h"
#include"declaration.h"

ssize_t writeDev (struct file *pfile, const char __user *ubuff, size_t size, loff_t * offset)
{
	int lsize,noctw,nocsw,ret,i;
	Device * ldev;
	Qset * first;
	#ifdef DEBUG
	printk(KERN_INFO "%s:Begins",__FUNCTION__);
	#endif
	ldev = (Device *) pfile->private_data;
	if(size > ldev->dev_size)
	{
		lsize = ldev->dev_size;
		#ifdef DEBUG
		printk(KERN_INFO "Oversize,Partial writing will be performed\n");
		#endif
	}
	else
		lsize = size;
	
	noctw = lsize;
	i = nocsw = 0;
	first = ldev->first = allocDev(lsize);
	while(noctw)
	{
		if(noctw > ldev->reg_size)
			noctw = ldev->reg_size;

		ret = copy_from_user(first->data[i],ubuff+nocsw,noctw);
		
		*(offset) += noctw - ret;
		nocsw += noctw - ret;
		noctw = lsize - nocsw;
		if(i == (noofreg - 1))
		{
			if(first->next == NULL)
				break;
			else 
			{
				i = 0;
				first = first->next;
			}
		}
		else
			i++;
	}
	
	#ifdef DEBUG
	printk(KERN_INFO "wrote %ld character",(long int)*(offset));
	printk(KERN_INFO "%s: Ends",__FUNCTION__);
	#endif
	ldev->data_size = nocsw;
	return nocsw;
}

