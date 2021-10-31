#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include <cstdlib>

//#define seat 10

using namespace std;

fstream tr; //Train en

void clrscr()
{
    system("cls"); // Clears terminal window
}

void superMenu();
float train[20];
float firstClssFare[20];
float secondClassFare[20];
float thirdClassFare[20];
float AcClassFare[20];
float TvClassFare[20];
float FoodClassFare[20];
bool duplicateCheck[20];
char trainName[20][50];
char trainBoardingPoint[20][50];
char trainDestinationPoint[20][50];
int seat[20];

class Load{
public:
void load()
{
    memset(train, 0, sizeof(train));
    memset(seat, 0, sizeof(seat));
     memset(firstClssFare, 0, sizeof(firstClssFare));
    memset(thirdClassFare, 0, sizeof(thirdClassFare));
    memset(secondClassFare, 0, sizeof(secondClassFare));
     memset(AcClassFare, 0, sizeof(AcClassFare));
     memset(TvClassFare,0,sizeof(TvClassFare));
      memset(FoodClassFare, 0, sizeof(FoodClassFare));
    memset(trainName, '\0', sizeof(trainName));
    memset(trainBoardingPoint, '\0', sizeof(trainBoardingPoint));
    memset(trainDestinationPoint, '\0', sizeof(trainDestinationPoint));
    memset(duplicateCheck, false, sizeof(duplicateCheck));

    tr.open("train123.txt ", ios::in);

    if(tr.is_open())
    {

        for(int i=0; !tr.eof(); i++) // tr != eof
        {
            int tempID, firstfare1, secondFare2, thirdFare3,acfare,tvfare,foodfare,tempSeat;
            char tempName[50];
            char tempBording[50];
            char tempDesti[50];

tr >> tempID >> firstfare1 >> secondFare2 >> thirdFare3 >> acfare >> tvfare >> foodfare >> tempSeat >> tempName >> tempBording >> tempDesti;

            duplicateCheck[tempID] = true;

            firstClssFare[tempID] = firstfare1; //First class fare
            secondClassFare[tempID] = secondFare2; // Second Class fare
            thirdClassFare[tempID] = thirdFare3; //Third class fare
            AcClassFare[tempID]=acfare;
            TvClassFare[tempID]=tvfare;
            FoodClassFare[tempID]=foodfare;
            seat[tempID] = tempSeat; //Seat number per train
            strcpy(trainBoardingPoint[tempID],tempBording);
            strcpy(trainDestinationPoint[tempID],tempDesti);
            strcpy(trainName[tempID], tempName);


        }

        tr.close();
    }

    else
    {

        cout << "Error Opening file" << endl;
        exit(1);

    }
}
};
class Unload{
public:
void unload()
{
    tr.open("train123.txt", ios::out);

    if(tr.is_open())
    {
        for(int i=0; i < 20; i++)
        {
            if(duplicateCheck[i] == false)
                continue;

            tr << endl << i << " " << firstClssFare[i] << " "  << secondClassFare[i] << " " << thirdClassFare[i] << " "
             <<AcClassFare[i]<<" "<<TvClassFare[i]<<" "<<FoodClassFare[i]<<" "
             << seat[i] << " " << trainName[i] << " " << trainBoardingPoint[i] << " " << trainDestinationPoint[i];

        }

        tr.close();

    }
    else
    {

        cout << "Error opening file in unload function" << endl;
        exit(1);

    }

}
};

