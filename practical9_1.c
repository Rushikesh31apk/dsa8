#include<stdio.h>
#include<stdlib.h>
#define n 5
int qu[n],front,rear;
void init()
{
	front=rear=-1;
}
void enque(int x)
{
	if(rear==n-1)
	{
		printf("queue is overflow\n");
	}
	else if(front ==-1 && rear==-1)
	{
		front=rear=0;
		qu[rear]=x;
	}
	else
	{
		qu[++rear]=x;
	}
}
int deque()
{
	if(front==n-1 || front==-1|| rear==-1 )
	{
		printf("queue is underflow\n");
		return '\0';
	}
	else if(front==rear)
	{
		int l=qu[front];
		front =rear=-1;
		return l;
	}
	else
	{
		return qu[front++];
	}
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d ",qu[i]);
	}
}
void main()
{
    int ch ,x;
    do
    {
    	printf("\n------MENU------");
    	printf("\n1.init\n2.enqueue\n3.dequeue\n4.display\n5.exit\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			printf("Intialitation of Queue:\n");
    			init();
    			break;
    		case 2:
    			printf("enter element to enqueue:\n");
    			scanf("%d",&x);
    			enque(x);
    			break;
    		case 3:
    			x=deque();
    			printf("poped element or dequeue element is:%d",x);
    			break;
    		case 4:
    			printf("show queue element:\n");
    			display();
    			break;
    		default:
    			printf("wrong input\n");
		}
	}while(ch!=5);
		
}
