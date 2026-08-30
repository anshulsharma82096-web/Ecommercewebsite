#include <bits/stdc++.h>
using namespace std;

enum category {
    Books,
    Clothes,
    Phone,
    laptop
};

enum OrderStatus {
    Created,
    Confirmed,
    Cancelled
};

enum deliveryStatus {
    Order_processing,
    Shipped,
    out_of_delivery,
    delivered
};

enum PaymentMethod {
    Credit_card,
    UPI,
    cash_on_delivery
};

enum PaymentStatus {
    Payment_pending,
    Payment_Success,
    Payment_Failed,
    Payment_Refunded
};

class Product {
private:
    long Product_id;
    string Name;
    int Price;
    long stock;
    category Category;

public:
    Product(long Product_id, long stock, int Price, string Name, category Category) {
        this->Product_id = Product_id;
        this->Name = Name;
        this->Price = Price;
        this->stock = stock;
        this->Category = Category;
    }

    long getProductId() {
        return Product_id;
    }

    int getPrice() {
        return Price;
    }

    void displayProduct() {
        cout << "Product ID: " << Product_id << endl;
        cout << "Name of Product: " << Name << endl;
        cout << "Price: " << Price << endl;
        cout << "Stock: " << stock << endl;

        cout << "Category: ";

        if (Category == Books)
            cout << "Books";
        else if (Category == Clothes)
            cout << "Clothes";
        else if (Category == Phone)
            cout << "Phone";
        else
            cout << "Laptop";

        cout << endl;
    }

    bool updateStock(long quantity) {
        if (stock + quantity < 0) {
            cout << "Not enough stock available." << endl;
            return false;
        }

        stock = stock + quantity;
        cout << "Stock updated successfully: " << stock << endl;
        return true;
    }

    bool CheckAvailability() {
        if (stock > 0) {
            cout << "Stock is Available" << endl;
            return true;
        }
        else {
            cout << "Stock is not Available" << endl;
            return false;
        }
    }
};

class Customer {
private:
    string customer_id;
    long Phone_number;
    string name;
    string address;
    string Email;

public:
    Customer(string customer_id, long Phone_number, string name,
             string address, string Email) {
        this->customer_id = customer_id;
        this->Phone_number = Phone_number;
        this->name = name;
        this->address = address;
        this->Email = Email;
    }

    string getCustomerId() {
        return customer_id;
    }

    string getaddress() {
        return address;
    }

    string getEmail() {
        return Email;
    }

    long getphonenumber() {
        return Phone_number;
    }

    void setaddress(string adrs) {
        address = adrs;
        cout << "Address Updated successfully" << endl;
    }

    void setEmail(string mail) {
        Email = mail;
        cout << "Email Updated successfully" << endl;
    }

    void setPhonenumber(long phone) {
        Phone_number = phone;
        cout << "Mobile Number updated successfully" << endl;
    }

    void displayCustomer() {
        cout << "\nCustomer ID: " << customer_id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << Email << endl;
        cout << "Phone: " << Phone_number << endl;
        cout << "Address: " << address << endl;
    }
};

union Paymentinfo {
    char last4digit[5];
    char upiid[20];
};

struct Order {
private:
    long order_id;
    string Customer_id;
    long Product_id;
    double Total_amount;
    OrderStatus status;
    PaymentStatus Payment;
    deliveryStatus delivery;
    PaymentMethod method;

public:
    Paymentinfo payment;

    Order(long order_id, string customer_id, long Product_id,
          double total_amount) {

        this->order_id = order_id;
        this->Customer_id = customer_id;
        this->Product_id = Product_id;
        this->Total_amount = total_amount;

        status = Created;
        Payment = Payment_pending;
        delivery = Order_processing;
        method = cash_on_delivery;
    }

    long getOrderId() {
        return order_id;
    }

    string getCustomerId() {
        return Customer_id;
    }

    long getProductId() {
        return Product_id;
    }

    bool validate_Customer_id(string customer_id) {

        if (customer_id.empty()) {
            cout << "Invalid customer ID" << endl;
            return false;
        }

        return true;
    }

    void createorder() {

        if (status == Created) {
            cout << "Order created successfully." << endl;
        }
        else if (status == Confirmed) {
            cout << "Order is ready for shipping." << endl;
        }
        else if (status == Cancelled) {
            cout << "Order is cancelled." << endl;
        }
    }

