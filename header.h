#include<linux/init.h>
#include<linux/module.h>
#include<linux/uaccess.h>
#include<asm/uaccess.h>
#include<linux/fs.h>
#include<linux/kernel.h>
#include<linux/cdev.h>
#include<linux/semaphore.h>
#include<linux/slab.h>
#include<linux/moduleparam.h>