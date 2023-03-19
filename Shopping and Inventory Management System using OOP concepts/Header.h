#include <iostream>
#include <string.h>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
class Registration
{
public:
    char CNIC[13];
    char password[100];
    char gender;
    double phone_num;
    int address;
    char location[100];

public:
    Registration()
    {
        CNIC[13] = {'0'};
        password[100] = {'0'};
        gender = 'N';
        phone_num = 0;
        address = 0;
        location[100] = {'0'};
    }

    void setcnic(string cnic)
    {
        strcpy(CNIC, cnic.c_str());
    }

    void setpassword(string pass)
    {
        strcpy(password, pass.c_str());
    }

    void personalinfo(char g, double p, int a)
    {
        gender = g;
        phone_num = p;
        address = a;
    }

    void setlocation(int loc)
    {
        address = loc;
    }
    char *getpass()
    {
        return password;
    }

    char *getcnic()
    {
        return CNIC;
    }

    void setaccount(Registration obj)
    {
        ofstream cust("Customer.bin", ios::binary);
        if (cust.write((char *)&obj, sizeof(obj)))
            cout << "Object Successfully Inserted!" << endl;
        else
            cout << "Object Insertion Failed" << endl;
        cust.close();
    }

    void setaccountofManager(Registration obj)
    {
        ofstream manag("Manager.bin", ios::binary);
        if (manag.write((char *)&obj, sizeof(obj)))
            cout << "Object Successfully Inserted!" << endl;
        else
            cout << "Object Insertion Failed" << endl;
        manag.close();
    }
};

class Person
{
protected:
    Registration temp; // composition
    char password[100];

public:
    Person()
    {
        ;
    }

    void setpass(string pass)
    {
        strcpy(password, pass.c_str());
    }

    char *getpass()
    {
        return password;
    }

    void display_error()
    {
        cout << "Incorrect credetials have been entered. Please try again.\n";
    }
};

class Customer : public Person
{
private:
    char CNIC[13];
    int location;

public:
    // Registration temp;
    bool customer(string cnic, string pass)
    {
        strcpy(temp.CNIC, cnic.c_str());
        strcpy(temp.password, pass.c_str());
        ifstream cust("Customer.bin", ios::binary);
        while (cust.read((char *)&temp, sizeof(temp)))
        {
            // cout<<temp.getcnic()<<" "<<cnic<<endl;
            // cout<<temp.getpass()<<" "<<pass<<endl;
            if (temp.getpass() == pass && temp.getcnic() == cnic + pass)
            {
                cout << "\nYOU HAVE SUCCESSFULLY LOGGED IN\n";
                cust.close();
                return 1;
            }
            else if (temp.getpass() == pass && temp.getcnic() == cnic)
            {
                cout << "\nYOU HAVE SUCCESSFULLY LOGGED IN\n";
                cust.close();
                return 1;
            }

            else
            {
                cout << "INCORRECT CREDENTIALS HAVE BEEN ENTERED!" << endl;
                return 0;
            }
        }
        return 0;
    }
    void setCNIC(string c)
    {
        strcpy(CNIC, c.c_str());
    }

    char *getcnic()
    {
        return CNIC;
    }

    int getlocationofcust()
    {
        return location;
    }
};

class Admin : public Person
{
private:
    char username[10];

public:
    void setuser(string u)
    {
        strcpy(username, u.c_str());
    }

    void insertobj(Admin obj)
    {
        ofstream admin("Admin.bin", ios::binary);
        if (admin.write((char *)&obj, sizeof(obj)))
            cout << "Object Successfully Inserted!" << endl;
        else
            cout << "Object Insertion Failed" << endl;
        admin.close();
    }

    char *getuser()
    {
        return username;
    }
};

class Product_Catalog
{
protected:
    string name;
    int price;
    int search;
    static int count_items_islamabad;
    int *sizeOfNameOfItems;
    static int count_items_quetta;
    static int count_items_peshawar;
    static int count_items_balochistan;
    static int count_items_rawalpindi;

public:
    int no_of_items=0;
    string items_in_islamabad; //=new char*[count_items_islamabad];
    string items_in_quetta;
    string items_in_peshawar;
    string items_in_balochistan;
    string items_in_pindi;
    int price_in_islamabad;
    int price_in_quetta;
    int price_in_peshawar;
    int price_in_balochistan;
    int price_in_pindi;
    int choice;

