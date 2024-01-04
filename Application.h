/* 
 * File:   Application.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 31, 2023, 8:54 PM
 */
#ifndef _APPLICATION_H
#define _APPLICATION_H

/* Section : Includes */
#include <windows.h>
#include "SingleLinkedList.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data type Declarations */

Node_t *NodeHead_1 = NULL;   /* initially there are no nodes */
uint16_t LengthNode_1 ;      /* Variable for user input for length of the linked list*/
uint8_t UserChoice ;         /* Variable for user choices */
uint8_t displaycount;        /* Variable to count the display of dots while waiting */
uint16_t NodePos;            /* Variable for user input for position of the linked list*/
uint32_t data1 ;             /* Variable for user input for data of the linked list */

/* Section : Functions Declaration */


#endif  //_APPLICATION_H