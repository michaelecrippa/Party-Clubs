#include "../Base Club/Club.h"
#include "HouseClub.h"
#include "../../Resources/Constants.h"
#include "../../Resources/Messages.h"

//House club has no limitation to number of people in it
HouseClub::HouseClub() : Club(INT32_MAX, HOUSE_MIN_WHISKY_PRICE, HOUSE_MIN_VODKA_PRICE) {
	numOfDjs = -1;
}
HouseClub::HouseClub(HouseClub&& other) noexcept : Club(std::move(other)){
	this->numOfDjs = other.numOfDjs;
}
HouseClub::HouseClub(const char* name, const double& whisky, const double& vodka, const int& djs) : Club(INT32_MAX, HOUSE_MIN_WHISKY_PRICE, HOUSE_MIN_VODKA_PRICE) {
	if (!setNewPrices(name, whisky, vodka))
		this->~HouseClub();
	if (djs < 0) {
		Messages::invalid_dj_number();
		this->~HouseClub();
	}	
	numOfDjs = djs;
}
HouseClub& HouseClub::operator=(HouseClub&& other) noexcept {
	if (this != &other) {
		this->~HouseClub();
		numOfDjs = other.numOfDjs;
		Club::operator=(std::move(other));
	}
	return *this;
}
bool HouseClub::addUser(const User& user){
	if (user.getPreferedMusic() == 0) {
		Messages::wrong_club_warning(user.getName(), 'h');
		return false;
	}
	else if (user.getYears() < LEGAL_AGE) {
		Messages::user_age_warning(user.getName());
		return false;
	}
	else if (user.getMoney() < user.getNumberOfVodkas() * getVodkaPrice() + user.getNumberOfWhiskies() * getWhiskyPrice()) {
		Messages::user_money_warning(user.getName());
		return false;
	}
	Club::addUser(user);
	return true;
}
Club* HouseClub::clone() {
	HouseClub* newHouseClub = new HouseClub(*this);
	return newHouseClub;
}