    int itemcode_in_islamabad;
    int itemcode_in_quetta;
    int itemcode_in_peshawar;
    int itemcode_in_balochistan;
    int itemcode_in_pindi;
    void display_item_admin()
    {
        Product_Catalog temp;
        // cout<<"\n****DISPLAYING ITEMS FOR ISLAMABAD****\n";

        cout << "\n****DISPLAYING ITEMS FOR ISLAMABAD****\n";
        ifstream islamabad_file("items_islamabad.bin", ios::binary);
        while (!islamabad_file.eof())
        {
            // cout<<"***********************"<<endl;
            islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // cout<<price_in_islamabad;
            int s = 0;
            islamabad_file.read((char *)&s, sizeof(s));
            if (s == 0)
                break;
            char *temp = new char[s + 1];
            islamabad_file.read(temp, s);
            temp[s] = '\0';
            string ss = temp;
            cout << "ITEM: " << ss << endl;
            cout << "Price: " << price_in_islamabad << endl; //[count_items_islamabad]<<endl;
            cout << "Item Code: " << itemcode_in_islamabad << endl
                 << endl;
        }
        islamabad_file.close();

        cout << "****DISPLAYING ITEMS FOR QUETTA****\n";
        ifstream quetta_file("items_quetta.bin", ios::binary);
        while (!quetta_file.eof())
        {
            quetta_file.read((char *)&price_in_quetta, sizeof(price_in_quetta));
            quetta_file.read((char *)&itemcode_in_quetta, sizeof(itemcode_in_quetta));
            int s = 0;
            quetta_file.read((char *)&s, sizeof(s));
            if (s == 0)
                break;
            char *temp = new char[s + 1];
            quetta_file.read(temp, s);
            temp[s] = '\0';
            string ss = temp;
            cout << "ITEM: " << ss << endl;
            cout << "Price: " << price_in_quetta << endl; //[count_items_islamabad]<<endl;
            cout << "Item Code: " << itemcode_in_quetta << endl
                 << endl;
        }
        quetta_file.close();

        cout << "****DISPLAYING ITEMS FOR PESHAWAR****\n";
        ifstream peshawar_file("items_peshawar.bin", ios::binary);
        while (!peshawar_file.eof())
        {
            peshawar_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
            peshawar_file.read((char *)&itemcode_in_peshawar, sizeof(itemcode_in_peshawar));
            int s = 0;
            peshawar_file.read((char *)&s, sizeof(s));
            if (s == 0)
                break;
            char *temp = new char[s + 1];
            peshawar_file.read(temp, s);
            temp[s] = '\0';
            string ss = temp;
            cout << "ITEM: " << ss << endl;
            cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
            cout << "Item Code: " << itemcode_in_peshawar << endl
                 << endl;
        }
        peshawar_file.close();

        cout << "****DISPLAYING ITEMS FOR BALOCHISTAN****\n";
        ifstream balochistan_file("items_balochistan.bin", ios::binary);
        while (!balochistan_file.eof())
        {
            balochistan_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
            balochistan_file.read((char *)&itemcode_in_balochistan, sizeof(itemcode_in_balochistan));
            int s = 0;
            balochistan_file.read((char *)&s, sizeof(s));
            if (s == 0)
                break;
            char *temp = new char[s + 1];
            balochistan_file.read(temp, s);
            temp[s] = '\0';
            string ss = temp;
            cout << "ITEM: " << ss << endl;
            cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
            cout << "Item Code: " << itemcode_in_balochistan << endl
                 << endl;
        }
        balochistan_file.close();

        cout << "****DISPLAYING ITEMS FOR RAWALPINDI****\n";
        ifstream pindi_file("items_pindi.bin", ios::binary);
        while (!pindi_file.eof())
        {
            pindi_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
            pindi_file.read((char *)&itemcode_in_pindi, sizeof(itemcode_in_pindi));
            int s = 0;
            pindi_file.read((char *)&s, sizeof(s));
            if (s == 0)
                break;
            char *temp = new char[s + 1];
            pindi_file.read(temp, s);
            temp[s] = '\0';
            string ss = temp;
            cout << "ITEM: " << ss << endl;
            cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
            cout << "Item Code: " << itemcode_in_pindi << endl
                 << endl;
        }
        pindi_file.close();
    }
    void add_item_admin()
    {
        // cout<<"In which city you want to add item: \n";
        // cout<<"1. Islamabad\n2. Peshawar\n3. Quetta\n4. Rawalpindi\n5. Balochistan\n";
        // cin>>choice;
        // char ch[100];
        // switch(choice)
        // {
        //     case 1:
        //     {
        cout << "Enter item name: ";
        cin >> items_in_islamabad;
        cout << "Enter price: ";
        cin >> price_in_islamabad; //[count_items_islamabad];
        cout << "Enter Item code: ";
        cin >> itemcode_in_islamabad;

        ofstream islamabad("items_islamabad.bin", ios::binary | ios::app);
        islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
        islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
        // islamabad.write((char *)&no_of_items, sizeof(no_of_items));
        int s = items_in_islamabad.size();
        islamabad.write((char *)&s, sizeof(s));
        const char *temp = items_in_islamabad.c_str();
        islamabad.write(temp, strlen(temp));
        islamabad.close();

        // cout<<"\n****DISPLAYING ITEMS FOR ISLAMABAD****\n";
        // ifstream islamabad_file("items_islamabad.bin", ios::binary);
        // while (!islamabad_file.eof())
        // {
        //     islamabad_file.read((char*)&price_in_islamabad, sizeof(price_in_islamabad));
        //     int s=0;
        //     islamabad_file.read((char *)&s, sizeof(s));
        //     if(s==0)
        //     break;
        //     char *temp=new char[s+1];
        //     islamabad_file.read(temp,s);
        //     temp[s]='\0';
        //     string ss=temp;
        //     cout<<"ITEM: "<<ss<<endl;
        //     cout<<"Price: "<<price_in_islamabad<<endl;//[count_items_islamabad]<<endl;
        // }
        // islamabad_file.close();
        // count_items_islamabad++;
        //     break;
        // }
        // case 2:
        // {
        //     cout<<"Enter item name: ";
        //     cin>>items_in_peshawar;
        //     cout<<"Enter price: ";
        //     cin>>price_in_peshawar;//[count_items_islamabad];

        ofstream peshawar("items_peshawar.bin", ios::binary | ios::app);
        peshawar.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
        peshawar.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
        // peshawar.write((char *)&no_of_items, sizeof(no_of_items));
        int pesh = items_in_islamabad.size();
        peshawar.write((char *)&pesh, sizeof(pesh));
        const char *str = items_in_islamabad.c_str();
        peshawar.write(str, strlen(str));
        peshawar.close();
        //     break;
        // }
        // case 3:
        // {
        //     cout<<"Enter item name: ";
        //     cin>>items_in_quetta;
        //     cout<<"Enter price: ";
        //     cin>>price_in_quetta;//[count_items_islamabad];

        ofstream quetta("items_quetta.bin", ios::binary | ios::app);
        quetta.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
        quetta.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
        // quetta.write((char *)&no_of_items, sizeof(no_of_items));
        int q = items_in_islamabad.size();
        quetta.write((char *)&q, sizeof(q));
        const char *str2 = items_in_islamabad.c_str();
        quetta.write(str2, strlen(str2));
        quetta.close();
        //     break;
        // }
        // case 4:
        // {
        //     cout<<"Enter item name: ";
        //     cin>>items_in_pindi;
        //     cout<<"Enter price: ";
        //     cin>>price_in_pindi;//[count_items_islamabad];

        ofstream pindi("items_pindi.bin", ios::binary | ios::app);
        pindi.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
        pindi.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
        // pindi.write((char *)&no_of_items, sizeof(no_of_items));
        int p = items_in_islamabad.size();
        pindi.write((char *)&p, sizeof(p));
        const char *str3 = items_in_islamabad.c_str();
        pindi.write(str3, strlen(str3));
        pindi.close();
        //     break;
        // }
        // case 5:
        // {
        //     cout<<"Enter item name: ";
        //     cin>>items_in_balochistan;
        //     cout<<"Enter price: ";
        //     cin>>price_in_balochistan;//[count_items_islamabad];

        ofstream balochistan("items_balochistan.bin", ios::binary | ios::app);
        balochistan.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
        balochistan.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
        // balochistan.write((char *)&no_of_items, sizeof(no_of_items));
        int b = items_in_islamabad.size();
        balochistan.write((char *)&b, sizeof(b));
        const char *str4 = items_in_islamabad.c_str();
        balochistan.write(str4, strlen(str4));
        balochistan.close();
        // break;
        // }
        // }
    }

    void delete_item_admin()
    {
        // int city;
        // cout<<"In which city you want to delete item: \n1. Islamabad\n2. Quetta\n3. Peshawar\n4. Balochistan\n5. Rawalpindi\n";
        // cin>>city;
        // switch(city)
        // {
        //     case 1:
        //     {
        string str;
        cout << "Enter the item name that you want to delete: ";
        cin >> str;
        fstream islamabad_file("items_islamabad.bin", ios::binary | ios::in | ios::out);
        fstream quetta_file("items_quetta.bin", ios::binary|ios::in|ios::out);
        fstream peshawar_file("items_peshawar.bin", ios::binary|ios::in|ios::out);
        fstream balochistan_file("items_balochistan.bin", ios::binary|ios::in|ios::out);
        fstream pindi_file("items_pindi.bin", ios::binary|ios::in|ios::out);

        ofstream after_deletion_islamabad("after_deletion_islamabad.bin", ios::binary | ios::app);
        ofstream after_deletion_quetta("after_deletion_quetta.bin",ios::binary| ios::app);
        ofstream after_deletion_peshawar("after_deletion_peshawar.bin",ios::binary| ios::app);
        ofstream after_deletion_pindi("after_deletion_pindi.bin",ios::binary| ios::app);
        ofstream after_deletion_balochistan("after_deletion_balochistan.bin",ios::binary| ios::app);

        while (!islamabad_file.eof())
        {
            islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
            int s = 0;
            islamabad_file.read((char *)&s, sizeof(s));
            if (s == 0)
                break;
            char *temp = new char[s + 1];
            islamabad_file.read(temp, s);
            temp[s] = '\0';
            string ss = temp;
            //cout << ss << endl;
            //cout << str << endl << endl;
            if (ss != str)
            {
                cout << "STR::: " << ss << endl;
                // items_in_islamabad='\0';
                // price_in_islamabad='\0';
                // int z=islamabad_file.tellg()-sizeof(s);
                // cout<<"Z INDEX: "<<z<<endl;
                // islamabad_file.seekg(z);
                // ofstream after_deletion("after_deletion_item.bin",ios::binary| ios::app);
                
                after_deletion_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_deletion_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // after_deletion_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                int s = ss.size();
                after_deletion_islamabad.write((char *)&s, sizeof(s));
                const char *temp = ss.c_str();
                after_deletion_islamabad.write(temp, strlen(temp));

                after_deletion_quetta.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_deletion_quetta.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                int q=ss.size();
                after_deletion_quetta.write((char *)&q, sizeof(q));
                const char*str1=ss.c_str();
                after_deletion_quetta.write(str1,strlen(str1));


                after_deletion_balochistan.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_deletion_balochistan.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                int b=ss.size();
                after_deletion_balochistan.write((char *)&b, sizeof(b));
                const char*str3=ss.c_str();
                after_deletion_balochistan.write(str3,strlen(str3));

                after_deletion_peshawar.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_deletion_peshawar.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                int pe=ss.size();
                after_deletion_peshawar.write((char *)&pe, sizeof(pe));
                const char*str4=ss.c_str();
                after_deletion_peshawar.write(str4,strlen(str4));


                after_deletion_pindi.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_deletion_pindi.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                int p=ss.size();
                after_deletion_pindi.write((char *)&p, sizeof(p));
                const char*str2=ss.c_str();
                after_deletion_pindi.write(str2,strlen(str2));
            }
            //
        }

        // while(!balochistan_file.eof())
        // {

        // }

        // while(!quetta_file.eof())
        // {

        // }

        // while(!peshawar_file.eof())
        // {

        // }

        islamabad_file.close();
        pindi_file.close();
        quetta_file.close();
        balochistan_file.close();
        peshawar_file.close();

        after_deletion_islamabad.close();
        after_deletion_balochistan.close();
        after_deletion_peshawar.close();
        after_deletion_quetta.close();
        after_deletion_pindi.close();

        remove("items_islamabad.bin");

        remove("items_quetta.bin");
        remove("items_peshawar.bin");
        remove("items_balochistan.bin");
        remove("items_pindi.bin");

        rename("after_deletion_islamabad.bin","items_islamabad.bin");

        rename("after_deletion_pindi.bin","items_pindi.bin");
        rename("after_deletion_balochistan.bin","items_balochistan.bin");
        rename("after_deletion_quetta.bin","items_quetta.bin");
        rename("after_deletion_peshawar.bin","items_peshawar.bin");

        // break;
        // char str[100];
        // cout<<"Enter item name you want to delete: ";
        // cin>>str;
        // Product_Catalog temp;
        // int delete_count;
        // ifstream islamabad_file("items_islamabad.bin", ios::binary);
        // while (islamabad_file.read((char *)&temp, sizeof(temp)))
        // {
        //     for(int i=0;i<temp.count_items_islamabad;i++)
        //     {
        //         if(temp.items_in_islamabad[i]==str)
        //         delete_count=i;
        //     }
        //     temp.items_in_islamabad[delete_count]="";
        // }
        // ofstream islamabad("items_islamabad.bin", ios::binary);
        // if (islamabad.write((char *)&temp, sizeof(temp)))
        //     cout << "Item Successfully Deleted!" << endl;
        // else
        //     cout << "Item deletion Failed" << endl;
        // islamabad.close();
        //     }
        //     case 2:
        //     {
        //         break;
        //     }
        //     case 3:
        //     {
        //         break;
        //     }
        //     case 4:
        //     {
        //         break;
        //     }
        //     case 5:
        //     {
        //         break;
        //     }
        // }
    }

