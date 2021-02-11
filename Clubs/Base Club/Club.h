#ifndef _CLUB_H_
#define _CLUB_H_

#include "../../User/User.h"
#include "../../Resources/Messages.h"

class Club : protected Messages {
public:
	Club();
	Club(const int& capacity, const double& whisky_price, const double& vodka_price);
	//used only for HouseClub
	//Club(const double& whisky_price, const double& vodka_price);
	virtual ~Club() = 0;

	double getVodkaPrice() const;
	double getWhiskyPrice() const;
	//users currently in the club
	int getCurrentUsers() const;
	char* getName() const;

	bool isEmpty() const;

	bool addUser(const User&);
	bool addUser(User&&);
	bool removeFromClub(const char* user_name);
	virtual Club* clone() = 0;
protected:
	Club(const Club& other);
	Club(Club&& other) noexcept;
	Club& operator=(const Club& other);
	Club& operator=(Club&& other) noexcept;

	bool setNewPrices(const char*, double, double);
private:
	char* name;

	int current;
	int userCapacity;

	double minWhiskyPrice;
	double minVodkaPrice;

	User* users;

	void erase();
	void copyFrom(const Club&);
	void move_(Club&&);

	void resize();
	//returns first free index where we can add new user
	int findFirstFreeIndex() const;

	bool setWhiskyPrice(const double);
	bool setVodkaPrice(const double);
	void setName(const char*);

	int getUserCapacity() const;
};

#endif // !_CLUB_H_
