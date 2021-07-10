#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <ctime>
#include <iomanip>
#include<windows.h>
#include "sub.cpp"
using namespace std;

int main()
{
	SetConsoleTitleA("HR Management System");
	
    int lo_at=0,i;
	while(lo_at<3)
	{
		system("cls");
		char u_id[25],u_pass[10],u_id1[4],u_pass1[4];
		int u_id2;
		char passwor[10],passwo[10],passwo1[10];
		int ch1;
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tGOOGLE\n";
		ResetConsoleColour(240);
		cout<<"\n\t\t\t\t\t\"Committed to significantly improving the lives of as many people as possible.\"\n";
		cout<<"\n\n\t\t\t\t\t\t\"We provide access to the world\'s information in one click.\"\n";
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tUSERID   : ";
		ResetConsoleColour(240);
		cin>>u_id;
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
		cout<<"\n\t\t\t\t\t\t\tPASSWORD : ";
		ResetConsoleColour(240);
		for( i=0 ; ; )
		{
			u_pass[i] = getch();
			if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
			{
				passwor[i] = u_pass[i];
				++i;
				u_pass[i]='*';
				cout<<u_pass[i];
		    }
		    if(u_pass[i] == '\b' && i>=1)
		    {
		    	cout<<"\b \b"; 
		    	--i;
			}
			if(u_pass[i] == '\r')
			{
				passwor[i] = '\0';
				break;
			}
		}
	if(strcmp(u_id,"Smartworker")== 0 && strcmp(passwor,"1234")== 0)
		{
			while(1)
			{
				system("cls");
				ResetConsoleColour(252);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLOADING PROGRAM...";
	                Sleep (1500);
	                cout << ".....";
	                Sleep (2000);
	                cout << ".....";
				start:
				system("cls");
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 249);
				cout<<"\n\n\t\t\tOur mission is to organise the world's information and make it universally accessible and useful.\n";
				ResetConsoleColour(240);
				cout<<"\n\n\n\n\t\t\t\t\t\t1) HR\n\n\t\t\t\t\t\t2) EMPLOYEE\n\n\t\t\t\t\t\t3) QUIT";
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
				cout<<"\n\n\t\t\tEnter your choice : ";
				ResetConsoleColour(240);
				cin>>ch1;
				if(ch1==1)
				{
					cout<<"\n\n\t\t-----------------------------------------------------------------------------------------\n\n";
					SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
					cout<<"\n\n\t\t\t\t\t\t---- HR ----\n\n";
					
					SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
					cout<<"\n\n\t\t\tUSERID    : ";
					ResetConsoleColour(240);
					cin>>u_id1;
					SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
					cout<<"\n\t\t\tPASSWORD  : ";
					ResetConsoleColour(240); 
					
					for( i=0 ; ; )
					{
						u_pass1[i] = getch();
						if((u_pass1[i]>='a'&&u_pass1[i]<='z')||(u_pass1[i]>='A'&&u_pass1[i]<='Z')||(u_pass1[i]>='!'&&u_pass1[i]<='@'))
						{
							passwo[i] = u_pass1[i];
							++i;
							u_pass1[i]='*';
							cout<<u_pass1[i];
					    }
					    if(u_pass1[i] == '\b' && i>=1)
					    {
					    	cout<<"\b \b";
					    	--i;
						}
						if(u_pass1[i] == '\r')
						{
							passwo[i] = '\0';
							break;
						}
					}
					
					cout<<"\n";
					cout<<"\n\n\t\t-----------------------------------------------------------------------------------------\n\n";
					int flag;
				    ifstream fin;
				    fin.open("hr.dat",ios::binary|ios::in|ios::out);
				    char ch;
					//int flag;
			
			        for(int i=0;i<4 && !fin.eof();i++)
			        {
				        fin.get(ch);
			        	if(ch!=u_id1[i])
			        	{
			        		flag=1;
			        		break;
						}
						else
							flag=0;	
				    } 
				    
					if (flag==0) 
					{
						SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 241);
						cout<<"\n\n\n\n\t\t\t\t\t  \" A WARM WELCOME HR \"\n\n\n\n\n\t\t";
						ResetConsoleColour(240);
						system("pause");
						
							int r;
							char option;
							int n;
							payroll p;
							while(1)
							    {
							      
								  //menu:
							      
							      getchar();
							      system("cls");
							      SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
							      cout<<"\n\n\n\n\t\t\t\t";
							      cout<<"\n\n\t\t\t\t\t\t\t\t----- MENU -----\n\n";  //asking for the choice
							      cout<<"\n\n\n\n\t\t";
							      SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
							      cout<<"\t\t\t\t\ta) Register\n";
							      cout<<"\n\t\t";
							      SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
							      cout<<"\t\t\t\t\tb) Display record\n";
							      cout<<"\n\t\t";
							      SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
							      cout<<"\t\t\t\t\tc) Add new record\n";
							      cout<<"\n\t\t";
							      SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
								  cout<<"\t\t\t\t\td) Modify record\n";
								  cout<<"\n\t\t";
								  SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
								  cout<<"\t\t\t\t\te) Delete record\n";
								  cout<<"\n\t\t";	
								  SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
								  cout<<"\t\t\t\t\tf) Search record\n";
								  cout<<"\n\t\t";
								  SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
								  cout<<"\t\t\t\t\tg) Return to HR / Employee page\n";
								  cout<<"\n";
								  cout<<"\n\n\t\t\t\t\t\tEnter your choice : ";
								   cin>>option;
							      if(option == 'g'||option == 'G')
							      {
							      	goto start;
								  }
							      else if(option == 'a'||option == 'A')
							      {
								    p.create();
								  
							      }
							      	else if(option == 'b'||option == 'B')
							      {
							        p.readDet();
										  	
								  }	
								  else if(option == 'c'||option == 'C')
								  {
								  	p.addNew();
								  	
								  }
								  else if(option == 'd'||option == 'D')
								  {
								  	p.modifyRec(r);
								  
								  }
								  else if(option == 'e'||option == 'E')
								  {
								  	p.deleteRec(r);
								  
								  }
								  else if(option == 'f'||option == 'F')
								  {
								  	p.search(r);
								  	
								  }
								  cout<<"\n";
								system("pause");  
							  }
					}
					else
					{
						cout<<"\n\tInvalid user login attempt by HR...!\n\n\n";
						system("pause");
					}
				}
				//employee
				if(ch1==2)
				{
					SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 244);
					cout<<"\n\n\t\t\t\t\t----EMPLOYEE----";
					SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 252);
					cout<<"\n\n\t\tUSERID    : ";
					SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
					cin>>u_id2;
					cout<<"\n\n";
			
					ResetConsoleColour(240);
					char opt;
					payroll p;
					p.search_emp(u_id2);
					goto start;
				
			    }
			    else if(ch1 == 3)
			    {
			    	exit(0);
				}
			    else
			    cout<<"\n\n\nINVALID CHOICE...!\n\n";
			}
		}
			
		else
		{
			lo_at++;
			cout<<"\n\n\n\n\t\t\t\t\tINVALID LOGIN ATTEMPT...!\n\n\n";
			cout<<"\t\t\t\t\t";
			system("pause");
		}
	}
	cout << "\n\nt\t\t\t\tToo many login attempts! Try again later...\n\nt\t\t\t\tThank you...!\n\n\n";
}
