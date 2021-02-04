#ifndef _CLUBCOLLECTION_H_
#define _CLUBCOLLECTION_H_

#include "../Clubs/Club.h"
#include "../Clubs/Folk/FolkClub.h"
#include "../Clubs/Rock/RockClub.h"
#include "../Clubs/House/HouseCLub.h"
#include "../User/User.h"
#include "../Resources/Messages.h"

class Clubs : protected Messages{
private:
	int elements;
	int current;
	Club** collection;

	void resize();
	void erase();
	void copyFrom(const Clubs&);
	int firstFreeIndex();
public:
	Clubs();
	Clubs(const Clubs&);
	Clubs& operator=(const Clubs&);
	~Clubs();

	int getNumberOfClubs() const;
	void addFolkClub(const char* name, const double& whiskyPrice, const double& vodkaPrice,const char* performerName);
	void addHouseClub(const char* name, const double& whiskyPrice, const double& vodkaPrice, const int& numberOfDjs);
	void addRockClub(const char* name, const double& whiskyPrice, const double& vodkaPrice);
	void add(Club*);

	bool removeFromClub(const char* userName, const char* clubName);
	bool addToClub(const User&, const char* clubName);
};

#endif // !_CLUBCOLLECTION_H_