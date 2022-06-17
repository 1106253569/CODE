public class staff
        extends People {
    String Id;
    String position;

    public staff(String n, String s,String I,String p) {
        super(n, s);
        Id=I;
        position=p;
    }

    public void setPosition(String newPosition){
        position=newPosition;
    }

    public String getId() {
        return Id;
    }

    public String getPosition() {
        return position;
    }

    public String getName() {
        return super.getName();
    }

    public String toString() {
        return "ID: "+getId()+"\tName: "+getName()+"\tSex: "+super.getSex()+"\tPosition: "+getPosition();
    }
}

class People {
    String name;
    String sex;

    public People(String n,String s) {
        name=n;
        sex=s;
    }

    public String getName() {
        return name;
    }

    public String getSex() {
        return sex;
    }
}
