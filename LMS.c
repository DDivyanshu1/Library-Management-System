#include <stdio.h>
#include <strings.h> 
#include <string.h>
 

struct checkout_date
{
    int date,month,year;                  
};

struct return_date
{
    int date,month,year;                    
};

struct student_details
{
    char name[20],address[50];
    long phone;
    struct checkout_date CHDATE[15];
    struct return_date REDATE[15];                 
};

struct book_details
{
    long book_no;
    char book_title[30],author[15];
    char publisher[30];
    int year_of_publication;
    char subject[15];
    struct student_details Studdet[100];
    int status;
}BOOK[2700];

int Choice,b,i=0,n=0;

int operation()                             
{
        printf("\t\t\t\tWELCOME TO ANSPRIN LIBRARY!");
         printf("\n----------------------------------------------------------------------------------------\n\n");
          printf("\t\t\t\tMENU");
          printf("\n---------------------------------------------------------------------------------------\n");
          printf("PRESS 1.TO ADD NEW BOOKS");
          printf("\nPRESS 2.TO SEARCH THE LIBRARY BY BOOK NUMBER, AUTHOR, TITLE, SUBJECT");
          printf("\nPRESS 3.TO REMOVE OUTDATED BOOKS (ALL BOOKS OLDER THAN 15 YEARS)");
          printf("\nPRESS 4.TO CHECKOUT BOOKS");
          printf("\nPRESS 5.TO RETURN BOOKS");
          printf("\nPRESS 6.TO EXIT");
          printf("\n---------------------------------------------------------------------------------------\n");
          printf("Enter Your Choice: ");
          scanf("%d",&Choice);
    return Choice;
}

int add_book()                             
{
    printf("Enter the following details:\n");
    printf("Book Number: ");   
    scanf("%ld",&BOOK[i].book_no);
    printf("Book Title: ");               
    scanf(" %[^\n]%*c",BOOK[i].book_title);
    printf("Author: ");              
    scanf(" %[^\n]%*c",BOOK[i].author);
    printf("Publisher: ");          
    scanf(" %[^\n]%*c",BOOK[i].publisher);
    printf("Year of Publication: ");    
    scanf("%d",&BOOK[i].year_of_publication);
    printf("Subject: ");           
    scanf(" %[^\n]%*c",BOOK[i].subject);
    printf("Available!!!\n"); 
    BOOK[i].status=1;
    i++;
}

void search_book_number()                           
{
    long num;
    printf("Enter the book number: ");   
    scanf("%ld",&num);
    for(int j=0;j<=i;j++)
    {
        if(num==BOOK[j].book_no)
        {
                printf("Deetails:\n");
                printf("Book Number: %ld",BOOK[j].book_no);
                printf("\nBook Title: %s",BOOK[j].book_title);
                printf("\nAuthor: %s",BOOK[j].author);
                printf("\nPublisher: %s",BOOK[j].publisher);
                printf("\nYear of Publiaction: %d",BOOK[j].year_of_publication);
                printf("\nSubject: %s\n",BOOK[j].subject);
                if(BOOK[j].status==2)
                {
                    printf("Unavailable(Issued by someone).\n");
                }
                else if(BOOK[j].status==3)
                {
                    printf("Unavailable(The book is outdated).\n");
                }
                else if(BOOK[j].status==1)
                {
                    printf("Available!!!\n");
                } 
                break;
        }
    }
}

void search_author()
{
    char auth[15];
    int r=-1;
    printf("Enter the name of author: ");    
    scanf(" %[^\n]%*c",auth);
    for(int j=0;j<=i;j++)
    {
        r=strcmp(auth,BOOK[j].subject);
        if(r==0)
        {
            printf("Here are the details:\n");
            printf("Book Number: %ld",BOOK[j].book_no);
            printf("\nBook Title: %s",BOOK[j].book_title);
            printf("\nAuthor: %s",BOOK[j].author);
            printf("\nPublisher: %s",BOOK[j].publisher);
            printf("\nYear of Publication: %d",BOOK[j].year_of_publication);
            printf("\nSubject: %s",BOOK[j].subject);
            if(BOOK[j].status==2)
            {printf("\nUnavailable(Issued by someone).");}
            else if(BOOK[j].status==3)
            {printf("\nUnavailable(The book is outdated).\n");}
            else if(BOOK[j].status==1)
            {printf("Available!!!\n");}
            break;
        }
    }
}

