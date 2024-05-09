#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "file_acess.h"

#define MAX_STUDENTS 100
#define MAX_FIELD_LENGTH 100

int main() {
    const char *filename_studentrecord = "student_data.csv";
    const char *filename_password = "admin_password.csv";
student_t students[MAX_STUDENTS];
int num_students = 0;
    ADD_vReadStudentRecords(filename_studentrecord);

    int choice;
    do {
        printf("\nAdmin Menu:\n");
        printf("1. Change Admin Password\n");
        printf("2. Edit Student Records\n");
        printf("3. Add New Student Record\n");
        printf("4. Remove Student Record\n");
        printf("5. View Student Records\n");
        printf("6. View Specific Student Record\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ADD_vChangeAdminPassword();
                break;
            case 2:
                ADD_vEditStudentRecords();
                ADD_vWriteStudentRecords(filename_studentrecord);
                break;
            case 3:
                ADD_vAddNewStudentRecord();
                ADD_vWriteStudentRecords(filename_studentrecord);
                break;
            case 4:
                ADD_vRemoveStudentRecord();
                ADD_vWriteStudentRecords(filename_studentrecord);
                break;
            case 5:
                ADD_vViewStudentRecord();
                break;
            case 6: {
                ADD_vViewSpecificStudentRecord();
                break;
            }
            case 7:
                printf("Exiting Admin Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
