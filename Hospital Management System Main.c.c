
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLUE "\033[1;34m"
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define BRIGHT_RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW  "\033[0;33m"
#define MAGENTA "\033[0;35m"

#define MAX_PATIENTS 50
#define MAX_DOCTORS 20
#define MAX_USERS 5

typedef struct {
    int id;
    char name[50];
    int age;
    char disease[100];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialization[100];
} Doctor;

typedef struct {
    int a;
    char b[50];
    int c;
} Appointmant;

// Structures
struct User {
    char username[20];
    char password[20];
};


   int a,c;
   char b[50];

// Sample users
struct User users[MAX_USERS] = {
    {"Shaii", "0902"},
    {"Abdul", "Rahman"},
    {"Tharaka", "1234"},
    {"Izni","0715"},
    {"Umasha","1234"}

    };




// Login System
int login() {
    char username[8], password[10];
    int attempts = 3;

    while (attempts > 0) {
 printf(BLUE "\t\t\t\t###################################################\n");
 printf("\t\t\t\t#                                                 #\n");
 printf("\t\t\t\t#" GREEN"      WELCOME TO HOSPITAL MANAGEMENT SYSTEM      "BLUE"#\n");
 printf("\t\t\t\t#                                                 #\n");
 printf("\t\t\t\t###################################################\n" RESET);


    FILE *file = fopen("Design.txt", "r");
    printf(RED"\n\n");

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character from file
    }

    fclose(file);

        printf(YELLOW"\nEnter username: "BLUE);
        scanf("%s", username);
        printf(YELLOW"Enter password: "BLUE);
        scanf("%s", password);

        for (int i = 0; i < MAX_USERS; i++) {
            if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
                printf(GREEN"Login successful. Welcome, %s!\n" RESET, username);
                return 1;
            }
        }

        attempts--;
        printf(BRIGHT_RED"Invalid credentials. %d attempt(s) remaining.\n"RESET, attempts);
    }

    printf(RED"Access denied. Exiting program.\n"RESET);
    return 0;
}


Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0, doctorCount = 0;

void savePatients() {
    FILE *file = fopen("patients.txt", "a"); // Append mode to add new patients
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "\t\t\n\n ID:%d \t Name:%s \t Age:%d \t Disease:%s", patients[patientCount - 1].id,
            patients[patientCount - 1].name, patients[patientCount - 1].age,
            patients[patientCount - 1].disease);
    fclose(file);
}


void printPatientsFile() {
    FILE *file = fopen("patients.txt", "r");
    if (file == NULL) {
        printf("No patient records found!\n");
        return;
    }
    printf(GREEN"\n\n");

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character from file
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

// doctor functions

void saveDoctors() {
    FILE *file = fopen("doctors.txt", "a");
    if (file == NULL) {
        printf("Error saving doctors!\n");
        return;
    }
    for (int i = 0; i < doctorCount; i++) {
        fprintf(file, "\t\t\n\n ID:%d \t\t Name:%s \t\t specialization:%s\n", doctors[i].id, doctors[i].name, doctors[i].specialization);
    }
    fclose(file);
}

void printdoctorsFile() {
    FILE *file = fopen("doctors.txt", "r");
    if (file == NULL) {
        printf("No doctors records found!\n");
        return;
    }

    printf(GREEN"\n\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character from file
    }

    fclose(file);
}

void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf(RED"Doctor list is full!\n"RESET);
        return;
    }
    printf("Enter Doctor ID: ");
    scanf("%d", &doctors[doctorCount].id);
    printf("Enter Name: ");
    scanf(" %s", doctors[doctorCount].name);
    printf("Enter Specialization: ");
    scanf(" %s", doctors[doctorCount].specialization);
    doctorCount++;
    saveDoctors();
    printf(GREEN"Doctor added successfully!\n"RESET);
}



void viewDoctors() {
    printf("\n--- Doctor List ---\n");
    for (int i = 0; i < doctorCount; i++) {
        printf(GREEN"ID: %d, Name: %s, Specialization: %s\n"RESET,
               doctors[i].id, doctors[i].name, doctors[i].specialization);
    }
}


//appointment functions

void Addappointment() {

    printf("Enter Patient ID: ");
    scanf("%d", &a);
    printf("Enter Name: ");
    scanf(" %s",&b);
    printf("Enter Age: ");
    scanf("%d", &c);

    saveapointmant();
    printf(GREEN"appintmant added successfully!\n"RESET);
}

void saveapointmant() {
    FILE *file = fopen("apointmant.txt", "a"); // Append mode to add new patients
    if (file == NULL) {
        printf(RED "Error opening file!\n"RESET);
        return;
    }
    fprintf(file, "\t\t\n\n ID:%d \t Name:%s \t Age:%d ",a,b,c );
    fclose(file);
}


void printappointmentFile() {
    FILE *file = fopen("apointmant.txt", "r");
    if (file == NULL) {
        printf(RED"No apointmant records found!\n"RESET);
        return;
    }
    printf(GREEN"\n\n");


    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character from file
    }

    fclose(file);
}





//main function

int main() {

   if (!login()) {  // If login fails, exit the program
        return 0;
    }

    int choice;

    while (1) {
     printf(BLUE"\n\n\n\t\t\t\t##############################################\n");
printf(BLUE"\t\t\t\t#                                            #\n");
printf(BLUE"\t\t\t\t#   HOSPITAL MANAGEMENT SYSTEM CHOICES       #\n");
printf(BLUE"\t\t\t\t#                                            #\n");
printf(BLUE"\t\t\t\t##############################################\n");
printf(BLUE"\t\t\t\t# 1. Add Patient                             #\n");
printf(BLUE"\t\t\t\t# 2. View Patients                           #\n");
printf(BLUE"\t\t\t\t# 3. Add Doctor                              #\n");
printf(BLUE"\t\t\t\t# 4. View Doctors                            #\n");
printf(BLUE"\t\t\t\t# 5. Add Appointment                         #\n");
printf(BLUE"\t\t\t\t# 6. view Appointment                        #\n");
printf(BLUE"\t\t\t\t#                                            #\n");
printf(BLUE"\t\t\t\t##############################################\n");
printf(BLUE"\t\t\t\t# "RED"7. EXIT "BLUE"                                   #\n");
printf(BLUE"\t\t\t\t##############################################\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: printPatientsFile(); break;
            case 3: addDoctor(); break;
            case 4: printdoctorsFile(); break;
            case 5: Addappointment(); break;
            case 6: printappointmentFile(); break;
            case 7:printf(RED"\n Exiting gracefully... Goodbye! \n"RESET); exit(0);
            default: printf(RED"Invalid choice! Please try again.\n"RESET);
        }
    }
    return 0;
}
