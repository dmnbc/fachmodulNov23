package Figur;

import java.util.List;

public class Turm extends Figur{
    public Turm(String color) {
        super(color, (!color.equals("Weiß") ? '\u2656' : '\u265C'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        return null;
    }
}
