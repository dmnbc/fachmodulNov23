package Figur;

import Spiel.Spiel;

import java.util.ArrayList;
import java.util.List;

public class Bauer extends Figur {
    public Bauer(String color) {
        super(color, (!color.equals("Weiß") ? '\u2659' : '\u265F'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte, Spiel spiel) {
        List<String> moves = new ArrayList<>();
        int direction = this.getColor().equals("Schwarz") ? -1 : 1;

        int nextRow = zeile + direction;
        String key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (spalte + 'a' - 1) + nextRow;
        if (nextRow >= 1 && nextRow <= 8 && spiel.isWegFrei(key,spiel)) {
            moves.add("" + (char) (spalte + 'a' - 1) + nextRow);
        }

        if ((this.getColor().equals("Schwarz") && zeile == 7) || (this.getColor().equals("Weiß") && zeile == 2)) {
            nextRow += direction;
            key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (spalte + 'a' - 1) + nextRow;

            if (nextRow >= 1 && nextRow <= 8 && spiel.isWegFrei(key,spiel)) {
                moves.add("" + (char) (spalte + 'a' - 1) + nextRow);
            }
        }

        return moves;
    }
}
