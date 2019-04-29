//
//  NFA_DFA.cpp
//  NfaToDfa
//
//  Created by Romeo Varela on 4/26/19.
//  Copyright © 2019 Romeo Varela. All rights reserved.
//

#include "NFA_DFA.h"

NFA_DFA::NFA_DFA(string filePath){
    
    ifstream nfa(filePath);
    int n,finalNode,startNode;
    char symbol;
    
    if(nfa.is_open()){
        nfa>>stateAmount;
        nfa>>alphabetSize;
        nfa>>finalStateAmount;
        
        for(int i=0; i<finalStateAmount; i++){
            nfa>>n;
            finalStates.push_back(n);
        }
        
        nfa>>transitionAmount;
        
        for(int i=0; i<transitionAmount; i++){
            nfa>>startNode>>finalNode>>symbol;
            
            NFA_table[make_pair(startNode, symbol)].push_back(finalNode);
            
        }

        nfa.close();
    }else{
        cout<<"Couldn´t open file\n";
        return;
    }
}
