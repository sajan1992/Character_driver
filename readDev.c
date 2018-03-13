#include"header.h"
#include"declaration.h"
ssize_t readDev (struct file *pfile, char __user *ubuff, size_t size, loff_t * offset)
{
	int lsize,noctr,nocsr,ret,i,limit,j;
	Device * ldev;
	Qset * first;
	limit = (int)(*offset);

	#ifdef DEBUG
	printk(KERN_INFO "%s:Begins",__FUNCTION__);
	#endif
	ldev = (Device *) pfile->private_data;
	if(size > ldev->data_size)
	{
		lsize = ldev->data_size;
		#ifdef DEBUG
		printk(KERN_INFO "Oversize,Partial writing will be performed\n");
		#endif
	}
	else
		lsize = size;
	
	noctr = lsize;
	j = i = nocsr = 0;
	first = ldev->first;
	noctr = noctr - limit;
	while(noctr)
	{
		/*if(noctr > ldev->reg_size)
			noctr = ldev->reg_size;*/
		if(limit == 0)
		{
			ret = copy_to_user(ubuff+nocsr,(first->data[i])+j,1);
			nocsr += 1 - ret;
			noctr = lsize - nocsr;
			//noctr = lsize - nocsr;
			if(i == (noofreg - 1) && (j+1)%4 == 0)
			{
				if(first->next == NULL)
					break;
				else 
				{
					i = 0;
					j = 0;
					first = first->next;
				}
			}
			else if((j+1)%4 ==0)
			{
				i++;
				j = 0;
			}
			else
				j++;
		}
		else
		{
			if(limit >= ldev->reg_size)
			{
				limit = limit - (ldev->reg_size);
				i++;

			}
			else
			{
				j++;
				limit--;
			}

		}
	}
	
	#ifdef DEBUG
	printk(KERN_INFO "read %d character -> %ld",nocsr,(long int)(*offset));
	printk(KERN_INFO "%s: Ends",__FUNCTION__);
	#endif
	return nocsr;
}

