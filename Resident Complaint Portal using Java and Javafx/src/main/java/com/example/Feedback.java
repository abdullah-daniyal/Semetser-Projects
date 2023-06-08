package com.example;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.StrokeLineCap;
import javafx.scene.shape.StrokeType;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;
import javafx.stage.Window;

public class Feedback {

    private ArrayList<FeedbackData> feedbackData;

    public Feedback() {
        feedbackData = new ArrayList<FeedbackData>();
    }

    @FXML
    private Pane container;
    private Window stage;

    @FXML
    private void submit(ActionEvent event) throws IOException {
        // Show messagebox that complaint has been registered
        Alert alert = new Alert(AlertType.INFORMATION);
        alert.setTitle("Feedback Submitted");
        alert.setHeaderText(null);
        alert.setContentText("Thank you for your feedback!");

        alert.showAndWait();
        System.out.println("Feedback submitted");
    }

    // get Feedback
    public ArrayList<FeedbackData> getFeedbackData() {
        return feedbackData;
    }

    // set Feedback
    public void setFeedbackData(ArrayList<FeedbackData> feedbackData) {
        this.feedbackData = feedbackData;
    }

    // select category
    public void selectCategory(String category) {
        for (FeedbackData feedback : feedbackData) {
            if (feedback.getCategory().equals(category)) {
                feedback.selectCategory(true);
            }
        }
    }

