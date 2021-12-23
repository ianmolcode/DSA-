
/* Program No. 1

Given the coefficients of the quadratic polynomial (float variables), write a C++ program to determine whether the roots are real or complex 
(imaginary). If the roots are real, find them otherwise write the message No real roots.*/ 

#include <iostream>
#include <math.h>
using namespace std;

void roots(int a, int b, int c)
{
if (a == 0) 
{
cout << "Not valid"<<endl;
return;
}
int d = b * b - 4 * a * c;
double sqrt_value = sqrt(abs(d));
if (d > 0) 
{
cout << "Roots are real and different"<<endl;
cout << (double)(-b + sqrt_value) / (2 * a) << "\n"<< (double)(-b - sqrt_value) / (2 * a);
}
else if (d == 0) 
{
cout << "Roots are real and same \n";
cout << -(double)b / (2 * a);
}
else 
{
cout << "Roots are complex \n";
cout << -(double)b / (2 * a) << " + i" << sqrt_value<< "\n"<< -(double)b / (2 * a) << " - i" << sqrt_value;
}
}
int main()
{
int a = 1, b = 7, c = 12;
roots(a, b, c);
return 0;
}


/* Program No. 2

An electricity board charges the following rates to domestic users to discourage large consumption of energy
For the first 100 units:- 60 P per unit For the next 200 units:-80 P per unit Beyond 300 units:-90 P per unit
All users are charged a minimum of Rs 50 if the total amount is more than Rs 300 then an additional surcharge of 15% is added.
WAP to read the names of users and number of units consumed and display the charges with names. */

#include <iostream>
#include<string.h>
using namespace std;
int main()
{
int unit;
float charge,scharge;
string name;
cout<<"Enter Name and Number of units consumed:"<<endl;
getline(cin,name);
cin>>unit;
if(unit<=100)
{
   charge=(0.60*unit);
}
else if(unit>100&&unit<=300)
{
charge=(100*0.60);
charge=charge+((unit-100)*0.80);
}
else if(unit>=300)
{
charge=(100*0.60);
charge=charge+(200*0.80);
charge=charge+((unit-300)*0.90);
}
if(charge<50)
charge=50;
if(charge>300)
{
scharge=(0.15*charge);
charge=charge+scharge;
}
cout<<"Electricity bill :"<<endl;
cout<<name<<" : Rs"<<charge;
return 0;
}

                 



/* Program No. 3

W.A.P in C++ by defining a class to represent a bank account. Include the following -
Data Members
 Name of the depositor
 Account number
 Type of account (Saving, Current etc.)
 Balance amount in the account
Member Functions
 To assign initial values
 To deposit an amount
 To withdraw an amount after checking the balance
 To display name and balance */

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Bank
{
int acno;
char nm[100], acctype[100];
float bal;
public:
Bank(int acc_no, char *name, char *acc_type, float balance) 
{
acno=acc_no;
strcpy(nm, name);
strcpy(acctype, acc_type);
bal=balance;
}
void deposit();
void withdraw();
void display();
};
void Bank::deposit() 
{
int damt1;
cout<<"Enter Deposit Amount = "<<endl;
cin>>damt1;
bal=bal+damt1;
}
void Bank::withdraw() 
{
int wamt1;
cout<<"Enter Withdraw Amount = "<<endl;
cin>>wamt1;
if(wamt1>bal)
cout<<"Cannot Withdraw Amount"<<endl;
bal=bal-wamt1;
}
void Bank::display() 
{
cout<<" ----------------------"<<endl;
cout<<"Account No. : "<<acno<<endl;
cout<<"Name : "<<nm<<endl;
cout<<"Account Type : "<<acctype<<endl;
cout<<"Balance : "<<bal<<endl;
}
int main()
{
int acc_no;
char name[100], acc_type[100];
float balance;
cout<<"\nEnter Details: \n";
cout<<"\n-----------------------\n";
cout<<"Account No. "<<endl;
cin>>acc_no;
cout<<"Name : "<<endl;
cin>>name;
cout<<"Account Type : "<<endl;
cin>>acc_type;
cout<<"Balance : "<<endl;
cin>>balance;
Bank b(acc_no, name, acc_type, balance); 
b.deposit(); 
b.withdraw();  
b.display(); 
return 0;
}

                                          
/*Program No. 4

W.A.P in C++ to show the working of function overloading by using a function named 
calculateArea() to calculate area of square, rectangle and triangle using different signatures as required.*/

