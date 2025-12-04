#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));

    int secret = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    int best = 5;

    FILE *file = fopen("record.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &best);
        fclose(file);
    }

    printf("====================================\n");
    printf("         Number Guessing Game        \n");
    printf("====================================\n");
    printf("I chose a number between 1 and 100.\n");
    printf("Guess until you get it right.\n");
    printf("Current best score: %d attempts\n", best);
    printf("------------------------------------\n\n");

    while (1) {

        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == secret) {
            printf("\nCorrect! You guessed the number.\n");
            printf("Your attempts: %d\n", attempts);

            if (attempts < best) {
                printf("New record achieved!\n");
                file = fopen("record.txt", "w");
                fprintf(file, "%d", attempts);
                fclose(file);
            } else {
                printf("Good attempt, but not a new record.\n");
            }
            break;
        } 
        else if (guess < secret) {
            printf("Too low. Try again.\n");
        } 
        else {
            printf("Too high. Try again.\n");
        }
    }

    printf("\nThank you for playing.\n");
    return 0;
}
