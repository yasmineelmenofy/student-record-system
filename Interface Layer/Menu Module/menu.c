/**
***************************************************************
@file        menu.c
@version     1.0.0
@brief       menu module.
@details     this file contains functions to display the main menu to the user and allow the user
             to select the desired mode.
@author      Mahmoud Ramzy Behilk.administration
@Created     on May 12, 2024, 8:19 PM
***************************************************************
*/
#include "menu.h"

void MM_vMenuDisplay(student_t* sHead)
{
    unsigned int Local_nLogInChoice = 0;
    unsigned int Local_nUserChoice = 0;
    unsigned int Local_nMode = 0;

    printf("Welcome to student record system \nOur system has two modes and each mode has some privileges\n");
    printf("First we have Administration mode and you can do the next \n");
    printf("1. Add student record \n");
    printf("2. Remove student record \n");
    printf("3. View student record \n");
    printf("4. View all records \n");
    printf("5. Edit admin password \n");
    printf("6. Edit student grade \n\n");

    printf("Second we have Student mode and you can do the next \n");
    printf("1. View your record. \n");
    printf("2. Edit your password \n");
    printf("3. Edit your name. \n\n");

    while(true)
    {
        printf("1. Get into the system \n2. Exit the system \n");
        printf("Please Enter your choose : ");
        scanf("%i", &Local_nLogInChoice);

        if(1 == Local_nLogInChoice)
        {
            Local_nMode = AM_vUserDetermination(sHead);

            switch(Local_nMode)
            {
                case 1:

                    printf("You now have the administration privileges and you can \n");
                    printf("1. Add student record \n");
                    printf("2. Remove student record \n");
                    printf("3. View student record \n");
                    printf("4. View all records \n");
                    printf("5. Edit admin password \n");
                    printf("6. Edit student grade \n");
                    printf("Please Enter your choose : ");
                    scanf("%i", &Local_nUserChoice);

                    switch(Local_nUserChoice)
                    {
                        case 1:

                            MMM_vAddStudentAtFrist(&head);
                            break;

                        case 2:

                            MMM_vDeleteSpecificStudent(&head);
                            break;

                        case 3:

                            ADD_vViewSpecificStudentRecord();
                            break;

                        case 4:

                            ADD_vViewStudentRecord();
                            break;

                        case 5:

                            ADD_vChangeAdminPassword();
                            break;

                        case 6:

                            ADD_vEditStudentRecords();

                            break;

                        default:
                            printf("Sorry wrong choice!! \n");
                            break;
                    }


                case 2:

                    printf("You now have the student privileges and you can \n");
                    printf("1. View your record. \n");
                    printf("2. Edit your password \n");
                    printf("3. Edit your name. \n");
                    printf("Please Enter your choose : ");
                    scanf("%i", &Local_nUserChoice);

                    switch(Local_nUserChoice)
                    {
                        case 1:

                            /** should call the function that does that job */
                            break;

                        case 2:

                            /** should call the function that does that job */
                            break;

                        case 3:

                            /** should call the function that does that job */
                            break;

                        default:
                            printf("Sorry wrong choice!! \n");
                            break;
                    }

                default:
                printf("Sorry wrong choice!! \n");
                break;
            }
        }

        else if(2 == Local_nLogInChoice)
        {
            break;
        }
        else
        {
            printf("Sorry wrong choice!! \nTry again \n\n");
        }
    }
}