void search_title()                             
{
    char title[20];
    int r=-1;
    printf("Please enter the Book Title: ");       
    scanf(" %[^\n]%*c",title);
    for(int j=0;j<=i;j++)
    {
        r=strcmp(title,BOOK[j].subject);
        if(r==0)
        {
            printf("Here are the details:\n");
            printf("Book Number: %ld",BOOK[j].book_no);
            printf("\nBook Title: %s",BOOK[j].book_title);
            printf("\nAuthor: %s",BOOK[j].author);
            printf("\nPublisher: %s",BOOK[j].publisher);
            printf("\nYear of Publiaction: %d",BOOK[j].year_of_publication);
            printf("\nSubject: %s\n",BOOK[j].subject);
            if(BOOK[j].status==2)
            {printf("Unavailable(Issued by someone0.\n");}
            else if(BOOK[j].status==3)
            {printf("Unavailable(The book is outdated)!\n");}
            else if(BOOK[j].status==1)
            {printf("Available!!!\n");}
            break;
        }
    }
}

void search_subject()
{
    char sub[20];
    int r=-1;
    printf("Enter the subject: ");  
    scanf(" %[^\n]%*c",sub);
    for(int j=0;j<=i;j++)
    {
        r=strcmp(sub,BOOK[j].subject);
        if(r==0)
        {
            printf("Here are the details:\n");
            printf("Book Number: %ld",BOOK[j].book_no);
            printf("\nBook Title: %s",BOOK[j].book_title);
            printf("\nAuthor: %s",BOOK[j].author);
            printf("\nPublisher: %s",BOOK[j].publisher);
            printf("\nYear of Publiaction: %d",BOOK[j].year_of_publication);
            printf("\nSubject: %s",BOOK[j].subject);
            if(BOOK[j].status==2)
            {printf("\nUnavailable(Issued by someone).\n");}
            else if(BOOK[j].status==3)
            {printf("Unavailable(The book is outdated)!\n");}
            else if(BOOK[j].status==1)
            {
            printf("Available!!!\n");}
            break;
        }
    }
}

