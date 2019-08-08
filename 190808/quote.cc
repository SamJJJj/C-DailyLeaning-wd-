#include <iostream>

using std::cout;
using std::endl;

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

    virtual ~Quote();

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
    ~BulkQuote()
    {}
private:
    std::size_t _minQty = 0;
    double _discount = 0.0;
};

int main(int argc, char **argv)
{
    return 0;
}