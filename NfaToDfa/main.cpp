//
//  main.cpp
//  NfaToDfa
//
//  Created by Romeo Varela on 4/25/19.
//  Copyright © 2019 Romeo Varela. All rights reserved.
//

#include "NFA_DFA.h"

int main() {
    
    //map<pair<int, char>,vector<int>> mymap;
    
    //mymap.insert(make_pair(make_pair(0,'a'), 1));
    //mymap.insert(make_pair(make_pair(0,'b'), 2));
    
    //mymap[make_pair(0, 'a')].push_back(1);
    //mymap[make_pair(0, 'a')].push_back(2);
    //mymap[make_pair(0, 'a')].push_back(2);
    
    
    /*queue<int> q;
    int a;
    
    q.push(10);
    q.push(20);
    
    a=q.front();
    
    cout<<a<<endl;*/
    NFA_DFA n("NFA_example.txt");
    
    n.nfa_to_dfa();
    
    return 0;
}
