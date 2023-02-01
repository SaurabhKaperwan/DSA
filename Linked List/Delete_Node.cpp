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
	{
		cout<<"LL is empty";
		return;
	}

	Node *ptr = head;

	cout<<"LL is : ";
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
} 

Node* delBeg(Node *head)
{
	if(head == NULL)
	{
		cout<<"LL is empty";
		return head;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	temp = NULL;
	return head;
}

Node* delEnd(Node *head)
{
	if(head == NULL)
	{
		cout<<"LL is empty";
		head = NULL;
	}
	else if(head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node *temp = head;
		Node *temp2 = head;

		while(temp->next != NULL)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = NULL;
		delete temp;
		temp = NULL;
	}

	return head;

}

void delAtPos(Node **head,int pos)
{
	Node *curr = *head;
	Node *prev = *head;

	if(*head == NULL)
		cout<<"LL is already empty!\n";
	else if(pos == 1)
	{
		*head = curr->next;
		delete curr;
		curr = NULL;
	}
	else
	{
		while(pos != 1)
		{
			prev = curr;
			curr = curr->next;
			pos--;
		}
		prev->next = curr->next;
		delete curr;
		curr = NULL;
	}
}

void delAllNodes(Node **head)
{
	Node *prev = *head;

	while(*head != NULL)
	{
		prev = *head;
		*head = (*head)->next;
		delete prev;
	}
}

int main()
{
	Node *head = NULL;
	head = new Node(45);

	Node *curr = new Node(98);
	head->next = curr;

	curr = new Node(3);
	head->next->next = curr;

	printNodes(head);

	//delAllNodes(&head);

	//printNodes(head);

	delAtPos(&head,2);

	printNodes(head);

	head = delBeg(head);

	printNodes(head);

	head = delEnd(head);

	printNodes(head);
}
