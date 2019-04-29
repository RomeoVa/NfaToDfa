//
//  NFA_DFA.hpp
//  NfaToDfa
//
//  Created by Romeo Varela on 4/26/19.
//  Copyright © 2019 Romeo Varela. All rights reserved.
//

#ifndef NFA_DFA_hpp
#define NFA_DFA_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class NFA_DFA {
    
    private:
        int stateAmount;
        int alphabetSize;
        int finalStateAmount;
        vector<int> finalStates;
        vector<int> currentState;
        vector<vector<int>> DFA_states;
        int transitionAmount;
        map<pair<int, char>,vector<int>> NFA_table;
        queue<int> e_closure;
        queue<int> states;
    
    public:
        NFA_DFA(string filePath);
    
    
    
};
#endif /* NFA_DFA_hpp */
