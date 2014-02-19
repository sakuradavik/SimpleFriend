#include <string>
#include <iostream>
#include <sstream>

using namespace std;

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
