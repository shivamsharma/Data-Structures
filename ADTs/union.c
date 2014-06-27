#include <stdio.h>
struct addr
{
	char street[50];
	char city[10];
	char state[30];
	char zip[6];
};
struct date
{
	int day;
	int month;
	int year;
};
struct policy
{
	int policyNo;
	char name[30];
	struct addr address;
	int amount;
	float premium;
	int kind;
	union{
		struct {
			char beneficiary[100];
			struct date dob;
		}Life;
		struct {
			char licenseNo[20];
			char state[30];
			char model[10];
			int deduct;		//Regular deduct of money 
			int year;
		}Auto;
		struct {
			int deduct;		//Regular deduct of money 
			int year;		//Year built of house
		}Home;
	}Policyselect;
};
			
int main()
{
	struct policy p;
	printf("			WELCOME TO THE XAKA'S INSURANCE COMPANY\n");
	printf("Enter the name:");
	gets(p.name);
	printf("\nEnter the Address in the following format.");
	printf("\nEnter the Street Name and no.:");
	gets(p.address.street);
	printf("\nEnter the City's Name:");
	gets(p.address.city);
	printf("\nEnter the State:");
	gets(p.address.state);
	printf("\nEnter the Area Zip Code:");
	gets(p.address.zip);
	printf("\n----------------------------\n");
	printf("Enter the Amount you want to insure in Rs :");
	scanf("%d",&p.amount);
	p.premium=(.01)*p.amount;
	p.policyNo=rand();
	printf("\nEnter 1 for Life,2 for Auto,3 for Home:");
	scanf("%d",&p.kind);
	if(p.kind==1)
	{
		printf("\n			WELCOME TO XAKA'S LIFE INSURANCE SECTION");
		printf("\nEnter the Birth date");
		printf("\nEnter the day:");
		scanf("%d",&p.Policyselect.Life.dob.day);
		printf("\nEnter the month:");
		scanf("%d",&p.Policyselect.Life.dob.month);
		printf("\nEnter the year:");
		scanf("%d",&p.Policyselect.Life.dob.year);
		//p.Policyselect.Life.beneficiary={"You are offered with Policy no. 2 for one month free"};
	}
	else if(p.kind==2)
	{
		printf("\n			WELCOME TO XAKA'S AUTO INSURANCE SECTION");
		printf("\nAuto deduct is Rs 150 per year.");
		p.Policyselect.Auto.deduct=150;
		printf("\nEnter the Lincense no. of your Vehicle:");
		fflush(stdin);
		gets(p.Policyselect.Auto.licenseNo);
		printf("\nEnter the State where from this Vehicle belongs:");
		gets(p.Policyselect.Auto.state);
		printf("\nEnter the Model No. of your Vehicle:");
		gets(p.Policyselect.Auto.model);
		printf("\nEnter the year of buy of Vehicle:");
		scanf("%d",p.Policyselect.Auto.year);
	}
	else if(p.kind==3)
	{
		printf("\n			WELCOME TO XAKA'S HOME INSURANCE SECTION");
		printf("\nLife deduct is Rs 120 per year");
		p.Policyselect.Home.deduct=120;
		printf("\nEnter the Year of built of house:");
		scanf("%d",&p.Policyselect.Home.year);
	}
	printf("\n~~~~~~YOUR DETAILS~~~~~~");
	printf("\nName :%s",p.name);
	printf("\nPolicy No. :%d",p.policyNo);
	printf("\nAddress :%s ,%s ,%s-%s",p.address.street,p.address.state,p.address.city,p.address.zip);
	printf("\nAmount of Insurance :Rs %d",p.amount);
	printf("\nPremium of Insurance :Rs %f",p.premium);
	printf("\nYou have been opted for ");
	if(p.kind==1)
	{
		printf("Life");
		printf("\nBeneficiary :%s",p.Policyselect.Life.beneficiary);
		printf("\nDate of Birth:%d-%d-%d",p.Policyselect.Life.dob.day,p.Policyselect.Life.dob.month,p.Policyselect.Life.dob.year);
	}
	else if(p.kind==2)
	{
		printf("Auto");
		printf("\nDeduct for Auto Insurance :Rs %d",p.Policyselect.Auto.deduct);
		printf("\nLicense No. of Vehicle :%s",p.Policyselect.Auto.licenseNo);
		printf("\nState from which your Vehicle belongs to is \"%s\"",p.Policyselect.Auto.state);
		printf("\nModel of Vehicle :%s",p.Policyselect.Auto.model);
		printf("\nYear of buy of Vehicle :%d",p.Policyselect.Auto.year);
	}
	else if(p.kind==3)
	{
		printf("Home");
		printf("\nDeduct for Home Insurance :Rs %d",p.Policyselect.Home.deduct);
		printf("\nYear of built of House :%d",p.Policyselect.Home.year);
	}
	return 0;
}
