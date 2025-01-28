#include "CBateau.h"

void testNormal_constructeurVide();
void testNormal_constructeur();
void testNormal_changePosition();
void testNormal_tirAdverse();
void testNormal_estCoule();

int main() {    

    cout << "Test de la classe CBateau" << endl;

    testNormal_constructeurVide();
    testNormal_constructeur();
    testNormal_changePosition();
    testNormal_tirAdverse();
    testNormal_estCoule();

    cout << endl << COLORED_BG_TEXT(" Test de la classe CBateau Terminer ! ", COLOR_WHITE, BG_BRIGHT_GREEN) << endl;
    return 0;
}

void printTestTitle(string title) {
    cout << endl << STYLED_TEXT("=== " << title << " ===", STYLE_BOLD, COLOR_WHITE) << endl;
}

void assert(bool condition, string message) {
    if (condition) {
        cout << COLORED_TEXT("✔ " << message, COLOR_GREEN) << endl;
    } else {
        cout << COLORED_TEXT("✘ " << message, COLOR_RED) << endl;
    }
}

void testNormal_constructeurVide() {
    printTestTitle("Test du constructeur vide");
    CBateau bateau = CBateau();
    bateau.afficher();
    
}

void testNormal_constructeur() {
    printTestTitle("Test du constructeur");
    CBateau bateau = CBateau(NULL, pair<int, int>(2, 3), 5);
    bateau.afficher();
}

void testNormal_changePosition() {
    printTestTitle("Test du changement de position");
    CBateau bateau = CBateau("croiseur", pair<int, int>(2,3), 3);
    bateau.afficher();
    cout << COLORED_TEXT("Changement de position en (4, 5)", COLOR_GRAY) << endl;
    bateau.setPosition(4, 5);
    bateau.afficher();
}

void testNormal_tirAdverse() {
    printTestTitle("Test de la méthode tirAdverse");
    CBateau bateau = CBateau("sous-marin", pair<int, int>(2, 3), 3);
    bateau.afficher();
    cout << COLORED_TEXT("Tir adverse en (2, 3)", COLOR_GRAY) << endl;
    bateau.tirAdverse(pair<int, int>(2, 3));
    bateau.afficher();
    cout << COLORED_TEXT("Tir adverse en (3, 3)", COLOR_GRAY) << endl;
    bateau.tirAdverse(pair<int, int>(3, 3));
    bateau.afficher();
    cout << COLORED_TEXT("Tir adverse en (4, 4)", COLOR_GRAY) << endl;
    bateau.tirAdverse(pair<int, int>(4, 4));
    bateau.afficher();
}

void testNormal_estCoule() {
    printTestTitle("Test de la méthode estCoule");
    CBateau bateau = CBateau("sous-marin", pair<int, int>(2, 3), 2);
    bateau.afficher();
    cout << "Bateau coulé ? ";
    if (bateau.estCoule()) {
        cout << COLORED_TEXT(" OUI ", COLOR_GREEN);
    } else {
        cout << COLORED_TEXT(" NON ", COLOR_RED);
    }
    cout << endl;
    cout << COLORED_TEXT("Tir adverse en (2, 3) et en (3, 3)", COLOR_GRAY) << endl;
    bateau.tirAdverse(pair<int, int>(2, 3));
    bateau.tirAdverse(pair<int, int>(3, 3));
    bateau.afficher();
    cout << "Bateau coulé ? ";
    if (bateau.estCoule()) {
        cout << COLORED_TEXT(" OUI ", COLOR_GREEN);
    } else {
        cout << COLORED_TEXT(" NON ", COLOR_RED);
    }
    cout << endl;
}


