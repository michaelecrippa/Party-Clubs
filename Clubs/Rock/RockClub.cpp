#include <typeindex>

#include "../Base Club/Club.h"
#include "RockClub.h"
#include "../../User/User.h"
#include "../../Resources/Constants.h"
#include "../../Resources/Messages.h"

RockClub::RockClub() : Club(ROCK_MAX_USERS, ROCK_MIN_WHISKY_PRICE, ROCK_MIN_VODKA_PRICE) {}
RockClub::RockClub(const char* name, const double& whisky, const double& vodka) : Club(ROCK_MAX_USERS, ROCK_MIN_WHISKY_PRICE, ROCK_MIN_VODKA_PRICE)  {
	if (!setNewPrices(name, whisky, vodka))
		this->~RockClub();
}
Club* RockClub::clone() {
	RockClub* newRockClub = new RockClub(*this);
	return newRockClub;
}
bool RockClub::isFull() const{
	return getCurrentUsers() == ROCK_MAX_USERS;
}
bool RockClub::addUser(const User& user) {
	if (user.getPreferedMusic() == 2) {
		Messages::wrong_club_warning(user.getName(), 'r');
		return false;
	}
	if (user.getYears() < LEGAL_AGE) {
		Messages::user_age_warning(user.getName());
		return false;
	}
	if (user.getMoney() < user.getNumberOfVodkas() * getVodkaPrice() + user.getNumberOfWhiskies() * getWhiskyPrice()) {
		Messages::user_money_warning(user.getName());
		return false;
	}

	Club::addUser(user);
	return true;
}