    void update_product_admin()
    {
        // int city;
        // cout<<"In which city you want to Update item: \n1. Islamabad\n2. Quetta\n3. Peshawar\n4. Balochistan\n5. Rawalpindi\n";
        // cin>>city;
        // switch(city)
        // {
        //     case 1:
        //     {
        Product_Catalog temp;
        string str;
        cout << "Enter item name you want to Update: ";
        cin >> str;
        fstream islamabad_file("items_islamabad.bin", ios::binary | ios::in | ios::out);
        fstream quetta_file("items_quetta.bin", ios::binary| ios::in | ios::out);
        fstream peshawar_file("items_peshawar.bin", ios::binary| ios::in | ios::out);
        fstream balochistan_file("items_balochistan.bin", ios::binary| ios::in | ios::out);
        fstream pindi_file("items_pindi.bin", ios::binary| ios::in | ios::out);

        ofstream after_update_islamabad("after_update_islamabad.bin",ios::binary| ios::app);
        ofstream after_update_quetta("after_update_quetta.bin",ios::binary| ios::app);
        ofstream after_update_peshawar("after_update_peshawar.bin",ios::binary| ios::app);
        ofstream after_update_pindi("after_update_pindi.bin",ios::binary| ios::app);
        ofstream after_update_balochistan("after_update_balochistan.bin",ios::binary| ios::app);
        while (!islamabad_file.eof())
        {
            islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // islamabad_file.write((char *)&no_of_items, sizeof(no_of_items));
            int s = 0;
            islamabad_file.read((char *)&s, sizeof(s));
            if (s == 0)
                break;
            char *temp = new char[s + 1];
            islamabad_file.read(temp, s);
            temp[s] = '\0';
            string ss = temp;
            //cout<<"File name: "<<ss<<endl;
            //cout<<"My name: "<<str<<endl<<endl;
            if (ss == str)
            {
                //cout<<"STR:  "<<ss<<endl;
                cout << "Enter new name: ";
                cin >> items_in_islamabad;
                cout << "Enter new price: ";
                cin >> price_in_islamabad;
                cout<<"Enter new item code: ";
                cin>>itemcode_in_islamabad;

                after_update_balochistan.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_update_balochistan.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                int b = items_in_islamabad.size();
                after_update_balochistan.write((char *)&b, sizeof(b));
                const char *str1 = items_in_islamabad.c_str();
                after_update_balochistan.write(str1, strlen(str1));

                after_update_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_update_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                int sw = items_in_islamabad.size();
                after_update_islamabad.write((char *)&sw, sizeof(sw));
                const char *temp = items_in_islamabad.c_str();
                after_update_islamabad.write(temp, strlen(temp));


                after_update_peshawar.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_update_peshawar.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                int pesh = items_in_islamabad.size();
                after_update_peshawar.write((char *)&pesh, sizeof(pesh));
                const char *str2 = items_in_islamabad.c_str();
                after_update_peshawar.write(str2, strlen(str2));

                after_update_pindi.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_update_pindi.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                int p = items_in_islamabad.size();
                after_update_pindi.write((char *)&p, sizeof(p));
                const char *str3 = items_in_islamabad.c_str();
                after_update_pindi.write(str3, strlen(str3));

                after_update_quetta.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_update_quetta.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                int q = items_in_islamabad.size();
                after_update_quetta.write((char *)&q, sizeof(q));
                const char *str4 = items_in_islamabad.c_str();
                after_update_quetta.write(str4, strlen(str4));
            }
            else
            {
                after_update_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                after_update_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                after_update_islamabad.write((char *)&s, sizeof(s));
                after_update_islamabad.write(temp, strlen(temp));

                after_update_balochistan.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    after_update_balochistan.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                    after_update_balochistan.write((char *)&s, sizeof(s));
                    after_update_balochistan.write(temp, strlen(temp));

                after_update_peshawar.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    after_update_peshawar.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                    after_update_peshawar.write((char *)&s, sizeof(s));
                    after_update_peshawar.write(temp, strlen(temp));

                after_update_pindi.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    after_update_pindi.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                    after_update_pindi.write((char *)&s, sizeof(s));
                    after_update_pindi.write(temp, strlen(temp));

                after_update_quetta.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    after_update_quetta.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                    after_update_quetta.write((char *)&s, sizeof(s));
                    after_update_quetta.write(temp, strlen(temp));
            }
        }
        
        islamabad_file.close();
        quetta_file.close();
        pindi_file.close();
        peshawar_file.close();
        balochistan_file.close();

        after_update_islamabad.close();
        after_update_balochistan.close();
        after_update_peshawar.close();
        after_update_pindi.close();
        after_update_quetta.close();
        remove("items_islamabad.bin");
        remove("items_quetta.bin");
        remove("items_pindi.bin");
        remove("items_peshawar.bin");
        remove("items_balochistan.bin");

        rename("after_update_islamabad.bin","items_islamabad.bin");
        rename("after_update_quetta.bin","items_quetta.bin");
        rename("after_update_pindi.bin","items_pindi.bin");
        rename("after_update_peshawar.bin","items_peshawar.bin");
        rename("after_update_balochistan.bin","items_balochistan.bin");
        // islamabad_file.close();
    }
    //             break;
    //         }
    //         case 2:
    //         {
    //             break;
    //         }
    //         case 3:
    //         {
    //             break;
    //         }
    //         case 4:
    //         {
    //             break;
    //         }
    //         case 5:
    //         {
    //             break;
    //         }
    //     }

    void Show_Feedbacks()
    {
        ;
    }
};

int Product_Catalog::count_items_islamabad = 1;
int Product_Catalog::count_items_peshawar = 1;
int Product_Catalog::count_items_balochistan = 1;
int Product_Catalog::count_items_rawalpindi = 1;
int Product_Catalog::count_items_quetta = 1;

//****************MANAGER CLASS*******************
class Manager : public Person, public Registration
{
protected:
    char CNIC[13];
    int location;

public:
    // char *items_of_islamabad=new char;
    // int price_in_islamabad[100];
    // static int count;
    // char *items_of_islamabad[32]={"chicken","beef","mutton","fish","milk","eggs","yougurt","cheese","apple","banana","mango","orange","watermelon","tomato","onion","cucumber","potatoes","chocolate","chips","biscuits","spices","lentils","wheat","flour","rice","cereal","shampoo","soap","hand_sanitizer","detergent","dish_soap","washroom_cleaner"};
    // int price_in_islamabad[32]={120,400,350,200,110,105,80,120,200,180,300,250,200,280,160,100,100,80,50,40,60,100,500,200,300,200,120,60,110,60,60,130};
    // char *items_of_quetta[32]={"chicken","beef","mutton","fish","milk","eggs","yougurt","cheese","apple","banana","mango","orange","watermelon","tomato","onion","cucumber","potatoes","chocolate","chips","biscuits","spices","lentils","wheat","flour","rice","cereal","shampoo","soap","hand_sanitizer","detergent","dish_soap","washroom_cleaner"};
    Manager() { ; }
    // Registration temp;
    bool manager(string cnic, string pass)
    {
        strcpy(temp.CNIC, cnic.c_str());
        strcpy(temp.password, pass.c_str());
        ifstream cust("Manager.bin", ios::binary);
        while (cust.read((char *)&temp, sizeof(temp)))
        {
            // cout<<temp.getcnic()<<" "<<cnic<<endl;
            // cout<<temp.getpass()<<" "<<pass<<endl;
            if (temp.getpass() == pass && temp.getcnic() == cnic + pass)
            {
                cout << "\nYOU HAVE SUCCESSFULLY LOGGED IN\n";
                cust.close();
                return 1;
            }
            else
            {
                cout << "INCORRECT CREDENTIALS HAVE BEEN ENTERED!" << endl;
                return 0;
            }
        }
        return 0;
    }
    void setCNIC(string c)
    {
        strcpy(CNIC, c.c_str());
    }

