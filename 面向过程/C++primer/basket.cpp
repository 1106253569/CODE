#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <set>
#include <algorithm>
#include <map>
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
    virtual ~Quote()
    {
        std::cout << "Quote::~Quote()\n";
    }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
    {
        printf("Quote::net_price(std::size_t n)\n");
        return n * price;
    }
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }

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
    Bulk_quote *clone() const & { return new Bulk_quote(*this); }
    Bulk_quote *clone() && { return new Bulk_quote(std::move(*this)); }
};
double Bulk_quote::net_price(std::size_t n) const
{
    printf("Bulk_quote::net_price(std::size_t n)\n");
    if(n>=quantity)
        return n * (1 - discount) * price;
        else
            return n * price;
}

class Basket
{
public:
    void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
    double total_receipt(std::ostream &) const;
    void add_item(const Quote &sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote &&sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) 
    { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};
double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend();iter=items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale:" << sum << "\n";
    return sum;
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
