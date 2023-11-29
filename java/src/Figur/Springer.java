package Figur;

import java.util.ArrayList;
import java.util.List;

public class Springer extends Figur {
    public Springer(String color) {
        super(color, (!color.equals("Weiß") ? '\u2658' : '\u265E'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        List<String> moves = new ArrayList<>();
        int[][] richtungen = { { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 }, { -1, -2 }, { -1, 2 }, { 1, -2 }, { 1, 2 } };

        for (int[] richtung : richtungen) {
            int neueZeile = zeile + richtung[0];
            int neueSpalte = spalte + richtung[1];
            if (neueZeile >= 1 && neueZeile <= 8 && neueSpalte >= 1 && neueSpalte <= 8) {
                moves.add("" + (char) (neueSpalte + 'a' - 1) + neueZeile);
            }
        }

        return moves;
    }
}