#include<iostream>
using namespace std;
int area(int);
int area(int,int);
float area(float);
float area(float,float);
int main()
{
   int s,l,b;
   float r,bs,ht;
   cout<<"Enter side of a square:"<<endl;
   cin>>s;
   cout<<"Enter length and breadth of rectangle:"<<endl;
   cin>>l>>b;
   cout<<"Enter radius of circle:"<<endl;
   cin>>r;
   cout<<"Enter base and height of triangle:"<<endl;
   cin>>bs>>ht;
   cout<<"Area of square is "<<area(s)<<endl;
   cout<<"Area of rectangle is "<<area(l,b)<<endl;
   cout<<"Area of circle is "<<area(r)<<endl;
   cout<<"Area of triangle is "<<area(bs,ht)<<endl;
}
int area(int s)
{
return(s*s);
}
int area(int l,int b)
{
return(l*b);
}
float area(float r)
{
return(3.14*r*r);
}
float area(float bs,float ht)
{
return((bs*ht)/2);
}


/* Program No. 5

Write a Program in C++ to demonstrate the concept of data abstraction using the concept of Class and Objects */

#include <iostream>
using namespace std;
class Abstraction
{
private:
int a, b;
public:
void set(int x, int y)
{  
a = x;
b = y;
} 
void display()
{
cout<<"a = " <<a << endl; 
cout<<"b = " << b << endl;  
}
};
int main()
{
Abstraction ob;
ob.set(10, 20);
ob.display();
return 0;
}


/* Program No. 6

Create a class called Invoice that a hardware store might use to represent an invoice for an item sold at the store. An Invoice should include four pieces of information as instance
Data Members 
· partNumber (type String)
· partDescription (type String)
· quantity of the item being purchased (type int ) price_per_item (type double)
Your class should have a constructor that initializes the four instance variables. 
Provide a set and a get method for each instance variable. 
In addition, provide a method named getInvoiceAmount() that calculates the invoice amount (i.e., multiplies the quantity by the price per item), 
then returns the amount as a double value. If the quantity is not positive, it should be set to 0. If the price per item is not positive, 
it should be set to 0.0. Write a test application named invoiceTest that demonstrates class Invoice capabilities. */ 

#include<iostream>
#include <string>
using namespace std;
class Invoice
{
public:
Invoice( string, string, int, int );
void setPartNumber( string );
string getPartNumber();
void setPartDescription(string);
string getPartDescription();
void setItemQuantity(int);
int getItemQuantity();
void setItemPrice(int);
int getItemPrice();
int getInvoiceAmount();
private:
string partNumber;
string partDescription;
int itemQuantity;
int itemPrice;
};
Invoice::Invoice( string number, string description, int quantity, int price )
{
partNumber=number;
partDescription=description;
if(quantity>0)
itemQuantity=quantity;
else
{
itemQuantity=0;
cout<<"Initial quantity was invalid."<<endl;
}
if(price>0)
itemPrice=price;
else
{
itemPrice=0;
cout<<"Initial price was invalid."<<endl;
}
}
void Invoice::setPartNumber( string number)
{
if ( number.length() <= 25 )
partNumber = number;
if ( number.length() > 25 )
{
partNumber = number.substr( 0, 25 );
cout << "Name \"" << number <<"\" exceeds maximum length (25).\n"<< "Limiting partNumber to first 25 characters.\n" << endl;
}
}
void Invoice::setPartDescription(string description )
{
if ( description.length() <= 25 )
partDescription = description;
if ( description.length() > 25 )
{
partDescription = description.substr( 0, 25 );
cout << "Name \"" << description <<"\" exceeds maximum length (25).\n"<< "Limiting partDescription to first 25 characters.\n" << endl;
}
}
void Invoice::setItemQuantity(int quantity )
{
if(quantity>0)
itemQuantity=quantity;
else
{
itemQuantity=0;
cout<<"Initial quantity was invalid."<<endl;
}
}
void Invoice::setItemPrice(int price )
{
if(price>0)
itemPrice=price;
else
{
itemPrice=0;
cout<<"Initial price was invalid."<<endl;
}
}
string Invoice::getPartNumber()
{
return partNumber;
}
string Invoice::getPartDescription()
{
return partDescription;
}
int Invoice::getItemQuantity()
{
return itemQuantity;
}
int Invoice::getItemPrice()
{
return itemPrice;
}
int Invoice::getInvoiceAmount()
{
return itemQuantity*itemPrice;
}
int main()
{
Invoice Invoice1("ed34","Screw Guage",2,30);
Invoice Invoice2("e322","Screws",10,3);
cout << "Invoice1's initial part number is: "<< Invoice1.getPartNumber()<< "\n and part description is: "<< Invoice1.getPartDescription()<<endl;

cout<< "quantity per item is: "<< Invoice1.getItemQuantity()<< "\nprice per item is: "<< Invoice1.getItemPrice()<< endl;

cout<<"Invoice1's total amount is: "<<Invoice1.getInvoiceAmount()<<endl<<endl;

cout << "Invoice2's initial part number is: "<< Invoice2.getPartNumber()<< "\n and part description is: "<< Invoice2.getPartDescription()<<endl;

cout<< "quantity per item is: "<< Invoice2.getItemQuantity()<< "\nprice per item is: "<< Invoice2.getItemPrice()<< endl;
cout<<"Invoice2's total amount is: "<<Invoice2.getInvoiceAmount()<<endl;
}

