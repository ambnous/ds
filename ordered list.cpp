/* Program to insert in a sorted list */
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

void sortedInsert(node *head_ref, node *new_node) {
    node *current;
    if ( head_ref == NULL || head_ref->data >= new_node->data) {
        new_node->next = head_ref;
        head_ref = new_node;
    }else {
        current = head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

node *newNode(int new_data) {
    node *new_node = new node;
    new_node->data  = new_data;
    new_node->next =  NULL;
    return new_node;
}

bool isEmpty(node *head_ref) {
	return head_ref == NULL;
}

bool inList(node *head_ref, int a) {
	node *temp = new node;
	temp = head_ref;
	for (; temp != NULL && temp->data != a; temp = temp->next);
	if (temp->data = a)
		return true;
	return false;
}
void delval(node *head_ref, int a) {
	node *temp;
	if (!isEmpty(head_ref)) {
		if (inList(head_ref, a)) {
			temp = head_ref->next;
			node *prev = head_ref;
			for (; temp->data != a; prev = prev->next, temp = temp->next);
			prev->next = temp->next;
			cout << "\nDeleted...\n";
		}else
			cout << "\nNot in list\n";
	}else
		cout << "\nList Empty\n";
}

node* merge(node *h1, node *h2) {
    if (!h1)
        return h2;
    if (!h2)
        return h1;
    if (h1->data < h2->data) {
        h1->next = merge(h1->next, h2);
        return h1;
    }else {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

void display(node *head) {
    if (!isEmpty(head)) {
		node *temp = head;
    	while(temp != NULL) {
       	cout << temp->data << " ";
        temp = temp->next;
    	}
    }else
    	cout << "\nList empty\n";
}

int main() {
    int choice;
    node *head1 = NULL;
    node *head2 = NULL;
	node *head = NULL;
	node *mergedList;
	node *new_node;
	int val, s1, s2;
	while (true) {
		cout << "\n1) Insetion\n2) Deletion\n3) Merging\n4) Display\n5Exit\n   Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1: cout << "\nEnter the number you want to insert: ";
					cin >> val;
					new_node = newNode(val);
					sortedInsert(&head, new_node);
					break;
			case 2: cout << "\nEnter the number you want to delete: ";
					cin >> val;
					delval(&head, val);
					break;
			case 3: cout << "\nEnter the size of the first ordered list: ";
					cin >> s1;
					cout << "\nEnter the elements of the first list\n";
					for (int i = 0; i < s1; ++i) {
						cout << "\nValue " << i+1 << ": ";
						cin >> val;
						new_node = newNode(val);
						sortedInsert(&head1, new_node);
					}
					cout << "\nEnter the size of the second list: ";
					cin >> s2;
					cout << "\nEnter the elements of the second list: ";
					for (int i = 0; i<s2; ++i) {
						cout << "\nValue " << i+1 << ": ";
						cin >> val;
						new_node = newNode(val);
						sortedInsert(&head2, new_node);
					}
					mergedList = merge(head1, head2);
					cout << "\nMerged List\n" << mergedList;
					break;
			case 4: display(&head);
					break;
			case 5: return false;
			default: cout << "\nPlease enter a valid input\n";
			}
		}
    return 0;
}