class Add_detail
{
protected:
    int train_no, numOfSeat;
    char train_name[80],boarding[80],destination[80];
    string clas;
    float fare_per_F,fare_per_S,fare_per_T,fare_per_Ac,fare_per_Tv,fare_per_food;
public:
    void Add_data(){


        while(1)
        {
            system("cls");
            system("COLOR 3E");


            cout<<"                              Insert Add details "<<endl;
            cout<<"                          **************************"<<endl;
            cout<<endl<<" Enter train no. ";
            cin>>train_no;

            if(duplicateCheck[train_no] == true)
            {
                cout << "This id has been used. Try again. "<< endl;
                system("PAUSE");
                continue;
            }

            cout<<endl<<"Enter train name ";
            cin>>train_name;
            cout<<endl<<"Enter boarding point ";
            cin>>boarding;
            cout<<endl<<"Enter destination point: ";
            cin>>destination;
            cout<<endl<<"Enter first class fare per ticket: ";
            cin>>fare_per_F;
            cout<<endl<<"Enter second class fare per ticket: ";
            cin>>fare_per_S;
            cout<<endl<<"Enter third class fare per ticket: ";
            cin>>fare_per_T;
            cout<<endl<<"Enter Ac class fare per ticket: ";
            cin>>fare_per_Ac;
            cout<<endl<<"Enter Tv class fare per ticket: ";
            cin>>fare_per_Tv;
            cout<<endl<<"Enter food class fare per ticket: ";
            cin>>fare_per_food;
            cout << endl << "How many seat does the train has? ";
            cin >> numOfSeat;

            duplicateCheck[train_no] = true;
             seat[train_no] = numOfSeat;
            firstClssFare[train_no] = fare_per_F;
            secondClassFare[train_no] = fare_per_S;
            thirdClassFare[train_no] = fare_per_T;
            AcClassFare[train_no]=fare_per_Ac;
            TvClassFare[train_no]=fare_per_Tv;
            FoodClassFare[train_no]=fare_per_food;
            strcpy(trainName[train_no], train_name);
            strcpy(trainBoardingPoint[train_no], boarding);
            strcpy(trainDestinationPoint[train_no], destination);

            int data;


            cout << "Do you want to add more details? (yes = 0, no =1) ?" << endl;
            cin >> data;

            if(data == 1)
                break;
            else
                continue;

        }

    }

void display_AddDetail()
{
    int data;

    while(1)
    {

        cout << "Enter train no : ";

        cin >> data;

        if(duplicateCheck[data] == true)
        {
            cout << "                              Train name: " << trainName[data] << endl;

            cout << "                              Train first class fare : " << firstClssFare[data] << endl;
            cout << "                              Train Second class fare: " << secondClassFare[data] << endl;
            cout << "                              Train first class fare : " << thirdClassFare[data] << endl;
            cout << "                              Train Ac class fare    : " << AcClassFare[data]<<endl;
            cout << "                              Train Tv class fare    : " << TvClassFare[data]<<endl;
            cout << "                              Train Food class fare  : " << FoodClassFare[data]<<endl;
            cout << "                              Available seat no: " << seat[data] << endl;
        }
        else
        {
            cout << "No train found" << endl;
            system("PAUSE");
        }

        int num;

        cout << "Do you wanna see more?(Yes = 1, No = 0) ";
        cin >> num;

        if(num == 1)
        {
            continue;
        }
        else
            break;
    }

}
};
class Managment{
public:
    void management()
    {
         system("COLOR 2F");

        cout << "1) Change or modify the name of the train" << endl;
        cout << "2) Change or modify the fare of train" << endl;
        cout << "3) Change or modify the seat number of trains" << endl;
        cout << "4) Return to menu"<<endl;

        int data;
        cout<<"Enter your choice: ";
        cin >> data;

        switch(data)
        {
        case 1:
            changeName();
            break;
        case 2:
            changeFare();
            break;

        case 3:
            changeSeat();
            break;
        case 4:
            return ;
            break;
        }
    }


    void changeSeat()
    {
        while(1)
        {
            cout << "Enter the train number: " << endl;

            int tempTrainId;

            cin >> tempTrainId;

            if(duplicateCheck[tempTrainId] == false || tempTrainId >= 20)
            {
                cout << "This train does not exists" << endl;
                system("PAUSE");
                management();
            }
            else
            {

                cout << "Here is the train Name: " << trainName[tempTrainId] << endl;

                cout << "Here are current seat numbers: " << seat[tempTrainId] << endl;

                cout << "Enter new seats: ";

                int seats;

                cin >> seats;

                seat[tempTrainId] += seats;

                cout << "Congratulations!!!!" << endl;

                cout << "New seat numbers are: " << seat[tempTrainId] << endl;

                int n;

                cout << "Do you wanna stay? (yes == 0, no == 1)" << endl;

                cin >> n ;

                if(n == 1) return;
                else {
                        clrscr();
                        continue;
                }
            }
        }

    }

