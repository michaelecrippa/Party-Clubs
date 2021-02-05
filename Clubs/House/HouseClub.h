#ifndef _HOUSECLUB_H_
#define _HOUSECLUB_H_

#include "../../User/User.h"
#include "../Club.h"

class HouseClub : public Club {
	int numOfDjs;
public:
	HouseClub();
	HouseClub(const char*, const double&, const double&, const int&);
	HouseClub(HouseClub&&) noexcept;
	HouseClub(const HouseClub&) = default;
	HouseClub& operator=(HouseClub&&) noexcept;
	~HouseClub();
	bool addUser(const User&);
	Club* clone();
};

#endif // _HOUSECLUB_H_