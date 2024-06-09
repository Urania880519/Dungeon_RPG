#include "Monster.h"
#include <Windows.h>
Monster::Monster(){}
Monster::Monster(string n, int h, int a, int d) :GameCharacter(n, "Monster", h, a, d) {}

/* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
bool Monster::triggerEvent(Object* obj) {
    cout << "=====================MONSTER ALERT!=====================" << endl;
    cout << "                       " << this->getName() << "                       " << endl;
    Player* player = dynamic_cast<Player*>(obj);
    while (this->getCurrentHealth() > 0 && player->getCurrentHealth() > 0)
    {
        cout << "What's your next action?" << endl;
        cout << "A. Attack the monster.\nB. Retreat.\n" << endl;
        char choice;
        cin >> choice;
        if ((choice == (char)'A') || (choice == (char)'a')) {
            Player* player = dynamic_cast<Player*>(obj);
            cout << "Attack" << endl;
            int p_att = player->getAttack();
            int m_d = this->getDefense();
            //p_att-m_d= loss of health each time the monster get attacked
            if (p_att - m_d > 0) {
                cout << "MONSTER'S HEALTH -" << p_att - m_d << endl;
                //this->takeDamage(p_att - m_d);
                this->setCurrentHealth(this->getCurrentHealth() - (p_att -m_d));
                this->setDefense(this->getDefense() - 5);
                cout << "The monster is trying to attack you at the same time and that makes it unable to quickly dodge your swinging sword!" << endl;
                player->setCurrentHealth(player->getCurrentHealth() - 5);
                cout << "PLAYER'S HEALTH - 5" << endl;
                cout << endl;
            }
            else if (p_att - m_d == 0) {
                cout << "The monster is too strong! Keep it up!!" << endl;
                this->setDefense(this->getDefense() - 5);
            }
            else {
                cout << "The monster is too strong! It's going to attack you!" << endl;
                this->setDefense(this->getDefense() - 5);
                int p_d = player->getDefense();
                int m_att = this->getAttack();
                if (m_att - p_d > 0) {
                    cout << "YOUR HEALTH -" << m_att - p_d << endl;
                    player->setCurrentHealth(player->getCurrentHealth() - (m_att - p_d));
                    player->setDefense(player->getDefense() - 5);
                    cout << "Don't blame yourself! You also gave it some damages!" << endl;
                    this->setCurrentHealth(this->getCurrentHealth() - 5);
                    cout << "MONSTER'S HEALTH -5" << endl;
                    cout << endl;
                }
                else {
                    cout << "The monster is not able to hurt you! But it's lowering your defense! Be careful!" << endl;
                    player->setDefense(player->getDefense() - 5);
                    cout << "Come on! Fight it back!\n" << endl;
                }
                
            }

        }
        else if ((choice == (char)'B') || (choice == (char)'b')) {
            Player* player = dynamic_cast<Player*>(obj);
            player->changeRoom(player->getPreviousRoom());
            player->setCurrentHealth(player->getCurrentHealth() - 10);
            cout << "You're now in the previous room." << endl;
            break;
        }
        else {
            cout << "Unrecognized choice." << endl;
            this->triggerEvent(obj);
        }

        if (this->getCurrentHealth() <= 0) {
            cout << "YOU WON THE BATTLE!\n" << endl;
            
        }
        else if (player->getCurrentHealth() <= 0) {
            cout << "You are defeated by the monster.\n" << endl;
        }
    }
    return 0;
}


bool Monster::triggerPoison(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);
    cout << "=====================POISONOUS MONSTER ALERT!=====================" << endl;
    Sleep(1000);
    if (this->getCurrentHealth() > 0 && player->getCurrentHealth() > 0)
    {
        cout << "You are biten by the " << this->getName() << endl;

        int p_d = player->getDefense();
        int m_att = this->getAttack();
        if ((m_att - p_d) > 0) {
            player->setCurrentHealth(player->getCurrentHealth() - (m_att - p_d));
        }
        
        if (this->getName() == "Vampire") {
            cout << "Your poison state is now " << player->getPoison() + 15 << endl;
            player->setPoison(15);
            cout << "POISON +15/CURRENT HEALTH -15\n" << endl;

            player->setCurrentHealth(player->getCurrentHealth() - 15);
            
        }
        player->triggerEvent(player);
        
        
    }
    return 0;
}