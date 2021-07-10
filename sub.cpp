using namespace std;
void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}
class emp_info
{
	protected:
		char first_name[50],last_name[50],dep[40];
		char password[20];
		char slash,address[100];
		
		int id_no;
		int da,m,y;
		int age; 
		
		float basic;
		float gross_salary;
		float medi_insur;
	public:
		
		void emp_id();
		void emp_name();
		void emp_basic();
		void emp_dept();
	
		void getInfo();
		void dateTime();
		void getDob();
		void getAdd();
		void getPassword();
};
class allowance: virtual public emp_info
{
	protected:
		float other_all,con_all,hr_all;
		float incre,hra1,spe1,con1;
		
	public:
		int GrossSalary();
		void hraAllow();
		int hraCalc();
		void conveyAllow();
		int conveyCalc();
		void specialAllow();
		int specialCalc();
		void increment();
		void allow();
};

class deductions:virtual public emp_info
{
	protected:
		float medi_insur,epf,income_tax,profess_tax;
	public:
		void medi()
		{
	        do
	        {
		        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);	
				cout<<"\n\n  Enter medical insurance     (in Rs) : ";
				ResetConsoleColour(240);
		        cin>>medi_insur;
	            
		        if(medi_insur >= 0)
				   break;	
			    else
			    {
				   cout<<"\nInvalid value...! Re-enter : ";
				   continue;	
			    }	
            } while(true);	        	        
		}
		int TaxCalc();
		int prof_tax(); 
		int EpfCalc();
};
class appraisal:virtual public emp_info
{
    protected:
    	int a,b,c,d,e,f,g,h,i,j,k;
	public:
		void getApp();
		void G_feedback();
		void P_feedback();
		int over_all();	
};
class payroll:public allowance,public deductions,public appraisal
{
	protected:
	  float	take_salary;
	  
	public:
		int TakeHomeSalary();
   	    void create();
		void readDet();
		void display();
		void display1();
		void display3();
		void displayName();
		void addNew();
		void modifyRec(int);
		void deleteRec(int);
		void search(int);
		void search_emp(int);
			
};

//----------------------------------------------------------------------------------------------------------------------------------------
//EMPLOYEE DETAILS
//----------------------------------------------------------------------------------------------------------------------------------------
// DISPLAY OF EMPLOYEE DETAILS 

void payroll::display1()
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<"\n\n\t\t\t\t------------------------------------------------------------------------\n";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	
    cout<<"\n\n\n\t\t\t\t\t\t\t  ----EMPLOYEE DETAILS---- "<<endl<<endl<<endl;
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
    
    cout<<"\n\n\t\t\t\t------------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  Id            : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<id_no<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  First Name    : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<first_name<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  Last Name     : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<last_name<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  Designation   : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<dep<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  Age           : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<age<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  Address       : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<address<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  Date of birth : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<da<<slash<<m<<slash<<y<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\t\t  Password      : ";
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<password<<endl;
    cout<<"\n\n\t\t\t\t------------------------------------------------------------------------\n\n";
}
//----------------------------------------------------------------------------------------------------------------------------------------
// ADDRESS OF EMPLOYEE

void emp_info::getAdd()
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  Enter address       : ";
		ResetConsoleColour(240);
    fflush(stdin);
    cin.getline(address,100);
}
//---------------------------------------------------------------------------------------------------------------------------------------
//PASSWORD

void emp_info::getPassword()
{
	char ch;
	int i,count;
	pass:
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		cout<<"\n  Enter password      : ";
		ResetConsoleColour(240);
	for(i=0;;)
	{
		ch = getch();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='!'&&ch<='@'))
		{
			password[i] = ch;
			++i;
			ch='*';
			cout<<ch;
	    }
	    if(ch == '\b' && i>=1)
	    {
	    	cout<<"\b \b";
	    	--i;
		}
		if(ch == '\r')
		{
			password[i] = '\0';
			break;
		}
	}
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	char h;
	cout<<"\n\n  Press 'y' to view password   ";
	ResetConsoleColour(240);
	cin>>h;
	if(h=='y' || h=='Y')
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		cout<<"\n\n  Created password    : ";
		ResetConsoleColour(240);
		cout<<password;
		cout<<"\n\n\n\t";
	}
	system("pause");
}
//----------------------------------------------------------------------------------------------------------------------------------------
//EMPLOYEE ID

