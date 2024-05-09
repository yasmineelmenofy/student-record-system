#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "file_acess.h"
#define MAX_STUDENTS 100
#define MAX_FIELD_LENGTH 100

/*
 * FILE: admin.c
 * AUTHOR: Yasmine Elmenofy
 * BRIEF: This section of the project deal with the admin mode and admin menu
 * DATA: 8/05/2024
 */

/*
* Use this function to change the admin password stored in the specified file.
* It asks the admin for current username and password  verifies them against stored records,
* and allows the admin to set a new password if authentication succeeds.
*/
student_t students[MAX_STUDENTS]; // Global array to hold student records
int num_students = 0;
/*
*use this function to save the records in the file in a global array
*/
void ADD_vReadStudentRecords(const char *filename_studentrecord) {
    FILE *file = fopen(filename_studentrecord, "r");
    if (file != NULL) {
        printf("Student Records:\n");
        int count = 0;
        char line[MAX_FIELD_LENGTH];
        while (fgets(line, sizeof(line), file) != NULL && count < MAX_STUDENTS) {
            char *token;
            token = strtok(line, ",");
            students[count].cName = strdup(token);
            token = strtok(NULL, ",");
            students[count].cPassword = strdup(token);
            token = strtok(NULL, ",");
            students[count].nUnique_Id = atoi(token);
            token = strtok(NULL, ",");
            students[count].fTotal_Grade = atof(token);
            token = strtok(NULL, ",");
            students[count].nAge = atoi(token);
            token = strtok(NULL, ",");
            strcpy(students[count].cGender, token);
            count++;
        }
        fclose(file);
        num_students = count;
    } else {
        printf("Error: Unable to open student records file %s\n", filename_studentrecord);
    }
}


/*
* Function to edit student records.
* Takes the target ID as input and allows the admin to modify the corresponding student's information.
*/

void ADD_vEditStudentRecords() {
    int targetId;
    printf("Enter the ID of the student record you want to edit: ");
    scanf("%d", &targetId);

    for (int i = 0; i < num_students; i++) {
        if (students[i].nUnique_Id == targetId) {
            printf("Current Information:\n");
            printf("Name: %s\n", students[i].cName);
            printf("Password: %s\n", students[i].cPassword);
            printf("ID: %d\n", students[i].nUnique_Id);
            printf("Grade: %.2f\n", students[i].fTotal_Grade);
            printf("Age: %d\n", students[i].nAge);
            printf("Gender: %s\n", students[i].cGender);

            printf("Enter new information:\n");
            printf("Name: ");
            scanf("%s", students[i].cName);
            printf("Password: ");
            scanf("%s", students[i].cPassword);
            printf("Grade: ");
            scanf("%f", &students[i].fTotal_Grade);
            printf("Age: ");
            scanf("%d", &students[i].nAge);
            printf("Gender: ");
            scanf("%s", students[i].cGender);

            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("No student record found with the provided ID.\n");
}


/*
* Function to add a new student record.
* Prompts the admin to input the new student's information and adds it to the student records.
*/
void ADD_vAddNewStudentRecord() {
    printf("Adding a new student record...\n");
    if (num_students < MAX_STUDENTS) {
        printf("Enter student name: ");
        students[num_students].cName = (char *)malloc(MAX_FIELD_LENGTH * sizeof(char));
        scanf("%s", students[num_students].cName);
        printf("Enter student password: ");
         students[num_students].cPassword = (char *)malloc(MAX_FIELD_LENGTH * sizeof(char));
        scanf("%s", students[num_students].cPassword);
        printf("Enter student ID: ");
        scanf("%d", &students[num_students].nUnique_Id);
        printf("Enter student GPA: ");
        scanf("%f", &students[num_students].fTotal_Grade);
        printf("Enter student age: ");
        scanf("%d", &students[num_students].nAge);
        printf("Enter student gender: ");
        scanf("%s", students[num_students].cGender);
        num_students++;
        printf("New student record added successfully.\n");
    } else {
        printf("Maximum number of students reached. Unable to add new record.\n");
    }
}
/*
* Function to remove a student record.
* Takes the target ID as input and removes the corresponding student record from the records.
*/
void ADD_vRemoveStudentRecord() {
    int targetId;
    printf("Enter the ID of the student record you want to remove: ");
    scanf("%d", &targetId);

    for (int i = 0; i < num_students; i++) {
        if (students[i].nUnique_Id == targetId) {
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("Student record with ID %d removed successfully\n", targetId);
            return;
        }
    }
    printf("Student record with ID %d not found\n", targetId);
}
/*
* Function to read student records from a file.
* Reads student records from the specified file and displays them.
*/

void ADD_vViewStudentRecord() {
    printf("Viewing student records...\n");
    for (int i = 0; i < num_students; i++) {
        printf("Record %d:\n", i+1);
        printf("Name: %s\n", students[i].cName);
        printf("Password: %s\n", students[i].cPassword);
        printf("ID: %d\n", students[i].nUnique_Id);
        printf("Grade: %.2f\n", students[i].fTotal_Grade);
        printf("Age: %d\n", students[i].nAge);
        printf("Gender: %s\n", students[i].cGender);
        printf("\n");
    }
}
/*
* use this function to view specific record
* According to entered id by the user
*/
void ADD_vViewSpecificStudentRecord() {
     int targetId;
      printf("Enter the ID of the student record you want to view: ");
      scanf("%d", &targetId);
    for (int i = 0; i < num_students; i++) {
        if (students[i].nUnique_Id == targetId) {
            printf("Student Record:\n");
            printf("Name: %s\n", students[i].cName);
            printf("Password: %s\n", students[i].cPassword);
            printf("ID: %d\n", students[i].nUnique_Id);
            printf("Grade: %.2f\n", students[i].fTotal_Grade);
            printf("Age: %d\n", students[i].nAge);
            printf("Gender: %s\n", students[i].cGender);
            return;
        }
    }
    printf("No student record found with the provided ID.\n");
}

 /*
* Use this function to change the admin password stored in the specified file.
* and allows the admin to set a new password .
*/

void ADD_vChangeAdminPassword() {
   AdminPassword admin;
    FILE *file = fopen("admin_password.csv", "r");

    if (file != NULL) {
        fscanf(file, "%49[^,],%49s", admin.username, admin.password);
        fclose(file);
        char new_password[50];
        printf("Enter a new password: ");
        scanf("%49s", new_password);
        strcpy(admin.password, new_password);
        file = fopen("admin_password.csv", "w");
        if (file != NULL) {
            fprintf(file, "%s,%s\n", admin.username, admin.password);
            fclose(file);
            printf("Admin password updated successfully.\n");
        } else {
            printf("Error: Unable to write to the file.\n");
        }
    } else {
        printf("Error: Unable to open the file.\n");
    }

}
/*
* Function to write student records to a file.
* Writes the current student records to the specified file.
*/
void ADD_vWriteStudentRecords(const char *filename_studentrecord) {
    FILE *file = fopen(filename_studentrecord, "w");
    if (file != NULL) {
        for (int i = 0; i < num_students; i++) {
            fprintf(file, "%s,%s,%d,%.2f,%d,%s\n", students[i].cName, students[i].cPassword, students[i].nUnique_Id, students[i].fTotal_Grade, students[i].nAge, students[i].cGender);
        }
        fclose(file);
        printf("Student records updated successfully.\n");
    } else {
        printf("Error: Unable to open student records file %s\n", filename_studentrecord);
    }
}





