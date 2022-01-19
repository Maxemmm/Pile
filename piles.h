#ifndef H_PILE
#define H_PILE

#define MAX 10
#define NUM 99

typedef struct Element Element;
struct Element{
    int nbr;
    Element *next;
};

typedef struct Pile Pile;
struct Pile{
    Element *first;
};

Pile *init();
void stack(Pile *pile, int newNum);
int unstack(Pile *pile);
void display(Pile *pile);

char* state(Pile *pile);

#endif
