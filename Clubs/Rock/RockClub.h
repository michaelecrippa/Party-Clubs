#ifndef _ROCKCLUB_H_
#define _ROCKCLUB_H_

#include "../../User/User.h"
#include "../Club.h"

class RockClub : public Club {
public:
	RockClub();
	RockClub(const char*, const double&, const double&);
	Club* clone();
	bool addUser(const User&);
	bool isFull() const;
};

#endif // !_ROCKCLUB_H_