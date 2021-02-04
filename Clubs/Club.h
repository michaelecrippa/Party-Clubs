#ifndef _CLUB_H_
#define _CLUB_H_

#include "../User/User.h"
#include "../Resources/Messages.h"

class Club : protected Messages {
public:
	Club();
	Club(const int&, const double&, const double&);
	Club(const double&, const double&);
	Club(const Club& other);
	Club(Club&& other) noexcept;
	Club& operator=(const Club& other);
	Club& operator=(Club&& other) noexcept;
	virtual ~Club() = 0;

	double getVodkaPrice() const;
	double getWhiskyPrice() const;
	int getCurrentUsers() const;
	char* getName() const;

	bool isEmpty() const;

	bool addUser(const User&);
	bool removeFromClub(const char* name);
	virtual Club* clone() = 0;
protected:
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

	void resize();
	int findFirstFreeIndex() const;
	bool setWhiskyPrice(const double);
	bool setVodkaPrice(const double);
	void setName(const char*);
	int getUserCapacity() const;
};

#endif // !_CLUB_H_
