package com.example;

import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;
import javafx.application.Application;

//make main
public class RCP {

    public static void main(String[] args) {
        // start the application
        // put 1234567 as admin cnic and admin as password in admin.txt
        // FileWriter fw = null;
        // try {
        // fw = new FileWriter("Admin.txt");
        // fw.write("1234,admin\n");
        // fw.close();
        // } catch (Exception e) {
        // System.out.println(e);
        // }
        Application.launch(Starter.class, args);
    }
}