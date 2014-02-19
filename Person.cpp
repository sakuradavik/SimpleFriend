#include "Person.h"
#include <stdexcept>

using namespace std;

	Person::Person(string first, string last, int age, int friendCap){
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
		this->friendCap = friendCap;

		this-> friendsList = new Person *[friendCap];
		howManyFriends = 0; //currently have no friends added
	}

	//only have to delete anything that has key word new because we allocated
	//memory for it
	//if not then we are just having pointers to memory but not having access
	//to that actual memory
	Person::~Person(){
			delete (this->friendsList);
	}

	bool Person::add(Person* p){
		if((howManyFriends < friendCap) && (this!= p)){
			friendsList [howManyFriends] = p;
			howManyFriends++;
			return true;
		}
		else
			return false;
	}

	string Person::toSimpleString(){
		ostringstream os;
		os << firstName <<" "<<lastName<<" , Age "<<age;
		return os.str();
	}

	string Person::toFullString(){
		ostringstream os;
		os << this->toSimpleString() << endl << "Friends:"<<endl;
		for(int i = 0; i < howManyFriends; i++){
			os << '\t'<<this->friendsList[i]->toSimpleString()<<endl;
		}
		return os.str();
	}

	string Person::getFirstName(){
		return this-> firstName;
	}

	string Person::getLastName(){
		return this-> lastName;
	}

	int Person::getAge(){
		return this-> age;
	}

	int Person::getFriendCap(){
		return this-> friendCap;
	}

	Person** Person::getFriendList(int& size){
		size = this->howManyFriends;
		Person ** actualFriends = new Person *[howManyFriends];
		for(int i = 0; i < howManyFriends; i++){
			actualFriends[i] = this->friendsList[i];
		}
		return actualFriends;
	}

	bool Person::isCapped(){
		return (howManyFriends == friendCap);
	}

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
