#include "GameCharacter.h"

GameCharacter::GameCharacter() :Object() {}
GameCharacter::GameCharacter(string n, string t, int max_h, int att, int def):Object(n, t){
	maxHealth = max_h;
	currentHealth = max_h;
	attack = att;
	defense = def;
}
bool GameCharacter::checkIsDead(){
	if (currentHealth <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int GameCharacter::takeDamage(int damage){
	int new_h = currentHealth - damage;
	this->setCurrentHealth(new_h);
	return new_h;
}

//setter
void GameCharacter::setMaxHealth(int max_h) {
	this->maxHealth = max_h;
}
void GameCharacter::setCurrentHealth(int current_h) {
	if (current_h > maxHealth) {
		this->currentHealth = maxHealth;
	}
	else {
		this->currentHealth = current_h;
	}
}
void GameCharacter::setAttack(int att) {
	this->attack = att;
}
void GameCharacter::setDefense(int def) {
	this->defense = def;
}

//getter

int GameCharacter::getMaxHealth() {
	return this->maxHealth;
}
int GameCharacter::getCurrentHealth(){
	return this->currentHealth;
}
int GameCharacter::getAttack() {
	return this->attack;
}
int GameCharacter::getDefense() {
	return this->defense;
}