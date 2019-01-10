#include<iostream>
using namespace std;
class BookShop
{
public:
    string bookShopUrl,bookShopName,bookShopAddress;
    string title,writerName,category;
    int price,quantity,editionNumber;
    BookShop(){}
    BookShop(string bookShopUrl,string bookShopName,string bookShopAddress){
         this->bookShopUrl = bookShopUrl;
         this->bookShopName = bookShopName;
         this->bookShopAddress = bookShopAddress;
    }

    void Book(string title,string writerName,int price,int quantity,int editionNumber,string category ){
        this->title = title;
        this->writerName = writerName;
        this->price = price;
        this->quantity = quantity;
        this->editionNumber = editionNumber;
        this->category = category ;
    }

      void showBookShop()
    {
        cout<<"BookShop Information: "<<endl<<endl;
        cout<<"Book Shop URL          : "<<bookShopUrl<<endl;
        cout<<"Book Shop Name         : "<<bookShopName<<endl;
        cout<<"Book Shop Address      : "<<bookShopAddress<<endl<<endl;
    }

    void showBookShopBook()
    {
        cout<<"Book Information : "<<endl<<endl;
        cout<<"Book Title       : "<<title<<endl;
        cout<<"Writer Name      : "<<writerName<<endl;
        cout<<"Book Price       : "<<price<<endl;
        cout<<"Book Category    : "<<category<<endl;
        cout<<"Edition Number   : "<<editionNumber<<endl;
        cout<<"Quantity         : "<<quantity<<endl;
    }
};

class ShopKeeper
{
 public:
     string type,title,writerName,category;
     int price,quantity,editionNumber;
     void showBook()
    {
       cout<<"Customer Book Information : "<<endl<<endl;
        cout<<"Title          : "<<title<<endl;
        cout<<"Writer Name    : "<<writerName<<endl;
        cout<<"Quantity       : "<<quantity<<endl;
        cout<<"Edition Number : "<<editionNumber<<endl;
    }

    friend void addBook();

};
void addBook(BookShop c){
        cout<<"Book Information: "<<endl<<endl;
        cout<<"Title          : "<<c.title<<endl;
        cout<<"Writer Name    : "<<c.writerName<<endl;
        cout<<"Price          : "<<c.price<<endl;
        cout<<"Quantity       : "<<c.quantity<<endl;
        cout<<"Edition Number : "<<c.editionNumber<<endl;

}
class Person
{
public:
    string name;
    Person() {}
};
class Customer:public Person
{
public:
    string type,title,writerName,category;
     int price,quantity,editionNumber;
    Customer(){}
    Customer(string name,string type,string title,string writerName,int quantity,int editionNumber){
      this->name = name;
      this->type = type;
      this->title = title;
      this->writerName = writerName;
      this->quantity = quantity;
      this->editionNumber = editionNumber;
      this->category = category;
    }
    void showCustomerBook()
    {
       cout<<"Customer Book Information : "<<endl<<endl;
        cout<<"Title          : "<<title<<endl;
        cout<<"Writer Name    : "<<writerName<<endl;
        cout<<"Quantity       : "<<quantity<<endl;
        cout<<"Edition Number : "<<editionNumber<<endl;
    }


};


class Price
{
public:
     friend void EstimatedPrice(BookShop bookshop,Customer customer);
};
void EstimatedPrice(BookShop bookshop,Customer customer)
    {
          double discount;
        if(bookshop.title==customer.title && bookshop.writerName==customer.writerName && customer.type=="Regular" && bookshop.quantity>=customer.quantity){
            discount=(bookshop.price*10)/100;
            bookshop.price=bookshop.price-discount;
            cout<<" Mr./Mrs. "<<customer.name<<" is a "<<customer.type<<" Customer."<<endl<<"He/she will get 10% discount."<<endl<<"And his/her Discount price:"<<bookshop.price<<" taka."<<endl<<endl;
        }
        else if(bookshop.title==customer.title && bookshop.writerName==customer.writerName && customer.type=="NonRegular" && bookshop.quantity>=customer.quantity)
        {
            cout<<" Mr./Mrs. "<<customer.name<<" is a "<<customer.type<<" Customer."<<endl<<"He/she will  not get 10% discount."<<endl<<"And his/her price:"<<bookshop.price<<" taka."<<endl<<endl;
        }
        else{
            cout<<"The book is out of stock."<<endl;
        }
        bookshop.quantity=bookshop.quantity-customer.quantity;
    }



int main()
{
    BookShop bookshop1("www.ikraBokkShop.com","Ikra Book Shop","Kandirpur,Comilla");
    ShopKeeper Rahim;
    bookshop1.Book("Introduction To Algorithms","Cormen",250,5,5,"NonFiction");
    bookshop1.showBookShop();
    bookshop1.showBookShopBook();

    Customer customer1("Mosiur","Regular","Operating System Concepts","Galvin",2,5);
    customer1.showCustomerBook();
     EstimatedPrice(bookshop1,customer1);

    Customer customer2("Munna","NonRegular","Introduction To Algorithms","Cormen",5,5);
    customer2.showCustomerBook();
    EstimatedPrice(bookshop1,customer2);

}


