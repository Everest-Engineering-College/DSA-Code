#include<iostream>
#include<conio.h>
#include<string.h>
#include "Source.h"
using namespace std;
#define ar 5 //defining size of array
struct stdinfo
{
	string div[ar];//for the report generation division
	string name[ar];
	int crn[ar];
	float programming[ar], maths[ar], physics[ar];
}stdu;
void count_fail();
void calculate_division();
void report_generation();
void c_division();
int main()
{
	settheinfo();//setting the value 
	count_fail();//for counting the fail and pass students
    calculate_division();//calculate division
	report_generation();//showing report
	c_division();//for checking division
	
}

void settheinfo()
{
	string n[ar] = { "Hari Kunwar","Manitha Thapa","Puskar Shah","Usha Karki","Bikash Rajat" };
	float prog[ar] = { 45,52,78,48,92 };
	float math[ar] = { 60,15,85,45,95 };
	float phy[ar] = { 36,65,79,45,88 };
	for (int i = 0; i < ar; i++)
	{
		stdu.name[i] = n[i];
		stdu.crn[i] = 301 + i;
		stdu.maths[i] = math[i];
		stdu.physics[i] = phy[i];
		stdu.programming[i] = prog[i];

	}
	/*cout << "first name" << stdu.name[0];
	cout << "manita thapa prog" << stdu.programming[1];
	cout << "he";*/
}
void count_fail()
{
	int count = 0;
	bool j = true;
	int pass = 45;
	bool mf;
	bool pf;
	bool phyf;
	for (int i = 0; i < ar; i++)
	{
		/*if (pf = (stdu.programming[i] < pass) || mf = (stdu.maths[i] < pass) || phyf = (stdu.physics[i] < pass))
		{
			cout << stdu.name[i] << "is failed in subject Programming" << endl;
		}*/
		if (stdu.programming[i] < pass)
		{
			cout << stdu.name[i] << " is failed in subject Programming"<<endl;
			//cout <<"bool"<< j << endl;
			if (j == true)
			{
              count++;
			  j = false;
			}
	    }
		if (stdu.maths[i] < pass)
		{
			cout << stdu.name[i] << " is failed in subject Maths" << endl;
			//cout << "bool" << j << endl;
			if (j == true)
			{
				count++;
				j = false;
			}
		}
		if (stdu.physics[i] < pass)
		{
			cout << stdu.name[i] << " is failed in subject Programming" << endl;
			//cout << "bool" << j << endl;
			if (j == true)
			{
				count++;
				j = false;
			}
		}
	    if (stdu.physics[i]>=pass&&stdu.maths[i]>=pass&&stdu.programming[i]>=pass)
		{
            cout << stdu.name[i]<<" is passed in all subjects" << endl;
		}
		j = true;
    } 
	cout << "Total number of students failed in all subjects is " << count<<endl<<endl;
	
}
void calculate_division()
{
	bool booldiv = true;
	float percent[ar];
	int total[ar];


	for (int i = 0; i < ar; i++)
	{
		total[i] = stdu.maths[i] + stdu.physics[i] + stdu.programming[i];
		percent[i] = (total[i] * 100) / 300;

	}
	for (int i =0 ; i < ar; i++)
	{
		
		if (percent[i] < 45 ||(stdu.maths[i]<45||stdu.physics[i]<45||stdu.programming[i]<45))/*kunai ko 45 banda 
																							 tala aako xa 
																							 baney fail hunxa*/
		{
			
			stdu.div[i] = "Fail";
		}
		else if (percent[i] >= 45 && percent[i] < 50)
		{
			
			stdu.div[i] = "Pass";
		}
		else if (percent[i] >= 50 && percent[i] < 75)
		{
			
			stdu.div[i] = "Second Division";
		}
		else if (percent[i] >= 75 && percent[i] < 90)
		{
			
			stdu.div[i] = "First Division";
		}
		else
		{
			
			stdu.div[i] = "Distinction";
		}
    }
	
}
void report_generation()
{
	cout << "CRN\t" << "Name\t\t" << "Division\t\t" << endl;
	for (int i = 0; i < ar; i++)
	{
		cout << 301 + i <<"\t" << stdu.name[i] <<" \t"<< stdu.div[i] << endl;
	}
}
void c_division()
{
	int crncode;
	cout << "Please Enter Your CRN number: ";
	while (!(cin >> crncode) || (crncode < 301 || crncode > 305))
	{
		// Explain Error
		cout << "RE-ENter: You must enter a number between 300 and 306: ";
		// Clear input stream
		cin.clear();
		// Discard previous input
		cin.ignore(132, '\n');
	}
	int i = crncode - 301;
	cout << stdu.name[i] << " = " << stdu.div[i] << endl;
}
