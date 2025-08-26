struct Node {
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;

    Node(int k, int v): key(k), val(v), cnt(1), next(nullptr), prev(nullptr) {};
};

class List {
public:
    int size;
    Node* head;
    Node* tail;
    
    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    void insertAtFront(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }

    ~List() {
        // Clean up all nodes (except sentinels)
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

class LFUCache {
public:
    int capacity;
    int minFreq;
    int curSize;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        this->curSize = 0;
    }

    void updateFreqListMap(Node* node) {
        int freq = node->cnt;
        freqListMap[freq]->removeNode(node);
        
        if(freq == minFreq && freqListMap[freq]->size == 0) {
            minFreq++; // previous freq list is empty.
        }

        node->cnt += 1;
        if(freqListMap.find(node->cnt) == freqListMap.end()) {
            freqListMap[node->cnt] = new List();
        }
        freqListMap[node->cnt]->insertAtFront(node);
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];
        updateFreqListMap(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(keyNode.find(key) != keyNode.end()) {
            Node* existingNode = keyNode[key];
            existingNode->val = value;
            updateFreqListMap(existingNode); // remove from curFreqList, add to freq++ list
        }
        else {
            if(curSize == capacity) {
                List* list = freqListMap[minFreq];
                Node* nodeToRemove = list->tail->prev;
                keyNode.erase(nodeToRemove->key);
                list->removeNode(nodeToRemove);
                delete nodeToRemove;
                curSize--;
            }
            
            Node* newNode = new Node(key, value);
            minFreq = 1;
            
            if(freqListMap.find(minFreq) == freqListMap.end()) {
                freqListMap[minFreq] = new List();
            }
            keyNode[key] = newNode;
            freqListMap[minFreq]->insertAtFront(newNode);
            curSize++;
        }
    }

    ~LFUCache() {
        for (auto& pair : freqListMap) {
            delete pair.second;
        }
    }
};