//definition file for car rental application

#include"car.h"//haeder file

int code1;
int logins=0;
int kms,days,week;
struct owner *head,*temp,*tail;//creating a linked list for storing user information

//function for creating a new node for saving car details 
void create()
{
    temp=(struct owner *)malloc(sizeof(struct owner));
    
    printf("Enter the car code:");
    scanf("%d",&temp->car_code);
    
    printf("Enter the car name :");
    scanf("%s",temp->car_name);
    
    printf("Enter the rent per day : ");
    scanf("%d",&temp->rent);
    
    printf("Enter the place : ");
    scanf("%s",temp->place);
}

//function to save car details as list
void creation()
{
    int choice=1;
    head=0;
    while(choice)
    {
        create();//calling create function to create node
        temp->next=0;
        
        //if list is empty
        if(head==0)
        {
            head=tail=temp;
        }
        
        //if list is not empty
        else
        {
            tail->next=temp;
            tail=temp;
        }
        
        //if you want to add more cars
        printf("\n\nDo you want to continue (0 for no / 1 for yes)");
        scanf("%d",&choice);
    }
    printf("\n\n");
}

//function to display car information
void display()
{
    
    temp=head;
    
    //if list is empty
    if(temp == 0)
    {
        printf("list is empty");
    }
    
    //if list is not empty
    else
    {
        printf("Car code\tCarName \t Rentprice \t Place \n");
        
    	//display cars
    	while(temp!=0)
    	{
    	    printf("%d\t\t %s \t\t %d \t\t %s\n",temp->car_code,temp->car_name,temp->rent,temp->place);
    	    temp=temp->next;
    	}
    }
    printf("\n\n");
}

//function to update car details
void update()
{
    struct owner *temp1=head;
    int code;
    printf("Enter the car code where you want to update : ");
    scanf("%d",&code);
    while(temp1!=0)
    {
        if(temp1->car_code == code)
        {
            printf("\n*Enter the car details*\n\n");
            printf("Enter the car name : ");
            scanf("%s",temp1->car_name);
            printf("Enter the rent : ");
            scanf("%d",&temp1->rent);
            printf("Enter the place : ");
            scanf("%s",temp1->place);
            printf("\n UPDATED CAR DETAILS IS : \n");
            printf("Car code :%d \nCar name : %s \nCar rent :%d \nCar place : %s \n",temp1->car_code,temp1->car_name,temp1->rent,temp1->place);
        }
        temp1=temp1->next;
    }
    printf("\nUPDATED SUCCESSFULLY!!!\n");
}

//function to rent a car
void selection()
{
    
    int kms,days,week;
    struct owner *temp2=head;
    printf("Enter the car code to select : \n");
    display();
    scanf("%d",&code1);
    while(temp2!=0)
    {
        if(temp2->car_code == code1)
        {
            printf("Car name : %s \n Car rent per day  : %d \n Cestination place : %s\n",temp2->car_name,temp2->rent,temp2->place);
        }
    temp2=temp2->next;
    }
    printf("\n\n");
}

//function to calculate to rent amount to be paid
void amount()
{
    struct owner *temp3=head;
    int rent2=0;
    
    printf("\nFOR EVERY ONE EXTRA KILOMETERS, RS.30 WILL BE ADDED !!!\n");
    
    printf("If you want to travel extra km , enter the approxiamate kms (if not press 0): \n");
    scanf("%d",&kms);
    
    printf("\nTHE ABOVE RENT PRICE IS FOR ONE DAY!!!\n");
    printf("For how many days you want car : \n");
    scanf("%d",&days);
    
    printf("\nIF YOU RENT CAR FOR WEEKENDS THE PRICE WILL INCREASED BY RS.1000!!!\n");
    printf("Do you want car in weekends(press 1 for yes , (or) 0 for no : \n");
    scanf("%d",&week);
    
    while(temp3!=0)
    {
        if(temp3->car_code == code1)
        {
            rent2 += temp3->rent * days;
           if(kms!=0)
           {
               rent2 += kms*30;
           }
           if(week==1)
           {
               rent2 += 1000;
           } 
        }
    temp3=temp3->next;
    }
    printf("\nTOTAL AMOUNT FOR THE CAR YOU SELECTED IS  : %d\n\n\n ",rent2);
}

//function to enter login details 
void login()
{
	
    char username[50],password[20];
    FILE *log;
    log=fopen("login12.txt","r");
    struct login l;
    printf("USERID : ");
    scanf("%s",username);
    printf("PASSWORD : ");
    scanf("%s",password);
    
    while(fread(&l,sizeof(l),1,log))
    {
    	//if entered username is same as saved username and password
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            logins++;
            printf("\nSUCCESSFULLY LOGGED IN !!!\n\n");}
        else
        {
            printf("\nERROR...INCORRECT USERNAME OR PASSWORD! PLEASE ENTER CORRECT VALUE!!!\n");
        }
    }
    fclose(log);
}

//function to register new customer and saving it in a file
void register_fun()
{
	//saving information in a file
	FILE *log;
    log=fopen("login12.txt","w");
    struct login l;
    
    /*storing fisrtname, lastname, password in file*/
    printf("Enter the first name : \n");
    scanf("%s",l.fname);
    
    printf("Enter the username : \n");
    scanf("%s",l.username);
    
    printf("Enter the password : \n");
    scanf("%s",l.password);
    
    fwrite(&l,sizeof(l),1,log);
    
    fclose(log);
    
    printf("\n\nyour USERNAME is your USERID \n");
    printf("Now login with USERID and PASSWORD\n\n");
    
    login();
}