    char *getcnic()
    {
        return CNIC;
    }
    int getlocation()
    {
        return address;
    }
};

// int Manager::count=0;

class Inventory_Managment : public Manager, public Product_Catalog
{
protected:
    string city;
    int location;
    char item;

public:
    Product_Catalog obj;

    Inventory_Managment() { ; }

    void setlocation(int loc)
    {
        location = loc;
    }
    void display_items()
    {
        switch (location)
        {
        case 1:
        {
            cout << "\n****DISPLAYING ITEMS FOR ISLAMABAD****\n";
            ifstream islamabad_file("items_islamabad.bin", ios::binary);
            while (!islamabad_file.eof())
            {
                islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                //islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                int s = 0;
                islamabad_file.read((char *)&s, sizeof(s));
                if (s == 0)
                    break;
                char *temp = new char[s + 1];
                islamabad_file.read(temp, s);
                temp[s] = '\0';
                string ss = temp;
                cout << "ITEM: " << ss << endl;
                cout << "Price: " << price_in_islamabad << endl; //[count_items_islamabad]<<endl;
                cout << "Item code: " << itemcode_in_islamabad << endl;
                //cout<<"Quantity of items present: "<<no_of_items<<endl<<endl;
            }
            islamabad_file.close();

            break;
        }

        case 2:
        {

            cout << "******DISPLAYING ITEMS OF QUETTA******\n";

            ifstream islamabad_file("items_quetta.bin", ios::binary);
            while (!islamabad_file.eof())
            {
                islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                int s = 0;
                islamabad_file.read((char *)&s, sizeof(s));
                if (s == 0)
                    break;
                char *temp = new char[s + 1];
                islamabad_file.read(temp, s);
                temp[s] = '\0';
                string ss = temp;
                cout << "ITEM: " << ss << endl;
                cout << "Price: " << price_in_islamabad << endl; //[count_items_islamabad]<<endl;
                cout << "Item code: " << itemcode_in_islamabad << endl;
                // cout<<"Quantity of item: "<<no_of_items<<endl<<endl;
            }
            islamabad_file.close();

            break;
        }

        case 3:
        {
            cout << "****DISPLAYING ITEMS FOR PESHAWAR****\n";
            ifstream peshawar_file("items_peshawar.bin", ios::binary);
            while (!peshawar_file.eof())
            {
                peshawar_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
                peshawar_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // peshawar_file.read((char *)&no_of_items, sizeof(no_of_items));
                int s = 0;
                peshawar_file.read((char *)&s, sizeof(s));
                if (s == 0)
                    break;
                char *temp = new char[s + 1];
                peshawar_file.read(temp, s);
                temp[s] = '\0';
                string ss = temp;
                cout << "ITEM: " << ss << endl;
                cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
                cout << "Item code: " << itemcode_in_islamabad << endl;
                // cout<<"Quantity of item: "<<no_of_items<<endl<<endl;
            }
            peshawar_file.close();
            break;
        }

        case 4:
        {
            cout << "****DISPLAYING ITEMS FOR BALOCHISTAN****\n";
            ifstream balochistan_file("items_balochistan.bin", ios::binary);
            while (!balochistan_file.eof())
            {
                balochistan_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
                balochistan_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // balochistan_file.read((char *)&no_of_items, sizeof(no_of_items));
                int s = 0;
                balochistan_file.read((char *)&s, sizeof(s));
                if (s == 0)
                    break;
                char *temp = new char[s + 1];
                balochistan_file.read(temp, s);
                temp[s] = '\0';
                string ss = temp;
                cout << "ITEM: " << ss << endl;
                cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
                cout << "Item code: " << itemcode_in_islamabad << endl;
                // cout<<"Quantity of item: "<<no_of_items<<endl<<endl;
            }
            balochistan_file.close();
            break;
        }

        case 5:
        {
            cout << "****DISPLAYING ITEMS FOR RAWALPINDI****\n";
            ifstream pindi_file("items_pindi.bin", ios::binary);
            while (!pindi_file.eof())
            {
                pindi_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
                pindi_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                // pindi_file.read((char *)&no_of_items, sizeof(no_of_items));
                int s = 0;
                pindi_file.read((char *)&s, sizeof(s));
                if (s == 0)
                    break;
                char *temp = new char[s + 1];
                pindi_file.read(temp, s);
                temp[s] = '\0';
                string ss = temp;
                cout << "ITEM: " << ss << endl;
                cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
                cout << "Item code: " << itemcode_in_islamabad << endl;
                // cout<<"Quantity of item: "<<no_of_items<<endl<<endl;
            }
            pindi_file.close();
            break;
        }
        }
    }

    void add_item()
    {
        switch (location)
        {
        case 1:
        {
            cout << "Enter item name: ";
            cin >> items_in_islamabad;
            cout << "Enter price: ";
            cin >> price_in_islamabad; //[count_items_islamabad];
            cout << "Enter item code: ";
            cin >> itemcode_in_islamabad;
            // cout<<"Enter the quantity of item: ";
            // cin>>no_of_items;
            ofstream islamabad("items_islamabad.bin", ios::binary | ios::app);
            islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // islamabad.write((char *)&no_of_items, sizeof(no_of_items));
            int s = items_in_islamabad.size();
            islamabad.write((char *)&s, sizeof(s));
            const char *temp = items_in_islamabad.c_str();
            islamabad.write(temp, strlen(temp));
            islamabad.close();

            break;
        }

        case 2:
        {
            cout << "Enter item name: ";
            cin >> items_in_islamabad;
            cout << "Enter price: ";
            cin >> price_in_islamabad; //[count_items_islamabad];
            cout << "Enter item code: ";
            cin >> itemcode_in_islamabad;
            // cout<<"Enter the quantity of item: ";
            // cin>>no_of_items;

            ofstream islamabad("items_quetta.bin", ios::binary | ios::app);
            islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // islamabad.write((char *)&no_of_items, sizeof(no_of_items));
            int s = items_in_islamabad.size();
            islamabad.write((char *)&s, sizeof(s));
            const char *temp = items_in_islamabad.c_str();
            islamabad.write(temp, strlen(temp));
            islamabad.close();
            break;
        }

        case 3:
        {
            cout << "Enter item name: ";
            cin >> items_in_islamabad;
            cout << "Enter price: ";
            cin >> price_in_islamabad; //[count_items_islamabad];
            cout << "Enter item code: ";
            cin >> itemcode_in_islamabad;
            // cout<<"Enter the quantity of item: ";
            // cin>>no_of_items;

            ofstream islamabad("items_peshawar.bin", ios::binary | ios::app);
            islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // islamabad.write((char *)&no_of_items, sizeof(no_of_items));
            int s = items_in_islamabad.size();
            islamabad.write((char *)&s, sizeof(s));
            const char *temp = items_in_islamabad.c_str();
            islamabad.write(temp, strlen(temp));
            islamabad.close();
            break;
        }

        case 4:
        {
            cout << "Enter item name: ";
            cin >> items_in_islamabad;
            cout << "Enter price: ";
            cin >> price_in_islamabad; //[count_items_islamabad];
            cout << "Enter item code: ";
            cin >> itemcode_in_islamabad;
            // cout<<"Enter the quantity of item: ";
            // cin>>no_of_items;

            ofstream islamabad("items_balochistan.bin", ios::binary | ios::app);
            islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // islamabad.write((char *)&no_of_items, sizeof(no_of_items));
            int s = items_in_islamabad.size();
            islamabad.write((char *)&s, sizeof(s));
            const char *temp = items_in_islamabad.c_str();
            islamabad.write(temp, strlen(temp));
            islamabad.close();
            break;
        }

        case 5:
        {
            cout << "Enter item name: ";
            cin >> items_in_islamabad;
            cout << "Enter price: ";
            cin >> price_in_islamabad; //[count_items_islamabad];
            cout << "Enter item code: ";
            cin >> itemcode_in_islamabad;
            // cout<<"Enter the quantity of item: ";
            // cin>>no_of_items;

            ofstream islamabad("items_pindi.bin", ios::binary | ios::app);
            islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
            islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
            // islamabad.write((char *)&no_of_items, sizeof(no_of_items));
            int s = items_in_islamabad.size();
            islamabad.write((char *)&s, sizeof(s));
            const char *temp = items_in_islamabad.c_str();
            islamabad.write(temp, strlen(temp));
            islamabad.close();
            break;
        }
        }
    }

