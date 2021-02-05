#ifndef _USER_H_
#define _USER_H_

#include "../Resources/Messages.h"

enum Music { folk = 0, rock, house, everything };

class User {
public:
	User();
	User(const char*, const short&, const double&, const int&, const int&, const char*);
	User(const User&) ;
	User(User&& other) noexcept;
	User& operator=(const User&);
	User& operator=(User && other) noexcept;
	~User();

	char* getName() const;
	short getYears() const;
	double getMoney() const;
	int getNumberOfWhiskies() const;
	int getNumberOfVodkas() const;
	int getPreferedMusic() const;

	void setName(const char*);
	void setYears(const short&);
	void setMoney(const double&);
	void setNumberOfWhiskies(const int&);
	void setNumberOfVodkas(const int&);
	void setPreferedMusic(const char*);

	bool isEmpty() const;
	bool checkForMatch(const char*) const;

	void payToTheGuard();
protected:
private:
	char* name;
	short years;
	double money;
	int whiskies;
	int vodkas;
	Music music;

	void erase();
	void copyFrom(const User&);
	void move_(User&&);
};

#endif // !_USER_H_