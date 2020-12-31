#include<iostream>
using namespace std;
struct node{
	int data;
	node *next = NULL;
};
class stack{
	private:
	node *top = NULL;
	public:
	void push(int d){
		node *temp = new node;
		temp -> data = d;
		temp -> next = top;
		top = temp;
	}
	void pop(){
		if(top == NULL){
			cout<<"stack is empty\n";
			return;
		}
		node *temp = top;
		top = top -> next;
		cout<<temp -> data<<" is deleted\n";
		delete(temp);
	}
	void peek(){
		if(top == NULL){
			cout<<"stack is empty\n";
			return;
		}
		cout<<"top most element in stack is "<<top -> data<<endl;
	}
	void display(){
		node *temp = top;
		while(temp){
			cout<<temp -> data<<"->";
			temp = temp -> next;
		}
		cout<<"NULL";
	}
};
int main(){
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.display();
	return 0;
}