package Figur;

import Spiel.Spiel;

import Spiel.Feld;

import java.util.List;
import java.util.Map;

public abstract class Figur {
    private final String color; // Entweder Weiß oder Schwarz
    private final char symbol; // UniCode Zeichen für die Spielfiguren.
    private final String name;
    private final Map<String, Feld> spielMap;

    public Figur(String color, char symbol, Map<String, Feld> spielMap) {
        if (!color.equals("Weiß") && !color.equals("weiß")) {
            this.color = "Schwarz";
        } else {
            this.color = color.toUpperCase().charAt(0) + color.substring(1);
        }
        this.spielMap = spielMap;
        this.symbol = symbol;
        this.name = getClass().getSimpleName();
    }
    public abstract List<String> getPossibleMoves(int zeile, int spalte, Spiel spiel);
    public String getColor() {
        return color;
    }

    public char getSymbol() {
        return symbol;
    }

    public String getName() {
        return name;
    }
     Map<String,Feld> getSpielMap(){
        return this.spielMap;
    }
}