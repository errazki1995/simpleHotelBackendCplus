#include "Room.cpp"

#include <iostream>

#include <vector>

using namespace std;
vector < Room > rooms;

void addRoom(Room & m) {
  rooms.push_back(m);
}

void printRoom(vector < Room > ::iterator listIter) {
  cout << "Room id:" << listIter -> getId() << " Name: " << listIter -> getName() << " length:<" << listIter -> getLength() << "> width <" << listIter -> getWidth() << "> color : [" << listIter -> getColor() << "]" << endl;

}

ListAllRooms() {
  vector < Room > ::iterator listIter;
  for (listIter = rooms.begin(); listIter != rooms.end(); ++listIter) {
    printRoom(listIter);
  }
}

bool searchForRoom(string name) {
  vector < Room > ::iterator itr;
  bool found = false;
  for (itr = rooms.begin(); itr != rooms.end(); ++itr) {
    if (name.compare(itr -> getName()) == 0) return found = true;
  }
  return found;
}

bool updateRoomByName(string name, Room & m) { //new object
  vector < Room > ::iterator itr;
  bool found = false;
  for (itr = rooms.begin(); itr != rooms.end(); ++itr) {

    if (name.compare(itr -> getName()) == 0) {
      found = true;
      Room & toupdate = * itr;
      //cout << "the M :" << m.getName() << endl;

      * itr = m;
      /*
      toupdate.setName(m.getName());
      toupdate.setWidth(m.getWidth());
      toupdate.setColor(m.getColor());
      toupdate.setId(m.getId());
      toupdate.setLength(m.getLength());
      cout << toupdate;
      cout << "--listing all rooms--" << endl;
      ListAllRooms();
      */
    }
  }
  return found;

}

bool searchByLengthWidth(float length, float width) {
  vector < Room > ::iterator itr;
  bool elementFound=false;
  for (itr = rooms.begin(); itr != rooms.end(); ++itr) {
    //cout<<"searching..."<<itr->getLength();
    if (itr -> getLength() == length && itr -> getWidth() == width) {
      elementFound=true;	
      printRoom(itr);
    }
  }
 return elementFound;
}

void ListRoomWithMaxArea() {
  vector < Room > ::iterator itr;
  float maxlength = 0, maxwidth = 0;
  for (itr = rooms.begin(); itr != rooms.end(); ++itr) {
    if (itr -> getLength() > maxlength && itr -> getWidth() > maxwidth) {
      maxlength = itr -> getLength();
      maxwidth = itr -> getWidth();
    }
  }
  searchByLengthWidth(maxlength, maxwidth);

}

bool ListRoomByName(string name) {
	bool found=false;
  vector < Room > ::iterator listIter;
  for (listIter = rooms.begin(); listIter != rooms.end(); ++listIter) {
    if (name.compare(listIter -> getName()) == 0) {
      found=true;	
      cout << "Room found..." << endl;
      printRoom(listIter);
    }

  }
return found;
}

void Quit() {}

void addRoomDisplay() {
  int id;
  float length, width = 0;
  string color, name;

  cout << "[+]Enter the id[+]" << endl;
  cin >> id;
  cout << "[+]Enter the name[+]" << endl;
  cin >> name;
  cout << "[+]Enter length[+]" << endl;
  cin >> length;
  cout << "[+]Enter width[+]" << endl;
  cin >> width;
  cout << "[+]Enter Color[+]" << endl;
  cin >> color;
  Room r(id, name, length, width, color);

  addRoom(r);
}

void updateHotelRoomDisplay() {
  string room_to_find;
  int newid;
  float newlength, newwidth;
  string newname, newcolor;

  cout << "[!] Enter the Room name to search [!]" << endl;
  cin >> room_to_find;

  if (!searchForRoom(room_to_find)) {
    cout << "Room not found !" << endl;

  } else {
    cout << "ROOM FOUND: " << room_to_find << endl;
    cout << "[+]Enter the New id for the room[+]" << endl;
    cin >> newid;
    cout << "[+]Enter the New name for the room[+]" << endl;
    cin >> newname;
    cout << "[+]Enter the New length for the room[+]" << endl;
    cin >> newlength;
    cout << "[+]Enter the New width for the room[+]" << endl;
    cin >> newwidth;
    cout << "[+]Enter the New Color for the room[+]" << endl;
    cin >> newcolor;

    Room r(newid, newname, newlength, newwidth, newcolor);
    updateRoomByName(room_to_find, r);

    ListAllRooms();
  }

}

void searchByLengthWidthDisplay(){
	 float lengthd,widthd;
	 
	 cout <<"[+] searching for a room by length and width [+]"<<endl;
	 cout<<"[+]Enter length of the room"<<endl;
	 cin>>lengthd;
	 
	 cout<<"[+] Enter width of the room"<<endl;
	 cin >>widthd;
	 
	 if(!searchByLengthWidth(lengthd,widthd)){
	  cout<<"No element found matching width"<< widthd<<" and length "<<lengthd<<endl;
	 }
	 
	 
}

void listRoomByNameDisplay(){
	string named;
	 cout <<"[+] searching for a room by Name [+]"<<endl;
	 cout<<" What's the room's name?"<<endl;
	 cin>>named;
	 
	 if(!ListRoomByName(named)){
	 	cout<<"We are sorry No room found with name"<< named<<endl;
	 }
	 
	
}

int main() {

  Room room1(1, "Valencia", 23.1, 23.1, "Blue");
  Room room2(2, "Royal Flamingo", 70.5, 50.3, "Purple");
  Room room3(3, "Esperanda", 40.1, 30.1, "Pink");
  Room room4(4, "Duplex", 140.4, 90.1, "green");

  addRoom(room1);
  addRoom(room2);
  addRoom(room3);
  addRoom(room4);
  cout<<"we have  "<<rooms.size()<<" available roooms."<<endl; 
  
  cout<<"---------------------MENU-----------------"<<endl;
  cout<<"1- add a Room									 [+]"<<endl;
  cout<<"2- update hotel room details                    [+]"<<endl;
  cout<<"3- search for a room by length and width        [+]"<<endl;
  cout<<"4- List room with max area (length and width)   [+]"<<endl;
  cout<<"5- List rooms by Name                           [+]"<<endl;
  
  int option;
  cout<<"[+]Enter your choice"<<endl;
  cin>>option;
  switch(option){
  	case 1:addRoomDisplay(); break;
  	case 2:updateHotelRoomDisplay(); break;
  	case 3:searchByLengthWidthDisplay(); break;
  	case 4:ListRoomWithMaxArea(); break;
  	case 5:listRoomByNameDisplay(); break;
  	default: cout<<"Please choose an appropriate choice !"<<endl;
  }


  return 0;
}
