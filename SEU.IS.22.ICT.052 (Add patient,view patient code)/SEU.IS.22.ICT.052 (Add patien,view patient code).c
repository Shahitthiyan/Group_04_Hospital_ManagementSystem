#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define MAX_PATIENTS 50

typedef struct {
    int id;
    char name[50];
    int age;
    char disease[100];
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

void savePatients() {
    FILE *file = fopen("patients.txt", "a"); // Append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "\nID: %d\tName: %s\tAge: %d\tDisease: %s\n",
            patients[patientCount - 1].id,
            patients[patientCount - 1].name,
            patients[patientCount - 1].age,
            patients[patientCount - 1].disease);
    fclose(file);
}

void printPatientsFile() {
    FILE *file = fopen("patients.txt", "r");
    if (file == NULL) {
        printf("No patient records found!\n");
        return;
    }
    printf(GREEN "\n\n--- Patient Records ---\n\n" RESET);

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient list is full!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &patients[patientCount].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", patients[patientCount].name);
    printf("Enter Age: ");
    scanf("%d", &patients[patientCount].age);
    printf("Enter Disease: ");
    scanf(" %[^\n]", patients[patientCount].disease);

    patientCount++;
    savePatients();
    printf(GREEN "Patient added successfully!\n" RESET);
}

int main() {
    int choice;

    do {
        printf("\n--- Hospital Management ---\n");
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
                printPatientsFile();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
