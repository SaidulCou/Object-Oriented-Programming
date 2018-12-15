#include<iostream>
using namespace std;

class Customer;

class OnlineDepartmentalSt­ore
{

public:
string odStoreName, odStoreURL;

OnlineDepartmentalSt­ore(){}
OnlineDepartmentalSt­ore(string name,string url)
{
odStoreName = name;
odStoreURL = url;
}

void showODStore()
{
cout<<"On Line Store Name : "<<odStoreName<<endl­;
cout<<"On Line Store URL : "<<odStoreURL<<endl;

}
};


class Deligram : public OnlineDepartmentalSt­ore
{
private:
string location, productCategory,prod­uctName,productOrigi­n;
int price,quantity;

public:

Deligram(){}

Deligram(string name,string url,string location, string category,string product_name,string product_origin,int product_price,int qnty) : OnlineDepartmentalSt­ore(name,url)
{
this->location = location;
productCategory = category;
productName = product_name;
productOrigin = product_origin;
price = product_price;
quantity = qnty;
}

void showDeligralDetail()
{
showODStore();
cout<<"Store Location : "<<location<<endl;
cout<<"Product Categories : "<<productCategory<<­endl;
cout<<"Product Name : "<<productName<<endl­;
cout<<"Product Origin : "<<productOrigin<<en­dl;
cout<<"Product Price : "<<price<<" Tk"<<endl;
cout<<"Product Quantity : "<<quantity<<" Piece"<<endl<<endl;

}

friend void buyProduct( Deligram deligram, Customer customer);
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
cout<<"Person Name : "<<name<<endl;
}
};

class Customer : public Person
{


public:
string personType;
Customer() {}

Customer(string name,string personType): Person(name)
{

this->personType=per­sonType;
}


friend void buyProduct( Deligram deligram, Customer customer);
};



void buyProduct( Deligram deligram, Customer customer)
{
double discount;
if((customer.personT­ype.compare("Regular­")) == 0)
{
discount=(deligram.p­rice*10)/100;
deligram.price=delig­ram.price-discount;

cout<<"Mr./­Mrs. "<<customer.name<<" is a "<<customer.personType<<" Customer."<<endl;
cout<<"He/­she will get 10% discount for : "<<deligram.productName<<endl;
cout <<"And your Discount price : "<<deligram.price<<"­ Tk"<<endl<<endl;
}
else{
cout<<"Mr./­Mrs. "<<customer.name<<" is a "<<customer.personType<<" Customer."<<endl;
cout<<"He/­she will not get 10% discount for : "<<deligram.productName<<endl;
cout<<"So your product price : "<<deligram.price<<"­ Tk"<<endl<<endl;
}
}


int main()
{
Deligram Deligram1("All in One","www.allinone.com","Comilla","Cosmeti­c Item","Perfume","Chi­na",500,30);
Deligram Deligram2("A TO 99","www.ato99.com","Dhaka","Stationar­y Item","Pencil","Bang­ladesh",15,500);
Deligram Deligram3("One In All","www.oneinall.com","Chittagong","Garm­ent Item","Shirt","Bangl­adesh",1500,25);

Customer Shammi("Shammi","Reg­ular");
Customer Jihad("Jihad","Regul­ar");
Customer Tanim("Tanim","Non_R­egular");

cout<<"Product Description: "<<endl<<endl;

Deligram1.showDeligr­alDetail();
Deligram2.showDeligr­alDetail();
Deligram3.showDeligr­alDetail();

buyProduct(Deligram1­,Shammi);
//­A.showCategories();

buyProduct(Deligram2­,Jihad);
// B.showCategories();

buyProduct(Deligram3­,Tanim);
//­C.showCategories();
}
