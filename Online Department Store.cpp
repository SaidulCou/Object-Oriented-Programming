#include<iostream>
using namespace std;

class Customer;

class OnlineDepartmentalStore
{

public:
    string odStoreName, odStoreURL;

    OnlineDepartmentalStore(){}
    OnlineDepartmentalStore(string name,string url)
    {
        odStoreName = name;
        odStoreURL = url;
    }

    void showODStore()
    {
        cout<<"On Line Store Name  :  "<<odStoreName<<endl;
        cout<<"On Line Store URL   :  "<<odStoreURL<<endl;

    }
};


class Deligram : public OnlineDepartmentalStore
{
private:
    string location, productCategory,productName,productOrigin;
    int price,quantity;

public:

    Deligram(){}

    Deligram(string name,string url,string location, string category,string product_name,string product_origin,int product_price,int qnty) : OnlineDepartmentalStore(name,url)
    {
        this->location = location;
        productCategory = category;
        productName = product_name;
        productOrigin = product_origin;
        price = product_price;
        quantity = qnty;
    }

    void showDeligramDetail()
    {
        showODStore();
        cout<<"Store Location      :  "<<location<<endl;
        cout<<"Product Categories  :  "<<productCategory<<endl;
        cout<<"Product Name        :  "<<productName<<endl;
        cout<<"Product Origin      :  "<<productOrigin<<endl;
        cout<<"Product Price       :  "<<price<<" Tk"<<endl;
        cout<<"Product Quantity    :  "<<quantity<<" Piece"<<endl<<endl;

    }

    friend void buyProduct(  Customer customer , Deligram deligram);
};

class Person
{
public:
    string name;
    Person(){}
    Person(string name)
    {
        this->name = name;
    }

    void showPerson()
    {
        cout<<"Person Name     :  "<<name<<endl;
    }
};

class Customer : public Person
{


public:
    string personType;
    Customer() {}

    Customer(string name,string personType): Person(name)
    {

        this->personType=personType;
    }


    friend void buyProduct( Customer customer , Deligram deligram);
};



void buyProduct( Customer customer , Deligram deligram)
{
    double discount;
    if((customer.personType.compare("Regular")) == 0)
    {
            discount=(deligram.price*10)/100;
            deligram.price=deligram.price-discount;

            cout<<"Mr./Mrs. "<<customer.name<<" is a "<<customer.personType<<" Customer."<<endl;
            cout<<"He/she will get 10% discount for : "<<deligram.productName<<endl;
            cout <<"And your Discount price : "<<deligram.price<<" Tk"<<endl<<endl;
    }
    else{
       cout<<"Mr./Mrs. "<<customer.name<<" is a "<<customer.personType<<" Customer."<<endl;
       cout<<"He/she will  not get 10% discount for : "<<deligram.productName<<endl;
       cout<<"So your product price : "<<deligram.price<<" Tk"<<endl<<endl;
    }
}


int main()
{
    Deligram Deligram1("All in One","www.allinone.com","Comilla","Cosmetic Item","Perfume","China",500,30);
    Deligram Deligram2("A TO 99","www.ato99.com","Dhaka","Stationary Item","Pencil","Bangladesh",15,500);
    Deligram Deligram3("One In All","www.oneinall.com","Chittagong","Garment Item","Shirt","Bangladesh",1500,25);

    Customer Shammi("Shammi","Regular");
    Customer Jihad("Jihad","Regular");
    Customer Tanim("Tanim","Non_Regular");

    cout<<"Product Description: "<<endl<<endl;

    Deligram1.showDeligramDetail();
    Deligram2.showDeligramDetail();
    Deligram3.showDeligramDetail();

    buyProduct(Shammi, Deligram1);
    //A.showCategories();

    buyProduct(Jihad , Deligram2);
   // B.showCategories();

    buyProduct(Tanim , Deligram3);
    //C.showCategories();
}


