#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class linkedlist{
	private:
	node *head, *tail;
	public:
	linkedlist(){
		head = tail = NULL;
	}
	void insert(int d){
		node *temp = new node;
		temp -> data = d;
		temp -> next = NULL;
		if(head == NULL){
			head = tail = temp;
		}
		else{
			tail -> next = temp;
			tail = temp;
		}
	}
	void Delete(int d){
		node *temp = head;
		node *prev = head;
		while(temp != NULL){
			if(temp -> data == d){
				if(head -> next == NULL){
					while(temp -> next != NULL){
						prev = temp;
						temp = temp -> next;
					}
					prev -> next = NULL;
					free(temp);
				}
				else{
					head -> data = head -> next -> data;
					head -> next = head -> next -> next;
					break;
				}
			}
			head = head -> next;
		}
	}
	/* void insertatbegin(int d){
        	node *temp = new node;
		temp -> data = d;
		temp -> next = NULL;
		if(head == NULL){
			head = tail = temp;
		}
		else{
			temp -> next = head;
			head = temp;
		}
	}
	*/
	void search(int d){
		node *temp = head;
		while(temp != NULL){
			if(temp -> data == d){
				cout<<d<<" element is found "<<endl;
				return;
			}
			temp = temp -> next;
		}
		cout<<d<<" element is not found "<<endl;
	}
	void display(){
		node *temp = head;
		while(temp != NULL){
			cout<<temp -> data<<"->";
			temp = temp -> next;
		}
		cout<<"NULL";
	}
};
int main(){
	int n;
	char ch;
	linkedlist l;
	cout<<"enter how many nodes u want 2 insert: ";
	cin>>n;
	cout<<"enter the data for "<<n<<" nodes\n";
	for(int i = 0; i < n; i++){
		int d;
		cin>>d;
		l.insert(d);
	}
	do{
		cout<<"**********MENU**********\n1 -> insert element\n2 -> delete an element\n3 -> search an element\n4 -> display linked list\nchoose from above options: ";
		cin>>ch;
		switch(ch){
			case 1:
				int d;
				cout<<"enter the data to be inserted: ";
				cin>>d;
				l.insert(d);
				l.display();
				break;
			case 2:
				cout<<"enter the data to be deleted: ";
				int d;
				cin>>d;
				l.Delete(d);
				l.display();
				break;
			case 3:
				cout<<"enter the element to be searched: ";
				int d;
				cin>>d;
				l.search(d);
				l.display();
				break;
			case 4:
				l.display();
				break;
			default:
				cout<<"wrong choice";
				break;
		}
		cout<<"code written by BIJENDER SINGH RAWAT\n";
		cout<<"do u want 2 continue(y or n)";
		ch = getchar();
		}while(ch == 'y');
	return 0;
}
