class LRUCache {
public:
    class node{
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key,int val)
        {
            this->key=key;
            this->val=val;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    unordered_map<int,node*> mp;
    int cap;

    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    void addNode(node* newNode)
    {
        node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }
    void deleteNode(node* delNode)
    {
        node* delPrev=delNode->prev;
        node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node* currNode=mp[key];
            int currVal=currNode->val;
            deleteNode(currNode);
            mp.erase(key);
            addNode(currNode);
            mp[key]=head->next;
            return currVal;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node* currNode=mp[key];
            mp.erase(key);
            deleteNode(currNode);
        }
        if(mp.size()==cap)
        {
            node* currNode=tail->prev;;
            mp.erase(currNode->key);
            deleteNode(currNode);
        }
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */