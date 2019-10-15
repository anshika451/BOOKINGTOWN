#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<conio.h>

#include<windows.h>



struct date

{

    int day;

    int month;

    int year;

};

struct time

{

    int hr;

    int min;

};

struct movie

{

    char movie[30];

    char theatre[40];

    struct date d;

    struct time t;

    int audi;

    float cost;


    struct movie* right;

    struct movie* down;

};

struct movie *start;

void insertmoviedetails()

{


char c;
    char ch;

    struct movie* n,* temp,* p;

    do

    {

        n=(struct movie*)malloc(sizeof(struct movie));

        printf("\n\n\nEnter Movie Name: ");

fflush(stdin);

        gets (n->movie);

        printf("\nEnter Theatre Name: ");

        gets(n->theatre);

        printf("\nEnter Audi No.: ");

        scanf("%d",&n->audi);

        printf("\nEnter DATE of movie: \n");

        scanf("%d%d%d",&n->d.day,&n->d.month,&n->d.year);

        printf("\nEnter Time in hrs & min: \n");

        scanf("%d%d",&n->t.hr,&n->t.min);

        fflush(stdin);
        printf("\nEnter Cost per Ticket: ");

        scanf("%f",&n->cost);



        n->right=NULL;

        n->down=NULL;

        if(start==NULL)

        {

            start=n;

            temp=n;

        }

        else

        {

            temp=start;

            while(temp!=NULL)

            {

                p=temp;

                if(strcmp(p->movie,n->movie)==0)

                {

                    temp=temp->down;

                }

                else if(strcmp(p->movie,n->movie)!=0)

                {

                    temp=temp->right;

                }

            }

            if(strcmp(p->movie,n->movie)==0)

            {

                p->down=n;

            }

            else if(strcmp(p->movie,n->movie)!=0)

            {

                p->right=n;

            }

        }
        printf("enter another movie? y/n");
         fflush(stdin);

        scanf("%c",&c);



              } while(c=='y');
if(c=='n')

       {

       printf("\nPress any key to Continue");

       getch();

       system("cls");

       }



   }

void booktickets()

{



    char ch[30],ch1[40];

    int day,month,year,hrs,min,audi,seats;

    int g,s,tickets;

    g=1;

    s=0;

    printf("\n\nEnter movie name: ");
fflush(stdin);



    gets(ch);

    struct movie *temp,*temp1;

    temp=start;

    while(temp!=NULL)

    {

       if(strcmp(temp->movie,ch)==0&&g==1)

       {

           g++;

           printf("\nEnter theatre name: ");

           gets(ch1);

           temp1=temp;

           while(temp1!=NULL)

           {

               if(strcmp(temp1->theatre,ch1)==0)

               {

                   printf("\nRECORD ");

                   s++;

                   printf(" %d\n\n",s);

                   printf("DATE : %d-%d-%d",temp1->d.day,temp1->d.month,temp1->d.year);

                   printf("\tTIME : %d:%d",temp1->t.hr,temp1->t.min);

                   printf("\tAUDI : %d",temp1->audi);

                   printf("\tCOST : %f",temp1->cost);

                                      temp1=temp1->down;

               }

               else

               {

                   temp1=temp1->down;

               }

           }

               if(s==0)

               {

                   printf("\n\a\nNo such movie is there in this theatre\n\n");

               }

               else

               {

                   temp1=temp;

                   printf("\n\nEnter rest of the details:\n\nDATE(day,month,year) : \n");

                   scanf("%d%d%d",&day,&month,&year);

                   printf("\n\nTIME(hrs,min) : \n");

                   scanf("%d%d",&hrs,&min);

                   while(temp1!=NULL)

                   {

                       if(strcmp(temp1->theatre,ch1)==0&&temp1->d.day==day&&temp1->d.month==month&&temp1->d.year==year&&temp1->t.hr==hrs&&temp1->t.min==min)

                       {





                           printf("\n\nHow many tickets? ");

                           scanf("%d",&tickets);

                           generateticket(temp1,tickets);



                       }

                       else

                       {

                           printf("\nRecords not found.\n");

                       }

                       temp1=temp1->down;

                   }

               }

               temp=temp->right;

           }



       else

       {

           temp=temp->right;

       }

    }

    if(g==1)

    {

        printf("\n\n\aNo such movie is there in the records.");
printf("\n\n\nPress any key to continue.");

        getch();

        system("cls");



        }

}

void displaymoviedetails()

{



    int g=1;

    struct movie* temp,*temp1;

    temp=start;

    while(temp!=NULL)

    {

        printf("\nRECORD : %d ",g);

        printf("\n");

        g++;

        temp1=temp;

        printf("\nMovie name: %s",temp->movie);

        while(temp1!=NULL)

        {

            printf("\nTheatre Name: %s",temp1->theatre);

            printf("\nDate: %d-%d-%d",temp1->d.day,temp1->d.month,temp1->d.year);

            printf("\nTime: %d:%d",temp1->t.hr,temp1->t.min);

            printf("\nAudi No.: %d",temp1->audi);

            printf("\nCost per Ticket: %f",temp->cost);

                     temp1=temp1->down;

        }

        temp=temp->right;

    }

    if(g==1)

    {

        printf("\n\aERROR::No records are there to be displayed\n");

    }
printf("\n\n\nPress any key to continue.");

        getch();

        system("cls");



    }

void searchviamovie()

