#include "../Club.h"
#include "FolkClub.h"
#include "../../User/User.h"
#include "../../Resources/Constants.h"
#include "../../Resources/Messages.h"

FolkClub::FolkClub() : Club(FOLK_MAX_USERS, FOLK_MIN_WHISKY_PRICE, FOLK_MIN_VODKA_PRICE) {
	performer = nullptr;
}
FolkClub::FolkClub(const char* name,const double& whisky,const double& vodka, const char* performer) : Club(FOLK_MAX_USERS, FOLK_MIN_WHISKY_PRICE, FOLK_MIN_VODKA_PRICE) {
	setPerformer(performer);
	if (!setNewPrices(name, whisky, vodka))
		this->~FolkClub();
}
FolkClub::FolkClub(const FolkClub& other) {
	copyFrom(other);	
}

FolkClub& FolkClub::operator=(const FolkClub& other) {
	if (this != &other)
	{
		erase();
		copyFrom(other);
	}
	return *this;
}
FolkClub::~FolkClub() {
	erase();
}

void FolkClub::erase() {
	if (!hasPerformer())
		return;
	delete[] performer;
	performer = nullptr;
}
void FolkClub::copyFrom(const FolkClub& other) {
	if (!other.hasPerformer())
		return;
	size_t len  = strlen(other.performer);
	performer = new char[len + 1];
	strcpy(performer, other.performer);
	this->performer[len] = '\0';
}
bool FolkClub::hasPerformer() const {
	return !(performer == nullptr);
}
void FolkClub::setPerformer(const char* performer) {
	if (hasPerformer())
		delete[] this->performer;
	size_t len = strlen(performer);
	this->performer = new char[len + 1];
	strcpy(this->performer, performer);
	this->performer[len] = '\0';
}
char* FolkClub::getPerformer() const {
	return performer;
}
bool FolkClub::isFull() const{
	return getCurrentUsers() == FOLK_MAX_USERS;
}
bool FolkClub::addUser(User& user) {
	if (user.getPreferedMusic() == 1)  {
		Messages::wrong_club_warning(user.getName(), 'f');
		return false;
	}
	else if (isFull()) {
		Messages::full_club_warning(this->getName());
		return false;
	}
	else if (user.getYears() < LEGAL_AGE)
	{
		if (user.getMoney() < GUARD_FEE + user.getNumberOfVodkas() * getVodkaPrice() + user.getNumberOfWhiskies() * getWhiskyPrice()) {
			Messages::user_money_warning(user.getName());
			return false;
		}
		else {
			user.payToTheGuard();
			Club::addUser(user);
			return true;
		}
	}
	else if (user.getMoney() < user.getNumberOfVodkas() * getVodkaPrice() + user.getNumberOfWhiskies() * getWhiskyPrice()) {
		Messages::user_money_warning(user.getName());
		return false;
	}
	else 
	{
		Club::addUser(user);
		return true;
	}		
}
Club* FolkClub::clone() {
	FolkClub* newFolkClub = new FolkClub(*this);
	return newFolkClub;
}