void search_keywords()      
{
    char key[15];
    printf("Please enter the keyword: ");        
    scanf("%s",key);
    int r=-1,t=-1,s=-1,p=-1;
    for(int j=0;j<=i;j++)
    {
        for (char *p1 = strtok(BOOK[j].book_title," "); p1 != '\0'; p1 = strtok(NULL, " "))        
        {
            t=strcmp(p1,key);
            if(t==0)
            {
            printf("Here are the details:\n");
            printf("Book Number: %ld",BOOK[j].book_no);
            printf("\nBook Title: %s",BOOK[j].book_title);
            printf("\nAuthor: %s",BOOK[j].author);
            printf("\nPublisher: %s",BOOK[j].publisher);
            printf("\nYear of Publiaction: %d",BOOK[j].year_of_publication);
            printf("\nSubject: %s",BOOK[j].subject);
            if(BOOK[j].status==2)
            {printf("\nUnavailable(Issued by someone).\n");}
            else if(BOOK[j].status==3)
            {printf("Unavailable(The book is outdated)!\n");}
            else if(BOOK[j].status==1)
            {printf("Available!!!\n");}
            }
        }
        
        for (char *p2 = strtok(BOOK[j].author," "); p2 != '\0'; p2 = strtok(NULL, " "))
        {
            r=strcmp(p2,key);
            if(r==0)
            {
            printf("Here are the details:\n");
            printf("Book Number: %ld",BOOK[j].book_no);
            printf("\nBook Title: %s",BOOK[j].book_title);
            printf("\nAuthor: %s",BOOK[j].author);
            printf("\nPublisher: %s",BOOK[j].publisher);
            printf("\nYear of Publiaction: %d",BOOK[j].year_of_publication);
            printf("\nSubject: %s",BOOK[j].subject);
            if(BOOK[j].status==2)
            {printf("\nUnavailable(Issued by someone).\n");}
            else if(BOOK[j].status==3)
            {printf("Unavailable(The book is outdated)!\n");}
            else if(BOOK[j].status==1)
            {printf("Available!!!\n");}
            }
        }
        
        for (char *p3 = strtok(BOOK[j].publisher," "); p3 != '\0'; p3 = strtok(NULL, " "))
        {
            p=strcmp(p3,key);
            if(p==0)
            {
            printf("Here are the details:\n");
            printf("Book Number: %ld",BOOK[j].book_no);
            printf("\nBook Title: %s",BOOK[j].book_title);
            printf("\nAuthor: %s",BOOK[j].author);
            printf("\nPublisher: %s",BOOK[j].publisher);
            printf("\nYear of Publiaction: %d",BOOK[j].year_of_publication);
            printf("\nSubject: %s",BOOK[j].subject);
            if(BOOK[j].status==2)
            {printf("\nUnavailable(Issued by someone).\n");}
            else if(BOOK[j].status==3)
            {printf("Unavailable(The book is outdated)!\n");}
            else if(BOOK[j].status==1)
            {printf("Available!!!\n");}
            }
        }
        
        for (char *p4 = strtok(BOOK[j].subject," "); p4 != '\0'; p4 = strtok(NULL, " "))
        {
            s=strcmp(p4,key);
            if(s==0)
            {
            printf("Details:\n");
            printf("Book Number: %ld",BOOK[j].book_no);
            printf("\nBook Title: %s",BOOK[j].book_title);
            printf("\nAuthor: %s",BOOK[j].author);
            printf("\nPublisher: %s",BOOK[j].publisher);
            printf("\nYear of Publiaction: %d",BOOK[j].year_of_publication);
            printf("\nSubject: %s",BOOK[j].subject);
            if(BOOK[j].status==2)
            {printf("\nUnavailable(Issued by someone).\n");}
            else if(BOOK[j].status==3)
            {printf("Unavailable(The book is outdated)!\n");}
            else if(BOOK[j].status==1)
            {printf("Available!!!\n");}
            }
        }
    }
    
}

void search()
{
    printf("Search the library by :\n1 = Book number\n2 = Author\n3 = Title\n4 = Subject\n5 = Keywords\n");
    scanf("%d",&b);
    switch(b)
    {
        case 1:
        search_book_number();
        break;
        case 2:
        search_author();
        break;
        case 3:
        search_title();
        break;
        case 4:
        search_subject();
        break;
        case 5:
        search_keywords();
        break;
        default:
        break;
    }
}

void remove_outdated_books()                //checked
{
    int z;
    printf("Current year: ");      scanf("%d",&z);
    z=z-15;
    int book_found=0;
    for(int j=0;j<i;j++)
    {
        if ((BOOK[j].year_of_publication!=0) && (BOOK[j].year_of_publication<z))
        {
            BOOK[j].status=3;
            book_found=1;
            printf("\nThe Book %s j= %d is outdated.\n",BOOK[j].book_title,j);
            }
    }
    if (book_found==0)
     printf("No book found\n");
        
}

