package com.example;

import java.util.Scanner;

import javafx.util.converter.BooleanStringConverter;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Date;

public class Person {
    String name;
    String cnic;
    String password;
    int age;
    PersonData personData;

    void getCNIC(String cnic) {
        this.cnic = cnic;
        System.out.println("CNIC: " + cnic);
    }

    void getName(String name) {
        this.name = name;
    }

    void getPassword(String password) {
        this.password = password;
        System.out.println("Password: " + password);
    }

    void getAge(int age) {
        this.age = age;
    }

    boolean EnterCredentials(String cnic, String password, String type) {
        PersonData personData = new PersonData();
        if (personData.iscorrectcredentials(cnic, password, type)) {
            // System.out.println("Login Successful");
            return true;
            // Complainant complainant = new Complainant();
            // complainant.RegisterComplaint();

        } else {
            System.out.println("Login Failed");
        }
        return false;
    }
}
