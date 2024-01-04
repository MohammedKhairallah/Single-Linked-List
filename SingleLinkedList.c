/* 
 * File:   SingleLinkedList.c
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 31, 2023, 8:54 PM
 */
#include "SingleLinkedList.h"

/*
   This function Insert_Node_At_Beginning is responsible for inserting a new node at the beginning of a linked list.
   It takes a double pointer to the head of the linked list (NodeHead) and a pointer to generic data (Data) as input.

   Parameters:
   - NodeHead: A double pointer to the head of the linked list where the new node is to be inserted.
   - Data: A void pointer to generic data that needs to be stored in the new node.

   Return value:
   - NodeStatus_t: It returns a NodeStatus_t value, which indicates the status of the insertion operation.

   Explanation of the function:
   - NodeStatus_t: An enumeration representing different statuses related to node operations (NODE_NOK, NODE_OK, NODE_EMPTY, NODE_NULL_POINTER).
   - uint32_t *_Data: A pointer to an unsigned 32-bit integer, obtained by casting the void pointer Data.

   Algorithm:
   - The function first initializes the status variable as NODE_NOK (indicating an unsuccessful operation).
   - It then checks for NULL pointers in the input parameters (NodeHead and Data). If any pointer is NULL, it sets status as NODE_NULL_POINTER.
   - If the pointers are valid, the function dynamically allocates memory for a new node (NodeList) using malloc().
   - If memory allocation fails (NodeList is NULL), the status is set as NODE_NOK.
   - Otherwise, if the linked list is empty (NodeHead points to NULL), the new node becomes the head of the list.
   - If the list is not empty, the new node is inserted at the beginning of the list, and the head is updated accordingly.
   - The data passed (pointed by Data) is assigned to the NodeData member of the new node.
   - Finally, the function returns the status indicating the success or failure of the insertion operation.
*/
NodeStatus_t Insert_Node_At_Beginning(Node_t **NodeHead, void *Data){
    NodeStatus_t status = NODE_NOK;  // Initialize status as NODE_NOK
    uint32_t *_Data = Data;  // Cast the void pointer Data to uint32_t pointer

    /* Check for NULL pointers in the input parameters */
    if((NULL == NodeHead||(NULL == Data))){
        status = NODE_NULL_POINTER;  // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        Node_t *NodeList = NULL;  

        // Allocate memory for a new node
        NodeList = (Node_t *)malloc(sizeof(Node_t));

        if(NULL == NodeList){  // Check if memory allocation failed
            status = NODE_NOK; // Set status as NODE_NOK if memory allocation failed
        }
        else{
            if(NULL == *NodeHead){ /* If the linked list is empty */
                *NodeHead = NodeList; // The new node becomes the head of the list
                NodeList->NodeData = *_Data; // Assign the data to the NodeData of the new node
                NodeList->NodeLink = NULL;  // Set the NodeLink of the new node to NULL
            }
            else{
                NodeList->NodeLink = *NodeHead;  // Link the new node to the existing list
                NodeList->NodeData = *_Data;  // Assign the data to the NodeData of the new node
                *NodeHead = NodeList;  // Update the head to point to the new node
            }
            status = NODE_OK;
        }
    }
    return status; // Return the status indicating the success or failure of the insertion operation
}

