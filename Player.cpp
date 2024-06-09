#include "Player.h"

Player::Player():wound(false){}
Player::Player(string name, int max_h, int attack, int defense, int hun, int thir, int poi) :GameCharacter(name, "Player", max_h, attack, defense) {
	
	hunger = hun;
	thirst = thir;
	poison = poi;
	wound = false;
}

//setter
void Player::setCurrentRoom(Room* current_r) {
	this->currentRoom = current_r;
}
void Player::setPreviousRoom(Room* prev_r) {
	this->previousRoom = prev_r;
}
void Player::setInventory(vector<Item> i) {
	this->inventory = i;
}
void Player::setHunger(int hun) {
	if (hun < 0) {
		this->hunger = 0;
	}
	else {
		this->hunger = hun;
	}
}
void Player::setThirst(int thir) {
	if (thir < 0) {
		this->thirst = 0;
	}
	else {
		this->thirst = thir;
	}
}
void Player::setPoison(int p) {
	this->poison = p;
}
void Player::setWound(bool w) {
	this->wound = w;
}

//getter
Room* Player::getCurrentRoom() {
	return this->currentRoom;
}
Room* Player::getPreviousRoom() {
	return this->previousRoom;
}
vector<Item> Player::getInventory() {
	return this->inventory;
}
int Player::getHunger() {
	return this->hunger;
}
int Player::getThirst() {
	return this->thirst;
}
int Player::getPoison() {
	return this->poison;
}
bool Player::getWound() {
	return this->wound;
}

//Functions
void Player::addItem(Item i){
	//inventory.push_back(i);
	
	vector<Item> items;
	for (int a = 0; a < this->getInventory().size(); a++) {
		items.push_back(this->getInventory()[a]);
	}
	items.push_back(i);
	this->setInventory(items);
	this->increaseStates(i.getHealth(), i.getAttack(), i.getDefense());
}
void Player::useItem(int index) {
	if (this->getInventory()[index].getTag() == "Water") {
		cout << "You drank some water. Now your thirst state is reset!" << endl;
		this->setThirst(100);
	}
	else if (this->getInventory()[index].getTag() == "Antidote") {
		cout << "You decided to use " << this->getInventory()[index].getName() << " for detoxification. Now your poison state is 0." << endl;
		this->setPoison(0);
	}
	else if (this->getInventory()[index].getTag() == "Food") {
		cout << "You decided to eat " << this->getInventory()[index].getName() << ". Now your hunger state is reset to 100." << endl;
		this->setHunger(100);
	}
	vector<Item> items;
	
	for (int a = 0; a < this->getInventory().size(); a++) {
		if (a != index) {
			Item obj = this->getInventory()[a];
			items.push_back(obj);
		}
	}
	this->setInventory(items);
}
void Player::increaseStates(int add_h, int add_a, int add_d) {
	int max_h = this->getMaxHealth();
	int current_h = this->getCurrentHealth();
	int current_a = this->getAttack();
	int current_d = this->getDefense();
	if ((current_h + add_h) < max_h) {
		this->setCurrentHealth(current_h + add_h);
	}
	else {
		this->setCurrentHealth(max_h);
	}
	
	this->setAttack(current_a + add_a);
	this->setDefense(current_d + add_d);	 
}
void Player::changeRoom(Room* new_r) {
	Room* previous_r = this->currentRoom;
	this->setCurrentRoom(new_r);
	this->setPreviousRoom(previous_r);
}

/* Virtual function that you need to complete   */
	/* In Player, this function should show the     */
	/* status of player.                            */
bool Player::triggerEvent(Object* obj) {
	cout << "\n============STATUS============\n";
	cout << this->getTag() << "  " << this->getName() << ":" << endl;
	cout << "Max Health: " << this->getMaxHealth() << endl;
	cout << "Current Health: " << this->getCurrentHealth() << endl;
	cout << "Attack: " << this->getAttack() << endl;
	cout << "Defense: " << this->getDefense() << endl;
	cout << "Backpack: " << endl;
	for (int i = 0; i < this->getInventory().size(); i++) {
		cout << "\t" << this->getInventory()[i].getName();
		cout << "(" << this->getInventory()[i].getHealth() << ")";
		cout << "(" << this->getInventory()[i].getAttack() << ")";
		cout << "(" << this->getInventory()[i].getDefense() << ")" << endl;
	}
	cout << "Hunger state: " << this->getHunger() << endl;
	cout << "Thirst state: " << this->getThirst() << endl;
	cout << "Poison state: " << this->getPoison() << endl;
	cout << "Current location: Room " << this->getCurrentRoom()->getIndex() << endl;
	if (wound) {
		cout << "WOUNDED" << endl;
	}
	cout << "\n==============================\n" << endl;
	
	return 0;
}