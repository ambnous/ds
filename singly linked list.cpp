#include <iostream>
#include <cstdlib>
using namespace std;

template<class T = int>
class node {
	public:
		T info;
		node *next;
		node(T i, node *n = NULL) {
			info = i;
			next = n;
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
		SLL  concat(SLL);
		SLL  operator +(SLL);
};

template<class T>
void SLL<T>::addToHead(T x) {
	if (head == NULL)
        tail = head = new node<T>(x);
	else
        head = new node<T>(x,head);
}

template<class T>
void SLL<T>::addToTail(T x) {
	if (head == NULL)
        tail = head = new node<T>(x);
	else
        tail = (tail->next = new node<T>(x));
}

template<class T>
void SLL<T>::deleteFromHead() {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	node<T> *temp = head;
	head = temp->next;
}

template<class T>
void SLL<T>::deleteFromTail() {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	node<T> *temp = head;
	for (; temp->next != tail; temp = temp->next);
	cout << "\nRemoving " << tail->info << endl;
	tail = temp;
	tail->next = NULL;
}

template<class T>
void SLL<T>::deleteNode(T x) {
	if (isEmpty()) {
		cout << "\nEmpty\n";
		return;
	}
	if(isInList(x)) {
		if (head->info == x)
            deleteFromHead();
		else if (tail->info == x)
            deleteFromTail();
		else {
			node<T> *temp = head->next;
			node<T> *prev = head;
			for (; temp->info != x; temp = temp->next, prev = prev->next);
			prev->next = temp->next;
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
	/*if (head == tail) {
        cout << head->info;
        return;
	}
	if (head->next == tail) {
        node<T> *temp = head;
        T d = temp->info;
        temp->info = tail->info;
        tail->info = d;
        display();
        return;
	}*/
	node<T> *first = NULL,*temp = head,*end = tail;
	do {
		first = head;
		while (first->next != end)
            first = first->next;
		T d = temp->info;
		temp->info = end->info;
		end->info  = d;

		end  = first->next;
		temp = temp->next;
	}while (temp != end);
	cout<<"\nReversed List: ";
	display();
}

template<class T>
SLL<T> SLL<T>::concat(SLL s) {
	if (isEmpty() && s.isEmpty()) {
		cout << "\nLists are empty";
		return s;
	}
	node<T> *temp;
	SLL<> s1;
	for (temp = this->head; temp != NULL; temp = temp->next)
        s1.addToTail(temp->info);
	for (temp = s.getHead(); temp != NULL; temp = temp->next)
        s1.addToTail(temp->info);
	return s1;
}

template<class T>
SLL<T> SLL<T>::operator+(SLL<T> s) {
	SLL<T> s1;
	node<T> *temp;
	for (temp = this->head; temp != NULL; temp = temp->next)
        s1.addToTail(temp->info);
	for (temp = s.getHead(); temp != NULL; temp = temp->next)
        s1.addToTail(temp->info);
	return s1;
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
	SLL<> s1, s;
	int choice, val;
	while (true) {
        cout << "\n1.  Add to head\n2.  Add to tail\n3.  Delete head\n4.  Delete tail\n5.  Delete value"
             << "\n6.  Reverse\n7.  Concatinate\n8.  Concatination by overloading\n9.  Display\n10. Exit"
             << "\n    Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: system("cls");
                    {
                        cout << "Enter the value you want to insert: ";
                        cin >> val;
                        s1.addToHead(val);
                    }
                    break;
            case 2: system("cls");
                    {
                        cout << "Enter the value you want to insert: ";
                        cin >> val;
                        s1.addToTail(val);
                    }
                    break;
            case 3: system("cls");
                    s1.deleteFromHead();
                    break;
            case 4: system("cls");
                    s1.deleteFromTail();
                    break;
            case 5: system("cls");
                    {
                        cout << "Enter the value you want to delete: ";
                        cin >> val;
                        s1.deleteNode(val);
                    }
                    break;
            case 6: s1.reverse();
                    break;
            case 7: system("cls");
                    {
                        SLL<> s2;
                        cout << "Enter the number of elements of the second list: ";
                        int size;
                        cin >> size;
                        for (int i=0; i<size; ++i) {
                            cout << "value " << i + 1 << " : ";
                            cin >> val;
                            s2.addToHead(val);
                        }
                        s = s1.concat(s2);
                        s.display();
                    }
                    break;
            case 8: system("cls");
                    {
                        SLL<> s2;
                            cout << "Enter the number of elements of the second list: ";
                            int size;
                            cin >> size;
                            for (int i=0; i<size; ++i) {
                                cout << "value " << i + 1 << " : ";
                                cin >> val;
                                s2.addToHead(val);
                            }
                            s = s1.operator+(s2);
                            s.display();
                    }
                    break;
            case 9: system("cls");
                    s1.display();
                    break;
            case 10: return false;
            default: cout << "\nEnter valid input\n";
        }
    }
	return 0;
}
