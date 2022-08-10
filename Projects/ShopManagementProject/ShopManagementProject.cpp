#include<bits/stdc++.h>
using namespace std;

class Shop
{
    public:
        string product_name[10];
        int product_price[10];
        int product_quantity[10];
    private:
        int total_income;
    public:
        Shop(string product_name[], int product_price[], int product_quantity[], int n)
        {
            copy_n(product_name, n, this->product_name);
            copy_n(product_price, n, this->product_price);
            copy_n(product_quantity, n, this->product_quantity);
            this->total_income = 0;
        }
        void setIncome(int income)
        {
            this->total_income += income;   
        }
        int getIncome()
        {
            return this->total_income;
        }
};

Shop* addProduct(int n)
{
    string product_name[n];
    int product_price[n], product_quantity[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i+1 << " Name: ";
        getline(cin >> ws, product_name[i]);
        cout << "Product " << i+1 << " Price: ";
        cin >> product_price[i];
        cout << "Product " << i+1 << " Quantity: ";
        cin >> product_quantity[i];
    }
        
    Shop *product = new Shop(product_name, product_price, product_quantity, n);
    return product;
}

void buyProduct(Shop *product, int index, int quantity)
{
    if(product->product_quantity[index-1]>=quantity)
    {
        int amount = product->product_price[index-1]*quantity;
        product->setIncome(amount);
        product->product_quantity[index-1] -= quantity;
        cout << "Your total income: " << product->getIncome() << endl << endl;
    }
    else
        cout << endl << "This quantity is not available!" << endl << endl;
}

int main()
{
    int n;
    cout << "Number of products: ";
    cin >> n;
    Shop *products = addProduct(n);
    // for (int i = 0; i < n; i++)
    // {
    //     products[i] = addProduct(i);
    // }
    int flag=1;
    while (flag)
    {
        cout << "                               Buy Product" << endl;
        cout << "                              --------------" << endl;
        cout.setf(ios::left);
        cout.width(20);
        cout << "Product Index";
        cout<< "|";
        cout.width(20);
        cout << "Product Name";
        cout << "|";
        cout.width(20);
        cout << "Product Price";
        cout << "|";
        cout.width(20);
        cout << "Product Quantity";
        cout << "|";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout.width(20);
            cout << i+1;
            cout<< "|";
            cout.width(20);
            cout << products->product_name[i];
            cout<< "|";
            cout.width(20);
            cout << products->product_price[i];
            cout<< "|";
            cout.width(20);
            cout << products->product_quantity[i] << "|" << endl;
        }
        cout << endl;
        // break;
        cout << "Which product do you want? From 1 to " << n << " : ";
        int productOption, productQuantity;
        cin >> productOption;
        cout << "What is the quantity that you want of " << products->product_name[productOption-1] << " : ";
        cin >> productQuantity;
        buyProduct(products, productOption, productQuantity);
    }
    return 0;
}