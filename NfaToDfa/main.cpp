//
//  main.cpp
//  NfaToDfa
//
//  Created by Romeo Varela on 4/25/19.
//  Copyright © 2019 Romeo Varela. All rights reserved.
//

#include "NFA_DFA.h"

int main() {
    string nfaFilePath,dfaFilePath;
    
    cout<<"NFA-e file path: "<<"\n";
    cin>>nfaFilePath;
    
    cout<<"DFA file path: "<<"\n";
    cin>>dfaFilePath;
    
    NFA_DFA n(nfaFilePath);
    
    n.nfa_to_dfa();
    
    n.write_dfa(dfaFilePath);
    
    return 0;
}
