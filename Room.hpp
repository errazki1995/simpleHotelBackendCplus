#ifndef ROOM_H
#define ROOM_H 
#include <iostream>
#include <string>
using namespace std;
class Room{
private:
	
int id;
string name;
int length;
int width; 
string color;

public:
		Room();
		Room(int id,string name,float length,float width,string color);
		//copy const
		Room(const Room &r);
	    ~Room();


	
	
	
};

#endif
