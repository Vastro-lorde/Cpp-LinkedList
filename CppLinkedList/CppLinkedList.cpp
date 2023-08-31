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
		int count = 1;
		while (node != nullptr) {
			if (count == 1)
			{
				cout << '[' << node->_value << ',';
			}
			else if (count == size)
			{
				cout << node->_value << ']' << endl;
			}
			else
			{
				cout << node->_value << ',';
			}
			node = node->next;
			count++;
		}
	}

	T getNodeValue(int index) {
		Node<T>* node = head;
		if (index > size)
		{
			return -1;
		}
		if (index == 0)
		{
			return node->_value;
		}
		for (size_t i = 1; i <= index; i++)
		{
			node = node->next;
		}
		return node->_value;
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

	cout << "value at index 0: " << singlyLinked->getNodeValue(90);

	delete singlyLinked; // Don't forget to free the allocated memory

	return 0;
}
