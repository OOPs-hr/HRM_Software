#include<iostream>
#include<fstream>
#include <ctime>
using namespace std;

class emp_info
{
	public:
		char name[50],dep[40];
		char status[10];
		int id_no;
		void getInfo();
		void dateTime();
};

class payroll: public emp_info
{
	private:
		float basic,other_all,con_all,hr_all;
		float increment,income_tax,profess_tax;
		float gross_salary,take_salary,medi_insur,epf;
	public:
		int TaxCalc();//
		int prof_tax(); //
		int EpfCalc();//
		int GrossSalary();//
		int TakeHomeSalary();//
		void getData();//
		void create();//
		void readDet();//
		void display();
		void addNew();//
		void modifyRec(int);//
		void deleteRec(int);//
		void search(int);//
};

void emp_info::dateTime()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	cout<<"\n\tDATE/TIME           : "<<dt;
}

void emp_info::getInfo()
{
			
	cout<<"\n\nENTER ID NUMBER      : ";
	cin>>id_no;
	fflush(stdin);
	cout<<"\n\nENTER EMPLOYEE NAME    : ";
	cin.getline(name,50);
	cout<<"\n\nENTER DEPARTMENT       : ";
	cin.getline(dep,40);
	cout<<"\n\nENTER STATUS           : ";
	cin>>status;
}

void payroll::getData()
{
	fflush(stdin);
	cout<<"\n\nENTER THE BASIC SALARY    : ";
	cin>>basic;
	cout<<"\n\nENTER H.R. ALLOWANCE      : ";
    cin>>hr_all;
    cout<<"\n\nENTER CONVEYANCE ALLOWANCE: ";
    cin>>con_all;
    cout<<"\n\nENTER SPECIAL ALLOWANCES  : ";
	cin>>other_all;
	cout<<"\n\nENTER AMT. OF INCREMENT   : ";
	cin>>increment;
	cout<<"\n\nENTER MEDICAL INSURANCE   : ";
	cin>>medi_insur;
}

int payroll::TaxCalc()
{
  if(gross_salary >= 50000 && gross_salary <100000)
  {
      income_tax = (0.05)*gross_salary;
  }
  else if(gross_salary >= 100000 && gross_salary < 150000)
  {
     income_tax = (0.1)*gross_salary;	
  }
  else if(gross_salary >= 150000 && gross_salary < 200000)
  {
     income_tax = (0.15)*gross_salary;	
  }
  else if(gross_salary >= 200000 && gross_salary < 250000)
  {
     income_tax = (0.2)*gross_salary;	
  }
  else if(gross_salary >= 250000 && gross_salary < 300000)
  {
     income_tax = (0.25)*gross_salary;	
  }
  else if(gross_salary >= 300000 )
  {
     income_tax = (0.3)*gross_salary;	
  }
  else if(gross_salary <50000)
  {
  	income_tax = 0;
  }
  else
  {
  	printf("INVALID AMOUNT");
  }
  return income_tax;  
}


int payroll::GrossSalary()
{
	gross_salary = basic +  hr_all + other_all + con_all + increment - medi_insur ;
	return gross_salary;
}

int payroll::TakeHomeSalary()
{
	take_salary = gross_salary - income_tax - profess_tax - epf;
	return take_salary;
}

int payroll::prof_tax()
{
  if(gross_salary >= 20000 && gross_salary <50000)
  {
      profess_tax = 300;
  }
  else if(gross_salary >= 50000 && gross_salary < 75000)
  {
     profess_tax = 500;	
  }
  else if(gross_salary >= 75000 && gross_salary < 125000)
  {
     profess_tax = 750;	
  }
  else if(gross_salary >= 125000 && gross_salary < 200000)
  {
     profess_tax = 1000;	
  }
  else if(gross_salary >= 200000 )
  {
     profess_tax = 1250;	
  }
  else if(gross_salary <20000)
  {
  	profess_tax = 0;
  }
  else
  {
  	printf("INVALID AMOUNT");
  }
  return profess_tax;  
}