void emp_info::emp_id()
{
	do
	{
		cout<<"\n\n";
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
	    cout<<"\t\tEmployee Details";
	    ResetConsoleColour(240);
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	    cout<<"\n\n  Enter ID            : ";
	    ResetConsoleColour(240);
	    cin>>id_no;
		if(id_no>=0)
		{
		  break;	
		}
		else
		{
		  SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		  cout<<"\nInvalid value...! Re-enter ";
		  ResetConsoleColour(240);
		  continue;	
		}	
	}while(true);
}
//---------------------------------------------------------------------------------------------------------------------------------------
//DATE AND TIME
void emp_info::dateTime()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t  DATE/TIME           : ";
	ResetConsoleColour(240);
	cout<<dt;
}
//--------------------------------------------------------------------------------------------------------------------------------------
//DATE OF BIRTH

void emp_info::getDob()
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  Enter date of birth : ";
	ResetConsoleColour(240);
	cin>>da>>slash>>m>>slash>>y;
	
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  Enter age           : ";
	do{
	ResetConsoleColour(240);
    cin>>age; 
	if(age>=18 && age<=58)
		break;
	else
		cout<<"\n Invalid age.!.Reenter: "  ;
		continue;
	}while(true);
	  
}
//---------------------------------------------------------------------------------------------------------------------------------------
//EMPLOYEE NAME

void emp_info::emp_name()
{
	fflush(stdin);
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  Enter first name    : ";
	ResetConsoleColour(240);
    cin>>first_name;
    
    fflush(stdin);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  Enter last name     : ";
	ResetConsoleColour(240);
    cin>>last_name;	
}

//---------------------------------------------------------------------------------------------------------------------------------------
//EMPLOYEE DEPARTMENT
//---------------------------------------------------------------------------------------------------------------------------------------

void emp_info::emp_dept()
{
	fflush(stdin);
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  Enter department    : ";
	ResetConsoleColour(240);
	cin.getline(dep,40);
}
//---------------------------------------------------------------------------------------------------------------------------------------
//EMPLOYEE COMPLETE INFORMATION

void emp_info::getInfo()
{
    emp_id();
	emp_name();
	emp_dept();
	getDob();	
    getAdd();
    getPassword();
}

/*--------------------------------------------------------------------------------------------------------------------------------------
EMPLOYEE APPRAISAL
//OVERALL RATING*/

int appraisal::over_all()
{
	k=(a+b+c+d+e+f+g+h+i+j)/10;
	return k;
}
//----------------------------------------------------------------------------------------------------------------------------------------
// DISPLAY THE APPRAISAL FORM

void payroll::display3()
{
	system("cls");
	ResetConsoleColour(15);
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout<<"\n\n\t\t\t\t\t\t---- EMPLOYEE APPRAISAL ---- "<<endl<<endl;
	ResetConsoleColour(240);
    cout<<"\t\t\t\t--------------------------------------------------------------\n";
    ResetConsoleColour(15);
    cout<<"\n\n\t\t\t\t\t5 Excellent - 4 Very good - 3 Good - 2 Fair - 1 Poor\n\n";
    ResetConsoleColour(240);
    cout<<"\n\t\t\t\t--------------------------------------------------------------\n";
    
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tAttendance                                 : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<a<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tDiscipline                                 : ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<b<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tGeneral conduct                            : ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<c<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tQuality of work                            : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<d<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tReliability and consistency of performance : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<e<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tWorking with management and peers          : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<f<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tPerformance under pressure                 : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<g<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tVolunteering                               : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<h<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tJob knowledge and skills                   : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<i<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tInitiative and motivation                  : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<j<<endl;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
    cout<<"\n\t\t\t\t--------------------------------------------------------------\n";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\t\t\t\t\tOverall performance rating                 : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<k<<endl;
    cout<<"\n\t\t\t\t--------------------------------------------------------------\n\n\n\t\t\t\t";
    system("pause");
}
//--------------------------------------------------------------------------------------------------------------------------------------
//GENERAL FEEDBACK

