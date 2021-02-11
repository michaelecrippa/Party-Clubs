#include <iostream>
#include <algorithm>

#include "../User/User.h"
#include "../Resources/Constants.h"


void User::erase() {
	if (isEmpty()) return;
	delete[] name;
	name = nullptr;
}
void User::copyFrom(const User& other) {
	if (other.isEmpty()) return;

	int len = strlen(other.name);
	name = new char[len + 1];
	strcpy(name, other.name);
	name[len] = '\0';

	years = other.years;
	money = other.money;
	whiskies = other.whiskies;
	vodkas = other.vodkas;
	music = other.music;
}
void User::move_(User&& other) {
	this->name = std::move(other.name);
	this->years = std::move(other.years);
	this->money = std::move(other.money);
	this->whiskies = std::move(other.whiskies);
	this->vodkas = std::move(other.vodkas);
	this->music = std::move(other.music);
	other.name = nullptr;
}
User::User() {
	name = nullptr;
	years = money = whiskies = vodkas = -1;
	music = everything;
}
User::User(const User& other) {
	copyFrom(other);
}
User::User(User&& other) noexcept { 
	move_(std::move(other));
}
User& User::operator=(const User& other) {
	if (this != &other) {
		erase();
		copyFrom(other);
	}
	return *this;
}
User& User::operator=(User&& other) noexcept {
	if (this != &other) {
		erase();
		move_(std::move(other));
	}
	return *this;
}
User::~User() {
	erase();
}

User::User(const char* name, const short& years, const double& money, const int& whiskies, const int& vodkas, const char* music) : User() {
	setName(name);
	setYears(years);
	setMoney(money);
	setNumberOfWhiskies(whiskies);
	setNumberOfVodkas(vodkas);
	setPreferedMusic(music);
}

char* User::getName() const {
	return name;
}
short User::getYears() const {
	return years;
}
double User::getMoney() const {
	return money;
}
int User::getNumberOfWhiskies() const {
	return whiskies;
}
int User::getNumberOfVodkas() const {
	return vodkas;
}
int User::getPreferedMusic() const {
	return music;
}

void User::setName(const char* name) {
	if (!isEmpty()) {
		delete[] this->name;
	}
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
	this->name[len] = '\0';
}
void User::setYears(const short& years) {
	if (years > 0 && years < 120) this->years = years;
}
void User::setMoney(const double& money) {
	if (money >= 0) this->money = money;
}
void User::setNumberOfWhiskies(const int& whiskies) {
	if (whiskies >= 0) this->whiskies = whiskies;
}
void User::setNumberOfVodkas(const int& vodkas) {
	if (vodkas >= 0) this->vodkas = vodkas;
}
void User::setPreferedMusic(const char* music) {
	if (!strcmp("folk", music))
		this->music = folk;
	else if (!strcmp("rock", music))
		this->music = rock;
	else if (!strcmp("house", music))
		this->music = house;
	else
		this->music = everything;	
}

bool User::isEmpty() const {
	return name == nullptr;
}
bool User::checkUserName(const char* name) const {
	return !strcmp(this->name, name);
}
void User::payToTheGuard() {
	if (this->money >= GUARD_FEE) this->money -= GUARD_FEE;
}