    void changeName()
    {
        while(1)
        {
            cout << "Enter the train number: " << endl;

            int tempTrainId;

            cin >> tempTrainId;

            if(duplicateCheck[tempTrainId] == false || tempTrainId >= 20)
            {
                cout << "This train does not exists" << endl;
                system("PAUSE");
                management();
            }
            else
            {

                cout << "Here is the current Name: " << trainName[tempTrainId] << endl;

                cout << "Enter new name: ";

                char tempName[20];

                cin >> tempName;

                strcpy(trainName[tempTrainId], tempName);

                cout << "Congratulations!!!!" << endl;


                int n;

                cout << "Do you wanna stay? (yes == 0, no == 1)" << endl;

                cin >> n ;

                if(n == 1) return;
                else {
                        clrscr();
                        continue;
                }
            }
        }
    }

    void changeFare()
    {
        while(1)
        {
            cout << "Enter the train number: " << endl;

            int tempTrainId;

            cin >> tempTrainId;

            if(duplicateCheck[tempTrainId] == false || tempTrainId >= 20){
                cout << "This train does not exists" << endl;
                system("PAUSE");
                management();
            }

            cout << "Here are the current fares," << endl;
            cout << "First class : " << firstClssFare[tempTrainId] << endl;
            cout << "Second class: " << secondClassFare[tempTrainId] << endl;
            cout << "Third class : " << thirdClassFare[tempTrainId] << endl;
            cout << "Ac class    : " <<AcClassFare[tempTrainId]<<endl;
            cout << "Tv class    : " <<TvClassFare[tempTrainId]<<endl;
            cout << "Food class  : " <<FoodClassFare[tempTrainId]<<endl;
            cout << "Enter new fares: ";

            float tempFare[6];

            for(int i=0; i<6; i++)
            cin >> tempFare[i];

            firstClssFare[tempTrainId] = tempFare[0];
            secondClassFare[tempTrainId] = tempFare[1];
            thirdClassFare[tempTrainId] = tempFare[2];
            AcClassFare[tempTrainId]=tempFare[3];
            TvClassFare[tempTrainId]=tempFare[4];
            FoodClassFare[tempTrainId]=tempFare[5];

            cout << "Congratulations!!!!" << endl;

            int n;

            cout << "Do you wanna stay? (yes == 0, no == 1)" << endl;

            cin >> n ;

            if(n == 1) return ;
            else continue;
        }
    }
};

class Admin:public Add_detail,public Managment
{
protected:
    int option;
    int chose;
    string pass,name;
public:


    //friend void superMenu();

    void admin_mode()
    {
        system("cls");
        system("COLOR 4F");  //4=red , F=white
        string password="*****";
        cout<<endl<<endl<<endl;
        cout<<"                            LOGIN SCREEN\n";
        cout<<"             ________________________________________________  "<< endl;
        cout<<"                          1.Admin Login\n";
        cout<<"                          2.Exit\n";
        cout<<"Enter your choice: ";
        cin>>chose;
        if(chose ==1)
        {
            cout<<"    @@@!!Administration Access!!@@@ "<<endl;
            cout<<"   -------------------- "<<endl;
            cout<<"1.Login\n"<<endl ;
              cout<<"USER NAME: ";
             cin>>name;
            cout<<"PASSWORD: ";
            cin>>pass;
            if(pass==password)
            {
                cout<<password;
                cout<<"*****ACCESS GRANTED*****"<<endl;
                admin_menu();
            }
            else
            {
                cout<<"PASSWORD INCORRECT! PLEASE TRY AGAIN! "<<endl;
                cout<<endl;

                system("PAUSE");
                superMenu();
            }
        }
        else if(chose==2)
        {
            superMenu();
        }
    }