void appraisal::G_feedback()
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout<<"\n\n\t\t\t\t\t\t\t ENTER THE FEEDBACK\n";
    cout<<"\n\n\t\t\t\t\t 5  Excellent - 4  Very good - 3 Good - 2 Fair - 1 Poor \n\n";	
	ResetConsoleColour(240);
	
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 250);
	cout<<"\n\t\t\t\t\t\t --- General feedback ---\n";
    ResetConsoleColour(240);
    
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  1) Attendance           : ";
	ResetConsoleColour(240);
	
    fflush(stdin);
    do
	{
    	cin>>a;
    	if(a>0&&a<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  2) Discipline           : ";
	ResetConsoleColour(240);
	
    fflush(stdin);
    do
	{
    	cin>>b;
    	if(b>0&&b<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  3) General conduct      : ";
	ResetConsoleColour(240);
    fflush(stdin);
    do
	{
    	cin>>c;
    	if(c>0&&c<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  4) Quality of work      : ";
	ResetConsoleColour(240);
	
    fflush(stdin);
    do
	{
    	cin>>d;
    	if(d>0&&d<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
	cout<<"\n\n";
}
//-------------------------------------------------------------------------------------------------------------------------------------
//PERSONAL FEEDBACK

void appraisal::P_feedback()
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 250);
    cout<<"\n\t\t\t\t\t\t --- Performance feedback ---\n";
    ResetConsoleColour(240);
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  1) Reliability and consistency of performance  : ";
	ResetConsoleColour(240);
    fflush(stdin);
    do
	{
    	cin>>e;
    	if(e>0&&e<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
    
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  2) Working with management and peers           : ";
	ResetConsoleColour(240);
    fflush(stdin);
    
    do
	{
    	cin>>f;
    	if(f>0&&f<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  3) Performance under pressure                  : ";
	ResetConsoleColour(240);
    fflush(stdin);
    
    do
	{
    	cin>>g;
    	if(g>0&&g<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n  4) Volunteering                                : ";
	ResetConsoleColour(240);
    fflush(stdin);
    
    do
	{
    	cin>>h;
    	if(h>0&&h<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  5) Job knowledge and skills                    : ";
	ResetConsoleColour(240);
    fflush(stdin);
    
    do
	{
    	cin>>i;
    	if(i>0&&i<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);
	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n  6) Initiative and motivation                   : ";
	ResetConsoleColour(240);
    fflush(stdin);
    
    do
	{
    	cin>>j;
    	if(j>0&&j<=5)
    		break;
    	else
    		cout<<"\n\nInvalid value...! Re-enter :  ";
    		continue;
	}while(true);	
}
//---------------------------------------------------------------------------------------------------------------------------------------
//EMPLOYEE COMPLETE APPRAISAL 
void appraisal::getApp()
{
	G_feedback();
	P_feedback();
	over_all();
}
/*---------------------------------------------------------------------------------------------------------------------------------------
EMPLOYEE PAYROLL
*/
//HRA ALLOWANCE

void allowance::hraAllow()
{
    fflush(stdin);
	do
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		cout<<"\n\n  Enter H.R allowance          (in %) : ";
		ResetConsoleColour(240);
        cin>>hr_all;
        if(hr_all >= 0)
        {
		   break;	
	    }
	    else
	    {
		   cout<<"\nInvalid value...! Re-enter : ";
		   continue;	
	    }	
    }while(true);	
}
int allowance::hraCalc()
{	
	hra1 = (hr_all * basic)/100;
	return hra1;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//CONVEYANCE ALLOWANCE

void allowance::conveyAllow()
{
	do
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		cout<<"\n\n  Enter conveyance allowance   (in %) : ";
		ResetConsoleColour(240);
        cin>>con_all;
        
        if(con_all >= 0)
        {
		   break;	
	    }
	    else
	    {
		   cout<<"\nInvalid value...! Re-enter : ";
		   continue;	
	    }	
    }while(true);
}
int allowance::conveyCalc()
{
    con1 = (con_all * basic)/100;
	return con1;		
} 
//--------------------------------------------------------------------------------------------------------------------------------------
//SPECIAL ALLOWANCE

void allowance::specialAllow()
{
    do
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		cout<<"\n\n  Enter special allowance      (in %) : ";
		ResetConsoleColour(240);
	    cin>>other_all;
        if(other_all >= 0)
        {
		   break;	
	    }
	    else
	    {
		   cout<<"\nInvalid value...! Re-enter : ";
		   continue;	
	    }	
    }while(true);
}
int allowance::specialCalc()
{
	spe1 = (other_all * basic)/100;
	return spe1;
}
//--------------------------------------------------------------------------------------------------------------------------------------
//INCREMENT

void allowance::increment() 
{
   	do
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		cout<<"\n\n  Enter amount of increment   (in Rs) : ";
		ResetConsoleColour(240);
	    cin>>incre;
        if(incre >= 0)
        {
		   break;	
	    }
	    else
	    {
		   cout<<"\nInvalid value...! Re-enter : ";
		   continue;	
	    }	
    }while(true);
}
//---------------------------------------------------------------------------------------------------------------------------------------
//BASIC SALARY

void emp_info::emp_basic()
{
	fflush(stdin);
	do
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
		cout<<"\n\n  Enter basic salary          (in Rs) : ";
		ResetConsoleColour(240);
	    cin>>basic;
	    if(basic > 0)
	    {
		   break;	
	    }
	    else
	    {
		   cout<<"\nInvalid value...! Re-enter : ";
		   continue;	
	    }	
    }while(true);
}
//---------------------------------------------------------------------------------------------------------------------------------------
//COMPLETE ALLOWANCES

void allowance::allow()
{
	increment();
    hraAllow();
	hraCalc();
    conveyAllow();
    conveyCalc();
	specialAllow();
	specialCalc();
}
//---------------------------------------------------------------------------------------------------------------------------------------
//INCOME TAX

int deductions::TaxCalc()
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
		printf("\nINVALID AMOUNT...!\n");
	}
	return income_tax;  
}
//---------------------------------------------------------------------------------------------------------------------------------------
//GROSS SALARY 