int payroll::EpfCalc()
{
	epf = (0.1)*gross_salary;
	return epf;
}

void payroll::display()
{
	 payroll p;
	 getchar();
	 system("cls");
	 cout<<"\n\n-----------------------------------------------------------------------------------";
	 cout<<"\n\n\t\t\tPAYROLL OF EMPLOYEE "<<name;
	 cout<<"\n\n-----------------------------------------------------------------------------------";
	 cout<<"\n\n\tID                  : "<<id_no;
	 cout<<"\n\tNAME                : "<<name;
	 cout<<"\n\tDEPARTMENT          : "<<dep;
	 cout<<"\n\tSTATUS              : "<<status;
	 p.dateTime();
	 cout<<"\n\n-----------------------------------------------------------------------------------";
	 cout<<"\n************************************************************************************";
	 cout<<"\n\t\tEARNINGS";
	 cout<<"\n************************************************************************************";
	 cout<<"\n\n\tBASIC SALARY        : "<<basic;
	 cout<<"\n\tH.R ALLOWANCE       : "<<hr_all;
	 cout<<"\n\tCONVEYANCE ALLOWANCE: "<<con_all;
	 cout<<"\n\tSPECIAL ALLOWANCE   : "<<other_all;
	 cout<<"\n\tINCREMENT           : "<<increment;
	 cout<<"\n************************************************************************************";
	 cout<<"\n\t\tDEDUCTIONS";
	cout<<"\n************************************************************************************";
	 cout<<"\n\n\tE.PROVIDENT FUND    : "<<epf;
	 cout<<"\n\tMEDICAL INSURANCE   : "<<medi_insur;
	 cout<<"\n\tINCOME TAX          : "<<income_tax;
	 cout<<"\n\tPROFESSIONAL TAX    : "<<profess_tax;
	 cout<<"\n************************************************************************************";
	 cout<<"\n************************************************************************************";
	 cout<<"\n\n\tTAKE HOME SALARY    : "<<take_salary;
	 cout<<"\n************************************************************************************";
	 
	 
}

void payroll::create()
{
    int ch;
	payroll p;
	ofstream cpay;
	cpay.open("payroll.dat",ios::binary);
	if(!cpay)
	{
	  cout<<"ERROR:FILE NOT YET OPENED";	
	}	
	do
	{
		getchar();
		system("cls");
		p.getInfo();
		p.getData();
		p.GrossSalary();
		p.TaxCalc();
		p.prof_tax();
		p.EpfCalc();
		p.TakeHomeSalary();
		cpay.write((char *)&p,sizeof(p));
		cout<<"\n\nDO YOU WANT TO CONTINUE - PRESS (1) OR PRESS (0) TO END";
		cin>>ch;
	}while(ch);
	cpay.close();
}

void payroll::readDet()
{
	payroll p;
	ifstream rpay;
	rpay.open("payroll.dat");
	rpay.read((char *)&p,sizeof(p));
	rpay.seekg(0);
	if(!rpay)
	{
		cout<<"\n\nERROR:FILE NOT YET OPENED";
	}
	else
	{
		while(true)
		{
		   rpay.read((char *)&p,sizeof(p));	
		   if(rpay.eof())
		   {
		   	break;
		   }
		   p.display();
		}
		
	}
 } 
 
 void payroll::addNew()
 {
 	payroll p;
 	ofstream apay;
 	apay.open("payroll.dat",ios::app|ios::binary);
 	if(!apay)
 	{
 	  cout<<"\n\nERROR:FILES NOT YET OPENED";	
	}
	getchar();
	system("cls");
	p.getInfo();
	p.getData();
	p.TaxCalc();
	p.prof_tax();
	p.EpfCalc();
	p.GrossSalary();
	p.TakeHomeSalary();
	apay.write((char *)&p,sizeof(p));
	apay.close();
 }

