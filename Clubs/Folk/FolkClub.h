#ifndef _FOLKCLUB_H_
#define _FOLKCLUB_H_

#include "../../User/User.h"
#include "../Club.h"

class FolkClub : public Club {
public:
	FolkClub();
	FolkClub(const char*, const double&, const double&, const char*);
	FolkClub(const FolkClub&);
	FolkClub& operator=(const FolkClub&);
	~FolkClub();
	Club* clone();

	void setPerformer(const char*);
	char* getPerformer() const;

	bool addUser(User&);
	bool hasPerformer() const;
	bool isFull() const;
protected:
private:
	char* performer;

	void erase();
	void copyFrom(const FolkClub&);

};

#endif // !_FOLKCLUB_H_