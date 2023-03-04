public class TestShape {
    static Shape[] shapes=new Shape[3];

    public static void main(String[] args) {
        shapes[0]= new Circle(2);
        shapes[1]=new Triangle(1,2,3);
        shapes[2]=new Rectangle(2,4);
        double sum=0;
        for (Shape shape : shapes) {
            sum += shape.getPerimeter();
        }
        System.out.println("所有子对象周长的和为: "+sum);
    }


}

class Triangle extends Shape{
    double A;
    double B;
    double C;

    public Triangle(double a,double b,double c){
        A=a;
        B=b;
        C=c;
    }

    public void draw() {

    }


    public double getPerimeter() {
        return A+B+C;
    }


    public double getArea() {
        double p=getPerimeter()/2;
        return Math.sqrt(p*(p-A)*(p-B)*(p-C));
    }
}

class Circle extends Shape{
    int R;

    public Circle(int r){
        R=r;
    }

    public void draw() {
    }


    public double getPerimeter() {
        return 2*3.14*R;
    }

    public double getArea() {
        return 3.14*R*R;
    }
}

class Rectangle extends Shape{
    double L;
    double H;
    public Rectangle(double length,double height){
        L=length;
        H=height;
    }

    public void draw() {
    }

    public double getPerimeter() {
        return 2*(L+H);
    }


    public double getArea() {
        return L*H;
    }
}