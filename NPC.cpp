#include <fstream>
#include "NPC.h"
#include <Windows.h>
using namespace std;

NPC::NPC() {}
NPC::NPC(string n, string sc, vector<Item> com):GameCharacter(n, "NPC", 100, 0, 0) {
	this->script = sc;
	this->commodity = com;
}
//setter
void NPC::setScript(string sc) {
    this->script = sc;
}
void NPC::setCommodity(vector<Item> com) {
    this->commodity = com;
}

//getter
string NPC::getScript(){
    return this->script;
}
vector<Item> NPC::getCommodity() {
    return this->commodity;
}

//Functions
void NPC::listCommodity() {
    /*print all the Item in this NPC*/
    cout << "============NPC " << this->getName() << "============" << endl;
    for (int i = 0; i < this->getCommodity().size(); i++) {
        cout << i + 1 << ". " << this->getCommodity()[i].getName() << endl;
        cout << "\thealth: " << this->getCommodity()[i].getHealth() << endl;
        cout << "\tattack: " << this->getCommodity()[i].getAttack() << endl;
        cout << "\tdefense: " << this->getCommodity()[i].getDefense() << endl;
    }
}
    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
bool NPC::triggerEvent(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);
    cout << "============You have met NPC " << this->getName() << "============" << endl;
    ifstream in;
    in.open(this->getScript());
    string temp;
    Sleep(500);
    while (getline(in, temp)) {
        cout << temp << endl;
    }
    Sleep(1000);
    char choice;
    cin >> choice;

    if (this->getName() == string("Loretta")) {
        if ((choice == (char)'A') || (choice == (char)'a')) {
            cout << "Thank god! I will help you. I have something that might help." << endl;
            cout << "COMMODITY LIST" << endl;
            for (int i = 0; i < this->getCommodity().size(); i++) {
                
                cout << this->getCommodity()[i].getName() << "(" << this->getCommodity()[i].getTag() << ")" << endl;
                cout << "\thealth: " << this->getCommodity()[i].getHealth() << endl;
                cout << "\tattack: " << this->getCommodity()[i].getAttack() << endl;
                cout<<"\tdefense: "<< this->getCommodity()[i].getDefense() << endl;
                player->addItem(this->getCommodity()[i]);
                player->increaseStates(this->getCommodity()[i].getHealth(), this->getCommodity()[i].getAttack(), this->getCommodity()[i].getDefense());
            }
            player->triggerEvent(obj);
            cout << "\nBe careful! I think that the tower had been casted a spell." << endl;
            cout << "You might be encountered with extreme climate and creepy creatures moving from one to another room." << endl;
            cout << "I wish you luck! You are my hero.\n" << endl;
        }
        else if ((choice == (char)'B') || (choice == (char)'b')) {
            
            cout << "I know that I'm asking too much..." << endl;
            cout << "Anyway, Be careful finding the way out." << endl;
        }
        else {
            cout << "Unrecognized choice." << endl;
            this->triggerEvent(obj);
        }
    }

    if (this->getName() == (string)"Dobby") {
        if ((choice == (char)'A') || (choice == (char)'a')) {
            int i = 0;
            cout << "You've chosen ";
            cout << this->getCommodity()[i].getName() << "(" << this->getCommodity()[i].getTag() << ")" << endl;
            cout << "\thealth: " << this->getCommodity()[i].getHealth() << endl;
            cout << "\tattack: " << this->getCommodity()[i].getAttack() << endl;
            cout << "\tdefense: " << this->getCommodity()[i].getDefense() << endl;
            player->addItem(this->getCommodity()[i]);
            player->increaseStates(this->getCommodity()[i].getHealth(), this->getCommodity()[i].getAttack(), this->getCommodity()[i].getDefense());
            player->triggerEvent(obj);
        }
        else if ((choice == (char)'B') || (choice == (char)'b')) {
            int i = 1;
            cout << "You've chosen ";
            cout << this->getCommodity()[i].getName() << "(" << this->getCommodity()[i].getTag() << ")" << endl;
            cout << "\thealth: " << this->getCommodity()[i].getHealth() << endl;
            cout << "\tattack: " << this->getCommodity()[i].getAttack() << endl;
            cout << "\tdefense: " << this->getCommodity()[i].getDefense() << endl;
            player->addItem(this->getCommodity()[i]);
            player->increaseStates(this->getCommodity()[i].getHealth(), this->getCommodity()[i].getAttack(), this->getCommodity()[i].getDefense());
            player->triggerEvent(obj);
        }
        else {
            cout << "Unrecognized choice." << endl;
            this->triggerEvent(obj);
        }
    }

    if (this->getName() == (string)"Firenze") {
        if ((choice == (char)'A') || (choice == (char)'a')) {
            int i = 0;
            cout << "You've  recieve a bottle of ";
            cout << this->getCommodity()[i].getName() << "(" << this->getCommodity()[i].getTag() << ")" << endl;
            cout << "\thealth: " << this->getCommodity()[i].getHealth() << endl;
            cout << "\tattack: " << this->getCommodity()[i].getAttack() << endl;
            cout << "\tdefense: " << this->getCommodity()[i].getDefense() << endl;
            cout << "Unicorn's blood is an antidote to all kinds of poison. Use it if you're posioned." << endl;
            player->addItem(this->getCommodity()[i]);
            player->increaseStates(this->getCommodity()[i].getHealth(), this->getCommodity()[i].getAttack(), this->getCommodity()[i].getDefense());
            player->triggerEvent(obj);
        }
        else if ((choice == (char)'B') || (choice == (char)'b')) {
            cout << "You will move on without getting Firenze's help." << endl;
        }
        else {
            cout << "Unrecognized choice." << endl;
            this->triggerEvent(obj);
        }

    }
    return 0;
   
}

//Loretta princess_script.txt
//Dobby elf_script.txt
//Firenze centaur_script.txt