// Program No. 7

/*Imagine a tollbooth with a class called TollBooth. The two data items are of type unsigned int and double to hold the total number of cars 
and total amount of money collected. A constructor initializes both of these data members to 0. 
A member function called payingCar( ) increments the car total and adds 0.5 to the cash total. Another function called nonPayCar( ) increments the car total
but adds nothing to the cash total. Finally a member function called display( ) shows the two totals. 
Include a program to test this class. This program should allow the user to push one key to count a paying car , 
and another to count a non paying car.*/

#include<iostream>
using namespace std;
class tollbooth
{
unsigned int car;
double amt;
public:
tollbooth()
{
this->car = 0;
this->amt = 0;
}
void payingcar()
{
this->car++;
this->amt+=0.50;
}
void nonpayingcar()
{
this->car++;
}
void display()
{
cout<<"Number of cars: "<<car<<endl;
cout<<"Amount: "<<amt<<endl;
}
};
int main()
{
char c='y';
int ch;
tollbooth t;
do{
cout<<" 1 for paying \n 2 for nopaying \n 3 Display/Exit \n";
cout<<"Enter choice \n";
cin>>ch;
switch(ch)
{
case 1:
t.payingcar();
cout<<"car added";
break;
case 2:
t.nonpayingcar();
cout<<"car added";
break;
case 3:
t.display();
c='n';
break;
}
// t.display();
if(c=='y'||c=='Y'){
cout<<"\nDo you want to continue";
cin>>c;
}
}
while(c=='y'||c=='Y');
return 0;
}




                            OUTPUT


/* Program No. 8

Create a class called Time that has separate int member data for hours, minutes and seconds. 
One constructor should initialize this data to 0, and another should initialize it to fixed values. 
A member function should display it in 11:59:59 format. A member function named add() should add two objects of type time passed as arguments. 
A main ( ) program should create two initialized values together, leaving the result in the third time variable. Finally it should
display the value of this third variable*/

#include <iostream>
using namespace std;
class time{
private:
int hours,minutes,seconds;
public:
time(){
hours = minutes = seconds = 0;
}
time(int h, int m, int s){
hours = h;
minutes = m;
seconds = s;
}
void showTime() const {
cout << hours << ':' << minutes << ':' << seconds;
}
void addTime(time x, time y){
seconds = x.seconds + y.seconds;
if(seconds>59){
seconds-=60;
minutes++;
}
minutes += x.minutes + y.minutes;
if(minutes>59){
minutes-=60;
hours++;
}
hours+=x.hours+y.hours;
}
};
int main()
{
const time a(2,23,45), b(4,25,15);
time c;
c.addTime(a,b);
c.showTime();
}


/* Program No. 9

Create class SavingsAccount. Use a static variable annualInterestRate to store the annual interest rate for all account holders.Each object of the class contains a private instance variable savingsBalance indicating the amount the saver currently has on deposit. Provide method calculateMonthlyInterest()to calculate the monthly interest by multiplying the savingsBalance by annualInterestRate divided by 12. This interest should be added to savingsBalance. Provide a static method modifyInterestRate that sets the annualInterestRate to a new value. 
Write a program to test class SavingsAccount. Instantiate two savingsAccount objects, saver1 and saver2, with balances of $2000.00 and $3000.00, respectively. Set annualInterestRate to 4%, then calculate the monthly interest and print the new balances for both savers. Then set the annualInterestRate to 5%, calculate the next month interest and print the new balances for both savers. */

