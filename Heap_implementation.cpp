class maxHeap {
    public:
        int arr[100000];
        int size;

    maxHeap() {
        arr[0] = -1;
        size = 0;
    }

    //T.C O(logn)
    void push(int val) {

        size++;
        int index = size;
        arr[index] = val;

        while(index>1) {
            int parent = index/2;

            if(arr[parent]<arr[index]) {
                swap(arr[parent],arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }
    //T.C O(log n)
    void pop() {

        if(size==0) {
            cout<<"There is nothing to delete"<<endl;
            return;
        }

        //step 1: put last element into first index
        arr[1] = arr[size];
        //step 2: remove last element
        size--;

        //take root node to its correct position
        int i = 1;
        while(i<size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            } else if(rightIndex<size && arr[i]<arr[rightIndex]) {
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            } else {
                return;
            }
        }
    }

    void print() {
        for(int i=1;i<=size;i++) {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};