    void updateOrder() {

        if (status == Cancelled) {
            cout << "Cancelled order cannot be updated." << endl;
            return;
        }

        if (delivery == delivered) {
            cout << "Delivered order cannot be updated." << endl;
            return;
        }

        int choice;

        cout << "\n1. Payment Successful";
        cout << "\n2. Payment Failed";
        cout << "\n3. Shipped";
        cout << "\n4. Out for Delivery";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            Payment = Payment_Success;
            cout << "Payment updated successfully." << endl;
        }
        else if (choice == 2) {
            Payment = Payment_Failed;
            cout << "Payment marked as failed." << endl;
        }
        else if (choice == 3) {
            if (status != Confirmed) {
                cout << "Order must be confirmed first." << endl;
                return;
            }

            delivery = Shipped;
            cout << "Order is shipped." << endl;
        }
        else if (choice == 4) {
            if (delivery != Shipped) {
                cout << "Order must be shipped first." << endl;
                return;
            }

            delivery = out_of_delivery;
            cout << "Order is out for delivery." << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    void confirmorder() {

        if (status == Cancelled) {
            cout << "Cannot confirm a cancelled order." << endl;
        }
        else if (status == Confirmed) {
            cout << "Order is already confirmed." << endl;
        }
        else if (Payment == Payment_Success) {
            status = Confirmed;
            cout << "Order confirmed successfully." << endl;
        }
        else if (Payment == Payment_Failed) {
            cout << "Order cannot be confirmed due to payment failure." << endl;
        }
        else {
            cout << "Order cannot be confirmed. Payment is pending." << endl;
        }
    }

    void cancelOrder() {

        if (delivery == delivered) {
            cout << "Cannot cancel a delivered order!" << endl;
        }
        else if (status == Cancelled) {
            cout << "Order is already cancelled." << endl;
        }
        else {
            status = Cancelled;
            cout << "Order cancelled successfully." << endl;
        }
    }

    void paymentForCancelledOrder() {

        if (status == Cancelled) {

            if (Payment == Payment_Success) {
                Payment = Payment_Refunded;

                cout << "Order is cancelled." << endl;
                cout << "Payment refunded successfully." << endl;
            }
            else {
                cout << "Order is cancelled. No payment refund required." << endl;
            }
        }
        else {
            cout << "Order is not cancelled." << endl;
        }
    }

    void confirmFailedPaymentOrder() {

        Payment = Payment_Failed;

        cout << "Payment failed." << endl;
        cout << "Order cannot be confirmed." << endl;
    }

    void makeDelivered() {

        if (status != Confirmed) {
            cout << "Order must be confirmed before delivery." << endl;
            return;
        }

        delivery = delivered;

        cout << "Order is now delivered." << endl;
    }

    void makePayment() {

        if (status == Cancelled) {
            cout << "Payment cannot be made for a cancelled order." << endl;
            return;
        }

        if (Payment == Payment_Success) {
            cout << "Payment is already successful." << endl;
            return;
        }

        Payment = Payment_Success;

        cout << "Payment successful." << endl;
    }

    void displayOrder() {
        cout << "Order ID: " << order_id << endl;
        cout << "Customer ID: " << Customer_id << endl;
        cout << "Product ID: " << Product_id << endl;
        cout << "Total Amount: " << Total_amount << endl;

        cout << "Order Status: ";

        if (status == Created)
            cout << "Created";
        else if (status == Confirmed)
            cout << "Confirmed";
        else
            cout << "Cancelled";

        cout << endl;

        cout << "Payment Status: ";

        if (Payment == Payment_pending)
            cout << "Payment Pending";
        else if (Payment == Payment_Success)
            cout << "Payment Success";
        else if (Payment == Payment_Failed)
            cout << "Payment Failed";
        else
            cout << "Payment Refunded";

        cout << endl;

        cout << "Delivery Status: ";

        if (delivery == Order_processing)
            cout << "Order Processing";
        else if (delivery == Shipped)
            cout << "Shipped";
        else if (delivery == out_of_delivery)
            cout << "Out for Delivery";
        else
            cout << "Delivered";

        cout << endl;
    }
};

int main() {

    Product p(
        346443,
        2500,
        2000,
        "Asus series laptop",
        laptop
    );

    Customer c1(
        "C101",
        9876543210,
        "Anshul Sharma",
        "Punjab",
        "anshul@gmail.com"
    );

    Customer c2(
        "C102",
        9876501234,
        "Rahul",
        "Delhi",
        "rahul@gmail.com"
    );

    p.displayProduct();


    p.CheckAvailability();

    p.updateStock(500);

    c1.displayCustomer();

    c1.setEmail("newemail@gmail.com");
    c1.setaddress("Jalandhar");
    c1.setPhonenumber(9999999999);

    c1.displayCustomer();

    PaymentMethod method;
    Paymentinfo payment;

    int choice;
    cout << "1. Credit Card" << endl;
    cout << "2. UPI" << endl;
    cout << "3. Cash on Delivery" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {

        method = Credit_card;

        string card;

        cout << "Enter the last four digits: ";
        cin >> card;

        if (card.length() != 4) {
            cout << "Invalid card digits." << endl;
        }
        else {
            strcpy(payment.last4digit, card.c_str());
            cout << "Credit Card selected." << endl;
        }
    }
    else if (choice == 2) {
        method = UPI;
        cout << "Enter UPI ID: ";
        cin >> payment.upiid;

        cout << "UPI selected." << endl;
    }
    else if (choice == 3) {

        method = cash_on_delivery;

        cout << "Cash on Delivery selected." << endl;
        cout << "No additional information required." << endl;
    }
    else {
        cout << "Invalid payment method." << endl;
    }
    Order order1(
        101,
        "C101",
        346443,
        2000
    );
    order1.createorder();
    order1.makePayment();
    order1.confirmorder();
    order1.updateOrder();
    order1.makeDelivered();
    order1.cancelOrder();
    order1.displayOrder();
    Order order2(
        102,
        "C102",
        346443,
        2000
    );

    order2.createorder();

    order2.confirmFailedPaymentOrder();

    order2.confirmorder();

    order2.cancelOrder();

    order2.paymentForCancelledOrder();

    order2.displayOrder();
    order2.validate_Customer_id("");
    Order order3(
        103,
        "C103",
        346443,
        2000
    );
    order3.createorder();
    order3.makePayment();
    order3.confirmorder();
    order3.makeDelivered();
    order3.displayOrder();
    return 0;
}