#include<stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void insert(int d)
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("queue overflow\n");
		return;
	}
	if(front == -1)
	{
		front = rear = 0;
	}
	else
	{
		if(rear == MAX-1)
		{
			rear = 0;
		}
		else{
			rear++;
		}
	}
	queue[rear] = d;
}
void deletion()
{
	if(front == -1)
	{
		printf("queue underflow\n");
		return;
	}
	printf("element deleted from queue is : %d\n", queue[front]);
	if(front == rear)
	{
		front = rear = -1;
	}
	else{
		if(front == MAX-1)
		{
			front = 0;
		}
		else{
			front++;
		}
	}
}
void display()
{
	int f = front, r = rear;
	if(front == -1)
	{
		printf("queue is empty\n");
		return;
	}
	if(f <= r)
	{
		while(f <= MAX-1)
		{
			printf("%d ", queue[f]);
			f++;
		}
		f = 0;
		while(f <= r)
		{
			if(f <= r)
			{
				printf("%d ", queue[f]);
				f++;
			}
		}
	}
	printf("\n");
}
int main()
{
	int choice, d;
	do
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
			printf("input the element for insertion in queue : ");
			scanf("%d", &d);
			insert(d);
			break;
			case 2 :
			deletion();
			break;
			case 3:
			display();
			break;
			case 4:
			break;
			default:
			printf("wrong choice\n");
		}
	}while(choice != 4);
	return 0;
}
