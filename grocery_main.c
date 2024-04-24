#include <stdio.h>
#include <stdlib.h>
#include "grocery_header.h"
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

int main()
{
    item = (struct Item *)malloc(10 * sizeof(struct Item));
    customer = (struct Customer *)malloc(10 * sizeof(struct Customer));

    item[0] = (struct Item){"Books", 60, 20};
    item[1] = (struct Item){"Bottle", 75, 50};
    item[2] = (struct Item){"Pens", 10, 30};
    item[3] = (struct Item){"Brush", 30, 10};
    item[4] = (struct Item){"Soap", 20, 20};

customer[0] = (struct Customer){"Rajesh", "9486726543", "232"};
    customer[1] = (struct Customer){"Rahul", "7492546186", "233"};
    customer[2] = (struct Customer){"Sameer", "8694142390", "234"};
    customer[3] = (struct Customer){"Ajay", "9446514235", "235"};
    customer[4] = (struct Customer){"Akshay", "9875562341", "236"};
    int c;

    while(c!=5)
    {
        printf("What do you like to do :\n 1.Item entry\n 2.Costumer entry\n 3.Edit Item\n 4.Compute and Print Bill\n 5.Quit\n\n");
        printf("Enter your option- ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                item_entry();
                break;
            }
            case 2:
            {
                customer_entry();
                break;
            }
            case 3:
            {
                edit_item();
                break;
            }
            case 4:
            {
                billing();
                break;
            }
            case 5:
            {
                printf("Thank You!\n Visit Again!\n\n");
                break;
            }
            default:
            {
                printf("Invalid Option! \nTry Again\n\n");
                break;
            }
        }
    }
     free(item);
    free(customer);
    return 0;
}