    void admin_menu()
    {
        system("COLOR 2F");
        do
        {
            cout<<endl;
            cout<<"                       ------------------ administration mode ----------------------"<<endl;
            cout<<"                       *************************************************************"<<endl<<endl;
            cout<<"                                         1.Add details"<<endl;
            cout<<"                                         2.Display details"<<endl;
            cout<<"                                         3.Management"<<endl;
            cout<<"                                         4.Return menu"<<endl;
            cout<<"Enter a option ";
            cin>>option;
            switch(option)
            {

            case 1:
                system("cls");
                Add_data();
                break;
            case 2:
                system("cls");
                system("COLOR 9F");
                cout<<"\n                               -----------------Add details--------------"<<endl;
                cout<<"\n                               ******************************************"<<endl;
                display_AddDetail();
                cout<<"\n                                *********************************************"<<endl;
                cout<<"                                               END OF ADD DETAILS              "<<endl;
                cout<<"                                *********************************************"<<endl;
                break;
            case 3:
                system("cls");
               Managment::management();
                break;
            case 4:
                superMenu();
                break;
            }
        }
        while(option!=4);

    }
};

class type_one
{
private:
    int choice;
public:
    void  first_class()
    {
        cout<<"                                         1.1st class facilities"<<endl;
        cout<<"                                           1.Air Cooler"<<"    2.First Aid"<<"    3.Newspaper"<<endl;
    }
    void second_class()
    {
        cout<<"                                         2.2nd class facilities"<<endl;
        cout<<"                                           1.Fan"<<"    2.First Aid"<<"    3.Hand-wash"<<endl;
    }
    void third_class()
    {
        cout<<"                                         3.3rd class facilities"<<endl;
        cout<<"                                           1.Proper ventilation system"<<"    2.First Aid"<<"    3.Water"<<endl;
    }
    void AC()
    {
        cout<<"                                         4.AC facilities"<<endl;
        cout<<"                                           1.Buffet"<<"    2.Good servicer"<<"    3.Wi-Fi"<<endl;
    }
};

class type_two
{

public:
    void Food()
    {
        cout<<"                                         5.Food facilities"<<endl;
        cout<<"                                           1.Chinese"<<"    2.Indian"<<"    3.Bengali"<<endl;
    }
};
class type_three
{
public:
    void TV()
    {
        cout<<"                                         6.TV facilities "<<endl;
        cout<<"                                           1.LED"<<"    2.LCD"<<"    flat screen"<<endl;
    }
};
class type_four
{
};

