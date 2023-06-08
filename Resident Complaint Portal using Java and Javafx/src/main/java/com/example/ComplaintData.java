package com.example;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class ComplaintData {
    private int complaintID;
    private String category;
    private String description;
    private String dateReceived;

    boolean checkFile() {
        boolean isEmpty = false;
        try {
            BufferedReader br = new BufferedReader(new FileReader("Complaints.txt"));
            if (br.readLine() == null) {
                isEmpty = true;
            }
            br.close();
        } catch (IOException e) {
            System.out.println("Error: " + e);
        }
        return isEmpty;
    }

    public int getNumberOfLines() {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                sc.nextLine();
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return count;
    }

    public String getID(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[0];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }

    String getname(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[1];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }

    String getAddress(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[2];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }

    String getcnic(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[3];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }

    String getCategory(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[4];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }

    String getDescription(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[5];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }

    String getDateReceived(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[6];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }

    String getExpedite(int lineNumber) {
        int count = 0;

        try (Scanner sc = new Scanner(new File("Complaints.txt"))) {
            while (sc.hasNextLine()) {
                count++;
                String line = sc.nextLine();

                // If the current line number is the desired line number, process it
                if (count == lineNumber) {
                    String[] details = line.split(",");
                    if (details.length > 0) {
                        return details[7];
                    } else {
                        return null;
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }
}
