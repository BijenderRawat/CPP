#include<iostream>
using namespace std;
struct node{
 int data;
 node *next = NULL;
};
class linkedlist{
	private:
	node *head, *tail;
	public:
	linkedlist(){
		head = tail = NULL;
	}
	void insertatend(int d){
		node *temp = new node;
		temp -> data = d;
		if(head == NULL)
			head = tail = temp;
		else{
			tail -> next = temp;
			tail = temp;
		}
	}
	void reverse(){
	node *current = head;
	node *prev = NULL, *next = NULL;
	while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
	}
	head = prev;
	}
	void display(){
		node *temp = head;
		while(temp != NULL){
			cout<<temp -> data<<"->";
			temp = temp -> next;
		}
		cout<<"NULL\n";
	}
};
int main(){
    linkedlist l;
    l.insertatend(1);
    l.insertatend(2);
    l.insertatend(3);
    l.insertatend(4);
    l.display();
    l.reverse();
    l.display();
    return 0;
}
