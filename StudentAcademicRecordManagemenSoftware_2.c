#include <stdio.h>
#include <string.h>

struct student {
    int rollno;
    char first_name[20];
    char last_name[20];
    char grades[5];
    float gpa;
} studarray[50];

int nstuds = 0;

void enrolstuds() {
    int i, j, min_indx, t;
    char first[20], last[20];

    printf("Enter the number of students to enroll: ");
    scanf("%d", &nstuds);

    if (nstuds < 0 || nstuds > 50) {
        while (nstuds < 0 || nstuds > 50) {
            printf("Enter a number between 0-50: ");
            scanf("%d", &nstuds);
        }
    }

    for (i = 0; i < nstuds; ++i) {
        printf("\nEnter the Roll number of student %d: ", i + 1);
        scanf("%d", &studarray[i].rollno);
        printf("Enter the first name of student %d: ", i + 1);
        scanf("%s", studarray[i].first_name);
        printf("Enter the last name of student %d: ", i + 1);
        scanf("%s", studarray[i].last_name);
    }

    for (i = 0; i < nstuds; ++i) {
        min_indx = i;
        for (j = i + 1; j < nstuds; j++) {
            if (studarray[j].rollno < studarray[min_indx].rollno) {
                min_indx = j;
            }
        }
        t = studarray[i].rollno;
        studarray[i].rollno = studarray[min_indx].rollno;
        studarray[min_indx].rollno = t;

        strcpy(first, studarray[i].first_name);
        strcpy(studarray[i].first_name, studarray[min_indx].first_name);
        strcpy(studarray[min_indx].first_name, first);

        strcpy(last, studarray[i].last_name);
        strcpy(studarray[i].last_name, studarray[min_indx].last_name);
        strcpy(studarray[min_indx].last_name, last);
    }

    printf("\nEntered data is:\n\n");
    for (i = 0; i < nstuds; ++i) {
        printf("Roll no.%d\n", studarray[i].rollno);
        printf("First name: %s\n", studarray[i].first_name);
        printf("Last name: %s\n\n", studarray[i].last_name);
    }
}

// Define other functions here (entergrades, displaystuds, searchstuds, editstudgrades, distmeritlist)

int main() {
    int inp = 1;

    while (inp != 7) {
        printf("Menu Choices:\n");
        printf("1: Enroll student\n");
        printf("2: Enter grade\n");
        printf("3: Display students\n");
        printf("4: Search student\n");
        printf("5: Edit student grades\n");
        printf("6: Display merit list\n");
        printf("7: Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &inp);

        switch (inp) {
            case 1:
                enrolstuds();
                break;
            // Add cases for other options (2, 3, 4, 5, 6)
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
