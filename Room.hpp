#ifndef ROOM_H
#define ROOM_H 
#include <iostream>
#include <string>
using namespace std;
class Room{
private:
	
int id;
string name;
float length;
float width; 
string color;

public:
	    //const
		Room();
		Room(int id,string name,float length,float width,string color);
		//copy const
		Room(const Room &r);
		//getters
		int getId();
		string getName();
		float getLength();
		float getWidth();
		string getColor();
		//setters
		void setId(int id);
		void setName(string name);
		void setWidth(float width);
		void setLength(float length);
		void setColor(string color);
		//ostream operator
		friend ostream& operator<<(ostream& ost,const Room& r);

		//dest
	    ~Room();


	
	
	
};

#endif
