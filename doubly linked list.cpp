// Program to implement the funtions of doubly linked list
#include <iostream>
using namespace std;

template<class T = int>
class node {
	public:
		T info;
		node *next, *prev;
		node(T i, node *n, node *p) {
			info = i;
			next = n;
			prev = p;
		}
};

template<class T = int>
class SLL {
	node<T> *head, *tail;
	public:
		SLL() {
			head = tail = NULL;
		}

		bool isEmpty() {
			return head == NULL;
		}

		node<T>* getHead() {
			return head;
		}

		node<T>* getTail() {
			return tail;
		}

		void addToHead(T);
		void addToTail(T);
		void deleteFromHead();
		void deleteFromTail();
		void deleteNode(T);
		void display();
		void reverse();
		bool isInList(T);
};

template<class T>
void SLL<T>::addToHead(T x) {
	if (head == NULL)
        tail = head = new node<T>(x, NULL, NULL);
	else
        head = new node<T>(x, head, NULL);
}

template<class T>
void SLL<T>::addToTail(T x) {
	if (head == NULL)
        tail = head = new node<T>(x, NULL, NULL);
	else
        tail = (tail->next = new node<T>(x, NULL, tail));
}

template<class T>
void SLL<T>::deleteFromHead() {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	head = head->next;
	head->prev = NULL;
}

template<class T>
void SLL<T>::deleteFromTail() {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	tail = tail->prev;
	tail->next = NULL;
}

template<class T>
void SLL<T>::deleteNode(T x) {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	if (isInList(x)) {
		if (head->info == x)
            deleteFromHead();
		else if (tail->info == x)
            deleteFromTail();
		else {
			node<T> *temp = new node<T>(0, NULL, NULL);
			temp = head;
			for (; temp->info != x; temp = temp->next);
			node<T> *pre = temp->prev;
			node<T> *suc = temp->next;
			pre->next = suc;
			suc->prev = pre;
			delete temp;
        }
	}else
        cout << "\n" << x << " not in list\n";
}

template<class T>
bool SLL<T>::isInList(T x) {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return false;
	}
	node<T> *temp = head;
	for (;temp != tail && temp->info != x; temp = temp->next);
	if (temp->info == x)
	return true;
	return false;
}

template<class T>
void SLL<T>::reverse() {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	node<T> *first = head, *end = tail;
	int temp;
	for (; first != end; first = first->next, end = end->prev) {
		temp = first->info;
		first->info = end->info;
		end->info = temp;
	}
	cout << "\nReversed List: ";
	display();
}

template<class T>
void SLL<T>::display() {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	node<T> *temp = head;
	do {
		cout << temp->info << " ";
		temp = temp->next;
	}while (temp != NULL);
}

int main() {
	SLL<> s1;
	int choice, val;
	while (true) {
        cout << "\n1. Add to head\n2. Add to tail\n3. Delete head\n4. Delete tail\n5. Delete node\n6. Reverse\n7. Display\n8. Exit"
             << "\n   Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter the value you want to insert: ";
                    cin >> val;
                    s1.addToHead(val);
                    break;
            case 2: cout << "Enter the value you want to insert: ";
                    cin >> val;
                    s1.addToTail(val);
                    break;
            case 3: s1.deleteFromHead();
                    break;
            case 4: s1.deleteFromTail();
                    break;
            case 5: cout << "\nEnter the value you want to delete: ";
                    cin >> val;
                    s1.deleteNode(val);
                    break;
            case 6: s1.reverse();
                    break;
            case 7: s1.display();
                    break;
            case 8: return false;
            default: cout << "\nEnter a valid input\n";
        }
    }
	return 0;
}
