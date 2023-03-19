#include <iostream>
#include "Header.h"
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
   int userchoice;
   int admin_login=0;
   Person *a;
   while(userchoice!=5)
   {
   cout<<"\n1. Login as admin\n2. Registeration for Customer\n3. Login Customer\n4. Login as Manager\n5. Exit\nNOTE: For Registration of manager you need to login as admin.\n";
   cin>>userchoice;

   switch(userchoice)
   {
      case 1:
      {
         Admin a;
         string pass="123";
         string user="abc";
         a.setpass(pass);
         a.setuser(user);
         a.insertobj(a);
         string u,p;
         cout<<"Enter username: ";
         cin>>u;
         cout<<"Enter password: ";
         cin>>p;
         Admin temp;
         ifstream admin("Admin.bin", ios::binary);
            while (admin.read((char *)&temp, sizeof(temp)))
            {
               if (temp.getpass() == p && temp.getuser()==u)
               {
                  cout<<"\nYOU HAVE SUCCESSFULLY LOGGED IN\n";
                  admin.close();
                  cout<<"\n1. Register manager\n2. Display Product\n3. Product Catalog\n4. Show Feedbacks\n";
                  int adminch=0;
                  cin>>adminch;
                  switch(adminch)
                  {
                     case 1:
                     {
                        static int count=0;
                        Registration manager;
                        char CNIC[13];
                        cout<<"Enter CNIC number of 13 digit of manager: \n";
                        cin>>CNIC;
                        int counter=0;
                        for(int i=0;CNIC[i]!='\0';i++)
                        {
                           counter++;
                        }

                        while(counter<13)
                        {
                           cout<<"ERROR! CNIC must contain 13 digits.\nRe-Enter: ";
                           cin>>CNIC;
                           for(int i=0;CNIC[i]!='\0';i++)
                           {
                              counter++;
                           }
                           if(counter==13)
                           break;
                           else
                           continue;
                        }
                        counter=0;
                        manager.setcnic(CNIC);
                        char password[9];
                        cout<<"Enter your password: ";
                        cin>>password;
                        int uppercase=0;
                        int numeric=0;
                        for(int i=0;password[i]!='\0';i++)
                        {
                           counter++;
                           if(password[i]>47 && password[i]<58)
                           numeric++;
                           if(password[i]>=65 && password[i]<=90)
                           uppercase++;
                        }
                        while(counter<9 || numeric==0 || uppercase==0)
                        {
                           cout<<"ERROR! Password must contain 9 characters and a minimum of one uppercase letter and one numeric digit is must.\nRe-Enter: ";
                           cin>>password;
                           for(int i=0;password[i]!='\0';i++)
                           {
                              counter++;
                              if(password[i]>47 && password[i]<58)
                              numeric++;
                              if(password[i]>=65 && password[i]<=90)
                              uppercase++;
                           }
                           if(counter==9 && numeric>=1 || uppercase>=1)
                           break;
                           else
                           continue;
                        }
                        int verify=0;
                        string checkpass;
                        while(verify==0)
                        {
                           cout<<"\nRe-Enter password for checking: ";
                           cin>>checkpass;
                           if(password==checkpass)
                           verify=1;
                           else 
                           {
                              cout<<"INCORRECT! RETRY: ";
                              continue;
                           }
                        }
                        manager.setpassword(password);
                        int loc;
                        cout<<"Enter the location of the manager you want to set at: \n1. Islamabad\n2. Quetta\n3. Peshawar\n4. Balochistan\n5. Rawalpindi\n";
                        cin>>loc;
                        manager.setlocation(loc);
                        
                        manager.setaccountofManager(manager);
                        break;
                     }

                     case 2:
                     {
                        Product_Catalog p1;
                        p1.display_item_admin();
                        break;
                     }

                     case 3:
                     {
                        int choice;
                        Product_Catalog p1;
                        cout<<"Do you want to\n1. Add Item\n2. Delete item\n3. Update Item\n";
                        cin>>choice;
                        switch(choice)
                        {
                           case 1:
                           {
                              p1.add_item_admin();
                              break;
                           }
                           case 2:
                           {
                              p1.delete_item_admin();
                              break;
                           }
                           case 3:
                           {
                              p1.update_product_admin();
                              break;
                           }

                           
                        }
                        
                        break;
                     }

                     case 4:
                           {
                                 //cout<<"hello\n";
                                 Payment temp;
                                 ifstream cust("Feedback.bin", ios::binary);
                                 //cout<<"hello\n";
                                 while (cust.read((char *)&temp, sizeof(temp)))
                                 {
                                    cout<<"\n*********FEEDBACKS***********\n";
                                    cout<<temp.str<<endl;
                                 }
                                 cust.close();
                                 break;
                              
                           }
                  }
               }
               else
               {
               temp.display_error();
               }
            } 
         break;
      }

      case 3:
      {
         string cnic;
         string pass;
         cout<<"Enter CNIC: ";
         cin>>cnic;
         cout<<"Enter password: ";
         cin>>pass;
         Customer c;
         c.setCNIC(cnic);
         c.setpass(pass);
         Customer cust;
         int i;
         i=cust.customer(cnic,pass);
         if(i==true)
         {
            int custch;
            OnlineShopping O;
            Customer temp;
            cout<<"\n********WECOME!********\n";
            cout<<"1. Show menu\n2. Show Recipt\n";
            cin>>custch;
            switch(custch)
            {
               case 1:
               {
                  Registration temp;
                  ifstream manager_file("Customer.bin", ios::binary);
                  while (manager_file.read((char *)&temp, sizeof(temp)))
                  {
                     
                     manager_file.close();
                     
                  }
                  //cout<<"LOCATION: "<<temp.address<<endl;
                  O.setlocationforcust(temp.address);
                  O.displayitems(O);
                 
                  break;
               }

               case 2:
               {
                  Payment p1;
                  
                  p1.delivery_reciept();
                  p1.delivery_type(p1.locatio);
                  cout<<"\nDo you want to add some feedback on your experience\n1. Yes\n2. No\n";
                  int ch;
                  cin>>ch;
                  
                  if(ch==1)
                  {
                        //string str;
                        cout<<"\nEnter your feedback: ";
                        string feedback;
                        cin>>feedback;
                        Payment obj;
                        obj.setfeedback(feedback);
                  }
                  else
                  {
                        cout<<"\nThankyou for ordering. Your item will be at to your door steps in approximately 2 hours.\n\n";
                  }
                  break;
               }
               
            }
         }
         break;
      }

      case 2:
      {
         Registration customer;
         char CNIC[13];
         cout<<"Enter CNIC number of 13 digit: \n";
         cin>>CNIC;
         int counter=0;
         for(int i=0;CNIC[i]!='\0';i++)
         {
            counter++;
         }

         while(counter<13)
         {
            cout<<"ERROR! CNIC must contain 13 digits.\nRe-Enter: ";
            cin>>CNIC;
            for(int i=0;CNIC[i]!='\0';i++)
            {
               counter++;
            }
            if(counter==13)
            break;
            else
            continue;
         }
         counter=0;
         customer.setcnic(CNIC);
         char password[9];
         cout<<"Enter your password: ";
         cin>>password;
         int uppercase=0;
         int numeric=0;
         for(int i=0;password[i]!='\0';i++)
         {
            counter++;
            if(password[i]>47 && password[i]<58)
            numeric++;
            if(password[i]>=65 && password[i]<=90)
            uppercase++;
         }
         while(counter<9 || numeric==0 || uppercase==0)
         {
            cout<<"ERROR! Password must contain 9 characters and a minimum of one uppercase letter and one numeric digit is must.\nRe-Enter: ";
            cin>>password;
            for(int i=0;password[i]!='\0';i++)
            {
               counter++;
               if(password[i]>47 && password[i]<58)
               numeric++;
               if(password[i]>=65 && password[i]<=90)
               uppercase++;
            }
            if(counter==9 && numeric>=1 || uppercase>=1)
            break;
            else
            continue;
         }
         int verify=0;
         string checkpass;
         while(verify==0)
         {
            cout<<"\nRe-Enter password for checking: ";
            cin>>checkpass;
            if(password==checkpass)
            verify=1;
            else 
            {
               cout<<"INCORRECT! RETRY: ";
               continue;
            }
         }
         customer.setpassword(password);
         char gender;
         double phone_num;
         int address;
         cout<<"Enter gender: ";
         cin>>gender;
         cout<<"Enter phone number: ";
         cin>>phone_num;
         cout<<"Enter location: \n1. Islamabad\n2. Quetta\n3. Peshawar\n4. Balochistan\n5. Rawalpindi\n";
         cin>>address;
         customer.personalinfo(gender, phone_num, address);
         customer.setlocation(address);
         customer.setaccount(customer);

         break;
      }

      case 4:
      {
         string cnic;
         string pass;
         int manager_choice;
         cout<<"Enter your CNIC: ";
         cin>>cnic;
         cout<<"Enter your password: ";
         cin>>pass;
         Manager m1;
         m1.setpass(pass);
         m1.setCNIC(cnic);
         Manager man;
         //man.manager(cnic,pass);
         if(man.manager(cnic,pass)==true)
         {
            Inventory_Managment m1;
            cout<<"\n1. Display Items\n2. Add Item\n3. Delete Item\n4. Set Number of Items\n5. Update Item\n6. Log out\n";
            cin>>manager_choice;

            Registration temp;
            ifstream manager_file("Manager.bin", ios::binary);
            while (manager_file.read((char *)&temp, sizeof(temp)))
            {
               
               manager_file.close();
               
            }
            m1.setlocation(temp.address);
            switch(manager_choice)
            {
               case 1:
               {
                  m1.display_items();
                  break;
               }

               case 2:
               {
                  m1.add_item();
                  break;
               }

               case 3:
               {
                  m1.delete_item();
                  break;  
               }

               case 4:
               {
                  m1.set_number_of_items();
                  break;
               }

               case 5:
               {
                  m1.update_item();
                  break;
               }
               case 6:
               {
                  break;
               }
            }
         }
         break;
      }

      case 5:
      {
         cout<<"Thankyou. Have a nice day.\n";
         return 0;
      }
      
   }
   }
   return 0;
}