#include <stdio.h>
#include <string.h>

int login() {
    char username[8], password[10];
    int attempts = 3;

    while (attempts > 0) {
        printf("\n=======Login page=======\n");
        printf("Enter username: ");
        scanf("%8s", username);

        printf("Enter password: ");
        scanf("%10s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
            printf("Login successful.\n");
            return 1;
        } else {
            attempts--;
            if (attempts > 0) {
                printf("Invalid credentials. %d attempts remaining\n", attempts);
            } else {
                printf("Invalid credentials. No attempts remaining. Login failed.\n");
            }
        }
    }
    return 0;
}

int main() {
    login();
    return 0;
}

