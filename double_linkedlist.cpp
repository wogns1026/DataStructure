/*
double linked list는 single linked list와 다르게 하나의 노드가
다음 노드와 이전 노드를 가리키는 포인터를 모두 가지고 있음
(포인터 공간이 2개)
나머지는 single linked list와 유사
*/

#include <iostream>

using namespace std;

class Node {
	friend class List;
private : 
	int val;
	Node *next_node;
	Node *prev_node;
public : 
	Node(int = 0, Node * = NULL, Node * = NULL);
	int retval();
	Node *next();
	Node *prev();
};

class List {
private : 
	Node *head;
	Node *tail;
	int cnt;
public : 
	List();
	bool empty(); // O(1)
	int front(); // O(1)
	int back(); // O(1)
	int list_size(); // O(1)
	void push_front(int); // O(1)
	void push_back(int); // O(1)
	void pop_front(); // O(1)
	void pop_back(); // O(1) => 단일 연결 리스트에서는 O(n)이 걸렸지만 
					// 이중 연결 리스트에서는 노드가 이전 노드의 주소를 알고 있으므로 O(1)이 걸림
	~List();
};

Node::Node(int v, Node *n, Node *p) : val(v), next_node(n), prev_node(p) {

}
int Node::retval() {
	return val;
}
Node *Node::next() {
	return next_node;
}
Node *Node::prev() {
	return prev_node;
}

List::List() : head(NULL), tail(NULL), cnt(0) {

}
bool List::empty() {
	if (cnt == 0)
		return true;
	return false;
}
int List::front() {
	return head->retval();
}
int List::back() {
	return tail->retval();
}
int List::list_size() {
	return cnt;
}
void List::push_front(int v) {
	Node *tmp = new Node(v);
	if (cnt == 0) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->next_node = head;
		head->prev_node = tmp;
		head = tmp;
	}
	cnt++;
}
void List::push_back(int v) {
	Node *tmp = new Node(v);
	if (cnt == 0) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->prev_node = tail;
		tail->next_node = tmp;
		tail = tmp;
	}
	cnt++;
}
void List::pop_front() {
	Node *tmp = head;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		head->next_node->prev_node = NULL;
		head = tmp->next();
	}
	delete tmp;
	cnt--;
}
void List::pop_back() {
	Node *tmp = tail;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		tail->prev_node->next_node = NULL;
		tail = tmp->prev();
	}
	delete tmp;
	cnt--;
}
List::~List() {

}

int main() {
	List *list = new List();
	list->push_front(5);
	list->push_back(4);
	cout << list->front() << '\n';
	cout << list->back() << '\n';
	cout << list->list_size() << '\n';
	list->pop_back();
	cout << list->back() << '\n';
	cout << list->empty() << '\n';
	list->pop_back();
	cout << list->empty() << '\n';


	return 0;
}