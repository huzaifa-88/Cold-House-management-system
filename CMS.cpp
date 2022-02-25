#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

//Globally declared array
int count=0;
const int TOTAL=10;
string nameA[TOTAL];
int priceA[TOTAL]={0};
float quantityA[TOTAL];
string expiry_dateA[TOTAL];
string saleNameA[TOTAL];
string buyer_companyA[TOTAL];
float stockA[TOTAL];
int recievePriceA[TOTAL];

//Prototypes
void header();
char Admin_menu();
char User_menu();
void addProduct();
void AddtoARRAY(string salestock,string buyercomp,float salequan,float recieveprice);
void addProduct(string name,float price,float quantity,string expiryDate);
void storeInArray(string name,float price,float quantity,string expiryDate);
void displayProduct(string name, float price, float quantity, string expiryDate);
int Checkstock(string sale_name);
int find_stock(string sale_name);
void clearScreen();

main()
{
    bool isFound = false;
    int index.delINDEX;
    int count=0;
    string salestock,buyercompany;
    string name,expiryDate;
    string deletestock;
    float price,quantity,salequantity,recieveprice;
    char option='0';

    while(true)
    {
        option =Admin_menu();
        if(option==1)//Enter new product
        { 
            addProduct(name,price,quantity,expiryDate);
            clearScreen();
        }
        else if(option==2)//view total products
        {
            displayProduct(name,price,quantity,expiryDate);
            clearScreen();
        }
        else if(option==3)//sorting
        {
            for(int x=0; x<TOTAL-1; x++)
            {
                for(int j=x+1; j<TOTAL; j++)
                {
                    if( priceA[j]<priceA[x] )
                    {
                        int temp = priceA[j];
                        priceA[j]=priceA[x];
                        priceA[x]=temp;
                    }//End of if
                }//End of nested for 
    
            }//End of for loop

            for(int i=0; i<TOTAL; i++)
            {
                cout<<nameA[i]<<"\t"<<priceA[i]<<"\t"<<quantityA[i]<<"\t"<<expiry_dateA[i]<<endl;
            }
        }   //.........End of sorting
        else if(option==4)//processing of product
        {
            cout<<"Enter sale product stock name:";
            cin >> salestock;
            cout<< "Enter company name which buy this stock:";
            cin >> buyercompany;
            cout<< "Enter number of stocks which sale to the company:";
            cin >> salequantity;
            cout<< "Enter price receive from company:";
            cin >> recieveprice;

            AddtoARRAY(salestock,buyercompany,salequantity,recieveprice);
            clearScreen();
        }//.......End of processing
        else if(option==5)//remaining product
        {
            cout<<"Enter sale product stock name:";
            cin>>salestock;
            index = Checkstock(salestock); 
            stockA[index] = quantityA[index] - stockA[index];
            cout<<"The remaining stock of this product are "<<stockA[index]<<"\n";  

            clearScreen();
        }
        else if(option==6)//Deleting of product
        {
            cout<<"Which product stock do you want to delete:";
            cin>>deletestock;
            delINDEX = find_stock(deletestock);
            priceA[delINDEX]=0;
            clearScreen();
        }
        else if(option==7)
        {
            break;
            clearScreen();
        }
        else
        {
            cout<<"You enter wrong option"<<"\n";
            clearScreen();
        }
    }
}

//Functions declaration

void header()
{
    cout << "************************************************" << endl;
    cout << "*   Cold Storage Warehouse Management System   *" << endl;
    cout << "************************************************" << endl;
    cout << endl;
} // End of 1st function
char Admin_menu()
{

    char option;
    header();
    // Main menu of project
    cout << "Admin Main Menu>>" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Select one of the following option..." << endl;
    cout << "1- Enter new product" << endl;
    cout << "2- View total products" << endl;
    cout << "3- Sorting them according to their price" << endl;
    cout << "4- Processing of product" << endl;
    cout << "5- Deleting of product" << endl;
    cout << "6- View Remaining product" << endl;
    cout << "7- Exit" << endl;
    cout << "Enter option:";
    cin >> option;
    return option;

} // End of 2nd function
char User_menu()
{
    char option;
    header();
    // Main menu of project
    cout << "Admin Main Menu>>" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Select one of the following option..." << endl;
    cout << "1- View Remaining products"<<endl; 
    cout << "2- Buy products" << endl;
    cout << "3- Report Admin"<<endl;
    cout << "4- Exit" << endl;
    cout << "Enter option:";
    cin >> option;
    return option;
}

void addProduct(string name,float price,float quantity,string expiryDate)
{
    
    cout << "Enter product Name:";
    cin >> name;
    cout << "Enter price of 1st product stock:";
    cin >> price;
    cout << "Enter quantity of 1st product in stocks:";
    cin >> quantity;
    cout << "Enter product expiry date:";
    cin >> expiryDate;
    
    storeInArray(name,price,quantity,expiryDate);
    count=count+1;
}//End of 3rd Function
void storeInArray(string name,float price,float quantity,string expiryDate)
{
    for(int i=0; i<TOTAL; i++)
    {
        nameA[i]=name;
        priceA[i]=price;
        quantityA[i]=quantity;
        expiry_dateA[i]=expiryDate;
    }//End of for loop
}//End of 4th function
void displayProduct(string name, float price, float quantity, string expiryDate)
{
    for(int x=0; x<TOTAL; x++)
    {
        if (price > 0)
        {
            cout<<"Name\tPrice\tQuantity\tExpiry Date"<<endl;
            cout<<endl;
            cout << nameA[x] << "\t" << priceA[x] << "\t" << quantityA[x] <<"\t"<< expiry_dateA[x] << endl;
        }
    }
} // End of 5th function
void AddtoARRAY(string salestock,string buyercomp,float salequan,float recieveprice)
{
    for(int x=0; x<TOTAL; x++)
    {
        saleNameA[x]=salestock;
        buyer_companyA[x]=buyercomp;
        stockA[x]=salequan;
        recievePriceA[x]=recieveprice;
    }
}//End of 6th function
int Checkstock(string sale_name)
{
    for(int z=0; z<TOTAL; z++)
    {
        if(sale_name == saleNameA[z])
        {
            return z;
        }
    }

    return 0 ;
}//End of 7th function
int find_stock(string delstock)
{
    for(int j=0; j<TOTAL; j++)
    {
        if(delstock == nameA[j])
        {
            return j;
        }
    }
    
    return 0 ;
}//End of 8th Function
void clearScreen()
{
    cout<<"Press any key to continue";
    getch();
    system("cls");
}//End of 9th function