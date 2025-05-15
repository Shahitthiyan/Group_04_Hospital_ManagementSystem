#include <stdio.h>
#include <string.h>


#define MAX_PATIENTS 100
#define MAX_DOCTORS 50

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

struct Doctor {
    int id;
    char name[50];
    char specialization[50];
};

struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

struct Doctor doctors[MAX_DOCTORS];
int doctorCount = 0;

void addPatient() {
    struct Patient p;
    printf("Enter Patient ID: "); scanf("%d", &p.id); getchar();
    printf("Enter Name: "); fgets(p.name, 50, stdin); strtok(p.name, "\n");
    printf("Enter Age: "); scanf("%d", &p.age); getchar();
    printf("Enter Gender: "); fgets(p.gender, 10, stdin); strtok(p.gender, "\n");
    printf("Enter Disease: "); fgets(p.disease, 50, stdin); strtok(p.disease, "\n");
    patients[patientCount++] = p;
    printf("Patient added.\n");
}

void listPatients() {
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d | Name: %s | Age: %d | Gender: %s | Disease: %s\n",
               patients[i].id, patients[i].name, patients[i].age,
               patients[i].gender, patients[i].disease);
    }
}

// Doctor Management
void addDoctor() {
    struct Doctor d;
    printf("Enter Doctor ID: "); scanf("%d", &d.id); getchar();
    printf("Enter Name: "); fgets(d.name, 50, stdin); strtok(d.name, "\n");
    printf("Enter Specialization: "); fgets(d.specialization, 50, stdin); strtok(d.specialization, "\n");
    doctors[doctorCount++] = d;
    printf("Doctor added.\n");
}

void listDoctors() {
    for (int i = 0; i < doctorCount; i++) {
        printf("ID: %d | Name: %s | Specialization: %s\n",
               doctors[i].id, doctors[i].name, doctors[i].specialization);
    }
}

int main(){
    addpatient();
    listPatients();
    addDoctor();
    listDoctors();
    return 0;
}