int allowance::GrossSalary()
{
	gross_salary = basic +  hr_all + other_all + con_all + incre - medi_insur ;
	return gross_salary;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//TAKE HOME SALARY

int payroll::TakeHomeSalary()
{
	take_salary = gross_salary - income_tax - profess_tax - epf;
	return take_salary;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//PROFESSIONAL TAX

int deductions::prof_tax()
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
		printf("\nINVALID AMOUNT...!\n");
	}
	return profess_tax;  
}
//---------------------------------------------------------------------------------------------------------------------------------------
//EPF CALCULATION

int deductions::EpfCalc()
{
	epf = (0.1)*gross_salary;
	return epf;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//DISPLAY THE PAYROLL

void payroll::display()
{
	payroll p;
	system("cls");
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<"\n\t\t\t\t------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout<<"\n\n\t\t\t\t\t\tPAYROLL OF EMPLOYEE - ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<first_name<<" "<<last_name;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<"\n\n\t\t\t\t------------------------------------------------------------------------------\n\n";
	cout<<"\t\t\t\t\t\t";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	time_t now = time(0);
	char* dt = ctime(&now);
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\tDATE/TIME           : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<dt;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<"\n\t\t\t\t------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout<<"\n\n\t\t\t\t\t\t EARNINGS \n";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\n\t\t\t\t\t\tBASIC SALARY        : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<basic;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t\tH.R ALLOWANCE       : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<hra1;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t\tCONVEYANCE ALLOWANCE: ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<con1;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t\tSPECIAL ALLOWANCE   : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<spe1;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t\tINCREMENT           : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<incre;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout<<"\n\n\n\t\t\t\t\t\t DEDUCTIONS \n";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\n\t\t\t\t\t\tE.PROVIDENT FUND    : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<epf;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t\tMEDICAL INSURANCE   : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<medi_insur;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t\tINCOME TAX          : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<income_tax;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\t\t\t\t\t\tPROFESSIONAL TAX    : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<profess_tax;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<"\n\n\t\t\t\t------------------------------------------------------------------------------\n\n";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout<<"\t\t\t\t\t\tNET PAY             : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<take_salary;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout<<"\n\n\t\t\t\t------------------------------------------------------------------------------\n\n\t\t\t\t\t";	
	system("pause"); 
}
//---------------------------------------------------------------------------------------------------------------------------------------
/****************************************************************************************************************************************
MENU
******************************************************************************************************************************************/
//CREATE

void payroll::create()
{
    int ch;
	payroll p;
	ofstream cpay;
	cpay.open("employ.dat",ios::binary|ios::app);
	if(!cpay)
	{
	  cout<<"\n\nERROR:FILE NOT YET OPENED...!\n";	
	}	
	getchar();
	system("cls");
	p.getInfo();
	getchar();
	system("cls");
	p.getApp();
	getchar();
	system("cls");
	p.dateTime();
	p.emp_basic();
	p.allow();
	p.medi();
	p.GrossSalary();
	p.TaxCalc();
	p.prof_tax();
	p.EpfCalc();
	p.TakeHomeSalary();
	cpay.write((char *)&p,sizeof(p));
	
	cpay.close();
}
//--------------------------------------------------------------------------------------------------------------------------------------
//DISPLAY  THE LIST

void payroll::displayName()
{
	cout<<id_no<<setw(15)<<first_name<<" "<<last_name<<setw(40)<<dep<<endl;	
}
//--------------------------------------------------------------------------------------------------------------------------------------
//READ DATA

void payroll::readDet()
{
	payroll p;
	int flag=0;
	int searchid;
	ifstream rpay;
	rpay.open("employ.dat");
	rpay.read((char *)&p,sizeof(p));
	rpay.seekg(0);
	if(!rpay)
	{
		cout<<"\n\nERROR : FILE NOT YET OPENED...!\n\n";
	}
	else
	{
		int id;
		char option;
		getchar();
		system("cls");
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
		cout<<"\t\t\t\t\t\t\n\nEMPLOYEES";
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	    cout<<"\n\n-----------------------------------------------------------------------------------------------\n\n";
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	    cout<<"\n\nID"<<setw(25)<<"NAME"<<setw(35)<<"DEPARTMENT\n";
	    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	    cout<<"\n\n-----------------------------------------------------------------------------------------------\n\n";
		while(true)
		{  
		   rpay.read((char *)&p,sizeof(p));	
		   
		   if(rpay.eof())
		   {
		   	    break;
		   }
		   p.displayName();
		}
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout<<"\t\t\t\t\n\n-----------------------------------------------------------------------------------------------\n\n";
		
		search:
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 249);
		cout<<"\n\n\nPress S to search information";
		cout<<"\t\tPress any key to go back to menu ";
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cin>>option;
		switch(option)
		{
			case 'S':
			case 's':
				p.search(id);
                goto search;
	            break;
			default:
				break;
		}
	}
} 
 //--------------------------------------------------------------------------------------------------------------------------------------
 //ADD NEW INFO

