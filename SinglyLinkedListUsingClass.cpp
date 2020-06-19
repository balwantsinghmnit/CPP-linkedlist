#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
};

//function to traverse and print the data of linkedlist
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main()
{
	node* head = new node();
	head->data = 15;
	head->next = new node();
	head->next->data = 63;
	head->next->next = new node();
	head->next->next->data = 7;
	head->next->next->next = NULL;

	cout<<"Linkedlist : ";
	print(head);
	cout<<endl;

	return(0);
}
