#include <iostream>

struct Node {
	int data;
	Node* link;
};

Node* CreateNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->link = NULL;
	return temp;
}

bool IsEmpty(Node* Q)
{
	if (Q == NULL) return true;
	else {
		return false;
	}
}

void Enqueue(Node** Q, int x)
{
	Node* temp = CreateNode(x);
	if (IsEmpty(*Q)) {
		temp->link = *Q;
		*Q = temp;
	}
	else {
		while ((*Q)->link != NULL) {
			*Q = (*Q)->link;
		}
		(*Q)->link = temp;
		temp->link = NULL;
	}
}

void Dequeue(Node** Q)
{
	Node* temp;
	if (IsEmpty(*Q)) return;
	else {
		temp = (*Q)->link;
		delete(*Q);
		*Q = temp;
	}
}

int Top(Node* Q)
{
	if (IsEmpty(Q)) return 0;
	else {
		return Q->data;
	}
}

void Print(Node* Q)
{
	if (IsEmpty(Q)) return;
	else {
		while (Q->link != NULL) {
			std::cout << Q->data << " ";
			Q = Q->link;
		}
	}
}

int main() {
	Node* Q = NULL;
	Enqueue(&Q, 1);
	Enqueue(&Q, 2);
	Enqueue(&Q, 3);
	Enqueue(&Q, 4);
	Enqueue(&Q, 5);
	Print(Q);
	Top(Q);
	Dequeue(&Q);
	Print(Q);
}