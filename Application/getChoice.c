#include"header.h"
#include"declaration.h"

int getChoice(void)
{
	int choice;
	printf("---------------------- DEVICE DRIVER MENU --------------------------\n");
	printf("1.Open_Device\n2.Release_Device\n3.Read_Device\n4.Write_Device\n5.Lseek_Device\n0.Exit\n");
	printf("---------------------- DEVICE DRIVER MENU --------------------------\n");
	printf("Enter your choice!\n");
	scanf("%d",&choice);
	return choice;
}
