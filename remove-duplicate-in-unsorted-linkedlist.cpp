#include<iostream>
#include<map>
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

//function to delete duplicate data from the linkedlist
void removeDuplicates( struct node **head) 
{
    map<int,int> m;
    struct node* root=*head;
    m[root->data]=1;
    while(root)
    {
        if(root->next && (m.find(root->next->data)!=m.end()))
        {
            struct node *temp = root->next;
            root->next = temp->next;
            free(temp);
        }
        else
        {
            root = root->next;
            if(root)
            m[root->data]=1;
        }
    }
}


int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	head->next->next->next = newnode(7);
	cout<<"Before : ";
	printList(head);
	removeDuplicates(&head);
	cout<<"After : ";
	printList(head);		
	return 0;
}