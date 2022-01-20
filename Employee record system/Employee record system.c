#include<stdio.h>
#include<stdlib.h>// system("cls");
struct Emp
{
	char Name[20];
	long int Salary;
	int Id;
	int Flag;
}Employee;
FILE *fp,*fp2;//fp2 helps in deleting record
void main()
{
	int Choice;
	int SId,rf=1;
	long int offset;//helps in deleting
	while(1)
	{
		system("cls");
		printf("----- Employee Record System in C -----\n\n");
		//=============================
		printf(" 1. Add\n");
		printf(" 2. Delete\n");
		printf(" 3. Display\n");
		printf(" 4. Exit\n\n");
		//=============================
		printf("Enter your choice(eg- 1,2,3): ");
		scanf("%d",&Choice);
		//=============================
		if(Choice==1)
		{
			system("cls");
			printf("--- Add ---\n\n");
			printf("Enter the name: ");
			scanf("%s",Employee.Name);
			printf("Enter the Id: ");
			scanf("%d",&Employee.Id);
			printf("Enter the Salary: ");
			scanf("%ld",&Employee.Salary);
			Employee.Flag=0;
			fp=fopen("employeerecsys.txt","a");
			fwrite(&Employee,sizeof(Employee),1,fp);
			fclose(fp);
			printf("\n\nRecord Added Successfully...\n");
			system("pause");
		}
		if(Choice==2)
		{
			system("cls");
			printf("--- Delete ---\n\n");
			printf("Enter the Id which you want to delete: ");
			scanf("%d",&SId);
			fp=fopen("employeerecsys.txt","r+");
			while(fread(&Employee,sizeof(Employee),1,fp))
			{
				if(SId==Employee.Id)
				{
					rf=0;
					Employee.Flag=1;
					offset=sizeof(Employee);
					fseek(fp,-offset,SEEK_CUR);
					fwrite(&Employee,sizeof(Employee),1,fp);
					printf("Deleated!\n\n");
					fclose(fp);
					system("pause");
					break;
				}
			}
			if(rf==1)
			{
				printf("ID not Found!!!\n");
				system("pause");
				fclose(fp);
			}
			if(rf==0)
			{
				//==============================
			fp=fopen("employeerecsys.txt","r");
			
			while(fread(&Employee,sizeof(Employee),1,fp))
			{
				if(Employee.Flag==0)
				{	
				fp2=fopen("nf.txt","a");
					fwrite(&Employee,sizeof(Employee),1,fp2);
					fclose(fp2);
				}
			}
			fclose(fp);
			fclose(fp2);
			if(remove("employeerecsys.txt")==0)
			{
				printf("d\n");
			}
			if(rename("nf.txt","employeerecsys.txt")==0)
			{
				printf("r\n");
			}
			//system("pause");
			}
		}
		if(Choice==3)
		{
			system("cls");
			printf("--- Display ---\n\n");
			fp=fopen("employeerecsys.txt","r");
			while(fread(&Employee,sizeof(Employee),1,fp))
			{
				printf("Name: %s \n",Employee.Name);
				printf("Id: %d\n",Employee.Id);
				printf("Salary: %ld\n",Employee.Salary);
				//printf("Flag: %d\n",Employee.Flag);
				printf("\n=============================\n\n");
			}
			fclose(fp);
			system("pause");
		}
		if(Choice==4)
		{
			exit(0);
		}
	}
}
