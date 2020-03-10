package prove02;

import java.awt.*;
import java.util.Random;

public class Wolf extends Creature implements Movable, Aggressor, Aware {
    Random _rand;

    public Wolf() {
        _health = 1;
        _rand = new Random();
    }

    public void attack(Creature target) {
        boolean isAnimal = target instanceof Animal;
        if(isAnimal) {
            target.takeDamage(10);
        }
    }


    public void senseNeighbors(Creature above, Creature below, Creature left, Creature right) {


    }

    public Color getColor() {
        return new Color(153, 153, 153);
    }
    public Boolean isAlive() {
        return _health > 0;
    }
    public Shape getShape() {
        return Shape.Square;
    }

    public void move() {
        // Choose a random direction each time move() is called.

        switch(_rand.nextInt(4)) {
            case 0:
                _location.x++;
                break;
            case 1:
                _location.x--;
                break;
            case 2:
                _location.y++;
                break;
            case 3:
                _location.y--;
                break;
            default:
                break;
        }

    }
}
