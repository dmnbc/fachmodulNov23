package Figur;

import Spiel.Feld;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Laeufer extends Figur {
    public Laeufer(String color, Map<String, Feld> spielMap) {
        super(color, (!color.equals("Weiß") ? '\u2657' : '\u265D'),  spielMap);
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        List<String> moves = new ArrayList<>();

        // Diagonale Bewegungen
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
