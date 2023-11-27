package Figur;

public class Springer extends Figur{
    public Springer(String color) {
        super(color, (color.equals("Weiß") ? '\u2658' : '\u265E'));
    }
}
