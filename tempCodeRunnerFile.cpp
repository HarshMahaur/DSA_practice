    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout<<key<<" "<<ourmap.getValue(key)<<endl;
    }
     cout<<ourmap.size()<<endl;