class Types:public type_one,public type_two,public type_three
{
protected:
    int choice;
    int cls,cl;
public:
    void choosetype()
    {
        cout<<"enter your required type: ";
        cout<<"1.type-1 "<<"/"<<"2.type-2 "<<"/"<<"3.type-3 "<<"/"<<"4.type-4 "<<" : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            type_one::first_class();
            type_one::second_class();
            type_one::third_class();
            type_one::AC();
            cout<<"enter the class you want from showing category: ";
            cin>>cls;
            if(cls==1)
            {
                type_one::first_class();
            }
            else if(cls==2)
            {
                type_one::second_class();
            }
            else if(cls==3)
            {
                type_one::third_class();
            }
            else if(cls==4)
            {
                type_one::AC();
            }
            break;
        case 2:
            type_one::first_class();
            type_one::second_class();
            type_one::third_class();
            type_one::AC();
            type_two::Food();
            cout<<"Enter the class do you want from showing category: ";
            cin>>cl;
            if(cl==1)
                type_one::first_class();
            else if(cl==2)
                type_one::second_class();
            else if (cl==3)
                type_one::third_class();
            else if(cl==4)
                type_one::AC();
            else if(cl==5)
                type_two::Food();
            break;
        case 3:
            type_one::first_class();
            type_one::second_class();
            type_one::third_class();
            type_one::AC();
            type_three::TV();
            cout<<"Enter the class do you want from showing category: ";
            cin>>cl;
            if(cl==1)
                type_one::first_class();
            else if(cl==2)
                type_one::second_class();
            else if (cl==3)
                type_one::third_class();
            else if(cl==4)
                type_one::AC();
            else if(cl==5)
                type_three::TV();
            break;
        case 4:
            type_one::first_class();
            type_one::second_class();
            type_one::third_class();
            type_one::AC();
            type_three::TV();
            cout<<"Enter the class do you want from showing category: ";
            cin>>cl;
            if(cl==1)
                type_one::first_class();
            else if(cl==2)
                type_one::second_class();
            else if (cl==3)
                type_one::third_class();
            else if(cl==4)
                type_one::AC();
            else if(cl==5)
                type_two::Food();
            else if(cl==6)
                type_three::TV();
            break;
        }
    }
    void Show_choiceT()
    {
        if(choice==1)
        {
            cout<<"                                       type one: "<<endl;
            if(cls==1)
            {
                type_one::first_class();
            }
            else if(cls==2)
            {
                type_one::second_class();
            }
            else if(cls==3)
            {
                type_one::third_class();
            }
            else if(cls==4)
            {
                type_one::AC();
            }
        }
        else if (choice==2)
        {
            cout<<"                                       type two: "<<endl;
            if(cl==1)
                type_one::first_class();
            else if(cl==2)
                type_one::second_class();
            else if (cl==3)
                type_one::third_class();
            else if(cl==4)
                type_one::AC();
            else if(cl==5)
                type_two::Food();
        }
        else if (choice==3)
        {
            cout<<"                                         type three: "<<endl;
            if(cl==1)
                type_one::first_class();
            else if(cl==2)
                type_one::second_class();
            else if (cl==3)
                type_one::third_class();
            else if(cl==4)
                type_one::AC();
            else if(cl==5)
                type_three::TV();
        }
        else if (choice==4)
        {
            cout<<"                                         type four: "<<endl;
            if(cl==1)
                type_one::first_class();
            else if(cl==2)
                type_one::second_class();
            else if (cl==3)
                type_one::third_class();
            else if(cl==4)
                type_one::AC();
            else if(cl==5)
                type_two::Food();
            else if(cl==6)
                type_three::TV();
        }
    }

};
class reservation:public Types
{
protected:
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    string clas;
    int nosr;
    int i;
    int d,m,y;
    int con;
    float amc;
public:
    void getresdet()
    {

        while(1)
        {
            system("cls");
             system("COLOR 2F");
            cout<<"Enter the details as follows\n";
            cout<<"Train no:";
            cin>>tno;

            Types::choosetype();
            cout<<"No of seats required:";
            cin>>nosr;

            if(seat[tno] < nosr)
            {
                cout << "Not enough seats available" << endl;
                system("PAUSE");
                clrscr();
                superMenu();
            }
            else
            {
                seat[tno] -= nosr;
            }

            for(i=0; i<nosr; i++)
            {
                cout<<"Passenger name:";
                cin>>pname[i];
                cout<<"Passenger age:";
                cin>>age[i];
            }
            cout<<"enter the class you selected(First/Second/Third/Ac/Tv/Food): ";
            cin>>clas;

            if(clas=="First"|| clas=="f"|| clas=="first")
            {
                amc=firstClssFare[tno]*(nosr*1.0);
            }
            else if(clas=="Second"|| clas=="s" || clas=="second")
            {
                amc=secondClassFare[tno]*(nosr*1.0);
            }
            else if(clas=="Third"|| clas=="t" || clas=="third")
            {
                amc=thirdClassFare[tno]*(nosr*1.0);
            }
            else if(clas=="Ac"|| clas=="ac"){
                amc=AcClassFare[tno]*(nosr*1.0);
            }
            else if(clas=="Tv"|| clas=="tv"){
                amc=TvClassFare[tno]*(nosr*1.0);
            }
            else if(clas=="Food"||clas=="food"){
                amc=FoodClassFare[tno]*(nosr*1.0);
            }

            cout<<"Date of travel:";
            cin>>d>>m>>y;
            cout<<"Enter the concession category\n";
            cout<<"1.Military\n2.Senior citizen\n";
            cout<<"3.Children below 5 yrs\n4.None\n";
            cin>>con;
            cout<<"............END OF GETTING DETAILS............\n\n";
            int data;

            cout << "Do you wanna reserve more seats? (yes == 0, no == 1)" << endl;
            cin >> data;

            if(data == 1)
                break;
            else continue;


        }



    }
    void displayresdet()
    {
        system("cls");
        system("COLOR 2F");
        cout<<"                                            Reservation details"<<endl;
        cout<<"                               ...............................................\n";
        cout<<"                               ...............................................\n";
        cout<<"\n                                         Train no:"<<tno<<"     "<<"Train name: "<<trainName[tno]<<endl;;
        cout<<"                                         Boarding point: "<<trainBoardingPoint[tno]<<endl;
        cout<<"                                         Destination point: "<<trainDestinationPoint[tno]<<endl;
        cout<<"                                         The types you selected "<<endl;
        Types::Show_choiceT();
        cout<<"                                         No of seats reserved:"<<nosr<<endl;
        for(i=0; i<nosr; i++)
        {
            cout<<"                                         Passenger name: "<<pname[i]<<"     "<<"Passenger age:"<<age[i]<<endl;
        }
        cout<<"                                         Date of reservation:"<<d<<"-"<<m<<"-"<<y<<endl;
        cout<<"                                         Your concession category: "<<endl;
        if(con==1)
        {
            cout<<"                                         military "<<endl;
        }
        else if(con==2)
        {
            cout<<"                                         senior citizen"<<endl;
        }
        else if(con==3)
        {
            cout<<"                                         Children"<<endl;

        }
        else if(con==4)
        {
            cout<<"                                         None"<<endl;
        }
        cout<<"                                         You must pay:"<<amc<<endl;
        cout<<"\n                                 ***********************************************\n";
        cout<<"                                ............END OF RESERVATION.................\n";
        cout<<"                                ***********************************************\n";
    }
};
class cancellation:public reservation
{
protected:
    int tno;
    int noOfSeat;
    int nocs;
    char tname1[100];
    string clas1;
    float amount1;
public:
    void set_reservation(){
         system("COLOR 2F");
        reservation::getresdet();
    }
    void display_reservation(){
         system("COLOR 2F");
        reservation::displayresdet();
    }

