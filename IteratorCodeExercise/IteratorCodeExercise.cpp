#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
	T value;
	Node* left{ nullptr }, * right{ nullptr }, * parent{ nullptr };

	Node(T value) : value(value) {}

	Node(T value, Node<T>* left, Node<T>* right) : value(value), left(left), right(right) {
		left->parent = right->parent = this;
	}

	// traverse the node and its children preorder
	// and put all the results into `result`
	void preorder_traversal(vector<Node<T>*>& result)
	{
		if (!this)
			return;

		result.push_back(this);
		this->left->preorder_traversal(result);
		this->right->preorder_traversal(result);
	}
};


int main()
{
	vector<Node<int>*> preorderList;

	Node<int> root1{ 1,
					  new Node<int>{2,
								   new Node<int>{4},
								   new Node<int>{5}
								},
					  new Node<int>{3,
								   new Node<int>{6},
								   new Node<int>{7}
								}
	};

	root1.preorder_traversal(preorderList);

	for (const auto& item : preorderList)
	{
		if (item == *(preorderList.end() - 1))
		{
			cout << item->value;
			continue;
		}

		cout << item->value << ", " ;
	}

}