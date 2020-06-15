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

//function to get nth node data from last
int nthNodeFromLast(struct node** head,int n)
{
	if((*head)==NULL)
		return(-1);
	struct node *i,*j;
	i=*head;
	j=*head;
	int c=0;
	while(c<n)
	{
		if(j==NULL)
			return(-1);
		j = j->next;
		c++;
	}
	while(j!=NULL)
	{
		j=j->next;
		i=i->next;
	}
	return(i->data);
}

int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(23);
	printList(head);
	cout<<"2nd element from last: "<<nthNodeFromLast(&head,2)<<endl;	
	return 0;
}