#include "Object.h"
Object::Object(){}
Object::Object(string name, string tag) :name(name), tag(tag) {}

//setter
void Object::setName(string n){
	name = n;
}
void Object::setTag(string t) {
	tag = t;
}
//getter
string Object::getName() {
	return name;
}
string Object::getTag() {
	return tag;
}

//triggerPoison
bool Object::triggerPoison(Object* obj) {
	return 0;
}