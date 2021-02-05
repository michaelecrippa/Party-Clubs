#ifndef _MESSAGES_H_
#define _MESSAGES_H_

#include <iostream>

class Messages {
public:
protected:

	void cheap_vodka() const {
		std::cout << "Vodka too cheap!" << std::endl;
	}
	void cheap_whisky() const {
		std::cout << "Whisky too cheap!" << std::endl;
	}

	void wrong_club_warning(const void* user_name, const char& type) const {
		if (type == 'f')
			std::cout << user_name << " doesnt go to folk clubs.";
		else if (type == 'r') {
			std::cout << user_name << " doesnt go to rock clubs.";
		}
		else if (type == 'h') {
			std::cout << user_name << " doesnt go to house clubs.";
		}
		std::cout << std::endl;
	}
	void full_club_warning(const void* club_name) const{
		std::cout << club_name << " is full!" << std::endl;
	}

	void user_money_warning(const void* user_name) const {
		std::cout << user_name << " doesnt have enough money!" << std::endl;
	}
	void user_age_warning(const void* user_name) const {
		std::cout << user_name << " is underaged!" << std::endl;
	}

	void invalid_dj_number() const {
		std::cout << "Invalid number of djs!" << std::endl;
	}

	void club_warning() const {
		std::cout << "Club not found!" << std::endl;
	}
private:
};

#endif // !_MESSAGES_H_

