package Figur;

import java.util.ArrayList;
import java.util.List;

public class Koenig extends Figur {
    public Koenig(String color) {
        super(color, (!color.equals("Weiß") ? '\u2654' : '\u265A'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        List<String> moves = new ArrayList<>();

        for (int rowDiff = -1; rowDiff <= 1; rowDiff++) {
            for (int colDiff = -1; colDiff <= 1; colDiff++) {
                if (rowDiff != 0 || colDiff != 0) {
                    int newRow = zeile + rowDiff;
                    int newCol = spalte + colDiff;
                    if (newRow >= 1 && newRow <= 8 && newCol >= 1 && newCol <= 8) {
                        moves.add("" + (char) (newCol + 'a' - 1) + newRow);
                    }
                }
            }
        }

        return moves;
    }
}
