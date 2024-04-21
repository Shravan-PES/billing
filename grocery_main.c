#include "grocery_header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;

    while(c!=4)
    {
        printf("What do you like to do:\n 1.Item entry\n 2.Costumer entry\n 3.Compute and Print Bill\n 4.Quit\n\n");
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
    return 0;
}
