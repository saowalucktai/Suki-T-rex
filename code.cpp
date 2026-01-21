#include <iostream>
#include <fstream>
#include <fstream>
using namespace std;
//attribute class
class Menu{
    public:
    //attribute store option from customer
    int customer_num,level_cost,level;
    char refill_water,discount_card;
    //attribute store cost of things
    int Standard_cost = 159,Premium_cost = 239,refill_cost = 20;
    int water_cost = 10,coke_cost = 15,greentea_cost = 30,discount_cost;
    //attribute store quantity of things
    int pork_quantity = 100,beef_quantity = 100;
    int water_quantity = 100,coke_quantity = 100,greentea_quantity = 100;
    //attribute store order of things from customer
    int pork_order,beef_order,water_order,coke_order,greentea_order;
    
};
//class that ask information of customer
class Customer_information : public Menu{
    public:
    int check_ask = 1;
    void askCustomer() {
        cout << "Welcome to suki_T-Rex" << endl;
        cout << "Type Amount Of Customer: ";
        cin >> customer_num;
        
    }
    void askLevel() {
        cout << "---------------" << endl;
        cout << "Please Choose Level of Buffet" << endl;
        cout << "1) Standard(pork) 159 THB\n2) Premium(pork, beef) 239 THB" << endl;
            while(check_ask == 1){
            cout << "Select level 1 or 2: ";
            cin >> level;
            if (level == 1) {
                level_cost = Standard_cost;
                cout << "---------------" << endl;
                break;
            } 
            else if (level == 2){
                level_cost = Premium_cost;
                cout << "---------------" << endl;
                break;
            }else{
                cout<<"Please type only (1 or 2)"<<endl;
            }
            }   
        
    }
    void askRefill();
    void askDiscountCard();
};
//use scope to ask about refill option
void Customer_information::askRefill() {
    char has_refill_water;
    while(check_ask == 1){
        cout << "Do you want refill water? (20 Baht) (Y/N): ";
        cin >> refill_water;
        if(refill_water == 'Y' || refill_water == 'y'){
            greentea_cost = 0,coke_cost = 0,water_cost = 0;
            break;
        }else if(refill_water == 'N' || refill_water == 'n'){
            break;
        }else{
            cout<<"Please type only Y or N"<<endl;
        }
    }        
}
//use scope to ask customer about discount
void Customer_information::askDiscountCard() {
    while(check_ask == 1){
        cout << "Do you have a discount card? (Y/N): ";
        cin >> discount_card;
        if(discount_card == 'Y' || discount_card == 'y'){
            int discount_choice;
            cout << "-----Please choose discount amount-----" << endl;
            cout << "1)50 THB" << endl;
            cout << "2)100 THB" << endl;
            cout << "3)120 THB" << endl;
            cout << "Enter your choice (1-3): ";
            cin >> discount_choice;
            while(check_ask == 1){
            if (discount_choice == 1) {
                discount_cost = 50;
                break;
            }else if (discount_choice == 2) {
                discount_cost = 100;
                break;
            }else if (discount_choice == 3) {
                discount_cost = 150;
                break;
            }else{
                cout << "Please type only (1-3)" << endl;
                break;
            }
            }
            break;
        }else if(discount_card == 'N' || discount_card == 'n'){
            break;
        }else{
            cout<<"Please type only Y or N"<<endl;
        }
    }        
}
//class that ask menu from customer
class Menu_order : public Customer_information{
   public:
   void Order_menu() {
        int check = 1;              //attribute that use to get in loop  
        int order_check,order_type;     //attribute that check desire of customer
        if (level == 1){        //this is condition for customer that select standard_level
           while (check == 1){      //while loop use to get order from customer
                cout<<"-----option-----"<<endl;
                cout<<"1.Order Menu"<<endl;
                cout<<"2.End\nChoose option(1-2): ";
                cin>>order_check;
                    if (order_check == 1){
                        cout<<"------What whould you like to order?-----"<<endl;
                        cout<<"1.pork\n2.water(10 THB if you're not select refill_water)"<<endl;
                        cout<<"3.coke(15 THB if you're not select refill_water)\n4.greentea(25 THB if you're not select refill_water)"<<endl;
                        cout<<"Please choose your order(1-4): ";
                        cin>>order_type;       
                        if (order_type == 1){      //get order from customer      
                            cout<<"Enter the quantity of pork: ";
                            cin>>pork_order;
                            if(pork_quantity == 0){
                            pork_quantity += pork_order;
                            cout<<"Sorry our pork is run out"<<endl;
                            }
                            pork_quantity -= pork_order;
                            if(pork_quantity < 0){
                            pork_quantity += pork_order;
                            cout<<"Sorry we only have "<<pork_quantity<<" quantity  of pork left"<<endl;
                            }
                        }else if(order_type == 2){
                            cout<<"Enter the quantity of water: ";
                            cin>>water_order;
                            if(water_quantity == 0){
                            water_quantity += water_order;
                            cout<<"Sorry our water is run out"<<endl;
                            }
                            water_quantity -= water_order;
                            if(water_quantity < 0){
                            water_quantity += water_order;
                            cout<<"Sorry we only have "<<water_quantity<<" glass of water left"<<endl;
                            }
                        }else if(order_type == 3){
                            cout<<"Enter the quantity of coke: ";
                            cin>>coke_order;
                            if(coke_quantity == 0){
                            coke_quantity += coke_order;
                            cout<<"Sorry our coke is run out"<<endl;
                            }
                            coke_quantity -= coke_order;
                            if(coke_quantity < 0){
                            coke_quantity += coke_order;
                            cout<<"Sorry we only have "<<coke_quantity<<" glass of coke left"<<endl;
                            }
                        }else if(order_type == 4){
                            cout<<"Enter the quantity of greentea: ";
                            cin>>greentea_order;
                            if(greentea_quantity == 0){
                            greentea_quantity += greentea_order;
                            cout<<"Sorry our greentea is run out"<<endl;
                            }
                            greentea_quantity -= greentea_order;
                            if(greentea_quantity < 0){
                            greentea_quantity += greentea_order;
                            cout<<"Sorry we only have "<<greentea_quantity<<" glass of greentea left"<<endl;
                            }
                        }
                    }else if(order_check == 2){
                        break;
                    }else{
                        cout <<"Please type only 1-2"<<endl;
                    }
            }
        }else if(level == 2) {      //this is condition for customer that select premium_level
            while (check == 1){
                cout<<"-----option-----"<<endl;
                cout<<"1.Order Menu"<<endl;
                cout<<"2.End\nChoose opton(1-2): ";
                cin>>order_check;
                if (order_check == 1){
                     cout<<"-----What whould you like to order?-----"<<endl;
                     cout<<"1.pork\n2.beef\n3.water(10 THB if you're not select refill_water)"<<endl;
                     cout<<"4.coke(15 THB if you're not select refill_water)\n5.greentea(25 THB if you're not select refill_water)"<<endl;
                     cout<<"Please choose your order(1-5): ";
                     cin>>order_type;
                     if (order_type == 1){
                        cout<<"Enter the quantity of pork: ";
                        cin>>pork_order;
                        if(pork_quantity == 0){
                            pork_quantity += pork_order;
                            cout<<"Sorry our pork is run out"<<endl;
                            }
                        pork_quantity -= pork_order;
                        if(pork_quantity < 0){
                            pork_quantity += pork_order;
                            cout<<"Sorry we only have "<<pork_quantity<<" quantity of pork left"<<endl;
                         }
                    }else if(order_type == 2){
                        cout<<"Enter the quantity of beef: ";
                        cin>>beef_order;
                        if(beef_quantity == 0){
                            beef_quantity += beef_order;
                            cout<<"Sorry our beef is run out"<<endl;
                            }
                        beef_quantity -= beef_order;
                        if(beef_quantity < 0){
                            beef_quantity += beef_order;
                            cout<<"Sorry we only have "<<beef_quantity<<" quantity of beef left"<<endl;
                        }
                    }else if(order_type == 3){
                        cout<<"Enter the quantity of water: ";
                        cin>>water_order;
                        if(water_quantity == 0){
                            water_quantity += water_order;
                            cout<<"Sorry our water is run out"<<endl;
                            }
                        water_quantity -= water_order;
                        if(water_quantity < 0){
                            water_quantity += water_order;
                            cout<<"Sorry we only have "<<water_quantity<<" glass of water left"<<endl;
                        }
                    }else if(order_type == 4){
                        cout<<"Enter the quantity of coke: ";
                        cin>>coke_order;
                        if(coke_quantity == 0){
                            coke_quantity += coke_order;
                            cout<<"Sorry our coke is run out"<<endl;
                            }
                        coke_quantity -= coke_order;
                        if(coke_quantity < 0){
                            coke_quantity += coke_order;
                            cout<<"Sorry we only have "<<coke_quantity<<" glass of coke left"<<endl;
                        }
                    }else if(order_type == 5){
                        cout<<"Enter the quantity of greentea: ";
                        cin>>greentea_order;
                        if(greentea_quantity == 0){
                            greentea_quantity += greentea_order;
                            cout<<"Sorry our greentea is run out"<<endl;
                            }
                        greentea_quantity -= greentea_order;
                        if(greentea_quantity < 0){
                            greentea_quantity += greentea_order;
                            cout<<"Sorry we only have "<<greentea_quantity<<" glass of greentea left"<<endl;
                            }
                    }
                }else if(order_check == 2){
                    break;
                }else{
                    cout <<"Please type only 1-5"<<endl;
                }
            }
        }    
    cout << "Thank for your order!" << endl;
    cout <<"---------------" << endl; 
    }
};
//class calculate money
class Check_bill : public Menu_order{
    public:

