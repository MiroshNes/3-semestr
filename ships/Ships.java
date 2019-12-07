/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ships;

import java.util.ArrayList;

/**
 *
 * @author 123
 */
public class Ships {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       ArrayList<ship> Ships = new ArrayList<>();
       ship ship = new CargoShip("Batillus", 1976, "нефтеналивной", 414 ); 
       Ships.add(ship);
       Ships.add(new Tanker("Mozah", 2007, "газоперевозка", 345));
       
       printShips(Ships);
    }
    
    public static void printShips(ArrayList<ship> Ships){
        for (ship ship : Ships){
            System.out.println("Name: " + ship.getName());
            System.out.println("Year: " + ship.getYear());
            System.out.println("Type: " + ship.getType());
            System.out.println("Lenght: " + ship.getLenght());
        }
    }
}
