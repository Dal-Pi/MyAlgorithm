#include <cstdlib>
#include <utility>

namespace treap
{
	template<typename KeyType>
	struct Node
	{
		KeyType key;
		int priority;
		int size;
		Node* left;
		Node* right;
		Node(const KeyType& _key)
			: key(_key),
			priority(rand()), size(1),
			left(nullptr), right(nullptr)
		{}
		void calcSize()
		{
			size = 1;
			if (left)
				size += left->size;
			if (right)
				size += right->size;
		}
		void setLeft(Node* newLeft)
		{
			left = newLeft;
			calcSize();
		}
		void setRight(Node* newRight)
		{
			right = newRight;
			calcSize();
		}
	};

	template<typename KeyType>
	using NodePair = std::pair<Node<KeyType>*, Node<KeyType>*>;

	template<typename KeyType>
	NodePair<KeyType> split(Node<KeyType>* root, KeyType key)
	{
		if (nullptr == root)
			return NodePair<KeyType>(nullptr, nullptr);
		if (root->key < key)
		{
			NodePair<KeyType> rs = split(root->right, key);
			root->setRight(rs.first);
			return NodePair<KeyType>(root, rs.second);
		}
		else
		{
			NodePair<KeyType> ls = split(root->left, key);
			root->setLeft(ls.second);
			return NodePair<KeyType>(ls.first, root);
		}
	}

	template<typename KeyType>
	Node<KeyType>* insert(Node<KeyType>* root, Node<KeyType>* node)
	{
		if (nullptr == root)
			return node;
		if (root->priority < node->priority)
		{
			NodePair<KeyType> splited = split(root, node->key);
			node->setLeft(splited.first);
			node->setRight(splited.second);
			return node;
		}

		if (node->key < root->key)
		{
			root->setLeft(insert(root->left, node));
		}
		else
		{
			root->setRight(insert(root->right, node));
		}
		return root;
	}

	template<typename KeyType>
	Node<KeyType>* merge(Node<KeyType>* a, Node<KeyType>* b)
	{
		if (nullptr == a)
			return b;
		if (nullptr == b)
			return a;
		if (a->priority < b->priority)
		{
			b->setLeft(merge(a, b->left));
			return b;
		}
		else
		{
			a->setRight(merge(a->right, b));
			return a;
		}
	}

	template<typename KeyType>
	Node<KeyType>* erase(Node<KeyType>* root, KeyType key)
	{
		if (nullptr == root)
			return root;
		if (root->key == key)
		{
			Node<KeyType>* ret = merge(root->left, root->right);
			delete root;
			return ret;
		}

		if (key < root->key)
		{
			root->setLeft(erase(root->left, key));
		}
		else
		{
			root->setRight(erase(root->right, key));
		}
		return root;
	}

	template<typename KeyType>
	Node<KeyType>* kth(Node<KeyType>* root, int k)
	{
		int leftSize = 0;
		if (nullptr != root->left)
			leftSize = root->left->size;
		if (k <= leftSize)
			return kth(root->left, k);
		else if (k == leftSize + 1)
			return root;
		else
			return kth(root->right, k - leftSize - 1);
	}

	template<typename KeyType>
	int countLessThan(Node<KeyType>* root, KeyType key)
	{
		if (nullptr == root) return 0;
		if (root->key >= key)
			return countLessThan(root->left, key);
		else
		{
			int ls = (root->right ? root->left->size : 0);
			return (ls + 1 + countLessThan(root->right, key));
		}
	}
}