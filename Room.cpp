#include "Room.hpp"
#include <iostream>

using namespace std;
Room::Room(){
	
	cout<<"Building a room !"<<endl;
	
}

//copy constr
Room::Room(const Room &r){
	id=r.id;
	name=r.name;
	length= r.length;
	width= r.width;
	color=r.color;

}
Room::Room(int id1,string name1,float length1,float width1,string color1){
	id=id1;
	name=name1;
	length= length1;
	width=width1;
	color=color1;
	//cout<<"Room id:"<<id<<" Name: "<<name<<" length:<"<<length<<"> width <"<<width<<"> color : ["<<color<<"]"<<endl;
}


int Room::getId(){
	return id;
}
string Room::getName(){
	return name;
}

float Room::getLength(){
	return length;
}

float Room::getWidth(){
	return width;
}

string Room::getColor(){
	return color;
}


//setters
void Room::setId(int id1){
	id=id1;
}

void Room::setName(string name1){
	name=name1;
}
void Room::setLength(float length1){
	length=length1;
}

void Room::setWidth(float width1){
	width=width1;
}

void Room::setColor(string color1){
	color= color1;
}


Room::~Room(){
	//cout<<"Destructing the room !"<<endl;
}
