package com.example;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Account {
    private int registeredUsers;

    int RegisterAccount(String cnic, String passwordInput, String confirmpass, int age, String address,
            String phoneno) {
        // if cnic<13 or >13
        if (cnic.length() != 13) {
            return 1;
        }
        // if password<8 or >8
        if (passwordInput.length() <= 8) {
            return 2;
        }
        // if password!=confirmpass
        if (!passwordInput.equals(confirmpass)) {
            return 3;
        }
        // if age<18
        if (age < 18) {
            return 4;
        }
        // if phoneno<11 or >11
        if (phoneno.length() != 11) {
            return 5;
        } else {
            String password = passwordInput;
            String phoneNumber = phoneno;

            try (FileWriter writer = new FileWriter("Accounts.txt", true)) {
                writer.write(cnic + "," + password + "," + age + "," + address + "," + phoneNumber + "\n");
            } catch (IOException eX) {
                System.err.println("Error writing to file: " + eX.getMessage());
            }
        }
        return 0;
    }

    boolean verifycredentials(String cnicInput, String passwordInput, String type) {
        if (type.equals("user")) {
            String fileName = "Accounts.txt";

            try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    String[] credentials = line.split(",");
                    if (credentials.length >= 2) {
                        String cnic = credentials[0];
                        String password = credentials[1];
                        if (cnic.equals(cnicInput) && password.equals(passwordInput)) {
                            // System.out.println("Password is correct true: " + password);
                            return true;
                        }
                    }
                }
            } catch (IOException e) {
                System.err.println("Error reading file: " + e.getMessage());
            }
        } else if (type.equals("admin")) {
            String fileName = "Admin.txt";

            try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    String[] credentials = line.split(",");
                    if (credentials.length >= 2) {
                        String cnic = credentials[0];
                        String password = credentials[1];
                        if (cnic.equals(String.valueOf(cnicInput)) && password.equals(passwordInput)) {
                            // System.out.println("Password is correct true: " + password);
                            return true;
                        }
                    }
                }
            } catch (IOException e) {
                System.err.println("Error reading file: " + e.getMessage());
            }
        }
        return false;
    }
}
