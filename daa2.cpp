#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    char data;
    int freq;
    Node *left;
    Node *right;

    Node(char a, int b) {
        data = a;
        freq = b;
        left = nullptr;
        right = nullptr;
    }
};

class Compare {
public:
    bool operator()(Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

void print(Node *root, string code = "") {
    if (!root) return;
    // Leaf node
    if (!root->left && !root->right) {
        cout << root->data << " " << code << endl;
    }
    print(root->left, code + "0");
    print(root->right, code + "1");
}

void huff(vector<char> &data, vector<int> &freq) {
    //Vector of characters to encode.
    // Corresponding frequencies for each character.

    priority_queue<Node *, vector<Node *>, Compare> pq;
    // Create leaf node for each char and push to pq
    for (size_t i = 0; i < data.size(); i++) {
        pq.push(new Node(data[i], freq[i]));
    }
    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        
        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    print(pq.top());
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> data(n);
    vector<int> freq(n);

    cout << "Enter the characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Enter the corresponding frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    huff(data, freq);
    return 0;
}