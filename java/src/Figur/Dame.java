package Figur;

import Spiel.Spiel;

import Spiel.Feld;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Dame extends Figur {
    public Dame(String color, Map<String, Feld> spielMap) {
        super(color, (!color.equals("Weiß") ? '\u2655' : '\u265B'),  spielMap);
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte, Spiel spiel) {
        List<String> moves = new ArrayList<>();
        String key;
        for (int i = 1; i <= 8; i++) {
            key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (spalte + 'a' - 1) + i;
            if (i != zeile && spiel.isWegFrei(key,spiel)) {
                moves.add("" + (char) (spalte + 'a' - 1) + i);
            }
            key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (i + 'a' - 1) + (char) (zeile + '1' - 1);
            if (i != spalte && spiel.isWegFrei(key,spiel)) {
                moves.add("" + (char) (i + 'a' - 1) + zeile);
            }
        }

        for (int i = -8; i <= 8; i++) {
            if (i != 0) {
                int newZeile = zeile + i;
                int newSpalte = spalte + i;
                key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (newSpalte + 'a' - 1) + newZeile;
                if (newZeile >= 1 && newZeile <= 8 && newSpalte >= 1 && newSpalte <= 8 && spiel.isWegFrei(key,spiel)) {
                    moves.add("" + (char) (newSpalte + 'a' - 1) + newZeile);
                }
                newSpalte = spalte - i;
                key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (newSpalte + 'a' - 1) + newZeile;

                if (newZeile >= 1 && newZeile <= 8 && newSpalte >= 1 && newSpalte <= 8 && spiel.isWegFrei(key,spiel)) {
                    moves.add("" + (char) (newSpalte + 'a' - 1) + newZeile);
                }
            }
        }

        return moves;
    }
}
