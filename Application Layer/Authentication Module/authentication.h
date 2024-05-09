/**
***************************************************************
@file        authentication.h
@version     1.0.0
@brief       authentication module.
@details     this file contains functions to check the username and password entered by the
             ser and determine whether the user is an admin or a student
@author      Mahmoud Ramzy Behilk.administration
@Created     on May 6, 2024, 6:19 PM
***************************************************************
*/

#ifndef _AUTHENTICATION_H
#define _AUTHENTICATION_H

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
 * Breif : This function used to check in Student ID and password
 * Parameters : Pointer to linked list head
 * return : void
 */
void AM_vStudentChecking(student_t* sHead);

/*
 * Breif : This function used to check in the user password
 * Parameters : void
 * return : void
 */
void AM_vUserChecking(void);

/*
 * Breif : This function used to determine who is the user (Admin or Student)
 * Parameters : Pointer to linked list head
 * return : void
 */
void AM_vUserDetermination(student_t* sHead);

#endif // _AUTHENTICATION_H