    void delete_item()
    {
        switch(location)
        {
            case 1:
            {

                string str;
                cout << "Enter the item name that you want to delete: ";
                cin >> str;
                fstream islamabad_file("items_islamabad.bin", ios::binary | ios::in | ios::out);
                // fstream quetta_file("items_quetta.bin", ios::binary|ios::in|ios::out);
                // fstream peshawar_file("items_peshawar.bin", ios::binary|ios::in|ios::out);
                // fstream balochistan_file("items_balochistan.bin", ios::binary|ios::in|ios::out);
                // fstream pindi_file("items_pindi.bin", ios::binary|ios::in|ios::out);

                ofstream after_deletion_islamabad("after_deletion_islamabad.bin", ios::binary | ios::app);
                // ofstream after_deletion_quetta("after_deletion_quetta.bin",ios::binary| ios::app);
                // ofstream after_deletion_peshawar("after_deletion_peshawar.bin",ios::binary| ios::app);
                // ofstream after_deletion_pindi("after_deletion_pindi.bin",ios::binary| ios::app);
                // ofstream after_deletion_balochistan("after_deletion_balochistan.bin",ios::binary| ios::app);

                while (!islamabad_file.eof())
                {
                    islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                    int s = 0;
                    islamabad_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    islamabad_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    //cout << ss << endl;
                    //cout << str << endl << endl;
                    if (ss != str)
                    {
                        cout << "STR::: " << ss << endl;
                        // items_in_islamabad='\0';
                        // price_in_islamabad='\0';
                        // int z=islamabad_file.tellg()-sizeof(s);
                        // cout<<"Z INDEX: "<<z<<endl;
                        // islamabad_file.seekg(z);
                        // ofstream after_deletion("after_deletion_item.bin",ios::binary| ios::app);
                        
                        after_deletion_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        after_deletion_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                        // after_deletion_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                        int s = ss.size();
                        after_deletion_islamabad.write((char *)&s, sizeof(s));
                        const char *temp = ss.c_str();
                        after_deletion_islamabad.write(temp, strlen(temp));

                        // after_deletion_quetta.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int q=items_in_islamabad.size();
                        // after_deletion_quetta.write((char *)&q, sizeof(q));
                        // const char*str1=items_in_islamabad.c_str();
                        // after_deletion_quetta.write(str1,strlen(str1));

                        // after_deletion_pindi.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int p=items_in_islamabad.size();
                        // after_deletion_pindi.write((char *)&p, sizeof(p));
                        // const char*str2=items_in_islamabad.c_str();
                        // after_deletion_pindi.write(str2,strlen(str2));

                        // after_deletion_balochistan.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int b=items_in_islamabad.size();
                        // after_deletion_balochistan.write((char *)&b, sizeof(b));
                        // const char*str3=items_in_islamabad.c_str();
                        // after_deletion_balochistan.write(str3,strlen(str3));

                        // after_deletion_peshawar.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int pe=items_in_islamabad.size();
                        // after_deletion_peshawar.write((char *)&pe, sizeof(pe));
                        // const char*str4=items_in_islamabad.c_str();
                        // after_deletion_peshawar.write(str4,strlen(str4));
                    }
                    //
                }

                islamabad_file.close();
                // pindi_file.close();
                // quetta_file.close();
                // balochistan_file.close();
                // peshawar_file.close();

                after_deletion_islamabad.close();
                // after_deletion_balochistan.close();
                // after_deletion_peshawar.close();
                // after_deletion_quetta.close();
                // after_deletion_pindi.close();

                remove("items_islamabad.bin");

                // remove("items_quetta.bin");
                // remove("items_peshawar.bin");
                // remove("items_balochistan.bin");
                // remove("items_pindi.bin");

                rename("after_deletion_islamabad.bin","items_islamabad.bin");
                break;
            }

            case 2:
            {
                string str;
                cout << "Enter the item name that you want to delete: ";
                cin >> str;
                fstream quetta_file("items_quetta.bin", ios::binary|ios::in|ios::out);
                ofstream after_deletion_quetta("after_deletion_quetta.bin",ios::binary| ios::app);
                while (!quetta_file.eof())
                {
                    quetta_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    quetta_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                    int s = 0;
                    quetta_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    quetta_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    //cout << ss << endl;
                    //cout << str << endl << endl;
                    if (ss != str)
                    {
                        cout << "STR::: " << ss << endl;
                        // items_in_islamabad='\0';
                        // price_in_islamabad='\0';
                        // int z=islamabad_file.tellg()-sizeof(s);
                        // cout<<"Z INDEX: "<<z<<endl;
                        // islamabad_file.seekg(z);
                        // ofstream after_deletion("after_deletion_item.bin",ios::binary| ios::app);
                        
                        after_deletion_quetta.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        after_deletion_quetta.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                        // after_deletion_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                        int s = ss.size();
                        after_deletion_quetta.write((char *)&s, sizeof(s));
                        const char *temp = ss.c_str();
                        after_deletion_quetta.write(temp, strlen(temp));

                        // after_deletion_quetta.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int q=items_in_islamabad.size();
                        // after_deletion_quetta.write((char *)&q, sizeof(q));
                        // const char*str1=items_in_islamabad.c_str();
                        // after_deletion_quetta.write(str1,strlen(str1));

                        // after_deletion_pindi.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int p=items_in_islamabad.size();
                        // after_deletion_pindi.write((char *)&p, sizeof(p));
                        // const char*str2=items_in_islamabad.c_str();
                        // after_deletion_pindi.write(str2,strlen(str2));

                        // after_deletion_balochistan.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int b=items_in_islamabad.size();
                        // after_deletion_balochistan.write((char *)&b, sizeof(b));
                        // const char*str3=items_in_islamabad.c_str();
                        // after_deletion_balochistan.write(str3,strlen(str3));

                        // after_deletion_peshawar.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        // int pe=items_in_islamabad.size();
                        // after_deletion_peshawar.write((char *)&pe, sizeof(pe));
                        // const char*str4=items_in_islamabad.c_str();
                        // after_deletion_peshawar.write(str4,strlen(str4));
                    }
                    //
                }

                quetta_file.close();
                // pindi_file.close();
                // quetta_file.close();
                // balochistan_file.close();
                // peshawar_file.close();

                after_deletion_quetta.close();
                // after_deletion_balochistan.close();
                // after_deletion_peshawar.close();
                // after_deletion_quetta.close();
                // after_deletion_pindi.close();

                remove("items_quetta.bin");

                // remove("items_quetta.bin");
                // remove("items_peshawar.bin");
                // remove("items_balochistan.bin");
                // remove("items_pindi.bin");

                rename("after_deletion_quetta.bin","items_quetta.bin");

                break;
            }

            case 3:
            {
                string str;
                cout << "Enter the item name that you want to delete: ";
                cin >> str;
                    fstream islamabad_file("items_peshawar.bin", ios::binary|ios::in|ios::out);
                                    
                    ofstream after_deletion_islamabad("after_deletion_peshawar.bin",ios::binary| ios::app);
                                    
                    while (!islamabad_file.eof())
                                    {
                    islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                    int s = 0;
                    islamabad_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    islamabad_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    //cout << ss << endl;
                    //cout << str << endl << endl;
                    if (ss != str)
                    {
                        cout << "STR::: " << ss << endl;
                        
                        
                        after_deletion_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        after_deletion_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                        // after_deletion_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                        int s = ss.size();
                        after_deletion_islamabad.write((char *)&s, sizeof(s));
                        const char *temp = ss.c_str();
                        after_deletion_islamabad.write(temp, strlen(temp));

                        
                    }
                    //
                }

                islamabad_file.close();
                // pindi_file.close();
                // quetta_file.close();
                // balochistan_file.close();
                // peshawar_file.close();

                after_deletion_islamabad.close();
                // after_deletion_balochistan.close();
                // after_deletion_peshawar.close();
                // after_deletion_quetta.close();
                // after_deletion_pindi.close();

                remove("items_peshawarbin");

                // remove("items_quetta.bin");
                // remove("items_peshawar.bin");
                // remove("items_balochistan.bin");
                // remove("items_pindi.bin");

                rename("after_deletion_peshawar.bin","items_peshawar.bin");

                break;
            }

            case 4:
            {
                string str;
                cout << "Enter the item name that you want to delete: ";
                cin >> str;
                fstream islamabad_file("items_balochistan.bin", ios::binary|ios::in|ios::out);
                ofstream after_deletion_islamabad("after_deletion_balochistan.bin",ios::binary| ios::app);
                while (!islamabad_file.eof())
                {
                    islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                    int s = 0;
                    islamabad_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    islamabad_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    //cout << ss << endl;
                    //cout << str << endl << endl;
                    if (ss != str)
                    {
                        cout << "STR::: " << ss << endl;
                        
                        
                        after_deletion_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        after_deletion_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                        // after_deletion_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                        int s = ss.size();
                        after_deletion_islamabad.write((char *)&s, sizeof(s));
                        const char *temp = ss.c_str();
                        after_deletion_islamabad.write(temp, strlen(temp));

                        
                    }
                    //
                }

                islamabad_file.close();
                

                after_deletion_islamabad.close();

                remove("items_balochistan.bin");

                rename("after_deletion_balochistan.bin","items_balochistan.bin");

                break;
            }

            case 5:
            {
                string str;
                cout << "Enter the item name that you want to delete: ";
                cin >> str;
                fstream islamabad_file("items_pindi.bin", ios::binary|ios::in|ios::out);
                ofstream after_deletion_islamabad("after_deletion_pindi.bin",ios::binary| ios::app);
                while (!islamabad_file.eof())
                    {
                    islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                    int s = 0;
                    islamabad_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    islamabad_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    //cout << ss << endl;
                    //cout << str << endl << endl;
                    if (ss != str)
                    {
                        cout << "STR::: " << ss << endl;
                        after_deletion_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                        after_deletion_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                        // after_deletion_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                        int s = ss.size();
                        after_deletion_islamabad.write((char *)&s, sizeof(s));
                        const char *temp = ss.c_str();
                        after_deletion_islamabad.write(temp, strlen(temp));
                    }
                }

                islamabad_file.close();
                after_deletion_islamabad.close();
                remove("items_pindibin");
                rename("after_deletion_pindi.bin","items_pindi.bin");

                break;
            }
        }
    }

