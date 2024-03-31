#include "grocery_header.h"
#include <stdio.h>
#include <conio.h>
    // int r=10,c=25;
    char item_name[10][25]={"Books","Bottle","Pens","Brush","Soap"};
    float item_cost[10]={60,100,10,30,20};
    char item_id[10][5]={"111","112","113","114","115"};
    int stock[10]={20,100,30,10,20};
    char customer_name[10][20]={"Rajesh","Rahul","Sameer","Ajay","Akshay"};
    char phone[10][11]={"9486726543","7492546186","8694142390","9446514235","9875562341"};
    char customer_id[10][5]={"232","233","234","235","236"};
    int count=5;
    char new_item_name[10][50];
    int new_item_quantity[10];

    void item_entry()
{  
    printf("----------------ITEM ENTRY------------------\n");
    if(count<=10){
    printf("Enter the name of item you want to add\n ");
    scanf("%s",&item_name[count]);
    printf("Enter the cost of the item\n ");
    scanf("%f",&item_cost[count]);
    printf("Enter the id of item\n ");
    scanf("%s",&item_id[count]);
    printf("Enter the number of item available in stock\n");
    scanf("%d",&stock[count]);
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
    scanf("%s",&customer_name[count]);
    printf("Enter the phone number of the customer\n ");
    scanf("%s",&phone[count]);
    printf("Enter the id of customer\n ");
    scanf("%d",&customer_id[count]);
    printf("Customer added successfully\n");
    }
    else{
        printf("Maximum count reached");
    }
}

void billing()
{
    char name[20];
    // float C[10];
    int Q[10];
    printf("Enter your name- ");
    scanf("%s",&name);
    int t=0;
    char c;
    float total = 0;
    int item_num;
    int N[10];
    int quantity;
    do 
    {
        printf("Items available are\n");
        printf("NAME---PRICE---IN STOCK\n");
        for(int i=0;i<count;i++)
        {
            printf("%d)%s---%.2f---%d\n",i+1,item_name[i],item_cost[i],stock[i]);
        }
        
        printf("Enter c to continue and q to quit\n");
        c=getch();
            
        if(c == 'q') break;
        if(c == 'c') 
        {
            t++;
            printf("Enter the item number you want to purchase: ");
            scanf("%d", &item_num);
            if(item_num < 1 || item_num > count)
            {
                printf("Invalid item number.\n");
                continue;
            }
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            
            if(quantity <= stock[item_num - 1])
            {
                float cost = item_cost[item_num - 1] * quantity;
                for(int u=t;u<=t;u++)
                {
                    N[u-1]=item_num-1;
                    Q[u-1]=quantity;
                }
                stock[item_num - 1] -= quantity;
                printf("Purchase successful.\n");
                total += cost;
            }
            else 
            {
                printf("Item out of stock.\n");
            }
        }
    } while (c != 'q');

    printf("Do you want to print the bill (y/n)");
    char C=getch();
    if(C=='y')
    {
        printf("-------Grocery Shop--------\n");
        printf("Name- %s\n", name);
        printf("ITEM NAME\tQUANTITY\tRATE\t\tTOTAL\n");
        float gst=0.08;
        float grand=0;
        for(int i = 0; i < t; i++) 
        {
            float itemTotal = item_cost[N[i]] * Q[i]; // Calculate total cost for each item
            printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", item_name[N[i]], Q[i], item_cost[N[i]], itemTotal);
            grand+=itemTotal;
        }     
        printf("\nTOTAL=\t%.2f\n",grand);
        printf("GST(8 percent)=\t%.2f\n",gst*grand);
        printf("GRAND TOTAL=\t%.2f\n",grand+(gst*grand));
    }
}
