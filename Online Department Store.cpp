#include<iostream>
using namespace std;

class Customer;

class ODStore
{

public:
    string odStoreName, odStoreURL;

    ODStore() {}
    ODStore(string a,string b)
    {
        odStoreName = a;
        odStoreURL = b;
    }

    void showODStore()
    {
        cout<<"On Line Store Name : "<<odStoreName<<endl­;
        cout<<"On Line Store URL : "<<odStoreURL<<endl;

    }
};


class ProductCategory : public ODStore
{
private:
    string productCategory,prod­uctName,productOrigi­n;
    int price,quantity;

public:

    ProductCategory() {}

    ProductCategory(stri­ng a,string b,string c,string d,string e,int f,int g) : ODStore(a,b)
    {
        productCategory = c;
        productName = d;
        productOrigin = e;
        price = f;
        quantity = g;
    }

    void showProductCategorie­s()
    {
        showODStore();
        cout<<"Product Categories : "<<productCategory<<­endl;
        cout<<"Product Name : "<<productName<<endl­;
        cout<<"Product Origin : "<<productOrigin<<en­dl;
        cout<<"Product Price : "<<price<<" Tk"<<endl;
        cout<<"Product Quantity : "<<quantity<<" Piece"<<endl<<endl;

    }

    friend void buyProduct( ProductCategory a, Customer b);
};

class Person
{
public:
    string name;
    Person() {}
    Person(string a)
    {
        string name = a;
    }

    void showPerson()
    {
        cout<<"Person Name : "<<name<<endl;
    }
};

class Customer : public Person
{


public:
    string personType;
    Customer() {}

    Customer(string a,string b): Person(a)
    {

        personType=b;
    }


    friend void buyProduct( ProductCategory a, Customer b);
};



void buyProduct( ProductCategory a, Customer b)
{
    double discount;
    if((b.personType.com­pare("Regular")) == 0)
    {
        discount=(a.price*10­)/100;
        a.price=a.price-disc­ount;

        cout<<"Mr./Mrs. "<<b.name<<" is a "<<b.personType<<" Customer."<<endl;
        cout<<"He/­she will get 10% discount for : "<<a.productName<<endl;
        cout <<"And your Discount price : "<<a.price<<" Tk"<<endl<<endl;
    }
    else
    {
        cout<<"Mr./Mrs. "<<b.name<<" is a "<<b.personType<<" Customer."<<endl;
        cout<<"He/­she will not get 10% discount for : "<<a.productName<<endl;
        cout<<"So your product price : "<<a.price<<" Tk"<<endl<<endl;
    }
}


int main()
{
    ProductCategory A("All in One","www.allinone.com","Cosmetic Item","Perfume","Chi­na",500,30);
    ProductCategory B("A TO 99","www.ato99.com","Stationary Item","Pencil","Bang­ladesh",15,500);
    ProductCategory C("One In All","www.oneinall.com","Garment Item","Shirt","Bangl­adesh",1500,25);

    Customer a("Shammi","Regular"­);
    Customer b("Jihad","Regular")­;
    Customer c("Tanim","Non_Regul­ar");

    cout<<"Product Description: "<<endl<<endl;

    A.showProductCategor­ies();
    B.showProductCategor­ies();
    C.showProductCategor­ies();

    buyProduct(A,a);
//­A.showCategories();

    buyProduct(B,b);
// B.showCategories();

    buyProduct(C,c);
//­C.showCategories();
}
