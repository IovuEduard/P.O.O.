#include "Dog.h"
#pragma warning(disable : 4996)
void Dog::setName(const char* c) {
	strcpy(name, c);
}
void Dog::setOwnerName(const char* c) {
	strcpy(ownerName, c);
}