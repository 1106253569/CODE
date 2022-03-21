public interface Movable {
    double move(double x, double y);
}

interface Powered extends Movable {
    double SPEED_LIMIT = 95;

    double milesPerGallon();
}

class movableTest implements Powered {

    @Override
    public double move(double x, double y) {
        return y - x;
    }

    @Override
    public double milesPerGallon() {
        return SPEED_LIMIT;
    }
}


