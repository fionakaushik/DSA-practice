class LFUCache {
public:
    struct Node{
        int key,value,cnt;
        Node* prev;
        Node* next;
        Node(int k , int v)
        {
            key=k;
            value=v;
            cnt=1;     //freq cnt to which it belongs (its default)
            prev=next=NULL;
        }

    };

    //structure of frequency specific DLL's
    struct List{
        int size;
        //dummy nodes
        Node* head;
        Node* tail;
        List()
        {
            head= new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        //islolated helper fns for each list wo keep count of increase /decrease of sixe of list
        void addFront(Node* newNode)
        {
            Node* oldNext=head->next;
            head->next=newNode;
            newNode->prev=head;
            newNode->next=oldNext;
            oldNext->prev=newNode;
            size++;
        }
        void removeNode( Node* delNode)
        {
            delNode->prev->next=delNode->next;
            delNode->next->prev=delNode->prev;
            size--;
        }
    };
    map<int,Node*>keyNode; //unordered map {key,address of key's node}
    map<int,List*>freqListMap; //
    int maxSizeCache;
    int minFreq;       
    int currSize;     //curr size of the cache
    
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        minFreq=0;
        currSize=0;
        
    }
    void updateFreqListMap(Node* node)
    {
        //erase from the keyNode map first
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);  //[gives us the value of int freq] that is a list hence we call lists' remove node fn 
        
        //if node belongs to min freq &if the list of minfreq becomes 0 we remove the list
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0)
            minFreq++;
            //create a new list of next higher freq
        List* nextHigherFreqList = new List();

        //if nextfreq list alr exists for that node we simply add the node to that list
        if(freqListMap.find(node->cnt+1)!=freqListMap.end())
        {
            nextHigherFreqList=freqListMap[node->cnt+1];
        }

        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt]=nextHigherFreqList; 
        keyNode[node->key]=node;

    }
    
    int get(int key) {
        //if key found in keynode map its present
        if(keyNode.find(key)!=keyNode.end())
        {
            //access its val 
            Node* valNode=keyNode[key];
            int val=valNode->value;
            //gotta update its freq 
            updateFreqListMap(valNode); //fn to update nodes to their increases freq list after access
            return val;

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if (maxSizeCache==0)
            return;
            //if key alr present
        if (keyNode.find(key)!=keyNode.end()){
            //update its freq
            Node* node=keyNode[key];
            node->value=value; //update prev value w new 
            //update node's frq
            updateFreqListMap(node);
        }
        else
        {
            if(currSize==maxSizeCache)
            {
                //access the minfreq list
                List* list=freqListMap[minFreq];
                //delet LRU node from this minfreq list
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--; //size of the list
            }
            currSize++;
            //new value has to be added who is not there previously in the list
            minFreq=1;
            List* listFreq=new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
                listFreq=freqListMap[minFreq];
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;

        }
    }
    //If the variable is...	Use this operator
    // If the variable is...	An Object (List myList)  . (Dot)
    // If the variable is...   A Pointer (List* myListPtr)  -> (Arrow)
    
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */