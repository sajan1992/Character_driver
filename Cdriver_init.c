#include"header.h"
#include"declaration.h"
#include"fileOpr.h"
int majorno,minorno; 		//Device MAJOR_NO and MINOR_NO
Device * device;		//Device struct
dev_t devid;			//dev_t to store minor and major no
int nod;			//Number of device
int ret;
int devno;
int loop;
int devSize,regSize,noofreg,dataSize;
module_param(nod,int,0644);
static int __init cdriver_start(void)	//This is the entry point 	
{	
	//nod = NOD;
	majorno = MAJORNO;						
	minorno = MINORNO;
	/*---------------------- Memory mapping ---------------------------------- */
	devSize  = DEVSIZE;
	regSize  = REGSIZE;
	dataSize = DATASIZE;
	noofreg  = NOOFREG;
	/*-------------------- Memory Mapping Ends -------------------------------*/
	    ret = alloc_chrdev_region(&devid,minorno,nod,DEVNAME);//register device to the device table using alloc_chrdev_region(dev_t*,unsigned,unsigned,numberOfdevice,Device_name);
	if(ret == -1)
	{
		printk(KERN_ERR "Device Couldn't be allocate!");
		goto end;
	}
	/* Fetching Majorno and Minorno*/
	majorno = MAJOR(devid);
	minorno = MINOR(devid);
	/* Printing the minor and major no and device status */
	printk(KERN_INFO "%s : Device driver registered successfully!\n",__FUNCTION__);
	printk(KERN_INFO "%s : MAJOR_NUMBER : %d\n",__FUNCTION__,majorno);
	//printk(KERN_INFO "%s : MINOR_NUMBER : %d\n",__FUNCTION__,minorno);
	
	device = (Device*) kmalloc(sizeof(Device)*nod,GFP_KERNEL);	//using kmalloc allocating memory to the struct device;
	if(!device)
	{
		
		printk(KERN_ERR "Memory couldn't be allocated!\n");
		goto end;
	}
	
	memset(device,'\0',sizeof(Device)*nod);		        //reseting memory to null
	/* Initialising the device structure */
	for(loop = 0;loop<nod;loop++)
	{
		cdev_init(&device[loop].c_dev,&fops);
		/* Initialising the file_operations*/
		device[loop].c_dev.ops=&fops;
		/*------------------------------------------ Memory Mapping ------------------------------------------------*/
		device[loop].data_size = dataSize;
		device[loop].reg_size = regSize;
		device[loop].dev_size = devSize;
		device[loop].noofreg = noofreg;
		device[loop].offset = OFFSET;
		/*-----------------------------------------------------------------------------------------------------------*/
		devno = MKDEV(majorno,loop);	/* using MKDEV call creating the dev_t */
		ret=cdev_add(&device[loop].c_dev,devno,nod); /* Adding the chardev struct(cdev) into the device table as per the given dev_t(devno) and nod*/
		if(ret == -1)
		{
			printk(KERN_ERR "cdev error\n");
			goto end;
		}
		printk(KERN_INFO "%s : MINOR_NUMBER : %d\n",__FUNCTION__,MINOR(device[loop].c_dev.dev));
	}
	printk(KERN_INFO "%s : Memory allocated successfully!\n",__FUNCTION__);
	return 0;
end:	
	return -1;
}
 module_init(cdriver_start);
