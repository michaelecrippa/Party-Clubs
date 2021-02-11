#include "ClubCollection.h"
#include "../../Resources/Messages.h"

void Clubs::erase() {
	for (int i = 0; i < current; i++) {
		delete collection[i];
	}
	delete[] collection;
	current = 0;
	elements = 0;
}
void  Clubs::copyFrom(const Clubs& other) {

	elements = other.elements;
	current = other.current;
	collection = new Club * [elements];
	for (int i = 0; i < current; i++) {
		collection[i] = other.collection[i]->clone();
	}
}
void Clubs::resize() {
	elements *= 2;
	Club** cpy = new Club* [elements];
	for (size_t i = 0; i < current; i++) {
		cpy[i] = std::move(collection[i]);
	}
	for (size_t i = current; i < elements; i++){
		cpy[i] = nullptr;
	}
	delete[] collection;
	collection = cpy;
}
int Clubs::firstFreeIndex() {
	for (size_t i = 0; i < current; i++)
		if (collection[i] == nullptr)
			return i;
	return current;
}
Clubs::Clubs() {
	current = 0;
	elements = 8;
	collection = new Club* [elements];
	for (int i = 0; i < elements; i++)
		collection[i] = nullptr;
}
Clubs::Clubs(const Clubs& other) {
	copyFrom(other);
}
Clubs& Clubs::operator=(const Clubs& other) {
	if (this != &other) {
		erase();
		copyFrom(other);
	}
	return *this;
}
Clubs::~Clubs() {
	erase();
}
void Clubs::add(Club* current_club) {
	int index = firstFreeIndex();
	if (index >= this->current && this->current >= elements / 2)
		resize();
	collection[index] = std::move(current_club);
	if (index >= this->current)
		++this->current;
}
void Clubs::addFolkClub(const char* name, const double& whisky, const double& vodka,const char* performer) {
	FolkClub* obj = new FolkClub(name,whisky,vodka,performer);
	add(obj);
}
void Clubs::addHouseClub(const char* name, const double& whisky, const double& vodka, const int& djs) {
	HouseClub* obj = new HouseClub(name, whisky, vodka, djs);
	add(obj);
}
void Clubs::addRockClub(const char* name, const double& whisky, const double& vodka) {
	RockClub* obj = new RockClub(name, whisky, vodka);
	add(obj);
}
int Clubs::getNumberOfClubs() const {
	return current;
}
bool Clubs::removeFromClub(const char* userName,const char* clubName) {
	for (int i = 0; i < current; i++) {
		if (!strcmp(collection[i]->getName(), clubName)) 
			return collection[i]->removeFromClub(userName);		
	}
	Messages::club_warning();
	return false;
}
//without forwarding (only cpy constructor invoked)
//bool Clubs::addToClub(User& user,const char* clubName) {
//	for (int i = 0; i < current; i++) {
//		if (!strcmp(collection[i]->getName(), clubName))
//			return collection[i]->addUser(std::forward(user));
//	}
//	Messages::club_warning();
//	return false;
//}
