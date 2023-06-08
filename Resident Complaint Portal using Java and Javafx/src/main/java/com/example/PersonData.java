package com.example;
import java.util.ArrayList;

public class PersonData {
    private Account account=new Account();

    public boolean iscorrectcredentials(String cnic, String password, String type)
    {
        //do file handling
        //System.out.println("CNIC is correct: "+cnic);
        if(account.verifycredentials(cnic, password, type))
        {
            //System.out.println("Password is correct true: "+password);
            return true;
        }
        else
        {
            return false;
        }
    }
}