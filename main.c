#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char course_name[50];
    uint32_t course_id;
}Course_t;

typedef struct {
    char name[50];
    uint32_t student_id;
    uint32_t stu_course_count;
    Course_t course[10];

}Student_t;





Student_t student[50];
Course_t course[50];
uint32_t student_count;
uint32_t course_count;

void addStudent(Student_t *students, Course_t *course, uint32_t *student_count, uint32_t *course_count);
void addCourse(Course_t *course,uint32_t *course_count);
void enrollStudentInCourse(Student_t *students,Course_t *course,uint32_t *student_count, uint32_t *course_count);
void displayStudentAndCourses(Student_t *students,Course_t *course,uint32_t *student_count, uint32_t *course_count);
void displayMessages();
int main(void) {

    while (1) {
        displayMessages();
        uint32_t user_choise = 0;
        printf("Enter our choise: ");
        scanf("%d",&user_choise);

        switch (user_choise) {

            case 1:
                addStudent(student, course, &student_count, &course_count);
            break;

            case 2:
                addCourse(course,&course_count);
            break;

            case 3:
                enrollStudentInCourse(student,course,&student_count,&course_count);
            break;

            case 4:
                displayStudentAndCourses(student,course,&student_count,&course_count);
            break;
            default:
                printf("Invalid input!!");
        }
    }
}


void addStudent(Student_t *students, Course_t *course, uint32_t *student_count, uint32_t *course_count) {

    uint32_t student_id = 0;
    printf("Enter New Student ID: ");
    scanf("%d",&student_id);

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
    (*student_count)++;
    printf("You are successfully added new student!\n");

}

void addCourse(Course_t *course,uint32_t *course_count) {

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
    (*course_count)++;
    printf("You are successfully added new course!\n");
}

void enrollStudentInCourse(Student_t *students,Course_t *course,uint32_t *student_count,uint32_t *course_count) {

    uint32_t course_id = 0;
    uint32_t student_id = 0;
    printf("Enter Student ID: ");
    scanf("%d",&student_id);

    for (uint32_t i = 0; i<*student_count;i++) {

        if(students[i].student_id == student_id) {

            printf("Enter Course ID to Enroll : ");
            scanf("%d",&course_id);

            for (uint32_t j = 0; j<*course_count; j++) {

                if (course[j].course_id == course_id) {

                    students[i].course[students[i].stu_course_count].course_id = course_id;
                    strcpy(students[i].course[students[i].stu_course_count].course_name,course[j].course_name);
                    students[i].stu_course_count++;

                }
            }

        }
    }





}

void displayStudentAndCourses(Student_t *students,Course_t *course,uint32_t *student_count,uint32_t *course_count) {

    for (uint32_t i = 0; i<*student_count; i++) {
        printf("Student ID: %d\n",students[i].student_id);
        printf("Student Name: %s\n",students[i].name);

        for (uint32_t j = 0; j<students[i].stu_course_count; j++) {
            printf("Enrolled Courses Name: %s and Course ID: %d\n",students[i].course[j].course_name,students[i].course[j].course_id);
        }
    }
    printf("\n");
}


void displayMessages() {

    printf("Add Student                         (1)\n");
    printf("Add Course                          (2)\n");
    printf("Enrolling Student into courses      (3)\n");
    printf("Show students and their courses     (4)\n");
}