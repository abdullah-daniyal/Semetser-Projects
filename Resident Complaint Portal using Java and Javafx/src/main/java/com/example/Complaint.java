package com.example;

import java.util.ArrayList;

public class Complaint {
    // stringg array
    private String complaintsString = "";
    ComplaintData ComplaintData = new ComplaintData();

    boolean getstatusofFile() {
        return ComplaintData.checkFile();
    }

    String getComplaint(int i) {

        complaintsString = ComplaintData.getID(i);
        complaintsString += ",";
        complaintsString += ComplaintData.getname(i);
        complaintsString += ",";
        complaintsString += ComplaintData.getAddress(i);
        complaintsString += ",";
        complaintsString += ComplaintData.getcnic(i);
        complaintsString += ",";
        complaintsString += ComplaintData.getCategory(i);
        complaintsString += ",";
        complaintsString += ComplaintData.getDescription(i);
        complaintsString += ",";
        complaintsString += ComplaintData.getDateReceived(i);
        complaintsString += ",";
        complaintsString += ComplaintData.getExpedite(i);
        complaintsString += ",";
        return complaintsString;

    }
}
