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

//function to find frequency of x in linkedlist
int xFreq(struct node** head,int x)
{
	if((*head)==NULL)
		return(0);
	int c=0;
	struct node* i=*head;
	while(i!=NULL)
	{
		if(i->data==x)
			c++;
		i=i->next;
	}
	return(c);
}

int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	printList(head);
	int f = xFreq(&head,7);
	if(f==0)
	cout<<"Frequency : 0"<<endl;
	else
	cout<<"Frequency : "<<f<<endl;	
	return 0;
}