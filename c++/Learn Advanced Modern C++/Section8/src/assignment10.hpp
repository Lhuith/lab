#ifndef ASSIGNMENT10_H
#define ASSIGNMENT10_H

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

namespace assignment10 {

class url {
    string protocol;
    string resource;
    string separator = "://";

   public:
    url(const string &p, const string &r) : protocol(p), resource(r) {}
    ~url() {}

    void print() { cout << to_string() << endl; }

    string to_string() const { return protocol + separator + resource; }
    bool operator==(const url &o) { return (o.to_string() == to_string()); }
    bool operator!=(const url &o) { return (o.to_string() != to_string()); }
};

bool operator==(const url &l, const url &r) {
    return r == l;
}

class url_cache {
    deque<url> cache;

   public:
    url_cache() {}
    url_cache(const url &c) { store(c); };
    url_cache(const deque<url> &vec) : cache(vec) {}

    void store(const url &c) {
        auto it = find(begin(cache), end(cache), c);

        if (it != cend(cache)) {
            auto temp = *it;
            cache.erase(it);
            cache.push_front(temp);
            return;
        }
        cache.push_front(c);
    }

    void print() {
        if (cache.size() == 0) {
            cout << "cache is empty" << endl;
            return;
        }
        int count{1};
        for (auto u : cache) {
            cout << count++ << " - ";
            u.print();
        }
    }
};

int main() {
    url_cache cache({url{"http", "www.example1.com/index.html"},
                     url{"http", "www.example2.com/index.html"},
                     url{"http", "www.example3.com/index.html"}});
    cache.print();

    cout << "adding new url" << endl;
    cache.store(url{"http", "www.example4.com/index.html"});
    cache.print();

    cout << "adding existing url" << endl;
    cache.store(url{"http", "www.example3.com/index.html"});
    cache.print();

    return 0;
}
}     // namespace assignment10
#endif     // ASSIGNMENT10_H

using namespace std;
