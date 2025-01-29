#include "CArmada.h"

#define assert_expr(expr) \
    { \
        cout << " - " << #expr << "\t\t"; \
        if (expr) { \
            cout << "[OK]" << endl; \
        } else { \
            cout << "[FAILED] at " << __FILE__ << ":" << __LINE__ << endl; \
            abort(); \
        } \
    }

#define assert_expr_msg(expr, msg) \
    { \
        cout << " - " << msg << "\t\t"; \
        if (expr) { \
            cout << "[OK]" << endl; \
        } else { \
            cout << "[FAILED] at " << __FILE__ << ":" << __LINE__ << endl; \
            abort(); \
        } \
    }

void showTestTitle(string msg) {
    cout << endl << "=== " << msg << " ===" << endl; 
}

void testAjouterBateau1();
void testLectureFichier1();
void testPlacementAleatoire1();

int main() {
	// on seed une valeur fixe pour avoir des tests reproductibles
    // srand(0);

    testAjouterBateau1();
    testLectureFichier1();
    testPlacementAleatoire1();
    return 0;
}

void testAjouterBateau1() {
    showTestTitle("Test de ajouter bateau");
    CArmada armada = CArmada();
    CBateau bateau = CBateau("sous-marin", pair<int, int>(0, 0), 2);
    armada.ajouterBateau(bateau);
    
    assert_expr(armada.getEffectifTotal() == 1);
    assert_expr(armada.getNbreTotCases() == 2);
}

void testLectureFichier1() {
    showTestTitle("Test de lecture de fichier");
    CArmada armada = CArmada();
    armada.getArmadaFromFile();

    assert_expr(armada.getEffectifTotal() == 5);
    assert_expr(armada.getBateau(0)->getNom() == "porte-avion");
    assert_expr(armada.getBateau(2)->getTaille() == 3);
}

void testPlacementAleatoire1() {
    showTestTitle("Test de placement aleatoire");
    CArmada armada = CArmada();
    armada.getArmadaFromFile();
    armada.placerAleatoirement();

    cout << "Vérification des placements..." << endl;
    cout << "Dans la grille" << endl;
    // regarder si aucun bateau sort de la grille
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        CBateau* bateau = armada.getBateau(i);
        pair<int, int> position = bateau->getPosition();
        int taille = bateau->getTaille();
        assert_expr_msg(
            position.first >= 0 && position.first <= TAILLE_GRILLE - 1 - taille,
            "Bateau " + bateau->getNom() + " de taille " + to_string(taille) + " à la position (" + to_string(position.first) + ", " + to_string(position.second) + ")"
        )
    }

    cout << "Aucune collision" << endl;
    // regarder si aucun bateau ce fait collision (+padding)
    bool aucuneCollision = true;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        CBateau* bateau = armada.getBateau(i);
        pair<int, int> position = bateau->getPosition();
        int taille = bateau->getTaille();
        
        bool collision = false;
        for (int j = 0; j < armada.getEffectifTotal(); j++) {
            CBateau* bateauAComparer = armada.getBateau(j);
            pair<int, int> positionAComparer = bateauAComparer->getPosition();

            if (i==j) continue; // eviter de comparer les deux meme bateau

            if (position.second == positionAComparer.second) {
                int xStart = positionAComparer.first - HORIZONTAL_PADDING_BOAT_PLACEMENT;
                int xEnd = positionAComparer.first + bateauAComparer->getTaille() + HORIZONTAL_PADDING_BOAT_PLACEMENT;
                
                if ((position.first + taille >= xStart) && (position.first <= xEnd)) {
                    collision = true;
                    break;
                }
            }
        }

        if (collision) {
            cout << "- Erreur de placement pour le bateau " << bateau->getNom() << "(" << i << ")" << endl;
            aucuneCollision = false;
        }
    }

    if (!aucuneCollision) {
        cout << "COLLISION DETECTER!!!" << endl;
        for (int i = 0; i < armada.getEffectifTotal(); i++) {
            CBateau* bateau = armada.getBateau(i);
            cout << "- " << bateau->getNom() << " " << bateau->getPosition().first << " " << bateau->getPosition().second << " taille=" << bateau->getTaille();
        }
    }
}
