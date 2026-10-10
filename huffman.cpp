#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char ch;
    int freq;
    int left, right; // indices of children (-1 if none)
};

vector<Node> tree;
map<char, string> codes;

// Used by the priority queue: smallest frequency first
struct Compare
{
    bool operator()(int a, int b)
    {
        return tree[a].freq > tree[b].freq;
    }
};

// Go left = add '0', go right = add '1'
void makeCodes(int idx, string code)
{
    if (tree[idx].left == -1)
    { // leaf
        codes[tree[idx].ch] = code;
        return;
    }
    makeCodes(tree[idx].left, code + "0");
    makeCodes(tree[idx].right, code + "1");
}

int main()
{
    string text;
    cout << "Enter text: ";
    cin >> text;

    // Step 1: count frequency
    map<char, int> freq;
    for (char c : text)
        freq[c]++;

    // Step 2: make a leaf node for each character
    priority_queue<int, vector<int>, Compare> pq;
    for (auto p : freq)
    {
        tree.push_back({p.first, p.second, -1, -1});
        pq.push(tree.size() - 1);
    }

    // Step 3: join two smallest nodes until one is left
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        tree.push_back({'#', tree[a].freq + tree[b].freq, a, b});
        pq.push(tree.size() - 1);
    }

    // Step 4: make codes from the root
    int root = pq.top();
    makeCodes(root, "");

    // Print codes
    cout << "\nCodes:\n";
    for (auto p : codes)
        cout << p.first << " : " << p.second << "\n";

    // Encode
    string encoded = "";
    for (char c : text)
        encoded += codes[c];
    cout << "\nEncoded: " << encoded << "\n";

    // Decode
    string decoded = "";
    int cur = root;
    for (char bit : encoded)
    {
        cur = (bit == '0') ? tree[cur].left : tree[cur].right;
        if (tree[cur].left == -1)
        { // reached a leaf
            decoded += tree[cur].ch;
            cur = root;
        }
    }
    cout << "Decoded: " << decoded << "\n";
    return 0;
}