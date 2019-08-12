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

class DiscQuote
: public Quote
{
public:
    DiscQuote() = default;
    DiscQuote(const std::string &book, double sales_price, size_t qty, double disc)
    : Quote(book, sales_price)
    , _quantity(qty)
    , _discount(disc)
    {}

    virtual double netPrice(size_t) const = 0;

    ~DiscQuote()
    {}

protected:
    size_t _quantity = 0;
    double _discount = 0.0;
};

class BulkQuote
: public DiscQuote
{
public:
    BulkQuote() = default;
    BulkQuote(const std::string &book, double sales_price, std::size_t minQty, double discount)
    : DiscQuote(book, sales_price, minQty, discount)
    {}
    double netPrice(size_t n) const override
    {
        if(n > _quantity)
            return n * (1 - _discount) * _price;
        else
            return n * _price;
    }

    void debug() const
    {
        cout << "_bookNo: " << isbn() << endl
             << "_price : " << _price << endl
             << "_minQty: " << _quantity << endl
             << "_discount: " << _discount << endl;
    }

    ~BulkQuote()
    {}
};

class MyQuote
: public DiscQuote
{
public:
    MyQuote() = default;
    MyQuote(const std::string &book, double sales_price, std::size_t maxQty, double discount)
    : DiscQuote(book, sales_price, maxQty, discount)
    {}

    double netPrice(std::size_t n) const override
    {
        if(n < _quantity)
        {
            return n * (1 - _discount) * _price;
        }
        else
        {
            return (n - _quantity) * _price + _quantity * (1 - _discount) * _price;
        }
    }

    void debug() const
    {
        cout << "_bookNo: " << isbn() << endl
             << "_price : " << _price << endl
             << "_maxQty: " << _quantity << endl
             << "_discount: " << _discount << endl;
    }
    ~MyQuote()
    {}

};

double printTotal(ostream &os, const DiscQuote &item, size_t n)
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
    BulkQuote bulk("101", 20, 10, 0.1);
    MyQuote my("101", 20, 10, 0.1);
    printTotal(cout, bulk, 20);
    printTotal(cout, my, 20);
    debug(bulk);
    debug(my);
    return 0;
}