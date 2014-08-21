#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    Employee(string name, string phone)
        : m_name(name)
        , m_phone(phone) {
        
        }
        
        virtual void display() = 0;

protected:
    string m_name;
    string m_phone;  
};

class Engineer : public Employee {
public:
    Engineer(string name, string phone)
        : Employee(name, phone) {
    }

    void display() {
        cout<<"Engineer( Name : "<<m_name<<" , Phone : "<<m_phone<<")"<<endl;
    }
};

class Manager : public Employee {
public:
    Manager(string name, string phone) 
        : Employee(name, phone) {
       
    }
    
    void addReportee(Employee* employee) {
        m_reportees.push_back(employee);
    }
    
    void display() {
        cout<<"Manager( Name : "<<m_name<<" , Phone : "<<m_phone<<")"<<endl;
        for (vector<Employee*>::iterator it = m_reportees.begin(); it != m_reportees.end(); ++it) {
            cout<<"\t";
            (*it)->display();
        }
        cout<<endl;    
    }

private:
    vector<Employee*> m_reportees;
};

int main()
{
    Employee *dev1 = new Engineer("XYZ", "6789");
    Employee *dev2 = new Engineer("PQR", "2345");
    
    Employee *manager = new Manager("ABC", "1234");
    dynamic_cast<Manager*>(manager)->addReportee(dev1);
    dynamic_cast<Manager*>(manager)->addReportee(dev2);
    
    dev1->display();
    dev2->display();
    manager->display();
    
    
    delete manager;
    return 0;    
}
