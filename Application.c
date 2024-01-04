/* 
 * File:   Application.c
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 31, 2023, 8:54 PM
 */

/*
   This program implements a menu-driven application for single linked list operations.
   Users can perform various operations like insertion, deletion, display, and length retrieval on the linked list.

   Explanation of the program:
   - The main function begins by displaying a loading message and a greeting for the Single Linked List application.
   - It then enters an infinite loop to continuously display the menu of options using the instructions() function.
   - Users can select various options such as:
        1. Insert an element at the beginning of the linked list.
        2. Insert an element at the end of the linked list.
        3. Insert an element after a specific position in the linked list.
        4. Display all nodes in the linked list.
        5. Get the length of the linked list.
        6. Delete a node from the linked list at a specific position.
        7. Delete a node from the beginning of the linked list.
        8. Quit the application.
   - It uses various linked list manipulation functions such as Insert_Node_At_Beginning, Insert_Node_At_End, Insert_Node_After,
     Display_All_Nodes, Get_Length, Delete_Node, and Delete_Node_At_Beginning based on the user's choice.
   - The instructions() function displays the menu of available options to the user.

*/
#include "Application.h"

void instructions( void );  // Function to Displays a menu of available options to the user

int main(){
    printf("please wait");
    while(displaycount < 5){
        printf(".");
        Sleep(250);  // Delay for 250 milliseconds (for Windows)
        displaycount++;
    }
    puts("\nHello to Single Linked List \n");

    while (1)
    {  // Infinite loop for menu-driven operations
        instructions();  // Display menu of options
        scanf("%i", &UserChoice); // Get user choice
        printf("\n");

        switch(UserChoice){  // Perform operations based on user choice
            case 1:
                printf("please enter the data : ");
                scanf("%i", &data1);
                printf("\n");
                Insert_Node_At_Beginning(&NodeHead_1, &data1);
                break;
            case 2:
                printf("please enter the data : ");
                scanf("%i", &data1);
                printf("\n");
                Insert_Node_At_End(&NodeHead_1, &data1);
                break;
            case 3:
                printf("please enter the data : ");
                scanf("%i", &data1);
                printf("\n");
                puts("Note : The first postion = 1 \n"
                     "please enter postion of the node :  ");
                scanf("%i", &NodePos);
                printf("\n");
                Insert_Node_After(&NodeHead_1, NodePos, &data1);
                break;
            case 4:
                Display_All_Nodes(NodeHead_1);
                printf("\n");
                break;
            case 5:
                Get_Length(&NodeHead_1, &LengthNode_1);
                printf("List Length : << %i >> Nodes\n\n", LengthNode_1);
                break;
            case 6:
                puts("Note : The first postion = 1 \n"
                     "please enter postion of the node :  ");
                scanf("%i", &NodePos);
                printf("\n");
                Delete_Node(&NodeHead_1, NodePos);
                break;
            case 7:
                Delete_Node_At_Beginning(&NodeHead_1);
                break;
            case 8:
                printf("Quit from application \n\n");
                exit(1); // Exit the application
                break;
            default:
                printf("User Choice out of range !!\n\n");
                break;
        }
    }
    return 0;
}

/* Function to Displays a menu of available options to the user */
void instructions( void )
{
    puts( "Enter your choice:\n"
          " 1 to insert an element at the beginning of the linked list.\n"
          " 2 to insert an element at the end of the linked list.\n"
          " 3 to insert an element after a specific position in a linked list.\n"
          " 4 to Display all nodes.\n"
          " 5 to get the length.\n"
          " 6 to delete node from the linked list.\n"
          " 7 to delete node from the beginning.\n"
          " 8 to end." );
    printf("UserChoice : ");
} 