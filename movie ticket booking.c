/*
PROGRAMING FOR PROBLEM SOLVING [MINI-PROJECT]
MINI PROJECT TITLE :- [ MOVIE TICKET BOOKING SYSTEM ]
STUDENT NAME :- [ AMOGH KUPPACHI(RA2111003011866) ]
SECTION :- [Z-2]
*/





#include<stdio.h>
#include<stdlib.h>



struct book
{
	char code[30];
	char name[30];
	char date[30];
	int cost;
}b;


int seat = 90;


void insert_details();	 //for inserting movie details (ADMIN ONLY).
void view_all();  // for viewing all data.
void book_ticket();  //for booking tickets.
void old_record();  //for view old records of users who booked tickets previously.



void main()
{

	int ch;
 	do{
	printf("\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*");
	printf("\n\n");
	printf("\t\tMOVIE TICKET BOOKING");
	printf("\n");
	printf("\n*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n\n");



	printf("\nPress <1> To - Insert Movie (ADMIN-ONLY)");
   	printf("\nPress <2> To - View all Movie Details");
	printf("\nPress <3> To - Book Tickets");
	printf("\nPress <4> To - View all Transactions (ADMIN-ONLY)");
   	printf("\nPress <0> Exit ");
    	printf("\n");



   	printf("\nEnter your Choice -> ");
   	scanf("%d",&ch);
   	printf("\n");



   	switch (ch)
   	{
    		 case 1 :
    		 insert_details();
            break;

            case 2:
    		 view_all();
            break;

            case 3:
            book_ticket();
            break;

		 case 4:
		 old_record();
            break;

    		 case 0:
    		 exit(0);
    		 break;

    		 default:
    		 printf("Wrong choice !");
    		 break;
   	}
 }while(ch!=0);

}



void insert_details() //for inserting movie details (ADMIN ONLY).
{

	FILE *fp;
	struct book b;
	printf("Enter movie code :- ");
	scanf("%s",b.code);
	printf("Enter movie name :- ");
	scanf("%s",b.name);
	printf("Enter Release Date:- ");
	scanf("%s",b.date);
	printf("Enter Ticket Price:- ");
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("FIlE not Found");
	}
	else
	{
		fprintf(fp,"\nCode : %s\nMovie : %s\nReleased on : %s\nPrice : %d\n\n",b.code,b.name,b.date,b.cost);
		printf("\n\tMovie details are inserted sucessfully!");
	}
    printf("\n");
	fclose(fp);
}




void view_all() // for viewing all data.
{
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{
	     	printf("\n");
		while( ( ch = fgetc(fp) ) != EOF )
      	printf("%c",ch);
	}
	printf("\n");
	fclose(fp);
}



void book_ticket()
{
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,total_amount;
	char name[20];
	char ch; //used to display all movies
	char movie_code[20]; //for searching
	printf("\n\t***Choose a Movie***\n\n\n");

	// displays all the movies by default for movie code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{
        	ch = fgetc(fp);
		while( ( ch = fgetc(fp) ) != EOF )
           printf("%c",ch);
	}
	fclose(fp);

	//display ends
	printf("\n\tEnter Movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{
	    getc(fp);
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode -> %s",b.code);
				printf("\n\t\tMovie name -> %s",b.name);
				printf("\n\t\tDate -> %s",b.date);
				printf("\n\t\tPrice of ticket -> %d",b.cost);
			}
		}
	}
	printf("\n* Fill Your Details *\n");
	printf("\n Your name :");
	scanf("%s",name);
	printf("Total tickets :");
	scanf("%d",&total_seat);


	total_amount = b.cost * total_seat;

	printf("\n ***** ENJOY THE MOVIE ***** \n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tCost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);


	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("FIlE not Found");
	}
	else
	{
		fprintf(ufp,"\n\nName : %s\nSeats : %d\nAmount : %d\nMovie : %s\nPrice : %d\n",name,total_seat,total_amount,b.name,b.cost);
		printf("\n\n Record inserted sucessfully!");
	}
		printf("\n");

	fclose(ufp);
	fclose(fp);

}



void old_record() //for view old records of users who booked tickets previously.
{
	char ch;
	FILE *fp;


	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{
		while( ( ch = fgetc(fp) ) != EOF )
      	printf("%c",ch);
	}
	fclose(fp);
}