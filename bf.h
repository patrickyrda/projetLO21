//
// Created by patri on 05/12/2023.
//

#ifndef UNTITLED5_BF_H
#define UNTITLED5_BF_H
#include <stdbool.h>
#include "regle.h"
typedef struct faitele {
    char fait;
    struct faitele *next;
    //bool checkedfait; Imma remove it
    bool outputfait;
} fait;

typedef fait *Fait;

Fait creerF();
Fait addFait(Fait fait, char val);
Fait addFaitO(Fait fait, char val);
Fait IsRuleComplete(Fait fait, Regle rule);

#endif //UNTITLED5_BF_H
