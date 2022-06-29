public class Pair<T> {
    private T first;
    private T second;

    public Pair() {
        first = null;
        second = null;
    }

    public Pair(T first, T second) {
        setFirst(first);
        setSecond(second);
    }

    public T getFirst() {
        return first;
    }

    public void setFirst(T newValue) {
        this.first = newValue;
    }

    public T getSecond() {
        return second;
    }

    public void setSecond(T newValue) {
        this.second = newValue;
    }

    public Pair<T> getBonus() {
        return new Pair<>(getFirst(), getSecond());
    }

}
