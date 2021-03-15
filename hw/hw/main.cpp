#include "phonebook.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	phonebook person;
	//person.start();

	int menu; //for menu
	int menu2; //for user's preference
	float phone;
	string isim;
	string soyisim;

	

	do {		
		cout << "\tMENU" << endl;
		cout << "1.Add record\n2.Remove record\n3.Update record" << endl;
		cout << "4.Print phonebook\n5.Search person\n0 for exit" << endl;
		cout << "Number of people: ";
		person.getCount();
		cout << "\nYour choice : ";
		cin >> menu;

		switch (menu) {
		case 1://Add
			cout << "\nPhone number : ";
			cin >> phone;
			cout << "Name : ";
			cin >> isim;
			cout << "Surname : ";
			cin >> soyisim;
			person.AddRecord(phone, isim, soyisim);
			cout << endl;
			break;
		case 2://delete
			if (person.isEmpty()) { //check whether list is empty
				cout << "Phonebook is empty!!\n" << endl;
			}
			else {
				cout << "\nEnter the name you want to delete : ";
				cin >> isim;
				person.searchbyName(isim);
				if (person.current != NULL) { //check if there is a match
					cout << "Do you want to delete this person?\n1.Yes\n2.No" << endl;
					cout << "Your choice : ";
					cin >> menu2;
					if (menu2 == 1) {
						person.removeRecord(isim);
						cout << "Person removed!" << endl;
						person.sort();
					}
					cout << endl;
				}
			}
				break;
		case 3://update
			if (person.isEmpty()) {//check whether list is empty
				cout << "Phonebook is empty!!\n" << endl;
			}
			else {
				cout << "\nEnter the name you want to update : ";
				cin >> isim;
				person.searchbyName(isim);//it searches the name and bring it to user
				if (person.current != NULL) { //if there is a such user program wants to new data here
					cout << endl;
					cout << "New Name : ";
					cin >> isim;
					cout << "New Surname : ";
					cin >> soyisim;
					cout << "New Number : ";
					cin >> phone;
					person.updateRecord(phone, isim, soyisim); //change the data
					person.sort();//sorts the phonebook 
					cout << endl;
				}
				else {
					break;
				}
			}
			break;
		case 4://print
			person.printPhonebook();
			cout << endl;
			break;
		case 5://search
			if (person.isEmpty()) {//check whether list is empty then starts to search
				cout << "Phonebook is empty!!" << endl;
			}
			else {
				cout << "1.Search by name\n2.Search by surname\n3.Search by number" << endl;
				cin >> menu2;
				{
					if (menu2 == 1) {//search by name
						cout << "\nEnter the name of the person you want to find : ";
						cin >> isim;
						person.searchbyName(isim);
						cout << endl;
					}
					else if (menu2 == 2) {//search by surname
						cout << "\nEnter the surname of the person you want to find : ";
						cin >> soyisim;
						person.searchbySurname(soyisim);
						cout << endl;
					}
					else if (menu2 == 3) {//search by no
						cout << "\nEnter the phone number you want to find : ";
						cin >> phone;
						person.searchbyNo(phone);
						cout << endl;
					}
					else {
						cout << "Invalid choice!" << endl;
					}
				}
			}
			break;
		case 0:
			person.deallocate();//frees memory
			break;
		default:
			cout << ("Invalid choice!!\n")<<endl;
			continue;
			}

		} while (menu != 0);

		cout << "Goodbye\n";
		system("PAUSE");
		return 0;
	}