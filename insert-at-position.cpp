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

//function to add new node with given data at the beginning of linkedlist
void insertAtBegin(struct node** head,int data)
{
	struct node* temp = newnode(data);

	temp->next = *head;
	*head = temp;
}

//function to add new node with given data at the given position in linkedlist
void insertAtPosition(struct node** head,int data,int pos)
{
	if(pos<1)
	{
		cout<<"invalid position"<<endl;
		return;
	}
	else if(pos==1)
		return(insertAtBegin(head,data));
	else
	{
		struct node* temp = newnode(data);
		struct node* i=*head;
		pos -= 1;

		while(pos>1)
		{
			pos -= 1;
			i = i->next;
			if(i==NULL)
			{
				cout<<"invalid Position"<<endl;
				return;
			}
		}
		if(i==NULL)
		{
			cout<<"invalid position"<<endl;
			return;
		}
		temp->next = i->next;
		i->next = temp;
	}
}


int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);

	cout<<"Before inserting : ";
	printList(head);	

	insertAtPosition(&head,15,3);

	cout<<"After inserting : ";
	printList(head);

	return 0;
}