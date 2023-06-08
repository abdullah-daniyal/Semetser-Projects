package com.example;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;

public class Admin extends Person {
    Complaint complaint = new Complaint();
    ComplaintData complainantData = new ComplaintData();

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
        if (complainantData.getNumberOfLines() == lineno)
            starter.BrowseComplaint(0);

        else
            starter.BrowseComplaint(lineno);
    }

    void sendCompaintDetails() {
        // send complaints to the concerned department
        String sourceFile = "Complaints.txt"; // Replace with the actual source file name
        String destinationFile = "ForwardedComplaints.txt"; // Replace with the actual destination file name

        try (BufferedReader reader = new BufferedReader(new FileReader(sourceFile));
                BufferedWriter writer = new BufferedWriter(new FileWriter(destinationFile))) {

            String line;
            while ((line = reader.readLine()) != null) {
                writer.write(line);
                writer.newLine();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        try {
            FileWriter fileWriter = new FileWriter(sourceFile, false);
            fileWriter.write("");
            fileWriter.close();
            System.out.println("File emptied successfully.");
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    void DeleteAccount(String reason, String description, int toOpen) {
        String inputFile = "Accounts.txt"; // Replace with the actual input file name
        String outputFile = "BannedAcc.txt"; // Replace with the actual output file name
        String details = complaint.getComplaint(toOpen);
        String[] detailsArray = details.split(",");
        String target = detailsArray[3]; // Specify the target value to remove lines containing it

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
                BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {

            String line;
            while ((line = reader.readLine()) != null) {
                if (!line.contains(target)) {
                    writer.write(line);
                    writer.newLine();
                }
            }

        } catch (IOException ex) {
            ex.printStackTrace();
        }

        try {
            Path inputPath = Path.of(inputFile);
            Path outputPath = Path.of(outputFile);

            // Rename the output file to the input file name
            Files.move(outputPath, inputPath, StandardCopyOption.REPLACE_EXISTING);

            // Delete the original input file
            Files.deleteIfExists(outputPath);
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        try {
            FileWriter fileWriter = new FileWriter("Complaints.txt", false);
            fileWriter.write("");
            fileWriter.close();
            System.out.println("File emptied successfully.");
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        String storeacc = "BannedAccounts.txt";
        // store detailsArray in BannendAcc.txt
        try {
            FileWriter fileWriter = new FileWriter(storeacc, true);
            fileWriter.write(detailsArray[1] + "," + detailsArray[3] + "," + reason + "," + description);
            fileWriter.write("\n");
            fileWriter.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    String viewComplaint(int complaintno) {
        return complaint.getComplaint(complaintno);
    }

    boolean isCorrectForwardType(String type_selected, String type_is) {
        if (type_selected.equals(type_is))
            return true;
        else
            return false;
    }
}
