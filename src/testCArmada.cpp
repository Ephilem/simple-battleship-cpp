#include "CArmada.h"

#define assert_expr(expr, message) \
    { \
        cout << " - " << #expr << "\t"; \
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
    CBateau bateau = CBateau("sous-marin", pair<int, int>(0, 0), 2);
    armada.ajouterBateau(bateau);
    
    assert_expr(armada.getEffectifTotal() == 1);
    assert_expr(armada.getNbreTotCases() == 2);
}