class DynamicArray {
   private:
    int* arr = nullptr;
    int size;
    int capacity;

   public:
    DynamicArray(int capacity) : arr(new int[capacity]), size(0), capacity(capacity) {}

    ~DynamicArray() { delete[] arr; }

    DynamicArray(const DynamicArray& other)
        : arr(new int[other.capacity]), size(other.size), capacity(other.capacity) {
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;
        delete[] arr;
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    int get(int i) const {
        // According to spec, we can assume:
        // 1. i >= 0
        // 2. i < size
        // So the following is valid:
        return arr[i];
    }

    void set(int i, int n) {
        // According to spec, we can assume:
        // 1. i >= 0
        // 2. i < size
        // Otherwise, this would be rather unsafe:
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        int value = arr[size - 1];
        size--;
        return value;
    }

    void resize() {
        capacity = capacity * 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() const { return size; }

    int getCapacity() const { return capacity; }
};
