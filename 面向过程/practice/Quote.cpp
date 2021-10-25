#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book,double sales_price):
                        bookNo(book),price(sales_price){}
    Quote(const Quote &) { printf("Quote(const Quote&)\n"); }
    Quote(Quote &&) { printf("Quote(Quote&&)\n"); }
    Quote &operator=(const Quote &) { printf("Quote& operator=(const Quote&)\n"); return *this; }
    Quote &operator=(Quote &&) { printf("Quote &operator=(Quote&&)\n"); return *this; }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
    {
        printf("Quote::net_price(std::size_t n)\n");
        return n * price;
    }
    virtual ~Quote()
    {
        std::cout << "Quote::~Quote()\n";
    }

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote:public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &s, double sales_price, std::size_t n, double dis):
                                        Quote(s,sales_price),quantity(n),discount(dis){}
    double net_price(std::size_t) const = 0;
    std::pair<size_t,double>discount_policy() const
    {
        return {quantity, discount};
    }
    ~Disc_quote()
    {
        std::cout << "Disc_quote::~Disc_quote()\n";
    }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote:public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &s, double sales_price, std::size_t n, double dis):
                                        Disc_quote(s, sales_price,n,dis){}
    Bulk_quote(const Bulk_quote &B): Disc_quote(B) { printf("Bulk_quote(const Bulk_quote&B)\n"); }
    Bulk_quote(Bulk_quote &&B) : Disc_quote(std::move(B)) { printf("Bulk_quote(Bulk_quote&&B)\n"); }
    Bulk_quote& operator=(const Bulk_quote&B)
    {
        printf("Bulk_quote& operator=(const Bulk_quote&B)\n");
        Quote::operator=(B);
        return *this;
    }
    Bulk_quote& operator=(Bulk_quote&&B) noexcept
    {
        printf("Bulk_quote& operator=(Bulk_quote&&)\n");
        Quote::operator=(std::move(B));
        return *this;
    }
    double net_price(std::size_t) const override;
    ~Bulk_quote()
    {
        std::cout << "Bulk_quote::~Bulk_quote()\n";
    }
};
double Bulk_quote::net_price(std::size_t n) const
{
    printf("Bulk_quote::net_price(std::size_t n)\n");
    if(n>=quantity)
        return n * (1 - discount) * price;
        else
            return n * price;
}

int main()
{
    double print_total(std::ostream & os, const Quote &item, size_t n);
    Quote base("0-201-82470-1",50);
    print_total(std::cout, base, 10);
    Bulk_quote derived("0-201-82470-1", 50, 5, 0.19);
    print_total(std::cout, derived, 10);
    base = derived;
    print_total(std::cout, base, 10);
    return 0;
}

double print_total(std::ostream&os,const Quote &item,size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << "\n"
       << "sold: " << n << "\ttotal due: " << ret << "\n";
    return ret;
}