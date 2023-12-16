//
// Created by patri on 25/11/2023.
//

#ifndef UNTITLED5_REGLE_H
#define UNTITLED5_REGLE_H
#include <stdbool.h>


typedef struct elem {
    char proposition;
    struct elem *next;
    struct elem *previous;
    bool checkedprop;
    bool isConclu;
} regle;

typedef regle *Regle;

Regle creerR();
Regle addProp(char prop, Regle rule);
Regle addConclusion(Regle rule, char conclusion);
Regle isIn(Regle rule, char value); //can i do this one void
Regle deleteProp(Regle rule, int position);
bool isPremisseEmpty(Regle rule);
Regle headPremisse(Regle rule);
Regle conclusion(Regle rule);

#endif //UNTITLED5_REGLE_H
