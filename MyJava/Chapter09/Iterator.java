import java.util.function.Consumer;

public interface Iterator<E> {
    E next();

    boolean hasNext();

    void remove();

    default void forEachRemaining(Consumer<? super E> action) {

    }

}
