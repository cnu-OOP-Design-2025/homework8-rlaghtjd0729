#include <iostream>
#include "game.h" // game.h는 변경 없음

using namespace std;

// Character 포인터를 레퍼런스(참조)로 받거나, 
// Character*를 반환하는 방식으로 변경해야 정확한 체인을 구성하고 메모리 해제가 가능합니다.
// 여기서는 테스트 케이스를 명확히 분리하기 위해 각 테스트마다 객체를 생성하고 출력합니다.

void run_test(Character* initial_char, Character* decorated_char) {
    // 예상 출력 포맷에 맞게 출력
    cout << decorated_char->getDescription() 
            << " | Attack: " << decorated_char->getAttack()
            << " | Speed: " << decorated_char->getSpeed()
            << " | Defense: " << decorated_char->getDefense() << endl;
    
    // 메모리 해제: 가장 바깥쪽 데코레이터만 삭제하면 체인 전체가 삭제됨 (equip_testmentDecorator의 ~)
    delete decorated_char;
    // initial_char는 decorated_char의 체인에 포함되어 함께 삭제됩니다.
}

int main() {
    cout << "-------------------------------------------------------------" << endl;

    // 1. Knight, Armor, Boots, Sword
    Character* k1 = new Knight();
    Character* k1_decorated = new Armor(k1);
    k1_decorated = new Boots(k1_decorated);
    k1_decorated = new Sword(k1_decorated);
    run_test(k1, k1_decorated);

    // 2. Knight, Armor, Bow
    Character* k2 = new Knight();
    Character* k2_decorated = new Armor(k2);
    k2_decorated = new Bow(k2_decorated);
    run_test(k2, k2_decorated);
    
    // 3. Knight, Boots, Staff
    Character* k3 = new Knight();
    Character* k3_decorated = new Boots(k3);
    k3_decorated = new Staff(k3_decorated);
    run_test(k3, k3_decorated);

    cout << "-------------------------------------------------------------" << endl;

    // 4. Wizard, Armor, Boots, Sword
    Character* w1 = new Wizard();
    Character* w1_decorated = new Armor(w1);
    w1_decorated = new Boots(w1_decorated);
    w1_decorated = new Sword(w1_decorated);
    run_test(w1, w1_decorated);

    // 5. Wizard, Armor, Bow
    Character* w2 = new Wizard();
    Character* w2_decorated = new Armor(w2);
    w2_decorated = new Bow(w2_decorated);
    run_test(w2, w2_decorated);

    // 6. Wizard, Boots, Staff
    Character* w3 = new Wizard();
    Character* w3_decorated = new Boots(w3);
    w3_decorated = new Staff(w3_decorated);
    run_test(w3, w3_decorated);

    cout << "-------------------------------------------------------------" << endl;
    
    // 7. Archer, Armor, Boots, Sword
    Character* a1 = new Archer();
    Character* a1_decorated = new Armor(a1);
    a1_decorated = new Boots(a1_decorated);
    a1_decorated = new Sword(a1_decorated);
    run_test(a1, a1_decorated);

    // 8. Archer, Armor, Bow
    Character* a2 = new Archer();
    Character* a2_decorated = new Armor(a2);
    a2_decorated = new Bow(a2_decorated);
    run_test(a2, a2_decorated);

    // 9. Archer, Boots, Staff
    Character* a3 = new Archer();
    Character* a3_decorated = new Boots(a3);
    a3_decorated = new Staff(a3_decorated);
    run_test(a3, a3_decorated);
    
    cout << "-------------------------------------------------------------" << endl;

    // main 함수에서 명시적으로 삭제할 객체는 없음 (모두 run_test에서 처리됨)
    return 0;
}