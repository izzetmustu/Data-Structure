#include "phonebook.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*void phonebook::start() {
	
	head = NULL;
	current = NULL;
	tail = NULL;

}
*/
int phonebook::count = 0;

void phonebook::createhead(float phone, string isim, string soyisim) {
	head = new Node;
	head->no = phone;
	head->name = isim;
	head->surname = soyisim;
	head->next = NULL;
	tail = head;
}

void phonebook::AddRecord(float phone, string isim, string soyisim) {
	if (isEmpty()) {
		createhead(phone, isim, soyisim);
	}
	else {
		int index = 0; //row of the current pointer
		current = head;
		while (current != NULL) {
			if (current->name.compare(isim) <= 0) {
				{
					if (current->next == NULL) {//end of the list(eklenecek isim listedekilerin hepsinden buyuk)
						insertAtEnd(phone, isim, soyisim);
						break;
					}
					else {
						current = current->next;
						index = index + 1;
						continue;//loop will continue till current node's name is bigger
					}
				}
			}
			else if (current->name.compare(isim) > 0) {
				if (index == 0) { // current pointer points to the Node that head pointer points
					insertAtBeginning(phone, isim, soyisim);
					break;
				}
				else {//new name should be added somewhere in the middle
					current = head;
					for (int i = 0; i < index - 1; i++) {//it takes the current pointer to the previous node to add the new name before the current node
						current = current->next;
					}
					insertAtMiddle(phone,isim,soyisim);
					break;
				}
			}
		}
	}
	count++;
}

void phonebook::insertAtBeginning(float phone, string isim, string soyisim) {
		Node *yeni;
		yeni = new Node;
		yeni->name = isim;
		yeni->surname = soyisim;
		yeni->no = phone;
		yeni->next = head;
		head = yeni;
}

void phonebook::insertAtMiddle(float phone, string isim, string soyisim) {
	Node *tmp;
	tmp = new Node;
	tmp->name = isim;
	tmp->surname = soyisim;
	tmp->no = phone;
	tmp->next = current->next;
	current->next = tmp;
}

void phonebook::insertAtEnd(float phone, string isim, string soyisim) {
		tail->next = new Node;
		tail->next->no = phone;
		tail->next->name = isim;
		tail->next->surname = soyisim;
		tail->next->next = NULL;
		tail = tail->next;
}

void phonebook::sort() {
	if (isEmpty() == false) {
		Node *tmp;
		tmp = NULL;
		Node *tmp2;
		tmp2 = NULL;
		for (current = head; current->next != NULL; current = current->next) {
			for (tmp = current->next; tmp != NULL; tmp = tmp->next) {
				if (current->name.compare(tmp->name) > 0) {
					tmp2 = new Node;
					tmp2->name = current->name;
					tmp2->surname = current->surname;
					tmp2->no = current->no;

					current->name = tmp->name;
					current->surname = tmp->surname;
					current->no = tmp->no;

					tmp->name = tmp2->name;
					tmp->surname = tmp2->surname;
					tmp->no = tmp2->no;

					delete tmp2;
				}
			}
		}

	}
}

void phonebook::removeRecord(string isim) {
	Node *deleted;
	deleted = NULL;
	current = head;
	if (head->name == isim) {
		deleted = head;
		head = head->next;
		delete deleted;
	}
	else {
		while (current->next != NULL) {
			if(current->next->name == isim){
				deleted = current->next;
				current->next = current->next->next;
				if (current->next == NULL) { //this line to track the tail pointer
					tail = current;
				}
				delete deleted;
				break;
			}
			current = current->next;
		}
	}
	count--;
}

void phonebook::updateRecord(float phone, string isim, string soyisim) {
	current->name = isim;
	current->surname = soyisim;
	current->no = phone;
	cout << "Person updated!" << endl;
}

void phonebook::printPhonebook() {
	if (isEmpty()) {
		cout << "Phonebook is empty!" << endl;
	}
	else {
		current = head;
		cout << "\nName\t\t\tSurname\t\t\tPhone Number" << endl;
		while (current != NULL) {
			cout << current->name << "\t\t\t" << current->surname << "\t\t\t" << current->no << endl;
			current = current->next;
		}
	}
}

void phonebook::searchbyName(string isim){
	current = head;
	while (current != NULL) {
		if (current->name == isim) {
			cout << "\nPerson's information:" << endl;
			cout << "Name : " << current->name << endl;
			cout << "Surname : " << current->surname << endl;
			cout << "No : " << current->no << endl;
			break;
		}
		current = current->next;
		if (current == NULL) {
			cout << "The person does not exist in phonebook!\n" << endl;
		}
	}
}

void phonebook::searchbySurname(string soyisim) {
	current = head;
	while (current != NULL) {
		if (current->surname == soyisim) {
			cout << "\nPerson's information:" << endl;
			cout << "Name : " << current->name << endl;
			cout << "Surname : " << current->surname << endl;
			cout << "No : " << current->no << endl;
			break;
		}
		current = current->next;
		if (current == NULL) {
			cout << "The person does not exist in phonebook!\n" << endl;
		}
	}
}

void phonebook::searchbyNo(float phone) {
		current = head;
		while (current != NULL) {
			if (current->no == phone) {
				cout << "\nPerson's information:" << endl;
				cout << "Name : " << current->name << endl;
				cout << "Surname : " << current->surname << endl;
				cout << "No : " << current->no << endl;
				break;
			}
			current = current->next;
			if (current == NULL){
				cout << "There is no such number in phonebook!\n" << endl;
		}
	}
}

bool phonebook::isEmpty(){
		return head==NULL;
}

void phonebook::deallocate(){
	current = head;
	while (current != NULL) {
		head = head->next;
		delete current;
		current = head;
	}
}
