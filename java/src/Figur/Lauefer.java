package Figur;

import java.util.List;

public class Lauefer extends Figur{
    public Lauefer(String color) {
        super(color, (!color.equals("Weiß") ? '\u2657' : '\u265D'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        return null;
    }
}
