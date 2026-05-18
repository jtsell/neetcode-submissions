template <typename T>
struct Node {
    T data;
    Node* next;
};

class LinkedList {
   private:
    Node<int>* head;

   public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node<int>* curr = head;
        while (curr != nullptr) {
            Node<int>* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int index) {
        if (!head) return -1;
        Node<int>* curr = head;
        for (int i = 0; i < index; i++) {
            if (!curr) return -1;
            curr = curr->next;
        }
        return curr ? curr->data : -1;
    }

    void insertHead(int val) {
        Node<int>* newNode = new Node{val, head};
        head = newNode;
    }

    void insertTail(int val) {
        Node<int>* newNode = new Node{val};
        Node<int>* tail = head;
        if (!tail) {
            head = newNode;
            return;
        }
        while (tail->next != nullptr) tail = tail->next;
        tail->next = newNode;
    }

    bool remove(int index) {
        if (index == 0) {
            if (!head) return false;
            Node<int>* newHead = head->next;
            delete head;
            head = newHead;
            return true;
        }
        if (!head) return false;

        Node<int>* curr = head;
        Node<int>* prev = nullptr;
        for (int i = 0; i < index; i++) {
            if (!curr) return false;
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return false;
        prev->next = curr->next;
        delete curr;
        return true;
    }

    vector<int> getValues() {
        vector<int> vals;
        for (Node<int>* curr = head; curr != nullptr; curr = curr->next) {
            vals.push_back(curr->data);
        }
        return vals;
    }
};