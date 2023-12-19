#include <iostream>
#include <string>
struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class bnp
{
private:
    Node* root;
    std::string brNot(Node* node) 
    {
        if (node == nullptr) { return ""; }
        std::string result = std::to_string(node->data);

        if (node->left != nullptr || node->right != nullptr) 
        {
            if (node->left != nullptr)
            {
                result += "(" + brNot(node->left) + ")";
            }
            //result += "(" + brNot(node->left) + ")";
            if (node->right != nullptr) 
            {
                result += "(" + brNot(node->right) + ")";
            }
        }
        return result;
    }

    Node* ins(Node* node, int val)
    {
        if (node == nullptr) { return new Node(val); }
        if (val < node->data) { node->left = ins(node->left, val);  }
        else if (val > node->data) { node->right = ins(node->right, val); }
        return node;
    }

    Node* fMin(Node* node)
    {
        while (node->left != nullptr) { node = node->left; }
        return node;
    }
    Node* fMax(Node* node)
    {
        while (node->right != nullptr) { node = node->right; }
        return node;
    }

    bool searchRec(Node* node, int value) {
        if (node == nullptr) { return false; }
        if (value == node->data) {  return true; }

        else if (value < node->data) 
        {
            return searchRec(node->left, value);
        }
        else
        {
            return searchRec(node->right, value);
        }
    }

    Node* rem(Node* node, int value) {
        if (node == nullptr) { return node; }

        if (value < node->data)
        {
            node->left = rem(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = rem(node->right, value);
        }
        else 
        {
            if (node->left == nullptr) 
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) 
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = fMin(node->right);
            node->data = temp->data;
            node->right = rem(node->right, temp->data);
        }
        return node;
    }

public:
    bnp() : root(nullptr) {};

    void insert(int value)
    {
        root = ins(root, value);
    }
    int findMin()
    {
        return fMin(root)->data;
    }
    int findMax()
    {
        return fMax(root)->data;
    }
    void remove(int val)
    {
        root = rem(root, val);
    }
    bool search(int value) 
    {
        return searchRec(root, value);
    }
    void printTree()
    {
        std::cout << "Tree: " << brNot(root) << std::endl;
    }

};


int main()
{
    bnp tree;
    std::string s = "0(3(1)(6(7)(4)))(10(14)(13))";
    int ind = 0;
    while (ind < s.length())
    {
        bool flag = false;
        int val = 0;
        while ((s[ind] - '0') >= 0 and (s[ind] - '0') <= 9)
        {
            flag = true;
            val *= 10;
            val += s[ind] - '0';
            ind += 1;
        }
        if (flag)
        {
            tree.insert(val);
        }
        
        ind += 1;
    }

    std::cout << "Max: " << tree.findMax() << " min: " << tree.findMin() << " 1?: " << tree.search(1) << std::endl;
    tree.remove(1);
    std::cout << " 1?: " << tree.search(1) << std::endl;
    tree.printTree();
    tree.remove(0);
    tree.printTree();
}
