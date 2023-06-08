package com.example;

abstract class Report {
    int toOpen;

    public void DisplayReport(int toOpen) {
        // polymorphism applied here. This is virtual class
        this.toOpen = toOpen;
    }
}

class ComplaintDocument extends Report {

    @Override
    public void DisplayReport(int toOpen) {
        Starter s = new Starter();
        s.ConvertToPdf(toOpen);
    }
}

class SurveyReport extends Report {
    @Override
    public void DisplayReport(int toOpen) {
        Starter s = new Starter();
        s.ConvertToPdf(toOpen);
    }
}