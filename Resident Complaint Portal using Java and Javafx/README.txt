
READ ME!

Project Name: Resident Complaint Portal


Description:
This JavaFX application is meticulously designed to ensure effective handling and resolution of complaints while offering an interactive and user-friendly interface. It offers significant flexibility and control to both users and administrators, enabling swift issue resolution and continuous service improvement.

How to Use it:
1) Initialize the JavaFX application by launching the RCP.java file. This is the key entry point for your application, effectively booting up the necessary components and preparing the system for interaction.

2) Upon successful execution, an interface should appear requiring account registration. Please fill out the appropriate fields with accurate information to create your account.

3) Once account registration is completed, you will be prompted to log in. Use the credentials just registered to gain access to the system.

4) Upon successful login, you'll be redirected to a complaint submission interface. Here, you can enter the details of your complaint into the provided text field.

5) Once your complaint details have been provided, you'll have the option to expedite the resolution process. Choose whether or not to expedite based on your individual needs and urgency of the complaint.

6) Submit the complaint. If you opted to expedite the resolution process, you will be required to input your credit card details for verification. Following successful verification, your expedited complaint will be officially submitted.

7) In addition to complaint submission, our system offers a feedback function. By navigating to the "Feedback" tab, you can share your thoughts or suggestions to help us improve the service.

8) As an admin user, after logging in, you'll gain access to a comprehensive list of all complaints registered by the complainants. You can browse through this list and select any complaint for further review or action.

9) As part of the admin role, you can forward complaints to the appropriate department for resolution, ensuring swift and efficient handling of user issues.

10) The system allows you to generate reports for individual complaints or a collection of them. This feature assists in tracking complaint statuses and ensuring transparent communication with complainants.
For severe or inappropriate cases, as an admin, you have the authority to delete a complaint from the system.
Lastly, the "Browse Complaint" tab facilitates a more specific search for complaints using the unique Complaint-ID. This allows for quick retrieval and review of particular cases.

Libraries Required:
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

