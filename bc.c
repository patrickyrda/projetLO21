#include "bc.h"
#include <stdlib.h>
#include <stdio.h>

//creer base vide
BC creerB() {
    BC temp = (BC)malloc(sizeof(bc));
    temp->next = NULL;
    temp->previous = NULL;
    temp->regle = creerR();
    return temp;
}

//ajouter une regle a une base en queue,
BC addtoBC(BC base, Regle rule) {
    //printf("\n ENTERED addToBC");
    if (!base) {
        return NULL;
    }

    if (!rule) {
        return NULL;
    }

    BC newbc = creerB();
    newbc->regle = headPremisse(rule); //changed here !

    if (!newbc->regle) {
        return base;
    } else {

        if (base->regle->proposition == '0') {
            //printf("\n TRIGERRED THE FIRST");
            return newbc;
        }

        BC current = base;

        while (current->next != NULL) {
            //printf("\n ENTERED while loop");
            current = current->next;
        }

        current->next = newbc;
        newbc->previous = current;
        return newbc;
    }
}

//acceder a la regle en tete
BC headBC(BC base) {
    if (base == NULL) return NULL;
    if (base->regle->proposition == '0') return NULL;
    BC current = base;
    while (current->previous) {
        current = current->previous;
    }
    return current;
}

bool BalreadyIn() {

}