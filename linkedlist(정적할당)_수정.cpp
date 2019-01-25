/*
리스트를 정적할당으로 구현해 보았는데 이전 코드에 약간의 문제가 있었다.
만약 테스트 케이스가 여러 가지일 경우 리스트의 초기화가 제대로 이루어지지 않는다.
그래서 이 점을 보완하고 head, tail을 미리 잡아 예외처리를 따로 해주지 않도록
코드를 짜보았다.
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
	int val;
	Node *next_node;
	Node *prev_node;
};

int nodecnt = 0;
Node nodepool[600005]; // 필요한 노드의 개수를 계산해서 미리 할당해 놓는다.
Node *newNode(int v) {
	// 노드를 생성할 때 값을 넣어줌
	nodepool[nodecnt].val = v;
	nodepool[nodecnt].next_node = nullptr;
	nodepool[nodecnt].prev_node = nullptr;
	return &nodepool[nodecnt++]; // 할당해놓은 노드 중에서 현재 위치 주소를 리턴하고 nodecnt++ 함
}

// FIFO로 구현
struct List {
	Node *head;
	Node *tail;
	int cnt;
	
	// 테스트 케이스마다 이 init 함수를 통해 리스트를 초기화 해줌
	void init() {
		cnt = 0;
		// head와 tail을 의미를 갖지 않는 노드로 미리 생성해줌
		head = newNode(0);
		tail = newNode(0);
		head->next_node = tail;
		tail->prev_node = head;
	}

	// push와 pop함수의 예외처리가 따로 필요 없어짐***************
	void push_val(int v) {
		Node *tmp = newNode(v); // 동적으로 노드를 생성하지 않고 할당되어 있는 노드의 주소를 가져옴
		tail->prev_node->next_node = tmp;
		tmp->prev_node = tail->prev_node;
		tmp->next_node = tail;
		tail->prev_node = tmp;
		cnt++;
	}
	void pop_val() {
		head->next_node->next_node->prev_node = head;
		head->next_node = head->next_node->next_node;
		cnt--;
	}
	int list_size() {
		return cnt;
	}
	bool empty() {
		if (cnt == 0)
			return true;
		return false;
	}
	int front() {
		return head->next_node->val;
	}
	int back() {
		return tail->prev_node->val;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, num = 0;
	cin >> n;
	string s;
	List q;
	q.init();
	while (n--) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			q.push_val(num);
		}
		else if (s == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop_val();
			}
		}
		else if (s == "size") {
			cout << q.list_size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}