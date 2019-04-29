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
#include <set>

using namespace std;

class NFA_DFA {
    
    private:
        int stateAmount;
        int alphabetSize;
        int finalStateAmount;
        const int initialState = 0;
        vector<int> finalStates;
        vector<int> finalDfaStates;
        vector<int> currentState;
        vector<int> dfaState;
        vector<vector<int>> DFA_states;
        int transitionAmount;
        map<pair<int, char>,vector<int>> NFA_table;
        map<int, char> alphabet;
        map<pair<int, char>,int> DFA_table;
        queue<int> e_closure;
        queue<int> states;
        set<char> dfaAlphabet;
    
    public:
        NFA_DFA(string filePath);
    
        void epsilon_closure(vector<int>& State);
        void nfa_to_dfa();
    
    
    
};
#endif /* NFA_DFA_hpp */
