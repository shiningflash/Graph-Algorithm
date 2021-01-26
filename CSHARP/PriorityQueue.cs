using System;

public class PriorityQueue {
    public int[] heap { get; set; }
    public int capacity { get; set; }
    public int size { get; set; }

    public PriorityQueue(int capacity) {
        heap = new int[capacity];
        this.capacity = capacity;
        this.size = 0;
    }

    public int Parent(int n) {
        return (n - 1) / 2;
    }

    public int Left(int n) {
        return n * 2 + 1;
    }

    public int Right(int n) {
        return n * 2 + 2;
    }

    public static void Swap<T>(ref T x, ref T y) {
        T tmp = x;
        x = y;
        y = tmp;
    }

    public bool Push(int val) {
        if (size == capacity) return false;
        
        int i = size;
        heap[i] = val;
        size++;

        while (i != 0 && heap[i] < heap[Parent(i)]) {
            Swap(ref heap[i], ref heap[Parent(i)]);
            i = Parent(i);
        }
        return true;
    }

    public int Top() {
        return heap[0];
    }

    public int Pop() {
        if (size <= 0) return int.MaxValue;
        if (size == 1) {
            size--;
            return heap[0];
        }
        
        int root = heap[0];
        heap[0] = heap[size-1];
        size--;
        MinHeapify(0);

        return root;
    }

    public void MinHeapify(int pos) {
        int l = Left(pos);
        int r = Right(pos);

        int smallest = pos;

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest != pos) {
            Swap(ref heap[pos], ref heap[smallest]);
            MinHeapify(smallest);
        }
    }

    public void decreaseVal(int pos, int val) {
        heap[pos] = val;

        while (pos != 0 && heap[pos] < heap[Parent(pos)]) {
            Swap(ref heap[pos], ref heap[Parent(pos)]);
            pos = Parent(pos);
        }
    }

    public void Deleteval(int pos) {
        decreaseVal(pos, int.MinValue);
        Pop();
    }

    public bool isEmpty() {
        return size <= 0;
    }
}