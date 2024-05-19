#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "grocery3_header.h"
struct Item {
    char id[5];
    char name[50];
    float price;
    int quantity;
};
struct Customer {
    char id[5];
    char name[50];
    char phone[11];
};
struct Item *item;
struct Customer *customer;
    FILE *fpi;
    FILE *fpc;

int main()
{
    printf("\1WELCOME\2");
    item = malloc(sizeof(struct Item) * 1000);
    customer = malloc(sizeof(struct Customer)* 1000);
    fpi=fopen("items.csv","a+");
    fpc=fopen("customer.csv","a+");
    if(fpi==NULL)
    {
        printf("Error in opening file\n ");
    }
    if(fpc==NULL)
    {
        printf("Error in opening file\n ");
    }

     char ch;
     ch = fgetc(fpi);
    while(ch!='\n')
    {
    ch=fgetc(fpi);
    }
    char ch1;
    ch1 = fgetc(fpc);
    while(ch1!='\n')
    {
    ch1=fgetc(fpc);
    }

    int icount=0;
char line[256];
    while (fgets(line, sizeof(line), fpi)) {
        char *token = strtok(line, ",");
        strcpy(item[icount].id, token);
        token = strtok(NULL, ",");
        strcpy(item[icount].name, token);
        token = strtok(NULL, ",");
        item[icount].price = atof(token);
        token = strtok(NULL, ",");
        item[icount].quantity = atoi(token);
        icount++;
    }

        int ccount=0;
char lin[256];
    while (fgets(lin, sizeof(lin), fpc)) {
        char *token = strtok(lin, ",");
        strcpy(customer[ccount].id, token);
        token = strtok(NULL, ",");
        strcpy(customer[ccount].name, token);
        token = strtok(NULL, ",");
        strcpy(customer[ccount].phone, token);
        ccount++;
    }

    int choice;
    while(choice!=5)
    {
        printf("What do you like to do :\n 1.Item entry\n 2.Costumer entry\n 3.Edit Item\n 4.Compute and Print Bill\n 5.Quit\n\n");
        printf("Enter your option- ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                item_entry(fpi);
                break;}
            case 2:{
                customer_entry(fpc);
                break;}
            case 3:{
                edit_item(icount);
                break;}
            case 4:{
                billing(icount);
                break;}
            case 5:{
                printf("\nThank You!\2\n Visit Again!\1\n\n");
                break;}
            default:{
                printf("\nInvalid Option! \nTry Again\n\n");
                break;}
        }
    }
       free(item);
       free(customer);
       fclose(fpi);
       fclose(fpc);
}