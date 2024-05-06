/**
***************************************************************
@file        memory_management.c
@version     1.0.0
@brief       memory management module.
@details     this file contains the memory management module which responsible for add or delete data from memory
@author      Mahmoud Ramzy Behilk.
@Created     on April 30, 2024, 7:07 PM
***************************************************************
*/

#include "memory_management.h"

            /**================  Helper Functions  =================**/

/*
 * Breif : This function used to check if the ID is already exist or not
 * Parameters : Pointer to linked list head
 * Parameters : New ID
 * return : Return status 1 if it's already exist and 0 if it not exist
 */
unsigned int  MMM_nCheckIfIdIsExist(student_t *sHead, unsigned int Local_nNew_Id);

unsigned int  MMM_nCheckIfIdIsExist(student_t *sHead, unsigned int Local_nNew_Id)
{
    student_t* Local_sLast = NULL;
    unsigned int Local_nLength = 0;
    unsigned int Local_nReturn_Status = 1;

    if(!sHead)
    {
        Local_nReturn_Status = 0; //this means no student added yet
    }
    else
    {
        Local_sLast = sHead;
        while(Local_sLast != NULL)
        {
            if(Local_sLast->nUnique_Id == Local_nNew_Id)
            {
                Local_nReturn_Status = 1;
                break;
            }
            else
            {
                Local_nReturn_Status = 0;
            }
            Local_sLast = Local_sLast->sNext;
        }
    }
    return Local_nReturn_Status;
}

            /**================  Basic Functions  =================**/

void MMM_vAddStudentAtFrist(student_t** sHead) // this student will be added at the beginning of the linked list
{
    student_t* Local_sNew_node = NULL;
    unsigned int Local_nNew_Id = 0;
    unsigned int Local_nReturn_Status = 1;
    char Local_cNewName[50];
    char Local_cNewPassword[50];

    Local_sNew_node = (student_t *)malloc(sizeof(student_t));

    if(NULL == Local_sNew_node)
    {
        printf("Failed to reserve this space in memory!!\n");
    }
    else
    {
        printf("Please enter student data \n");
        printf("Please enter student unique ID : ");

        scanf("%i", &Local_nNew_Id);
        Local_nReturn_Status = MMM_nCheckIfIdIsExist(*sHead, Local_nNew_Id);

        if(0 == Local_nReturn_Status)
        {
            Local_sNew_node->nUnique_Id = Local_nNew_Id;

            printf("Please enter student name : ");
            fflush(stdin);
            gets(Local_cNewName);
            Local_sNew_node->cName = (student_t *)malloc(strlen(Local_cNewName) + 1);
            strcpy(Local_sNew_node->cName, Local_cNewName);

            printf("Please enter student total degree : ");
            scanf("%f", &Local_sNew_node->fTotal_Grade);

            printf("Please enter student age : ");
            scanf("%i", &Local_sNew_node->nAge);

            printf("Please enter student gender : ");
            fflush(stdin);
            gets(Local_sNew_node->cGender);

            printf("Please enter student password : ");
            fflush(stdin);
            gets(Local_cNewPassword);
            Local_sNew_node->cPassword = (student_t *)malloc(strlen(Local_cNewPassword) + 1);
            strcpy(Local_sNew_node->cPassword, Local_cNewPassword);

            Local_sNew_node->sNext = *sHead;
            *sHead = Local_sNew_node;
        }
        else
        {
            printf("This ID is already exist !!\n");
        }
    }
    printf("\n");
}

void MMM_vDeleteSpecificStudent(student_t** sHead) //Delete_Specific_Node
{
    student_t* Local_sCurrent = *sHead;
    student_t* Local_sPrevious = *sHead;
    unsigned int Local_nNew_Id = 0;

    if (!Local_sCurrent)
    {
        printf("Can't delete, linked list is empty!\n");
        return;
    }
    else
    {
        printf("Please enter student ID you want to delete : ");
        scanf("%i", &Local_nNew_Id);

        if (Local_sCurrent->nUnique_Id == Local_nNew_Id) /* If the first node matches the ID */
        {
            *sHead = Local_sCurrent->sNext;
            free(Local_sCurrent);
            Local_sCurrent = NULL; // added
            return;
        }

        while(Local_sCurrent != NULL && Local_sCurrent->nUnique_Id != Local_nNew_Id)
        {
            Local_sPrevious = Local_sCurrent;
            Local_sCurrent = Local_sCurrent->sNext;
        }
        if (Local_sCurrent == NULL)
        {
            printf("Student with such ID not found in the linked list!\n");
            return;
        }
        Local_sPrevious->sNext = Local_sCurrent->sNext;
        Local_sCurrent->sNext = NULL;
        free(Local_sCurrent);
        Local_sCurrent = NULL; // added
    }
}