package Figur;

import java.util.List;

public class Springer extends Figur{
    public Springer(String color) {
        super(color, (!color.equals("Weiß") ? '\u2658' : '\u265E'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        return null;
    }
}
