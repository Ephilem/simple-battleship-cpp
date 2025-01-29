#ifndef CARMADA_H
#define CARMADA_H

#include "BiblioStd.h"
#include "CBateau.h"

#define HORIZONTAL_PADDING_BOAT_PLACEMENT 1
#define FLOTILLE_FILE "../ws/flotille.txt"

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
};

#endif // CARMADA_H