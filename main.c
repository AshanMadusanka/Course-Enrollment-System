#include <stdio.h>
#include <stdint.h>



typedef struct {
    char name[50];
    uint32_t student_id;
}Student_t;

typedef struct {
    char course_name[50];
    uint32_t course_id;
}Course_t;

typedef struct {

    Student_t student;
    Course_t course;
}Students_t;

Students_t students[50];
uint32_t student_count;

void addStudent(Students_t *students,uint32_t *student_count);
void addCourse(Students_t *students,uint32_t *student_count);
void enrollStudentInCourse(Students_t *students,uint32_t *student_count);
void displayStudentAndCourses(Students_t *students,uint32_t *student_count);

int main(void) {

    return 0;
}


void addStudent(Students_t *students,uint32_t *student_count) {

    uint32_t student_id = 0;
    printf("Enter New Student ID: ");
    scanf("%d",student_id);

    for (uint32_t i = 0; i< *student_count;i++) {

        if (students[i].student.student_id == student_id) {

            printf("You can't use this ID");
            return;
        }
    }

    students[*student_count].student.student_id = student_id;
    getchar();
    printf("Enter student name: ");
    scanf("%50[^\n]",&students[*student_count].student.name);
    // students[*student_count].course.course_id = (uint32_t)NULL;

}

void addCourse(Students_t *students,uint32_t *student_count) {



}

void enrollStudentInCourse(Students_t *students,uint32_t *student_count) {



}

void displayStudentAndCourses(Students_t *students,uint32_t *student_count) {



}


void displayMessages() {

    printf("Add Student     (1)\n");
    printf("Add Course     (2)\n");
    printf("Show enroll Student in course     (2)\n");
    printf("Show students and courses     (1)\n");
}