#include "grocery2_header.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct Item {
    char name[50];
    float price;
    int quantity;
};

struct Customer {
    char name[50];
    char phone[11];
    char id[5];
};

struct Item *item;
struct Customer *customer;
int count =5;
void item_entry()
{  
    printf("----------------ITEM ENTRY------------------\n");
    if(count<=10){
    printf("Enter the name of item you want to add\n ");
    scanf("%s",&item[count].name);
    printf("Enter the cost of the item\n ");
    scanf("%f",&item[count].price);
    printf("Enter the number of item available in stock\n");
    scanf("%d",&item[count].quantity);
    printf("Item added successfully\n");
    count++;
    }
    else{
        printf("Maximum count reached");
    }
}

void customer_entry()
{
     printf("----------------CUSTOMER ENTRY------------------\n");
    if(count<=5){
    printf("Enter the name of customer you want to add\n ");
    scanf("%s",&customer[count].name);
    printf("Enter the id of customer\n ");
    scanf("%d",&customer[count].id);
    printf("Enter the phone number of the customer\n ");
    scanf("%s",&customer[count].phone);
    printf("Customer added successfully\n");
    }
    else{
        printf("Maximum count reached");
    }
}

void edit_item() 
{
    int index;
    for(int i = 0; i < count; i++) {
        printf("%d)%s---%.2f---%d\n", i + 1, item[i].name, item[i].price, item[i].quantity);
    }
    printf("Enter the item number you want to edit : ");
    scanf("%d", &index);

    if (index > 0 && index <= count) {
        printf("Enter new item name: ");
        scanf("%s", item[index-1].name);
        printf("Enter new item price: ");
        scanf("%f", &item[index-1].price);
        printf("Enter new item quantity: ");
        scanf("%d", &item[index-1].quantity);
    } 
    else {
        printf("Invalid item index.\n");
    }
}

void billing()
{
    struct purchase 
    {
        char nam[50];
        int quant;
    } New[10];
    char name[20];
    printf("Enter your name- ");
    scanf("%s",&name);
    int o = 0;
    char c;
    int quantity;
    int t = 0;
    int item_num;
    do 
    {
    printf("Items available are\n");
    printf("NAME---PRICE---IN STOCK\n");
    for(int i = 0; i < count; i++) {
        printf("%d)%s---%.2f---%d\n", i + 1, item[i].name, item[i].price, item[i].quantity);
    }

    printf("Enter c to Continue and q to Quit\n");
    c = getch();
   
     if(c == 'q') break;
        if(c == 'c') 
        {
        printf("Enter the item number you want to purchase: ");
        scanf("%d", &item_num);

        if (item_num < 1 || item_num > count) {
            printf("Invalid item number.\n");
            continue;
        }
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        strcpy(New[o].nam, item[item_num - 1].name); 
        New[o].quant = quantity; 
        o++;
        if (quantity <= item[item_num - 1].quantity) {
            item[item_num - 1].quantity -= quantity; 
            printf("Purchase successful.\n");
            t++;
        } else {
            printf("Item out of stock.\n");
        }
    }
    }while (c != 'q');

    printf("Do you want to print the bill (y/n)\n");
    char C = getch();
    if (C == 'y') {
        printf("-------Grocery Shop--------\n");
        printf("Name:%s\n",name);
        printf("ITEM NAME\tQUANTITY\tRATE\t\tTOTAL\n");
        float gst = 0.08;
        float grand = 0;
        for (int i = 0; i < t; i++) {
            float itemTotal = item[item_num - 1].price * New[i].quant; 
            printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", New[i].nam, New[i].quant, item[item_num - 1].price, itemTotal);
            grand += itemTotal;
        }
        printf("\nTOTAL=\t%.2f\n", grand);
        printf("GST(8%%)=\t%.2f\n", gst * grand);
        printf("GRAND TOTAL=\t%.2f\n", grand + (gst * grand));
    }
}