#include "Club.h"
#include "../User/User.h"
#include "../Resources/Messages.h"

void Club::erase() {
	if (isEmpty()) return;
	delete[] users;
	users = nullptr;

	delete[] name;
	name = nullptr;
}
void Club::copyFrom(const Club& other) {
	if (other.isEmpty()) {
		erase();
		return;
	}
	minVodkaPrice = other.minVodkaPrice;
	minWhiskyPrice = other.minWhiskyPrice;
	int len = strlen(other.name);
	name = new char[len+1];
	strcpy(name, other.name);
	name[len] = '\0';
	userCapacity = other.userCapacity;
	current = other.current;
	users = new User[userCapacity];
	for (int i = 0; i < current; i++)
		users[i] = other.users[i];
}
void Club::move_(Club&& other) {
	name = other.name;
	other.name = nullptr;

	users = other.users;
	other.users = nullptr;

	userCapacity = other.userCapacity;
	current = other.current;

	minVodkaPrice = other.minVodkaPrice;
	minWhiskyPrice = other.minWhiskyPrice;
}
void Club::resize() {
	userCapacity *= 2;
	User* cpy = new User[userCapacity];
	for (int i = 0; i < current; i++) {
		if(!users[i].isEmpty())
			cpy[i] = users[i];
	}
	delete[] users;
	users = cpy;
}

int Club::findFirstFreeIndex() const {
	for (int i = 0; i < userCapacity; i++) {
		if (users[i].isEmpty())
			return i;
	}
	return -1;
}

Club::Club(const int& capacity, const double& minWhiskyPrice, const double& minVodkaPrice) {
	name = nullptr;
	this->minWhiskyPrice = minWhiskyPrice;
	this->minVodkaPrice = minVodkaPrice;
	userCapacity = capacity;
	current = 1;
	users = new User[userCapacity];
}
Club::Club(const double& minWhiskyPrice, const double& minVodkaPrice) {
	name = nullptr;
	this->minWhiskyPrice = minWhiskyPrice;
	this->minVodkaPrice = minVodkaPrice;
	userCapacity = 8;
	current = 0;
	users = new User[userCapacity];
}
Club::Club() {
	current = userCapacity = 0;
	minVodkaPrice = minWhiskyPrice = 0;
	users = nullptr;
	name = nullptr;
}
Club::Club(const Club& other) {
	copyFrom(other);
}
Club::Club(Club&& other) noexcept{
	move_(std::move(other));
}
Club& Club::operator=(const Club& other) {
	if (this != &other) {
		erase();
		copyFrom(other);
	}
	return *this;
}
Club& Club::operator=(Club&& other) noexcept{
	if (this != &other) {
		erase();
		move_(std::move(other));
	}
	return *this;
}
Club::~Club() {
	erase();
}

bool Club::setNewPrices(const char* name, const double whiskyPrice, const double vodkaPrice) {
	if (!setVodkaPrice(vodkaPrice)) {
		Messages::cheap_vodka();
		return false;
	}
	if (!setWhiskyPrice(whiskyPrice)) {
		Messages::cheap_whisky();
		return false;
	}	
	setName(name);
	return true;
}
void Club::setName(const char* name) {
	if (!isEmpty()) {
		delete[] this->name;
	}
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
	this->name[len] = '\0';
}
bool Club::setWhiskyPrice(const double price) {
	if (price < minWhiskyPrice) return false;

	minWhiskyPrice = price;
	return true;
}
bool Club::setVodkaPrice(const double price) {
	if (price < minVodkaPrice)
		return false;
	minVodkaPrice = price;
	return true;
}

double Club::getVodkaPrice() const {
	return minVodkaPrice;
}
double Club::getWhiskyPrice() const {
	return minWhiskyPrice;
}
int Club::getCurrentUsers() const {
	return current;
}
int Club::getUserCapacity() const {
	return userCapacity;
}
char* Club::getName() const {
	return name;
}

bool Club::isEmpty() const{
	return name == nullptr;
}
bool Club::addUser(const User& user) {
	int index = findFirstFreeIndex();
	if (index < 0) return false;
	users[index] = user;
	if (index < current - 1) return true;
	++current; return true;
}
bool Club::removeFromClub(const char* name) {
	for (int i = 0; i < current; i++)
	{
		if (users[i].isEmpty())
			continue;
		if (users[i].checkForMatch(name)) {
			users[i] = User();	
			return true;
		}				
	}
	return false;
}