#include <iostream>
using namespace std;
class SavingsAccount
{
public:
SavingsAccount(){}
SavingsAccount(int value);
static float annualInterestRate;
void calculateMonthlyInterest();
static void modifyIntererestRate(float value);
float GetBalance() const { return savingsBalance; }
private:
float savingsBalance;
};
SavingsAccount::SavingsAccount(int value)
{
savingsBalance = value;
}
float SavingsAccount::annualInterestRate = 0;
void SavingsAccount::calculateMonthlyInterest()
{
savingsBalance = (savingsBalance+(savingsBalance * annualInterestRate) / 12);
}
void SavingsAccount::modifyIntererestRate(float value)
{
annualInterestRate = value;
}
int main()
{
SavingsAccount saver1(2000.00);
SavingsAccount saver2(3000.00);
SavingsAccount::modifyIntererestRate(4);
saver1.calculateMonthlyInterest();
cout << "Saver 1 Savings Balance: $" << saver1.GetBalance() << endl;
saver2.calculateMonthlyInterest();
cout << "Saver 2 Savings Balance: $" << saver2.GetBalance() << endl;
cout << endl;
SavingsAccount::modifyIntererestRate(5);
saver1.calculateMonthlyInterest();
cout << "Saver 1 Savings Balance: $" << saver1.GetBalance() << endl;
saver2.calculateMonthlyInterest();
cout << "Saver 2 Savings Balance: $" << saver2.GetBalance() << endl;
cout << endl;
return 0;
}


/* Program No. 10

Create a class Complex having two int type variable named real & img denoting real and imaginary part respectively of a complex number. 
Overload + , - , == operator to add, to subtract and to compare two complex numbers being denoted by the two complex type objects. */

#include <iostream>
using namespace std;

class Complex
{
private:
    int real, img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    Complex operator+(Complex obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }
    Complex operator-(Complex obj)
    {
        Complex res;
        res.real = real - obj.real;
        res.img = img - obj.img;
        return res;
    }
    string operator==(Complex obj)
    {
        if (real = obj.real && img == obj.img)
        {
            return "true";
        }
        else
            return "false";
    }
    void display()
    {
        if (img < 0)
        {
            img = 2 * img - img;
            cout << real << " -i" << img << endl;
        }
        else if (img > 1)
        {
            cout << real << " +i" << img << endl;
        }
        else if (img == 1)
        {
            cout << real << " +i" << endl;
        }
        else if (img == 0)
        {
            cout << real << endl;
        }
    }
};

int main()
{
    Complex a(2, 5), b(3, 4), c;

    c = a + b;
    c.display();

    c = a - b;
    c.display();

    string d = (a == b);
    cout << d;
}


/* Program No. 11)a)

Using the concept of operator overloading. Write a program to overload using with friend Function.
a. Unary -
b. Unary ++ preincrement, postincrement
c. Unary -- predecrement, postdecrement */

#include<iostream>
using namespace std;
class UnaryFriend
{
int a=10;
int b=20;
public:
void getvalues()
{
cout<<"Values of A & B\n";
cout<<a<<"\n"<<b<<"\n"<<endl;
}
void show()
{
cout<<a<<"\n"<<b<<"\n"<<endl;
}
void friend operator-(UnaryFriend &x);
void friend operator ++(UnaryFriend &x);
void friend operator --(UnaryFriend &x);
};
void operator-(UnaryFriend &x)
{
x.a = -x.a;
x.b = -x.b;
}
void operator++(UnaryFriend &x)
{
x.a=++x.a;
x.b=x.b++;
}
void operator--(UnaryFriend &x)
{
x.a=--x.a;
x.b=x.b--;
}
int main()
{
UnaryFriend x1;
UnaryFriend x2;
UnaryFriend x3;
x1.getvalues();
cout<<"Before Overloading\n";
x1.show();
cout<<"After Overloading \n";
-x1;
x1.show();
x2.getvalues();
cout<<"Before Pre and Post increment Overloading\n";
x2.show();
cout<<"After Pre and Post increment Overloading \n";
++x2;
x2.show();
x3.getvalues();
cout<<"Before Pre and Post decrement Overloading\n";
x3.show();
cout<<"After Pre and Post decrement Overloading \n";
--x3;
x3.show();
return 0;
}
 

