#include<iostream>
using namespace std;

// node structure
struct node
{
	int data;
	struct node *next;
};

//function to create new node with given data
struct node* newnode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return(temp);
}

//function to print linkedlist
void printList(struct node* head)
{
	cout<<"head";

	while(head!=NULL)
	{
		cout<<"->"<<head->data;
		head = head->next;
	}
	cout<<"->NULL"<<endl;
}

//function to count the length of loop
int loopLength(struct node *slow)
{
	int len=1;
	struct node* temp = slow;
	while(temp->next!=slow)
	{
		len += 1;
		temp = temp->next;
	}
	return(len);
}

//function to detect loop using floyed's cycle finding algorithm
int isLoop(struct node *head)
{
	struct node *slow,*fast;
	slow = head; fast=head;

	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast)
		return(loopLength(slow));
	}
	return(0);
}


int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	head->next->next->next = head;
	int len = isLoop(head);
	if(len)
	cout<<"Loop is present. Loop Length : "<<len<<endl;
	else
	cout<<"No loop present"<<endl;	

	return 0;
}
