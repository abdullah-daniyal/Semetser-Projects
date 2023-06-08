package com.example;

public class Payment {
    private Double CreditCardNo;
    private int CVC;
    private String expirydate;
    private int Zipfield;

    public Payment(Double CreditCardNo, int CVC, String expirydate, int Zipfield) {
        this.CVC = CVC;
        this.CreditCardNo = CreditCardNo;
        this.Zipfield = Zipfield;
        this.expirydate = expirydate;
    }

    Double getCreditCardNo() {
        return CreditCardNo;
    }

    int getCVC() {
        return CVC;
    }

    int getzipField() {
        return Zipfield;
    }

    String getexpirydate() {
        return expirydate;
    }

    int isValidCredentials(Double CreditCardNo, int CVC, String expirydate, int Zipfield) {
        // if credit card number is not 16 digits
        String numberString = String.valueOf(CreditCardNo);
        int length = numberString.length();
        System.out.println(length);
        length -= 4;
        if (length != 16) {
            return 1;
        }
        // if cvc<3 or >3
        String numberString2 = String.valueOf(CVC);
        int length2 = numberString2.length();
        if (length2 != 3) {
            return 2;
        }
        if (CVC - (CreditCardNo % 1000) != 0) {
            return 2;
        }
        boolean validFormat = false;
        String pattern = "(0[1-9]|1[0-2])/\\d{2}";
        if (expirydate.matches(pattern)) {
            validFormat = true;
        }
        if (!validFormat) {
            return 3;
        }

        // incorrect zipcode
        numberString = String.valueOf(Zipfield);
        length = numberString.length();
        if (length != 5) {
            return 4;
        } else {
            return 0;
        }
    }
}
