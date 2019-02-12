#include <bits/stdc++.h>
using namespace std;


class ProductCategory
{
private:

   string category;
public:

       ProductCategory(){};
       ProductCategory(string category)
       {
           this->category = category;
       }
       void ShowProductCategory()
       {
           cout<<"Product Category : "<<this->category<<endl;
       }
};

class Product
{
private:

    string product_name;
    double price;
    int quantity;
    ProductCategory product_category;

public:

    Product(){};
    Product(string product_name,double price, int quantity,ProductCategory product_category)
    {
        this->product_name = product_name;
        this->price = price;
        this->quantity = quantity;
        this->product_category = product_category;
    }
    void ShowProduct()
    {
        cout<<"Product Name     : "<<this->product_name<<endl;
        product_category.ShowProductCategory();
        cout<<"Product Quantity : "<<this->quantity<<endl;
        cout<<"Product Price    : "<<this->price<<endl;
    }
};



class Person
{

private:

    string name,personId;

public:

    Person(){};

    Person(string name,string personId)
    {
        this->name = name;
        this->personId = personId;
    }

    void ShowPerson()
    {
        cout<<"Person Name         : "<<this->name<<endl;
        cout<<"Person Id           : "<<this->personId<<endl;
    }

};

class CustomerCategory
{
private:

   string category;

public:

       CustomerCategory(){};

       CustomerCategory(string category)
       {
           this->category=category;
       }

       void ShowCustomerCategory()
       {
         cout<<"Customer Category : "<<this->category<<endl;
       }
};

class Customer : public Person
{
    int customer_id;
    CustomerCategory customer_category;

public:
    Customer(){};
    Customer(string name, string personId, int customer_id,CustomerCategory customer_category) : Person(name,personId)
    {
        this->customer_id = customer_id;
        this->customer_category = customer_category;
    }
    void ShowCustomer()
    {
        ShowPerson();
        cout<<"Customer ID         : "<<this->customer_id<<endl;
    }
};

int main()
{
    CustomerCategory *customer_category[3]={
                                           new CustomerCategory("Male"),
                                           new CustomerCategory("Female"),
                                           new CustomerCategory("Child")
                                           };
    Customer *customer[3]={
                                           new Customer("Mosiur","11508001",1100001,*customer_category[0]),
                                           new Customer("Jihad","11508002",1100002,*customer_category[1]),
                                           new Customer("Sabbir","11508004",11000004,*customer_category[2])
                                           };

    ProductCategory *product_category[3]={
                                           new ProductCategory("Garment"),
                                           new ProductCategory("Stationary"),
                                           new ProductCategory("Cosmetics")
                                         };
   Product *products[3]={
                                           new Product("Shirts",1950.00,30,*product_category[0]),
                                           new Product("Pencils",15.00,100,*product_category[1]),
                                           new Product("Perfume",120.00,20,*product_category[2]),
                                        };
   int buying_frequency[3]={6,10,2};


   cout<<"------Available Products-------"<<endl;
   for(int i=0;i<3;i++)
   {
       products[i]->ShowProduct();
       cout<<endl;
   }
   for(int i=0;i<3;i++)
   {
      if(buying_frequency[i]>=5 && buying_frequency[i]<=7)
      {
          cout<<" Congratulations !  YOU HAVE EARNED 35% DISCOUNT ON YOUR PURCHASE."<<endl;
          cout<<endl<<" Eligible Customer Information : "<<endl<<endl;
          customer[i]->ShowCustomer();
          cout<<endl;
      }
      else if(buying_frequency[i]>7)
      {
          cout<<"Congratulations !  YOU HAVE EARNED 65% DISCOUNT ON YOUR PURCHASE."<<endl;
          cout<<endl<<"Eligible Customer Information: "<<endl<<endl;
          customer[i]->ShowCustomer();
          cout<<endl;
      }
      else
      {
          cout<<"Keep Buying Products! Discount is on the way."<<endl;
          cout<<endl<<"Customer Information: "<<endl;
          customer[i]->ShowCustomer();
          cout<<endl;

      }
   }
}
