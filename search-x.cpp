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

//function to search x in linkedlist
int search(struct node** head,int x)
{
	if(head==NULL)
		return(0);
	int c=0;
	struct node* i=*head;
	while(i!=NULL)
	{
		if(i->data==x)
			return(c+1);
		i=i->next;
		c++;
	}
	return(0);
}

int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	printList(head);
	int pos = search(&head,7);
	if(pos==0)
	cout<<"Not Found"<<endl;
	else
	cout<<"Found at position "<<pos<<endl;	
	return 0;
}