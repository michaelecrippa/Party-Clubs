#include <iostream>
#include <algorithm>

#include "../User/User.h"
#include "../Resources/Constants.h"


void User::erase() {
	if (!isEmpty()) {
		delete[] name;
		name = nullptr;
	}	
	years = money = whiskies = vodkas = -1;
}
void User::copyFrom(const User& other) {
	if (!other.isEmpty()) {
		int len = strlen(other.name);
		name = new char[len+1];
		strcpy(name, other.name);
		name[len] = '\0';
	}
	else  {
		name = nullptr;
		years = other.years;
		money = other.money;
		whiskies = other.whiskies;
		vodkas = other.vodkas;
		music = other.music;
	}
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
	name = nullptr;
	years = money = whiskies = vodkas = -1;
	music = everything;

	copyFrom(other);
	other.erase();
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
		copyFrom(other);
		other.erase();
	}
	return *this;
}
User::~User() {
	erase();
}

User::User(const char* name, const short& years, const double& money, const int& whiskies, const int& vodkas, const char* music) {
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
	else if (!strcmp("everything", music))
		this->music = everything;
	else
		std::cout << "Invalide type of music!" << std::endl;
}

bool User::isEmpty() const {
	return name == nullptr;
}
bool User::checkForMatch(const char* name) const {
	return !strcmp(name, this->name);
}
void User::payToTheGuard() {
	if (this->money >= GUARD_FEE) this->money -= GUARD_FEE;
}