    void cancel_detail()
    {


        system("cls");
        cout<<"                              ..........Canceling ticket............."<<endl;
        cout<<"                              ***************************************"<<endl;
        cout<<"train no: ";
        cin >>tno;

        if(duplicateCheck[tno] == true && tno < 20)
        {
            cout << "Enter number of seats you want to cancel? ";
            cin >> nocs;
            cout << "Enter class type: (first/second/third/ac/tv/food)";
            cin >> clas1;
            if(clas1=="f" || clas1 == "First" || clas1=="first")
            {
                amount1 = firstClssFare[tno] * (nocs);
            }
            else if(clas1=="s"  || clas1 == "Second" || clas1=="second")
            {
                amount1 = secondClassFare[tno] * (nocs);
            }
            else if(clas1=="t" || clas1 == "T" || clas1=="third")
            {
                amount1 = thirdClassFare[tno] * (nocs);
            }
               else if(clas1=="Ac"|| clas1=="ac"){
                amount1=AcClassFare[tno]*(nocs);
            }
            else if(clas1=="Tv"|| clas1=="tv"){
                amount1=TvClassFare[tno]*(nocs);
            }
            else if(clas1=="Food"||clas1=="food"){
                amount1=FoodClassFare[tno]*(nocs);
            }


            seat[tno] += nocs;
        }

        else
        {
            cout << "Train not found" << endl;
            system("PAUSE");
        }

    }