void payroll::modifyRec(int id)
{
	int pos, flag = 0;
	cout<<"\n\nENTER THE EMPLOYEE INFORMATION TO BE MODIFIED";
	cin>>id;
	fstream mpay;
	mpay.open("payroll.dat",ios::binary|ios::in|ios::out);
	while(!mpay.eof())
	{
		pos = mpay.tellg();
		mpay.read((char *)this,sizeof(payroll));
		if(mpay)
		{
		   if(id == id_no)
		   {
		      flag = 1;
		      getchar();
	          system("cls");
	          getInfo();
	          getData();
	          TaxCalc();
	          prof_tax();
	          EpfCalc();
	          GrossSalary();
	          TakeHomeSalary();
		      mpay.seekg(pos);
		      mpay.write((char *)this,sizeof(payroll));
		      display();
		      break;	
		    }
	    }
	}
	mpay.close();
	if(flag == 1)
	{
		cout<<"GIVEN INFORMATION IS MODIFIED";
	}
	else
	{
		cout<<"GIVEN INFORMATION IS NOT MODIFIED";
	}
}

void payroll::deleteRec(int id)
{
	int flag = 0;
	cout<<"\n\nENTER THE EMPLOYEE INFORMATION TO DELETE:\nID: ";
	cin>>id;
	ifstream dpay;
	dpay.open("payroll.dat",ios::binary|ios::in);
	ofstream dpay1;
	dpay1.open("temp.dat",ios::binary|ios::out);
	while(!dpay.eof())
	{
		dpay.read((char *)this,sizeof(payroll));
		if(dpay)
		{
			if(id == id_no)
			{
				flag = 1;
				cout<<"\n\nTHE DELETED INFORMATION IS:"<<endl<<endl;
				display();
			}
			else
			{
				dpay1.write((char *)this,sizeof(payroll));
			}
		}
	}
	dpay.close();
	dpay1.close();
	remove("payroll.dat");
	rename("temp.dat","payroll.dat");
	if(flag == 1)
	{
		cout<<"\n\nGIVEN INFORMATION IS DELETED";
	}
	else
	{
		cout<<"\n\nGIVEN INFORMATION IS NOT DELETED";
	}
}

void payroll::search(int id)
{
	int flag = 0;
	cout<<"ENTER THE EMPLOYEE INFORMATION TO BE SEARCHED:\nID:";
	cin>>id;
	ifstream spay;
	spay.open("payroll.dat",ios::binary|ios::in);
	while(!spay.eof())
	{
		spay.read((char *)this,sizeof(payroll));
		if(spay)
		{
			if(id == id_no)
			{
				flag = 1;
				cout<<"THE SEARCHED EMPLOYEE INFORMATION IS "<<endl<<endl;
				display();
			}
		}
	}
	spay.close();
	if(flag == 1)
	{
		cout<<"\n\nGIVEN INFORMATION IS FOUND";
	}
	else
	{
		cout<<"\n\nGIVEN INFORMATION IS NOT FOUND";
	}
}

int main()
{
	system("color 4F");
	int r;
	char option;
	payroll p;
	while(1)
	    {
	      
	      getchar();
	      system("cls");
	      printf("\nENTER THE CHOICE: \na) CREATE RECORD \nb) DISPLAY RECORDS\nc) ADD NEW RECORD\nd) MODIFY RECORDS\ne) DELETE RECORDS\nf) SEARCH RECORDS\ng) QUIT\n");  //asking for the choice
	      scanf("%c",&option);
	      if(option == 'g'||option == 'G')
	      {
	      	exit(0);
		  }
	      else if(option == 'a'||option == 'A')
	      {
		    p.create();
		    getchar();
	      }
	      	else if(option == 'b'||option == 'B')
	      {
	        p.readDet();
			getchar();	  	
		  }	
		  else if(option == 'c'||option == 'C')
		  {
		  	p.addNew();
		  	getchar();
		  }
		  else if(option == 'd'||option == 'D')
		  {
		  	p.modifyRec(r);
		  	getchar();
		  }
		  else if(option == 'e'||option == 'E')
		  {
		  	p.deleteRec(r);
		  	getchar();
		  }
		  else if(option == 'f'||option == 'F')
		  {
		  	p.search(r);
		  	getchar();
		  }
	  }
	  return 0;
}