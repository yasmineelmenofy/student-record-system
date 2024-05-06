/**
***************************************************************
@file        memory_management.h
@version     1.0.0
@brief       memory management module.
@details     this file contains the memory management module which responsible for add or delete data from memory
@author      Mahmoud Ramzy Behilk.
@Created     on April 30, 2024, 6:42 PM
***************************************************************
*/

#ifndef _MEMORY_MANAGEMENT_H
#define _MEMORY_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char cGender[10];
    float fTotal_Grade;
    unsigned int nUnique_Id;
    unsigned int nAge;
    struct student_t* sNext;
    char *cName;
    char *cPassword;

}student_t;

        /**================  Basic Functions  =================**/

/*
 * Breif : This function used to add student at the beginning of the linked list
 * Parameters : Double pointer to linked list head
 * return : void
 */
void MMM_vAddStudentAtFrist(student_t** head); // Insert_Frist_Node


/*
 * Breif : This function used to delete specific student by his ID
 * Parameters : Double pointer to linked list head
 * return : void
 */
void MMM_vDeleteSpecificStudent(student_t** head);

#endif // _MEMORY_MANAGEMENT_H