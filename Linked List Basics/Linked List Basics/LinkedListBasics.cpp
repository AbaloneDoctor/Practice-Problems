// LinkedListBasics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//Linked lists 
//pros: fast insertion, deletion. No size limit. 
//Cons: poor search and indexing

struct node {
	int value;
	node *next;
};

class linkedList {
private: 
	node *head, *tail;
public:
	linkedList() {
		head = NULL;
		tail = NULL;
	}
	
	void printHeadTail() {
		cout << "head: " << head->value << endl;
		cout << "tail: " << tail->value << endl;
	}

	//Updated 3/14
	void insertAtPosition( int val , int pos) {		
		node *itrSlow = new node();
		itrSlow->next = head;
		node *itrFast = head;
		node *insertee = new node();
		insertee->value = val;

		int counter = 0;
		while (counter < pos && itrFast) {
			itrSlow = itrSlow->next;
			itrFast = itrFast->next;
			counter++;
		}
		
		//inserts insertee between slow and fast pointers
		itrSlow->next = insertee;
		insertee->next = itrFast;

		if (itrFast == head) {				//inserted at head, repoint head
			//head = itrSlow;				//<< this is wrong, itrSlow points to the head, it isn't the head
			head = insertee;
			delete itrSlow;
		}
		if (!itrFast) {						//inserted after tail, repoint tail
			tail = itrFast;
		}
	}

	//circa pre 3/13
	//Decrepit code for learning
	//initial idea was to set itrSlow to itrFast, then move itrFast forward to keep itrSlow tailing itrFast
	//but this allows for collision of the 2 itr's 
	void insertAtPositionOLD(int pos, int val) {
		//currently doesn't account for if pos > arr.size

		//previous implementation, sets itrfast to head, and itrslow is looped and set
		node *itrSlow = new node();					//to itrfast right before itrfast is incremented forward
		node *itrFast = head;						//causes problems at pos==0 because itrSlow is never set to anything if loop doesn't run
		node *temp = new node();
		temp->value = val;

		for (int i = 0; i < pos; i++) {
			itrSlow = itrFast;				//rewrite. If pos is 0 or 1, itrSLow is never properly initialized
			if (itrFast != NULL) {
				itrFast = itrFast->next;
			}
		}

		//FOLLOWING IS BAD
		//itrSlow becomes NULL (ie reach the end), 
		//and tail->next == temp because the for loop above allows itrSlow == itrFast 
		if (itrSlow != NULL) {				//check if at last member
			itrSlow->next = temp;
		}
		else {	//reached end
			tail->next = temp;
			tail = temp;
		}
		temp->next = itrFast;
	}


	void insertAtStart( int val ) {
		node *insertee = new node();  
		insertee->value = val;
		insertee->next = head;
		head = insertee;
	}

	void insertAtTail( int val ) {
		node *insertee = new node();
		insertee->value = val;
		insertee->next = NULL;
		tail->next = insertee;
		tail = insertee;
	}

	//goal, delete at pos, if pos > arr.size(), delete last element
	void deleteAtPosition( int pos ) {				//itrSlow is ptr to node before deleted node
		node *itrSlow = new node();
		itrSlow->next = head;
		node *itrFast = head;						

		int counter = 0;
		while (counter < pos && itrFast->next) {
			itrSlow = itrSlow->next;
			itrFast = itrFast->next;
			counter++;
		}

		if ( itrFast == head ) {					//in case of head/ pos == 0, itrSlow is never set to anything. 
			head = itrFast->next;
		}
		if( counter < pos - 1){						//in case of pos > arr.size()
			tail = itrSlow;
		}

		itrSlow->next = itrFast->next;
		delete itrFast;	
	}


	void deleteHead() {
		node *temp = head->next;
		delete head;
		head = temp;
	}

	void deleteTail() {

		node *itrSlow = new node();
		itrSlow->next = head;
		node *itrFast = head;

		while (itrFast->next ) {		//same as while(itrFast->next != NULL){...}
			itrSlow = itrSlow->next;
			itrFast = itrFast->next;
		}
		
		delete tail;
		tail = itrSlow;
		itrSlow->next = NULL;			//sets last member's ->next to NULL, or causes erros with while looping
		
		
	}

	void printNodes() {
		node *temp = head; 
		while(temp){							//when i was using delete, this would crash when reached end
			cout << temp->value << " ";			//used to crash because end of linked list was not properly set to NULL
			temp = temp->next;					//it would just be deleted. NOT THE SAME
		}

		cout << endl;
	}

	void generateList(vector<int> arr) {
		head = new node();
		tail = new node();
	

		head->value = arr[0];
		node *itr = head;
		for (int i = 1; i < arr.size(); i++) {
			itr->next = new node();
			itr = itr->next;

			itr->value = arr[i];
			tail = itr;

		}
	}


	//practice for different for loops. Same result as generateList(vector<int> arr){}
	//generate list using for ( : ) instead of for( int i = 0 ...)
	void generateList2(vector<int> arr) {
		//different from the other for method because you can't generate head's value beforehand and start at arr[1]
		//you essentially have to start at arr[0], so you set the value before doing itr=itr->next
		//difference is that on arr[ lastMemner] you have to not add itr->next = new node()

		head = new node();
		node *itr = head;
		//itr->value = arr[i];
		for (int i : arr) {
			itr->value = i;
			if( i != arr.back() ){
				itr->next = new node();
				itr = itr->next;
			}
		}
		tail = itr;		//at last
	}
		
};



void linkedListSol() {
	linkedList list;
	list.generateList({ 1 , 2 , 3, 4, 5 });
	list.printNodes();
	int deleteAt;

	

	cout << "insert 0 at start" << endl;
	list.insertAtStart(0);
	list.printNodes();
	

	cout << "insert 6 at tail" << endl;
	list.insertAtTail(6);
	list.printNodes();
	
	list.printHeadTail();

	cout << "insert number at position" << endl;
	int insertee;
	int insertAt;
	cout << "number: ";
	cin >> insertee;
	cout << "position: ";
	cin >> insertAt;
	list.insertAtPosition(insertee, insertAt);
	list.printNodes();

	cout << "delete at position:" << endl;
	cin >> deleteAt;
	list.deleteAtPosition(deleteAt);
	list.printNodes();

	cout << "delete head and tail" << endl;
	list.deleteHead();	
	list.deleteTail();

	list.printNodes();
	list.printHeadTail();
	
}



int main()
{

	int repeat = 1;
	do {
		linkedListSol();
		
		cout << endl << "Repeat: 1, end: 0" << endl;
		cin >> repeat; 
		cout << endl;
		if (!isdigit(repeat)) break;

	} while (repeat == 1);

    return 0;
}

