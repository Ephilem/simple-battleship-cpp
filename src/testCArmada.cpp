#include "CArmada.h"

#define assert_expr(expr, message) \
    { \
        cout << " - " << "#expr" << "\t"; \
        if (expr) { \
            cout << "[OK]" << endl; \
        } else { \
            cout << "[FAILED] at " << __FILE__ << ":" << __LINE__ << " " << message << endl; \
            abort(); \
        } \
    }

void testAjouterBateau1();

int main() {
    testAjouterBateau1();
    return 0;
}

void testAjouterBateau1() {
    CArmada armada = CArmada();
    CBateau bateau = CBateau("sous-marin", pair<int, int>(0, 0), 0);
    armada.ajouterBateau(bateau);
    assert_expr(armada.getEffectifTotal() == 1, "Ajout d'un bateau");
    assert_expr(armada.getNbreTotCases() == 3, "Ajout d'un bateau");
}