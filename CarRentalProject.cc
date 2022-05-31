#include <iostream>
#include <fstream>
#include <string.h>
#include<unistd.h>
#include <cctype>
#include <iomanip>
using namespace std;
void login();
void registration();
void remind();
void mainPage();
void sum();
void processingBar();
int price, mark, model, duration, totalprice, count = 0, option, totallimit = 200;
string limit;
string name;
string carmark;
string carmodel;
string carplate;
string summary;
string inovice;
string decide;
int main()
{
    system("cls");
    cout<<"\t\t\t\t\tStarting the program please wait....."<<endl;
    sleep(1);
    cout<<"\n\t\t\t\t\t\tloading up files....."<<endl;
    sleep(2);
    system("cls");
    int operation = 0;
    cout << setw(35) << ' ' << setfill ('_') << setw(57) <<'_' << setfill(' ')<< endl;
    cout<<"\n\n\t\t\t\t\t\tWelcome to CarRentProject \n\n\n";
    cout<<endl;
    cout<<"\t\t\t\t\t |Press 1 to Register"<<setw(17)<<"|"<<endl;
    cout<<"\t\t\t\t\t |Press 2 to Login"<<setw(20)<<"|"<<endl;
    cout<<"\t\t\t\t\t |Press 4 if You forgot Your password|"<<endl;
    cout <<"\t\t\t\t\t |Press 4 to exit"<<setw(21)<<"|"<<endl;
    cout<<"\t\t\t\t\t    Tell us what You want to do: ";
    cin>>operation;

    cout<<endl;
    if (operation !=4){
            system("cls");
    cout<<"\t\t\t\t\t\t  Processing"<<endl;
    processingBar();
    }
    switch(operation)
        {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            remind();
            break;
        case 4:
            system("cls");
            cout<<"\n\t\t\t\tThank you for Visiting CarRentProject.\n\t\t\t\t\tHope to see you soon"<<endl;
            exit(0);
        default:
            system("cls");
            cout<<"\t\t\t\t\tPlease select from one of above"<<endl;
            sleep(3);
            main();
        }
    }
    void registration()
    {
        string rlogin, rpassword, rlog, rpass;
        system("cls");
        cout<<"\t\t\t\t\t Login: ";
        cin>>rlogin;
        cout<<"\t\t\t\t\t Password: ";
        cin>>rpassword;
        fstream f1("credentials.txt", ios::app);
        f1<<rlogin<<' '<<rpassword<<' '<<endl;
        system("cls");
        cout<<"\t\t\t\t\t Registred succefull"<<endl;
        sleep(1);
        main();
    }
    void login()
    {
        string login, password, log, pass;
        system("cls");
        cout<<"\t\t\t\t\t Enter your Login and Password: "<<endl;
        cout<<"\t\t\t\t\t Login: ";
        cin>>login;
        cout<<"\t\t\t\t\t Password: ";
        cin>>password;
        system("cls");
        cout<<"\t\t\t\t\t Checking credentials"<<endl;
        processingBar();
        ifstream input("credentials.txt");
        while(input>>log>>pass)
        {
        if(log==login && pass==password)
            {
                count = 1;
                system("cls");
            }
        }
        input.close();

        if(count==1)
        {
            cout<<"\t\t\t\t\t\t"<<login<<"\n\t\t\t\t\t\tAccess Granted!"<<endl;
            mainPage();
        }
        else
        {
            system("cls");
            cout << "\n\n\t\t\t\t\t\tAccess Aborted...\n \t\t\t\t\t\tPlease Try Again\n\n";
            sleep(2);
            main();
        }
    }
    void remind()
        {
            system("cls");
            cout<<"\t\t\t\t |Press 1 to remind by username "<<endl;
            cout<<"\t\t\t\t |Press 2 to go back to main menu "<<endl;
            cout<<"\t\t\t\t Tell us what You want to do: ";
            cin>>option;
            cout<<endl;
            switch(option)
            {
            case 1:
                {
                string nlogin, npassword, nlog;
                cout<<" Enter your login: ";
                cin>>nlogin;

                ifstream f2("credentials.txt");
                while (f2>>nlogin>>nlog)
                {
                    if(nlogin==nlog)
                    {
                        count = 1;
                    }
                }
                f2.close();
                if(count==1)
                {
                    cout<<"\n\nWe got your account!"<<endl;
                    cout<<"\n\n Here is your password: "<<npassword;
                    main();
                }
                else{
                    cout<<"\n\n There is no account with that login";
                    main();
                }
                break;
                }
            case 2:
                cout<<"\n\nBye";
                    main();
            default:
                system("cls");
                cout<<"Please select from one of above"<<endl;
                remind();
            }
        }
     void sum()
        {
        system("cls");
                cout<<"\t\t\t\t\t\t  Summary"<<endl<<endl;
                cout<<"\n\t\t\t\t\tMark of your car is: "<<carmark<<endl;
                cout<<"\t\t\t\t\tModel of your car is: "<<carmodel<<endl;
                cout<<"\t\t\t\t\tDuration of your rent is: "<<duration<<endl;
                cout<<"\t\t\t\t\tPrice for one day is: "<<price<<" $"<<endl;
                cout<<"\t\t\t\t\tLimit of kilometers: "<<limit<<endl;
                cout<<"\t\t\t\t\tTotal price is: "<<totalprice<<" $"<<endl;
                cout<<" "<<endl;

        }
    void inv()
    {
        cout<<"\t\t\t\t\t\t  Preparing invoice"<<endl;
        processingBar();
        system("cls");
        sum();
        cout<<" " <<endl;
        cout << "\t\t\t\tThis invoce is  automaticlly generated and it does not"<<endl;
        cout << "\t\t\t\trequire an authorised signture #"<<endl;
        cout <<" "<<endl;
        cout << "\t\t\t\t///////////////////////////////////////////////////////////"<<endl;
        cout << "\t\t\t\tYou are advised to pay up the amount before due date."<<endl;
        cout << "\t\t\t\tOtherwise penelty fee will be applied"<<endl;
        cout << "\t\t\t\t///////////////////////////////////////////////////////////"<<endl;
    }
     void processingBar()
     {
                sleep(1);
                cout<<"\t\t\t\t\t.   .";
                sleep(1);
                cout<<"\t.   .";
                sleep(1);
                cout<<"\t.   .";
                sleep(1);
                cout<<"\t.";
                sleep(1);
     }
