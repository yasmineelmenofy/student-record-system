#include <stdio.h>
#include <string.h>
#include "file_acess.h"
#include "struct.h"

int main() {
    const char *filename_studentrecord = "student_data.csv";
    const char *filename_password = "admin_password.csv";

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add student record\n");
        printf("2. Add admin password\n");
        printf("3. View student records\n");
        printf("4. View admin passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
     student_t student;
    printf("Enter student ID: ");
scanf("%u", &student.nUnique_Id);
printf("Enter student name: ");
student.cName = malloc(50 * sizeof(char));
scanf(" %[^\n]", student.cName);
printf("Enter student GPA: ");
scanf("%f", &student.fTotal_Grade);
printf("Enter student gender: ");
scanf("%49s", student.cGender);
printf("Enter student age: ");
scanf("%u", &student.nAge);
printf("Enter student username: ");
student.cUsername = malloc(50 * sizeof(char));
scanf(" %[^\n]", student.cUsername);
printf("Enter student password: ");
student.cPassword = malloc(50 * sizeof(char));
scanf(" %[^\n]", student.cPassword);
    DFF_vWriteStudentRecord(filename_studentrecord, &student);
}

                break;
            case 2:
                {
                     AdminPassword admin;
    printf("Enter admin username: ");
    scanf(" %[^\n]", admin.username);
    printf("Enter admin password: ");
    scanf(" %[^\n]", admin.password);


    DFF_vWriteAdminPassword(filename_password, &admin);
}
                break;
            case 3:
                DFF_vReadStudentRecords(filename_studentrecord);
                break;
            case 4:
                DFF_vReadAdminPasswords(filename_password);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
