#include "Person.h"
#include <stdexcept>

using namespace std;

	Person::Person(string first, string last, int age, int friendCap){
		//Check for any illegal arguments passed
		if(first.compare("") == 0){
			throw invalid_argument("Not a real first name");
		}
		this->firstName = first;

		if(last.compare("") == 0){
			throw invalid_argument("Not a real last name");
		}
		this->lastName = last;

		if(age < 0){
			throw invalid_argument("Not a proper age");
		}
		this->age = age;

		if(friendCap < 0){
			throw invalid_argument("Not a proper age");
		}
		//defines the capacity of friends they can have
		this->friendCap = friendCap;

		//Creates a new friendList of Persons
		this-> friendsList = new Person *[friendCap];
		howManyFriends = 0; //currently have no friends added
	}

	//Make sure to delete the friendList we created
	Person::~Person(){
			delete (this->friendsList);
	}

	//Allows users to ass more friends as long as they have space 
	//and it is not themselves
	bool Person::add(Person* p){
		if((howManyFriends < friendCap) && (this!= p)){
			friendsList [howManyFriends] = p;
			howManyFriends++;
			return true;
		}
		else
			return false;
	}

	//Returns name of this person
	string Person::toSimpleString(){
		ostringstream os;
		os << firstName <<" "<<lastName<<" , Age "<<age;
		return os.str();
	}

	//Returns name of friends infriendsList
	string Person::toFullString(){
		ostringstream os;
		os << this->toSimpleString() << endl << "Friends:"<<endl;
		for(int i = 0; i < howManyFriends; i++){
			os << '\t'<<this->friendsList[i]->toSimpleString()<<endl;
		}
		return os.str();
	}

	//Get person's firstName
	string Person::getFirstName(){
		return this-> firstName;
	}

	//Get person's lastName
	string Person::getLastName(){
		return this-> lastName;
	}

	//Get person's age
	int Person::getAge(){
		return this-> age;
	}

	//Get person's friendCap
	int Person::getFriendCap(){
		return this-> friendCap;
	}

	//Returns an array of all other Person objects the
	//current one considers "friends"
	Person** Person::getFriendList(int& size){
		size = this->howManyFriends;
		Person ** actualFriends = new Person *[howManyFriends];
		for(int i = 0; i < howManyFriends; i++){
			actualFriends[i] = this->friendsList[i];
		}
		return actualFriends;
	}

	//returns true if the Person is at max "friendship" capacity
	bool Person::isCapped(){
		return (howManyFriends == friendCap);
	}

	//Returns an array of all friends of the current Person 
	//with remaining "friend" capacity
	Person** Person::getUncappedFriends(int& size){
		int friendsWithCapacity = 0;
		for(int i = 0; i < howManyFriends; i++){
			if(!friendsList[i]->isCapped())
				friendsWithCapacity++;
		}
		size = friendsWithCapacity;
		Person ** friendsWCapacity = new Person *[friendsWithCapacity];
		int j = 0;
		for(int i = 0; i < howManyFriends; i++){
			if(!friendsList[i]->isCapped()){
				friendsWCapacity[j] = friendsList[i];
				j++;
			}
		}

		return friendsWCapacity;
	}
