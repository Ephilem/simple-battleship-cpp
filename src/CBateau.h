#ifndef CBATEAU_H
#define CBATEAU_H

#include "BiblioStd.h"

class CBateau
{
private:
    int m_taille;
    string m_nom;
    pair<int, int> m_position;
    bool* m_pDegats;

public:
    CBateau();
    CBateau(const CBateau& bateau);
    CBateau(string nom, pair<int, int> postition, int taille);
    ~CBateau();

    // Getter
    int getTaille();
    string getNom();
    pair<int, int> getPosition();
    bool estCoule();
    
    // Setter
    void setPosition(int i, int j);
    void tirAdverse(pair<int, int> tir); 


    // TODO: Supprimer cette methode
    void afficher();

};

#endif // CBATEAU_H