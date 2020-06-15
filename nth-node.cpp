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

//function to get nth node data
int nthNode(struct node** head,int n)
{
	if((*head)==NULL)
		return(-1);
	struct node* i=*head;
	while(n>1)
	{
		i = i->next;
		n--;
	}
	return(i->data);
}

int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	printList(head);
	cout<<"2nd element : "<<nthNode(&head,2)<<endl;	
	return 0;
}