#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
class adminNode {
public:
    int admin_id;
    string admin_name;
    string admin_pass;
    adminNode* pNext;
};
class adminList {
public:
    adminNode* pHead;
    adminNode* pTail;

    adminList()
    {
        pHead = NULL;
        pTail = NULL;
    }

    void Attach(adminNode* pnn)
    {
        if (pHead == NULL) {
            pHead = pnn;
            pTail = pnn;
        }
        else {
            pTail->pNext = pnn;
            pTail = pnn;
        }
    }

    ~adminList()
    {
        adminNode* pTrav;
        pTrav = pHead;
        while (pHead != NULL) {
            pHead = pTrav->pNext;
            pTrav->pNext = NULL;
            delete[] pTrav;
            pTrav = pHead;
        }
    }
};

class ProductNode {

public:
    int product_id;
    string product_name;
    int product_stock;
    int product_price;
    int product_month;
    int product_year;
    ProductNode* pNext;
};

class productList {
public:
    ProductNode* pHead;
    ProductNode* pTail;

    productList()
    {
        pHead = NULL;
        pTail = NULL;
    }

    void Attach(ProductNode* pnn)
    {
        if (pHead == NULL) {
            pHead = pnn;
            pTail = pnn;
        }
        else {
            pTail->pNext = pnn;
            pTail = pnn;
        }
    }

    ~productList()
    {
        ProductNode* pTrav;
        pTrav = pHead;
        while (pHead != NULL) {
            pHead = pTrav->pNext;
            pTrav->pNext = NULL;
            delete[] pTrav;
            pTrav = pHead;
        }
    }

};

class CustomerNode {
public:
    int Customer_id;
    string Customer_name;
    string Customer_pass;
    CustomerNode* pNext;
};
class CustomerList {
public:
    CustomerNode* pHead;
    CustomerNode* pTail;

    CustomerList()
    {
        pHead = NULL;
        pTail = NULL;
    }

    void Attach(CustomerNode* pnn)
    {
        if (pHead == NULL) {
            pHead = pnn;
            pTail = pnn;
        }
        else {
            pTail->pNext = pnn;
            pTail = pnn;
        }
    }


    ~CustomerList()
    {
        CustomerNode* pTrav;
        pTrav = pHead;
        while (pHead != NULL) {
            pHead = pTrav->pNext;
            pTrav->pNext = NULL;
            delete[] pTrav;
            pTrav = pHead;
        }
    }

};
class OrderNode {
public:
    int order_id_product;
    int order_id_customer;
    OrderNode* pNext;
};
class OrderList {
public:
    OrderNode* pHead;
    OrderNode* pTail;

    OrderList()
    {
        pHead = NULL;
        pTail = NULL;
    }

    void Attach(OrderNode* pnn)
    {
        if (pHead == NULL) {
            pHead = pnn;
            pTail = pnn;
        }
        else {
            pTail->pNext = pnn;
            pTail = pnn;
        }
    }


