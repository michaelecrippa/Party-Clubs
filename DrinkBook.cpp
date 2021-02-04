#include "../DrinkBook/Clubs/ClubCollection.h"

int main()
{
	Clubs d;
	d.addRockClub("Stereo", 35, 50);
	User user("Miro", 27, 100, 1, 1, "everything");
	d.addToClub(user, "Stereo");
	d.addToClub(user, "Stereo");
	d.addToClub(user, "Stereo");
	d.addToClub(user, "Stereo");
	d.addToClub(user, "Stereo");
	d.addToClub(user, "Stereo");
	d.addToClub(user, "Stereo");
	d.addToClub(user, "Stereo");
	d.removeFromClub("Miro", "Stereo");

	d.addRockClub("1", 35, 50);
	d.addRockClub("2", 35, 50);
	d.addRockClub("3", 35, 50);
	d.addRockClub("4", 35, 50);
	d.addRockClub("5", 35, 50);
	d.addRockClub("6", 35, 50);
	d.addRockClub("7", 35, 50);
}