void Checkout_books()                       
{
    long num;
    printf("Please enter the Book Number: ");        scanf("%ld",&num);
    for(int j=0;j<=i;j++)
    {
        if(num==BOOK[j].book_no)
        {
            if(BOOK[j].status==2 || BOOK[j].status==3)
            {
                printf("Sorry, This book is unavailable.\n");
            }
            else if(BOOK[j].status==1)
            {
                printf("Please enter the following: \n");
                printf("Name: ");       scanf(" %[^\n]%*c",BOOK[j].Studdet[n].name);                 
                printf("Address: ");  scanf(" %[^\n]%*c",BOOK[j].Studdet[n].address);             
                printf("Phone: ");    scanf("%ld",&BOOK[j].Studdet[n].phone);
                printf("Checkout details: \n");
                printf("Date: ");     scanf("%d",&BOOK[j].Studdet[n].CHDATE[n].date);
                printf("Month: ");    scanf("%d",&BOOK[j].Studdet[n].CHDATE[n].month);
                printf("Year: ");     scanf("%d",&BOOK[j].Studdet[n].CHDATE[n].year);
                printf("Return details: \n");
                printf("Date: ");     scanf("%d",&BOOK[j].Studdet[n].REDATE[n].date);
                printf("Month: ");    scanf("%d",&BOOK[j].Studdet[n].REDATE[n].month);
                printf("Year: ");     scanf("%d",&BOOK[j].Studdet[n].REDATE[n].year);             
                printf("Book issued successfully by: %s\n",BOOK[j].Studdet[n].name);
                BOOK[j].status=2;
                n++;
            }
        }
    }
}
void return_books()                         
{
    char name[20];int r;
    printf("Please enter your name: ");     
    scanf("%s",name);
    for(int j=0;j<=i;j++)
    {
        for(int k=0;k<=n;k++)
        {
            r=strcmp(name,BOOK[j].Studdet[k].name);
            if(r==0)
            {
                printf("Book details: \nBook Number: %ld",BOOK[j].book_no);
                printf("\nBook Title: %s",BOOK[j].book_title);
                printf("\nAuthor: %s",BOOK[j].author);
                printf("\nPublished by: \nName: %s",BOOK[j].Studdet[k].name);                 
                printf("\nAddress: %s",BOOK[j].Studdet[k].address);             
                printf("\nPhone: %ld",BOOK[j].Studdet[k].phone);
                printf("\nThis book is returned successfully!");
                BOOK[j].status=1;
                break;
            }
        }
    }                                                                           
}

void logo(){
    
    printf("                                                                              \n");
    printf("                ___________________________________________________________   \n");
    printf("                ||-------------------------------------------------------||   \n");
    printf("                ||.--.    .-._                        .----.             ||   \n");
    printf("                |||==|____| |H|___            .---.___|''''|_____.--.___ ||   \n");
    printf("                |||  |====| | |xxx|_          |+++|=-=|_  _|-=+=-|==|---|||   \n");
    printf("                |||==|    | | |   | \           |   |   |_\/_|Black|  | ^ |||   \n");
    printf("                |||  |    | | |   |\ \      .--. |   |=-=|_/\_|-=+=-|  | ^ |||   \n");
    printf("                |||  |    | | |   |_\ \_( oo )|     |   |    |Magus|  | ^ |||   \n");
    printf("                |||==|====| |H|xxx|  \ \ |''|   |+++|=-=|''''|-=+=-|==|---|||   \n");
    printf("                ||`--^----'-^-^---'   `-' ''  '---^---^----^-----^--^---^||   \n");
    printf("                ||-------------------------------------------------------||   \n");
    printf("                ||-------------------------------------------------------||   \n");
    printf("                ||               ___                   .-.__.-----. .---.||   \n");
    printf("                ||              |===| .---.   __   .---| |XX|<(*)>|_|^^^|||   \n");
    printf("                ||         ,  /(|   |_|III|__|''|__|:x:|=|  |     |=| Q |||   \n");
    printf("                ||      _a'{ / (|===|+|   |++|  |==|   | |  |Illum| | R |||   \n");
    printf("                ||        '// _(|===|-|   |  |''|  |:x:|=|  |inati| | Y |||   \n");
    printf("                ||_____   -\{___(|   |-|   |  |  |  |   | |  |     | | Z |||   \n");
    printf("                ||       _(____)|===|+|[I]|DK|''|==|:x:|=|XX|<(*)>|=|^^^|||   \n");
    printf("                ||              `---^-^---^--^--'--^---^-^--^-----^-^---^||   \n");
    printf("                ||-------------------------------------------------------||   \n");
    printf("                ||_______________________________________________________||   \n\n\n\n");

}



int main()
{


    logo();
    start:
    Choice=operation();
    switch(Choice)
    {
        case 1:
        add_book();
        break;
        case 2:
        search();
        break;
        case 3:
        remove_outdated_books();
        break;
        case 4:
        Checkout_books();
        break;
        case 5:
        return_books();
        break;
        case 6:
        goto end;
        break;
        default:;
    }
    goto start;
    
    end:
    printf("THANKS FOR VISITING,!!");
    return 0;
}
