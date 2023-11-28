package Figur;

public class Lauefer extends Figur{
    public Lauefer(String color) {
        super(color, (!color.equals("Weiß") ? '\u2657' : '\u265D'));
    }
}
