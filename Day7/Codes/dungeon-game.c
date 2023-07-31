#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate a battle with a monster
bool battle(int *playerHealth, int *playerAttack, int *playerDefense) {
    int monsterHealth = getRandomNumber(50, 100);
    int monsterAttack = getRandomNumber(10, 20);
    int monsterDefense = getRandomNumber(5, 10);

    printf("You encountered a fearsome monster!\n");

    while (*playerHealth > 0 && monsterHealth > 0) {
        int playerDamage = *playerAttack - monsterDefense;
        int monsterDamage = monsterAttack - *playerDefense;

        if (playerDamage > 0) {
            monsterHealth -= playerDamage;
        } else {
            playerDamage = 0;
        }

        if (monsterDamage > 0) {
            *playerHealth -= monsterDamage;
        } else {
            monsterDamage = 0;
        }

        printf("You dealt %d damage to the monster. Monster's health: %d\n", playerDamage, monsterHealth);
        printf("Monster dealt %d damage to you. Your health: %d\n", monsterDamage, *playerHealth);
    }

    if (*playerHealth <= 0) {
        printf("You were defeated by the monster. Game Over!\n");
        return false;
    } else {
        printf("Congratulations! You defeated the monster!\n");
        return true;
    }
}

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int playerAttack = 20;
    int playerDefense = 10;

    printf("Welcome to the Dungeon Adventure!\n");
    printf("You are in a dark and mysterious dungeon. Your goal is to reach the exit safely.\n");

    while (playerHealth > 0) {
        printf("\nYou are in a new room. What do you want to do?\n");
        printf("1. Explore the room\n");
        printf("2. Rest and recover health\n");
        printf("3. Try to find an exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (getRandomNumber(1, 2) == 1) {
                    if (battle(&playerHealth, &playerAttack, &playerDefense) == false) {
                        return 0;
                    }
                } else {
                    int treasure = getRandomNumber(20, 50);
                    printf("You found a treasure chest containing %d gold coins!\n", treasure);
                }
                break;
            case 2:
                playerHealth += getRandomNumber(10, 20);
                printf("You rested and recovered some health. Your health: %d\n", playerHealth);
                break;
            case 3:
                if (getRandomNumber(1, 2) == 1) {
                    printf("Congratulations! You found the exit and escaped the dungeon safely!\n");
                    return 0;
                } else {
                    printf("You searched but couldn't find the exit in this room.\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Your health has reached zero. Game Over!\n");

    return 0;
}
