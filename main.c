#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "piles.h"

int main(int argc, char* argv[]){

    // Clear screen in prompt
    system("clear");

    // Pile init
    printf("Pile init...\n");
    Pile *pile = init();

    // Random init
    srand(time(NULL));
    
    while(1){
        // Action menu
        int act;
        //printf("\nPile state: %s.\n[1] Afficher;\n[2] Remplir;\n[3] unstack;\n[4] Quitter.\nAction: ", empty);
        printf("\n[1] Display;\n[2] Stack;\n[3] Unstack;\n[4] Quit.\n\nPile state: %s\nAction: ", state(pile));
        scanf("%d", &act);

        // Different options
        switch(act){

            case 1:
                system("clear");
                // Check for pile state
                if(pile->first == NULL){
                    printf("(Error): Pile has not been filled yet.\n");
                }
                else{
                    printf("\n");
                    display(pile);
                }
                break;

            case 2:
                system("clear");
                int actStack;
                printf("\n[1] Random 0-10;\n[2] Manual.\nAction: ");
                scanf("%d", &actStack);
                if(actStack == 1){
                    int randSize = rand() % MAX;
                    for(size_t i = 0; i < randSize; ++i){
                        int randNum = rand() % NUM;
                        stack(pile, randNum);
                    }
                }
                else{
                    int nbrStack;
                    printf("How much stacking? ");
                    scanf("%d", &nbrStack);
                    for(size_t i = 0; i < nbrStack; ++i){
                        int usrNbr;
                        printf("Insert a number: ");
                        scanf("%d", &usrNbr);
                        if(usrNbr < 0 || usrNbr > 99){
                            printf("(Error): number must be between 0-99.\n");
                            break;
                        }
                        stack(pile, usrNbr);
                    }
                }
                system("clear");
                break;

            case 3:
                system("clear");
                if(pile->first == NULL){
                    printf("(Error): Pile has not been filled yet.\n");
                    break;
                }

                int actUnstack;
                printf("\n[1] Whole stack;\n[2] Manual.\nAction: ");
                scanf("%d", &actUnstack);
                if(actUnstack == 1){
                    for(size_t i = 0; i < pile->first; ++i){
                        unstack(pile);
                    }
                }
                else{
                    int nbrUnstack;
                    printf("How much unstacking? ");
                    scanf("%d", &nbrUnstack);
                    for(size_t i = 0; i < nbrUnstack; ++i){
                        unstack(pile);
                    }
                }
                system("clear");
                break;

            case 4:
                printf("\nExiting the program...\n");
                exit(EXIT_SUCCESS);
            
            default:
                system("clear");
                printf("(Error): Invalid action.\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}