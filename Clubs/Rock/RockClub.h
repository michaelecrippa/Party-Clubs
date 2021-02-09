#ifndef _ROCKCLUB_H_
#define _ROCKCLUB_H_

#include "../../User/User.h"
#include "../Club.h"

class RockClub : public Club {
public:
	RockClub();
	RockClub(const char*, const double&, const double&);
	RockClub(RockClub&&) = default;
	RockClub(const RockClub&) = default;
	RockClub& operator=(RockClub&&) = default;
	~RockClub() = default;

	Club* clone() override;

	bool addUser(const User&);
	bool isFull() const;
};

#endif // !_ROCKCLUB_H_