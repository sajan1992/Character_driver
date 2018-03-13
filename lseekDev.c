#include"header.h"
#include"declaration.h"

loff_t lseekDev (struct file * pfile, loff_t offset, int whence) 
{
	Device * ldev;
	printk(KERN_INFO "%s : Begins",__FUNCTION__);
	ldev = (Device *) pfile->private_data;
	if(whence == 1)
	{
		if(offset <= ldev->data_size)
			pfile->f_pos = offset;
		else
			goto err;
	}
	else if(whence == 2)
	{
		if((pfile->f_pos)+offset > ldev->data_size)
			goto err;
		else
			pfile->f_pos += offset;
	}
	else if(whence == 3)
	{
		if(offset <= ldev->data_size)
			pfile->f_pos = (ldev->data_size) - offset;
		else
			goto err;
	}
/*
	int lsize,noctr,nocsr,ret,i;
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
	
	noctr = lsize;
	i = nocsr = 0;
	first = ldev->first;
	while(noctr)
	{
		if(noctr > ldev->reg_size)
			noctr = ldev->reg_size;

		ret = copy_to_user(ubuff+nocsr,first->data[i],noctr);

		nocsr += noctr - ret;
		noctr = lsize - nocsr;
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
	printk(KERN_INFO "read %d character",nocsr);
	printk(KERN_INFO "%s: Ends",__FUNCTION__);
	#endif
	return nocsr;*/
	return (pfile->f_pos);
	printk(KERN_INFO "%s : Ends",__FUNCTION__);
err:	
	return -1;
}

