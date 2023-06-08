package com.example;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.text.SimpleDateFormat;

public class Complainant extends Person {
    private int complainantID;
    private int noOfComplaints;
    private Complaint complaint;

    public Complainant() {
        this.complainantID = 0;
        this.noOfComplaints = 0;
        this.complaint = new Complaint();
    }

    void BrowseComplaints(String id) {
        Starter starter = new Starter();
        int lineno = 0;
        // get line no where there is id
        try {
            FileReader fr = new FileReader("Complaints.txt");
            BufferedReader br = new BufferedReader(fr);
            String line;
            while ((line = br.readLine()) != null) {
                if (line.contains(id)) {
                    break;
                }
                lineno++;
            }
            br.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        starter.BrowseComplaint(lineno);
    }

    void RegisterComplaint(String name, String address, String cnic, String complaint, String description,
            String expedite) {
        // System.out.println("Before: "+name+" "+address+" "+cnic+" "+complaint+"
        // "+description+" "+expedite);
        try (FileWriter writer = new FileWriter("Complaints.txt", true)) {
            // generate 6 digit random number
            int random = (int) (Math.random() * 900000) + 100000;
            // todays date and store in string
            String date = new SimpleDateFormat("dd-MM-yyyy").format(new Date());

            writer.write(random + "," + name + "," + address + "," + cnic + "," + complaint + "," + description + ","
                    + date + "," + expedite + "\n");
        } catch (IOException eX) {
            System.err.println("Error writing to file: " + eX.getMessage());
        }
    }

    public boolean isExpedite(String status) {
        if (status == "Yes") {
            return true;
        }
        return false;
    }
}
