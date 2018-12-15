#include<iostream>
using namespace std;

class Customer;

class OnlineStore
{

public:
    string onlineStoreName, onlineStoreURL,onlineStoreLocation, productCategory;

    OnlineStore(){}
    OnlineStore(string name,string url, string location, string category)
    {
        onlineStoreName = name;
        onlineStoreURL = url;
        onlineStoreLocation = location;
        productCategory = category;
    }

    void showOnlineStore()
    {
        cout<<"On Line Store Name     :  "<<onlineStoreName<<endl;
        cout<<"On Line Store URL      :  "<<onlineStoreURL<<endl;
        cout<<"On Line store Location :  "<<onlineStoreLocation<<endl;
        cout<<"Product Categories     :  "<<productCategory<<endl;

    }



};



class Product : public OnlineStore
{
public:

    string productName,productOrigin,productType;
    int price,quantity;


    Product(){}

    Product(string name,string url,string location, string category,string product_name,string product_origin,string type,int product_price,int qnty) : OnlineStore(name,url,location,category)
    {


        productName = product_name;
        productOrigin = product_origin;
        productType = type;
        price = product_price;
        quantity = qnty;
    }


    void showProduct()
    {
        showOnlineStore();

        cout<<"Product Name           :  "<<productName<<endl;
        cout<<"Product Origin         :  "<<productOrigin<<endl;
        cout<<"Product Type           :  "<<productType<<endl;
        cout<<"Product Price          :  "<<price<<" Tk"<<endl;
        cout<<"Product Quantity       :  "<<quantity<<" Piece"<<endl<<endl;

    }

    friend void buyProduct(  Customer customer , Product product);


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
    string customerType;
    Customer() {}

    Customer(string name,string customerType): Person(name)
    {

        this->customerType=customerType;
    }


    friend void buyProduct( Customer customer , Product product);
};



void buyProduct( Customer customer , Product product)
{
    double discount;
    if((customer.customerType.compare("Regular")) == 0)
    {
            discount=(product.price*10)/100;
            product.price=product.price-discount;

            cout<<"Mr./Mrs. "<<customer.name<<" is a "<<customer.customerType<<" Customer."<<endl;
            cout<<"He/she will get 10% discount for : "<<product.productName<<endl;
            cout <<"And your Discount price : "<<product.price<<" Tk"<<endl<<endl;
    }
    else{
       cout<<"Mr./Mrs. "<<customer.name<<" is a "<<customer.customerType<<" Customer."<<endl;
       cout<<"He/she will  not get 10% discount for : "<<product.productName<<endl;
       cout<<"So your product price : "<<product.price<<" Tk"<<endl<<endl;
    }
}


int main()
{
    Product product1("All in One","www.allinone.com","Comilla","Cosmetic Item","Perfume","China","Ladies",500,30);
    Product product2("A TO 99","www.ato99.com","Dhaka","Stationary Item","Pencil","Bangladesh","Children",15,500);
    Product product3("One In All","www.oneinall.com","Chittagong","Garment Item","Shirt","Bangladesh","Gents",1500,25);

    Customer Shammi("Shammi","Regular");
    Customer Jihad("Jihad","Regular");
    Customer Tanim("Tanim","Non_Regular");

    cout<<"Product Description: "<<endl<<endl;


    product1.showProduct();
    product2.showProduct();
    product3.showProduct();

    buyProduct(Shammi, product1);
    //A.showCategories();

    buyProduct(Jihad , product2);
   // B.showCategories();

    buyProduct(Tanim , product3);
    //C.showCategories();
}




