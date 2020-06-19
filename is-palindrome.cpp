#include<iostream>
#include<stack>
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

//function to check linkedlist is a palindrome or not
bool isPalindrome(struct node *head)
{
    //Your code here
    stack<int> st;
    struct node *temp=head;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    while(!st.empty())
    {
        if(st.top()!=head->data)
        return(false);
        st.pop();
        head=head->next;
    }
    return(true);
}


int main(int argc, char const *argv[])
{
	struct node *head;

	head = newnode(2);
	head->next = newnode(7);
	head->next->next = newnode(10);
	printList(head);
	if(isPalindrome(head))
	cout<<"Yes,palindrome"<<endl;
	else
	cout<<"No, not palindrome"<<endl;	
	return 0;
}