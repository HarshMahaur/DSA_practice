#include <bits/stdc++.h>
using namespace std;
vector<int> removeDupe(int *arr,int n){
    vector<int> ans;
    unordered_map<int,bool> mp;

    if(n==0){
        return ans;
    }
    for(int i=0;i<n;i++){
        if(mp.count(arr[i])==1){
            continue;
        }
        else{
            mp[arr[i]]=true;
            ans.push_back(arr[i]);
        }
    }
    return ans;

}

void printVec(vector<int> vec){
    for(auto c:vec){
        cout<< c << " ";
    }
}
template <typename T>
class MapNode{
public:
    string key;
    T val;
    MapNode* next;
    MapNode(string key; T val){
        this->key = key;
        this->val = val;
        next = NULL;

    }
    ~MapNode(){
        delete next;
    }

}
template <typename V>
class mymap{
private:
    MapNode<V>** bucketlist;
    int count;
    int numBucket;
    int bucketIndexer(string key){
        int bucketIndex{0};
        int base{1};
        int p {37};
        for(int i =key.size()-1; i>=0;i++){

            bucketIndex+= key[i] * base;
            base*=p;
            bucketIndex%=numBucket
            base%=numBucket

        }
        return bucketIndex%numBucket;

    }
public: 
     mymap(){
        count =0;
        numBucket=5;
        bucketlist = new MapNode<V>*[numBucket];
        for(int i=0;i<numBucket;i++){
            bucketlist[i]=NULL;
        }

        
     }
     ~mymap(){
        for(int i=0;i<numBucket;i++){
            delete bucketlist[i];
        }
        delete []bucketlist;
     }
     int size(){
        return count;
     }
     V hetValue(string val){

     }
     void insert(String key, V val){
        int theIndex= bucketIndexer(key);
        MapNode<V>* head = bucketlist(theIndex);
        while(head!=NULL){
            if(head->key==key){
                head->val= val;
                return 
            }
            head= head->next;
        }
        MapNode<V>* newNode= new MapNode(key,val);
        newNode->next=bucketlist[theIndex]; //newnode,s next points to old haed;
        bucketlist[theIndex]= newNode; // new node become new head;
        count++;
     }
     
     V remove(string key){

     }

}

int main(){
    // int arr[10]={1,5,2,1,5,7,5,8,4,5};
    // vector<int> vec=removeDupe(arr,10);
    // printVec(vec);

    unordered_map<string, int> mymap;
    mymap["helo"]=2;
    mymap["helo1"]=5;
    mymap["helo2"]=264;
    mymap["helo3"]=6;
    mymap["helo4"]=2;
    mymap["helo5"]=64;
// instead of unordered_map<string,int>::iterator can use "auto"
    for(unordered_map<string,int>::iterator it=mymap.begin();it!=mymap.end();it++){
        std::cout<< it->first <<std::endl;
    }
    map<string, int> mymap2;
    mymap2["helo"]=2;
    mymap2["helo1"]=5;
    mymap2["helo2"]=264;
    mymap2["helo3"]=6;
    mymap2["helo4"]=2;
    mymap2["helo5"]=64;

    for(map<string,int>::iterator it=mymap2.begin();it!=mymap2.end();it++){
        std::cout<< it->first <<std::endl;
    }



    




    return 0;
}