#include <stdio.h>
#include "bc.h"
#include "bf.h"


int main() {

    Regle regle1 = creerR();
    regle1 = addProp('A', regle1);
    regle1 = addProp('B', regle1);
    regle1 = addProp('C', regle1);
    regle1 = addConclusion(regle1, 'D');

    Regle regle2 = creerR();
    regle2 = addProp('B', regle2);
    regle2 = addProp('E', regle2);
    regle2 = addConclusion(regle2, 'F');

    Regle regle4 = creerR();
    regle4 = addProp('F', regle4);
    regle4 = addProp('D', regle4);
    regle4 = addConclusion(regle4, 'G');

    Regle regle5 = creerR();
    regle5 = addProp('A', regle5);
    regle5 = addProp('G', regle5);
    regle5 = addProp('C', regle5);
    regle5 = addProp('E', regle5);
    regle5 = addConclusion(regle5, 'H');

    Regle regle6 = creerR();
    regle6 = addProp('H', regle6);
    regle6 = addProp('T', regle6);
    regle6 = addProp('S', regle6);
    regle6 = addConclusion(regle6, 'V');


    BC base = creerB();

    base = addtoBC(base, regle1);

    base = addtoBC(base, regle2);

    base = addtoBC(base, regle4);

    base = addtoBC(base, regle5);

    Fait bf = creerF();



    bf = addFait(bf, 'A');
    bf = addFait(bf, 'B');
    bf = addFait(bf, 'C');
    bf = addFait(bf, 'E');

    BC bctemp = headBC(base);
    Fait bftemp = bf;
    Regle rtemp;


   while (bftemp) {

       while (bctemp) {
           rtemp = bctemp->regle;
           rtemp = isIn(rtemp, bftemp->fait);
           bftemp = IsRuleComplete(bftemp, rtemp);
           bctemp = bctemp->next;
       }

       bftemp = bftemp->next;
       bctemp = headBC((base));
   }

   int count = 1;
   while (bf) {
       if (bf->outputfait) {
           printf("\n OUTPUT %d : %c", count, bf->fait);
           count++;
       }
       bf = bf->next;
   }

   return 0;
}
