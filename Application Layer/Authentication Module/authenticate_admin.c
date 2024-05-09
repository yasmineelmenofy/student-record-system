/**
***************************************************************
@file        authentication.c
@version     1.0.0
@brief       authentication module.
@details     this file contains functions to check the username and password entered by the
             ser and determine whether the user is an admin or a student
@author      Mahmoud Ramzy Behilk.administration
@Created     on May 6, 2024, 7:44PM
***************************************************************
*/

#include "memory_management.h"
#include "authentication.h"

void AM_vUserChecking(void)
{
    unsigned int Local_nNewPassword[50];
    unsigned int counter = 0;
    char *cUserPassword = "1234";

    while(counter < 3)
        {
            printf("Please enter your password : ");
            fflush(stdin);
            gets(Local_nNewPassword);

            if(strcmp(cUserPassword , Local_nNewPassword) != 0) /* strcmp return <<0>> if it's true */
            {
                printf("Please try again!!\n");
                counter++;
            }

            else
            {
               printf("You are welcome ");
               break;
            }

            if(3 == counter)
            {
                printf("No more tries.\nYou are not registered.\n");
            }
            else{/*Nothing*/}
        }
}

void AM_vStudentChecking(student_t* sHead)
{
    unsigned int Local_nStudentId = 0;
    unsigned int Local_nNewPassword[50];
    student_t* Local_sCurrent = sHead;
    unsigned int counter = 0;

    printf("Please enter your ID : ");
    scanf("%i", &Local_nStudentId);

    if(!MMM_nCheckIfIdIsExist(sHead, Local_nStudentId)) // this function will return 1 if student exist
    {
        printf("Sorry this ID does not exist!!\n");
    }

    else
    {
         while(Local_sCurrent != NULL && Local_sCurrent->nUnique_Id != Local_nStudentId)
         {
             Local_sCurrent = Local_sCurrent->sNext; //now Local_sCurrent is pointing at the student with that ID
         }

        while(counter < 3)
        {
            printf("Please enter your password : ");
            fflush(stdin);
            gets(Local_nNewPassword);

            if(strcmp(Local_sCurrent->cPassword , Local_nNewPassword) != 0) /* strcmp return <<0>> if it's true */
            {
                printf("Please try again!!\n");
                counter++;
            }

            else
            {
               printf("You are welcome ");
               break;
            }
        }
    }

    if(3 == counter)
    {
        printf("No more tries.\nYou are not registered.\n");
    }
    else{/*Nothing*/}
}

void AM_vUserDetermination(student_t* sHead)
{
    unsigned int Local_nMode = 0;

    printf("The system has two modes \n1. Admin mode \n2. Student mode\n");
    printf("Please choose the mode : ");
    scanf("%i", &Local_nMode);

    switch(Local_nMode)
    {
        case 1:

            AM_vUserChecking();
            break;

        case 2:
            AM_vStudentChecking(sHead);
            break;

        default:
        printf("Sorry wrong choice!! \n");
    }
}