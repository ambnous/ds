// Program to implement ordered list

#include <iostream>
using namespace std;

class node{
	public:
		int info;
		node *next;
		node(int i, node *n = NULL){
			info = i;
			next = n;
		}
};

class OrderedList{
	node *head, *tail;
	public:
		OrderedList(){
			head = tail = NULL;
		}

		bool isEmpty(){
			return head == NULL;
		}

		node* getHead(){
			return head;
		}
		void insertAtHead(int);
		void insertAtTail(int);
		void insert(int);
		void display();
		void deleteHead();
		void deleteTail();
		void deleteNode();
		void merge(OrderedList&);
};

void OrderedList::insert(int x){
	if(isEmpty()){
		head = tail = new node(x);
	}else {
		if (x < head->info)
            insertAtHead(x);
		else if (x > tail->info)
            insertAtTail(x);
		else {
			node *temp = head->next, *prev = head;
			for (; temp->info < x; temp = temp->next, prev = prev->next);
			prev->next = new node(x, temp);
		}
	}
}

void OrderedList::insertAtHead(int x){
	if (isEmpty()) {
		head = tail = new node(x);
	}else {
		head = new node(x, head);
	}
}

void OrderedList::insertAtTail(int x) {
	if (isEmpty()) {
		head = tail = new node(x);
	}else {
		tail->next = new node(x);
		tail = tail->next;
	}
}

void OrderedList::deleteHead() {
	if (isEmpty()) {
		cout << "\nList is Empty";
		return;
	}else {
		int d = head->info;
		head = head->next;
	}
}

void OrderedList::deleteTail() {
	if (isEmpty()) {
		cout << "\nList is empty";
		return;
	}else {
		node *temp = head;
		for (; temp->next != tail; temp = temp->next);
		temp->next = NULL;
		int d = tail->info;
		tail = temp;
		cout << "\nDeleted value: " << d;
	}
}

void OrderedList::deleteNode() {
	if (isEmpty()) {
		cout << "\nList is empty";
		return;
	}else {
		int x;
		cout << "\nEnter the element to be deleted: ";
		cin >> x;
		if (head->info == x)
            deleteHead();
		else if (tail->info == x)
            deleteTail();
		else {
			node *temp = head->next, *prev = head;
			for (; temp->info != x; temp = temp->next, prev = prev->next);
			prev->next = temp->next;
		}
	}
}

void OrderedList::display() {
	if (isEmpty()) {
		cout << "\nList is empty";
		return;
	}else {
		node *temp = head;
		while (temp != NULL) {
			cout << temp->info << " ";
			temp = temp->next;
		}
	}
}

void OrderedList::merge(OrderedList &ol) {
	node *temp = head;
	node *temp1 = ol.getHead();
	while (!ol.isEmpty()) {
		insert(temp1->info);
		ol.deleteHead();
		temp1 = ol.getHead();
	}
}

OrderedList enterValuesInList() {
	OrderedList sol;
	char choice;
	int x;
	do {
		cout << "\na) Insert value";
		cout << "\nb) Delete value";
		cout << "\nc) Display";
		cout << "\nd) Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		if (choice == 'a') {
			int n;
			cout << "\n1. Insert at head";
			cout << "\n2. Insert at tail";
			cout << "\nEnter your choice: ";
			cin >> n;

			if (n == 1) {
				cout<<"\nEnter value to be inserted: ";
				cin>>x;
				sol.insertAtHead(x);
			}else if(n==2){
				cout<<"\nEnter value to be inserted: ";
				cin>>x;
				sol.insertAtTail(x);
			}
		}else if(choice=='b'){
			int n;
			cout<<"\n1. Delete from head";
			cout<<"\n2. Delete from tail";
			cout<<"\n3. Delete a node";
			cout<<"\nEnter your choice: ";
			cin>>n;

			if(n==1)
                sol.deleteHead();
			else if(n==2)
                sol.deleteTail();
			else if(n==3)
                sol.deleteNode();
		}else if(choice=='c'){
			cout<<"\nList is: ";
			sol.display();
		}else if(choice=='d')
            break;
	}while (true);
	return sol;
}

int main(){
	int x;
	char choice;
	OrderedList sol=enterValuesInList();

	do{
		cout << "\na) Insertion";
		cout << "\nb) Deletion";
		cout << "\nc) Merging";
		cout << "\nd) Display";
		cout << "\ne) Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		if (choice == 'a') {
			cout << "\nEnter element to be inserted: ";
			cin >> x;
			sol.insert(x);
		}else if (choice == 'b'){
			sol.deleteNode();
		}else if(choice == 'c'){
			OrderedList sol1 = enterValuesInList();
			sol.merge(sol1);
		}else if (choice == 'd'){
			sol.display();
		}else if (choice == 'e')
            break;
	}while (true);
	return 0;
}
