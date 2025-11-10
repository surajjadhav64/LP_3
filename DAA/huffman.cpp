#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

struct Node{
    char ch;
    int fre;
    Node* left;
    Node* right;
    
    Node(char c, int f){
        ch = c;
        fre = f;
        left = NULL;
        right =NULL;
    }
};

struct compare{
    bool operator()(Node* a,Node* b){
        return a->fre > b->fre;
    }
};

void generatecode(Node* root,string code,unordered_map<char,string> &huffman){
    if(!root){
        return;
    }
    
    if(!root->left && !root->right){
        huffman[root->ch]=code;
        return;
    }
    
    generatecode(root->left,code+'0',huffman);
    generatecode(root->right,code+'1',huffman);
}

int main(){
    string str;
    cout<<"Enter the String:";
    cin>>str;
    
    unordered_map<char,int>freq;
    for(char ch:str){
        freq[ch]++;
    }
    
    priority_queue<Node*, vector<Node*>,compare> pq;
    for(auto pair:freq){
        pq.push(new Node(pair.first,pair.second));
    }
    
    while(pq.size()>1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        
        Node* parent = new Node('\0',left->fre + right->fre);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    
    Node* root = pq.top();
    
    unordered_map<char,string> huffman;
    generatecode(root,"",huffman);
    
    cout<<"Huffman Codes:\n";
    for(auto pair:huffman){
        cout<<pair.first<<":"<<pair.second<<endl;
    }

    string encoded = "";
    for(char ch:str){
        encoded+=huffman[ch];
    }
    
    cout<<"Encoded:"<<encoded;
    
}

// input: ABBCDA
// Step 1: Frequencies
// Character	Frequency
// A	2
// B	2
// C	1
// D	1
// Step 2: Min-Heap Initialization

// Heap = [A(2), B(2), C(1), D(1)]

// Step 3: Build Tree

// Pop smallest two → C(1), D(1) → merge → CD(2)
// Heap = [A(2), B(2), CD(2)]

// Pop A(2), B(2) → merge → AB(4)
// Heap = [CD(2), AB(4)]

// Pop CD(2), AB(4) → merge → Root(6)

// Step 4: Assign Codes

// (Left = 0, Right = 1)

// Example codes might be:

// C = 00
// D = 01
// A = 10
// B = 11

// Step 5: Encode String

// Input: ABBCDA

// → 10 11 11 00 01 10
// → Encoded output: 101111000110