    int calculateCost(int total_cost) const {
        total_cost = level_cost * customer_num;
        total_cost += (coke_cost * coke_order) + (water_cost * water_order) + (greentea_cost * greentea_order);
        return total_cost;
    }

    int calculateCost(int total_cost,bool refill_water) const {
        total_cost = level_cost * customer_num;
        if (refill_water) {
            total_cost += refill_cost * customer_num;
        } else {
            total_cost += (coke_cost * coke_order) + (water_cost * water_order) + (greentea_cost * greentea_order);
        }
        return total_cost;
    }

    int calculateDiscountedCost(int total_cost) const {
        if (discount_card) {
            total_cost -= discount_cost;
        }
        return total_cost;
    }

    int calculateDiscountedCost(int total_cost, bool discount_card) const {
        if (discount_card) {
            total_cost -= discount_cost;
        }
        return total_cost;
    }
};
class FileHandler_customer : public Check_bill {
public:
    void writeToFile(const Check_bill& customer) {
        ofstream file("customer_order.txt");

        if (file.is_open()) {
            file << "Customer Number: " << customer.customer_num << endl;
            file << "Level: " << customer.level << endl;
            file << "Pork order: " << customer.pork_order << endl;
            file << "Beef order: " << customer.beef_order << endl;
            file << "Water order: " << customer.water_order << endl; 
            file << "coke order: " << customer.coke_order << endl;
            file << "greentea order: " << customer.greentea_order << endl;
            file << "Refill Water: " << customer.refill_water << endl;
            file << "discount_card: "<<customer.discount_card << endl;
            int total_cost = customer.calculateCost(0,customer.refill_water);
            char discount_card = customer.discount_card;
            if (discount_card == 'Y' || discount_card == 'y') {
                file << "Discout cost: " << customer.discount_cost <<endl;
                total_cost = customer.calculateDiscountedCost(total_cost);
            }
            file << "Total cost: " << total_cost << " THB" << endl;

            cout << "Order details written to file successfully!" << endl;
           

            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};
class FileHandler_stock : public Check_bill {
public:
    void writeToFile(const Check_bill& customer) {
        ofstream file("Stock.txt");

        if (file.is_open()) {
            file << "Pork quantity: " << customer.pork_quantity << endl;
            file << "Beef quantity: " << customer.beef_quantity << endl;
            file << "Water quantity: " << customer.water_quantity << endl; 
            file << "coke quantity: " << customer.coke_quantity << endl;
            file << "greentea quantity: " << customer.greentea_quantity << endl;
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};
int main(){
    Check_bill customer;
    customer.askCustomer();
    customer.askLevel();
    customer.askRefill();
    customer.Order_menu();
    customer.askDiscountCard();
    int base_cost = customer.calculateCost(0,customer.refill_water);
    int discounted_cost = customer.calculateDiscountedCost(base_cost);
    
    cout <<"---------------" << endl;
    if (customer.refill_water) {
        cout << "Refill Water applied: " << customer.refill_cost << " THB" << endl;
    } else {
        cout << "No refill water applied." << endl;
    }
    if (customer.discount_card) {
        cout << "Discount applied: " << customer.discount_cost << " THB" << endl;
        cout << "Original cost: " << base_cost << " THB" << endl;
        cout << "Total cost: " << discounted_cost << " THB" << endl;
    } else {
        cout << "No discount applied." << endl;
         cout << "Total cost: " << base_cost << " THB" <<endl;
    }
    FileHandler_customer file_customer;
    FileHandler_stock file_stock;
    file_customer.writeToFile(customer);
    file_stock.writeToFile(customer);
}
