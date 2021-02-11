#ifndef _USER_H_
#define _USER_H_

#include "../Resources/Messages.h"

enum Music { folk = 0, rock, house, everything };

class User {
public:
	User();
	User(const char* user_name, const short& years, const double& money, const int& number_of_whiskies, const int& number_of_vodkas, const char* type_music);
	User(const User&) ;
	User(User&& other) noexcept;
	User& operator=(const User&);
	User& operator=(User && other) noexcept;
	~User();

	char* getName() const;
	short getYears() const;
	double getMoney() const;
	//
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
	//compare user_name to given name
	bool checkUserName(const char* name) const;

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