/* Program No. 11)b)

Using the concept of operator overloading. Write a program to overload using without friend Function.
a. Unary -
b. Unary ++ preincrement, postincrement
c. Unary -- predecrement, postdecrement */

#include <iostream>
using namespace std;
int main()
{

int a = 1;
cout << "a value before Unary Minus: " << a << endl;
int b = -a;
cout << "b value after -a : " << b << endl;

a = 1;
cout << "a value Post increment: " << a << endl;
b = a++;
cout << "b value after a++ : " << b << endl; 
cout << "a value after a++ : " << a << endl; 

a = 1;
cout << "a value Pre increment:" << a << endl; 
b = ++a;
cout << "b value after ++a : " << b << endl; 
cout << "a value after ++a : "<< a << endl; 

a = 5;
cout << "a value Post decrement: " << a << endl; 
b = a--;
cout << "b value after a-- : " << b << endl; 
cout << "a value after a-- : " << a << endl; 

a = 5;
cout << "a value Pre decrement: "<< a<<endl; 
b = --a;
cout << "b value after --a : " << b << endl; 
cout << "a value after --a : " << a << endl; 
return 0;
}


             LAB ASSIGNMENT 1 

/* Q1.Create a class called Time that has separate int member data for days, hours, minutes and seconds. One constructor should initialize this data to 0, and another should initialize it to fixed values. A member function should display it in 11:59:59 format. A member function named add() should add two objects of type time passed as arguments and also calculate the total number of days . A main ( ) program should create two initialized values together, leaving the result in the third time variable. Finally it should display the value of this third variable and also the number of days. */

#include<iostream>
using namespace std;
class time
{
    int days,hours,minutes,seconds;
public:
    time()
    {
        days = hours = minutes = seconds=0;
    }
    time(int h,int m,int s)
    {
        hours=h;
        minutes=m;
        seconds=s;
    }
    void showTime()
    {
        cout<<"Days: "<<days<<endl;
        cout<<hours<<":"<<minutes<<":"<<seconds;
    }
    void addTime(time x,time y)
    {
        seconds=x.seconds+y.seconds;
        if(seconds>59)
        {
             seconds=seconds-60;
             minutes++;
        }
        minutes=minutes+x.minutes+y.minutes;
        if(minutes>59)
        {
            minutes=minutes-60;
            hours++;
        }
        hours=hours+x.hours+y.hours;
        while(hours>24)
        {
          hours=hours-24;
          days++;
        }
    }
};
int main()
{
    const time a(56,23,45),b(89,25,15);
    time c;

    c.addTime(a,b);
    c.showTime();
}




            LAB ASSIGNMENT 2

/* Q2. Create a class complex having two int type variable name real and img denoting real and imaginary part of a complex number. Overload “==” operator to compare two complex number being denoted by the two complex type objects. */

#include<iostream>
using namespace std;
class Complex
{
public:
    int real , img;
    Complex(int tempreal=0 , int tempimaginary=0)
    {
        real=tempreal;
        img=tempimaginary;
    }
    Complex compare_comp(Complex c1  , Complex c2)
    {
        if( (c1.real==c2.real ) && (c1.img==c2.img) )
        {
            cout<<"equal  complex number"<<endl;
        }
        else
        {
            cout<<"unequal complex number"<<endl;
        }
    }
};
int main()
{
    Complex  c1(3,2);
    Complex  c2(9,5);
    Complex c3;
    c3=c3.compare_comp(c1,c2);
    Complex c5(2,4);
    Complex c6(2,4);
    Complex c4;
    c4=c4.compare_comp(c5,c6);
    return 0;
}
             LAB ASSIGNMENT 3

/* Q3. Create a base class that consists of private data members and member functions try using different access modifiers for inheriting base class to derived class (i.e try to access private data members of base class into derived class ). */

#include<iostream>
using namespace std;
class base
{
private:
    int pvt=1;
public:
    int getpvt()
    {
        return pvt;
    }
};
class derived:public base
{

};
int main()
{
    derived ob;
    cout<<"private member is :"<<ob.getpvt()<<endl;
}
                              
                                                                


