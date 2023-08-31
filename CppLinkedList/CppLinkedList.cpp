#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
	T _value;
	Node* next;

	Node() : next(nullptr) {}
};

template <typename T>
class SpiritSinglyLinkedList
{
public:
	Node<T>* head;
	int size;

	SpiritSinglyLinkedList(T headValue) : size(1) {
		head = new Node<T>();
		head->_value = headValue;
	}

	~SpiritSinglyLinkedList() {
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}

	void AddToEnd(T value) {
		Node<T>* newNode = new Node<T>();
		newNode->_value = value;

		Node<T>* node = head;
		while (node->next != nullptr) {
			node = node->next;
		}

		node->next = newNode;
		size++;
	}

	void AddToFront(T value) {
		Node<T>* newNode = new Node<T>();
		newNode->_value = value;

		newNode->next = head;
		head = newNode;

		size++;
	}

	void printList() {
		Node<T>* node = head;
		while (node != nullptr) {
			cout << node->_value << endl;
			node = node->next;
		}
	}
};

int main()
{
	SpiritSinglyLinkedList<int>* singlyLinked = new SpiritSinglyLinkedList<int>(8);

	singlyLinked->AddToEnd(9);
	singlyLinked->AddToEnd(10);

	singlyLinked->AddToFront(11);
	singlyLinked->AddToFront(12);

	singlyLinked->printList();

	delete singlyLinked; // Don't forget to free the allocated memory

	return 0;
}
