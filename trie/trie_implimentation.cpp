#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    bool isTerminal;
    Node* child[26];

    Node(){
        isTerminal= false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

void add(string w,Node* trie){
    int n= w.size();
    for(int i =0;i<n;i++){
        if(trie->child[w[i]-'A']==NULL){
            trie->child[w[i]-'A']=new Node();
        }
        trie=trie->child[w[i]-'A'];
    }
    trie->isTerminal=true;

}
// search code by me
bool search(string w, Node* trie){
    int n = w.size();
    for(int i =0;i<n;i++){
        if(trie->child[w[i]-'A']==NULL){
            return false;
        }
        trie=trie->child[w[i]-'A'];
    }
    if(trie->isTerminal==true){
        return true;
    }
    return false;
}


//search code by sir




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
    dict.push_back("NISGT");



    Node* root= new Node();

    for (int i =0;i<dict.size();i++){
        add(dict[i],root);

    }

    if(search("NISG",root)){
        std::cout<< "we found the word" <<std::endl;
    }
    else{
        std::cout<< "the word does not exist" <<std::endl;
    }





    return 0;
}




