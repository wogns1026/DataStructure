/*
����Ʈ�� �����Ҵ����� ������ ���Ҵµ� ���� �ڵ忡 �ణ�� ������ �־���.
���� �׽�Ʈ ���̽��� ���� ������ ��� ����Ʈ�� �ʱ�ȭ�� ����� �̷������ �ʴ´�.
�׷��� �� ���� �����ϰ� head, tail�� �̸� ��� ����ó���� ���� ������ �ʵ���
�ڵ带 ¥���Ҵ�.
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
Node nodepool[600005]; // �ʿ��� ����� ������ ����ؼ� �̸� �Ҵ��� ���´�.
Node *newNode(int v) {
	// ��带 ������ �� ���� �־���
	nodepool[nodecnt].val = v;
	nodepool[nodecnt].next_node = nullptr;
	nodepool[nodecnt].prev_node = nullptr;
	return &nodepool[nodecnt++]; // �Ҵ��س��� ��� �߿��� ���� ��ġ �ּҸ� �����ϰ� nodecnt++ ��
}

// FIFO�� ����
struct List {
	Node *head;
	Node *tail;
	int cnt;
	
	// �׽�Ʈ ���̽����� �� init �Լ��� ���� ����Ʈ�� �ʱ�ȭ ����
	void init() {
		cnt = 0;
		// head�� tail�� �ǹ̸� ���� �ʴ� ���� �̸� ��������
		head = newNode(0);
		tail = newNode(0);
		head->next_node = tail;
		tail->prev_node = head;
	}

	// push�� pop�Լ��� ����ó���� ���� �ʿ� ������***************
	void push_val(int v) {
		Node *tmp = newNode(v); // �������� ��带 �������� �ʰ� �Ҵ�Ǿ� �ִ� ����� �ּҸ� ������
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