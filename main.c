//client code for car rental application

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"car.h"//header file

//main code
int main()
{
	int code1;
	int logins=0;
	int kms,days,week;
	struct owner *head,*temp,*tail;//creating a linked list for storing user information
	
    int choice1,choice2,choice3;
    printf("*CAR RENTAL APPLICATION*\n");
    printf("**************************************************************************************************************");
    char car[50];
    int num,rent1,place1;
    struct owner *temp2=head;
    //options to login as owner, customer or close the application
    
    do//start of do-while loop
    {
    	printf("\nSELECT THE OPTION: \n 1) Enter as owner  \n 2) Enter as customer \n 3) Exit\n");
    	scanf("%d",&choice1);
		
    	switch(choice1)//start of switch
    	{
        	case 1://login as owner
            {
                
                do
                {
                    printf("\nSELECT THE OPTION : \n 1) Enter car data \n 2) Update details \n 3) Display car \n 4) Exit\n");
                    scanf("%d",&choice2);// options to enter, update and display car data
                    switch(choice2)
                    {
                        case 1://add new car information
                            creation();
                        	break;
                        case 2://update car details
                            update();
                            break;
                        case 3://display car data
                        	display();
                        	break;
                    }
                }while(choice2!=4);
            }
            break;
            
        	case 2:// login as customer
        	{
        		do//start of do-while loop
        		{
		        	printf("WELCOME !!!\n\n");
		        	printf("**CUSTOMER MENU**\n\n");
		            printf("\nSELECT THE OPTION : \n 1)New Registration  \n 2)Rent Car\n 3)Total amount \n 4)exit\n");
		            scanf("%d",&choice3);
		            switch(choice3)//start of switch
		            {
		            	case 1://registration for new customer
		                	register_fun();//register function
		                    break;
		               	case 2://renting a car
		               	{
		                	if(logins!=0)
		                    {
		                    	selection();//rent function
		                    }
		                    else  
		                    	printf("\n\nYOU'RE NOT A REGISTERED USER . PLEASE REGISTER TO CONTINUE.\n\n");
		                }
		                    break;
		                case 3://calculate amount to be paid by the customer
		                    amount();//payment option
		                    break;
		            }//end of switch
            	}while(choice3!=4);//end of do-while loop
        	}
        	break;
    	}
    }while(choice1!=3);//end of do-while loop and exit
}
