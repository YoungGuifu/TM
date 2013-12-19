#include<cstring>
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
class CStaff
{
public:
	char Number[20],Name[20],Sex;
	int ServiceYears;
	double Salary;
	int SetNo(char a[])
	{
		strcpy(Name,a);
		return 1;
	}
	char* GetNo()
	{
		return Number;
	}
	int SetName(char a[])
	{
		strcpy(Name,a);
		return 1;
	}
	char* GetName()
	{
		return Name;
	}
	int SetSex(char c)
	{
		Sex=c;
		return 1;
	}
	char GetSex()
	{
		return Sex;
	}
	int SetServiceYears(int b)
	{
		ServiceYears=b;
		return 1;
	}
	int GetServiceYears()
	{
		return ServiceYears;
	}
	double GetSalary(){}

};



class CTempStaff:public CStaff
{
public:
	double GetSalary()
	{
		return Salary;
	}
};



class CAdministrator:public CStaff
{
public:
	char business[20];
	int i;
	double YearSalary,BusinessSalary;
	double GetSalary()
	{
		return YearSalary+BusinessSalary+Salary;
	}
};


class CTeacher:public CStaff
{
public:
	char Classification[20];
	int hour,master,phd;
	double HourSalary,MasterSalary,PhdSalary,YearSalary;
	double GetSalary()
	{
		return Salary+HourSalary*hour+MasterSalary*master+PhdSalary*phd+YearSalary;
	}
};

