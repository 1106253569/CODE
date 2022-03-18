public class STRING {
    public static void main(String[] args) {
        String w = "";
        String greeting = "Hello";
        String s = greeting.substring(0, 3);
        System.out.println(s);
        String expletive = w + greeting + s;
        System.out.println(expletive);
        int a = 13;
        System.out.println(expletive + a);
        String all = String.join("/", "S", "M", "L", "XL");
        System.out.println(all);
        System.out.println("Java/".repeat(3));
        /*
        *if (greeting.equals(s)) {
        *    System.out.println("These is one string");
        *} else {
        *    System.out.println("There is no a String ");
        *}
        */
        System.out.println(greeting.length());
        System.out.println(greeting.codePointCount(0, greeting.length()));
        System.out.println(greeting.charAt(1));
        int index = greeting.offsetByCodePoints(0, 2);
        System.out.println(index);
        System.out.println(greeting.codePointAt(index));
        /*
        *StringBuilder builder = new StringBuilder();
        *builder.append(greeting);
        *builder.append(s);
        *String ch = builder.toString();
        *System.out.println(ch);
         */

    }
}
