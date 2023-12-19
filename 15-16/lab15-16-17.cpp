#include <iostream>
#include <vector>

#include <sstream>
#include <stack>


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int f_index(const std::string s, int start_ind, int end_ind) //поиск индекса последней скобки левого поддерева
{
    if (start_ind > end_ind) { return -1; }
    std::stack<char> a;
    for (int i = start_ind; i <= end_ind; i++)
    {
        if (s[i] == '(') { a.push(s[i]); }
        else if (s[i] == ')')
        {
            if (a.top() == '(')
                a.pop();
            if (a.empty()) { return i; }
        }      
    }
    return -1;
}

Node* fillTree(const std::string s, int start_ind, int end_ind)
{
    if (start_ind > end_ind) { return nullptr; }
    int val = 0;
    while (start_ind <= end_ind and (s[start_ind]-'0') >= 0 and (s[start_ind]-'0') <= 9)
    {
        val *= 10;
        val += s[start_ind]-'0';
        start_ind += 1;
    }

    auto* root = new Node(val);
    int ind = -1;
    if (start_ind <= end_ind and s[start_ind] == '(') { ind = f_index(s, start_ind, end_ind); }

    if (ind != -1)
    {
        root->left = fillTree(s, start_ind + 1, ind - 1);
        root->right = fillTree(s, ind + 2, end_ind - 1);
    }
    return root;
}
void preOrder(Node* node) {
    if (node == nullptr) { return; }
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
void inOrder(Node* node) {
    if (node == nullptr) { return; }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node* node) {
    if (node == nullptr) { return; }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

void stackOrder(Node* node)
{
    if (node == nullptr) { return; }
    std::stack<Node*> s;
    s.push(node);

    while (!s.empty())
    {
        auto temp = s.top();
        std::cout << temp->data << " ";

        s.pop();
        if (temp->right != nullptr) { s.push(temp->right); }
        if (temp->left != nullptr) { s.push(temp->left); }
        
    }
}

int main() {
   
    std::string str = "0(3(1)(6(4)(7)))(10(14)(13))";
    Node* root  = fillTree(str, 0, str.length() - 1);

    std::cout << "preOrder: ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "inOrder: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "postOrder: ";
    postOrder(root);
    std::cout << std::endl;

    std::cout << "stackOrder: ";
    stackOrder(root);
    std::cout << std::endl;
}

