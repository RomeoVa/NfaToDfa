//
//  main.cpp
//  NfaToDfa
//
//  Created by Romeo Varela on 4/25/19.
//  Copyright © 2019 Romeo Varela. All rights reserved.
//

#include "NFA_DFA.h"

#include <map>

int main() {
    
    //map<pair<int, char>,vector<int>> mymap;
    
    //mymap.insert(make_pair(make_pair(0,'a'), 1));
    //mymap.insert(make_pair(make_pair(0,'b'), 2));
    
    //mymap[make_pair(0, 'a')].push_back(1);
    //mymap[make_pair(0, 'a')].push_back(2);
    //mymap[make_pair(0, 'a')].push_back(2);
    
    /*vector<int> v,v2;
    
    v.push_back(1);
    v.push_back(2);
    v2.push_back(1);
    v2.push_back(2);
    
    if(v==v2){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }*/
    
    NFA_DFA n("NFA_example.txt");
    
    return 0;
}
