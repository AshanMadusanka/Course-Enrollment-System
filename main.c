#include <stdio.h>
#include <stdint.h>


typedef struct {
    char course_name[50];
    uint32_t course_id;
}Course_t;

typedef struct {
    char name[50];
    uint32_t student_id;
    Course_t course;
}Student_t;





Student_t student[50];
Course_t course[50];
uint32_t student_count;
uint32_t course_count;

void addStudent(Student_t *students,uint32_t *student_count);
void addCourse(Student_t *students,uint32_t *course_count);
void enrollStudentInCourse(Student_t *students,uint32_t *student_count);
void displayStudentAndCourses(Student_t *students,uint32_t *student_count);

int main(void) {

    return 0;
}


void addStudent(Student_t *students,uint32_t *student_count) {

    uint32_t student_id = 0;
    printf("Enter New Student ID: ");
    scanf("%d",student_id);

    for (uint32_t i = 0; i< *student_count;i++) {

        if (students[i].student_id == student_id) {

            printf("You can't use this ID");
            return;
        }
    }

    students[*student_count].student_id = student_id;
    getchar();
    printf("Enter student name: ");
    scanf("%50[^\n]",&students[*student_count].name);
    // students[*student_count].course.course_id = (uint32_t)NULL;

}

void addCourse(Student_t *students,uint32_t *course_count) {

    uint32_t course_id = 0;
    printf("Enter Course ID: ");
    scanf("%d",&course_id);

    for (uint32_t i = 0; i< *course_count;i++) {

        if (course[i].course_id == course_id) {

            printf("You can't use this ID");
            return;
        }
    }
    course[*course_count].course_id = course_id;
    getchar();
    printf("Enter course name: ");
    scanf("%50[^\n]",course[*course_count].course_name);
}

void enrollStudentInCourse(Student_t *students,uint32_t *student_count) {



}

void displayStudentAndCourses(Student_t *students,uint32_t *student_count) {



}


void displayMessages() {

    printf("Add Student     (1)\n");
    printf("Add Course     (2)\n");
    printf("Show enroll Student in course     (2)\n");
    printf("Show students and courses     (1)\n");
}