#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char userChoice;
char computerChoice;
int userWins;
int computerWins;
struct Node {
    char data;
    struct Node* next;
};
struct Node* head;

void getUserChoice();
char getComputerChoice();
int compareChoices();
void displayResults();
void freeLinkedList();
void insertAtEnd(char data);
void printList();

int main() {
    srand(time(NULL));
    userWins = 0;
    computerWins = 0;
    int totalRounds;

    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &totalRounds);

    for (int round = 1; round <= totalRounds; round++) {
        printf("\nRound %d:\n", round);
        getUserChoice();
        computerChoice = getComputerChoice();
        int result = compareChoices();
        displayResults(result);
        freeLinkedList();
    }
    
    printf("\nOverall Results:\n");
    if (userWins > computerWins) {
        printf("User wins: %d\n", userWins);
        printf("Computer wins: %d\n", computerWins);
    } else {
        printf("User wins: %d\n", userWins);
        printf("Computer wins: %d\n", computerWins);
    }
    return 0;
}

void getUserChoice() {
    while (true) {
        printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
        scanf(" %c", &userChoice);
        if (userChoice == 'R' || userChoice == 'P' || userChoice == 'S') {
            break;
        }
    }
}

char getComputerChoice() {
    int random = rand() % 3;
    switch (random) {
        case 0:
            return 'R';
        case 1:
            return 'P';
        default:
            return 'S';
    }
}

int compareChoices() {
    if (userChoice == computerChoice) {
        return 0;
    } else if ((userChoice == 'R' && computerChoice == 'S') ||
               (userChoice == 'P' && computerChoice == 'R') ||
               (userChoice == 'S' && computerChoice == 'P')) {
        insertAtEnd(userChoice);
        return 1;
    } else {
        insertAtEnd(computerChoice);
        return -1;
    }
}

void displayResults(int result) {
    if (result == 0) {
        printf("It's a tie!\n");
    } else if (result == 1) {
        printf("You win!\n");
        userWins++;
    } else {
        printf("You lose!\n");
        computerWins++;
    }
    printf("Your choice: %c\n", userChoice);
    printf("Computer's choice: %c\n", computerChoice);
    printList();
}

void freeLinkedList() {
    struct Node* temp = head;
    while (temp != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

void insertAtEnd(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    struct Node* temp = head;
    printf("Moves: ");
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
