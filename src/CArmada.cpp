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
    const int nbBateau = getEffectifTotal();
    
    // pour chaque bateau
    CBateau* bateauPlacer[getEffectifTotal()];
    bateauPlacer[getEffectifTotal()] = {nullptr};
    
    // pour chaque bateau
    for (int i = 0; i < nbBateau; i++) {
        CBateau* bateau = getBateau(i);
        int taille = bateau->getTaille();
        
        // definir les bornes
        int maxX = TAILLE_GRILLE - taille; 
        int maxY = TAILLE_GRILLE - 1;

        int x = rand() % maxX;
        int y = rand() % maxY;

        bool placer = false;
        int essaie = 0;
        while (!placer && essaie < MAX_ESSAIS) {
                
            
        

            essaie++;
        }

    }
    

    


    return false;
}

bool CArmada::testPosition(int i, int j, int taille) {
    bool positionCorrecte = false;
    
    
    // test si le bateau est dans la grille
    if (i >= 0 && i <= maxX && j >= 0 && j <= maxY) {
        // pour chaque bateau...
        int nbBateau = getEffectifTotal();
        for (int i = 0; i < nbBateau; i++) {
            CBateau* bateau = getBateau(i);
            pair<int, int> pos = bateau.getPosition();
            int taille = bateau.getTaille();
            
            int pad = HORIZONTAL_PADDING_BOAT_PLACEMENT;
            int xStart = pos.first - pad;
            int xEnd = pos.first + taille + pad;
            
            // check si le bateau est sur la même ligne
            if (j == pos.second) {
                // check collision 
                if ((i + taille >= xStart) && (i <= xEnd)) {
                    positionCorrecte = false;
                    break;
                }
            }
        }
    }

    return positionCorrecte;
}