    ~OrderList()
    {
        OrderNode* pTrav;
        pTrav = pHead;
        while (pHead != NULL) {
            pHead = pTrav->pNext;
            pTrav->pNext = NULL;
            delete[] pTrav;
            pTrav = pHead;
        }
    }
};
int main()
{
    adminList adminL;
    CustomerList Customers;
    OrderList Orders;
    productList productL;

    //put proudcts in list
    string ProductsText;
    ifstream ProductsFile;
    ProductsFile.open("product.txt");
    if (ProductsFile.is_open())
    {
        string temp[6];
        int k = 0;
        int ct = 0;
        while (getline(ProductsFile, ProductsText))
        {
            if (ct > 0)
            {
                for (int i = 0; i < ProductsText.length(); i++)
                {
                    if (ProductsText[i] == ',')
                    {
                        k++;
                    }
                    else
                    {
                        temp[k] += ProductsText[i];
                    }
                }
                k = 0;
                ProductNode* pnn = new ProductNode;
                pnn->product_id = stoi(temp[0]);
                pnn->product_name = temp[1];
                pnn->product_stock = stoi(temp[3]);
                pnn->product_price = stoi(temp[2]);
                pnn->product_month = stoi(temp[4]);
                pnn->product_year = stoi(temp[5]);
                pnn->pNext = NULL;
                productL.Attach(pnn);
                for (int h = 0; h < 6; h++)
                {
                    temp[h].clear();
                }
            }
            ct++;
        }
    }
    else {
        cout << "file not open ";
    }
    ProductsFile.close();
    //put customer in list
    string CustomersLine;
    ifstream CustomersFile;
    CustomersFile.open("customer.txt");
    if (CustomersFile.is_open())
    {
        string temp[3];
        int k = 0;
        int ct = 0;
        while (getline(CustomersFile, CustomersLine))
        {
            if (ct > 0)
            {
                for (int i = 0; i < CustomersLine.length(); i++)
                {
                    if (CustomersLine[i] == ',')
                    {
                        k++;
                    }
                    else
                    {
                        temp[k] += CustomersLine[i];
                    }

                }
                k = 0;
                CustomerNode* pnn = new CustomerNode;
                pnn->Customer_id = stoi(temp[0]);
                pnn->Customer_name = temp[1];
                pnn->Customer_pass = temp[2];
                pnn->pNext = NULL;
                Customers.Attach(pnn);

                for (int h = 0; h < 3; h++)
                {
                    temp[h].clear();
                }
            }
            ct++;

        }
    }
    CustomersFile.close();
    ////put order in list
    string OrdersLine;
    ifstream OrdersFile;
    OrdersFile.open("orders.txt");
    if (OrdersFile.is_open())
    {
        string temp[2];
        int k = 0;
        int ct = 0;
        while (getline(OrdersFile, OrdersLine))
        {
            if (ct > 0)
            {
                for (int i = 0; i < OrdersLine.length(); i++)
                {
                    if (OrdersLine[i] == ',')
                    {
                        k++;
                    }
                    else
                    {
                        temp[k] += OrdersLine[i];
                    }

                }
                k = 0;
                OrderNode* pnn = new OrderNode;
                pnn->order_id_customer = stoi(temp[0]);
                pnn->order_id_product = stoi(temp[1]);
                pnn->pNext = NULL;
                Orders.Attach(pnn);

                for (int h = 0; h < 2; h++)
                {
                    temp[h].clear();
                }
            }
            ct++;

        }
    }
    OrdersFile.close();

    string name, password;
    int num = 0, selectedProduct, newStock = 0;
    cout << "if admin press 1 else if Customer press 2 : ";
    cin >> num;
    if (num == 1)
    {
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter password : ";
        cin >> password;
        // put admin in admin list
        string adminsLine;
        ifstream adminsFile;

        adminsFile.open("admin.txt");
        if (adminsFile.is_open())
        {
            string temp[3];
            int k = 0;
            int ct = 0;
            while (getline(adminsFile, adminsLine))
            {
                if (ct > 0)
                {
                    for (int i = 0; i < adminsLine.length(); i++)
                    {
                        if (adminsLine[i] == ',')
                        {
                            k++;
                        }
                        else
                        {
                            temp[k] += adminsLine[i];
                        }
                    }
                    k = 0;
                    adminNode* pnn = new adminNode;
                    pnn->admin_id = stoi(temp[0]);
                    pnn->admin_name = temp[1];
                    pnn->admin_pass = temp[2];
                    pnn->pNext = NULL;
                    adminL.Attach(pnn);
                    for (int h = 0; h < 3; h++)
                    {
                        temp[h].clear();
                    }
                }
                ct++;
            }
            adminNode* pTrav = adminL.pHead;
            int login = 0;
            while (pTrav != NULL)
            {
                if (pTrav->admin_name == name && pTrav->admin_pass == password)
                {
                    login = 1;
                    break;
                }

                pTrav = pTrav->pNext;
            }
            if (login == 1)
            {
                // display all products
                ProductNode* pTrav = productL.pHead;
                cout << "Products" << endl;
                while (pTrav != NULL)
                {
                    cout << pTrav->product_id << " " << pTrav->product_name << " " << pTrav->product_stock << " " << pTrav->product_price << " " << pTrav->product_month << " " << pTrav->product_year;
                    cout << endl;
                    pTrav = pTrav->pNext;
                }

                //Adjust
                cout << "adjust" << endl;
                cout << "select product by id : ";
                cin >> selectedProduct;
                ProductNode* pTravP = productL.pHead;
                while (pTravP != NULL)
                {
                    if (selectedProduct == pTravP->product_id)
                    {
                        cout << "product stock is : " << pTravP->product_stock << endl;
                        break;
                    }
                    pTravP = pTravP->pNext;
                }
                cout << " item is selected set the new value for stock : ";
                cin >> newStock;
                pTravP->product_stock = newStock;
                cout << "stock become : " << pTravP->product_stock << endl;

                //delete product
                int deleteProduct = 0;
                cout << "select item want delete by id :";
                cin >> deleteProduct;
                ProductNode* pTravd = productL.pHead;
                ProductNode* tempo = pTravd;

                while (pTravd != NULL)
                {
                    if (pTravd->product_id == deleteProduct)
                    {
                        if (pTravd != productL.pHead)
                        {
                            cout << "delete product" << endl;
                            if (pTravd != productL.pTail)
                            {
                                tempo->pNext = pTravd->pNext;
                                pTravd->pNext = NULL;
                                delete pTravd;
                            }
                            else
                            {
                                productL.pTail = tempo;
                                tempo->pNext = NULL;
                                delete pTravd;
                            }
                        }
                        else
                        {
                            productL.pHead = pTravd->pNext;
                            pTravd->pNext = NULL;
                            delete pTravd;
                        }

                        break;
                    }
                    else
                    {
                        tempo = pTravd;
                        pTravd = pTravd->pNext;
                    }
                }
                //display after delete
                pTrav = productL.pHead;
                cout << "Products" << endl;
                while (pTrav != NULL)
                {
                    cout << pTrav->product_id << " " << pTrav->product_name << " " << pTrav->product_stock << " " << pTrav->product_price << " " << pTrav->product_month << " " << pTrav->product_year;
                    cout << endl;
                    pTrav = pTrav->pNext;
                }

                // add new product
                cout << "add new product" << endl;
                ProductNode* pnn = new ProductNode;
                pnn->product_id = productL.pTail->product_id + 1;
                string pn;
                int ps;
                cout << "name of product : ";
                cin >> pn;
                pnn->product_name = pn;
                cout << "stock of product : ";
                cin >> ps;
                pnn->product_stock = ps;
                cout << "price of product : ";
                cin >> ps;
                pnn->product_price = ps;
                cout << "expire month of product : ";
                cin >> ps;
                pnn->product_month = ps;
                cout << "expire year of product : ";
                cin >> ps;
                pnn->product_year = ps;
                productL.Attach(pnn);


                //display all products after add new product
                pTrav = productL.pHead;
                cout << "Products" << endl;
                while (pTrav != NULL)
                {
                    cout << pTrav->product_id << " " << pTrav->product_name << " " << pTrav->product_stock << " " << pTrav->product_price << " " << pTrav->product_month << " " << pTrav->product_year;
                    cout << endl;
                    pTrav = pTrav->pNext;
                }

                // display all products that stock less than quantity
                int quantity;
                cout << "select quantity : ";
                cin >> quantity;
                pTrav = productL.pHead;
                cout << "Products" << endl;
                while (pTrav != NULL)
                {
                    if (pTrav->product_stock < quantity)
                    {
                        cout << pTrav->product_id << " " << pTrav->product_name << " " << pTrav->product_stock << " " << pTrav->product_price << " " << pTrav->product_month << " " << pTrav->product_year << endl;
                    }
                    pTrav = pTrav->pNext;
                }
                //display how many order done by id 
                cout << "order done by customer id" << endl;
                cout << "customer id : ";
                int cid;
                cin >> cid;
                OrderNode* orderTrav = Orders.pHead;
                int ct = 0;
                while (orderTrav != NULL)
                {
                    if (orderTrav->order_id_customer == cid)
                    {
                        ct++;
                    }

                    orderTrav = orderTrav->pNext;
                }

                if (ct == 0)
                {
                    cout << "No order found" << endl;
                }
                else
                {
                    cout << " have " << ct << " orders" << endl;
                }
                // save all data in fils
                ofstream ProductsFileWrite;
                ProductsFileWrite.open("product.txt");

                if (ProductsFileWrite.is_open())
                {
                    ProductNode* pTravWrite = productL.pHead;
                    ProductsFileWrite << "ID" << ",";
                    ProductsFileWrite << "Name" << ",";
                    ProductsFileWrite << "Stock" << ",";
                    ProductsFileWrite << "Price" << ",";
                    ProductsFileWrite << "Exp Month" << ",";
                    ProductsFileWrite << "Exp Year" << endl;

                    while (pTravWrite != NULL)
                    {
                        ProductsFileWrite << pTravWrite->product_id << ",";
                        ProductsFileWrite << pTravWrite->product_name << ",";
                        ProductsFileWrite << pTravWrite->product_stock << ",";
                        ProductsFileWrite << pTravWrite->product_price << ",";
                        ProductsFileWrite << pTravWrite->product_month << ",";
                        ProductsFileWrite << pTravWrite->product_year << endl;

                        pTravWrite = pTravWrite->pNext;
                    }

                    ProductsFile.close();
                }
            }
            else {
                cout << "account not found" << endl;
            }
        }
        else {
            cout << "file not open " << endl;
        }
        adminsFile.close();

    }
    else if (num == 2)
    {
        cout << "Enter username :";
        cin >> name;
        cout << "password :";
        cin >> password;

        CustomerNode* pTravccc = Customers.pHead;
        int login = 0;
        while (pTravccc != NULL)
        {
            // string nn =pTravccc->Customer_pass;
            // cout<<pTravccc->Customer_name<<" "<<nn<<endl;÷
            if (pTravccc->Customer_name == name && pTravccc->Customer_pass == password)
            {
                cout << "login done " << endl;
                login = pTravccc->Customer_id;
                break;
            }
            pTravccc = pTravccc->pNext;
        }
        if (login == 0)
        {
            cout << "account not found" << endl;
            cout << "new account name : ";
            cin >> name;
            cout << "new account password : ";
            cin >> password;
            CustomerNode* pnn = new CustomerNode;
            pnn->Customer_id = Customers.pTail->Customer_id + 1;
            pnn->Customer_name = name;
            pnn->Customer_pass = password;
            pnn->pNext = NULL;
            Customers.Attach(pnn);
            cout << "account created" << endl;
        }
        cout << "done" << endl;
        ProductNode* trav = productL.pHead;
        //display all product > 0
        while (trav != NULL)
        {
            if (trav->product_stock > 0)
            {
                cout << trav->product_id << " " << trav->product_name << " " << trav->product_stock << " " << trav->product_price << " " << trav->product_month << " " << trav->product_year;
                cout << endl;
            }
            trav = trav->pNext;
        }
        //buy
        int total = 0;
        cout << "which product need :";
        int idBuy, q;
        cin >> idBuy;
        cout << "quantity :";
        cin >> q;
        trav = productL.pHead;
        while (trav != NULL)
        {
            if (trav->product_id == idBuy)
            {
                OrderNode* p = new OrderNode;
                p->order_id_customer = login;
                p->order_id_product = trav->product_id;
                p->pNext = NULL;
                Orders.Attach(p);
                trav->product_stock -= q;
                total += q * trav->product_price;
                break;
            }
            trav = trav->pNext;
        }
        // user return
        cout << "which product need to return:";
        int iddBuy, qq;
        cin >> iddBuy;
        cout << "quantity :";
        cin >> qq;
        trav = productL.pHead;
        while (trav != NULL)
        {
            if (trav->product_id == iddBuy)
            {
                trav->product_stock += qq;
                total -= qq * trav->product_price;
                break;
            }
            trav = trav->pNext;
        }
        //Reccipt
        OrderNode* ttrav = Orders.pHead;
        while (ttrav != NULL)
        {
            if (ttrav->order_id_customer == login)
            {
                cout << ttrav->order_id_product << endl;
            }
            ttrav = ttrav->pNext;
        }
        cout << "total :" << total << endl;
        //log out 

        ofstream CustomersFile;
        CustomersFile.open("customer.txt");

        if (CustomersFile.is_open())
        {
            CustomerNode* pTrav = Customers.pHead;

            CustomersFile << "ID" << ",";
            CustomersFile << "Name" << ",";
            CustomersFile << "Password" << endl;

            while (pTrav != NULL)
            {
                CustomersFile << pTrav->Customer_id << ",";
                CustomersFile << pTrav->Customer_name << ",";
                CustomersFile << pTrav->Customer_pass << endl;

                pTrav = pTrav->pNext;
            }

            CustomersFile.close();
        }

        ofstream OrdersFile;
        OrdersFile.open("orders.txt");

        if (OrdersFile.is_open())
        {
            OrderNode* pTrav = Orders.pHead;

            OrdersFile << "Customer ID" << ",";
            OrdersFile << "Product ID" << endl;

            while (pTrav != NULL)
            {
                OrdersFile << pTrav->order_id_customer << ",";
                OrdersFile << pTrav->order_id_product << endl;

                pTrav = pTrav->pNext;
            }

            OrdersFile.close();
        }
    }

}