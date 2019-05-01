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
        
        alphabet.insert(pair<int, char>(1,'a'));
        alphabet.insert(pair<int, char>(2,'b'));
        alphabet.insert(pair<int, char>(3,'c'));
        alphabet.insert(pair<int, char>(4,'d'));
        alphabet.insert(pair<int, char>(5,'e'));

        nfa.close();
    }else{
        cout<<"Couldn´t open file\n";
        return;
    }
}

void NFA_DFA::epsilon_closure(vector<int>& State){
    
    for(int i=0; i<State.size(); i++){
        e_closure.push(State[i]);
    }
    
    while (!e_closure.empty()) {
        
        if(!NFA_table[make_pair(e_closure.front(), 'f')].empty()){
            
            for (int i=0; i<NFA_table[make_pair(e_closure.front(), 'f')].size() ; i++) {
                if(find(State.begin(),State.end(),
                        NFA_table[make_pair(e_closure.front(), 'f')][i]) == State.end()){
                    
                    State.push_back(NFA_table[make_pair(e_closure.front(), 'f')][i]);
                    e_closure.push(NFA_table[make_pair(e_closure.front(), 'f')][i]);
                    
                }
            }
        }
        e_closure.pop();
    }
}

void NFA_DFA::nfa_to_dfa(){
    
    int idState;
    
    currentState.push_back(initialState);
    
    epsilon_closure(currentState);
    
    DFA_states.push_back(currentState);
    
    for(int i=0; i<finalStates.size(); i++){
        if(find(currentState.begin(), currentState.end(), finalStates[i]) != currentState.end())
        {
            finalDfaStates.push_back(0);
            break;
            
        }
    }
    
    currentState.clear();
    
    states.push(DFA_states.size()-1);
    
    while (!states.empty()) {
        
        dfaState = DFA_states[states.front()];
        for(int i=1; i<=alphabetSize-1; i++){
            for(int j=0; j<dfaState.size(); j++){
                if(!NFA_table[make_pair(dfaState[j], alphabet[i])].empty()){
                    for(int x=0; x<NFA_table[make_pair(dfaState[j], alphabet[i])].size(); x++){
                        
                        if(find(currentState.begin(),currentState.end(),
                                NFA_table[make_pair(dfaState[j],alphabet[i])][x]) == currentState.end()){
                            
                            currentState.push_back(NFA_table[make_pair(dfaState[j],alphabet[i])][x]);
                            
                        }
                    }
                
                }
               
            }
            
            if(!currentState.empty()){
                
                epsilon_closure(currentState);
                
                sort(currentState.begin(), currentState.end());
                
                dfaAlphabet.insert(alphabet[i]);
                
                if(find(DFA_states.begin(), DFA_states.end(), currentState) != DFA_states.end()){
                    
                    vector<vector<int>>::iterator it=find(DFA_states.begin(), DFA_states.end(), currentState);
                    
                    idState = distance(DFA_states.begin(), it);
                    DFA_table[make_pair(states.front(), alphabet[i])] = idState ;
                    
                }else{
                    DFA_states.push_back(currentState);
                    idState=DFA_states.size()-1;
                    states.push(idState);
                    
                    DFA_table[make_pair(states.front(), alphabet[i])] = idState ;
                    
                    for(int i=0; i<finalStates.size(); i++){
                        if(find(currentState.begin(), currentState.end(), finalStates[i]) != currentState.end())
                        {
                            finalDfaStates.push_back(idState);
                            break;
                            
                        }
                    }
                }
                
                currentState.clear();
            }
            
        }
        
        states.pop();
    
    }
    
    /*cout<<DFA_states.size()<<endl;
    cout<<dfaAlphabet.size()<<endl;
    cout<<finalDfaStates.size()<<endl;
    
    for(int i=0; i<finalDfaStates.size(); i++){
        cout<<finalDfaStates[i]<<endl;
    }
    
    cout<<DFA_table.size()<<endl;

    for(map<pair<int,char>, int>::const_iterator it = DFA_table.begin();it != DFA_table.end(); ++it)
    {
        cout << it->first.first << " " << it->second << " " << it->first.second << "\n";
    }*/
    
}

void NFA_DFA::write_dfa(string file){
    ofstream dfa(file);
    
    dfa<<DFA_states.size()<<"\n";
    dfa<<dfaAlphabet.size()<<"\n";
    dfa<<finalDfaStates.size()<<"\n";
    
    for(int i=0; i<finalDfaStates.size(); i++){
        dfa<<finalDfaStates[i]<<"\n";
    }
    
    dfa<<DFA_table.size()<<"\n";
    
    for(map<pair<int,char>, int>::const_iterator it = DFA_table.begin();it != DFA_table.end(); ++it)
    {
        dfa << it->first.first << " " << it->second << " " << it->first.second << "\n";
    }
}
