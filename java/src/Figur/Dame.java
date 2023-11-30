package Figur;

import Spiel.Spiel;

import java.util.ArrayList;
import java.util.List;

public class Dame extends Figur {
    public Dame(String color) {
        super(color, (!color.equals("Weiß") ? '\u2655' : '\u265B'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte, Spiel spiel) {
        List<String> moves = new ArrayList<>();

        for (int i = 1; i <= 8; i++) {
            if (i != zeile) {
                moves.add("" + (char) (spalte + 'a' - 1) + i);
            }
            if (i != spalte) {
                moves.add("" + (char) (i + 'a' - 1) + zeile);
            }
        }

        for (int i = -8; i <= 8; i++) {
            if (i != 0) {
                int newZeile = zeile + i;
                int newSpalte = spalte + i;
                if (newZeile >= 1 && newZeile <= 8 && newSpalte >= 1 && newSpalte <= 8) {
                    moves.add("" + (char) (newSpalte + 'a' - 1) + newZeile);
                }

                newSpalte = spalte - i;
                if (newZeile >= 1 && newZeile <= 8 && newSpalte >= 1 && newSpalte <= 8) {
                    moves.add("" + (char) (newSpalte + 'a' - 1) + newZeile);
                }
            }
        }

        return moves;
    }
}
