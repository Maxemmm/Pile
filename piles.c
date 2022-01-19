#include <stdio.h>
#include <stdlib.h>
#include "piles.h"

Pile *init(){
    Pile *pile = malloc(sizeof(*pile));
    pile->first = NULL;
}

void stack(Pile *pile, int newNum){
    Element *new = malloc(sizeof(*new));
    if (pile == NULL || new == NULL){
        exit(EXIT_FAILURE);
    }

    new->nbr = newNum;
    new->next = pile->first;
    pile->first = new;
}

int unstack(Pile *pile){
    if (pile == NULL){
        exit(EXIT_FAILURE);
    }

    int nbrUnstack = 0;
    Element *eleUnstack = pile->first;

    if (pile != NULL && pile->first != NULL){
        nbrUnstack = eleUnstack->nbr;
        pile->first = eleUnstack->next;
        free(eleUnstack);
    }
    return nbrUnstack;
}

void display(Pile *pile){
    if (pile == NULL){
        exit(EXIT_FAILURE);
    }
    Element *curr = pile->first;

    printf("------\n");

    while (curr != NULL){
        printf("| %.2d |\n", curr->nbr);
        printf("------\n");
        curr = curr->next;
    }

    printf("\n");
}

char* state(Pile *pile){
    if(pile->first == NULL){
        return "empty";
    }
    else{
        return "filled";
    }
}