#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
}Node;

void printNodes(Node *head)
{
	if(head == NULL)
		cout<<"LL is empty";

	Node *ptr = head;

	cout<<"LL is : ";
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
} 

void insertAtEnd(Node *head, int data)
{
	Node *ptr = head;
	Node *temp = new Node(data);

	while(ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = temp;
}

Node* insertAtBeg(Node *head, int data)
{
	Node *temp = new Node(data);
	temp->next = head;
	head = temp;
	return head;
}

void insertAtPos(Node *head, int data, int pos)
{
	Node *ptr = head;
	Node *temp = new Node(data);
	pos--;

	while(pos != 1)
	{
		ptr = ptr->next;
		pos--;
	}
	temp->next = ptr->next;
	ptr->next = temp;
}

int main()
{
	Node *head = NULL;
	head = new Node(45);

	Node *curr = new Node(98);
	head->next = curr;

	curr = new Node(3);
	head->next->next = curr;

	insertAtEnd(head, 67);
	head = insertAtBeg(head, 8);
	printNodes(head);

	insertAtPos(head,56,3);
	printNodes(head);
}
