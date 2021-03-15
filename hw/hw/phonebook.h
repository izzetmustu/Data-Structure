#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node {
	float no;
	string name;
	string surname;
	Node *next;
};

class phonebook {

public:
	static int count;

	Node *head;
	Node *current;
	Node *tail;

	//void start();

	phonebook() :head(NULL), current(NULL), tail(NULL) {};

	static void getCount() { cout << count << endl; }

	void createhead(float phone, string isim, string soyisim);

	void AddRecord(float phone, string isim, string soyisim);

	void insertAtBeginning(float phone, string isim, string soyisim);

	void insertAtMiddle(float phone, string isim, string soyisim);

	void insertAtEnd(float phone, string isim, string soyisim);

	void sort();

	void removeRecord(string isim);

	void updateRecord(float phone, string isim, string soyisim);

	void printPhonebook();

	void searchbyName(string isim);

	void searchbySurname(string soyisim);

	void searchbyNo(float phone);

	bool isEmpty();

	void deallocate();
};