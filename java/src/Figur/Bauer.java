package Figur;

public class Bauer extends Figur{
    public Bauer(String color) {
        super(color, (color.equals("Weiß") ? '\u2659' : '\u265F'));
    }
}
