#include <iostream>
#include <queue>

using namespace std;

class StockTrade {
public:
    void buy() {
        cout<<"Buying stocks"<<endl;
    }
    void sell(){
        cout<<"Selling stocks"<<endl;
    }
};

class StockOrder {
public:
    StockOrder(StockTrade *trade) 
        : m_trade(trade) {
    }
    virtual void execute() = 0;
    
protected:
    StockTrade *m_trade;
};

class BuyStock : public StockOrder {
public:
    BuyStock (StockTrade *trade) 
        : StockOrder(trade) {

    }
    void execute() { //virtual 
        m_trade->buy();
    }
};

class SellStock : public StockOrder {
public:
    SellStock (StockTrade *trade) 
        : StockOrder(trade) {

    }    
    void execute() { //virtual 
        m_trade->sell();
    }
};

class Agent {
public:
    void placeOrder(StockOrder *order) {
        m_orders.push(order);
        order->execute();    
    }

private:
    queue<StockOrder*> m_orders;
};

int main()
{
    StockTrade trade;
    BuyStock buy(&trade);
    SellStock sell(&trade);
    
    Agent agent;
    
    agent.placeOrder(&buy);
    agent.placeOrder(&sell);
    
    return 0;
}
