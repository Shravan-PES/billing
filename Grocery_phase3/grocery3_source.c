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
void item_entry()
{
    char name[50],id[15];
    float price;
    int quantity;
    printf("----------------ITEM ENTRY------------------\n");
    printf("Enter the id of the item you want to add\n ");
    scanf("%s",&id);
    printf("Enter the name of item you want to add\n ");
    scanf("%s",&name);
    printf("Enter the cost of the item\n ");
    scanf("%f",&price);
    printf("Enter the number of item available in stock\n");
    scanf("%d",&quantity);
    fprintf(fpi,"%s,%s,%.2f,%d\n",id,name,price,quantity);
fclose(fpi);
    printf("Item added successfully\n");
    addtoistruct();
    }

    void customer_entry()
    {
        char name[50],phone[11],id[15];
        printf("----------------CUSTOMER ENTRY------------------\n");
        printf("Enter the id of customer\n ");
        scanf("%s",&id);
        printf("Enter the name of customer you want to add\n ");
        scanf("%s",&name);
        printf("Enter the phone number of the customer\n ");
        scanf("%s",&phone);
        fprintf(fpc,"%s,%s,%s\n",id,name,phone);
    fclose(fpc);
        printf("Customer added successfully\n");
        void addtocstruct();
    }



void edit_item(int count) 
{
    int index;
    printf("ID\tNAME\tPRICE\tQuantity\n");
    for(int i = 0; i < count; i++) {
        printf("%d)%s---%s---%.2f---%d\n", i + 1,item[i].id, item[i].name, item[i].price, item[i].quantity);
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
        FILE *file = fopen("items.csv", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    fprintf(file,"ID,NAME,COST,INSTOCK\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%.2f,%d\n", item[i].id, item[i].name, item[i].price, item[i].quantity);
    }

    fclose(file);
    } 
    else {
        printf("Invalid item number entered.\n");
    }

}

    void billing(int count)
{
    struct purchase 
    {
        char nam[50];
        int quant;
    } New[10];
    char name[20];
    printf("Enter your name- ");
    scanf("%s",&name);
    FILE *f=fopen("customer.csv","a+");
    if (!f) {
        printf("Could not open file for writing.\n");
        return;
    }
    char line[500];
    int customer_exists = 0;
    
    while (fgets(line, sizeof(line), f)) {
        char *tok = strtok(line, ",");
        tok=strtok(NULL,",");
        if (tok != NULL && strcmp(tok, name) == 0) {
            customer_exists = 1;
            break;
        }
    }  
    if (customer_exists) {
        printf("Customer exists. Proceeding with billing.\n");
    } else {
        printf("Customer does not exist.\n");
        char name[50],phone[11],id[15];
        printf("----------------CUSTOMER ENTRY------------------\n");
        printf("Enter the id of customer\n ");
        scanf("%s",&id);
        printf("Enter the name of customer you want to add\n ");
        scanf("%s",&name);
        printf("Enter the phone number of the customer\n ");
        scanf("%s",&phone);
        fprintf(f,"%s,%s,%s\n",id,name,phone);
    fclose(f);
        printf("Customer added successfully\n");
    }

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

void addtoistruct()
{
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
}
void addtocstruct()
{
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
}
