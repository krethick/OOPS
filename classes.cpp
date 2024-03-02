#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;



// Creating an abstract class

class AbstractEmployee
{
   virtual void AskForPromotion() = 0; // It is a pure virtual function (IMPLEMENTED ONE RULE)
};

class Employee: AbstractEmployee // Employee signing the contract
{
 private:   
    string Company;
    int Age;
protected:
   string Name;
 public:
    // Getters and Setters
    
    // This is a setter
    void setName(string name) 
    {
      Name = name;
    }

    void setCompany(string company)
    {
        Company = company;
    }

    void setAge(int age)
    {
        if(age>=18)
        Age = age;
        else
        Age = 0;
    }
    
    // This is a getter
    string getName() 
    {
        return Name;
    }

    string getCompany()
    {
        return Company;
    }

    int getAge()
    {
        return Age;
    }
  
    void Introduce()
    {
      cout<<"\n"<<"The Employee Name is : "<<getName()<<endl;
      cout<<"The Company Name is : "<<getCompany()<<endl;
      cout<<"The Age of the Employee is : "<<getAge()<<endl;
      
    }

    void AskForPromotion() 
    {
        
        if(Age>30)
        {
            cout<<Name<<":"<<"Employee is Promoted";
        }
        else
        {
            cout<<Name<<":"<<"Sorry no Promotion";
        }
    }
    
    virtual void Work() // (Virtual) It works in a such a way that if existing Work() is there it executes first like in Developer and Teacher class
    {                   // Incase if not exists this present function gets executed
        cout<<"\n"<<Name<< " is checking email, task backlog, performing tasks..."<<endl;
    }
    
    
    Employee(string name, string company, int age) // Call the Constructor
    {
       Name = name;
       Company = company;
       Age = age;
    }
    
};

// Inheritance (Developer inherititng from Employee)
class Developer: public Employee // Developer is a sub class or derived class and Employee is the super class or Parent class
{
   public:
     string FavProgrammingLanguage;
        
     // Developer Extends the property of employee
     Developer(string name, string company,int age, string favProgrammingLanguage)
           : Employee(name,company,age)// Calling the developer constructor having the parameter value as favProgrammingLanguage
     {
        FavProgrammingLanguage = favProgrammingLanguage;
     }

     void FixBug()  // Create this function
     {
        // We cannot access name directly instead we need to use getters
        // But incase if the Name variable is protected we can directly access it
        cout<<Name<<": Fixed the bug using :" << FavProgrammingLanguage <<endl; // Call the Programming Language
     }

     /*
      void Work() // Polymorphism
      {
        cout<<"\n"<<Name<< " is writing " <<FavProgrammingLanguage<< " code"<<endl;
      }
    */
 
};

//(Teacher inherititng from Employee)
class Teacher : public Employee 
{
   public:
      string Subject;
     

     Teacher(string name, string company, int age, string subject) :  Employee(name,company,age)// Call the Teacher Constructor extends from employee
     {
       Subject = subject;
     }

      void PrepareLesson() 
      {
          cout<<"\n"<<Name<<" :is preparing"<<Subject<<" :lesson"<<endl;
      }
   
   
      void Work() // Polymorphism
    {
        cout<<Name<< " is teaching: " <<Subject<<endl;
    }

};


int main()
{
   
   string name;
   string name1;
   
   string company;
   string company1;
  
   int age;
   int age1;

   string language;
   string subject;
  
   
   cout<<"Enter the Employees Name:"<<endl;
   cin>>name;
   cout<<"Enter the Company's Name:"<<endl;
   cin>>company;
   cout<<"Enter the Age of the Employee:"<<endl;
   cin>>age;
   cout<<"Enter the favourite Programming Language:"<<endl;
   cin>>language;
   

   /*
     Not using this because the Developer extends the property of rmployee
   Employee e1 = Employee(name,company,age); // Create an object of a class
   e1.setName(name);
   e1.setCompany(company);
   e1.setAge(age);

   e1.Introduce();
   e1.AskForPromotion();

   cout<<"\n The Employee Name is : "<<e1.getName()<<endl;
   cout<<"The Company Name is : "<<e1.getCompany()<<endl;
   cout<<"The Age of the Employee is : "<<e1.getAge()<<endl;

   */
   
   // Developer Extends the property of employee
   Developer d1 = Developer(name,company,age,language); // We need to invoke constructor here. In this function we are using only one parameter i.e language
   d1.setName(name);
   d1.setCompany(company);
   d1.setAge(age);

   d1.Introduce();
   d1.FixBug();
   d1.AskForPromotion();
   
   Employee *e1 = &d1;  // Holds the reference/address of the developer
   e1->Work(); // This -> is used when you want to access members using a pointer e1(pointer) ->(accessing) Work() (Member function)

   cout<<"\n Enter the Teachers Name:"<<endl;
   cin>>name1;
   cout<<"Enter the School Name:"<<endl;
   cin>>company1;
   cout<<"Enter the Age of the Employee:"<<endl;
   cin>>age1;
   cout<<"Enter the subject which is being taken:"<<endl;
   cin>>subject;

   Teacher t1 = Teacher(name1,company1,age1,subject); // We need to invoke constructor here. In this function we are using only one parameter i.e language
   t1.setName(name1);
   t1.setCompany(company1);
   t1.setAge(age1);

   t1.Introduce();
   t1.AskForPromotion();

   t1.PrepareLesson(); 
   
   // The most common use of polymorphism is when a parent class reference is used to refer to a child class object.

   // Create a employee pointer

   
   Employee  *e2 = &t1;  // Holds the reference/address of the teacher
   e2->Work(); // This -> is used when you want to access members using a pointer e1(pointer) ->(accessing) Work() (Member function)
 
}