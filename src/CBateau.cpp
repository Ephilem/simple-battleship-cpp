#include "CBateau.h"

CBateau::CBateau() {
    m_taille = 0;
    m_nom = "";
    m_position = pair<int, int>(0, 0);
    m_pDegats = nullptr;
}

CBateau::CBateau(string nom, pair<int, int> position, int taille) {
    if (taille <= 0) {
        cout << "Erreur: la taille du bateau doit être supérieure à 0" << endl;
        taille = 0;
    } 
    if (nom == "") {
        cout << "Erreur: le nom du bateau ne doit pas être vide ou NULL" << endl;
        nom = "";
    }
    
    m_nom = nom;
    m_taille = taille;
    setPosition(position.first, position.second);
    
    m_pDegats = new bool[taille];
    for (int i = 0; i < taille; i++) {
        m_pDegats[i] = false;
    }
}

CBateau::CBateau(const CBateau& bateau) {
    m_taille = bateau.m_taille;
    m_nom = bateau.m_nom;
    m_position = bateau.m_position;
    
    m_pDegats = new bool[m_taille];
    for (int i = 0; i < m_taille; i++) {
        m_pDegats[i] = bateau.m_pDegats[i];
    }
}

/**********************************************************************/

int CBateau::getTaille() {
    return m_taille;
}

string CBateau::getNom() {
    return m_nom;
}

pair<int, int> CBateau::getPosition() {
    return m_position;
}

bool CBateau::estCoule() {
    bool coule = true;
    for (int i = 0; i < m_taille; i++) {
        if (!m_pDegats[i]) {
            coule = false;
            break;
        }
    }
    
    return coule;
}

/**********************************************************************/

void CBateau::setPosition(int i, int j) {
    // test si le bateau rentre dans la grille
    int max_x = TAILLE_GRILLE - 1 - m_taille;
    int max_y = TAILLE_GRILLE - 1;
    if (i < 0 || i > max_x || j < 0 || j > max_y) {
        cout << "Erreur: le bateau de taille " << m_taille << " ne rentre pas dans la grille avec la position (" << i << ", " << j << ")" << endl;
        return;
    }
    m_position = pair<int, int>(i, j);
}

void CBateau::tirAdverse(pair<int, int> tir) {
    // récupérer les coordonnées de tir relatif à l'origine du bateau
    int i = tir.first - m_position.first;
    int j = tir.second - m_position.second;
    
    if (j == 0 && // si le tir s'effectue sur la meme ligne
        i >= 0 && i < m_taille) { // si le tir est dans la taille du bateau
        m_pDegats[i] = true;
    }
}

void CBateau::afficher() {
    
    cout << "🛥  " << STYLED_TEXT(m_nom, STYLE_UNDERLINE, COLOR_WHITE);
    cout << COLORED_TEXT(" (" << m_position.first << ", " << m_position.second << ")", COLOR_GRAY) << " :" << endl;

    if (m_taille == 0) {
        cout << COLORED_TEXT("Bateau vide", COLOR_GRAY) << endl;
        return;
    } else {
        for (int i = 0; i < m_taille; i++) {
            if (m_pDegats[i]) {
                cout << STYLED_TEXT("X", STYLE_BOLD, COLOR_RED) << " ";
            } else {
                cout << STYLED_TEXT("B", STYLE_BOLD, COLOR_GREEN) << " ";
            }
        }
        cout << endl;
    }
}

/**********************************************************************/

CBateau::~CBateau() {
    delete[] m_pDegats;
}

