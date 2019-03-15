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
		cout << "tail :" << tail->value << endl;
	}

	//Updated 3/14
	void insertAtPosition( int val , int pos) {		
		node *itrSlow = new node();
		itrSlow->next = head;
		node *itrFast = head;
		node *insertee = new node();
		insertee->value = val;

		int counter = 0;
		while (counter < pos && itrFast->next) {
			itrSlow = itrSlow->next;
			itrFast = itrFast->next;
			counter++;
		}
		
		//inserts insertee between slow and fast pointers
		itrSlow->next = insertee;
		insertee->next = itrFast;

		if (itrFast == head) {				//inserted at head, repoint head
			head = itrSlow;
		}

		if (!itrFast->next) {				//inserted after tail, repoint tail
			tail = itrFast;
		}
	}

	//circa March 13
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
		delete itrSlow;
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


	//practice for different for loops
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

	cin >> deleteAt;
	list.deleteAtPosition(deleteAt);

	list.printNodes();

	cin >> deleteAt;
	list.deleteAtPosition(deleteAt);
	


	list.insertAtTail(7);
	list.printNodes();

	list.insertAtStart(9);
	list.printNodes();

	list.insertAtPosition(9, 3);

	list.printNodes();

	list.deleteTail();
	list.printHeadTail();
	list.printNodes();
}


void nodeTest() {

	node first;
	first.value = 1;


	node second;
	second.value = 2;

	node *third = new node();
	third->value = 3;

	first.next = &second;
	second.next = third;

	node *temp = new node();


	//temp = &first;
	//first.next = temp;
	temp = first.next;
	//*temp = *third;


	cout << "temp: " << temp->value << endl;
	//temp = temp->next;
	cout << "temp moved to next: " << temp->value << endl;
	cout << "pointer test" << endl;

	cout << "first value: " << first.value;
	cout << ", second value: " << second.value;
	cout << ", third value: " << third->value << endl;

	cout << "first next: " << first.next->value;
	cout << ", second next: " << second.next->value;
	cout << ", third next: " << third->next->value << endl;
}

int main()
{
	 
	//void pointers();

	/*
	char a = 'a';
	char b = 'b';
	char c = 'c';

	char *ptr;
	char *ptr2;
	ptr = &a;					//bind ptr to a
	//ptr = &b;	// set a to b		
	//ptr = &c;	//set a to c

	
	*ptr = b;					//set value at a to b
	cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

	*ptr = c;					//set value at a to b
	cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

	ptr2 = ptr;					//ptr2 now controls ptr which controls a
	*ptr2 = b;					//set value at ptr2 pointee to b

	cout << "a: " << a << ", b: " << b << ", c: " << c <<  ", ptr: " << *ptr << ", ptr2: " << *ptr2 <<endl;

	*/
	

	linkedListSol();


	//temp = first.next;
	//cout << "first.next" << temp->value << endl;

	cin.get();
	cin.get();


    return 0;
}