    void update_item()
    {
        switch (location)
        {
        case 1:
        {
            Product_Catalog temp;
            string str;
            cout << "Enter item name you want to Update: ";
            cin >> str;
            fstream islamabad_file("items_islamabad.bin", ios::binary | ios::in | ios::out);
            // fstream quetta_file("items_quetta.bin", ios::binary);
            // fstream peshawar_file("items_peshawar.bin", ios::binary);
            // fstream balochistan_file("items_balochistan.bin", ios::binary);
            // fstream pindi_file("items_pindi.bin", ios::binary);

            ofstream after_update_islamabad("after_update_islamabad.bin",ios::binary| ios::app);
            // ofstream after_deletion_quetta("after_deletion_quetta.bin",ios::binary| ios::app);
            // ofstream after_deletion_peshawar("after_deletion_peshawar.bin",ios::binary| ios::app);
            // ofstream after_deletion_pindi("after_deletion_pindi.bin",ios::binary| ios::app);
            // ofstream after_deletion_balochistan("after_deletion_balochistan.bin",ios::binary| ios::app);
            while (!islamabad_file.eof())
            {
                islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                //islamabad_file.read((char *)&no_of_items, sizeof(no_of_items));
                int s = 0;
                islamabad_file.read((char *)&s, sizeof(s));
                if (s == 0)
                    break;
                char *temp = new char[s + 1];
                islamabad_file.read(temp, s);
                temp[s] = '\0';
                string ss = temp;
                cout<<"File name: "<<ss<<endl;
                cout<<"My name: "<<str<<endl<<endl;
                if (ss == str)
                {
                    cout<<"STR:  "<<ss<<endl;
                    cout << "Enter new name: ";
                    cin >> items_in_islamabad;
                    cout << "Enter new price: ";
                    cin >> price_in_islamabad;
                    cout<<"Enter new item code: ";
                    cin>>itemcode_in_islamabad;
                    // cout<<"Enter new item quantity: ";
                    // cin>>no_of_items;
                    after_update_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    after_update_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                    int se = items_in_islamabad.size();
                    after_update_islamabad.write((char *)&se, sizeof(se));
                    const char *temp = items_in_islamabad.c_str();
                    after_update_islamabad.write(temp, strlen(temp));
                }

                else
                {
                    after_update_islamabad.write((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    after_update_islamabad.write((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // after_update_islamabad.write((char *)&no_of_items, sizeof(no_of_items));
                    after_update_islamabad.write((char *)&s, sizeof(s));
                    after_update_islamabad.write(temp, strlen(temp));
                }
            }
            islamabad_file.close();
            after_update_islamabad.close();
            remove("items_islamabad.bin");
            rename("after_update_islamabad.bin","items_islamabad.bin");
            break;
            }
        }
    }

    void set_number_of_items()
    {
        string str;
        cout<<"Enter the item name: ";
        cin>>str;

        cout<<"Set the number of items present in the catalog: ";
        cin>>no_of_items;

    }
};
class Payment;

//******************ONLINE PAYMENT*******************
class OnlineShopping : public Product_Catalog
{
protected:
    Customer cust;
    int choices;
    static double total;
    int location;
    int kilo, dozen;
    static int size;
    // ofstream cust_file;
public:
    OnlineShopping()
    {
    }

    const int chicken = 120;
    const int beef = 400;
    const int mutton = 350;
    const int fish = 200;

    const int milk = 110;
    const int eggs = 105;
    const int yougurt = 80;
    const int cheese = 120;

    const int apple = 200;
    const int banana = 180;
    const int mango = 300;
    const int orange = 250;
    const int watermelon = 200;

    const int tomato = 280;
    const int onion = 160;
    const int cucumber = 100;
    const int potatoes = 100;

    const int chocolate = 80;
    const int chips = 50;
    const int biscuits = 40;

    const int spices = 60;

    const int lentils = 100;
    const int wheat = 500;
    const int flour = 200;
    const int rice = 300;

    const int cereal = 200;

    const int shampoo = 120;
    const int soap = 60;
    const int hand_sanitizer = 110;

    const int detergent = 60;
    const int dish_soap = 60;
    const int washroom_cleaner = 130;
    static string cart[100];
    int add;
    static bool locatio;
    bool add_to_cart(string name, int p, int c, int addre)
    { 
        cout<<"\nHow many quantity of "<<name<<" do you want: ";
        cin>>kilo;
        cart[size]=name+": "+to_string(kilo);
        size++;
        total+=p*kilo;

        cout << "\n\n*****TOTAL= " << total << "*****\n";
        for (int k = 0; k < size; k++)
        {
            cout << cart[k] << endl;
        }
        cout << endl;
        if(addre!=location)
        locatio=false;

        OnlineShopping O;
        displayitems(O);
        return true;
    }

    // double OnlineShopping::total=0;

    void setlocationforcust(int loc)
    {
        location = loc;
        cout << "LOCATION: " << location << endl;
        OnlineShopping O;
        displayitems(O);
    }
    void displayitems(OnlineShopping O)
    {
        bool n;
        int count=0;
        int i=1;
        cout<<"Do you want to keep Shopping\n1. Yes\n2. No\n";
        cin>>i;
        cout << "\nThe items are listed below:\n ";
        switch(i)
        {
            case 1:
            {

            switch (location)
            {
            case 1:
            {
                
                cout << "\n******DISPLAYING ITEMS OF ISLAMABAD******\n";
                ifstream islamabad_file("items_islamabad.bin", ios::binary);
                while (!islamabad_file.eof())
                {
                    // cout<<"***********************"<<endl;
                    islamabad_file.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    islamabad_file.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // cout<<price_in_islamabad;
                    int s = 0;
                    islamabad_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    islamabad_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    cout << "ITEM: " << ss << endl;
                    cout << "Price: " << price_in_islamabad << endl; //[count_items_islamabad]<<endl;
                    cout << "Item Code: " << itemcode_in_islamabad << endl
                        << endl;
                }
                islamabad_file.close();

                string code;
                cout << "Select the item name to put in cart: ";
                cin >> code;
                ifstream add_in_cart("items_islamabad.bin", ios::binary);
                while (!add_in_cart.eof())
                {
                    // cout<<"***********************"<<endl;
                    add_in_cart.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    add_in_cart.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // cout<<price_in_islamabad;
                    int s = 0;
                    add_in_cart.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    add_in_cart.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
                    transform(code.begin(), code.end(), code.begin(), ::toupper);
                    if(ss==code)
                    {
                    //cart[size]=ss;
                    string temp;
                    int price;
                    int code;
                    temp=ss;
                    price=price_in_islamabad;
                    code=itemcode_in_islamabad;
                    add=1;
                    n=add_to_cart(temp,price,code,add);
                    count=0;
                    }
                    
                }
                if(count>=5)
                {
                    add_in_cart.close();
                    cout<<"Sorry. Your item cannot be found in any store";
                    break;
                }
                if(n!=true)
                {
                    add_in_cart.close();
                    count++;
                    setlocationforcust(2);
                    break;
                }
                add_in_cart.close();
                
                break;
            }
            case 2:
            {
                cout << "******DISPLAYING ITEMS OF QUETTA******\n";
                ifstream quetta_file("items_quetta.bin", ios::binary);
                while (!quetta_file.eof())
                {
                    quetta_file.read((char *)&price_in_quetta, sizeof(price_in_quetta));
                    quetta_file.read((char *)&itemcode_in_quetta, sizeof(itemcode_in_quetta));
                    int s = 0;
                    quetta_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    quetta_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    cout << "ITEM: " << ss << endl;
                    cout << "Price: " << price_in_quetta << endl; //[count_items_islamabad]<<endl;
                    cout << "Item Code: " << itemcode_in_quetta << endl
                        << endl;
                }
                quetta_file.close();
                string code;
                cout << "Select the item name to put in cart: ";
                cin >> code;
                ifstream add_in_cart("items_quetta.bin", ios::binary);
                while (!add_in_cart.eof())
                {
                    // cout<<"***********************"<<endl;
                    add_in_cart.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    add_in_cart.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // cout<<price_in_islamabad;
                    int s = 0;
                    add_in_cart.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    add_in_cart.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
                    transform(code.begin(), code.end(), code.begin(), ::toupper);
                    if(ss==code)
                    {
                    //cart[size]=ss;
                    string temp;
                    int price;
                    int code;
                    temp=ss;
                    price=price_in_islamabad;
                    code=itemcode_in_islamabad;
                    add=2;
                    n=add_to_cart(temp,price,code,add);
                    count=0;
                    }
                    
                    
                }
                if(count==5)
                {
                    add_in_cart.close();
                    cout<<"Sorry. Your item cannot be found in any store";
                    break;
                }
                if(n!=true)
                {
                    add_in_cart.close();
                    count++;
                    setlocationforcust(3);
                    break;
                }
                add_in_cart.close();
                break;
            }

                // cout<<"****DISPLAYING ITEMS FOR QUETTA****\n";

            case 3:
            {
                cout << "******DISPLAYING ITEMS OF PESHAWAR******\n";
                ifstream peshawar_file("items_peshawar.bin", ios::binary);
                while (!peshawar_file.eof())
                {
                    peshawar_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
                    peshawar_file.read((char *)&itemcode_in_peshawar, sizeof(itemcode_in_peshawar));
                    int s = 0;
                    peshawar_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    peshawar_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    cout << "ITEM: " << ss << endl;
                    cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
                    cout << "Item Code: " << itemcode_in_peshawar << endl
                        << endl;
                }

                peshawar_file.close();

                string code;
                cout << "Select the item name to put in cart: ";
                cin >> code;
                ifstream add_in_cart("items_peshawar.bin", ios::binary);
                while (!add_in_cart.eof())
                {
                    // cout<<"***********************"<<endl;
                    add_in_cart.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    add_in_cart.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // cout<<price_in_islamabad;
                    int s = 0;
                    add_in_cart.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    add_in_cart.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
                    transform(code.begin(), code.end(), code.begin(), ::toupper);
                    if(ss==code)
                    {
                    //cart[size]=ss;
                    string temp;
                    int price;
                    int code;
                    temp=ss;
                    price=price_in_islamabad;
                    code=itemcode_in_islamabad;
                    add=3;
                    n=add_to_cart(temp,price,code,add);
                    count=0;
                    }
                    
                    
                    
                }
                if(count==5)
                {
                    add_in_cart.close();
                    cout<<"Sorry. Your item cannot be found in any store";
                    break;
                }
                if(n!=true)
                {
                    add_in_cart.close();
                    count++;
                    setlocationforcust(4);
                    break;
                }
                add_in_cart.close();
                break;
            }

            case 4:
            {
                cout << "******DISPLAYING ITEMS OF BALOCHISTAN******\n";
                ifstream balochistan_file("items_balochistan.bin", ios::binary);
                while (!balochistan_file.eof())
                {
                    balochistan_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
                    balochistan_file.read((char *)&itemcode_in_balochistan, sizeof(itemcode_in_balochistan));
                    int s = 0;
                    balochistan_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    balochistan_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    cout << "ITEM: " << ss << endl;
                    cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
                    cout << "Item Code: " << itemcode_in_balochistan << endl
                        << endl;
                }
                balochistan_file.close();

                string code;
                cout << "Select the item name to put in cart: ";
                cin >> code;
                ifstream add_in_cart("items_balochistan.bin", ios::binary);
                while (!add_in_cart.eof())
                {
                    // cout<<"***********************"<<endl;
                    add_in_cart.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    add_in_cart.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // cout<<price_in_islamabad;
                    int s = 0;
                    add_in_cart.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    add_in_cart.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
                    transform(code.begin(), code.end(), code.begin(), ::toupper);
                    if(ss==code)
                    {
                    //cart[size]=ss;
                    string temp;
                    int price;
                    int code;
                    temp=ss;
                    price=price_in_islamabad;
                    code=itemcode_in_islamabad;
                    add=4;
                    n=add_to_cart(temp,price,code,add);
                    count=0;
                    }
                    
                    
                    
                }
                if(count==5)
                {
                    add_in_cart.close();
                    cout<<"Sorry. Your item cannot be found in any store";
                    break;
                }
                if(n!=true)
                {
                    add_in_cart.close();
                    count++;
                    setlocationforcust(5);
                    break;
                }
                add_in_cart.close();
                break;
            }

            case 5:
            {
                cout << "******DISPLAYING ITEMS OF PINDI******\n";
                ifstream pindi_file("items_pindi.bin", ios::binary);
                while (!pindi_file.eof())
                {
                    pindi_file.read((char *)&price_in_peshawar, sizeof(price_in_peshawar));
                    pindi_file.read((char *)&itemcode_in_pindi, sizeof(itemcode_in_pindi));
                    int s = 0;
                    pindi_file.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    pindi_file.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    cout << "ITEM: " << ss << endl;
                    cout << "Price: " << price_in_peshawar << endl; //[count_items_islamabad]<<endl;
                    cout << "Item Code: " << itemcode_in_pindi << endl
                        << endl;
                }
                pindi_file.close();

                string code;
                cout << "Select the item name to put in cart: ";
                cin >> code;
                ifstream add_in_cart("items_pindi.bin", ios::binary);
                while (!add_in_cart.eof())
                {
                    // cout<<"***********************"<<endl;
                    add_in_cart.read((char *)&price_in_islamabad, sizeof(price_in_islamabad));
                    add_in_cart.read((char *)&itemcode_in_islamabad, sizeof(itemcode_in_islamabad));
                    // cout<<price_in_islamabad;
                    int s = 0;
                    add_in_cart.read((char *)&s, sizeof(s));
                    if (s == 0)
                        break;
                    char *temp = new char[s + 1];
                    add_in_cart.read(temp, s);
                    temp[s] = '\0';
                    string ss = temp;
                    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
                    transform(code.begin(), code.end(), code.begin(), ::toupper);
                    if(ss==code)
                    {
                    //cart[size]=ss;
                    string temp;
                    int price;
                    int code;
                    temp=ss;
                    price=price_in_islamabad;
                    code=itemcode_in_islamabad;
                    add=5;
                    n=add_to_cart(temp,price,code,add);
                    count=0;
                    }
                    
                    
                    
                }
                if(count==5)
                {
                    add_in_cart.close();
                    cout<<"Sorry. Your item cannot be found in any store";
                    break;
                }
                if(n!=true)
                {
                    add_in_cart.close();
                    count++;
                    setlocationforcust(1);
                    break;
                }
                add_in_cart.close();
            
                break;
            }
                break;
            }
        }
        case 2:
        {
            break;
        }
        }
        

        // int custch;
        // cout<<"What do you want: \n1. Perishable Goods\n2. Non-Perishable Goods\n3. Personal Hygeine\n4. Household Cleaning\n5. Show Cart\n";
        // cin>>custch;
        // switch(custch)
        // {
        //     int itemtype;
        //     int itemch;
        //     case 1:
        //     {
        //         cout<<"\n1. Meat\n2. Dairy\n3. Fruit\n4. Vegetable\n";
        //         cin>>itemtype;
        //         switch(itemtype)
        //         {
        //             case 1:
        //             {
        //                 cout<<"\n1. Chicken\n2. Beef\n3. Mutton\n4. Fish\n5. Go Back\n";
        //                 cin>>itemch;
        //                 if(itemch==5)
        //                 displayitems(O);
        //                 else
        //                 {
        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);
        //                 }
        //                 break;
        //             }

        //             case 2:
        //             {
        //                 cout<<"\n1. Milk\n2. Eggs\n3. Yougurt\n4. Cheese\n5. Go Back\n";
        //                 cin>>itemch;
        //                 if(itemch==5)
        //                 displayitems(O);
        //                 else
        //                 {
        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);
        //                 }
        //                 break;
        //             }

        //             case 3:
        //             {
        //                 cout<<"\n1. Apple\n2. Banana\n3. Mango\n4. Orange\n4. Watermelon\n5. Go Back\n";
        //                 cin>>itemch;
        //                 if(itemch==5)
        //                 displayitems(O);
        //                 else
        //                 {
        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);
        //                 }
        //                 break;
        //             }

        //             case 4:
        //             {
        //                 cout<<"\n1. Tomato\n2. Onion\n3. Cucumber\n4. Potatoes\n5. Go Back\n";
        //                 cin>>itemch;
        //                 if(itemch==5)
        //                 displayitems(O);
        //                 else
        //                 {
        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);
        //                 }
        //                 break;
        //             }
        //         }
        //         break;
        //     }

        //     case 2:
        //     {
        //         cout<<"\n1. Snacks\n2. Spices\n3. Grains\n4. Cereal\n5. Go Back\n";
        //         cin>>itemtype;
        //         switch(itemtype)
        //         {
        //             case 1:
        //             {
        //                 cout<<"\n1. Chocolates\n2. Chips\n3. Biscuits\n4. Go Back\n";
        //                 cin>>itemch;
        //                 if(itemch==4)
        //                 displayitems(O);
        //                 else
        //                 {
        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);
        //                 }
        //                 break;
        //             }

