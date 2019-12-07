/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ships;

/**
 *
 * @author 123
 */
public class Tanker extends CargoShip {
         private String name;
         private int year;
         private String type;
         private int Lenght;
         
         public Tanker(String name, int year, String type, int Lenght) {
            super(name, year , type, Lenght);
            this.name = name;
            this.year = year;
            this.type = type;
            this.Lenght = Lenght;
     }
    @Override
    public String getName() {
        return name;
    }
 
    @Override
    public int getYear() {
        return year;
    }
 
    @Override
    public String getType() {
        return type;
    }
 
 
    @Override
    public int getLenght() {
        return Lenght;
    }
}