    @FXML
    private void initialize() throws IOException {

        Image image = new Image(getClass().getResourceAsStream("/assets/dashboard.png"));
        javafx.scene.image.ImageView imageView = new javafx.scene.image.ImageView(image);
        imageView.setLayoutX(40.0);
        imageView.setLayoutY(23.0);
        imageView.setFitHeight(39.0);
        imageView.setFitWidth(45.0);
        imageView.setSmooth(false);

        Image image1 = new Image(getClass().getResourceAsStream("/assets/browse.png"));
        javafx.scene.image.ImageView imageView1 = new javafx.scene.image.ImageView(image1);
        imageView1.setLayoutX(43.0);
        imageView1.setLayoutY(105.0);
        imageView1.setFitHeight(44.0);
        imageView1.setFitWidth(43.0);
        imageView1.setPreserveRatio(true);

        Image image2 = new Image(getClass().getResourceAsStream("/assets/analysis.png"));
        javafx.scene.image.ImageView imageView2 = new javafx.scene.image.ImageView(image2);
        imageView2.setLayoutX(40.0);
        imageView2.setLayoutY(175.0);
        imageView2.setFitHeight(47.0);
        imageView2.setFitWidth(48.0);
        imageView2.setPreserveRatio(true);

        Image image3 = new Image(getClass().getResourceAsStream("/assets/feedback.png"));
        javafx.scene.image.ImageView imageView3 = new javafx.scene.image.ImageView(image3);
        imageView3.setLayoutX(40.0);
        imageView3.setLayoutY(270.0);
        imageView3.setFitHeight(47.0);
        imageView3.setFitWidth(48.0);
        imageView3.setPickOnBounds(true);
        imageView3.setPreserveRatio(true);
        imageView3.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                try {
                    initializee(event);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        container.getChildren().add(imageView);
        container.getChildren().add(imageView1);
        container.getChildren().add(imageView2);
        container.getChildren().add(imageView3);

    }

    @FXML
    public void initializee(MouseEvent event) throws IOException {
        Rectangle rectangle = new Rectangle();
        rectangle.setArcHeight(5.0);
        rectangle.setArcWidth(5.0);
        rectangle.setFill(Color.web("#5672a9"));
        rectangle.setHeight(64.0);
        rectangle.setLayoutX(170.0);
        rectangle.setLayoutY(30.0);
        rectangle.setStroke(Color.WHITE);
        rectangle.setStrokeType(StrokeType.INSIDE);
        rectangle.setWidth(1036.0);

        Text submitText = new Text();
        submitText.setLayoutX(596.0);
        submitText.setLayoutY(72.0);
        submitText.setStrokeType(StrokeType.OUTSIDE);
        submitText.setStrokeWidth(0.0);
        submitText.setStyle("-fx-font-weight: bold;");
        submitText.setText("Submit Feedback");
        submitText.setFont(Font.font(26.0));
        submitText.setWrappingWidth(261.2764892578125);

        System.out.println("Feedback submitted");
        TextField nameField = new TextField();
        nameField.setLayoutX(219);
        nameField.setLayoutY(153);
        nameField.setPrefHeight(44);
        nameField.setPrefWidth(360);
        nameField.setPromptText("Name");
        nameField.setFont(Font.font("System Bold", 20));

        TextField cnicField = new TextField();
        cnicField.setLayoutX(217);
        cnicField.setLayoutY(220);
        cnicField.setPrefHeight(44);
        cnicField.setPrefWidth(360);
        cnicField.setPromptText("CNIC");
        cnicField.setFont(Font.font("System Bold", 20));

        Text selectProblemText = new Text("Select Problem");
        selectProblemText.setLayoutX(217);
        selectProblemText.setLayoutY(321);
        selectProblemText.setStrokeType(javafx.scene.shape.StrokeType.OUTSIDE);
        selectProblemText.setStrokeWidth(0);
        selectProblemText.setFont(Font.font(20));

        ChoiceBox<String> problemChoiceBox = new ChoiceBox<>();
        problemChoiceBox.setLayoutX(214);
        problemChoiceBox.setLayoutY(341);
        problemChoiceBox.setPrefHeight(44);
        problemChoiceBox.setPrefWidth(366);
        problemChoiceBox.setItems(FXCollections.observableArrayList(
                "Electricity Problem", "Water Problem", "Road Problem"));

        TextArea descriptionArea = new TextArea();
        descriptionArea.setLayoutX(216);
        descriptionArea.setLayoutY(506);
        descriptionArea.setPrefHeight(153);
        descriptionArea.setPrefWidth(366);
        descriptionArea.setPromptText("Description");
        descriptionArea.setFont(Font.font(20));

        TextField bugsField = new TextField();
        bugsField.setLayoutX(664);
        bugsField.setLayoutY(153);
        bugsField.setPrefHeight(44);
        bugsField.setPrefWidth(360);
        bugsField.setPromptText("Any Bugs?");
        bugsField.setFont(Font.font("System Bold", 20));

        Button chooseFileButton = new Button("Choose File");
        chooseFileButton.setLayoutX(886);
        chooseFileButton.setLayoutY(220);
        chooseFileButton.setMnemonicParsing(false);
        chooseFileButton.setPrefHeight(44);
        chooseFileButton.setPrefWidth(137);
        chooseFileButton.setFont(Font.font(17));
        chooseFileButton.setOnAction(e -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Open Resource File");
            // once file is selected, show the name of the file
            // in the text field
            File selectedFile = fileChooser.showOpenDialog(stage);
            if (selectedFile != null) {
                Text text = new Text(selectedFile.getName());
                text.setLayoutX(700);
                text.setLayoutY(245);
                text.setFont(new Font(16));
                container.getChildren().add(text);
            }
        });

        Button submitButton = new Button("Submit");
        submitButton.setLayoutX(893);
        submitButton.setLayoutY(592);
        submitButton.setMnemonicParsing(false);
        submitButton.setPrefHeight(44);
        submitButton.setPrefWidth(131);
        submitButton.setFont(Font.font("System Bold", 18));
        submitButton.setOnAction(e -> {

            if (nameField.getText().isEmpty() || cnicField.getText().isEmpty() || descriptionArea.getText().isEmpty()
                    || problemChoiceBox.getValue().isEmpty()) {
                Alert alert = new Alert(AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText(null);
                alert.setContentText("Please fill all the fields!");

                alert.showAndWait();
                return;
            } else {
                // add to feedbackData
                feedbackData.add(new FeedbackData(nameField.getText(), cnicField.getText(), problemChoiceBox.getValue(),
                        descriptionArea.getText(), bugsField.getText()));
                // add to database
                feedbackData.stream().forEach((feedback) -> {
                    feedback.addToDatabase(nameField.getText(), cnicField.getText(), problemChoiceBox.getValue(),
                            descriptionArea.getText(), bugsField.getText());
                });
                // Show messagebox that complaint has been registered
                Alert alert = new Alert(AlertType.INFORMATION);
                alert.setTitle("Feedback Submitted");
                alert.setHeaderText(null);
                alert.setContentText("Thank you for your feedback!");

                alert.showAndWait();
                System.out.println("Feedback submitted");
            }
        });

        Pane pane = new Pane();
        pane.setLayoutX(0);
        pane.setLayoutY(0);
        pane.setPrefHeight(44);
        pane.setPrefWidth(100);

        pane.getChildren().add(rectangle);
        pane.getChildren().add(submitText);
        pane.getChildren().add(nameField);
        pane.getChildren().add(cnicField);
        pane.getChildren().add(selectProblemText);
        pane.getChildren().add(problemChoiceBox);
        pane.getChildren().add(descriptionArea);
        pane.getChildren().add(bugsField);
        pane.getChildren().add(chooseFileButton);
        pane.getChildren().add(submitButton);

        container.getChildren().add(pane);
    }

    // get feedback
    public void getFeedback() throws IOException {
        // call initialize
        initializee(null);
    }

}