#include <iostream>
#include <string>
#include <map>


using namespace std;

class Vehicle {
public:
    enum VehicleType {MotorBike, Scotter, Car, Bus};
    
    explicit Vehicle(VehicleType type) : m_type(type) {}
    
    void setPart(string partName, string partValue) {
        m_parts[partName] = partValue;
    }
    
    string getPartValue(string partName) {
        map<string, string>::iterator it = m_parts.find(partName);
        if (it == m_parts.end()) {
            cout<<"Not Found!"<<endl;
            return "NULL";
        }   
        return it->second;
    }
    void show() {
        cout<<"Vehicle Type :"<<m_type<<endl;
        for (map<string, string>::iterator it = m_parts.begin(); it != m_parts.end(); ++it)
            cout<<it->first<<" : "<<it->second<<endl;
        cout<<endl;               
    }  
    
private:
    Vehicle() {}
    
    map<string, string> m_parts;
    VehicleType m_type;
    
};

class VehicleBuilder {
public:
    VehicleBuilder() : m_vehicle(NULL){}
    Vehicle& getVehicle() { return *m_vehicle ;}
    
    virtual ~VehicleBuilder() { 
        delete m_vehicle; 
        m_vehicle = NULL;
    }
    
    virtual void buildDoors() = 0;
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildFrame() = 0;
    
protected:
    Vehicle* m_vehicle;
};

class MotorCycleBuilder : public VehicleBuilder {
public:
    MotorCycleBuilder () {
        m_vehicle = new Vehicle(Vehicle::MotorBike);
    }

    void buildDoors() {
        m_vehicle->setPart("Doors", "2");
    }
    
    void buildEngine() {
        m_vehicle->setPart("Engine", "200 cc");
    }
    
    void buildWheels() {
        m_vehicle->setPart("Wheels", "2");
    }
    
    void buildFrame() {
        m_vehicle->setPart("Frame", "MotorCycle Frame");
    }       
};


class BusBuilder : public VehicleBuilder {
public:
    BusBuilder() {
        m_vehicle = new Vehicle(Vehicle::Bus);
    }

    void buildDoors() {
        m_vehicle->setPart("Doors", "2");
    }
    
    void buildEngine() {
        m_vehicle->setPart("Engine", "Bus Engine 5000 cc");
    }
    
    void buildWheels() {
        m_vehicle->setPart("Wheels", "4");
    }
    
    void buildFrame() {
        m_vehicle->setPart("Frame", "Bus Frame");
    }       
};


int main()
{
    VehicleBuilder *builder = new BusBuilder();
    builder->buildDoors();
    builder->buildFrame();
    builder->buildEngine();
    builder->buildEngine();
    builder->getVehicle().show();
    delete builder;

    builder = new MotorCycleBuilder();
    builder->buildDoors();
    builder->buildFrame();
    builder->buildEngine();
    builder->buildEngine();
    builder->getVehicle().show();
    delete builder;
    
    return 0;    
}