/*
   This function Insert_Node_At_End is responsible for inserting a new node at the end of a linked list.
   It takes a double pointer to the head of the linked list (NodeHead) and a pointer to generic data (Data) as input.

   Parameters:
   - NodeHead: A double pointer to the head of the linked list where the new node is to be inserted.
   - Data: A void pointer to generic data that needs to be stored in the new node.

   Return value:
   - NodeStatus_t: It returns a NodeStatus_t value, which indicates the status of the insertion operation.

   Explanation of the function:
   - NodeStatus_t: An enumeration representing different statuses related to node operations (NODE_NOK, NODE_OK, NODE_EMPTY, NODE_NULL_POINTER).
   - uint32_t *_Data: A pointer to an unsigned 32-bit integer, obtained by casting the void pointer Data.

   Algorithm:
   - The function first initializes the status variable as NODE_NOK (indicating an unsuccessful operation).
   - It then checks for NULL pointers in the input parameters (NodeHead and Data). If any pointer is NULL, it sets status as NODE_NULL_POINTER.
   - If the pointers are valid, the function dynamically allocates memory for a new node (NodeList) using malloc().
   - If memory allocation fails (NodeList is NULL), the status is set as NODE_NOK.
   - Otherwise, if the linked list is empty (NodeHead points to NULL), the new node becomes the head of the list.
   - If the list is not empty, the function traverses the list to find the last node and inserts the new node at the end.
   - The data passed (pointed by Data) is assigned to the NodeData member of the new node.
   - Finally, the function returns the status indicating the success or failure of the insertion operation.
*/
NodeStatus_t Insert_Node_At_End(Node_t **NodeHead, void *Data){
    NodeStatus_t status = NODE_NOK;
    uint32_t *_Data = Data;  // Cast the void pointer Data to uint32_t pointer

    /* Check for NULL pointers in the input parameters */
    if((NULL == NodeHead||(NULL == Data))){
        status = NODE_NULL_POINTER;  // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        Node_t *NodeList = NULL;

        // Allocate memory for a new node
        NodeList = (Node_t *)malloc(sizeof(Node_t));

        if(NULL == NodeList){ // Check if memory allocation failed
            status = NODE_NOK;  // Set status as NODE_NOK if memory allocation failed
        }
        else{
            if(NULL == *NodeHead){ /* If the linked list is empty */
                *NodeHead = NodeList; // The new node becomes the head of the list
                NodeList->NodeData = *_Data;  // Assign the data to the NodeData of the new node
                NodeList->NodeLink = NULL;  // Set the NodeLink of the new node to 
            }
            else{
                NodeList->NodeData = *_Data;  // Assign the data to the NodeData of the new node
                NodeList->NodeLink = NULL;    // Set the NodeLink of the new node to NULL

                // Create a copy of the head pointer to traverse the list
                struct Node *NodeHeadCopy = *NodeHead;

                // Traverse to find the last node in the list
                while (NULL != (NodeHeadCopy->NodeLink))
                {
                    NodeHeadCopy = NodeHeadCopy->NodeLink;
                }

                // Insert the new node at the end of the list
                NodeHeadCopy->NodeLink = NodeList;
            }
            status = NODE_OK;
        }
    }
    return status;
}

