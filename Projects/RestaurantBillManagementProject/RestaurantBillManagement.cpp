#include<bits/stdc++.h>
using namespace std;

class Restaurant
{
    public:
        int food_item_codes[12];
        string food_item_names[12];
        int food_item_prices[12];
    private:
        int total_tax;
    public:
        Restaurant(int food_item_codes[], string food_item_names[], int food_item_prices[], int n)
        {
            copy_n(food_item_codes, n, this->food_item_codes);
            copy_n(food_item_names, n, this->food_item_names);
            copy_n(food_item_prices, n, this->food_item_prices);
            this->total_tax = 0;
        }
        void setTAX(double tax)
        {
            this->total_tax += tax;
        }
        double getTAX()
        {
            return this->total_tax;
        }
};

Restaurant* addProducts(int n)
{
    int food_item_codes[n], food_item_prices[n];
    string food_item_names[n];
    for (int i = 0; i < n; i++)
    {
        cin >> food_item_codes[i];
        getline(cin >> ws, food_item_names[i]);
        cin >> food_item_prices[i];
    }
    Restaurant *addedProduct = new Restaurant(food_item_codes, food_item_names, food_item_prices, n);
    return addedProduct;
}

void showFoodItems(Restaurant *foodItems, int n)
{
    cout << "                               MAKE BILL" << endl;
    cout << "                            ---------------" << endl;
    cout.setf(ios::left);
    cout.width(20);
    cout << "Item Code";
    cout.width(30);
    cout << "Item Name";
    cout.width(20);
    cout << "Item Price";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout.width(20);
        cout << foodItems->food_item_codes[i];
        cout.width(30);
        cout << foodItems->food_item_names[i];
        cout.width(20);
        cout << foodItems->food_item_prices[i] << endl;
    }
    cout << endl;
}

void showBillSummary(Restaurant *foodItems, int tableNum, int itemCodeList[], int quantityList[], int itemNum)
{
    cout << "                               BILL SUMMARY" << endl;
    cout << "                              --------------" << endl;
    cout << "Table No.: " << tableNum <<endl; 
    cout.setf(ios::left);
    cout.width(15);
    cout << "Item Code";
    cout.width(25);
    cout << "Item Name";
    cout.width(15);
    cout << "Item Price";
    cout.width(15);
    cout << "Item Quantity";
    cout.width(15);
    cout << "Total Price";
    cout << endl;
    double total=0;
    for (int i = 0; i < itemNum; i++)
    {
        double itemTotal = foodItems->food_item_prices[itemCodeList[i]]*quantityList[i];
        total = total + itemTotal;
        cout.width(15);
        cout << foodItems->food_item_codes[itemCodeList[i]];
        cout.width(25);
        cout << foodItems->food_item_names[itemCodeList[i]];
        cout.width(15);
        cout << foodItems->food_item_prices[itemCodeList[i]];
        cout.width(15);
        cout << quantityList[i];
        cout.width(15);
        cout << itemTotal;
        cout << endl;
    }
    double tax = total*0.05;
    cout.width(15);
    cout << "TAX";
    cout.width(55);
    cout << "";
    cout.width(15);
    cout << fixed << setprecision(2) << tax << endl;
    cout << "____________________________________________________________________________________" << endl;
    total = total + tax;
    cout.width(15);
    cout << "NET TOTAL";
    cout.width(55);
    cout << "";
    cout << fixed << setprecision(2) << total;
    cout.width(15);
    cout << " Taka" << endl;
    foodItems->setTAX(tax);
    cout << endl ;
    // cout << foodItems->getTAX() << endl;
}

int main()
{
    int n;
    cin >> n;
    Restaurant *billManagement = addProducts(n);
    while (1)
    {
        showFoodItems(billManagement, n);
        int tableNum, itemNum;
        cout << "Enter Table No: " ;
        cin >> tableNum;
        cout << "Enter Number of Items: ";
        cin >> itemNum;
        int itemCodeList[itemNum], quantityList[itemNum];
        for (int i = 0; i < itemNum; i++)
        {
            while (1)
            {
                cout << "Enter Item " << i+1 << " Code: ";
                cin >> itemCodeList[i];
                int matched=0;
                for (int j = 0; j < n; j++)
                {
                    if(billManagement->food_item_codes[j] == itemCodeList[i])
                    {
                        matched =  1;
                        itemCodeList[i] = j;
                        break;
                    }
                }
                if (matched==0)
                {
                    cout << "This item code is not valid! Pleas enter a valid code." << endl;
                    continue;
                }
                cout << "Enter Item " << i+1 << " Quantity: ";
                cin >> quantityList[i];
                break;
            }
            
            
        }
        showBillSummary(billManagement, tableNum, itemCodeList, quantityList, itemNum);
        // break;
    }
    
    return 0;
}