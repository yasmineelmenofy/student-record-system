#ifndef ADMIN_H
#define ADMIN_H
#include "file_acess.h"


/*
 * FILE: admin.h
 * AUTHOR: Yasmine Elmenofy
 * BRIEF: Header file for the module Module that
 *contain function prototypes
 * DATA: 8/05/2024
 */


void ADD_vChangeAdminPassword();
void ADD_vEditStudentRecords();
void ADD_vAddNewStudentRecord();
void ADD_vRemoveStudentRecord();
void ADD_vViewStudentRecord();
void ADD_vReadStudentRecords(const char *filename_studentrecord);
void ADD_vWriteStudentRecords(const char *filename_studentrecord);

#endif




