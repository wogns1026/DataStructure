/*
single linked list는 각 노드가 데이터와 포인터를 가지고 
한줄로 연결되어 있는 방식으로 데이터를 저장하는 자료구조
포인터는 다음 노드 or 이전 노드와의 연결을 담당함

장점 : 배열과는 다르게 중간의 노드의 삽입, 삭제가 용이****
	=> 시간복잡도는 O(n), 노드가 맨 앞(head), 맨 뒤(tail) 부분에 삽입, 삭제될 때는 O(1)로 빠름
단점 : 탐색에서 O(n)이 걸려 느리다.

탐색은 드물고 추가, 삽입, 삭제가 잦은 곳에 사용하기 좋음
*/

#include <iostream>

using namespace std;

// 노드
class Node {
	friend class List; // List가 Node의 private에 접근할 수 있도록 허락함
private : 
	int value; // 데이터 값
	Node *next_node; // 다음 노드를 가리키는 포인터
public : 
	Node(int = 0, Node* = 0); // 생성자, value와 next_node 포인터 값 초기화
	Node *next(); // 다음 노드의 주소 리턴
	int retval(); // 노드의 데이터 값 리턴
};

// 리스트
class List {
private : 
	int cnt; // list의 인덱스
	Node *head; // list의 head
	Node *tail; // list의 tail
public : 
	List(); // 생성자, head와 tail을 NULL로 초기화
	bool empty(); // List가 비어있는지 확인 => O(1)
	int front(); // head의 데이터 값 리턴 => O(1)
	int back(); // tail의 데이터 값 리턴 => O(1)
	bool find(int); // 인자 값을 데이터 값으로 가지는 노드가 있는지 확인 => O(n)
	int size(); // list의 크기를 리턴 => O(1)
	void push_front(int); // 맨 앞에 노드 추가 => O(1)
	void push_back(int); // 맨 뒤에 노드 추가 => O(1)
	void push_idx(int, int); // 중간 해당 인덱스에 노드 추가 => O(n)
	void pop_front(); // 맨 앞 노드 삭제 => O(1)
	void pop_back(); // 맨 뒤 노드 삭제 => O(n)
	void pop_idx(int); // 인덱스에 해당하는 노드를 삭제 => O(n)
	void modify(int, int); // 첫번째 인자 값을 인덱스로 가지는 노드의 값을 두번째 인자 값으로 수정함 => O(n)
	void print(); // List의 모든 노드의 데이터 값 리턴 => O(n)
	~List(); // 소멸자
};

Node::Node(int v, Node *n) : value(v), next_node(n) {

}
Node *Node::next() {
	return next_node;
}
int Node::retval() {
	return value;
}

List::List() : head(NULL), tail(NULL), cnt(0) {

}
bool List::empty() {
	if (head == NULL)
		return true;
	else
		return false;
}
int List::front() {
	return head->retval();
}
int List::back() {
	return tail->retval();
}
bool List::find(int val) {
	for (Node *ptr = head; ptr != tail->next(); ptr = ptr->next()) {
		if (ptr->retval() == val) {
			return true;
		}
	}
	return false;
}
int List::size() {
	return cnt;
}
void List::push_front(int val) {
	Node *ptr = new Node(val);
	if (head == NULL) {
		head = ptr;
		tail = ptr;
	}
	else {
		ptr->next_node = head;
		head = ptr;
	}
	cnt++;
}
void List::push_back(int val) {
	Node *ptr = new Node(val);
	if (tail == NULL) {
		head = ptr;
		tail = ptr;
	}
	else {
		tail->next_node = ptr;
		tail = ptr;
	}
	cnt++;
}
void List::push_idx(int idx, int val) {
	Node *ptr = new Node(val);
	int num = 0;
	if (idx == 0) {
		push_front(val);
	}
	else if (idx == cnt) {
		push_back(val);
	}
	else {
		for (Node *ptl = head; ptl != tail->next(); ptl = ptl->next()) {
			if (num + 1 == idx) {
				ptr->next_node = ptl->next();
				ptl->next_node = ptr;
				break;
			}
			num++;
		}
		cnt++;
	}
}
void List::pop_front() {
	Node *ptr = head;
	if (head == NULL) {
		cout << "List is empty!\n";
	}
	else {
		head = ptr->next();
		delete ptr;
		cnt--;
	}
}
void List::pop_back() {
	Node *ptr;
	if (tail == NULL) {
		cout << "List is empty\n";
	}
	else if (head == tail) {
		head = NULL;
		tail = NULL;
		cnt--;
	}
	else {
		for (ptr = head; ptr != tail->next(); ptr = ptr->next()) {
			if (ptr->next() == tail) {
				ptr->next_node = NULL;
				tail = ptr;
				break;
			}
		}
		cnt--;
	}
}
void List::pop_idx(int idx) {
	if (idx == 0)
		pop_front();
	else if (idx == cnt - 1)
		pop_back();
	else {
		int num = 0;
		for (Node *ptl = head; ptl != tail->next(); ptl = ptl->next()) {
			if (num + 1 == idx) {
				Node *ptr = ptl->next();
				ptl->next_node = ptr->next();
				delete ptr;
				break;
			}
			num++;
		}
		cnt--;
	}
}
void List::modify(int idx, int newval) {
	int n = 0;
	for (Node *ptr = head; ptr != tail->next(); ptr = ptr->next()) {
		if (n == idx) {
			ptr->value = newval;
			return;
		}
		n++;
	}
	cout << "The value can't be found!\n";
}
void List::print() {
	if (head != NULL) {
		for (Node *ptr = head; ptr != tail->next(); ptr = ptr->next()) {
			cout << ptr->retval() << ' ';
		}
		cout << '\n';
	}
	else {
		cout << "list is empty!\n";
	}
}
List::~List() {

}

int main() {
	List *list = new List();
	list->print();
	list->push_front(3);
	list->print();
	list->push_back(5);
	list->print();
	cout << list->front() << ' ' << list->back() << '\n';
	list->push_idx(1, 4);
	list->print();
	cout << list->find(7) << '\n';
	cout << list->find(4) << '\n';
	cout << list->size() << '\n';
	list->modify(1, 7);
	list->print();
	list->pop_idx(1);
	list->print();
	cout << list->empty() << '\n';
	list->pop_back();
	list->print();
	list->pop_front();
	list->print();

	return 0;
}