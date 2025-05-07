#include <stdio.h>
#include <string.h>

int login() {
    char username[8], password[10];

    printf("Enter username: ");
    scanf("%8s", username); // in hear we type the f.s as 8s it's indicate to Prevents buffer overflow by limiting input length (scanf("%8s", username))


    printf("Enter password: ");
    scanf("%10s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {  //in hear strcmp is used to compare two strings
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Invalid credentials.\n");
        return 0;
    }
}

int main() {
    login();
    return 0;
}