    void show_cancel_detail()
    {
        system("cls");
         system("COLOR 2F");
        cout<<"                                  ***********************************************"<<endl;
        cout<<"                                         Canceling ticket details"<<endl;
        cout<<"                                  ***********************************************"<<endl<<endl;
        cout<<"                                       No of train that canceled: "<<tno<<endl;
        cout<<"                                       Name of train that canceled: "<<trainName[tno]<<endl;
        cout<<"                                       Class that canceled: "<<clas1<<endl;
        cout<<"                                       Amount that you will have: "<<amount1<<endl;
        cout<<"                                       Remaining seats: "<<seat[tno]<<endl;
        cout<<"\n                                 ***********************************************\n";
        cout<<"                                 ............END OF CANCELING TICKET.............\n";
        cout<<"                                 ***********************************************\n";

        system("PAUSE");

    }
};
class user:public cancellation
{
protected:
    int userchoice;
    char ch;
    string pass,name;
    int chose;
public:
     void User_mode()
    {
        system("cls");
        system("COLOR 4F");  //4=red , F=white
        string password="*****";
        cout<<endl<<endl<<endl;
        cout<<"                            LOGIN SCREEN\n";
        cout<<"             ________________________________________________  "<< endl;
        cout<<"                          1.User Login\n";
        cout<<"                          2.Exit\n";
        cout<<"Enter your choice: ";
        cin>>chose;
        if(chose ==1)
        {
            cout<<"    @@@!!Administration Access!!@@@ "<<endl;
            cout<<"   -------------------- "<<endl;
            cout<<"1.Login\n"<<endl ;
              cout<<"USER NAME: ";
             cin>>name;
            cout<<"PASSWORD: ";
            cin>>pass;
            if(pass==password)
            {
                cout<<password;
                cout<<"*****ACCESS GRANTED*****"<<endl;
                select_user();
            }
            else
            {
                cout<<"PASSWORD INCORRECT! PLEASE TRY AGAIN! "<<endl;
                cout<<endl;

                system("PAUSE");
                superMenu();
            }
        }
        else if(chose==2)
        {
            superMenu();
        }
    }
    void select_user()
    {
        system("cls");
         system("COLOR 2F");
        do
        {
            cout<<endl;
            cout<<"                                        **************"<<endl;
            cout<<"                                          user mode "<<endl;
            cout<<"                                        --------------"<<endl<<endl;
            cout<<"                                        1.reservation "<<endl;
            cout<<"                                        2.cancellation" <<endl;
            cout<<"                                        3.return to the menu"<<endl;
            cout<<"enter your choice: ";
            cin>>userchoice;
            switch(userchoice)
            {
            case 1:
                system("cls");
                cancellation::set_reservation();
                cancellation::display_reservation();
                break;
            case 2:
                system("cls");
                cancellation::cancel_detail();
                cancellation::show_cancel_detail();
                break;

            case 3:
                cout<<endl;
                return;
            default:
                break;
            }
        }
        while(userchoice!=3);
    }
};



void superMenu()
{
      system("cls");
      system("COLOR 3A");
    int choice;
    char ch;
    Admin ad;
    user use;
    Unload op2;
    cout<<endl;
    cout<<"                          #########################################################"<<endl<<endl;
    cout<<"                              WELCOME TO BANGLADESH RAILWAY E-TICKETING SERVICE"<<endl<<endl;
    cout<<"                          #########################################################"<<endl<<endl;
    do
    {

        cout<<"                                             main menu"<<endl;
        cout<<"                                         ****************"<<endl;
        cout<<"                                           1.Admin mode "<<endl;
        cout<<"                                           2.user mode "<<endl;
        cout<<"                                           3.exit "<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            system("cls");
            ad.admin_mode();
            break;
        case 2:
            system("cls");
            use.User_mode();
            break;
        case 3:
            system("cls");
            op2.unload();
            exit(0);
            break;

        }
    }
    while(choice);

}



int main()
{
    Load op1;
    op1.load();
    superMenu();
    return 0;
}






