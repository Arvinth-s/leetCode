//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    
    char ch;
    Trie* children[26];
    bool completed;
    
    
    Trie() {
        this->ch=' ';
        for(int i=0; i<26; i++)this->children[i]=NULL;
        this->completed=true;
    }
    
    Trie(char ch){
        this->ch=ch;
        for(int i=0; i<26; i++)this->children[i]=NULL;
        this->completed=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *traversal = this;
        for(char ch:word){
            if(traversal->children[ch-'a'] != NULL)traversal=traversal->children[ch-'a'];
            else{
                traversal->children[ch-'a']=new Trie(ch);
                traversal=traversal->children[ch-'a'];
            }
        }
        traversal->completed=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *traversal = this;
        for(char ch:word){
            if(traversal->children[ch-'a'] != NULL)traversal=traversal->children[ch-'a'];
            else{
                return false;
            }
        }
        return traversal->completed;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *traversal = this;
        for(char ch:prefix){
            if(traversal->children[ch-'a'] != NULL)traversal=traversal->children[ch-'a'];
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */