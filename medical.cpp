#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_HISTORY_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char history[MAX_HISTORY_LENGTH];
} Patient;

int numPatients = 0;
Patient patients[MAX_PATIENTS];

void addPatient() {
    if (numPatients < MAX_PATIENTS) {
        Patient newPatient;
        printf("Enter patient name: ");
        scanf("%s", newPatient.name);
        printf("Enter medical history: ");
        scanf(" %[^\n]", newPatient.history); // Read until newline

        patients[numPatients] = newPatient;
        numPatients++;
        printf("Patient added successfully!\n");
    } else {
        printf("Maximum number of patients reached.\n");
    }
}

void viewPatients() {
    if (numPatients == 0) {
        printf("No patients available.\n");
        return;
    }

    printf("List of patients:\n");
    for (int i = 0; i < numPatients; i++) {
        printf("%d. Name: %s\n", i + 1, patients[i].name);
        printf("   Medical History: %s\n", patients[i].history);
    }
}

int main() {
    int choice;

    do {
        printf("\nMedical History Viewing System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

