package Figur;

import java.util.List;

public class Koenig extends Figur{
    public Koenig(String color) {
        super(color, (!color.equals("Weiß") ? '\u2654' : '\u265A'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        return null;
    }
}
