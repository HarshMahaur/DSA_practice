#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    bool isTerminal;
    Node* child[26];

    node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

void add(string w,Node* trie){
    int n= w.size();
    for(int i =0;i<n;i++){
        if(trie->child[w[i]-'A']=NULL){
            trie->child[w[i]-'A']=new Node();
        }
        trie=trie->child[w[i]-'A'];
    }
    trie->isTerminal=true;

}


int main(){
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");


    Node* root= new Node();

    for (int i =0;i<dict.size();i++){
        add(dict[i],root);

    }





    return 0;
}