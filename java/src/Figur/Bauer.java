package Figur;

import java.util.List;

public class Bauer extends Figur{
    public Bauer(String color) {
        super(color, (!color.equals("Weiß") ? '\u2659' : '\u265F'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        return null;
    }
}
