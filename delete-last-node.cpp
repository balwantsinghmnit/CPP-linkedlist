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

//function to delete last node
void deleteLast(struct node **head)
{

	struct node* temp = *head;

	if((*head)==NULL)
		return;

	if(temp->next==NULL)
	{
		*head=NULL;
		free(temp);
		return;
	}

	while(temp->next->next!=NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}


int main(int argc, char const *argv[])
{
	struct node *head=NULL;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);

	cout<<"before deletion : ";
	printList(head);	

	deleteLast(&head);

	cout<<"after deletion : ";
	printList(head);	

	return 0;
}