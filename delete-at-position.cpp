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

//function to delete node at given position
void deleteAtPos(struct node **head,int pos)
{

	if((*head)==NULL || pos<1)
		return;
	if(pos==1)
	{
		struct node* dlt = *head;
		*head = (*head)->next;
		free(dlt);
		return;
	}
	struct node* temp = *head;

	pos--;

	while(pos>1)
	{
		temp = temp->next;
		pos--;
		if(temp==NULL)
		{
			cout<<"Invalid Position"<<endl;
			return;
		}
	}
	if(temp->next==NULL)
	{
		cout<<"Invalid Position"<<endl;
		return;
	}
	struct node* dlt = temp->next;
	temp->next = temp->next->next;
	free(dlt);
}


int main(int argc, char const *argv[])
{
	struct node *head=NULL;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	int n;
	cin>>n;
	cout<<"before deletion : ";
	printList(head);	

	deleteAtPos(&head,n);

	cout<<"after deletion : ";
	printList(head);	

	return 0;
}