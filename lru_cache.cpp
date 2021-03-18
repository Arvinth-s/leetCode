struct node{
    node *next, *prev;
    int key, val;
    node(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    int capacity;
    int current_size;
    unordered_map<int, node*> key_val;
    node *front, *back;

public:
    LRUCache(int capacity) {
        this->current_size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!key_val[key])return -1;
        if(key_val[key]==back)return key_val[key]->val;
        node *temp = key_val[key];
        
        //modyfing prev & temp
        temp->next->prev = temp->prev;
        if(temp!=front){
            //i.e temp->prev != NULL
            temp->prev->next = temp->next;
        }else{
            front = temp->next;
        }
        
        //modifying back & temp
        temp->prev = back;
        temp->next = NULL;
        back->next = temp;
        back=temp;
        return temp->val;
    }
    
    void put(int key, int value) {
        if(current_size==0){
            front = back = new node(key, value);
            key_val[key] = front;
            this->current_size++;
        }
        
        //if it already exists update it and update queue
        else if(key_val[key]){
            key_val[key]->val = value;
            get(key);
        }
        
        
        else{
            node* temp = new node(key, value);
            temp->prev = back;
            back->next = temp;
            key_val[key] = back = temp;
            if(this->current_size < this->capacity){
                this->current_size++;
            }else{
                //removing the least recently used element
                if(front->next){
                    front->next->prev = NULL;
                }
                key_val[front->key] = NULL;
                temp = front;
                front = front->next;
                delete(temp);
            }
        }
        
    }
};
