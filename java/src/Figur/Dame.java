package Figur;

public class Dame extends Figur{
    public Dame(String color) {
        super(color, (color.equals("Weiß") ? '\u2655' : '\u265B'));
    }
}