/*
   This function Insert_Node_After is responsible for inserting a new node after a specific position in a linked list.
   It takes a double pointer to the head of the linked list (NodeHead), a position (NodePosition), and a pointer to generic data (Data) as input.

   Parameters:
   - NodeHead: A double pointer to the head of the linked list where the new node is to be inserted.
   - NodePosition: The position after which the new node needs to be inserted.
   - Data: A void pointer to generic data that needs to be stored in the new node.

   Return value:
   - NodeStatus_t: It returns a NodeStatus_t value, which indicates the status of the insertion operation.

   Explanation of the function:
   - NodeStatus_t: An enumeration representing different statuses related to node operations (NODE_NOK, NODE_OK, NODE_EMPTY, NODE_NULL_POINTER).
   - uint32_t *_Data: A pointer to an unsigned 32-bit integer, obtained by casting the void pointer Data.
   - uint16_t NodeCounter: A counter to keep track of the number of nodes in the linked list.
   - uint16_t counter: A counter variable used for iteration.

   Algorithm:
   - The function first initializes the status variable as NODE_NOK (indicating an unsuccessful operation).
   - It checks for NULL pointers in the input parameters (NodeHead and Data). If any pointer is NULL, it sets status as NODE_NULL_POINTER.
   - If the pointers are valid, the function dynamically allocates memory for a new node (NodeList) using malloc().
   - If memory allocation fails (NodeList is NULL), the status is set as NODE_NOK.
   - If the linked list is empty, the new node becomes the head of the list.
   - Otherwise, if the NodePosition is within a valid range, the function finds the node at the specified position and inserts the new node after it.
   - The data passed (pointed by Data) is assigned to the NodeData member of the new node.
   - Finally, the function returns the status indicating the success or failure of the insertion operation.
*/
NodeStatus_t Insert_Node_After(Node_t **NodeHead, uint16_t NodePosition, void *Data){
    NodeStatus_t status = NODE_NOK;
    uint32_t *_Data = Data;    // Cast the void pointer Data to uint32_t pointer
    uint16_t NodeCounter = 0;  // Initialize NodeCounter to keep track of node count
    uint16_t counter = 1;      // Initialize counter for iteration

    /* Check for NULL pointers in the input parameters */
    if((NULL == NodeHead)||(NULL == Data)){
        status = NODE_NULL_POINTER;  // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        Node_t *NodeList = NULL;

        // Allocate memory for a new node
        NodeList = (Node_t *)malloc(sizeof(Node_t));

        if(NULL == NodeList){ // Check if memory allocation failed
            status = NODE_NOK;  // Set status as NODE_NOK if memory allocation fails
        }
        else{
            if(NULL == *NodeHead){  /* If the linked list is empty */
                *NodeHead = NodeList;  // The new node becomes the head of the list
                NodeList->NodeData = *_Data;  // Assign the data to the NodeData of the new node
                NodeList->NodeLink = NULL;   // Set the NodeLink of the new node to NULL
                status = NODE_OK;
            }
            else{
                NodeList->NodeData = *_Data;  // Assign the data to the NodeData of the new node
                Get_Length(NodeHead, &NodeCounter);  // Get the length of the linked list

                if((0 != NodePosition)&&(NodePosition <= NodeCounter)){
                    struct Node *NodeHeadCopy = *NodeHead;

                    // Traverse to find the node at NodePosition
                    while (counter < NodePosition)
                    {
                        NodeHeadCopy = NodeHeadCopy->NodeLink;
                        counter++;
                    }

                    /* Connect the right side connection */
                    NodeList->NodeLink = NodeHeadCopy->NodeLink;
                    /* Connect the Left side connection */
                    NodeHeadCopy->NodeLink = NodeList;
                    status = NODE_OK;
                }
                else{
                    status = NODE_NOK;
                    free(NodeList);  // Free the memory allocated for the new node
                }
            }
        }
    }
    return status;
}

/*
   This function Delete_Node_At_Beginning is responsible for deleting the node at the beginning of a linked list.
   It takes a double pointer to the head of the linked list (NodeHead) as input.

   Parameters:
   - NodeHead: A double pointer to the head of the linked list from which the node at the beginning is to be deleted.

   Return value:
   - NodeStatus_t: It returns a NodeStatus_t value, which indicates the status of the deletion operation.

   Explanation of the function:
   - NodeStatus_t: An enumeration representing different statuses related to node operations (NODE_NOK, NODE_OK, NODE_EMPTY, NODE_NULL_POINTER).

   Algorithm:
   - The function first initializes the status variable as NODE_NOK (indicating an unsuccessful operation).
   - It checks for NULL pointers in the input parameters (NodeHead). If NodeHead is NULL, it sets status as NODE_NULL_POINTER.
   - If the NodeHead pointer is valid:
     - If the linked list is empty (NodeHead points to NULL), the function sets the status as NODE_EMPTY.
     - If the list is not empty, the function deletes the node at the beginning of the list:
       - It creates a temporary copy of the head pointer (NodeHeadCopy).
       - Updates the head pointer to point to the next node in the list.
       - Sets the NodeLink of the removed node to NULL (detaching it from the list).
       - Frees the memory allocated for the removed node.
   - Finally, the function returns the status indicating the success or failure of the deletion operation.
*/
NodeStatus_t Delete_Node_At_Beginning(Node_t **NodeHead){
    NodeStatus_t status = NODE_NOK;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER;  // Set status as NODE_NULL_POINTER if NodeHead is NULL
    }
    else{
        if(NULL == *NodeHead){ /* if the linked list is empty */
            status = NODE_EMPTY;
        }
        else{
            // Create a temporary copy of the head pointer
            struct Node *NodeHeadCopy = *NodeHead; 

            *NodeHead = NodeHeadCopy->NodeLink; // Update the head pointer to the next node
            NodeHeadCopy->NodeLink = NULL; // Set the NodeLink of the removed node to NULL (detach it from the list)
            free(NodeHeadCopy); // Free the memory allocated for the removed node
            status = NODE_OK;  // Set status as NODE_OK indicating successful deletion
        }
    }
    return status;
}

