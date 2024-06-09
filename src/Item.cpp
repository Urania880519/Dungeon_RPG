#include "Item.h"

Item::Item(){}
Item::Item(string n, string t, int h, int att, int def) :Object(n, t) {
	health = h;
	attack = att;
	defense = def;
}
//setter
void Item::setHealth(int h) {
	this->health = h;
}
void Item::setAttack(int a) {
	this->attack = a;
}
void Item::setDefense(int d) {
	this->defense = d;
}
//getter
int Item::getHealth() {
	return this->health;
}
int Item::getAttack() {
	return this->attack;
}
int Item::getDefense() {
	return this->defense;
}

/* Virtual function that you need to complete    */
/* In Item, this function should deal with the   */
/* pick up action. You should add status to the  */
/* player.                                       */
bool Item::triggerEvent(Object* obj) {
	cout << "===========ITEM FOUND!===========" << endl;
	cout << "This is a/an " << this->getName() << "(" << this->getTag() << ")." << endl;
	cout << "\tHealth- " << this->getHealth() << endl;
	cout << "\tAttack- " << this->getAttack() << endl;
	cout << "\tDefense- " << this->getDefense() << endl;

	Item new_i = Item(this->getName(), this->getTag(), this->getHealth(), this->getAttack(), this->getDefense());
	Player * player = dynamic_cast<Player*>(obj);
	char choice;
	cout << "A:Pick it up\n" << "B:Leave" << endl;
	cin >> choice;
	if ((choice == (char)"A") || (choice == (char)"a")) {
		cout << "Item collected!";
		cout << "----> health +" << this->getHealth();
		cout << " / attack +" << this->getAttack();
		cout << " / defense + " << this->getDefense() << endl;
		player->addItem(new_i);
		player->increaseStates(this->getHealth(), this->getAttack(), this->getDefense());
		player->triggerEvent(obj);
	}
	else if ((choice == (char)"B") || (choice == (char)"b")) {
		
	}
	else {
		cout << "Unrecognized choice." << endl;
		this->triggerEvent(obj);
	}
	return 0;
}


