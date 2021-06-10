#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void show_record();
void reset_score();
void help();
void edit_score(float , char []);
void credits();
struct question 
{
	char statement[300];
	char answer;
	char optiona[30];
	char optionb[30];
	char optionc[30];
	char optiond[30];
	int questionno;
};
int main()
     {
     int countr=0,r,r1,count,i,n;
     float score;
     char choice;
     char playername[20];
     mainhome:
     system("cls");
     printf("\n\n\n\t\t\tC PROGRAM QUIZ GAME\n");
     printf("\n\t\t_________________________________________________");
     printf("\n\t\t|\t\t   WELCOME                      |");
     printf("\n\t\t|\t\t      to                        |");
     printf("\n\t\t|\t\t THE GAME                       |");
     printf("\n\t\t|_______________________________________________|");
     printf("\n\t\t|_______________________________________________|");
     printf("\n\t\t| > Press S to start the game                   |");
     printf("\n\t\t| > Press V to view the highest score           | ");
     printf("\n\t\t| > Press R to reset score                      |");
     printf("\n\t\t| > Press H for help                            |");
     printf("\n\t\t| > Press C for credits                         |");
     printf("\n\t\t| > press Q to quit                             |");
     printf("\n\t\t|_______________________________________________|\n\n");
     choice=toupper(getch());
     if (choice=='V')
	{
	show_record();
	goto mainhome;
	}
     else if (choice=='H')
	{
	help();getch();
	goto mainhome;
	}
	else if (choice=='R')
	{reset_score();
	getch();
	goto mainhome;}
	else if (choice=='C')
	{credits();
	 getch();
	 goto mainhome;
	}
	else if (choice=='Q')
	exit(1);
    else if(choice=='S')
    {
     system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tRegister your name:");
     gets(playername);

    system("cls");
    printf("\n ------------------  Welcome %s to Quiz Game----------------------------",playername);
    printf("\n\n Here are some tips you might wanna know before playing:");
    printf("\n -------------------------------------------------------------------------");
    printf("\n >> There are 2 rounds in this Quiz Game");
    printf("\n >> In warmup round you will be asked a total of 5 questions to test your");
    printf("\n    general knowledge. ");
    printf("\n >> Your game starts with CHALLANGE ROUND. In this round you will be asked a");
    printf("\n    total of 10 questions. Each right answer will be awarded $100,000!");
    printf("\n    By this way you can win upto ONE MILLION cash prize!!!!!..........");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option.");
    printf("\n >> No negative marking for wrong answers!");
    printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
    printf("\n\n\n Press Y  to start the game!\n");
    printf("\n Press any other key to return to the main menu!");
    if (toupper(getch())=='Y')
		{
		    goto home1;
        }
	else
		{
        goto mainhome;
       system("cls");
       }
      
	  
	home1:
    system("cls");
	FILE *fp2;
	fp2=fopen("questions2.bin","rb");
	struct question q[30];
	fread(q,sizeof(struct question),30,fp2);
	int j,rb=0;
	int pass = 0;
	for(j=1;j<=5;j++)
    {
		system("cls");
		printf("Round 1(Warmup round)\n");
		
		
	
       srand(time(NULL));
       rb = rand()%30;
		puts(q[rb].statement);
		printf("\n\nA.%s\n\nB.%s\n\nC.%s\n\nD.%s",q[rb].optiona,q[rb].optionb,q[rb].optionc,q[rb].optiond);
		if (toupper(getch())==q[rb].answer)
			{printf("\n\nCorrect!!!");pass++;count++; getch();
			}
		else
		       {printf("\n\nWrong!!! The correct answer is %c",q[rb].answer);getch();
			  /* goto score;*/
		      }
		if(j==2||j==4)
		{
			if(count<=2)
			{
				printf("Very poor....Practice well and enter into challenge round");
				pass=0;
				continue;
			}
			else
			{
				printf("Good!!! You can try the challenge round now");
				pass=0;
				continue;
			}
	}
		}
		fclose(fp2);
		system("cls");
		printf("\n\n\nPress B to continue with the challenge round!\n");
		printf("\n\n\nPress any other key to return to main menu\n");  
	    if (toupper(getch())=='B')
		{
		    goto home2;
        }
	    else
		{
        goto mainhome;
        system("cls");
        }
    }
    home2:
    system("cls");
	FILE *fp;
	fp=fopen("questions.bin","rb");
	struct question q[50];
	fread(q,sizeof(struct question),50,fp);
	int j,ra=0;
	int pass = 0;
	for(j=1;j<=10;j++)
    {
		system("cls");
		printf("Round 2(challenge round)\n");
		
	
       srand(time(NULL));
       ra = rand()%50;
		puts(q[ra].statement);
		printf("\n\nA.%s\n\nB.%s\n\nC.%s\n\nD.%s",q[ra].optiona,q[ra].optionb,q[ra].optionc,q[ra].optiond);
		if (toupper(getch())==q[ra].answer)
			{printf("\n\nCorrect!!!");pass++;countr++; getch();
			}
		else
		       {printf("\n\nWrong!!! The correct answer is %c",q[ra].answer);getch();
			  /* goto score;*/
		      }
		if(j==3||j==6)
		{
			if(pass>=2)
			{
				pass=0;
				continue;
			}
			else
			{
				printf("\n\n\nGAME OVER");
				getch();
				break;
			}
		}
	}
	fclose(fp);
	score:
    system("cls");
    printf("%d\n",countr);
	score=(float)countr*100000;
	if(score>0.00 && score<1000000)
	{
	   printf("\n\n\t\t*** CONGRATULATION ****");
	     printf("\n\t You won $%.2f",score);goto go;}

	 else if(score==1000000.00)
	{
	    printf("\n\n\n \t\t*** CONGRATULATION ***");
	    printf("\n\t\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
	    printf("\n\t\t You won $%.2f",score);
	    printf("\t\t Thank You!!");
	}
	 else
{
	 printf("\n\n\t** SORRY YOU DIDN'T WIN ANY CASH **");
	    printf("\n\t\t Thanks for your participation");
	    printf("\n\t\t TRY AGAIN");goto go;}

	go:
	puts("\n\n Press Y if you want to play next game");
	puts(" Press any key if you want to go main menu");
	if (toupper(getch())=='Y')
		goto home1;
	else
		{
		edit_score(score,playername);
		goto mainhome;}}

void show_record()
    {system("cls");
	char name[20];
	float scr;
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&name,&scr);
	printf("\n\n\t\t*********");
	printf("\n\n\t\t %s has secured the Highest Score %0.2f",name,scr);
	printf("\n\n\t\t*********");
	fclose(f);
	getch();}

