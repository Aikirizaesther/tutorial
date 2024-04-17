#include <stdio.h>
#include <string.h>

// Define the Student structure
typedef struct
{
    char name[50];
    char first_name[25];
    char last_name[25];
    char full_name[50];
    char hall_of_residence[50];
    int grades[4];
    char letter_grade;
} Student;

// Function to input student details
void input_student_details(Student *s)
{
    printf("Enter student's first name: ");
    scanf("%s", s->first_name);
    printf("Enter student's last name: ");
    scanf("%s", s->last_name);
    printf("Enter student's hall of residence: ");
    scanf("%s", s->hall_of_residence);
    strcpy(s->name, s->first_name);
    strcat(s->name, " ");
    strcat(s->name, s->last_name);
    strcpy(s->full_name, s->name);
    printf("Enter student's 4 grades:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Enter grade %d: ", i + 1);
        scanf("%d", &s->grades[i]);
    }
}

// Function to calculate the average grade
float calculate_average_grade(Student *s)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += s->grades[i];
    }
    return sum / 4.0;
}

// Function to assign a letter grade
void assign_letter_grade(Student *s)
{
    float average = calculate_average_grade(s);
    if (average >= 80)
    {
        s->letter_grade = 'A';
    }
    else if (average < 80)
    {
        s->letter_grade = 'B';
    }
    else
    {
        s->letter_grade = 'C';
    }
}

// Function to display the student's complete record
void display_student_record(Student *s)
{
    printf("\n\n");
    printf("Student's Full Name: %s\n", s->full_name);
    printf("Hall of Residence: %s\n", s->hall_of_residence);
    printf("Grades: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", s->grades[i]);
    }
    printf("\nAverage Grade: %.2f\n", calculate_average_grade(s));
    printf("Letter Grade: %c\n", s->letter_grade);
}

int main()
{
    Student s;
    input_student_details(&s);
    assign_letter_grade(&s);
    display_student_record(&s);
    return 0;
}