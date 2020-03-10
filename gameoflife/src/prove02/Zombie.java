package prove02;

import java.awt.*;
import java.util.Random;


public class Zombie extends Creature implements Movable, Aggressor {
    Random _rand;

    public Zombie() {
        _health = 1;
        _rand = new Random();
    }

    Shape getShape() {
        return Shape.Square;
    }
    Color getColor() {
        return new Color(0, 0, 255);
    }
    Boolean isAlive() {
        return _health > 0;
    }

    public void attack(Creature target) {
        boolean isAnimal = target instanceof Animal;
        if(isAnimal) {
            target.takeDamage(10);
        }
    }


    public void move() {

        // Choose a random direction each time move() is called.
        switch(_rand.nextInt(2)) {
            case 0:
                _location.x++;
                break;
            case 1:
                _location.x--;
                break;
            default:
                break;
        }
    }
}
