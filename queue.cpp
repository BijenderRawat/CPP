#include<iostream>
using namespace std;
struct node{
	int data;
	node *next = NULL;
};
class queue{
	private:
	node *front = NULL, *rear = NULL;
	public:
	void insert(int d){
		node *temp = new node;
		temp -> data = d;
		if(rear == NULL){
			front = rear = temp;
			return;
		}
		rear -> next = temp;
		rear = temp;
	}
	void Delete(){
		if(front == NULL){
			cout<<"queue is empty\n";
			return;
		}
		node *temp = front;
		front = front -> next;
		cout<<temp -> data<<" is deleted"<<endl;
		delete(temp);
	}
	void display(){
		node *temp = front;
		while(temp != NULL){
			cout<<temp -> data<<"->";
			temp = temp -> next;
		}
		cout<<"NULL";
	}
};
int main(){
	queue q;
	q.insert(1);
	q.insert(2);
	q.insert(3);
	q.insert(4);
	q.Delete();
	q.display();
	return 0;
}