void payroll::addNew()
{
	payroll p;
	ofstream apay;
	apay.open("employ.dat",ios::app|ios::binary);
	if(!apay)
	{
		cout<<"\n\nERROR:FILES NOT YET OPENED...!\n";	
	}
		getchar();
		system("cls");
		p.getInfo();
		getchar();
		system("cls");
		p.getApp();
		getchar();
		system("cls");
		p.dateTime();
		p.emp_basic();
		p.medi();
		p.allow();
		p.GrossSalary();
		p.TaxCalc();
		p.prof_tax();
		p.EpfCalc();
		p.TakeHomeSalary();
		
		apay.write((char *)&p,sizeof(p));
		apay.close();
}

//----------------------------------------------------------------------------------------------------------------------------------------
//MODIFY RECORDS

void payroll::modifyRec(int id)
{
	int pos, flag = 0;
	cout<<"\n\n  Enter the id to be modified : ";
	cin>>id;
	fstream mpay;
	mpay.open("employ.dat",ios::binary|ios::in|ios::out);
	while(!mpay.eof())
	{
		pos = mpay.tellg();
		mpay.read((char *)this,sizeof(payroll));
		if(mpay)
		{
		   if(id == id_no)
		   {
		   	    getchar();
		   	    system("cls");
		   	    flag =1;
		        int ch;
				cout<<"\n\n\t\t\t\t\tSelect the detail to be modified : \n";
				cout<<"\t\t\t\t\t-------------------------------------------";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
				cout<<"\n\t\t\t\t\t\tEMPLOYEE DETAILS\n";
				ResetConsoleColour(240);
				cout<<"\t\t\t\t\t-------------------------------------------";
				cout<<"\n\t\t\t\t\t 1) Employee Name";
				cout<<"\n\t\t\t\t\t 2) Department";
				cout<<"\n\t\t\t\t\t 3) Date of birth";
				cout<<"\n\t\t\t\t\t 4) Address";
				cout<<"\n\t\t\t\t\t 5) Change password";
				cout<<"\n\t\t\t\t\t-------------------------------------------";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
				cout<<"\n\t\t\t\t\t\tEMPLOYEE APPRAISAL";
				ResetConsoleColour(240);
				cout<<"\n\t\t\t\t\t-------------------------------------------";
				cout<<"\n\t\t\t\t\t 6) Appraisal form";
				cout<<"\n\t\t\t\t\t-------------------------------------------";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
				cout<<"\n\t\t\t\t\t\tEMPLOYEE PAYROLL";
				ResetConsoleColour(240);
				cout<<"\n\t\t\t\t\t-------------------------------------------";
				cout<<"\n\t\t\t\t\t 7) Basic Pay";
				cout<<"\n\t\t\t\t\t 8) H.R.Allowance";
				cout<<"\n\t\t\t\t\t 9) Conveyance Allowance";
				cout<<"\n\t\t\t\t\t 10)Special Allowance";
				cout<<"\n\t\t\t\t\t 11)Increment";
				cout<<"\n\t\t\t\t\t 12)Medical Insurance";
				cout<<"\n\n\t\t\t\t\t Enter your choice : ";
				cin>>ch;                     
				mod:            
				switch(ch)
				{
					case 1:
						emp_name();
						break;
					case 2:
						emp_dept();
						break;
					case 3:
						getDob();
                        break;
                    case 4:
                    	getAdd();
                    	break;
                    
                    case 5:
                    	getPassword();
                    	break;
                    case 6:
                    	getApp();
                    	break;
					case 7:
					    emp_basic();
					    GrossSalary();
					    TaxCalc();
					    prof_tax();
					    EpfCalc();
					    TakeHomeSalary();
						break;
					case 8:
					    hraAllow();
					    hraCalc();
					    GrossSalary();
					    TaxCalc();
					    prof_tax();
					    EpfCalc();
					    TakeHomeSalary();
						break;
					case 9:
						conveyAllow();
						conveyCalc();
						GrossSalary();
					    TaxCalc();
					    prof_tax();
					    EpfCalc();
					    TakeHomeSalary();
						break;
					case 10:
						specialAllow();
						specialCalc();
						GrossSalary();
					    TaxCalc();
					    prof_tax();
					    EpfCalc();
					    TakeHomeSalary();
                        break;
					case 11:
					    increment();
					    GrossSalary();
					    TaxCalc();
					    prof_tax();
					    EpfCalc();
					    TakeHomeSalary();
						break;
					case 12:
					    medi();
					    GrossSalary();
					    TaxCalc();
					    prof_tax();
					    EpfCalc();
					    TakeHomeSalary();
						break;
					default:
					    cout<<"Invalid choice...!\n";
						goto mod; 	
						break;			
				}	
		      mpay.seekg(pos);
		      mpay.write((char *)this,sizeof(payroll));
		      break;	
		    }
	    }
	}
	mpay.close();
	if(flag == 1)
	{
		cout<<"\n\nInformation is modified...!\n\n";
	}
	else
	{
		cout<<"\n\nId not found...!\n\n";
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------
//DELETE RECORD

void payroll::deleteRec(int id)
{
	int flag = 0;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
    cout<<"\n\nEnter the id to be deleted : ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cin>>id;
	ifstream dpay;
	dpay.open("employ.dat",ios::binary|ios::in);
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
				
			}
			else
			{
				dpay1.write((char *)this,sizeof(payroll));
			}
		}
	}
	dpay.close();
	dpay1.close();
	remove("employ.dat");
	rename("temp.dat","employ.dat");
		if(flag == 1)
	{
		cout<<"\n\nInformation is deleted successfully ...\n\n";
	}
	else
	{
		cout<<"\n\nID not found...\n\n";
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
//SEARCH RECORD

void payroll::search(int id)
{
	int flag = 0;
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
	cout<<"\n\n\t\tEnter the id to be searched : ";
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cin>>id;
	ifstream spay;
	spay.open("employ.dat",ios::binary|ios::in);
	while(!spay.eof())
	{
		spay.read((char *)this,sizeof(payroll));
		if(spay)
		{
			if(id == id_no)
			{
				flag = 1;
				getchar();
				system("cls");
				
				display1();
				getchar();
				display3();
				display();
			}
		}
	}
	spay.close();
	if(flag == 0)
	{
		cout<<"\n\nGiven id is not found..!";
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
//SEARCH EMPLOYEE

void payroll::search_emp(int id)
{
	int flag = 0;
	ifstream spay;
	spay.open("employ.dat",ios::binary|ios::in);
	while(!spay.eof())
	{
		spay.read((char *)this,sizeof(payroll));
		if(spay)
		{
			if(id == id_no)
			{
				int op;
				flag = 1;
				do
				{
				getchar();
				system("cls");
				cout<<"\n\n\n\n\t\t\t\t";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
				cout<<"Choose Required Information";
				cout<<"\n\n\n\n\t\t";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout<<"\t1) Employee Details";
				cout<<"\n\t\t";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
                cout<<"\t2) Employee Appraisal";
                cout<<"\n\t\t";
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout<<"\t3) Employee Payroll";
				cout<<"\n\t\t";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
                cout<<"\t4) Quit";
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
                cout<<"\n";
				cout<<"\n\n\t\tEnter the option: ";
				cin>>op;
				
					if(op == 1)
					{
					   getchar(); 
				       system("cls");
				       display1();
				    }
				    else if(op == 2)
				    {
						getchar();
				        display3();
				    }
				    else if(op == 3)
				    {
						getchar();
				        display();
				    }
				    else if(op == 4)
				    {
				    	break;
					}
				    else
				    {
				    	cout<<"\n\nInvalid";
					}
				}while(true);	
			}
		}
	}
	spay.close();
		if(flag != 1)
	{
		cout<<"\n\nId is not found...!\n\n";
		system("pause");
	}
}
