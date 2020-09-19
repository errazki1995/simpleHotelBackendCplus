#include "Room.cpp"
#include <iostream>
#include <vector>
using namespace std;
vector<Room> rooms;


void addRoom(Room& m){
	rooms.push_back(m);	
}



void printRoom(vector<Room>::iterator listIter){
	cout<<"Room id:"<<listIter->getId()<<" Name: "<<listIter->getName()<<" length:<"<<listIter->getLength()<<"> width <"<<listIter->getWidth()<<"> color : ["<<listIter->getColor()<<"]"<<endl;

}



void updateRoomByName(string name,Room &m){ //new object
	vector<Room>::iterator itr;
 for(itr= rooms.begin();itr!=rooms.end();++itr){
	
	if(name.compare(itr->getName()) ==0 ){
		itr->setName(m.getName());
		itr->setWidth(m.getWidth());
		itr->setLength(m.getLength());
		
	}
}	
	
}




void searchByLengthWidth(float length,float width){
	vector<Room>::iterator itr;

	for(itr= rooms.begin();itr!=rooms.end();++itr){
		//cout<<"searching..."<<itr->getLength();
     if(itr->getLength() == length && itr->getWidth()==width){
     	printRoom(itr);
    }
 }
}


void ListRoomWithMaxArea(){
vector<Room>::iterator itr;
 float maxlength=0,maxwidth=0;
for(itr= rooms.begin();itr!=rooms.end();++itr){
  if(itr->getLength() > maxlength && itr->getWidth()>maxwidth){
  	maxlength=itr->getLength();
  	maxwidth= itr->getWidth();
	  }
   }
  searchByLengthWidth(maxlength,maxwidth);
   
}



void  ListRoomByName(string name){
	vector<Room>::iterator listIter;
	for( listIter= rooms.begin();listIter!=rooms.end();++listIter){
 		if(name.compare(listIter->getName())==0){
 			cout <<"Room found..."<<endl;
 			printRoom(listIter);
		 } 

    }
}

void Quit(){
}

int main(){
	Room room1(1,"Valencia",23.1,23.1,"Blue");
	Room room2(2,"Royal Flamingo",70.5,50.3,"Purple");
	Room room3(3,"Esperanda",40.1,30.1,"Pink");
	Room room4(4,"Duplex",140.4,90.1,"green");
	
	addRoom(room1);
	addRoom(room2);
	addRoom(room3);
	cout<<"Vector size is:"<<rooms.size()<<endl;	
	
	//updateRoomByName("Royal Flamingo",room3);
	//searchByLengthWidth(40.1,30.1);
	ListRoomWithMaxArea();
    ListRoomByName("Valencia");	
	
	return 0;
}



