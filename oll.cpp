#include<iostream>
using namespace std;

class node{
	public:
		int info;
		node *next;
		node(int i,node *n=NULL){
			info=i;
			next=n;
		}
};

class OrderedList{
	node *head,*tail;
	public:
		OrderedList(){
			head=tail=NULL;
		}

		bool isEmpty(){
			return head==NULL;
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
		head=tail=new node(x);
	}else{
		if(x<head->info)
		insertAtHead(x);
		else if(x>tail->info)
		insertAtTail(x);
		else{
			node *temp=head->next,*prev=head;

			for(;temp->info < x;temp=temp->next,prev=prev->next);

			prev->next=new node(x,temp);
		}
	}
}

void OrderedList::insertAtHead(int x){
	if(isEmpty()){
		head=tail=new node(x);
	}else{
		head=new node(x,head);
	}
}

void OrderedList::insertAtTail(int x){
	if(isEmpty()){
		head=tail=new node(x);
	}else{
		tail->next=new node(x);
		tail=tail->next;
	}
}

void OrderedList::deleteHead(){
	if(isEmpty()){
		cout<<"\nList is Empty";
		return;
	}else{
		node *temp=head;
		head=head->next;
		delete temp;
	}
}

void OrderedList::deleteTail(){
	if(isEmpty()){
		cout<<"\nList is empty";
		return;
	}else{
		node *temp=head;
		for(;temp->next!=tail;temp=temp->next);
		temp->next=NULL;
		int d=tail->info;
		delete tail;
		tail=temp;
		cout<<"\nDeleted value: "<<d;
	}
}

void OrderedList::deleteNode(){
	if(isEmpty()){
		cout<<"\nList is empty";
		return;
	}else{
		int x;
		cout<<"\nEnter the element to be deleted: ";
		cin>>x;
		if(head->info==x)
		deleteHead();
		else if(tail->info==x)
		deleteTail();
		else{
			node *temp=head->next,*prev=head;
			for(;temp->info!=x;temp=temp->next,prev=prev->next);
			prev->next=temp->next;
		}
	}
}

void OrderedList::display(){
	if(isEmpty()){
		cout<<"\nList is empty";
		return;
	}else{
		node *temp=head;
		while(temp!=NULL){
			cout<<temp->info<<" ";
			temp=temp->next;
		}
	}
}

void OrderedList::merge(OrderedList &ol){
	node *temp=head;
	node *temp1=ol.getHead();
	while(!ol.isEmpty()){
		insert(temp1->info);
		ol.deleteHead();
		temp1=ol.getHead();
	}
}

OrderedList enterValuesInList(int k){
	OrderedList sol;
	char choice;
	int x;
	do{
		cout<<"\na) Insertion";
		cout<<"\nb) Deletion";
		cout<<"\nc) Merging";
		cout<<"\nd) Display";
		cout<<"\ne) Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;

		if(choice=='a'){
			cout<<"\nEnter element to be inserted: ";
			cin>>x;
			sol.insert(x);
		}else if(choice=='b'){
			sol.deleteNode();
		}else if(choice=='c'){
			cout<<"\nMerging "<<k;
			OrderedList sol1=enterValuesInList(k+1);
			sol.merge(sol1);
			cout<<"\nOut from merge "<<k<<endl;
		}else if(choice=='d'){
			sol.display();
		}else if(choice=='e')
		break;
	}while(true);

	return sol;
}

int main(){
	int x;
	char choice;
	OrderedList sol=enterValuesInList(0);
	return 0;
}
