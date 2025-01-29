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

void CArmada::getArmadaFromFile() {
    ifstream fileStream(FLOTILLE_FILE, ios::in);
    
    while (!fileStream.eof()) {
        string line;
        getline(fileStream, line, '\n');
        
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // structure : nom nombre taille
        istringstream temp(line);
        string nom;
        int nombre;
        int taille;

        temp >> nom >> nombre >> taille;
        
        for (int i = 0; i < nombre; i++) {
            CBateau bateau (nom, pair(0, 0), taille);
            ajouterBateau(bateau);
        }
    }

    fileStream.close();
}

bool CArmada::placerAleatoirement() {
    bool processusRater = false; // si le processus de placement a échoué
    const int nbBateau = getEffectifTotal();
    
    // pour chaque bateau
    int nbBateauPlacer = 0;
    CBateau* bateauxPlacer[getEffectifTotal()] = {};
    
    // pour chaque bateau
    for (int i = 0; i < nbBateau; i++) {
        CBateau* pBateau = getBateau(i);
        int taille = pBateau->getTaille();
        // cout << "placement de bateau " << pBateau->getNom() << " de taille " << taille << "(" << i << ")" << endl;
        
        // definir les bornes
        int maxX = TAILLE_GRILLE - taille; 
        int maxY = TAILLE_GRILLE - 1;
        // cout << "max : " << maxX << " " << maxY << endl;

        bool placer = false;
        int essaie = 0;
        while (!placer && essaie < MAXESSAIS) {    
            essaie++;

            int x = rand() % maxX;
            int y = rand() % maxY;
            // cout << "Essai " << essaie << " à " << x << " " << y << endl;

            // si aucun bateau n'est placé, on place le bateau
            if (nbBateauPlacer == 0) {
                // cout << "Placé !" << endl;
                pBateau->setPosition(x, y);
                bateauxPlacer[nbBateauPlacer] = pBateau;
                nbBateauPlacer++;
                placer = true;
                continue;
            }

            // parcourir les bateaux déjà placés
            bool collision = false;
            for (int j = 0; j < nbBateauPlacer; j++) {
                CBateau* pBateauPlacer = bateauxPlacer[j];
                // cout << " - test avec bateau à " << pBateauPlacer->getPosition().first << " " << pBateauPlacer->getPosition().second << " de taille " << pBateauPlacer->getTaille() << endl;

                // si meme ligne que le bateau déjà placé
                if (y == pBateauPlacer->getPosition().second) {
                    int xStart = pBateauPlacer->getPosition().first - HORIZONTAL_PADDING_BOAT_PLACEMENT;
                    int xEnd = pBateauPlacer->getPosition().first + pBateauPlacer->getTaille() + HORIZONTAL_PADDING_BOAT_PLACEMENT;
                    
                    // check la collision
                    if ((x + taille >= xStart) && (x <= xEnd)) {
                        // cout << "    - Collision horizontale" << endl;
                        collision = true;
                        break;
                    }
                }
            }        

            if (!collision) {
                // cout << "Placé !" << endl;
                pBateau->setPosition(x, y);
                bateauxPlacer[nbBateauPlacer] = pBateau;
                nbBateauPlacer++;
                placer = true;
            }
        }

        if (!placer) {
            // cout << "ERREUR : impossible de placer tout les bateaux !" << endl;
            processusRater = true;
            break;
        }
    }

    return processusRater;
}

/**********************************************************************/