void reset_score()
    {system("cls");
    float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","wb");
	fscanf(f,"%s%f",&nm,&sc);
	sc=0;
	fprintf(f,"%s,%.2f",nm,sc);
    fclose(f);}

void help()
	{system("cls");
    printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ......................... C program Quiz Game...........");
    printf("\n >> There are two rounds in the game, WARMUP ROUND & CHALLENGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 5 questions to test your general");
    printf("\n    knowledge. ");
    printf("\n >> Your game starts with the CHALLANGE ROUND. In this round you will be asked");
    printf("\n    total 10 questions each right answer will be awarded $100,000.");
    printf("\n    By this way you can win upto ONE MILLION cash prize in USD...............");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option");
    printf("\n >> No negative marking for wrong answers");

	printf("\n\n\t***BEST OF LUCK*****");
    }
	
void credits()
    {
    	system("cls");
    	printf("\n\n\n                         CREDITS");
    	printf("\n ___________________________________________________________________");
    	printf("\n\n         COIMBATORE INSTITUTE OF TECHNOLOGY");
    	printf("\n_____________________________________________________________________");
    	printf("\n\n         M.Sc SOFTWARE SYSTEMS- 1ST SEMESTER");
    	printf("\n_____________________________________________________________________");
    	printf("\n\n    PROJECT - QUIZ GAME");
    	printf("\n_____________________________________________________________________");
    	printf("\n\n    CODED BY-\n");
    	printf("\t      Lakshman Karthick T \n");
    	printf("\t      Kaviraj V G");
    	printf("\n_____________________________________________________________________");
    	printf("\n\n    MENTORS - \n");
    	printf("\t      Dr.P.Aruna  \n");
    	printf("\t      Dr.D.Anandhi");
    	printf("\n_____________________________________________________________________");
    	printf("\n\n\t                     THANK YOU!!!      ");
	}

void edit_score(float score, char plnm[20])
	{system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc)
	  { sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
	    fclose(f);}}
