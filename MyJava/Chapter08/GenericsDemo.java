public class GenericsDemo {
    public static void main(String[] args) {
        String[] words = {"Mary", "had", "a", "little", "lamb"};
        Pair<String> mm = new Pair<>(words[4], words[1]);
        System.out.println(mm.getFirst());
        System.out.println(mm.getSecond());

    }

    static <T extends Throwable> void throwAs(Throwable t) throws T {
        throw (T) t;
    }

}


