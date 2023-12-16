#include "bf.h"
#include <stdlib.h>
#include <stdio.h>

Fait creerF() {
    Fait fait = (Fait)malloc(sizeof(fait));
    fait->fait = '0';
    fait->next = NULL;
    fait->outputfait = false;
}

Fait addFait(Fait fait, char val) {

    Fait newfait = creerF();
    newfait->fait = val;

    if (fait->fait == '0' || !fait) {
        return newfait;
    }

    Fait temp = fait;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newfait;

    return fait;
}

Fait addFaitO(Fait fait, char val) {

    Fait newfait = creerF();
    newfait->fait = val;
    newfait->outputfait = true;

    if (fait->fait == '0' || !fait) return newfait;

    Fait temp = fait;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newfait;

    return fait;
}

Fait IsRuleComplete(Fait fait, Regle rule) {
    if (!rule || isPremisseEmpty(rule)) {
        return fait;
    }
    if (!fait) {
        return NULL;
    }

    if (rule->checkedprop) {
        if (!rule->next->next) {
            if (!rule->next->checkedprop) {
                Regle conclu = conclusion(rule);
                if (conclu) {
                    conclu->checkedprop = true;
                } else {
                    return fait;
                }
                fait = addFaitO(fait, conclu->proposition);
            }
            return fait;
        } else {
            return IsRuleComplete(fait, rule->next);
        }
    } else {
        return fait;
    }
}