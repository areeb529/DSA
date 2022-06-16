class MinStack {
public:
    class Node{
        public:
        int data;
        Node*next;
        int minM;
        Node(int data){
            this->data=data;
            next=NULL;
            minM=data;
        }
    };
    Node*head;
    Node*tail;
    MinStack() {
        head=NULL;
        tail=NULL;
    }
    
    void push(int val) {
        Node*newNode=new Node(val);
        newNode->next=tail;
        if(head==NULL)head=newNode;
        tail=newNode;
        if(tail->next){
            tail->minM=min(tail->minM,tail->next->minM);
        }
    }
    
    void pop() {
        Node*temp=tail;
        tail=tail->next;
        temp->next=NULL;
        delete temp;
    }
    
    int top() {
        return tail->data;
    }
    
    int getMin() {
        return tail->minM;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */