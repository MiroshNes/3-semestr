/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package phonebook;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.w3c.dom.ranges.RangeException;

/**
 *
 * @author 123
 */
public class record implements Serializable, Cloneable{
    private long id;
    private String name;
    private String name2;
    private String date;
    private String time;
    private String duration;
    
    public record(long id, String name,String name2, String date, String time, String duration ) {
        this.id = id;
        this.name = name;
        this.name2 = name2;
        this.date = date;
        this.time = time;
        this.duration = duration;
    }
    @Override
    public String toString() {
        return  name + ": " + name2 + ", " + date + ", " + time + ", " + duration;
        
    }
        @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final record other = (record) obj;
        if ((this.name == null) ? (other.name != null) : !this.name.equals(other.name)) {
            return false;
        }
        if ((this.name2 == null) ? (other.name2 != null) : !this.name2.equals(other.name2)) {
            return false;
        }
        if ((this.date == null) ? (other.date != null) : !this.date.equals(other.date)) {
            return false;
        }
        if ((this.time == null) ? (other.time != null) : !this.time.equals(other.time)) {
            return false;
        }
        if ((this.duration == null) ? (other.duration != null) : !this.duration.equals(other.duration)) {
            return false;
        }
        return true;
    }
    @Override
    public int hashCode() {
        int hash = 7;
        hash = 61 * hash + (int) (this.id ^ (this.id >>> 32));
        hash = 61 * hash + (this.name != null ? this.name.hashCode() : 0);
        hash = 61 * hash + (this.name2 != null ? this.name2.hashCode() : 0);
        hash = 61 * hash + (this.date != null ? this.date.hashCode() : 0);
        hash = 61 * hash + (this.time != null ? this.time.hashCode() : 0);
        hash = 61 * hash + (this.duration != null ? this.duration.hashCode() : 0);
        return hash;
    }
    
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    public long getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public String getName2() {
        return name2;
    }
    public String getDate () {
        return date;
    }
    public String getTime () {
        return time;
    }
    public String getDuration () {
        return duration;
    }
}

 class AddressBook {
    private Map<Long, record> records = new HashMap<Long, record>();
    private long nextId;
    private long getNextId() {
        if (nextId < Long.MAX_VALUE && !records.containsKey(nextId))
            return nextId++;
        nextId = 0;
        while (nextId < Long.MAX_VALUE) {
            if (!records.containsKey(nextId))
                return nextId;
            ++nextId;
        }
        throw new RangeException((short)111, "No more IDs availiable");
    }
    public record addRecord(String name, String name2, String date, String time, String duration) 
        throws CloneNotSupportedException {
        long recordId = getNextId();
        record record = new record(recordId, name, name2, date, time, duration);
        records.put(recordId, record);
        return (record)record.clone();
    }
    public record getRecord(long id) throws CloneNotSupportedException {
        if (records.containsKey(id))
            return (record)records.get(id).clone();
        return null;
    }
    public record updateRecord(long id, String name, String name2, String date, String time, String duration)
        throws CloneNotSupportedException {
        record record = new record(id, name, name2, date, time, duration);
        records.put(id, record);
        return getRecord(id);
    }
    public void removeRecord(long id) {
        records.remove(id);
    }
    public List<record> allRecords() {
        List<record> result = new ArrayList<record>();
        for (record record : this.records.values())
            result.add(record);
        return result;
    }

}

