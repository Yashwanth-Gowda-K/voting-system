#include <stdio.h>

#define OPTIONS 3

void displayOptions(char *names[]);
void castVote(int votes[], char *names[]);

int main() {
    int votes[OPTIONS] = {0}; // Array to store votes for each option

    // Array of names for each option
    char *names[OPTIONS] = {"Alice", "Bob", "Charlie"};

    int choice;

    printf("Welcome to the Voting System\n");

    while (1) {
        displayOptions(names);
        printf("\nEnter the number of your choice (0 to end voting): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;  // Exit the loop if the user enters 0
        } else if (choice >= 1 && choice <= OPTIONS) {
            votes[choice - 1]++;
            printf("Thank you for voting for %s!\n\n", names[choice - 1]);
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    // Display the results
    printf("\nVoting Results:\n");
    for (int i = 0; i < OPTIONS; i++) {
        printf("%s: %d votes\n", names[i], votes[i]);
    }

    return 0;
}

void displayOptions(char *names[]) {
    printf("\nVoting Options:");
    for (int i = 0; i < OPTIONS; i++) {
        printf("\n%d. %s", i + 1, names[i]);
    }
    printf("\n");
}
