#ifndef ASSOC_CONTAINERS_WITH_CUSTOM_H
#define ASSOC_CONTAINERS_WITH_CUSTOM_H

#include <iostream>
#include <map>

using namespace std;

namespace assocContainersWithCustom {

class book_idx {
    std::string author;
    std::string title;

   public:
    book_idx(const std::string& author, const std::string& title) : author(author), title(title) {}
    bool operator<(const book_idx& other) const {
        // if the author is the same, order by title
        if (author == other.author)
            return title < other.title;

        // otherwise, order by author
        return author < other.author;
    }
    friend std::ostream& operator<<(std::ostream& os, const book_idx& bkx) {
        os << bkx.author << ", " << bkx.title;
        return os;
    }
};

class book {
   private:
    string publisher;
    string edition;
    int date;

   public:
    book(string publisher, string edition, int date) : publisher(publisher), edition(edition), date(date) {}
    friend ostream& operator<<(ostream& os, const book& bk) {
        os << "(" << bk.publisher << ", " << bk.edition << "," << bk.date << ")";
        return os;
    }
};

int main() {
    multimap<book_idx, book> library;     // key insert

    // add some books to the library
    book prog_princs("Addison-Wesley", "2nd Edition", 2014);
    book_idx prog_princs_idx{"Stroustrup, Bjarne", "Programming Principles and Practice"};
    library.insert(make_pair(prog_princs_idx, prog_princs));

    book cpp_primer("Addison-Wesley", "5th Edition", 2013);
    book_idx cpp_primer_idx{"Lippmann, Stanley B.", "C++ Primer"};
    library.insert(make_pair(cpp_primer_idx, cpp_primer));

    book cpp_prog("Addison-Wesley", "4th Edition", 2013);
    book_idx cpp_prog_idx{"Stroustrup, Bjarne", "The C++ Programming Language"};
    library.insert(make_pair(cpp_prog_idx, cpp_prog));

    book cpp_tour("Addison-Wesley", "1st Edition", 2018);
    book_idx cpp_tour_idx{"Stroustrup, Bjarne", "A Tour of C++"};
    library.insert(make_pair(cpp_tour_idx, cpp_tour));

    // print out all the books
    for (auto b : library)
        cout << b.first << ", " << b.second << endl;

    return 0;
}
}     // namespace assocContainersWithCustom
#endif     // ASSOC_CONTAINERS_WITH_CUSTOM_H