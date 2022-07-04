#include <iostream>
#include <cbpro++/auth.h>
#include <cbpro++/marketdata/products.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <string>
#include <mutex>
#include "src/CoinbaseRobotCpp.h"

using namespace Robot::CoinbaseCpp;

//#include "src/boolinq/boolinq.h"
/*
std::mutex m;
struct X {
    void foo(int i, const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << ' ' << i << '\n';
    }
    void bar(const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << '\n';
    }
    int operator()(int i) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << i << '\n';
        return i + 10;
    }
};

template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
   auto len = end - beg;
   if (len < 1000)
       return std::accumulate(beg, end, 0);

   RandomIt mid = beg + len/2;
   auto handle = std::async(std::launch::async,
                            parallel_sum<RandomIt>, mid, end);
   int sum = parallel_sum(beg, mid);
   return sum + handle.get();
}
*/
int main() {

  std::cout << "Start" << std::endl;

CoinbaseRobotCpp cr;



std::cout << "Done" << std::endl;


  return 0;
  /*
  int src[] = {10,100,1,2,3,4,5,6};
      int ans[] = {1,  3,  5};
      std::string s = "123h456e78ll9o";

      std::vector<int> vi(src, src + sizeof src / sizeof src[0]);
      std::vector<char> vc(s.begin(), s.end());

      auto rng = boolinq::from(vc);
      auto dst = rng.where([](char a){return std::isalpha(a); });

      std::sort(vi.begin(), vi.end(), std::greater <>());//, std::string::compare);

      for(std::vector<int>::iterator i = vi.begin(); i != vi.end(); ++i)
      {
        std::cout << *i << " ";
          //printf("%s\n", i.c_str);
      }

      std::string apiSecret("USD");

      for (auto &item : dst.toStdVector())
      {
        std::cout << item;
      }
      std::cout << apiSecret << std::endl;

      return 0;


      Auth auth("2e506aa3ec83fb4164e50b79ff0a7fd4", "YN3Zf9zH+zdi53MiKBmjWq267/j+BZQkVt/RXUNyTW+jj2TzT5m58XgTuH1LAvzApvQeaOPkZ7aOhu5WkS828A==", "tzi4cbvjyt", Auth::Mode::LIVE);

      std::vector<responses::product> products = marketdata::products::getProducts(auth);

      for (auto &product : products)
      {
        if (product.getTradingDisabled() || product.getLimitOnly())
          continue;

        std::cout << product.getId() << " " << product.getTradingDisabled() << " " << product.getLimitOnly() << std::endl;
      }
  return 0;



      std::vector<int> v(10000, 1);
      std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';

      X x;
      // Calls (&x)->foo(42, "Hello") with default policy:
      // may print "Hello 42" concurrently or defer execution
      auto a1 = std::async(&X::foo, &x, 42, "Hello");
      // Calls x.bar("world!") with deferred policy
      // prints "world!" when a2.get() or a2.wait() is called
      auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
      // Calls X()(43); with async policy
      // prints "43" concurrently
      auto a3 = std::async(std::launch::async, X(), 43);
      a2.wait();                     // prints "world!"
      std::cout << a3.get() << '\n'; // prints "53"

      return 0;







    auto book = marketdata::products::getOrderBookLevelThree(auth, "BTC-USD");
    auto bids = book.getBids();

    for (auto &bid : bids) {
        //if (std::stoi(bid.getSize()) > 5) {
            std::cout << bid.getPrice() << std::endl;
      //  }
    }
*/
    return 0;
}
