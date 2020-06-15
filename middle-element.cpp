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

//function to find middle element of the linkedlist
struct node* middleElement(struct node** head)
{
	struct node *slow,*fast;
	slow = *head;
	fast = *head;

	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow = slow->next;
	}
	return(slow);
}

int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	head->next->next->next = newnode(0);
	head->next->next->next->next = newnode(14);
	printList(head);
	struct node* mid = middleElement(&head);
	if(mid!=NULL)
	cout<<"middle element : "<<mid->data<<endl;	
	return 0;
}