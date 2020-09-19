#include "Room.hpp"
#include <iostream>

using namespace std;
Room::Room(){
	
	cout<<"Building a room !"<<endl;
	
}

//copy constr
Room::Room(Room &r){
	id=r.id;
	name=r.name;
	length= r.length;
	width= r.width;
	color=r.color;

}
Room::Room(int id,string name,float length,float width,string color){
	id=id;
	name=name;
	length= length;
	width=width;
	color=color;
	cout<<"Room id:"<<id<<" Name: "<<name<<" length:<"<<length<<"> width <"<<width<<"> color : ["<<color<<"]"<<endl;
}

Room::~Room(){
	cout<<"Destructing the room !"<<endl;
}
