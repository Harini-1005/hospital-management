#include <stdio.h>
#include <string.h>

struct patient {
    int id, age;
    char name[50], disease[50], doctor[50];
    float bill;
} p[100];

int count = 0;

// Function declarations
void addPatient();
void viewPatients();
void searchPatient();
void deletePatient();
void assignDoctor();
void generateBill();

int main() {
    int choice;
    char user[20];
    int pass;

    printf("\n____ HOSPITAL MANAGEMENT SYSTEM ____\n");

    printf("\nEnter Admin Username: ");
    scanf("%s", &user);

    printf("Enter Password: ");
    scanf("%d", &pass);

    if (strcmp(user, "harini") != 0 || pass != 345678) {
        printf("Invalid Login!\n");
        return 0;
    }

    while (1) {
        printf("\n1. Add Patient");
        printf("\n2. View Patients");
        printf("\n3. Search Patient");
        printf("\n4. Delete Patient");
        printf("\n5. Assign Doctor");
        printf("\n6. Generate Bill");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: assignDoctor(); break;
            case 6: generateBill(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

// Add Patient
void addPatient() {
    if (count >= 100) {
        printf("Patient limit reached!\n");
        return;
    }

    printf("\nEnter Patient Name: ");
    scanf("%s", &p[count].name);

    printf("Enter Age: ");
    scanf("%d", &p[count].age);

    printf("Enter Disease: ");
    scanf("%s", &p[count].disease);

    p[count].id = 100 + count;
    p[count].bill = 0;
    strcpy(p[count].doctor, "Not Assigned");

    printf("Patient ID: %d\n", p[count].id);

    count++;
}

// View Patients
void viewPatients() {
    if (count == 0) {
        printf("No patients found!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d", p[i].id);
        printf("\nName: %s", p[i].name);
        printf("\nAge: %d", p[i].age);
        printf("\nDisease: %s", p[i].disease);
        printf("\nDoctor: %s", p[i].doctor);
        printf("\nBill: %.2f\n", p[i].bill);
    }
}

// Search Patient
void searchPatient() {
    int id;
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("\nFound!\n");
            printf("Name: %s\n", p[i].name);
            printf("Disease: %s\n", p[i].disease);
            printf("Doctor: %s\n", p[i].doctor);
            printf("Bill: %.2f\n", p[i].bill);
            return;
        }
    }
    printf("Patient not found!\n");
}

// Delete Patient
void deletePatient() {
    int id;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                p[j] = p[j + 1];
            }
            count--;
            printf("Deleted successfully!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}

// Assign Doctor
void assignDoctor() {
    int id;
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Enter Doctor Name: ");
            scanf("%s", p[i].doctor);
            printf("Doctor assigned!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}

// Generate Bill
void generateBill() {
    int id;
    float amount;

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Enter Bill Amount: ");
            scanf("%f", &amount);
            p[i].bill += amount;
            printf("Bill updated!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}