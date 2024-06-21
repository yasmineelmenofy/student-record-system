/**
***************************************************************
@file        menu.h
@version     1.0.0
@brief       menu module.
@details     this file contains functions to display the main menu to the user and allow the user
             to select the desired mode.
@author      Mahmoud Ramzy Behilk.administration
@Created     on May 12, 2024, 8:17 PM
***************************************************************
*/

#ifndef _MENU_H
#define _MENU_H

#include <stdbool.h>
#include "authentication.h"
#include "student.h"
#include "admin.h"

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

/*
 * Breif : This function used to display the main menu to the user
 * Parameters :  Pointer to linked list head
 * return : void
 */
void MM_vMenuDisplay(student_t* sHead);

#endif // _MENU_H
