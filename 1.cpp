#include<iostream>
using namespace std;
class BookShop
{
public:
    string bookshop_url,bookshop_name,bookshop_address;
    BookShop(){}
    BookShop(string url,string name,string address){
        bookshop_url = url;
        bookshop_name = name;
        bookshop_address = address;
    }
    void bookShop_display()
    {
        cout<<"BookShop Information: "<<endl;
        cout<<"---------------------"<<endl;
        cout<<"URL          : "<<bookshop_url<<endl;
        cout<<"Name         : "<<bookshop_name<<endl;
        cout<<"Address      : "<<bookshop_address<<endl<<endl;
    }
};
class AddBook
{
public:
    string title,writer_name,category;
    int price,quantity,edition_number;
    AddBook(){}
    AddBook(string title,string writer_name,int price,int quantity,int edition_number,string category){
        this->title = title;
        this->writer_name = writer_name;
        this->price = price;
        this->quantity = quantity;
        this->edition_number = edition_number;
        this->category = category;
    }
};
class ShopKeeper:public AddBook
{

public :

    void book_display()
    {
        cout<<"Book Information: "<<endl;
        cout<<"----------------"<<endl;
        cout<<"Title          : "<<title<<endl;
        cout<<"Writer Name    : "<<writer_name<<endl;
        cout<<"Price          : "<<price<<endl;
        cout<<"Quantity       : "<<quantity<<endl;
        cout<<"Edition Number : "<<edition_number<<endl;
        cout<<"Category       : "<<category<<endl<<endl;

    }

};
class Person
{
public:
    string name;
    Person() {}
};
class Customer:public Person
{
public:
    string type,title,writer_name,category;
     int price,quantity,edition_number;
    Customer(){}
    Customer(string name,string type,string title,string writer_name,int quantity,int edition_number,string category){
      this->name = name;
      this->type = type;
      this->title = title;
      this->writer_name = writer_name;
      this->quantity = quantity;
      this->edition_number = edition_number;
      this->category = category;
    }
    void customer_Book_display()
    {
       cout<<"Customer Book Details: "<<endl;
        cout<<"----------------"<<endl;
        cout<<"Title           : "<<title<<endl;
        cout<<"Writer Name     : "<<writer_name<<endl;
        cout<<"Quantity        : "<<quantity<<endl;
        cout<<"Edition Number  : "<<edition_number<<endl;
        cout<<"Category        : "<<category<<endl<<endl;
    }
};

class Price
{
public:
     friend void Count_price(AddBook b,Customer c);
};
void Count_price(AddBook b,Customer c)
    {
          double discount;
        if(b.title==c.title && b.writer_name==c.writer_name && c.type=="Regular" && b.quantity>=c.quantity){
            discount=(b.price*10)/100;
            b.price=b.price-discount;
            cout<<" Mr./Mrs. "<<c.name<<" is a "<<c.type<<" Customer,he/she will get 10% discount,so his/her Discount price:"<<b.price<<" taka."<<endl<<endl;
        }
        else if(b.title==c.title && b.writer_name==c.writer_name && c.type=="NonRegular" && b.quantity>=c.quantity)
        {
            cout<<" Mr./Mrs. "<<c.name<<" is a "<<c.type<<" Customer,he/she will  not get 10% discount,so his/her price:"<<b.price<<" taka."<<endl<<endl;
        }
        else{
            cout<<"The book is out of stock."<<endl;
        }
        b.quantity=b.quantity-c.quantity;
    }
int main()
{
    BookShop bk1("https://www.google.com/comilla/Ananda-book-shop/033PXX33","Ananda_book_shop","Kotbari,Comilla");

    AddBook b1("Object_Oriented_Programming_Language","Balagurusamy",180,3,5,"Fiction");
    AddBook b2("Introduction_To_Algorithms","Cormen",320,15,4,"NonFiction");
    Person p;
    bk1.bookShop_display();

    Customer c1("Riya","Regular","Object_Oriented_Programming_Language","Balagurusamy",2,5,"Fiction");
    c1.customer_Book_display();
    Count_price(b1,c1);

    Customer c2("Roton","NonRegular","Object_Oriented_Programming_Language","Balagurusamy",4,5,"Fiction");
    c2.customer_Book_display();
    Count_price(b1,c2);

}


