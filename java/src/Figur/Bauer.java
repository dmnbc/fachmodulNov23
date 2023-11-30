package Figur;

import java.util.ArrayList;
import java.util.List;

public class Bauer extends Figur {
    public Bauer(String color) {
        super(color, (color.equals("Weiß") ? '\u2659' : '\u265F'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        List<String> moves = new ArrayList<>();
        int direction = getColor().equals("Weiß") ? -1 : 1;

        int nextRow = zeile + direction;
        if (nextRow >= 1 && nextRow <= 8) {
            moves.add("" + (char) (spalte + 'a' - 1) + nextRow);
        }

        if ((getColor().equals("Weiß") && zeile == 7) || (getColor().equals("Schwarz") && zeile == 2)) {
            nextRow += direction;
            if (nextRow >= 1 && nextRow <= 8) {
                moves.add("" + (char) (spalte + 'a' - 1) + nextRow);
            }
        }

        return moves;
    }
}
