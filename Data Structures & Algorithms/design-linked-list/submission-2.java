class MyLinkedList {
    class ListNode {
        int val;
        ListNode next;
        
        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    ListNode head;
    int size;

    public MyLinkedList() {
        head = new ListNode(0, null);
        size = 0;
    }
    
    public int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        ListNode curr = head.next;
        for (int i = 0; i < index; i++) {
            curr = curr.next;
        }
        
        return curr.val;
    }
    
    public void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    public void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    public void addAtIndex(int index, int val) {
        if (index > size || index < 0) {
            return;
        }

        ListNode pred = head; 
        
        for (int i = 0; i < index; i++) {
            pred = pred.next;
        }

        ListNode newNode = new ListNode(val, pred.next);
        pred.next = newNode;
        
        size++;
    }
    
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        ListNode pred = head; 
        
        for (int i = 0; i < index; i++) {
            pred = pred.next;
        }

        pred.next = pred.next.next;
        
        size--;
    }
}