#include "CGui.h"

CGui::CGui() {
    m_pArmada = NULL;
    m_pCoups = NULL;
}

CGui::CGui(CArmada* pArmada, CCoups* pCoups) {
    setArmadaCoups(pArmada, pCoups);
}

CGui::CGui(const CGui& gui) {
    setArmadaCoups(gui.m_pArmada, gui.m_pCoups);
}

CGui::~CGui() {
    delete m_pArmada;
    delete m_pCoups;
}

/**********************************************************************/

void CGui::setArmadaCoups(CArmada* pArmada, CCoups* pCoups) {
    m_pArmada = pArmada;
    m_pCoups = pCoups;
}

bool CGui::positionnerBateaux() {
    return m_pArmada->placerAleatoirement();
}

pair<int, int> CGui::choisirAttaque() {
    // TODO: a
}

/**********************************************************************/

void CGui::afficheGagne() {
    cout << "Vous avez gagné !" << endl;
}

void CGui::affichePerdu() {
    cout << "Vous avez perdu !" << endl;
}

/**********************************************************************/

ostream& operator<<(ostream& os, const CGui& gui) {
    
}

/**********************************************************************/

void CGui::remplirDeuxGrilles(ostream& os) {
    cout << "Grille de jeu" << endl;
}

void CGui::afficherLaGrille(ostream& os, string jouOuAdv) {
    cout << "Grille de jeu" << endl;
}



