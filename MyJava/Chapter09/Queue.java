public interface Queue<E> {
    void add(E element);

    E remove();

    int size();
}

class CircularArrayQueue<E> implements Queue<E> {
    private int head;
    private int tail;
    private E[] element;


    CircularArrayQueue(int capacity) {

    }

    public void add(E element) {

    }

    public E remove() {
        return null;
    }

    @Override
    public int size() {
        return 0;
    }

}

class LinkedListQueue<E> implements Queue<E> {
    private int head;
    private int tail;

    LinkedListQueue() {

    }

    @Override
    public void add(E element) {

    }

    @Override
    public E remove() {
        return null;
    }

    @Override
    public int size() {
        return 0;
    }
}