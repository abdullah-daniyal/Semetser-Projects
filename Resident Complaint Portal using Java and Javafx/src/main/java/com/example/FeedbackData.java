package com.example;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class FeedbackData {
    private int feedbackID;
    private String Name;
    private String cnic;
    private String category;
    private String description;
    private String bugsField;
    private String dateReceived;
    private Boolean Selected;

    public FeedbackData(String Name, String cnic, String Category, String description, String bugsField) {
        this.feedbackID += 1;
        this.Name = Name;
        this.cnic = cnic;
        this.category = Category;
        this.description = description;
        this.bugsField = bugsField;
        this.dateReceived = java.time.LocalDate.now().toString();
    }

    public int getFeedbackID() {
        return feedbackID;
    }

    public void setFeedbackID(int feedbackID) {
        this.feedbackID = feedbackID;
    }

    // select feedback
    public void selectCategory(Boolean selected) {
        Selected = selected;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public void addToDatabase(String Name, String cnic, String category, String description, String bugsField) {
        // todays dateReceived
        String dateReceived = java.time.LocalDate.now().toString();
        // add to file database
        String data = Name + "," + cnic + "," + category + "," + description + "," + bugsField + "," + dateReceived;
        // write to file
        String fileName = "feedback.txt";
        try {
            FileWriter fw = new FileWriter(fileName, true);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(data);
            bw.newLine();
            bw.close();
        } catch (IOException e) {
            System.out.println("Error writing to file");
        }
    }
}