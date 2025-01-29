#ifndef CARMADA_H
#define CARMADA_H

#include "BiblioStd.h"
#include "CBateau.h"

#define HORIZONTAL_PADDING_BOAT_PLACEMENT 1
#define MAX_ESSAIS 100

class CArmada {
private:
    vector<CBateau> m_listeBateaux;

// Getter & Setter
public:
    void ajouterBateau(CBateau& unBat);
    CBateau* getBateau(int i);  
    int getEffectifTotal();
    int getNbreTotCases();
    int getEffectif();
    void getArmadaFromFile();
    bool placerAleatoirement();
    
private:
    bool testPosition(int i, int j, int taille);
};

#endif // CARMADA_H