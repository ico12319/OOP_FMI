#include <iostream>
#include <fstream>

struct Product{
  int barcode;
  char* name;
  unsigned quantity;
  double price;

  Product(){
    barcode = 0;
    name = nullptr;
    quantity = 0;
    price = 0;
  }

  Product(int barcode,const char* name, unsigned quantity,double price){
    this->barcode = barcode;
    this->name = new char[std::strlen(name)+1];
    std::strcpy(this->name,name);
    this->quantity = quantity;
    this->price = price;
  }

  void addMoreQuantity(int extraQuantity){
     quantity += extraQuantity;
  }

  void printInfo() const{
    std::cout<<"Barcode: " << barcode << " " << "Name: " << name << " " << "Quantity: " << quantity << " " << "Price: " << price << std::endl;
  }

};

struct Shop{

    char name[31];
    char address[51];
    Product products[100];
    int productsCount;
    double earnings;

    Shop(){
    }


    Shop(const char* name,const char* address, const Product* products,int productsCount,double earnings){
        std::strcpy(this->name,name);
        std::strcpy(this->address,address);
        for(int i = 0;i<productsCount;i++){
            this->products[i] = products[i];
        }
        this->productsCount = productsCount;
        this->earnings = earnings;

    }

    void addProductToTheShop(const Product& prod){

        if(productsCount < 100){
             products[productsCount] = prod;
             productsCount++;
        }
        else{
            std::cout<<"Not enough space. Try again later!"<<std::endl;
        }
    }

    bool isContained(const Product& prod) const{
        
        for(int i = 0;i<productsCount;i++){
            if(products[i].name == prod.name){
                return true;
            }
        }
        return false;
    }

    void sellProduct(const Product& prod){

        for(int i = 0;i<productsCount;i++){
            if(products[i].name == prod.name){
                if(products[i].quantity >= prod.quantity){
                    products[i].quantity -= prod.quantity;
                    earnings+=prod.price;
                    std::cout<<"Product sold successfully!"<<std::endl;
                    return;
                }
                else{
                    std::cout<<"Not enough quantity!"<<std::endl;
                }
            }
            
        }
    }


    void printShopInfo() const{

        std::cout<<"The name of the shop is: " << name << std::endl;
        std::cout<<"Address: " << address << std::endl;
        std::cout<<"Earnings: " << earnings << std::endl;

        for(int i = 0;i<productsCount;i++){

            if(products[i].quantity > 0){
                products[i].printInfo();
            }
            else{
                std::cout<<"The product has already been sold!" <<std::endl;
            }
        }

    }


};



int main(){


    Product product1(243,"A",3,4.50);
    Product product2(167,"B",0,1.25);
    Product product3(87,"V",12, 2.54);
    Product product4(49,"S",54,8.54);
    Product product5(65,"Ar",32,1.30);
    Product products[] = {product1,product2,product3};

    Shop shop("F","Arb",products,3,25);
    shop.printShopInfo();
    shop.addProductToTheShop(product4);
    std::cout<<shop.isContained(product3)<<std::endl;;
    std::cout<<shop.isContained(product5)<<std::endl;
    shop.sellProduct(product2);
    shop.sellProduct(product1);
    shop.sellProduct(product4);

    shop.printShopInfo();


}