        //             case 2:
        //             {

        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);

        //                 break;
        //             }
        //             case 3:
        //             {
        //                 cout<<"\n1. Lentils\n2. Wheat\n3. Flour\n4. Rice\n5. Go Back\n";
        //                 cin>>itemch;
        //                 if(itemch==5)
        //                 displayitems(O);
        //                 else
        //                 {
        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);
        //                 }
        //                 break;
        //             }

        //             case 4:
        //             {
        //                 add_to_cart(O,custch,itemtype,itemch);
        //                 displayitems(O);

        //                 break;
        //             }
        //             case 5:
        //             {
        //                 displayitems(O);
        //             }
        //         }
        //         break;
        //     }

        //     case 3:
        //     {
        //         cout<<"\n1. Shampoo\n2. Soap\n3. Hand Sanitizer\n4. Go Back\n";
        //         cin>>itemch;
        //         if(itemch==4)
        //         displayitems(O);
        //         else
        //         {
        //         add_to_cart(O,custch,itemtype,itemch);
        //         displayitems(O);
        //         }
        //         break;
        //     }

        //     case 4:
        //     {
        //         cout<<"\n1. Detergent\n2. Dish Soap\n3. Washroom Cleaner\n4. Go Back\n";
        //         cin>>itemch;
        //         if(itemch==4)
        //         displayitems(O);
        //         else
        //         {
        //         add_to_cart(O,custch,itemtype,itemch);
        //         displayitems(O);
        //         }
        //         break;
        //     }

        //     case 5:
        //     {
        //         break;
        //     }

        // }
    }
};
int OnlineShopping::size = 0;
string OnlineShopping::cart[] = {"0"};
double OnlineShopping::total = 0;
bool OnlineShopping::locatio=false;
class Payment : public OnlineShopping
{
protected:
    OnlineShopping payment;
    int delivery;

public:
    char str[200];
    Payment() {}

