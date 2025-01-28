#include "CArmada.h"


void CArmada::ajouterBateau(CBateau& unBat) {
    m_listeBateaux.push_back(unBat);
} 


/**********************************************************************/

CBateau* CArmada::getBateau(int i) {
    return &m_listeBateaux[i];
}

int CArmada::getEffectifTotal() {
    return m_listeBateaux.size();
}

int CArmada::getNbreTotCases() {
    int tot = 0;
    for (int i = 0; i < getEffectifTotal(); i++) {
        tot += m_listeBateaux[i].getTaille();
    }
    return tot;
}

void getArmadaFromFile() {
    // TODO
}

bool CArmada::placerAleatoirement() {
    return false;
}

