#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_USERS 100

/* User and candidate structures */
struct user {
    char username[20];
    char password[20];
    int is_admin;
    int is_polling_officer;
    int has_voted;
};

struct candidate {
    char name[50];
    int votes;
};

/* Global variables */
struct user users[MAX_USERS];
int num_users = 3; /* includes hardcoded test accounts */
struct candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
int candidates_initialized = 0; /* Flag to check if candidates have been initialized */

/* Function prototypes */
int login();
void user_panel(int user_index);
void admin_panel();
void polling_officer_panel();
void initialize_users();

/* Hardcoded test accounts */
void initialize_users() {
    strcpy(users[0].username, "Voter");
    strcpy(users[0].password, "password");
    users[0].is_admin = 0;
    users[0].is_polling_officer = 0;
    users[0].has_voted = 0;

    strcpy(users[1].username, "Officer");
    strcpy(users[1].password, "password");
    users[1].is_admin = 0;
    users[1].is_polling_officer = 1;
    users[1].has_voted = 0;

    strcpy(users[2].username, "Admin");
    strcpy(users[2].password, "password");
    users[2].is_admin = 1;
    users[2].is_polling_officer = 0;
    users[2].has_voted = 0;
}

int main() {
    /* Initialize test accounts */
    initialize_users();

    int choice;
    do {
        /* Display main menu */
        printf("Welcome to the Polling System!\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        /* Perform chosen action */
        switch (choice) {
            case 1: /* Login */
            {
                int user_index = login();
                if (user_index == -1) {
                    printf("Invalid login credentials. Please try again.\n");
                    break;
                }

                /* Initialize candidates if user is polling officer and candidates are not initialized */
                if (users[user_index].is_polling_officer && !candidates_initialized) {
                    printf("Please enter the number of candidates: ");
                    scanf("%d", &num_candidates);
                    printf("Please enter the names of the candidates:\n");
                    for (int i = 0; i < num_candidates; i++) {
                        printf("Candidate %d: ", i + 1);
                        scanf("%s", candidates[i].name);
                        candidates[i].votes = 0;
                    }
                    candidates_initialized = 1;
                }

                /* Display appropriate panel based on user type */
                if (users[user_index].is_admin) {
                    admin_panel();
                } else if (users[user_index].is_polling_officer) {
                    polling_officer_panel();
                } else {
                    user_panel(user_index);
                }

                /* Prompt user to exit or continue */
                printf("\nPress 1 to exit or any other key to continue: ");
                scanf("%d", &choice);
                break;
            }
            case 2: /* Exit */
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

/* Login */
int login() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return i;
        }
    }

    return -1;
}

/* User panel */
void user_panel(int user_index) {
    if (users[user_index].has_voted) {
        printf("You have already voted.\n");
        return;
    }

    printf("Vote for a candidate:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    candidates[choice - 1].votes++;
    users[user_index].has_voted = 1;
    printf("Thank you for voting!\n");
}

/* Admin panel */
void admin_panel() {
    int choice;
    do {
        printf("Admin Panel:\n");
        printf("1. Reset User Password\n");
        printf("2. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: /* Reset User Password */
            {
                printf("Enter the username of the user whose password you want to reset: ");
                char username[20];
                scanf("%s", username);

                int user_index = -1;
                for (int i = 0; i < num_users; i++) {
                    if (strcmp(username, users[i].username) == 0) {
                        user_index = i;
                        break;
                    }
                }

                if (user_index == -1) {
                    printf("User not found.\n");
                    break;
                }

                printf("Enter the new password for the user: ");
                scanf("%s", users[user_index].password);
                printf("Password has been reset.\n");
                break;
            }
            case 2: /* Exit */
                printf("Exiting Admin Panel...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);
}

/* Polling Officer panel */
void polling_officer_panel() {
    int choice;
    do {
        printf("Polling Officer Panel:\n");
        printf("1. Add Candidate\n");
        printf("2. Remove Candidate\n");
        printf("3. Declare Winner\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        /* Perform chosen polling officer action */
        switch (choice) {
            case 1: /* Add candidate */
                // (Same code as before)
                break;
            case 2: /* Remove candidate */
                // (Same code as before)
                break;
            case 3: /* Declare Winner */
            {
                printf("Poll Results:\n");
                int max_votes = -1;
                int winner_index = -1;
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                    if (candidates[i].votes > max_votes) {
                        max_votes = candidates[i].votes;
                        winner_index = i;
                    }
                }
                printf("Winner: %s with %d votes.\n", candidates[winner_index].name, candidates[winner_index].votes);
                break;
            }
            case 4: /* Exit */
                printf("Exiting Polling Officer Panel...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}