int main()
{
	struct Staff{
		char Category[20];
		char Number[20];
		char Name[20];
		char sex;
		int ServiceYears;
		double Salary;
		int hour;
		int master;
		int phd;
		char Business[20];
		char Classification[20];
	}staff[100];
	FILE *fp;
	int count=1;
	int choice;
	int i,j,flag;
	char a[20];
	CTempStaff tempstaff;
	CAdministrator administrator;
	CTeacher teacher;
	printf("Welcome to the system of managing staffs' wage!\nPress enter to continue!\n");
	getchar();
start: system("CLS");	
	flag=0;
	printf("Select what service you want!\n");
	printf("1.Add\n");
	printf("2.Modify\n");
	printf("3.Inquire\n");
	printf("4.Delete\n");
	printf("5.Write data on disk\n");
	printf("6.Exit\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("CLS");
		printf("Please select category!\n");
		printf("1.Temp staff\n");
		printf("2.Administrator\n");
		printf("3.Teacher\n");
		printf("4.Return\n");
		scanf("%d",&choice);
		if(choice==1)
		{			
step11:		system("CLS");
			printf("Temp staff\n");
			printf("Number:");
			scanf("%s",tempstaff.Number);
			getchar();
			for(i=1;i<count;i++)
			{
				if(strcmp(tempstaff.Number,staff[i].Number)==0)
				{
					printf("There is already a some number,please check it and input again!\n");
					getchar();
					goto step11;
				}
			}
			printf("Name:");
			scanf("%s",tempstaff.Name);
			getchar();
			printf("sex(f or m):");
			scanf("%c",&tempstaff.Sex);
			getchar();
			printf("Service years:");
			scanf("%d",&tempstaff.ServiceYears);
			printf("Fundamental salary:");
			scanf("%lf",&tempstaff.Salary);
			strcpy(staff[count].Category,"tempstaff");
			strcpy(staff[count].Name,tempstaff.GetName());
			strcpy(staff[count].Number,tempstaff.GetNo());
			staff[count].ServiceYears=tempstaff.GetServiceYears();
			staff[count].sex=tempstaff.GetSex();
			staff[count].Salary=tempstaff.GetSalary();
			count++;
		}
		if(choice==2)
		{
step12:		system("CLS");
			printf("Administrator\n");
			printf("Number:");
			scanf("%s",administrator.Number);
			getchar();
			for(i=1;i<count;i++)
			{
				if(strcmp(administrator.Number,staff[i].Number)==0)
				{
					printf("There is already a some number,please check it and input again!\n");
					getchar();
					goto step12;
				}
			}
			printf("Name:");
			scanf("%s",administrator.Name);
			getchar();
			printf("sex(f or m):");
			scanf("%c",&administrator.Sex);
			getchar();
			printf("Service years:");
			scanf("%d",&administrator.ServiceYears);
			printf("Fundamental salary:");
			scanf("%lf",&administrator.Salary);
			getchar();
			printf("Business:");
			scanf("%s",administrator.business);
			printf("BusinessSalary:");
			scanf("%lf",&administrator.BusinessSalary);
			printf("YearSalary:");
			scanf("%lf",&administrator.YearSalary);
			strcpy(staff[count].Category,"administrator");
			strcpy(staff[count].Business,administrator.business);
			strcpy(staff[count].Name,administrator.GetName());
			strcpy(staff[count].Number,administrator.GetNo());
			staff[count].ServiceYears=administrator.GetServiceYears();
			staff[count].sex=administrator.GetSex();
			staff[count].Salary=administrator.GetSalary();
			count++;
		}
		if(choice==3)
		{
step13:		system("CLS");
			printf("Administrator\n");
			printf("Number:");
			scanf("%s",teacher.Number);
			getchar();
			for(i=1;i<count;i++)
			{
				if(strcmp(teacher.Number,staff[i].Number)==0)
				{
					printf("There is already a some number,please check it and input again!\n");
					getchar();
					goto step13;
				}
			};
			printf("Name:");
			scanf("%s",teacher.Name);
			getchar();
			printf("sex(f or m):");
			scanf("%c",&teacher.Sex);
			getchar();
			printf("Service years:");
			scanf("%d",&teacher.ServiceYears);
			printf("Fundamental salary:");
			scanf("%lf",&teacher.Salary);
			getchar();
			printf("Classification:");
			scanf("%s",teacher.Classification);
			printf("Hour:");
			scanf("%lf",&teacher.hour);
			printf("Hour salary:");
			scanf("%lf",&teacher.HourSalary);
			printf("Master:");
			scanf("%d",&teacher.master);
			printf("Master salary:");
			scanf("%lf",&teacher.MasterSalary);
			printf("Phd:");
			scanf("%d",&teacher.phd);
			printf("Phd salary:");
			scanf("%lf",&teacher.PhdSalary);
			printf("YearSalary:");
			scanf("%lf",&teacher.YearSalary);
			strcpy(staff[count].Category,"teacher");
			strcpy(staff[count].Classification,teacher.Classification);
			strcpy(staff[count].Name,teacher.GetName());
			strcpy(staff[count].Number,teacher.GetNo());
			staff[count].ServiceYears=teacher.GetServiceYears();
			staff[count].sex=teacher.GetSex();
			staff[count].Salary=teacher.GetSalary();
			staff[count].hour=teacher.hour;
			staff[count].master=teacher.master;
			staff[count].phd=teacher.phd;
			count++;
		}
		if(choice==4)
		{
			system("CLS");
			goto start;
		}
		printf("OK!\n");
		printf("Press enter to continue!\n");
		getchar();
		getchar();
		system("CLS");
		goto start;
	}
	if(choice==2)
	{
		system("CLS");
		printf("If you don't want to motify anything,just input 'return'!\n");
step2:	printf("Please input the number:");
		scanf("%s",&a);
		getchar();
		if(strcmp(a,"return")==0)
			goto start;
		for(i=1;i<count;i++)
		{
			if(strcmp(a,staff[i].Number)==0)
				flag=1;
				break;																				
		}
		if(flag==0)
		{
			printf("The number is not exsiting,please check out and input again!\n");
			printf("Press enter to continue!\n");
			getchar();
			getchar();
			system("CLS");
			goto step2;
		}
step22:	system("CLS");
		i=1;
		printf("Please select the one you want to motify\n");
		printf("1.Number\n");
		printf("2.Name\n");
		printf("3,Sex\n");
		printf("4.Service years\n");
		printf("5.Fundamental salary\n");
		printf("6.Teaching hours\n");
		printf("7.The number of master\n");
		printf("8.The number of doctor\n");
		printf("9.The bussiness of administrator\n");
		printf("10.The classification of teacher\n");
		printf("11.Compelet motifying\n");
		scanf("%d",&choice);
		getchar();
		printf("If you find you select the wrong one,just input the old data!\n");
		if(choice==1)
		{
step23:		printf("Please input new number:");
			scanf("%s",staff[i].Number);
			for(j=1;j<count;j++)
			{
				if(strcmp(tempstaff.Number,staff[i].Number)==0&&j!=i)
				{
					printf("There is already a some number,please check it and input again!\n");
					getchar();
					system("CLS");
					goto step23;
				}
			}
			system("CLS");
			goto step22;
		}
		if(choice==2)
		{
			printf("Please input new name:");
			scanf("%s",staff[i].Name);
			system("CLS");
			goto step22;
		}
		if(choice==3)
		{
			printf("Please input new sex:");
			scanf("%c",&staff[i].sex);
			system("CLS");
			goto step22;
		}
		if(choice==4)
		{
			printf("Please input new service years:");
			scanf("%d",&staff[i].ServiceYears);
			system("CLS");
			goto step22;
		}
		if(choice==5)
		{
			printf("Please input new fundamental salary:");
			scanf("%lf",&staff[i].Salary);
			system("CLS");
			goto step22;
		}
		if(choice==6)
		{
			printf("Please input new teaching hours:");
			scanf("%d",&staff[i].hour);
			system("CLS");
			goto step22;
		}
		if(choice==7)
		{
			printf("Please input new number of master:");
			scanf("%d",&staff[i].master);
			system("CLS");
			goto step22;
		}
		if(choice==8)
		{
			printf("Please input new number of doctor:");
			scanf("%d",&staff[i].phd);
			system("CLS");
			goto step22;
		}
		if(choice==9)
		{
			printf("Please input new business:");
			scanf("%s",staff[i].Business);
			system("CLS");
			goto step22;
		}
		if(choice==10)
		{
			printf("Please input new category:");
			scanf("%s",staff[i].Category);
			system("CLS");
			goto step22;
		}
		if(choice==11)
		{
			system("CLS");
			goto start;
		}
	}
	if(choice==3)
	{
		getchar();
		system("CLS");
		printf("If you don't want to inquire anything,just input 'return'!\n");
step3:	printf("Please input the number you want to inquire:");
		scanf("%s",&a);
		if(strcmp(a,"return")==0)
			goto start;
		for(i=1;i<count;i++)
		{
			if(strcmp(a,staff[i].Number)==0)
			{	flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("The number is not exsiting,please check it and input again!\n");
			printf("Press enter to continue!\n");
			getchar();
			getchar();
			system("CLS");
			goto step3;
		}
		if(strcmp(staff[i].Category,"tempstaff")==0)
		{
			printf("Category:tempstaff\n");
			printf("Number:%s\n",staff[i].Number);
			printf("Name:%s\n",staff[i].Name);
			printf("Sex:");
			if(staff[i].sex=='f')
				printf("female\n");
			else
				printf("male\n");
			printf("Service years:%d years\n",staff[i].ServiceYears);
			printf("Salary:%lf\n",staff[i].Salary);
		}
		if(strcmp(staff[i].Category,"administrator")==0)
		{
			printf("Category:administrator\n");
			printf("Number:%s\n",staff[i].Number);
			printf("Name:%s\n",staff[i].Name);
			printf("Sex:");
			if(staff[i].sex=='f')
				printf("female\n");
			else
				printf("male\n");
			printf("Bussiness:%s\n",staff[i].Business);
			printf("Service years:%d years\n",staff[i].ServiceYears);
			printf("Salary:%lf\n",staff[i].Salary);
		}
		if(strcmp(staff[i].Category,"teacher")==0)
		{
			printf("Category:teacher\n");
			printf("Number:%s\n",staff[i].Number);
			printf("Name:%s\n",staff[i].Name);
			printf("Sex:");
			if(staff[i].sex=='f')
				printf("female\n");
			else
				printf("male\n");
			printf("Classification:%s\n",staff[i].Classification);
			printf("The number of masters:%d\n",staff[i].master);
			printf("The number of doctors:%d\n",staff[i].phd);
			printf("Service years:%d years\n",staff[i].ServiceYears);
			printf("Salary:%lf\n",staff[i].Salary);
		}
		printf("Press enter to continue!\n");
		getchar();
		getchar();
		goto start;
	}
	if(choice==4)
	{
		system("CLS");
		printf("If you don't want to delete anything,just input 'return'!\n");
step4:	printf("Please input the number you want to delete:");
		scanf("%s",&a);
		if(strcmp(a,"return")==0)
			goto start;
		for(i=1;i<count;i++)
		{
			if(strcmp(a,staff[i].Number)==0)
			{
				flag=1;
				break;	
			}
		}
		if(flag==0)
		{
			printf("The number is not exsiting,please check out and input again!\n");
			printf("Press enter to continue!\n");
			getchar();
			getchar();
			system("CLS");
			goto step4;
		}
		for(;i<count;i++)
			staff[i]=staff[i+1];
		count--;
		printf("Succeed!\nPress enter to return to the main menu!\n");
		getchar();
		getchar();
		goto start;
	}
	if(choice==5)
	{
		fp=fopen("C:\\Users\\Administrator\\Desktop\\data.txt","w");
		fprintf(fp,"The amount of the data is %d\n\n\n",count-1);
		for(i=1;i<count;i++)
		{
			if(strcmp(staff[i].Category,"tempstaff")==0)
			{
			fprintf(fp,"Category:tempstaff\n");
			fprintf(fp,"Number:%s\n",staff[i].Number);
			fprintf(fp,"Name:%s\n",staff[i].Name);
			fprintf(fp,"Sex:");
			if(staff[i].sex=='f')
				fprintf(fp,"female\n");
			else
				fprintf(fp,"male\n");
			fprintf(fp,"Service years:%d years\n",staff[i].ServiceYears);
			fprintf(fp,"Salary:%lf\n",staff[i].Salary);
			}
			if(strcmp(staff[i].Category,"administrator")==0)
			{
				fprintf(fp,"Category:administrator\n");
				fprintf(fp,"Number:%s\n",staff[i].Number);
				fprintf(fp,"Name:%s\n",staff[i].Name);
				fprintf(fp,"Sex:");
				if(staff[i].sex=='f')
					fprintf(fp,"female\n");
				else
					fprintf(fp,"male\n");
				fprintf(fp,"Bussiness:%s\n",staff[i].Business);
				fprintf(fp,"Service years:%d years\n",staff[i].ServiceYears);
				fprintf(fp,"Salary:%lf\n",staff[i].Salary);
			}
			if(strcmp(staff[i].Category,"teacher")==0)
			{
				fprintf(fp,"Category:teacher\n");
				fprintf(fp,"Number:%s\n",staff[i].Number);
				fprintf(fp,"Name:%s\n",staff[i].Name);
				fprintf(fp,"Sex:");
				if(staff[i].sex=='f')
					fprintf(fp,"female\n");
				else
					fprintf(fp,"male\n");
				fprintf(fp,"Classification:%s\n",staff[i].Classification);
				fprintf(fp,"The number of masters:%d\n",staff[i].master);
				fprintf(fp,"The number of doctors:%d\n",staff[i].phd);
				fprintf(fp,"Service years:%d years\n",staff[i].ServiceYears);
				fprintf(fp,"Salary:%lf\n",staff[i].Salary);
			}
			fprintf(fp,"\n\n\n");
		}
		printf("The txt file is on the desktop!\n");
		printf("Press enter to continue!\n");
		getchar();
		getchar();
		goto start;
	}
	if(choice==6)
		return 0;
	getchar();
	return 0;
}