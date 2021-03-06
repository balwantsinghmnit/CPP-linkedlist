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

//function to detect loop using floyed's cycle finding algorithm
bool isLoop(struct node *head)
{
	struct node *slow,*fast;
	slow = head; fast=head;

	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast)
			return(true);
	}
	return(false);
}


int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	head->next->next->next = head;
	if(isLoop(head))
	cout<<"Loop is present"<<endl;
	else
	cout<<"No loop present"<<endl;	

	return 0;
}