void mainPage()
{
    cout<<"\t\t\t\t _______________________________________\n\n\n";
    cout<<"\t\t\t\t\t Welcome to CarRentProject \n\n\n";
    cout<<endl;
    cout<<"\t\t\t\t |Press 1 to select from Hyundai's cars|"<<endl;
    cout<<"\t\t\t\t |Press 2 to select from BMW's cars"<<setw(5)<<"|"<<endl;
    cout<<"\t\t\t\t |Press 3 select from Mercedes cars"<<setw(5)<<"|"<<endl;
    cout<<"\t\t\t\t |Press 4 to go back to main menu"<<setw(7)<<"|"<<endl;
    cout<<"\t\t\t\t\tTell us what You want to do: ";
    cin>>mark;
    cout<<endl;
    system("cls");
    switch(mark)
        {
        case 1:
        carmark = "Hyundai";
        cout<<"\t\t\t\t _______________________________________\n\n\n";
        cout<<"\t\t\t\t\t Here is list of Hyundai's cars \n\n\n";
        cout<<endl;
        cout<<"\t\t\t\t |Press 1 to select Hyundai Kona"<<setw(13)<<"|"<<endl;
        cout<<"\t\t\t\t |Press 2 to select Hyundai Tuscon"<<setw(11)<<"|"<<endl;
        cout<<"\t\t\t\t |Press 3 select Hyundai i30N"<<setw(16)<<"|"<<endl;
        cout <<"\t\t\t\t |Press 4 to go back to main menu           |"<<endl;
        cout<<"\t\t\t\t\t Choose your car: ";
        cin >> model;
        switch(model)
            {
            case 1:
                carmodel = "Hyundai Kona";
                system("cls");
                cout<<"\t\t\t\t\tSpecyfication of Hyundai Kona"<<endl;
                cout<<"\t\t\t\t\tYear of production: 2021"<<endl;
                cout<<"\t\t\t\t\tkW/KM: 88/120"<<endl;
                cout<<"\t\t\t\t\tGearbox type: Manual"<<endl;
                cout<<"\t\t\t\t\tCombustion: 5,6/100km"<<endl;
                cout<<"\t\t\t\t\tPrice for day: 45$"<<endl;
                cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                cout<<"\t\t\t\t\t";
                cin>>decide;
                price += 45;
                break;
            case 2:
                carmodel = "Hyundai Tuscon";
                system("cls");
                cout<<"\t\t\t\t\tSpecyfication of Hyundai Tuscon"<<endl;
                cout<<"\t\t\t\t\tYear of production: 2019"<<endl;
                cout<<"\t\t\t\t\tkW/KM: 110/150"<<endl;
                cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                cout<<"\t\t\t\t\tCombustion: 6.4/100km"<<endl;
                cout<<"\t\t\t\t\tPrice for day: 52$"<<endl;
                cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                cout<<"\t\t\t\t\t";
                cin>>decide;
                price += 65;
                break;
            case 3:
                carmodel = "Hyundai I30n";
                system("cls");
                cout<<"\t\t\t\t\tSpecyfication of Hyundai I30n"<<endl;
                cout<<"\t\t\t\t\tYear of production: 2022"<<endl;
                cout<<"\t\t\t\t\tkW/KM: 206/280"<<endl;
                cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                cout<<"\t\t\t\t\tCombustion: 8.4/100km"<<endl;
                cout<<"\t\t\t\t\tPrice for day: 65$"<<endl;
                cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                cout<<"\t\t\t\t\t";
                cin>>decide;
                price += 85;
                break;
            case 4:
                system("cls");
                cout<<"On my way to main menu, please wait"<<endl;
                processingBar();
                system("cls");
                main();
            }
            break;
        case 2:
            carmark = "BMW";
            cout<<"\t\t\t\t _______________________________________\n\n\n";
            cout<<"\t\t\t\t\t Here is list of BMW's cars \n\n\n";
            cout<<endl;
            cout<<"\t\t\t\t |Press 1 to select BMW Series 3 F30"<<setw(10)<<"|"<<endl;
            cout<<"\t\t\t\t |Press 2 to select BMW Series 5 G30"<<setw(10)<<"|"<<endl;
            cout<<"\t\t\t\t |Press 3 to select BMW M8"<<setw(20)<<"|"<<endl;
            cout<<"\t\t\t\t |Press 4 to go back to main menu"<<setw(13)<<"|"<<endl;
            cout<<"\t\t\t\t\t Choose your car: ";
            cin >> model;
            switch(model)
                {
                case 1:
                    carmodel = "BMW F30";
                    system("cls");
                    cout<<"\t\t\t\t\tSpecyfication of BMW F30"<<endl;
                    cout<<"\t\t\t\t\tYear of production: 2015"<<endl;
                    cout<<"\t\t\t\t\tkW/KM: 135/184"<<endl;
                    cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                    cout<<"\t\t\t\t\tType of fuel: Gasoline"<<endl;
                    cout<<"\t\t\t\t\tCombustion: 6.5/100km"<<endl;
                    cout<<"\t\t\t\t\tPrice for day: 75$"<<endl;
                    cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                    cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                    cout<<"\t\t\t\t\t";
                    cin>>decide;
                    price += 75;
                    break;
                case 2:
                    carmodel = "BMW G10";
                    system("cls");
                    cout<<"\t\t\t\t\tSpecyfication of BMW G30"<<endl;
                    cout<<"\t\t\t\t\tYear of production: 2019"<<endl;
                    cout<<"\t\t\t\t\tkW/KM: 140/190"<<endl;
                    cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                    cout<<"\t\t\t\t\tType of fuel: Diesel"<<endl;
                    cout<<"\t\t\t\t\tCombustion: 7.2/100km"<<endl;
                    cout<<"\t\t\t\t\tPrice for day: 90$"<<endl;
                    cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                    cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                    cout<<"\t\t\t\t\t";
                    cin>>decide;
                    price += 90;
                    break;
                 case 3:
                    carmodel = "BMW M8";
                    system("cls");
                    cout<<"\t\t\t\t\tSpecyfication of BMW M8"<<endl;
                    cout<<"\t\t\t\t\tYear of production: 2022"<<endl;
                    cout<<"\t\t\t\t\tkW/KM: 206/280"<<endl;
                    cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                    cout<<"\t\t\t\t\tCombustion: 11.6/100km"<<endl;
                    cout<<"\t\t\t\t\tPrice for day: 216$"<<endl;
                    cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                    cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                    cout<<"\t\t\t\t\t";
                    cin>>decide;
                    price += 216;
                    break;
                case 4:
                    cout<<"\t\t\t\tOn my way to main menu, please wait"<<endl;
                    processingBar();
                    system("cls");
                    main();
                }
                break;
        case 3:
            carmark = "Mercedes";
            cout<<"\t\t\t\t _______________________________________\n\n\n";
            cout<<"\t\t\t\t\t Here is list of Mercedes cars \n\n\n";
            cout<<endl;
            cout<<"\t\t\t\t |Press 1 to select Mercedes A Class 250 e   |"<<endl;
            cout<<"\t\t\t\t |Press 2 to select Mercedes EQE 350+        |"<<endl;
            cout<<"\t\t\t\t |Press 3 to select Mercedes G63 AMG         |"<<endl;
            cout <<"\t\t\t\t |Press 4 to go back to main menu           |"<<endl;
            cout<<"\t\t\t\t\t Choose your car: ";
            cin >> model;
            switch(model)
            {
                case 1:
                carmodel = "Mercedes A Class 250 e";
                system("cls");
                cout<<"\t\t\t\t\tSpecyfication of Mercedes A Class 250 e"<<endl;
                cout<<"\t\t\t\t\tYear of production: 2021"<<endl;
                cout<<"\t\t\t\t\tkW/KM: 118+75/160+ 102"<<endl;
                cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                cout<<"\t\t\t\t\tType of fuel: Hybrid"<<endl;
                cout<<"\t\t\t\t\tCombustion: 1/100km / 15.3kW/100km"<<endl;
                cout<<"\t\t\t\t\tPrice for day: 68$"<<endl;
                cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                cout<<"\t\t\t\t\t";
                cin>>decide;
                price += 68;
                break;
             case 2:
                carmodel = "Mercedes EQE 350+";
                system("cls");
                cout<<"\t\t\t\t\tSpecyfication of Mercedes EQE 350+"<<endl;
                cout<<"\t\t\t\t\tYear of production: 2022"<<endl;
                cout<<"\t\t\t\t\tkW/KM: 215/292"<<endl;
                cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                cout<<"\t\t\t\t\tType of fuel: Electric"<<endl;
                cout<<"\t\t\t\t\tCombustion: 16.4 kWh/100km"<<endl;
                cout<<"\t\t\t\t\tPrice for day: 150$"<<endl;
                cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes'"<<endl;
                cout<<"\t\t\t\t\tif you want to choose other car type 'no'"<<endl;
                cout<<"\t\t\t\t\t";
                cin>>decide;
                price += 90;
                break;
             case 3:
                carmodel = "AMG G63";
                system("cls");
                cout<<"\t\t\t\t\tSpecyfication of Mercedes AMG G63"<<endl;
                cout<<"\t\t\t\t\tYear of production: 2019"<<endl;
                cout<<"\t\t\t\t\tkW/KM: 430/585"<<endl;
                cout<<"\t\t\t\t\tGearbox type: Automatic"<<endl;
                cout<<"\t\t\t\t\tCombustion: 16/100km"<<endl;
                cout<<"\t\t\t\t\tPrice for day: 250$"<<endl;
                cout<<"\t\t\t\t\tif you want to proceed with that car type 'yes' lower case only"<<endl;
                cout<<"\t\t\t\t\tif you want to choose other car type 'no' lower case only"<<endl;
                cout<<"\t\t\t\t\t";
                cin>>decide;
                price += 250;
                break;
            case 4:
                cout<<"\t\t\t\tOn my way to main menu, please wait"<<endl;
                processingBar();
                system("cls");
                main();
            }
            break;
        case 4:
            cout<<"\t\t\t\tOn my way to main menu, please wait"<<endl;
            processingBar();
            system("cls");
            main();
        }

        if (decide =="yes")
        {
            system("cls");
            cout<<"\t\t\t\t\tTell us for how long You need that car: ";
            cin>>duration;
            cout<<"\t\t\t\t\tThere is a 200km limit per day.\n\t\t\t\t\tYou can remove limit for 50$ per day\n\t\t\t\t\tDo You want to remove current limit of "<<duration * totallimit <<"km?"<<endl;
            cout<<"\t\t\t\t\t(yes/no lower case only): ";
            cin>>limit;

            if (limit=="yes")
            {
                totalprice = price * duration + 50 * duration;
                limit="No Limit";
            }
            else if (limit=="no")
            {
                totalprice = price * duration;
                limit = "Limited";
            }
            cout<<"\t\t\t\t\tDo you want to see summary? (yes/no lower case only)";
            cin>>summary;

            if (summary == "yes")
            {
                system("cls");
                cout<<"\t\t\t\t\t\t  Procesing"<<endl;
                processingBar();
                sum();
                cout<<"\t\t\t\t\tContinue to Inovice? (yes/no lower case only)";
                cin>>inovice;

                if (inovice=="yes")
                {
                    system("cls");
                    inv();
                }
                else if (inovice == "no")
                {
                    system("cls");
                    cout<<"\t\t\t\tOn my way to main page ";
                    sleep(3);
                    mainPage();
                }
                else if (inovice != "YES" || inovice != "NO")
                {
                    system("cls");
                    cout<<"\t\t\t\t\tPlease select from one of above"<<endl;
                    sleep(2);
                    inv();
                }
            else if (summary == "NO")
            {
                system("cls");
                cout<<" On my way to main page ";
                main();
            }
            system("pause");
            }
            else{
                system("cls");
                mainPage();
            }
        }
        else if (decide == "NO")
        {
            system("cls");
            mainPage();
        }
        else{
            system("cls");
            cout<<"\t\t\t\t\tPlease select from one of above"<<endl;
            sleep(2);
            mainPage();
        }
};


