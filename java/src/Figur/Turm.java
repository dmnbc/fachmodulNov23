package Figur;

public class Turm extends Figur{
    public Turm(String color) {
        super(color, (color.equals("Weiß") ? '\u2656' : '\u265C'));
    }
}
