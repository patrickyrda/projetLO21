#include <stdio.h>
#include "regle.h"
#include <stdbool.h>
#include <stdlib.h>

//cree une nouvelle Regle
Regle creerR() {
    Regle temp = (Regle)malloc(sizeof(regle));
    temp->next = NULL;
    temp->previous = NULL;
    temp->proposition = '0';
    temp->checkedprop = false;
    temp->isConclu = false;

    return temp;
}

//Ajoute proposition en queue de la premisse          CHECKED
Regle addProp(char prop, Regle rule) {
    Regle newProp = creerR();
    newProp->proposition = prop;
    Regle conclu = conclusion(rule);

    if (rule->proposition == '0') {
        return newProp;
    }

    if (isPremisseEmpty(rule)) {
        if (conclu != NULL) {
            newProp->next = conclu;
            conclu->previous = newProp;
            return newProp;

        } else {
            return newProp;
        }
    }

    Regle tmp = headPremisse(rule);
    while (tmp->next != NULL && tmp->next->isConclu == false) {
        tmp = tmp->next;
    }

    tmp->next = newProp;
    newProp->previous = tmp;
    if (conclu) {
        newProp->next = conclu;
        conclu->previous = newProp;
    }

    return rule;
}

//Cree la conclusion
Regle addConclusion(Regle rule, char conclusion) {                    //checked
    Regle newConclusion = creerR();
    newConclusion->proposition = conclusion;
    newConclusion->isConclu = true;

    if (isPremisseEmpty(rule)) {
        return newConclusion;
    } else {

        Regle tmp = headPremisse(rule);
        while (tmp->next && tmp->next->isConclu == false) {
            tmp = tmp->next;
        }
        tmp->next = newConclusion;
        newConclusion->previous = tmp;
        return rule;
    }
}

//Teste si proposition appartient a la premisse
Regle isIn(Regle rule, char value) {
    if (!rule || isPremisseEmpty(rule)) {
        return headPremisse(rule);
    }
    if (rule->isConclu == true) {
        return headPremisse(rule);
    }
    if (rule->proposition == value) {
        rule->checkedprop = true;
        return headPremisse(rule);
    } else {
        return headPremisse(isIn(rule->next, value));
    }
}

//Supprime une position de la premisse            CHECKED TESTAR MAIS DEPOIS
Regle deleteProp(Regle rule, int position) {
    if (!rule) {
        printf("\nRule is NULL");
        return rule;
    }
    if (isPremisseEmpty(rule) || position < 0) {
        printf("\n!!Error, Empty Premisse or invalid position!!\n");
        return rule;
    }
    Regle current = headPremisse(rule);
    int pos = 1;

    while (current != NULL && current->isConclu == false && pos < position) {
        current = current->next;
        pos++;
    }
    //position is not in the
    if (!current){
        printf("\n POSITION IS BIGGER THAN PREMISSE");
        return rule;
    }

    if (current->isConclu) {
       printf("\n CANT DELETE CONCLUSION");
       return rule;
    }

    if (current->previous != NULL) {
        current->next->previous = current->previous;
        current->previous->next = current->next;
    } else {
        current->next->previous = NULL;
        return current->next;
    }

    free(current);

    return rule;
}

//teste si premisse est vide

bool isPremisseEmpty(Regle rule) {              //checked
    return headPremisse(rule) == NULL;
}

//acceder a la proposition en tete de la Regle                       CHEKCED
Regle headPremisse(Regle rule) {

    if (rule == NULL) {
        return NULL;
    }

    if (rule->proposition == '0') {
        return NULL;
    } else {
        Regle current = rule;
        while (current->previous != NULL) {
            current = current->previous;
        }
        if (current->isConclu == true) {
            return NULL;
        } else {
            return current;
        }
    }
}

//Acceder a la conclusion de la Regle                    !!What do i return, the regle or only the value                CHECKED
Regle conclusion(Regle rule) {
    Regle tmp = rule;

    if (tmp == NULL) {
        return tmp;
    }
    if(tmp->isConclu) {
        return tmp;
    } else {

        tmp = headPremisse(rule);              // !!does it need to be the head, i dont think so

        while (tmp != NULL && tmp->isConclu != true) {
            tmp = tmp->next;
        }

        return tmp;
    }
}

bool RalreadyIn(Regle rule, char value) {
    if (!rule) {
        return false;
    }
    if (!rule->next) {
        return false;
    }
    if (rule->proposition == value) {
        return true;
    } else {
        return headPremisse(isIn(rule->next, value));
    }
}