{
char ch[10];

    int g=1;

    printf("\n\nEnter Movie Name: ");

    fflush(stdin);

    gets(ch);

    struct movie* temp,*temp1;

    temp=start;

    while(temp!=NULL)

    {

        temp1=temp;

        while(temp1!=NULL)

        {

            if(strcmp(temp->movie,ch)==0)

            {

                printf("\n    Record %d\n",g);

                g++;

                printf("\nTheatre Name: %s",temp1->theatre);

                printf("\nDate: %d-%d-%d",temp1->d.day,temp1->d.month,temp1->d.year);

                printf("\nTime: %d:%d",temp1->t.hr,temp1->t.min);

                printf("\nAudi: %d",temp1->audi);

                printf("\nCost: %f",temp1->cost);

                temp1=temp1->down;

            }

            else

            {

                temp1=temp1->down;

            }

        }

        temp=temp->right;

    }

    if(g==1)

    {

        printf("\n\a\nNo such records are present.");

    }

printf("\n\n\nPress any key to continue.");

        getch();

        system("cls");



}

void generateticket(struct movie* temp1,int t)

{printf("\n\n\nPress any key to continue.");

        getch();

        system("cls");



    float co=(temp1->cost)*t;

    int i,j,k;

    char ch[20],c,d;

    printf("\nEnter your name : ");

fflush(stdin);

    gets(ch);

     printf("\nWANT TO PREBOOK REFRESHMENTS.....(enter 'y' else 'n'):  ");

    scanf("%c",&c);

    if(c=='y')

    {

        printf("\n");

        printf("MENU CARD\n");

        printf("\nPOPCORN : small @ Rs. 100\t\t\t(enter '1') \n\t: tub @ Rs. 300\t\t\t\t(enter '2')\n");

        printf("\nCOLD-DRINKS : 200 ml @ Rs. 100\t\t\t(enter '3') \n\t: 300 ml @ Rs. 150\t\t\t(enter '4') \n\t: 400 ml @ Rs. 220\t\t\t(enter '5')\n");

        printf("\nCOMBOS : nachaos+cold drink @ Rs. 300\t\t(enter '6')\n\t: nachos+popcorn+cold drink @ Rs. 500\t(enter '7')\n");

        printf("\n");



        do

        {

        printf("\nEnter your refreshments:");

        scanf("%d",&k);

        switch(k)

        {

            case 1:co=co+100;

                   break;

            case 2:co=co+300;

                   break;

            case 3:co=co+100;

                   break;

            case 4:co=co+150;

                   break;

            case 5:co=co+220;

                   break;

            case 6:co=co+300;

                   break;

            case 7:co=co+500;

                   break;

            default:printf("wrong choice\n");



        }

        printf("Want to add more refreshments?(y/n)");

        scanf("%c",&d);

        }while(d=='y');

    }



    printf("\nGENERATING TICKET.....");

    printf("\n\t\t\t NO OF TICKETS : %d",t);

    printf("\n\t\t\t MOVIE NAME: %s",temp1->movie);

    printf("\n\t\t\t THEATRE NAME: %s",temp1->theatre);

    printf("\n\t\t\t DATE: %d-%d-%d",temp1->d.day,temp1->d.month,temp1->d.year);

    printf("\n\t\t\t TIME: %d:%d",temp1->t.hr,temp1->t.min);

    printf("\n\t\t\t AUDI: %d",temp1->audi);

    printf("\n\t\t\t COST of ticket+refreshments: %f",co);

    printf("\n\t\t\tTHANK YOU :) ");
printf("\n\n\nPress any key to continue.");

        getch();

        system("cls");



    }





int *password()

{char p[10];
printf("enter password");

scanf("%s",&p);

   if(strcmp(p,"xyz")==0)

  {

      return 1;

  }

  else

  return 0;

}

void main()

{



    int i,j,k,l;

    start=NULL;

    do

    {





              printf("\n\n\t\t\t\t\t\t\t\t****HELLO! WELCOME TO BOOKINGTOWN****\n\n");

              printf("\nPress<1> : If you are an admin\n\n");

        printf("     <2> : If you are a guest\n\n");
        printf("     <3> : Exit\n\n");

        printf("\nEnter your choice: \n");

        scanf("%d",&i);

        if(i==1)

        {

            printf("\nEnter password: ");

            l=password();

            if(l==1)

            {

                    printf("\n\n\t\t\t\t\t\t\t\tPress<1> : Enter records");

                printf("\n\n\t\t\t\t\t\t\t\t     <2> : See all records");

                scanf("%d",&j);

                switch(j)

                {

                    case 1:insertmoviedetails();

                           break;

                    case 2:displaymoviedetails();

                           break;



                    default: printf("\n\nWRONG CHOICE.");

                            }

            }

            else

            {



                 printf("\nWrong Password");

                }



        }

        else if(i!=1&&i!=2&&i!=3)

        {

            printf("\n\nWRONG CHOICE.");

            }

        else if(i==2)

        {

        printf("\n\n\n\n\t\t\t\t\t\t\t\tPress<1> : Book ticket(s)");

        printf("\n\n\t\t\t\t\t\t\t\tPress<2> : See all records");

        printf("\n\n\t\t\t\t\t\t\t\tPress<3> : Search  movie details");

        printf("\n\n\n\t\t\t\t\t\t\t\tEnter your choice: ");

        scanf("%d",&j);



        switch(j)

        {

            case 1:booktickets();

                   break;

            case 2:displaymoviedetails();

                   break;

            case 3:searchviamovie();

                   break;

            default: printf("\n\nWRONG CHOICE.");

                     }

        }

        else if(i==3)

        {

            exit(2);

        }

    }while(j!=3);

}
