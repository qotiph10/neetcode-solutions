class MyCircularQueue {
    class ListNode {
        int val;
        ListNode next;
        public ListNode(int val) {
            this.val = val;
        }
    }

    int size;
    int curSize;
    ListNode front;
    ListNode rear;

    public MyCircularQueue(int k) {
        size = k;
        curSize = 0;
        front = null;
        rear = null;
    }
    
    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        }

        ListNode newNode = new ListNode(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear.next = newNode;
            rear = newNode;
        }
        
        curSize++;
        return true;
    }
    
    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = front.next;
        curSize--;
        
        if (isEmpty()) {
            rear = null;
        }
        
        return true;
    }
    
    public int Front() {
        if (isEmpty()) {
            return -1;
        }
        return front.val;
    }
    
    public int Rear() { 
        if (isEmpty()) {
            return -1;
        }
        return rear.val;
    }
    
    public boolean isEmpty() {
        return curSize == 0;
    }
    
    public boolean isFull() {   
        return curSize == size;
    }
}