/*
   This function, Delete_Node, is responsible for deleting a node from a specified position in a linked list.
   It takes a double pointer to the head of the linked list (NodeHead) and the position of the node to be deleted (NodePosition).

   Parameters:
   - NodeHead: A double pointer to the head of the linked list from which the node will be deleted.
   - NodePosition: An unsigned 16-bit integer representing the position of the node to be deleted.

   Return value:
   - NodeStatus_t: It returns a NodeStatus_t value, indicating the status of the operation (NODE_NOK, NODE_OK, NODE_NULL_POINTER).

   Explanation of the function:
   - NodeStatus_t: An enumeration representing different statuses related to node operations.
   - struct Node *NextNode: A pointer to a Node structure used to store the next node after the node to be deleted.
   - uint16_t NodeCounter: An unsigned 16-bit integer to keep track of the node count in the linked list.
   - uint16_t counter: An unsigned 16-bit integer used for iteration within the function.

   Algorithm:
   - The function initializes the status variable as NODE_NOK, indicating an unsuccessful operation.
   - It checks for a NULL pointer in the input parameter NodeHead. If NodeHead is NULL, it sets status as NODE_NULL_POINTER.
   - If NodeHead is valid:
        - If the NodePosition is 1 (indicating the first node):
            - It calls the Delete_Node_At_Beginning function to delete the first node.
        - If the NodePosition is other than 1:
            - It retrieves the length of the linked list using Get_Length function.
            - If the specified position (NodePosition) is valid and within the range:
                - It traverses the list to find the node before the one to be deleted.
                - It updates pointers to detach the node to be deleted from the linked list.
                - It frees the memory allocated for the deleted node.
            - If the specified position is invalid or out of range:
                - It sets status as NODE_NOK, indicating an unsuccessful operation.
   - The function returns the status indicating the success or failure of the operation.
*/

NodeStatus_t Delete_Node(Node_t **NodeHead, uint16_t NodePosition){
    NodeStatus_t status = NODE_NOK;
    struct Node *RemovedNode = NULL;
    uint16_t NodeCounter = 0;  // Initialize NodeCounter to keep track of node count
    uint16_t counter = 1;  // Initialize counter for iteration

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER;  // Set status as NODE_NULL_POINTER if NodeHead is NULL
    }
    else{
        if(1 == NodePosition){
            status = Delete_Node_At_Beginning(NodeHead);
        }
        else{
            // Get the length of the linked list using Get_Length function
            Get_Length(NodeHead, &NodeCounter);

            if((0 != NodePosition)&&(NodePosition <= NodeCounter)){
                struct Node *NodeHeadCopy = *NodeHead;  // Create a temporary copy of the head pointer

                // Traverse to find the node at NodePosition
                while (counter < (NodePosition - 1))
                {
                    NodeHeadCopy = NodeHeadCopy->NodeLink;
                    counter++;
                }

                RemovedNode = NodeHeadCopy->NodeLink;  
                NodeHeadCopy->NodeLink = RemovedNode->NodeLink;  
                free(RemovedNode); // Free the memory allocated for the removed node
                status = NODE_OK;  // Set status as NODE_OK indicating successful deletion
            }
            else{
                status = NODE_NOK;  // Set status as NODE_NOK if NodePosition is out of range or zero
            }
        }
        
    }
    return status;
}

