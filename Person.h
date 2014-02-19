#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/*
	To be particular, each Person object is 
	responsible for maintaining a list of its “friends,”
	 which will be other Person objects. As real-world 
	 people tend to have differing degrees of extraversion/outgoingness, 
	 each Person will have a different “capacity” for friendship.
*/

class Person
{
public:
	Person(string first, string last, int age, int friendCap);

	~Person();

	bool add(Person* p);
	string toSimpleString();
	string toFullString();
	string getFirstName();
	string getLastName();
	int getAge();
	int getFriendCap();
	Person** getFriendList(int& size);
	bool isCapped();
	Person** getUncappedFriends(int& size);


private:
	Person ** friendsList;
	int friendCap; //how many friends they can have
	string firstName;
	string lastName;
	int age;
	int howManyFriends; //how many friends have been added
};
