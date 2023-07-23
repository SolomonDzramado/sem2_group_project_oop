#include <iostream>
#include <string>
#include <stdlib.h>
#include "AUTH.hpp"
#include "customer.hpp"
#include <iomanip>
#include "CART.hpp"
#include "UI.hpp"
#include "PRODUCT.hpp"
#include "COLOR.h++"
#include "MANAGER.hpp"
#include <iomanip>


using namespace std;

int main(int argc, char *argv[])
{

    if (argc == 1){
    UI *authPage =  UI::getUIInstace();
    authPage->loadAuthPage();
    }
    else if (argc > 1)
    {
        string firstname = argv[1];
        string lastname = argv[2];
        string password =  argv[3];

        AUTH manAuth(firstname, lastname, password);
     bool islogin =   manAuth.Login();

    if (islogin){
        cout << setw(20)<< right << Color::FG_BLUE<< Color::BOLD;
        UI * ui =  UI::getUIInstace();
        ui->delayPrint("WELCOME MANGER\n");

        cout << setw(20)<< right  << "Your are logedin as " << Color::FG_LIGHT_BLUE << Color::BOLD<<firstname << " " <<lastname<<Color::FG_DEFAULT << Color::NORMAL<< endl;

        cout << setw(20)<< right;

        ui->delayPrint("Go to the ");

        cout << Color::FG_LIGHT_MAGENTA<< Color::BOLD <<"statistics.txt"<< Color::FG_DEFAULT;

        ui->delayPrint(" file if you want to get the statctics of your shop\n");
       ui->delayPrint("You can also press 1 if want to restock the shop otherwise press any key\n");

        string choice;
        cout << ">> ";
        cin >> choice;
        cout << "\n";

        if (choice ==  "1")
        {
        MANAGER::restock();

        UI * ui =  UI::getUIInstace();
        cout << setw(20)<< right << Color::BOLD << Color::FG_GREEN;
        ui->delayPrint("You have informed the cashier you have restocked the shop\n ");
        }
        else {
            ui->delayPrint("Thanks for the inspection");
        }

    }
    else {
        cout << Color::FG_RED<< Color::BOLD;
        UI * ui =  UI::getUIInstace();
         ui->delayPrint("CREDENTIALS ARE INCORRECT PLEASE MAKE SURE YOU HAVE ACCESS TO THESE RESOURCES\n");
    }

    }

    // CART *cart = CART::getinStance();
    // cart->showCart();
}