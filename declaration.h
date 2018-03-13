#ifndef DEBUG
#define DEBUG
#endif

#ifndef OFFSET
#define OFFSET 0
#endif
#ifndef MAJORNO
#define MAJORNO 0
#endif
#ifndef MINORNO
#define MINORNO 0
#endif
#ifndef NOD
#define NOD 1
#endif
#ifndef NOOFREG
#define NOOFREG 8
#endif
#ifndef REGSIZE
#define REGSIZE 4
#endif
#ifndef DEVSIZE
#define DEVSIZE 256
#endif
#ifndef DATASIZE
#define DATASIZE 0
#endif
#ifndef DEVNAME
#define DEVNAME "CHARACTER_DRIVER"
#endif

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mr.SAJAN KUMAR JHA");
MODULE_DESCRIPTION("CHARACTER DRIVER");

typedef struct Qset 
{
	struct Qset * next;
	void **data;
}Qset;

typedef struct Device
{
	struct cdev c_dev;
	struct Qset *first;
	int dev_size;
	int reg_size;
	int data_size;
	int noofreg;
	loff_t offset;
}Device;

extern int majorno,minorno,devno,nod,devSize,regSize,dataSize,noofreg;
extern Device *device; 
extern dev_t devid;

int openDev(struct inode *, struct file *);
int releaseDev(struct inode *, struct file *);
int trimDev(Device *);
ssize_t writeDev(struct file *, const char __user *, size_t, loff_t *);
ssize_t readDev(struct file *, char __user *, size_t, loff_t *);
Qset * allocDev(int);
loff_t lseekDev (struct file *, loff_t, int);
