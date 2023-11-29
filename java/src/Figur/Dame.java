package Figur;

import java.util.List;

public class Dame extends Figur{
    public Dame(String color) {
        super(color, (!color.equals("Weiß") ? '\u2655' : '\u265B'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        return null;
    }
}
