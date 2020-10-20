class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* copy = nullptr;
        Node* original = head;
        while(original != NULL)
        {
            copy = new Node(original->val);
            mp[original] = copy;
            original= original->next;
        }
        original = head;
        while(original != NULL)
        {
            copy = mp[original];
            copy->next = mp[original->next];
            copy->random = mp[original->random];
            original = original->next;
            
        }
        return mp[head];
        
    }
};