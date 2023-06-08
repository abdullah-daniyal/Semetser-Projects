package com.example;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Authenticator;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Random;

import java.util.Properties;
import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.print.PageLayout;
import javafx.print.PageOrientation;
import javafx.print.Paper;
import javafx.print.Printer;
import javafx.print.PrinterJob;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.SnapshotParameters;
import javafx.scene.control.Accordion;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Spinner;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.effect.BlendMode;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.WritableImage;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.robot.Robot;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.StrokeLineCap;
import javafx.scene.shape.StrokeType;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.Window;
import javafx.stage.FileChooser.ExtensionFilter;

//login
public class Starter extends Application {

    @FXML
    private Pane container;

    @FXML
    private Pane initializedPane;

    @Override
    public void start(Stage primaryStage) {
        AnchorPane root = new AnchorPane();

        ImageView backgroundImgView = new ImageView(new Image("zaki-muhamad-aGmNiU3UIC0-unsplash.jpg"));
        backgroundImgView.setFitHeight(449);
        backgroundImgView.setFitWidth(252);
        backgroundImgView.setLayoutX(349);

        ImageView logoImgView = new ImageView(new Image("Free_Sample_By_Wix.png"));
        logoImgView.setFitHeight(107);
        logoImgView.setFitWidth(106);
        logoImgView.setLayoutX(13);
        logoImgView.setLayoutY(-13);

        Text titleText = new Text("Residents Complaint Portal");
        titleText.setFill(Color.web("#19346e"));
        titleText.setLayoutX(216);
        titleText.setLayoutY(39);
        titleText.setStyle("-fx-font-weight: bold;");
        titleText.setUnderline(true);
        titleText.setWrappingWidth(131.75);

        Text welcomeText = new Text("Welcome, Dear Citizen / Member!");
        welcomeText.setFill(Color.web("#293399"));
        welcomeText.setLayoutX(21);
        welcomeText.setLayoutY(88);
        welcomeText.setFont(new Font(9));

        Text cnicText = new Text("CNIC");
        cnicText.setLayoutX(21);
        cnicText.setLayoutY(136);
        cnicText.setFont(new Font(8));

        Text passwordText = new Text("Password");
        passwordText.setLayoutX(21);
        passwordText.setLayoutY(163);
        passwordText.setFont(new Font(8));

        Button loginButton = new Button("Login");
        loginButton.setLayoutX(251);
        loginButton.setLayoutY(209);
        loginButton.setStyle("-fx-background-color: #95a2ff;");
        loginButton.setFont(new Font(9));

        Text registerText = new Text("Register Now!");
        registerText.setLayoutX(145);
        registerText.setLayoutY(263);
        registerText.setFont(new Font(8));

        Text followText = new Text("Follow us");
        followText.setLayoutX(21);
        followText.setLayoutY(326);
        followText.setFont(new Font(9));

        CheckBox rememberMeCheckbox = new CheckBox("Remember Me ?");
        rememberMeCheckbox.setLayoutX(21);
        rememberMeCheckbox.setLayoutY(208);
        rememberMeCheckbox.setFont(new Font(8));

        TextField cnicTextField = new TextField();
        cnicTextField.setLayoutX(87);
        cnicTextField.setLayoutY(123);
        cnicTextField.setPrefHeight(17);
        cnicTextField.setPrefWidth(197);
        cnicTextField.setFont(new Font(8));

        TextField passwordTextField = new TextField();
        passwordTextField.setLayoutX(87);
        passwordTextField.setLayoutY(152);
        passwordTextField.setPrefHeight(17);
        passwordTextField.setPrefWidth(197);
        passwordTextField.setFont(new Font(8));

        Line line1 = new Line(-49.8, 261, 57.33, 261);
        line1.setLayoutX(72);

        Line line2 = new Line();
        line2.setStartX(190);
        line2.setStartY(261);
        line2.setEndX(73.2);
        line2.setEndY(261);
        line2.setLayoutX(140);

        ImageView instagramImgView = new ImageView(new Image("instagram.png"));
        instagramImgView.setFitHeight(16);
        instagramImgView.setFitWidth(17);
        instagramImgView.setLayoutX(77);
        instagramImgView.setLayoutY(314);

        ImageView facebookImgView = new ImageView(new Image("facebook.png"));
        facebookImgView.setFitHeight(16);
        facebookImgView.setFitWidth(17);
        facebookImgView.setLayoutX(109);
        facebookImgView.setLayoutY(314);

        ImageView twitterImgView = new ImageView(new Image("twitter.png"));
        twitterImgView.setFitHeight(16);
        twitterImgView.setFitWidth(17);
        twitterImgView.setLayoutX(139);
        twitterImgView.setLayoutY(314);

        Button loginasadmin = new Button("Login as Admin");
        loginasadmin.setLayoutX(171);
        loginasadmin.setLayoutY(209);
        loginasadmin.setStyle("-fx-background-color: #95a2ff;");
        loginasadmin.setFont(new Font(9));

        root.getChildren().addAll(backgroundImgView, logoImgView, titleText, welcomeText, cnicText, passwordText,
                loginButton, registerText, followText, rememberMeCheckbox, cnicTextField, passwordTextField, line1,
                line2, instagramImgView, facebookImgView, twitterImgView, loginasadmin);

        Scene scene = new Scene(root, 600, 400);
        // Scene scene = new Scene(root, 1248, 715);

        primaryStage.setScene(scene);
        primaryStage.show();
        loginasadmin.setOnAction(e -> {
            String cnic = cnicTextField.getText();
            String password = passwordTextField.getText();
            Person person = new Person();
            person.getCNIC(cnic);
            person.getPassword(password);
            Boolean check;
            check = person.EnterCredentials(cnic, password, "admin");
            if (check == true) {
                AllComplaints();
            } else {
                Alert alert = new Alert(AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText("Invalid Credentials");
                alert.setContentText("Please enter valid CNIC and Password");
                alert.showAndWait();
            }
        });

        loginButton.setOnAction(e -> {
            // get cnic and password from text fields
            String cnic = cnicTextField.getText();
            String password = passwordTextField.getText();
            Person person = new Person();
            person.getCNIC(cnic);
            person.getPassword(password);
            Boolean check;
            check = person.EnterCredentials(cnic, password, "user");
            if (check == true) {
                RegisterComplaint(cnic);
            } else {
                Alert alert = new Alert(AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText("Invalid Credentials");
                alert.setContentText("Please enter valid CNIC and Password");
                alert.showAndWait();
            }
        });

        registerText.setOnMouseClicked(e -> {
            RegisterAccount();
            // RegisterAccount registerAccount = new RegisterAccount();
            // registerAccount.registerstart();
        });

    }

    private void RegisterAccount() {
        Stage primaryStage = new Stage();
        primaryStage.setTitle("Registration Form");

        // Create the registration form layout
        GridPane gridPane = new GridPane();
        gridPane.setAlignment(Pos.CENTER);
        gridPane.setHgap(10);
        gridPane.setVgap(10);
        gridPane.setPadding(new Insets(25, 25, 25, 25));

        // Add a title to the form
        Text titleText = new Text("Account Registration");
        titleText.setFont(Font.font("Tahoma", FontWeight.BOLD, 20));
        gridPane.add(titleText, 0, 0, 2, 1);

        // Add labels and input fields
        Label cnicLabel = new Label("CNIC:");
        gridPane.add(cnicLabel, 0, 1);

        TextField cnicField = new TextField();
        gridPane.add(cnicField, 1, 1);

        Label passwordLabel = new Label("Password:");
        gridPane.add(passwordLabel, 0, 2);

        PasswordField passwordField = new PasswordField();
        gridPane.add(passwordField, 1, 2);

        Label confirmPasswordLabel = new Label("Confirm Password:");
        gridPane.add(confirmPasswordLabel, 0, 3);

        PasswordField confirmPasswordField = new PasswordField();
        gridPane.add(confirmPasswordField, 1, 3);

        Label ageLabel = new Label("Age:");
        gridPane.add(ageLabel, 0, 4);

        Label addressLabel = new Label("Address:");
        gridPane.add(addressLabel, 0, 5);

        TextArea addressTextArea = new TextArea();
        addressTextArea.setPrefRowCount(2);
        addressTextArea.setPrefColumnCount(15);
        gridPane.add(addressTextArea, 1, 5);

        Label phoneNumberLabel = new Label("Phone Number:");
        gridPane.add(phoneNumberLabel, 0, 6);

        TextField phoneNumberField = new TextField();
        gridPane.add(phoneNumberField, 1, 6);

        Spinner<Integer> ageSpinner = new Spinner<>(1, 120, 18);
        gridPane.add(ageSpinner, 1, 4);

        // Add a register button
        Button registerButton = new Button("Register");
        gridPane.add(registerButton, 1, 7);

        // Add a registration status label
        Text registrationStatus = new Text();
        gridPane.add(registrationStatus, 0, 8, 2, 1);

        // make a back button
        Button backButton = new Button("Back");
        gridPane.add(backButton, 2, 7);
        backButton.setOnAction(e -> {
            // Login login = new Login();
            // login.start(primaryStage);
            // call App page
            // close current window
            primaryStage.close();
        });

        // Set event handler for the register button
        registerButton.setOnAction(e -> {
            // check if no complaint is selected
            String cnic = cnicField.getText();
            String password = passwordField.getText();
            String confirmPassword = confirmPasswordField.getText();
            String address = addressTextArea.getText();
            String phoneNumber = phoneNumberField.getText();
            int age = ageSpinner.getValue();
            // check if cnic field is empty
            boolean check = cnicField.getText().isEmpty();
            if (check || password.isEmpty() || confirmPassword.isEmpty()) {
                registrationStatus.setText("Please fill all the fields!");
                registrationStatus.setFill(Color.RED);
            } // make for empty text fields

            else {
                Account account = new Account();
                int error_type = account.RegisterAccount(cnic, password, confirmPassword, age, address, phoneNumber);
                // Perform account registration logic here
                if (error_type == 1) {
                    registrationStatus.setText("INVALID CNIC!");
                    registrationStatus.setFill(Color.RED);
                } else if (error_type == 2) {
                    registrationStatus.setText("Password length must be greater than 8!");
                    registrationStatus.setFill(Color.RED);
                } else if (error_type == 3) {
                    registrationStatus.setText("Passwords do not match!");
                    registrationStatus.setFill(Color.RED);
                } else if (error_type == 4) {
                    registrationStatus.setText("Age must be greater than 18!");
                    registrationStatus.setFill(Color.RED);
                } else if (error_type == 5) {
                    registrationStatus.setText("Phone Number does not exist!");
                    registrationStatus.setFill(Color.RED);
                } else if (error_type == 0) {
                    registrationStatus.setText("Account registered successfully!");
                    registrationStatus.setFill(Color.GREEN);
                }
                // put cnic and password in Accounts.txt
            }
        });

        // Create the scene and add it to the stage
        Scene scene = new Scene(gridPane, 800, 600);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void Delete(int toOpen) {

        Stage primaryStage = new Stage();
        AnchorPane root = new AnchorPane();

        Rectangle rect2 = new Rectangle(179, 125, 742, 111);
        rect2.setFill(javafx.scene.paint.Color.WHITE);
        rect2.setStroke(javafx.scene.paint.Color.BLACK);

        Rectangle rect9 = new Rectangle(105, 719);
        rect9.setFill(Color.web("#5673a6"));
        rect9.setStroke(Color.web("#5673a8"));
        rect9.setStrokeType(StrokeType.INSIDE);
        rect9.setArcHeight(5);
        rect9.setLayoutY(-3);
        rect9.setWidth(105);

        Rectangle rect3 = new Rectangle(170, 30, 1036, 64);
        rect3.setFill(javafx.scene.paint.Color.web("#5672a9"));
        rect3.setStroke(javafx.scene.paint.Color.WHITE);

        Text text1 = new Text(207, 151, "Name : ");
        text1.setFont(Font.font(20));
        text1.setStyle("-fx-font-weight: bold;");

        Text text2 = new Text(207, 187, "CNIC :");
        text2.setFont(Font.font(20));
        text2.setStyle("-fx-font-weight: bold;");

        Text text3 = new Text(206, 557, "Expedite Action:");
        text3.setFont(Font.font(20));
        text3.setStyle("-fx-font-weight: bold;");

        Text text4 = new Text(590, 71, "Deleting Account");
        text4.setFont(Font.font(26));
        text4.setStyle("-fx-font-weight: bold;");
        text4.setWrappingWidth(213.4327392578125);

        Admin admin = new Admin();
        String details = admin.viewComplaint(toOpen);
        String[] detailsArray = details.split(",");
        Text text5 = new Text(427, 150, detailsArray[1]);
        text5.setFont(Font.font(18));

        // make a radio button for banning reason
        RadioButton rb1 = new RadioButton("Spamming");
        ToggleGroup group = new ToggleGroup(); // Create a new ToggleGroup
        rb1.setToggleGroup(group);
        rb1.setUserData("Spamming");
        rb1.setLayoutX(427);
        rb1.setLayoutY(213);
        rb1.setFont(Font.font(15));

        RadioButton rb2 = new RadioButton("Abusive Language");
        rb2.setToggleGroup(group);
        rb2.setUserData("Abusive Language");
        rb2.setLayoutX(427);
        rb2.setLayoutY(253);
        rb2.setFont(Font.font(15));

        RadioButton rb3 = new RadioButton("Inappropriate Content");
        rb3.setToggleGroup(group);
        rb3.setUserData("Inappropriate Content");
        rb3.setLayoutX(427);
        rb3.setLayoutY(293);
        rb3.setFont(Font.font(15));

        RadioButton rb4 = new RadioButton("Other");
        rb4.setToggleGroup(group);
        rb4.setUserData("Other");
        rb4.setLayoutX(427);
        rb4.setLayoutY(333);
        rb4.setFont(Font.font(15));

        Text text7 = new Text(425, 187, detailsArray[3]);
        text7.setFont(Font.font(18));

        TextArea text9 = new TextArea();
        text9.setLayoutX(427);
        text9.setLayoutY(435);
        text9.setPrefHeight(100);
        text9.setPrefWidth(300);
        text9.setStyle("-fx-border-color: black;");
        text9.setFont(Font.font(15));
        text9.setWrapText(true); // Enable text wrapping

        Text text11 = new Text(426, 557, "No");
        text11.setFont(Font.font(18));

        Button button1 = new Button("Back");
        button1.setLayoutX(188);
        button1.setLayoutY(621);
        button1.setPrefHeight(1);
        button1.setPrefWidth(93);
        button1.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        button1.setFont(Font.font(15));

        // add a button for importing photo
        Button button3 = new Button("Import Photo +");
        button3.setLayoutX(427);
        button3.setLayoutY(387);
        button3.setPrefHeight(1);
        button3.setPrefWidth(150);
        button3.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        button3.setFont(Font.font(15));

        Text text12 = new Text(207, 223, "Reason :");
        text12.setFont(Font.font(20));
        text12.setStyle("-fx-font-weight: bold;");

        Text text13 = new Text(207, 413, "Add Evidence :");
        text13.setFont(Font.font(20));
        text13.setStyle("-fx-font-weight: bold;");

        Text text14 = new Text(207, 455, "Description : ");
        text14.setFont(Font.font(20));
        text14.setStyle("-fx-font-weight: bold;");

        ImageView imageView1 = new ImageView(new Image("dashboard.png"));
        imageView1.setFitHeight(52);
        imageView1.setFitWidth(56);
        imageView1.setLayoutX(26);
        imageView1.setLayoutY(64);
        imageView1.setPreserveRatio(true);
        imageView1.setPickOnBounds(true);

        ImageView imageView2 = new ImageView(new Image("browse.png"));
        imageView2.setFitHeight(59);
        imageView2.setFitWidth(60);
        imageView2.setLayoutX(23);
        imageView2.setLayoutY(135);
        imageView2.setPreserveRatio(true);
        imageView2.setPickOnBounds(true);

        ImageView imageView3 = new ImageView(new Image("feedback.png"));
        imageView3.setFitHeight(52);
        imageView3.setFitWidth(56);
        imageView3.setLayoutX(27);
        imageView3.setLayoutY(207);
        imageView3.setPreserveRatio(true);
        imageView3.setPickOnBounds(true);

        ImageView imageView4 = new ImageView(new Image("Free_Sample_By_Wix.jpg"));
        imageView4.setFitHeight(110);
        imageView4.setFitWidth(115);
        imageView4.setLayoutX(-4);
        imageView4.setLayoutY(606);
        imageView4.setPreserveRatio(true);
        imageView4.setPickOnBounds(true);

        ImageView imageView5 = new ImageView(new Image("deleting.png"));
        // add above ban account
        imageView5.setFitHeight(290);
        imageView5.setFitWidth(290);
        imageView5.setLayoutX(950);
        imageView5.setLayoutY(205);
        imageView5.setPreserveRatio(true);
        imageView5.setPickOnBounds(true);

        Button button2 = new Button("Ban Account");
        // below comaplaintType
        button2.setLayoutX(1016);
        button2.setLayoutY(621);
        button2.setPrefHeight(1);
        button2.setPrefWidth(140);
        button2.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        button2.setFont(Font.font(15));

        root.getChildren().addAll(rect3, rect9, text1, text2, text3, text4, text5,
                text7,
                text9, text11, button1, text12, text13, text14,
                imageView1, imageView2, imageView3, imageView4, button2, imageView5, rb1,
                rb2, rb3, rb4, button3);

        // Scene scene = new Scene(root, 1248, 715);
        button1.setOnAction(e -> {
            primaryStage.close();
            AllComplaints();
        });

        button3.setOnAction(e -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Import Photo +");
            fileChooser.getExtensionFilters().addAll(new ExtensionFilter("Image Files", "*.png", "*.jpg", "*.gif"));
            File selectedFile = fileChooser.showOpenDialog(primaryStage);
            if (selectedFile != null) {
                Image image = new Image(selectedFile.toURI().toString());
                imageView5.setImage(image);
                String path = selectedFile.getAbsolutePath();
                Text text = new Text(path);
                text.setLayoutX(850);
                text.setLayoutY(245);
                text.setFont(new Font(16));
                root.getChildren().add(text);

            }
        });

        button2.setOnAction(e -> {
            // display which reason is selected
            String reason = "";
            if (rb1.isSelected()) {
                reason = rb1.getText();
            } else if (rb2.isSelected()) {
                reason = rb2.getText();
            } else if (rb3.isSelected()) {
                reason = rb3.getText();
            } else if (rb4.isSelected()) {
                reason = rb4.getText();
            }
            // display which description is selected
            String description = text9.getText();

            Stage popupwindow = new Stage();
            popupwindow.initModality(Modality.APPLICATION_MODAL);
            popupwindow.setTitle("Account Banned");
            Label label1 = new Label("Account Banned");
            label1.setFont(Font.font(20));
            label1.setStyle("-fx-font-weight: bold;");
            Button button4 = new Button("Close");
            button4.setOnAction(e1 -> popupwindow.close());
            VBox layout = new VBox(10);
            layout.getChildren().addAll(label1, button4);
            layout.setAlignment(Pos.CENTER);
            Scene scene1 = new Scene(layout, 300, 250);
            popupwindow.setScene(scene1);
            popupwindow.showAndWait();
            admin.DeleteAccount(reason, description, toOpen);

        });

        imageView1.setOnMouseClicked(e -> {
            System.out.println("Dashboard");
        });

        imageView2.setOnMouseClicked(e -> {
            System.out.println("Browse");
        });

        imageView3.setOnMouseClicked(e -> {
            System.out.println("Feedback");
        });

        Scene scene = new Scene(root, 1248, 715);
        primaryStage.setTitle("JavaFX App");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void ConvertToPdf(int toOpen) {
        AnchorPane root = new AnchorPane();
        Stage primaryStage = new Stage();

        Rectangle rect3 = new Rectangle(20, 50, 545, 40);
        rect3.setFill(javafx.scene.paint.Color.web("#5672a9"));
        rect3.setStroke(javafx.scene.paint.Color.WHITE);

        Rectangle rect1 = new Rectangle(20, 254, 545, 298);
        rect1.setFill(javafx.scene.paint.Color.WHITE);
        rect1.setStroke(javafx.scene.paint.Color.BLACK);

        Rectangle rect2 = new Rectangle(20, 125, 545, 111);
        rect2.setFill(javafx.scene.paint.Color.WHITE);
        rect2.setStroke(javafx.scene.paint.Color.BLACK);

        Text text1 = new Text(30, 151, "Name : ");
        text1.setFont(Font.font(20));
        text1.setStyle("-fx-font-weight: bold;");

        Text text2 = new Text(30, 187, "Address :");
        text2.setFont(Font.font(20));
        text2.setStyle("-fx-font-weight: bold;");

        Text text3 = new Text(30, 517, "Expedite Action:");
        text3.setFont(Font.font(20));
        text3.setStyle("-fx-font-weight: bold;");

        Admin admin = new Admin();
        String complaint = admin.viewComplaint(toOpen);
        String[] complaintArray = complaint.split(",");

        Text text19 = new Text(30, 284, "ID : ");
        text19.setFont(Font.font(20));
        text19.setStyle("-fx-font-weight: bold;");

        Text id = new Text(150, 284, complaintArray[0]);
        id.setFont(Font.font(18));

        Text text4 = new Text(200, 75, "Complaint-" + complaintArray[0]);
        text4.setFont(Font.font(20));
        text4.setStyle("-fx-font-weight: bold;");
        text4.setWrappingWidth(213.4327392578125);

        Text text5 = new Text(150, 150, complaintArray[1]);
        text5.setFont(Font.font(18));

        Text text6 = new Text(150, 186, complaintArray[2]);
        text6.setFont(Font.font(18));

        Text text7 = new Text(150, 223, complaintArray[3]);
        text7.setFont(Font.font(18));

        Text text8 = new Text(150, 316, complaintArray[4]);
        text8.setFont(Font.font(18));

        Text text9 = new Text(150, 384, complaintArray[5]);
        text9.setFont(Font.font(18));
        text9.setWrappingWidth(482.060302734375);

        Text text10 = new Text(150, 351, complaintArray[6]);
        text10.setFont(Font.font(18));

        Text text11 = new Text(200, 517, complaintArray[7]);
        text11.setFont(Font.font(18));

        Text text12 = new Text(30, 223, "CNIC :");
        text12.setFont(Font.font(20));
        text12.setStyle("-fx-font-weight: bold;");

        Text text13 = new Text(30, 316, "Type :");
        text13.setFont(Font.font(20));
        text13.setStyle("-fx-font-weight: bold;");

        Text text14 = new Text(30, 384, "Description : ");
        text14.setFont(Font.font(20));
        text14.setStyle("-fx-font-weight: bold;");

        Text text15 = new Text(30, 352, "Date :");
        text15.setFont(Font.font(20));
        text15.setStyle("-fx-font-weight: bold;");

        root.getChildren().addAll(rect3, rect1, rect2, text1, text2, text3, text4,
                text5, text6, text7, text8,
                text9, text10, text11, text12, text13, text14, text15,
                text19, id);
        Scene scene = new Scene(root, 595, 842);
        primaryStage.setTitle("JavaFX App");
        primaryStage.setScene(scene);
        // primaryStage.show();

        Printer printer = Printer.getDefaultPrinter();
        PageLayout pageLayout = printer.createPageLayout(Paper.A4, PageOrientation.PORTRAIT,
                Printer.MarginType.EQUAL);
        PrinterJob job = PrinterJob.createPrinterJob();
        job.getJobSettings().setPageLayout(pageLayout);
        job.showPrintDialog(null);
        job.printPage(root);
        job.endJob();
    }

    private void ForwardComplaint(int toOpen) {
        AnchorPane root = new AnchorPane();
        Stage primaryStage = new Stage();
        Rectangle rect1 = new Rectangle(179, 254, 742, 298);
        rect1.setFill(javafx.scene.paint.Color.WHITE);
        rect1.setStroke(javafx.scene.paint.Color.BLACK);

        Rectangle rect2 = new Rectangle(179, 125, 742, 111);
        rect2.setFill(javafx.scene.paint.Color.WHITE);
        rect2.setStroke(javafx.scene.paint.Color.BLACK);

        Rectangle rect9 = new Rectangle(105, 719);
        rect9.setFill(Color.web("#5673a6"));
        rect9.setStroke(Color.web("#5673a8"));
        rect9.setStrokeType(StrokeType.INSIDE);
        rect9.setArcHeight(5);
        rect9.setLayoutY(-3);
        rect9.setWidth(105);

        Rectangle rect3 = new Rectangle(170, 30, 1036, 64);
        rect3.setFill(javafx.scene.paint.Color.web("#5672a9"));
        rect3.setStroke(javafx.scene.paint.Color.WHITE);

        Text text1 = new Text(207, 151, "Name : ");
        text1.setFont(Font.font(20));
        text1.setStyle("-fx-font-weight: bold;");

        Text text2 = new Text(207, 187, "Address :");
        text2.setFont(Font.font(20));
        text2.setStyle("-fx-font-weight: bold;");

        Text text3 = new Text(206, 517, "Expedite Action:");
        text3.setFont(Font.font(20));
        text3.setStyle("-fx-font-weight: bold;");

        Text text4 = new Text(590, 71, "View Complaint ");
        text4.setFont(Font.font(26));
        text4.setStyle("-fx-font-weight: bold;");
        text4.setWrappingWidth(213.4327392578125);

        Admin admin = new Admin();
        String complaint = admin.viewComplaint(toOpen);
        String[] complaintArray = complaint.split(",");

        // make text id before complaintType
        Text text19 = new Text(207, 284, "ID : ");
        text19.setFont(Font.font(20));
        text19.setStyle("-fx-font-weight: bold;");

        Text id = new Text(425, 284, complaintArray[0]);
        id.setFont(Font.font(18));

        Text text5 = new Text(427, 150, complaintArray[1]);
        text5.setFont(Font.font(18));

        Text text6 = new Text(425, 186, complaintArray[2]);
        text6.setFont(Font.font(18));

        Text text7 = new Text(425, 223, complaintArray[3]);
        text7.setFont(Font.font(18));

        Text text8 = new Text(427, 316, complaintArray[4]);
        text8.setFont(Font.font(18));

        Text text9 = new Text(425, 392, complaintArray[5]);
        text9.setFont(Font.font(18));
        text9.setWrappingWidth(482.060302734375);

        Text text10 = new Text(429, 351, complaintArray[6]);
        text10.setFont(Font.font(18));

        Text text11 = new Text(426, 517, complaintArray[7]);
        text11.setFont(Font.font(18));

        Button button1 = new Button("Back");
        button1.setLayoutX(188);
        button1.setLayoutY(621);
        button1.setPrefHeight(1);
        button1.setPrefWidth(93);
        button1.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        button1.setFont(Font.font(15));

        Button button4 = new Button("Report Account");
        button4.setLayoutX(950);
        button4.setLayoutY(621);
        button4.setPrefHeight(1);
        button4.setPrefWidth(130);
        button4.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        button4.setFont(Font.font(15));

        Text text12 = new Text(207, 223, "CNIC :");
        text12.setFont(Font.font(20));
        text12.setStyle("-fx-font-weight: bold;");

        Text text13 = new Text(207, 316, "Complaint Type :");
        text13.setFont(Font.font(20));
        text13.setStyle("-fx-font-weight: bold;");

        Text text14 = new Text(207, 384, "Description : ");
        text14.setFont(Font.font(20));
        text14.setStyle("-fx-font-weight: bold;");

        Text text15 = new Text(207, 352, "Date :");
        text15.setFont(Font.font(20));
        text15.setStyle("-fx-font-weight: bold;");

        Rectangle rect4 = new Rectangle(975, 484, 239, 133);
        rect4.setFill(javafx.scene.paint.Color.WHITE);
        rect4.setStroke(javafx.scene.paint.Color.BLACK);

        ComboBox<String> complaintType = new ComboBox<>();
        // increase text size
        complaintType.getItems().addAll("Water", "Electricity", "Gas", "Roads",
                "Sewerage", "Sanitation", "Other");
        complaintType.setLayoutX(1010);
        complaintType.setLayoutY(570);
        complaintType.setPrefHeight(25);
        complaintType.setPrefWidth(200);
        complaintType.setStyle("-fx-background-color: WHITE; -fx-text-fill: BLACK;");
        complaintType.setPromptText("Send to Department");
        complaintType.setStyle("-fx-font-size: 15px;");

        ImageView imageView1 = new ImageView(new Image("dashboard.png"));
        imageView1.setFitHeight(52);
        imageView1.setFitWidth(56);
        imageView1.setLayoutX(26);
        imageView1.setLayoutY(64);
        imageView1.setPreserveRatio(true);
        imageView1.setPickOnBounds(true);

        ImageView imageView2 = new ImageView(new Image("browse.png"));
        imageView2.setFitHeight(59);
        imageView2.setFitWidth(60);
        imageView2.setLayoutX(23);
        imageView2.setLayoutY(135);
        imageView2.setPreserveRatio(true);
        imageView2.setPickOnBounds(true);

        ImageView imageView3 = new ImageView(new Image("feedback.png"));
        imageView3.setFitHeight(52);
        imageView3.setFitWidth(56);
        imageView3.setLayoutX(27);
        imageView3.setLayoutY(207);
        imageView3.setPreserveRatio(true);
        imageView3.setPickOnBounds(true);

        ImageView imageView4 = new ImageView(new Image("Free_Sample_By_Wix.jpg"));
        imageView4.setFitHeight(110);
        imageView4.setFitWidth(115);
        imageView4.setLayoutX(-4);
        imageView4.setLayoutY(606);
        imageView4.setPreserveRatio(true);
        imageView4.setPickOnBounds(true);

        ImageView imageView5 = new ImageView(new Image("pdf.png"));
        imageView5.setFitHeight(52);
        imageView5.setFitWidth(56);
        imageView5.setLayoutX(1110);
        imageView5.setLayoutY(460);
        imageView5.setPreserveRatio(true);
        imageView5.setPickOnBounds(true);

        Button PDF = new Button();
        PDF.setGraphic(imageView5);
        PDF.setLayoutX(1100);
        PDF.setLayoutY(450);
        PDF.setPrefHeight(70);
        PDF.setPrefWidth(70);
        PDF.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        PDF.setFont(Font.font(15));

        Button button2 = new Button("Forward");
        // below comaplaintType
        button2.setLayoutX(1116);
        button2.setLayoutY(621);
        button2.setPrefHeight(1);
        button2.setPrefWidth(93);
        button2.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        button2.setFont(Font.font(15));

        root.getChildren().addAll(rect1, rect2, rect3, rect9, text1, text2, text3,
                text4, text5, text6, text7, text8,
                text9, text10, text11, button1, text12, text13, text14, text15,
                complaintType, imageView1, imageView2, imageView3, imageView4, button2, button4, PDF, imageView5,
                text19, id);

        // set pdf button action
        PDF.setOnAction(e -> {
            Report report = new ComplaintDocument();
            report.DisplayReport(toOpen);
        });

        button2.setOnAction(e -> {
            // Display forwarded message
            boolean correct;
            correct = admin.isCorrectForwardType(complaintType.getValue(), complaintArray[4]);
            if (correct == true) {
                admin.sendCompaintDetails();
                Alert alert = new Alert(AlertType.INFORMATION);
                alert.setTitle("Information Dialog");
                alert.setHeaderText(null);
                alert.setContentText("Complaint has been forwarded to the department");

                alert.showAndWait();
            } else {
                // show error to select correct message
                Alert alert = new Alert(AlertType.ERROR);
                alert.setTitle("Error Dialog");
                alert.setHeaderText("Look, an Error Dialog");
                alert.setContentText("Select the correct Department!");
                alert.showAndWait();
            }
        });

        imageView1.setOnMouseClicked(e -> {
            System.out.println("Dashboard");
        });

        imageView2.setOnMouseClicked(e -> {
            System.out.println("Browse");
        });

        imageView3.setOnMouseClicked(e -> {
            System.out.println("Feedback");
        });

        button1.setOnAction(e -> {
            primaryStage.close();
            AllComplaints();
        });

        button4.setOnAction(e -> {
            primaryStage.close();
            Delete(toOpen);
        });

        Scene scene = new Scene(root, 1248, 715);

        primaryStage.setTitle("JavaFX App");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void RegisterComplaint(String displaythiscnic) {
        AnchorPane root = new AnchorPane();
        Stage primaryStage = new Stage();
        TextField nameTextField = new TextField();
        nameTextField.setLayoutX(219);
        nameTextField.setLayoutY(152);
        nameTextField.setPrefWidth(360);
        nameTextField.setPrefHeight(44);
        nameTextField.setPromptText("Enter name");
        nameTextField.setStyle("-fx-background-color: transparent; -fx-border-color:black; -fx-border-width: 1px;");
        nameTextField.setFont(new Font(15));

        Rectangle rect2 = new Rectangle(1036, 64);
        rect2.setArcHeight(5);
        rect2.setArcWidth(5);
        rect2.setLayoutX(170);
        rect2.setLayoutY(30);
        rect2.setFill(Color.web("#5672a9"));
        rect2.setStroke(Color.WHITE);

        Text registerText = new Text("Register Complaint");
        registerText.setLayoutX(596);
        registerText.setLayoutY(72);
        registerText.setFont(new Font(26));
        registerText.setFill(Color.BLACK);
        registerText.setStyle("-fx-font-weight: bold;");
        registerText.setWrappingWidth(261.28);

        Button submitButton = new Button("Submit");
        submitButton.setLayoutX(1000);
        submitButton.setLayoutY(592);
        submitButton.setPrefWidth(152);
        submitButton.setPrefHeight(44);
        submitButton.setStyle("-fx-background-color: #5672A9;");
        submitButton.setTextFill(Color.WHITE);
        submitButton.setFont(new Font(15));

        Rectangle rect3 = new Rectangle(360, 44);
        rect3.setArcHeight(5);
        rect3.setArcWidth(5);
        rect3.setLayoutX(217);
        rect3.setLayoutY(222);
        rect3.setFill(Color.WHITE);
        rect3.setStroke(Color.BLACK);

        ImageView imageView = new ImageView(new Image("notes.png"));
        imageView.setFitWidth(196);
        imageView.setFitHeight(184);
        imageView.setLayoutX(984);
        imageView.setLayoutY(383);
        imageView.setPreserveRatio(true);
        imageView.setPickOnBounds(true);

        imageView.setEffect(new ColorAdjust());

        Accordion accordion = new Accordion();
        accordion.setLayoutX(0);
        accordion.setLayoutY(0);

        Rectangle rect4 = new Rectangle(105, 719);
        rect4.setFill(Color.web("#5673a6"));
        rect4.setStroke(Color.web("#5673a8"));
        rect4.setStrokeType(StrokeType.INSIDE);
        rect4.setArcHeight(5);
        rect4.setLayoutY(-3);
        rect4.setWidth(105);

        Button dashboardButton = new Button();
        dashboardButton.setLayoutY(60);
        dashboardButton.setPrefWidth(105);
        dashboardButton.setPrefHeight(59);
        dashboardButton.setBlendMode(BlendMode.SOFT_LIGHT);
        dashboardButton.setFont(new Font(14));

        Button browseButton = new Button();
        browseButton.setLayoutY(125);
        browseButton.setPrefWidth(105);
        browseButton.setPrefHeight(59);
        browseButton.setBlendMode(BlendMode.DARKEN);
        browseButton.setFont(new Font(14));

        Button feedbackButton = new Button();
        feedbackButton.setLayoutY(193);
        feedbackButton.setPrefWidth(105);
        feedbackButton.setPrefHeight(59);
        feedbackButton.setBlendMode(BlendMode.DARKEN);
        feedbackButton.setFont(new Font(14));

        ImageView dashboardImageView = new ImageView(new Image("dashboard.png"));
        dashboardImageView.setFitWidth(56);
        dashboardImageView.setFitHeight(52);
        dashboardImageView.setLayoutX(27);
        dashboardImageView.setLayoutY(64);
        dashboardImageView.setPreserveRatio(true);
        dashboardImageView.setPickOnBounds(true);

        ImageView browseImageView = new ImageView(new Image("browse.png"));
        browseImageView.setFitWidth(60);
        browseImageView.setFitHeight(59);
        browseImageView.setLayoutX(23);
        browseImageView.setLayoutY(131);
        browseImageView.setPreserveRatio(true);
        browseImageView.setPickOnBounds(true);

        ImageView feedbackImageView = new ImageView(new Image("feedback.png"));
        feedbackImageView.setFitWidth(56);
        feedbackImageView.setFitHeight(52);
        feedbackImageView.setLayoutX(27);
        feedbackImageView.setLayoutY(197);
        feedbackImageView.setPreserveRatio(true);
        feedbackImageView.setPickOnBounds(true);
        // enclose cnic in a rectangle
        Rectangle rect5 = new Rectangle(360, 44);
        rect5.setArcHeight(5);
        rect5.setArcWidth(5);
        rect5.setLayoutX(217);
        rect5.setLayoutY(222);
        rect5.setFill(Color.TRANSPARENT);
        rect5.setStroke(Color.BLACK);

        Text cnicText = new Text(displaythiscnic);
        cnicText.setLayoutX(228);
        cnicText.setLayoutY(250);
        // cnicText.setStyle("-fx-background-color: transparent; -fx-border-color:black;
        // -fx-border-width: 1px;");
        cnicText.setFont(new Font(15));

        // add drop down menu for selecting complaint type
        ComboBox<String> complaintType = new ComboBox<>();
        complaintType.getItems().addAll("Water", "Electricity", "Gas", "Roads", "Sewerage", "Sanitation", "Other");
        complaintType.setLayoutX(219);
        complaintType.setLayoutY(290);
        complaintType.setPrefWidth(360);
        complaintType.setPrefHeight(44);
        complaintType.setPromptText("Select Complaint Type");
        complaintType.setStyle("-fx-background-color: transparent; -fx-border-color:black; -fx-border-width: 1px;");
        // complaintType.setId(new Font(15));

        // textfield for complaint description
        TextArea complaintDescription = new TextArea();
        complaintDescription.setLayoutX(219);
        complaintDescription.setLayoutY(360);
        complaintDescription.setPrefWidth(360);
        complaintDescription.setPrefHeight(152);
        complaintDescription.setPromptText("Enter Complaint Description");
        complaintDescription
                .setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");
        complaintDescription.setFont(new Font(15));

        // enter address textfield
        TextField addressText = new TextField();
        addressText.setLayoutX(686);
        addressText.setLayoutY(154);
        addressText.setPrefWidth(360);
        addressText.setPrefHeight(44);
        addressText.setPromptText("Enter Address");
        addressText.setStyle("-fx-background-color: transparent; -fx-border-color:black; -fx-border-width: 1px;");
        addressText.setFont(new Font(15));

        Button ImportPhoto = new Button("Import Photo +");
        ImportPhoto.setLayoutX(686);
        ImportPhoto.setLayoutY(225);
        ImportPhoto.setPrefWidth(140);
        ImportPhoto.setPrefHeight(30);
        ImportPhoto.setStyle("-fx-background-color: #95a2ff;");
        ImportPhoto.setFont(new Font(15));

        Text expediteText = new Text("Do you want Expedite actions?");
        expediteText.setLayoutX(685);
        expediteText.setLayoutY(315);
        expediteText.setFont(new Font(20));
        expediteText.setFill(Color.web("#14227b"));
        expediteText.setStyle("-fx-font-weight: bold;");
        expediteText.setUnderline(true);

        RadioButton yesRadioButton = new RadioButton("Yes");
        yesRadioButton.setLayoutX(690);
        yesRadioButton.setLayoutY(338);
        yesRadioButton.setPrefWidth(66);
        yesRadioButton.setPrefHeight(26);
        yesRadioButton.setFont(new Font(14));
        yesRadioButton.setMnemonicParsing(false);

        RadioButton noRadioButton = new RadioButton("No");
        noRadioButton.setLayoutX(842);
        noRadioButton.setLayoutY(342);
        noRadioButton.setFont(new Font(14));
        noRadioButton.setMnemonicParsing(false);

        ImageView logoImageView = new ImageView(new Image("Free_Sample_By_Wix.jpg"));
        logoImageView.setFitWidth(110);
        logoImageView.setFitHeight(114);
        logoImageView.setLayoutX(-4);
        logoImageView.setLayoutY(605);
        logoImageView.setPreserveRatio(true);
        logoImageView.setPickOnBounds(true);

        ToggleGroup group = new ToggleGroup();
        yesRadioButton.setToggleGroup(group);
        noRadioButton.setToggleGroup(group);

        root.getChildren().addAll(cnicText, rect5, nameTextField, rect2, registerText, submitButton,
                imageView, accordion,
                rect4, dashboardButton, browseButton, feedbackButton, dashboardImageView,
                browseImageView,
                feedbackImageView, addressText, expediteText,
                yesRadioButton, noRadioButton, logoImageView, complaintType,
                complaintDescription, ImportPhoto);

        ImportPhoto.setOnAction(e -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Import Photo +");
            fileChooser.getExtensionFilters().addAll(new ExtensionFilter("Image Files", "*.png", "*.jpg", "*.gif"));
            File selectedFile = fileChooser.showOpenDialog(primaryStage);
            if (selectedFile != null) {
                Image image = new Image(selectedFile.toURI().toString());
                imageView.setImage(image);
                String path = selectedFile.getAbsolutePath();
                Text text = new Text(path);
                text.setLayoutX(850);
                text.setLayoutY(245);
                text.setFont(new Font(16));
                root.getChildren().add(text);

            }
        });

        submitButton.setOnAction(e -> {
            Complainant complainant = new Complainant();
            String name = nameTextField.getText();
            String cnic = cnicText.getText();
            String address = addressText.getText();
            String complaint = complaintType.getValue();
            String description = complaintDescription.getText();
            String expedite;
            boolean status;
            if (yesRadioButton.isSelected()) {
                expedite = "Yes";
                status = complainant.isExpedite("Yes");
            } else {
                expedite = "No";
                status = complainant.isExpedite("No");
            }

            if (name.isEmpty() || cnic.isEmpty() || address.isEmpty() || complaint.isEmpty() || description.isEmpty()
                    || expedite.isEmpty()) {
                Alert alert = new Alert(AlertType.ERROR);
                alert.setTitle("Error");
                alert.setHeaderText("Error");
                alert.setContentText("Please fill all the fields");
                alert.showAndWait();
            }
            if (status) {
                isExpedite(name, address, cnic, complaint, description, expedite);
            }
            if (!status) {
                Alert alert = new Alert(AlertType.INFORMATION);
                alert.setTitle("Success");
                alert.setHeaderText("Success");
                alert.setContentText("Your complaint has been registered");
                alert.showAndWait();
                try (FileWriter writer = new FileWriter("Complaints.txt", true)) {
                    // generate 6 digit random number
                    int random = (int) (Math.random() * 900000) + 100000;
                    // todays date and store in string
                    String date = new SimpleDateFormat("dd-MM-yyyy").format(new Date());

                    writer.write(
                            random + "," + name + "," + address + "," + cnic + "," + complaint + "," + description + ","
                                    + date + "," + expedite + "\n");
                } catch (IOException eX) {
                    System.err.println("Error writing to file: " + eX.getMessage());
                }

            }
        });

        feedbackImageView.setOnMouseClicked(e -> {
            // load fxml
            try {
                // Create a new root for the new scene.
                Parent feedbackRoot = FXMLLoader.load(getClass().getResource("SubmitFeedback.fxml"));
                Scene scene1 = new Scene(feedbackRoot, 1248, 715);
                primaryStage.setScene(scene1);
                primaryStage.show();
            } catch (IOException ex) {
                System.err.println("Failed to create new window.");
            }
        });

        browseImageView.setOnMouseClicked(e -> {
            System.out.println("Browse");
        });

        dashboardImageView.setOnMouseClicked(e -> {
            System.out.println("Dashboard");
            // RegisterComplaint(displaythiscnic);
        });

        Scene scene = new Scene(root, 1248, 715);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private Parent loadFXML(String string) {
        return null;
    }

    public void isExpedite(String name, String address, String cnic, String complaint, String description,
            String expedite) {
        AnchorPane root = new AnchorPane();

        Text text1 = new Text("Card Number:");
        text1.setLayoutX(271);
        text1.setLayoutY(194);
        text1.setStyle("-fx-font-weight: bold;");
        text1.setFont(new Font(20));

        Text text2 = new Text("Payment");
        text2.setLayoutX(632);
        text2.setLayoutY(72);
        text2.setStyle("-fx-font-weight: bold;");
        text2.setFont(new Font(26));

        Text text3 = new Text();
        text3.setLayoutX(427);
        text3.setLayoutY(150);
        text3.setFont(new Font(18));

        Button submiButton = new Button("Submit");
        submiButton.setLayoutX(570);
        submiButton.setLayoutY(437);
        submiButton.setPrefSize(253, 32);
        submiButton.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        submiButton.setFont(new Font(15));

        Text PaymentStatus = new Text();
        PaymentStatus.setLayoutX(570);
        PaymentStatus.setLayoutY(500);
        PaymentStatus.setStyle("-fx-font-weight: bold;");
        PaymentStatus.setFont(new Font(20));

        Text text4 = new Text("Date of Expiry:");
        text4.setLayoutX(261);
        text4.setLayoutY(297);
        text4.setStyle("-fx-font-weight: bold;");
        text4.setFont(new Font(20));

        Text text5 = new Text("CVC:");
        text5.setLayoutX(356);
        text5.setLayoutY(245);
        text5.setStyle("-fx-font-weight: bold;");
        text5.setFont(new Font(20));

        TextField cardDescription = new TextField();
        cardDescription.setLayoutX(424);
        cardDescription.setLayoutY(168);
        cardDescription.setPrefWidth(652);
        cardDescription.setPrefHeight(38);
        cardDescription.setPromptText("without spaces or dashes");
        cardDescription
                .setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");
        cardDescription.setFont(new Font(15));

        Rectangle rectangle2 = new Rectangle(1036, 64);
        rectangle2.setLayoutX(170);
        rectangle2.setLayoutY(30);
        rectangle2.setFill(javafx.scene.paint.Color.valueOf("#5672a9"));
        rectangle2.setStroke(javafx.scene.paint.Color.WHITE);

        TextField Payment = new TextField();
        Payment.setLayoutX(424);
        Payment.setLayoutY(219);
        Payment.setPrefWidth(652);
        Payment.setPrefHeight(38);
        Payment.setPromptText("Enter Last 3 Digits");
        Payment
                .setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");
        cardDescription.setFont(new Font(15));

        TextField ExpirtDate = new TextField();
        ExpirtDate.setLayoutX(424);
        ExpirtDate.setLayoutY(275);
        ExpirtDate.setPrefWidth(652);
        ExpirtDate.setPrefHeight(38);
        ExpirtDate.setPromptText("mm/yy");
        ExpirtDate
                .setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");
        cardDescription.setFont(new Font(15));

        TextField addressField = new TextField();
        addressField.setLayoutX(424);
        addressField.setLayoutY(339);
        addressField.setPrefWidth(263);
        addressField.setPrefHeight(38);
        // addressField.setPromptText("mm/yy");
        addressField
                .setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");
        cardDescription.setFont(new Font(15));

        TextField zipField = new TextField();
        zipField.setLayoutX(832);
        zipField.setLayoutY(339);
        zipField.setPrefWidth(244);
        zipField.setPrefHeight(38);
        // addressField.setPromptText("mm/yy");
        zipField
                .setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");
        cardDescription.setFont(new Font(15));

        Rectangle rectangle7 = new Rectangle(105, 722);
        rectangle7.setLayoutY(-3);
        rectangle7.setFill(javafx.scene.paint.Color.valueOf("#5673a6"));
        rectangle7.setStroke(javafx.scene.paint.Color.valueOf("#5673a8"));
        rectangle7.setStrokeLineCap(StrokeLineCap.ROUND);
        rectangle7.setStrokeType(StrokeType.INSIDE);

        Text text6 = new Text("Email:");
        text6.setLayoutX(326);
        text6.setLayoutY(365);
        text6.setStyle("-fx-font-weight: bold;");
        text6.setFont(new Font(20));

        Text text7 = new Text("Zip Code:");
        text7.setLayoutX(728);
        text7.setLayoutY(365);
        text7.setStyle("-fx-font-weight: bold;");
        text7.setFont(new Font(20));

        ImageView imageView = new ImageView();
        imageView.setLayoutX(897);
        imageView.setLayoutY(437);
        imageView.setFitWidth(292);
        imageView.setFitHeight(244);
        imageView.setPreserveRatio(true);
        imageView.setPickOnBounds(true);
        imageView.setImage(new Image("Expedite.png"));
        imageView.setEffect(new ColorAdjust());

        Accordion accordion = new Accordion();
        accordion.setLayoutX(0);
        accordion.setLayoutY(0);

        Button buttonback = new Button("Back");
        buttonback.setLayoutX(188);
        buttonback.setLayoutY(621);
        buttonback.setPrefHeight(1);
        buttonback.setPrefWidth(93);
        buttonback.setStyle("-fx-background-color: #5672A9; -fx-text-fill: WHITE;");
        buttonback.setFont(Font.font(15));

        root.getChildren().addAll(rectangle2, text1, text2, text3, submiButton, text4, text5,
                text6, text7, imageView, accordion, rectangle7,
                cardDescription, Payment,
                ExpirtDate, zipField, addressField, buttonback, PaymentStatus);

        Scene scene = new Scene(root, 1248, 715);
        Stage primaryStage = new Stage();
        primaryStage.setScene(scene);
        primaryStage.setTitle("Payment Form");
        primaryStage.show();

        buttonback.setOnAction(e -> {
            primaryStage.close();
            // RegisterComplaint(cnic);
        });

        submiButton.setOnAction(e -> {
            String Cardno = cardDescription.getText();
            double cardno_int = Double.parseDouble(Cardno);
            String cvc = Payment.getText();
            int cvc_int = Integer.parseInt(Payment.getText());
            String expirydate = ExpirtDate.getText();
            String Email = addressField.getText();
            String Zipfield = zipField.getText();
            int Zip_int = Integer.parseInt(Zipfield);

            if (cvc.isEmpty() || expirydate.isEmpty() || Email.isEmpty() || Zipfield.isEmpty()) {
                PaymentStatus.setText("Please fill all the fields!");
                PaymentStatus.setFill(Color.RED);
                root.getChildren().add(PaymentStatus);
            } else {
                Payment payment = new Payment(cardno_int, cvc_int, expirydate, Zip_int);
                int error_type = payment.isValidCredentials(cardno_int, cvc_int, expirydate, Zip_int);
                if (error_type == 1) {
                    PaymentStatus.setText("INVALID credit No!");
                    PaymentStatus.setFill(Color.RED);
                } else if (error_type == 2) {
                    PaymentStatus.setText("INVALID CVC");
                    PaymentStatus.setFill(Color.RED);

                } else if (error_type == 3) {
                    PaymentStatus.setText("INVALID Date Format");
                    PaymentStatus.setFill(Color.RED);

                } else if (error_type == 4) {
                    PaymentStatus.setText("INVALD Zip Code");
                    PaymentStatus.setFill(Color.RED);

                } else if (error_type == 0) {
                    PaymentStatus.setText("Sucess");
                    PaymentStatus.setFill(Color.GREEN);
                    Alert alert = new Alert(AlertType.INFORMATION);
                    alert.setTitle("Success");
                    alert.setHeaderText("Success");
                    alert.setContentText("Your complaint has been registered");
                    alert.showAndWait();
                    try (FileWriter writer = new FileWriter("Complaints.txt", true)) {
                        // generate 6 digit random number
                        int random = (int) (Math.random() * 900000) + 100000;
                        // todays date and store in string
                        String date = new SimpleDateFormat("dd-MM-yyyy").format(new Date());

                        writer.write(
                                random + "," + name + "," + address + "," + cnic + "," + complaint + "," + description
                                        + ","
                                        + date + "," + expedite + "\n");
                    } catch (IOException eX) {
                        System.err.println("Error writing to file: " + eX.getMessage());
                    }
                    primaryStage.close();
                }
            }
        });
    }

    public void BrowseComplaint(int lineno) {
        if (lineno == 0) {
            Alert alert = new Alert(AlertType.INFORMATION);
            alert.setTitle("No Complaints");
            alert.setHeaderText("No Complaints");
            alert.setContentText("No Complaint of this Cmoplaint ID exists!");
            alert.showAndWait();
            return;
        }
        Stage primaryStage = new Stage();
        AnchorPane root = new AnchorPane();
        // Button button2;

        Rectangle rect1 = new Rectangle(1058, 616);
        rect1.setArcHeight(5);
        rect1.setArcWidth(5);
        rect1.setFill(Color.rgb(255, 255, 255, 0.64));
        rect1.setLayoutX(144);
        rect1.setLayoutY(48);

        Rectangle rect2 = new Rectangle(987, 511);
        rect2.setArcHeight(5);
        rect2.setArcWidth(5);
        rect2.setFill(Color.rgb(255, 255, 255, 0.08));
        rect2.setLayoutX(180);
        rect2.setLayoutY(113);

        Rectangle rect3 = new Rectangle(815, 37);
        rect3.setArcHeight(5);
        rect3.setFill(Color.rgb(255, 255, 255, 0));
        rect3.setLayoutX(247);
        rect3.setLayoutY(219);

        Rectangle rect4 = new Rectangle(949, 43);
        rect4.setArcHeight(5);
        rect4.setArcWidth(5);
        rect4.setFill(Color.rgb(86, 115, 166));
        rect4.setStroke(Color.rgb(86, 115, 168));
        rect4.setLayoutX(202);
        rect4.setLayoutY(168);

        Text text1 = new Text("Complaint ID");
        text1.setFont(new Font(14));
        text1.setLayoutX(258);
        text1.setLayoutY(194);

        Text text2 = new Text("Name");
        text2.setFont(new Font(14));
        text2.setLayoutX(393);
        text2.setLayoutY(194);

        Text text3 = new Text("Address");
        text3.setFont(new Font(14));
        text3.setLayoutX(502);
        text3.setLayoutY(195);

        Text text4 = new Text("CNIC");
        text4.setFont(new Font(14));
        text4.setLayoutX(621);
        text4.setLayoutY(194);

        Text text5 = new Text("Date");
        text5.setFont(new Font(14));
        text5.setLayoutX(988);
        text5.setLayoutY(197);

        Text text6 = new Text("Complaint Type");
        text6.setFont(new Font(14));
        text6.setLayoutX(704);
        text6.setLayoutY(195);

        Text text37 = new Text("Description");
        text37.setFont(new Font(14));
        text37.setLayoutX(846);
        text37.setLayoutY(195);

        Text text43 = new Text("Complaint Browsed");
        text43.setFont(new Font(19));
        text43.setFill(Color.rgb(1, 71, 191));
        text43.setLayoutX(149);
        text43.setLayoutY(41);

        ImageView imageView1 = new ImageView(new Image("dashboard.png"));
        imageView1.setFitHeight(52);
        imageView1.setFitWidth(56);
        imageView1.setLayoutX(26);
        imageView1.setLayoutY(64);
        imageView1.setPreserveRatio(true);
        imageView1.setPickOnBounds(true);

        ImageView imageView2 = new ImageView(new Image("browse.png"));
        imageView2.setFitHeight(59);
        imageView2.setFitWidth(60);
        imageView2.setLayoutX(23);
        imageView2.setLayoutY(135);
        imageView2.setPreserveRatio(true);
        imageView2.setPickOnBounds(true);

        ImageView imageView3 = new ImageView(new Image("feedback.png"));
        imageView3.setFitHeight(52);
        imageView3.setFitWidth(56);
        imageView3.setLayoutX(27);
        imageView3.setLayoutY(207);
        imageView3.setPreserveRatio(true);
        imageView3.setPickOnBounds(true);

        ImageView imageView4 = new ImageView(new Image("Free_Sample_By_Wix.jpg"));
        imageView4.setFitHeight(110);
        imageView4.setFitWidth(115);
        imageView4.setLayoutX(-2);
        imageView4.setLayoutY(616);
        imageView4.setPreserveRatio(true);
        imageView4.setPickOnBounds(true);

        // Text text44 = new Text("Show");
        // text44.setFont(new Font(14));
        // text44.setLayoutX(259);
        // text44.setLayoutY(145);

        TextField search = new TextField();
        search.setLayoutX(500);
        search.setLayoutY(120);
        search.setPrefWidth(300);
        search.setPrefHeight(38);
        search.setPromptText("Enter ID");
        search.setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");

        Button applyButton = new Button("Apply");
        applyButton.setLayoutX(830);
        applyButton.setLayoutY(120);
        applyButton.setMnemonicParsing(false);
        applyButton.setFont(new Font(14));

        Rectangle rect9 = new Rectangle(105, 730);
        rect9.setFill(Color.web("#5673a6"));
        rect9.setStroke(Color.web("#5673a8"));
        rect9.setStrokeType(StrokeType.INSIDE);
        rect9.setArcHeight(5);
        rect9.setLayoutY(-3);
        rect9.setWidth(105);

        Scene scene = new Scene(root, 1280, 720);
        primaryStage.setTitle("Complaints UI");
        primaryStage.setScene(scene);
        primaryStage.show();

        root.getChildren().addAll(rect1, rect2, rect3, rect4, text1, text2, text3, text4,
                text5, text6, text37, text43,
                search,
                rect9, imageView1, imageView2, imageView3, imageView4, applyButton);

        Admin admin = new Admin();
        String complaint = admin.viewComplaint(lineno + 1);
        String[] parts = complaint.split(",");

        Text text7 = new Text(parts[0]);
        text7.setFont(new Font(14));
        text7.setLayoutX(262);
        text7.setLayoutY(242);

        Text text8 = new Text(parts[1]);
        text8.setFont(new Font(14));
        text8.setLayoutX(355);
        text8.setLayoutY(242);

        Text text9 = new Text(parts[2]);
        text9.setFont(new Font(14));
        text9.setLayoutX(485);
        text9.setLayoutY(243);

        Text text10 = new Text(parts[3]);
        text10.setFont(new Font(14));
        text10.setLayoutX(599);
        text10.setLayoutY(243);

        Text text11 = new Text(parts[4]);
        text11.setFont(new Font(14));
        text11.setLayoutX(724);
        text11.setLayoutY(244);

        String s = parts[5].substring(0, 10);
        s += "...";
        Text text38 = new Text(s);
        text38.setFont(new Font(14));
        text38.setLayoutX(831);
        text38.setLayoutY(242);

        Text text12 = new Text(parts[6]);
        text12.setFont(new Font(14));
        text12.setLayoutX(973);
        text12.setLayoutY(241);

        Button button2 = new Button("Open " + (lineno + 1));
        button2.setLayoutX(1091);
        button2.setLayoutY(220);
        button2.setMnemonicParsing(false);
        button2.setFont(new Font(14));

        // Button 1 should be created anew for each iteration as well
        Button button1 = new Button();
        button1.setLayoutX(208);
        button1.setLayoutY(222);
        button1.setPrefHeight(29);
        button1.setPrefWidth(29);
        button1.setFont(new Font(14));

        root.getChildren().addAll(
                text7, text8, text9, text10, text11, text12,
                button1, button2, text38);

        button2.setOnAction(e -> {
            String whichtoOpen = button2.getText();
            String[] parts1 = whichtoOpen.split(" ");
            int which = Integer.parseInt(parts1[1]);
            System.out.println(which);
            primaryStage.close();
            ForwardComplaint(which);

        });

        applyButton.setOnAction(e -> {
            String id1 = search.getText();
            Admin admin1 = new Admin();
            admin1.BrowseComplaints(id1);
        });
    }

    // private void verifyPayment() {
    // Random random = new Random();
    // int code = random.nextInt(900000) + 100000;
    // }

    private void AllComplaints() {
        Stage primaryStage = new Stage();
        AnchorPane root = new AnchorPane();
        // Button button2;

        Rectangle rect1 = new Rectangle(1058, 616);
        rect1.setArcHeight(5);
        rect1.setArcWidth(5);
        rect1.setFill(Color.rgb(255, 255, 255, 0.64));
        rect1.setLayoutX(144);
        rect1.setLayoutY(48);

        Rectangle rect2 = new Rectangle(987, 511);
        rect2.setArcHeight(5);
        rect2.setArcWidth(5);
        rect2.setFill(Color.rgb(255, 255, 255, 0.08));
        rect2.setLayoutX(180);
        rect2.setLayoutY(113);

        Rectangle rect3 = new Rectangle(815, 37);
        rect3.setArcHeight(5);
        rect3.setFill(Color.rgb(255, 255, 255, 0));
        rect3.setLayoutX(247);
        rect3.setLayoutY(219);

        Rectangle rect4 = new Rectangle(949, 43);
        rect4.setArcHeight(5);
        rect4.setArcWidth(5);
        rect4.setFill(Color.rgb(86, 115, 166));
        rect4.setStroke(Color.rgb(86, 115, 168));
        rect4.setLayoutX(202);
        rect4.setLayoutY(168);

        Text text1 = new Text("Complaint ID");
        text1.setFont(new Font(14));
        text1.setLayoutX(258);
        text1.setLayoutY(194);

        Text text2 = new Text("Name");
        text2.setFont(new Font(14));
        text2.setLayoutX(393);
        text2.setLayoutY(194);

        Text text3 = new Text("Address");
        text3.setFont(new Font(14));
        text3.setLayoutX(502);
        text3.setLayoutY(195);

        Text text4 = new Text("CNIC");
        text4.setFont(new Font(14));
        text4.setLayoutX(621);
        text4.setLayoutY(194);

        Text text5 = new Text("Date");
        text5.setFont(new Font(14));
        text5.setLayoutX(988);
        text5.setLayoutY(197);

        Text text6 = new Text("Complaint Type");
        text6.setFont(new Font(14));
        text6.setLayoutX(704);
        text6.setLayoutY(195);

        Text text37 = new Text("Description");
        text37.setFont(new Font(14));
        text37.setLayoutX(846);
        text37.setLayoutY(195);

        Text text43 = new Text("Welcome Admin!");
        text43.setFont(new Font(19));
        text43.setFill(Color.rgb(1, 71, 191));
        text43.setLayoutX(149);
        text43.setLayoutY(41);

        ImageView imageView1 = new ImageView(new Image("dashboard.png"));
        imageView1.setFitHeight(52);
        imageView1.setFitWidth(56);
        imageView1.setLayoutX(26);
        imageView1.setLayoutY(64);
        imageView1.setPreserveRatio(true);
        imageView1.setPickOnBounds(true);

        ImageView imageView2 = new ImageView(new Image("browse.png"));
        imageView2.setFitHeight(59);
        imageView2.setFitWidth(60);
        imageView2.setLayoutX(23);
        imageView2.setLayoutY(135);
        imageView2.setPreserveRatio(true);
        imageView2.setPickOnBounds(true);

        ImageView imageView3 = new ImageView(new Image("feedback.png"));
        imageView3.setFitHeight(52);
        imageView3.setFitWidth(56);
        imageView3.setLayoutX(27);
        imageView3.setLayoutY(207);
        imageView3.setPreserveRatio(true);
        imageView3.setPickOnBounds(true);

        ImageView imageView4 = new ImageView(new Image("Free_Sample_By_Wix.jpg"));
        imageView4.setFitHeight(110);
        imageView4.setFitWidth(115);
        imageView4.setLayoutX(-2);
        imageView4.setLayoutY(616);
        imageView4.setPreserveRatio(true);
        imageView4.setPickOnBounds(true);

        Button button5 = new Button("All Complaints");
        button5.setLayoutX(200);
        button5.setLayoutY(120);
        button5.setMnemonicParsing(false);
        button5.setFont(new Font(14));

        Button button6 = new Button("Sort by Date");
        button6.setLayoutX(350);
        button6.setLayoutY(120);
        button6.setMnemonicParsing(false);
        button6.setFont(new Font(14));

        // combobox of complaint type

        // Text text44 = new Text("Show");
        // text44.setFont(new Font(14));
        // text44.setLayoutX(259);
        // text44.setLayoutY(145);

        TextField search = new TextField();
        search.setLayoutX(500);
        search.setLayoutY(120);
        search.setPrefWidth(300);
        search.setPrefHeight(38);
        search.setPromptText("Enter ID");
        search.setStyle("-fx-background-color: transparent; -fx-border-color: black;-fx-border-width: 1px;");

        Button applyButton = new Button("Apply");
        applyButton.setLayoutX(830);
        applyButton.setLayoutY(120);
        applyButton.setMnemonicParsing(false);
        applyButton.setFont(new Font(14));

        Rectangle rect9 = new Rectangle(105, 730);
        rect9.setFill(Color.web("#5673a6"));
        rect9.setStroke(Color.web("#5673a8"));
        rect9.setStrokeType(StrokeType.INSIDE);
        rect9.setArcHeight(5);
        rect9.setLayoutY(-3);
        rect9.setWidth(105);

        Scene scene = new Scene(root, 1280, 720);
        primaryStage.setTitle("Complaints UI");
        primaryStage.setScene(scene);
        primaryStage.show();

        root.getChildren().addAll(rect1, rect2, rect3, rect4, text1, text2, text3, text4,
                text5, text6, text37, text43,
                rect9, imageView1, imageView2, imageView3, imageView4, button5, button6);

        // feedback image
        imageView3.setOnMouseClicked(e -> {
            System.out.println("feedback");
        });

        // dashboard image
        imageView1.setOnMouseClicked(e -> {
            // remove search and apply button
            root.getChildren().removeAll(search, applyButton);
            // add Welcome Admin
            root.getChildren().add(text43);
            root.getChildren().add(button5);
            root.getChildren().add(button6);

        });

        // browse image
        imageView2.setOnMouseClicked(e -> {
            root.getChildren().addAll(search, applyButton);
            // remove Welcome Admin
            root.getChildren().remove(text43);
            root.getChildren().remove(button5);
            root.getChildren().remove(button6);
        });

        // check if file is not empty then read from file
        Complaint complaints = new Complaint();
        boolean isEmpty = false;
        isEmpty = complaints.getstatusofFile();
        // String filtertypeString = complaintType.getValue();

        if (isEmpty == false) {

            String fileName = "Complaints.txt"; // Replace with the actual file name
            // count number of lines in file
            int lines = 0;
            try {
                BufferedReader reader = new BufferedReader(new FileReader(fileName));
                while (reader.readLine() != null)
                    lines++;
                reader.close();
            } catch (IOException e) {
                System.out.println("Error: " + e);
            }

            System.out.println("Number of lines in file : " + lines);

            Admin admin = new Admin();
            int count = 0;
            int y = 0;
            while (count < lines) {
                String complaint = admin.viewComplaint(count + 1);
                String[] parts = complaint.split(",");

                Text text7 = new Text(parts[0]);
                text7.setFont(new Font(14));
                text7.setLayoutX(262);
                text7.setLayoutY(242 + y);

                Text text8 = new Text(parts[1]);
                text8.setFont(new Font(14));
                text8.setLayoutX(355);
                text8.setLayoutY(242 + y);

                Text text9 = new Text(parts[2]);
                text9.setFont(new Font(14));
                text9.setLayoutX(485);
                text9.setLayoutY(243 + y);

                Text text10 = new Text(parts[3]);
                text10.setFont(new Font(14));
                text10.setLayoutX(599);
                text10.setLayoutY(243 + y);

                Text text11 = new Text(parts[4]);
                text11.setFont(new Font(14));
                text11.setLayoutX(724);
                text11.setLayoutY(244 + y);

                String s = parts[5].substring(0, 10);
                s += "...";
                Text text38 = new Text(s);
                text38.setFont(new Font(14));
                text38.setLayoutX(831);
                text38.setLayoutY(242 + y);

                Text text12 = new Text(parts[6]);
                text12.setFont(new Font(14));
                text12.setLayoutX(973);
                text12.setLayoutY(241 + y);

                Button button2 = new Button("Open " + (count + 1));
                button2.setLayoutX(1091);
                button2.setLayoutY(220 + y);
                button2.setMnemonicParsing(false);
                button2.setFont(new Font(14));

                // Button 1 should be created anew for each iteration as well
                Button button1 = new Button();
                button1.setLayoutX(208);
                button1.setLayoutY(222 + y);
                button1.setPrefHeight(29);
                button1.setPrefWidth(29);
                button1.setFont(new Font(14));

                root.getChildren().addAll(
                        text7, text8, text9, text10, text11, text12,
                        button1, button2, text38);

                button2.setOnAction(e -> {
                    String whichtoOpen = button2.getText();
                    String[] parts1 = whichtoOpen.split(" ");
                    int which = Integer.parseInt(parts1[1]);
                    System.out.println(which);
                    primaryStage.close();
                    ForwardComplaint(which);

                });

                applyButton.setOnAction(e -> {
                    String id = search.getText();
                    Admin admin1 = new Admin();
                    admin1.BrowseComplaints(id);
                });

                count++;
                y += 50;
            }
        }
    }

    public static void main(String args[]) {
        launch(args);
    }
}