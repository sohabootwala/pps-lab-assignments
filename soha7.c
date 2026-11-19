#include <stdio.h>

#define MAX 100

struct Student {
    int roll_no;
    char name[50];
    float marks[3];
    float total;
    float percentage;
};

int main() {
    struct Student s[MAX];
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter the roll number, name and marks of 3 subjects:\n");
        scanf("%d %s %f %f %f",
              &s[i].roll_no,
              s[i].name,
              &s[i].marks[0],
              &s[i].marks[1],
              &s[i].marks[2]);

        s[i].total = 0;
        for (j = 0; j < 3; j++) {
            s[i].total += s[i].marks[j];
        }
        s[i].percentage = s[i].total / 3.0;
    }

    printf("\n%-10s %-12s %-12s %-12s %-12s %-10s %-10s\n",
           "Roll No", "Name", "Subject: 1", "Subject: 2", "Subject: 3", "Total", "Percentage");

    for (i = 0; i < n; i++) {
        printf("%-10d %-12s %-12.0f %-12.0f %-12.0f %-12.0f %-10.2f\n",
               s[i].roll_no,
               s[i].name,
               s[i].marks[0],
               s[i].marks[1],
               s[i].marks[2],
               s[i].total,
               s[i].percentage);
    }

    return 0;
}
