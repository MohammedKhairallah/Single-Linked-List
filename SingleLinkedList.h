/* 
 * File:   SingleLinkedList.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 31, 2023, 8:54 PM
 */
#ifndef _SINGLELINKEDLIST_H
#define _SINGLELINKEDLIST_H

/* Section : Includes */
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h" 

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data type Declarations */

/* 
   This typedef enum represents different statuses related to node operations.
   It contains the following enumerators:

   Explanation of enumerators:
   - NODE_NOK: Represents a status where a node operation was not performed successfully.
   - NODE_OK: Represents a status indicating that a node operation was performed successfully.
   - NODE_EMPTY: Represents a status denoting that a node is empty (contains no data or no valid content).
   - NODE_NULL_POINTER: Represents a status when a NULL pointer is passed to the Node.

   NodeStatus_t is an alias for this enumeration, and it can be used to conveniently denote and manage different statuses related to node operations within a program.
*/
typedef enum{
    NODE_NOK = 0,      /* Node operation not performed successfully */
    NODE_OK,           /* Node operation performed successfully  */  
    NODE_EMPTY,        /* Node is empty */
    NODE_NULL_POINTER  /* NULL pointer passed to the Node */
}NodeStatus_t; 

/* 
   This typedef struct represents a node in a linked list.
   It contains two members:
   - NodeData: an unsigned 32-bit integer to store data.
   - NodeLink: a pointer to the next node in the linked list.
   Node_t is an alias for the struct Node.

   Explanation of members:
   - NodeData: Holds the data value within the node, represented as an unsigned 32-bit integer.
   - NodeLink: Holds a pointer to the next node in the linked list. It points to another Node_t (struct Node), 
               allowing the creation of a linked sequence of nodes.
*/
typedef struct Node{
    uint32_t NodeData;      /* Stores an unsigned 32-bit integer data in the node */
    struct Node *NodeLink;  /* pointer to next node */
}Node_t; /* end structure Node */


/* Section : Functions Declaration */

NodeStatus_t Insert_Node_At_Beginning(Node_t **NodeHead, void *Data);
NodeStatus_t Insert_Node_At_End(Node_t **NodeHead, void *Data);
NodeStatus_t Insert_Node_After(Node_t **NodeHead, uint16_t NodePosition, void *Data);
NodeStatus_t Delete_Node_At_Beginning(Node_t **List);
NodeStatus_t Delete_Node(Node_t **NodeHead, uint16_t NodePosition);
NodeStatus_t Display_All_Nodes(Node_t *List);
NodeStatus_t Get_Length(Node_t **NodeHead, uint16_t *Length);

#endif  //_SINGLELINKEDLIST_H