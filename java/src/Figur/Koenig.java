package Figur;

public class Koenig extends Figur{
    public Koenig(String color) {
        super(color, (!color.equals("Weiß") ? '\u2654' : '\u265A'));
    }
}
