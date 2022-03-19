public class Demo {
    public static final double C = 2.54;

    public static void main(String[] args) {
        int i = 4;
        int j = 5;
        System.out.println(i + j);
        System.out.println("Hello world!");
        double a = 8.5;
        double b = 11;
        System.out.println("paper size in centimeters:" + a * C + " by " + b * C);
        enum Size {S, M, L, XL}
        Size s = Size.M;
        System.out.println(s);
        double x = 4;
        double y = Math.sqrt(x);
        System.out.println(y);
        double z = Math.pow(x, 3);
        System.out.println(z);
        x = 9.997;
        int nx = (int) Math.round(x);
        System.out.println(nx + (int) x);

    }
}
