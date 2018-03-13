#include"header.h"
#include"declaration.h"

Qset * allocDev(int size)
{
	int noi,noq,i,p=0;
	Qset * first = NULL;
	Qset * last = NULL;
	#ifdef DEBUG
	printk(KERN_INFO "%s: Begins\n", __FUNCTION__);
	#endif
	noq = size/regSize;
	if(noq%(regSize))
	{
		noq++;
	}
	noi = size/(noofreg*regSize);
	if(size%(noofreg*regSize))
	{
		noi++;
	}
	for(i=0;i<noi;i++)
	{
		if(i == 0)
		{
			last = first = (Qset*)kmalloc(sizeof(Qset),GFP_KERNEL);
			memset(last,'\0',sizeof(Qset));
		}
		else
		{
			last->next = (Qset*)kmalloc(sizeof(Qset),GFP_KERNEL);
			memset(last->next,'\0',sizeof(Qset));
			last = last->next;
		}
	}
	last->next = NULL;
	last = first;
	for(i=0;i<noi;i++)
	{
		last->data = kmalloc(sizeof(char*)*8,GFP_KERNEL);
		memset(last->data,'\0',sizeof(char*)*8);
		last = last->next;
	}
	last = first;
	for(i=0;i<noq;i++)
	{
		last->data[p] = kmalloc(sizeof(char)*regSize,GFP_KERNEL);
		memset(last->data[p],'\0',sizeof(char)*regSize);
		if(p == (noofreg-1))
		{
			last = last->next;
			p = 0;
		}
		else
			p++;
	}
return first;
}
