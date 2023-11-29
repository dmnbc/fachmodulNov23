package Figur;

import java.util.ArrayList;
import java.util.List;

public class Turm extends Figur {
    public Turm(String color) {
        super(color, (!color.equals("Weiß") ? '\u2656' : '\u265C'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        List<String> moves = new ArrayList<>();

        for (int i = 1; i <= 8; i++) {
            if (i != zeile) {
                moves.add("" + (char) (spalte + 'a' - 1) + i);
            }
            if (i != spalte) {
                moves.add("" + (char) (i + 'a' - 1) + zeile);
            }
        }

        return moves;
    }
}
