#include <stdio.h>

#define MAX_STUDENTS 100

int s = 0;

struct student
{
    int id;
    char name[20];
    int clas;
    char sec[5];
    float cgpa;
} std[MAX_STUDENTS];

// Function prototypes
void load_data();
void save_data();
void add();
void find();
void update();
void deletek();
void show();

int main()
{
    load_data();

    int n;
    do
    {
        printf("1. For add student\n");
        printf("2. Find the Student details\n");
        printf("3. Update the student details\n");
        printf("4. Delete the students details\n");
        printf("5. Show all Students details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            add();
            break;
        case 2:
            find();
            break;
        case 3:
            update();
            break;
        case 4:
            deletek();
            break;
        case 5:
            show();
            break;
        }
    }
    while (n != 6);

    // Save data before exiting
    save_data();

    return 0;
}

void load_data()
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("No existing student data found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d %s %d %s %f", &std[s].id, std[s].name, &std[s].clas, std[s].sec, &std[s].cgpa) != EOF)
    {
        s++;
    }
    fclose(file);
}

void save_data()
{
    FILE *file = fopen("students.txt", "w");
    if (file == NULL)
    {
        printf("Error saving data.\n");
        return;
    }

    for (int i = 0; i < s; i++)
    {
        fprintf(file, "%d %s %d %s %.2f\n", std[i].id, std[i].name, std[i].clas, std[i].sec, std[i].cgpa);
    }
    fclose(file);
}

void add()
{
    if (s >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &std[s].id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", std[s].name);
    printf("Enter Class: ");
    scanf("%d", &std[s].clas);
    printf("Enter Section: ");
    scanf("%s", std[s].sec);
    printf("Enter CGPA: ");
    scanf("%f", &std[s].cgpa);
    s++;
}

void find()
{
    int k = -1, f;
    printf("Enter ID to find: ");
    scanf("%d", &f);
    for (int i = 0; i < s; i++)
    {
        if (std[i].id == f)
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("%d %s %d %s %.2f\n", std[k].id, std[k].name, std[k].clas, std[k].sec, std[k].cgpa);
    }
}

void update()
{
    int k = -1, f;
    printf("Enter ID to update: ");
    scanf("%d", &f);
    for (int i = 0; i < s; i++)
    {
        if (std[i].id == f)
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Enter new ID: ");
        scanf("%d", &std[k].id);
        printf("Enter new Name: ");
        scanf(" %[^\n]s", std[k].name);
        printf("Enter new Class: ");
        scanf("%d", &std[k].clas);
        printf("Enter new Section: ");
        scanf("%s", std[k].sec);
        printf("Enter new CGPA: ");
        scanf("%f", &std[k].cgpa);
    }
}

void deletek()
{
    int k = -1, f;
    printf("Enter ID to delete: ");
    scanf("%d", &f);
    for (int i = 0; i < s; i++)
    {
        if (std[i].id == f)
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        printf("Not found\n");
    }
    else
    {
        for (int l = k; l < s - 1; l++)
        {
            std[l] = std[l + 1];
        }
        s--;
        printf("Student deleted successfully\n");
    }
}

void show()
{
    if (s == 0)
    {
        printf("No students to display\n");
        return;
    }

    printf("ID   Name                 Class Section CGPA\n");
    printf("---- -------------------- ----- ------- -----\n");
    for (int i = 0; i < s; i++)
    {
        printf("%-4d %-20s %-5d %-7s %.2f\n", std[i].id, std[i].name, std[i].clas, std[i].sec, std[i].cgpa);
    }
}
