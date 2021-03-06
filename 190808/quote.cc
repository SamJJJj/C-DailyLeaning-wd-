#include <iostream>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
    : _bookNo(book)
    , _price(sales_price)
    {}

    std::string isbn() const { return _bookNo; }

    virtual double netPrice(std::size_t n) const
    {
        return n * _price;
    }

    virtual void debug() const
    {
        cout << "_bookNo: " << _bookNo << endl
             << "_price : " << _price << endl;
    }

    virtual ~Quote()
    {}

private:
    std::string _bookNo;
protected:
    double _price = 0.0;
};

class BulkQuote
: public Quote
{
public:
    BulkQuote() = default;
    BulkQuote(const std::string &book, double sales_price, std::size_t minQty, double discount)
    : Quote(book, sales_price)
    , _minQty(minQty)
    , _discount(discount)
    {}
    double netPrice(std::size_t n) const override
    {
        if(n > _minQty)
            return n * (1 - _discount) * _price;
        else
            return n * _price;
    }

    void debug() const
    {
        cout << "_bookNo: " << isbn() << endl
             << "_price : " << _price << endl
             << "_minQty: " << _minQty << endl
             << "_discount: " << _discount << endl;
    }

    ~BulkQuote()
    {}
private:
    std::size_t _minQty = 0;
    double _discount = 0.0;
};

class MyQuote
: public Quote
{
public:
    MyQuote() = default;
    MyQuote(const std::string &book, double sales_price, std::size_t maxQty, double discount)
    : Quote(book, sales_price)
    , _maxQty(maxQty)
    , _discount(discount)
    {}

    double netPrice(std::size_t n) const override
    {
        if(n < _maxQty)
        {
            return n * (1 - _discount) * _price;
        }
        else
        {
            return (n - _maxQty) * _price + _maxQty * (1 - _discount) * _price;
        }
    }

    void debug() const
    {
        cout << "_bookNo: " << isbn() << endl
             << "_price : " << _price << endl
             << "_maxQty: " << _maxQty << endl
             << "_discount: " << _discount << endl;
    }
    ~MyQuote()
    {}

private:
    std::size_t _maxQty = 0;
    double _discount = 0.0;
};

double printTotal(ostream &os, const Quote &item, size_t n)
{
    double ret = item.netPrice(n);
    os << "ISBN: " << item.isbn()
       << "# sold" << n << " total due: " << ret << endl;
    return ret;
}

void debug(const Quote &item)
{
    item.debug();
}

int main(int argc, char **argv)
{
    Quote basic("101", 20);
    BulkQuote bulk("101", 20, 10, 0.1);
    MyQuote my("101", 20, 10, 0.1);
    printTotal(cout, basic, 20);
    printTotal(cout, bulk, 20);
    printTotal(cout, my, 20);
    debug(basic);
    debug(bulk);
    debug(my);
    return 0;
}