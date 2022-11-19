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

void Enqueue(Node** F, Node** R, int x)
{
	Node* temp = CreateNode(x);
	if (*F == NULL && *R == NULL) {
		*F = *R = temp;
		return;
	}
	(*R)->link = temp;
	(*R) = temp;
}

void Dequeue(Node** F, Node** R)
{
	Node* temp = *F;
	if (*F == NULL) return;
	if (*F == *R) {
		*F = *R = NULL;
	}
	else {
		*F = (*F)->link;
	}
	delete(temp);
}

int Top(Node* F, Node* R)
{
	if (F == NULL && R == NULL) return 0;
	else {
		return F->data;
	}
}

void Print(Node* F, Node* R)
{
	if (F == NULL && R == NULL) return;
	else {
		while (F != R->link) {
			std::cout << F->data << " ";
			F = F->link;
		}
	}
}

int main() {
	Node* F = NULL;
	Node* R = NULL;
	Enqueue(&F, &R, 1);
	Enqueue(&F, &R, 2);
	Enqueue(&F, &R, 3);
	Enqueue(&F, &R, 4);
	Enqueue(&F, &R, 5);
	Print(F, R);
	std::cout << "\n";
	Dequeue(&F, &R);
	Print(F, R);
}