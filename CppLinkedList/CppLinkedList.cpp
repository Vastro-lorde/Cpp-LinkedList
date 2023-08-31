
#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
	string _value;
	Node* next;

};


class SpiritSinglyLinkedList
{
public:
	Node* head = new Node();
	int size = 0;
	void AddToEnd(string value) {
			Node* newNode = new Node();{};
			newNode->_value = value;
		if (size > 1)
		{
			Node* node = head;
			//get to the last node using the while loop
			while (node->next != NULL)
			{
				node = node->next;
			}

			// by now node is now the last node in the linkedlist
			node->next = newNode;
			newNode->next = NULL;
			size++;
		}
		else
		{
			head->next = newNode;
			newNode->next = NULL;
			size++;
		}

	};
	void AddToFront(string value) {
		Node* newNode = new Node(); {};
		newNode->_value = value;
		
		Node* tempNode = head;

		newNode->next = tempNode;

		head = newNode;
		
	}
	void printList() {
		Node* node = head;
		while (node != NULL)
		{
			cout << node->_value << endl;

			node = node->next;
		}
	};
	SpiritSinglyLinkedList(string headValue) {
		head->_value = headValue;
		size = 1;
	};
};




int main()
{
	SpiritSinglyLinkedList* singlyLinked = new SpiritSinglyLinkedList("Seun");

	singlyLinked->AddToEnd("Daniel");
	singlyLinked->AddToEnd("Omatsola");

	singlyLinked->AddToFront("Mr.");
	singlyLinked->AddToFront("Family Of:");

	singlyLinked->printList();

	cout << singlyLinked->size << endl;
}