    void delivery_reciept()
    {
        cout << "\nYour reciept is: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << cart[i] << endl;
        }
        
        cout << "\n\nYour total is: "<<total<<endl;
        
        
    }
    void delivery_type(bool add)
    {

        cout << "How do you want to pay for the items: ";
        cout << "\n1. Cash on delivery\n2. Master Card\n3. Easy Paisa\n4. Jazz Cash\n";
        cin >> delivery;
        switch (delivery)
        {
        case 1:
        {
            if(add==false)
            {
            cout<<" Your total is with 50Rs. Delivery Charges: "<<total+50<<endl;
            }
            else
            {
                cout<<" Your total is with 30Rs. Delivery Charges: "<<total+30<<endl;
            }
            cout << "Thankyou for ordering. Your item will be at to your door steps in approximately 2 hours.\n\n";
            break;
        }

        case 2:
        {
            double card_number;
            int exp_day, exp_month, cvc;
            cout << "\nEnter you card number: ";
            cin >> card_number;
            cout << "Enter Expiry Day: ";
            cin >> exp_day;
            cout << "Enter Expiry Month: ";
            cin >> exp_month;
            cout << "Enter CVC Number: ";
            cin >> cvc;
            cout << "Processing...\n";
            cout << "\nYour transaction has been successfully done.\n\nThankyou for ordering. Your item will be at to your door steps in approximately 2 hours.\n\n";
            break;
        }

        case 3:
        {
            double acc_num;
            int confirmation;
            cout << "Enter your Easy Paisa account number: ";
            cin >> acc_num;
            cout << "Enter the confirmation number (123): ";
            cin >> confirmation;
            while (confirmation != 123)
            {
                cout << "Incorrect confirmation number has been sent!\n";
                cout << "Enter the confirmation number (123): ";
                cin >> confirmation;
            }
            cout << "Processing...\n";
            cout << "\nYour transaction has been successfully done.\n\nThankyou for ordering. Your item will be at to your door steps in approximately 2 hours.\n\n";
            break;
        }

        case 4:
        {
            double acc_num;
            int confirmation;
            cout << "Enter your Jazz Cash account number: ";
            cin >> acc_num;
            cout << "Enter the confirmation number (123): ";
            cin >> confirmation;
            while (confirmation != 123)
            {
                cout << "Incorrect confirmation number has been sent!\n";
                cout << "Enter the confirmation number (123): ";
                cin >> confirmation;
            }
            cout << "Processing...\n";
            cout << "\nYour transaction has been successfully done.\n";
            break;
        }
        }

        total = 0;
        size = 0;
        for (int i = 0; i < size; i++)
        {
            cart[i] = "";
        }

        
    }

    void setfeedback(string feed)
    {
        strcpy(str, feed.c_str());
        Payment obj;
        ofstream cust("Feedback.bin", ios::binary);
                        if (cust.write((char *)&obj, sizeof(obj)))
                            cout << "Your Feedback has been recorder!" << endl;
                        else
                            cout << "Object Insertion Failed" << endl;
                        cust.close();
    }
};

class StoreCheckout{
    private:
    Payment p;
    float cashire;
    int no_items;
    int choice;
    int lane;
    int nolane;
    public:
    void cas_payment()
    {

    }

    void cheque_payment()
    {

    }

    void debit_card()
    {

    }


};

class Counter:public StoreCheckout
{
    private:
    
    int no_o_cus;;
    int no_counters;
    public:
    void counter()
    {

    }

    void avaliablity()
    {

    }
};