//header file for car rental application
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//login function: it has first name, user name(of user's choice), password
struct login
{
    char fname[50];
    char username[50];
    char password[50];
};

//owner function: it has car code, rent, car name, place
struct owner
{
    int car_code;
    char car_name[25];
    int rent;
    char place[30];
    struct owner *next;
};

//functions
void create();//create node
void creation();//adding owner details
void display();//showing car details
void update();//updating car details
void selection();//renting car
void amount();//calculating amount to be paid by user
void login();//login in function
void register_fun();//registering new user
