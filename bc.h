//
// Created by patri on 25/11/2023.
//

#ifndef UNTITLED5_BC_H
#define UNTITLED5_BC_H
#include "regle.h"
typedef struct bcelem{
    struct bcelem *next;
    struct bcelem *previous;
    Regle regle;
}bc;

typedef bc *BC;

BC creerB();
BC addtoBC(BC base, Regle rule);
BC headBC(BC base);
#endif //UNTITLED5_BC_H
