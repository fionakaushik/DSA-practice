class LRUCache {
    //we will use a DLL and a HashMap

public:
    struct Node{
        public:
            int key,val;
            Node* prev;
            Node* next;
            Node(int k,int v)
            {
                key=k;
                val=v;
                prev=next=NULL;
            }
    };
    //dummy nodes
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    void addNode(Node* newNode)  //O(1)
    {
        //store head->next first as oldNext 
        Node* oldNext=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=oldNext;
        oldNext->prev=newNode;
    }
    void deleteNode(Node* oldNode)  //O(1)
    {
        //storw the node to be deleted's prev and nxt
        Node* oldPrev=oldNode->prev;
        Node* oldNext=oldNode->next;

        //change links
        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;
        
    }
    unordered_map<int,Node*>mpp;

    int limit;
    
    LRUCache(int capacity) {
        limit =capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        //if not found 
        if(mpp.find(key)==mpp.end())
        {
            return -1;
        }
        //IF FOUND IN THE MAP ,give value,delete it,add it in front again

        // int ans=mpp[key]->val;

        
        Node* ansNode=mpp[key];
        int ans= ansNode->val;
        //dlt this ans node 
        mpp.erase(key);
        deleteNode(ansNode);
        
        //insert again
        addNode(ansNode);
        mpp[key]=ansNode;

        return ans;    
        
    }
    
    void put(int key, int value) { //O(1)
        
        //check if that key already present in map
        if(mpp.find(key)!=mpp.end())
        {
            //dlt it and updte new node with key val
            Node* oldNode=mpp[key]; //val is node* type
            deleteNode(oldNode);
            //erase it from map also
            mpp.erase(key);
        }
        //check if size is full 
        if(mpp.size()==limit){
            //delete LRU node/data
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        //create new ode put in map and DLL
        Node* newNode=new Node(key,value);
        addNode(newNode);//add newnode in DLL in start(head->next)
        mpp[key]=newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */