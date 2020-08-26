#include "ItemType.h"
#include <iostream>
using namespace std;
ItemType::ItemType() {
	
}
void ItemType::initialize(int number) {
	
	this->value = number;
	
}
void ItemType::print() {
	
	cout << getValue() << " ";
}

int ItemType::getValue() const {
	return value;

}
