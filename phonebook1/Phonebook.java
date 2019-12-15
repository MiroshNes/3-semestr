/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package phonebook;

/**
 *
 * @author 123
 */
public class Phonebook {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws CloneNotSupportedException  {
        AddressBook addressBook = new AddressBook();
        addressBook.addRecord("Вася", "Петя", "12.01.12", "15:00", "5");
        System.out.println(addressBook.allRecords());
        addressBook.addRecord("Настя", "Сережа", "09.12.18", "18:00", "20");
        System.out.println(addressBook.allRecords());
        addressBook.addRecord("Саша", "Костя", "25.06.15", "12:35", "12");
        System.out.println(addressBook.allRecords());

    }

    
}