/*
   This function Display_All_Nodes is responsible for displaying the data of all nodes in a linked list.
   It takes a pointer to the head of the linked list (NodeHead) as input.

   Parameters:
   - NodeHead: A pointer to the head of the linked list whose node data needs to be displayed.

   Return value:
   - NodeStatus_t: It returns a NodeStatus_t value, which indicates the status of the display operation.

   Explanation of the function:
   - NodeStatus_t: An enumeration representing different statuses related to node operations (NODE_NOK, NODE_OK, NODE_NULL_POINTER).
   - Node_t *NodeHeadcopy: A pointer used to iterate through the linked list without modifying the original head pointer.

   Algorithm:
   - The function first initializes the status variable as NODE_NOK (indicating an unsuccessful operation).
   - It checks for a NULL pointer in the input parameter (NodeHead). If NodeHead is NULL, it sets status as NODE_NULL_POINTER.
   - If the NodeHead pointer is valid:
     - It creates a temporary copy of the head pointer (NodeHeadcopy).
     - It traverses the linked list using a while loop and displays the data of each node until it reaches the end (NodeLink becomes NULL).
     - It prints "NULL" after the last node to indicate the end of the linked list.
     - Finally, it sets the status as NODE_OK indicating a successful display operation.
   - The function returns the status indicating the success or failure of the display operation.
*/
NodeStatus_t Display_All_Nodes(Node_t *NodeHead){
    NodeStatus_t status = NODE_NOK;
    Node_t *NodeHeadcopy = NodeHead;  // Create a temporary copy of the head pointer

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER;  // Set status as NODE_NULL_POINTER if NodeHead is NULL
    }
    else{
        while(NodeHeadcopy != NULL){
            printf("%i -> ", NodeHeadcopy->NodeData);  // Display the node data
            NodeHeadcopy = NodeHeadcopy->NodeLink;  // Move to the next node
        }
        if(NULL == NodeHeadcopy){
            printf("NULL \n");  // Print "NULL" to indicate the end of the linked list
        }
        status = NODE_OK; // Set status as NODE_OK indicating successful display
    }
    return status;
}

/*
   This function Get_Length is responsible for determining the length (number of nodes) of a linked list.
   It takes a double pointer to the head of the linked list (NodeHead) and a pointer to an unsigned 16-bit integer (Length) as input.

   Parameters:
   - NodeHead: A double pointer to the head of the linked list whose length needs to be determined.
   - Length: A pointer to an unsigned 16-bit integer where the length of the linked list will be stored.

   Return value:
   - NodeStatus_t: It returns a NodeStatus_t value, which indicates the status of the operation (NODE_NOK, NODE_OK, NODE_NULL_POINTER).

   Explanation of the function:
   - NodeStatus_t: An enumeration representing different statuses related to node operations.
   - uint16_t l_Length: A local variable to calculate and store the length of the linked list.

   Algorithm:
   - The function first initializes the status variable as NODE_NOK (indicating an unsuccessful operation).
   - It checks for NULL pointers in the input parameters (NodeHead and Length). If any pointer is NULL, it sets status as NODE_NULL_POINTER.
   - If both pointers are valid:
     - It creates a temporary copy of the head pointer (NodeHeadCopy).
     - It traverses the linked list using a while loop and counts the number of nodes until it reaches the end (NodeLink becomes NULL).
     - It stores the calculated length in the variable Length using the pointer.
     - Finally, it sets the status as NODE_OK indicating a successful length calculation operation.
   - The function returns the status indicating the success or failure of the operation.
*/
NodeStatus_t Get_Length(Node_t **NodeHead, uint16_t *Length){
    NodeStatus_t status = NODE_NOK;
    uint16_t l_Length = 0; // Local variable to store the length of the linked list

    /* Check for NULL pointers in the input parameters */
    if((NULL == NodeHead)||(NULL == Length)){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        struct Node *NodeHeadCopy = *NodeHead;  // Create a temporary copy of the head pointer

        while (NULL != NodeHeadCopy)
        {
            NodeHeadCopy = NodeHeadCopy->NodeLink;  // Move to the next node
            l_Length++; // Increment the length counter
        }
        *Length = l_Length;  // Store the calculated length in the provided Length variable using the pointer
        status = NODE_OK;
    }
    return status;
}