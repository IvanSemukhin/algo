#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <string>
#include "myfunction.h"

// compile string: g++ main.cpp -std=c++11

int main()
{
	std::cout << std::boolalpha;
	std::cout <<"RES = " << fuzzy_search("car", "cartwheel") << std::endl;
	std::cout <<"RES = " << fuzzy_search("cwhl", "cartwheel") << std::endl;
	std::cout <<"RES = " << fuzzy_search("cwheel", "cartwheel") << std::endl;
	std::cout <<"RES = " << fuzzy_search("cartwheel", "cartwheel") << std::endl;
	
	std::cout <<"RES = " << fuzzy_search("cwheeel", "cartwheel") << std::endl;
	std::cout <<"RES = " << fuzzy_search("lw", "cartwheel") << std::endl;
	
	std::cout <<"RES = " << fuzzy_search("w", "cartwheel") << std::endl;
	std::cout <<"RES = " << fuzzy_search("l", "cartwheel") << std::endl;
	std::cout <<"RES = " << fuzzy_search("cl", "cartwheel") << std::endl;
	
    unsigned length = 0;
    std::cout << "Kol elem = " << (length = E(544, 119)) << std::endl;

    std::vector<int> data;
    init_vec(data, length);
    print_vec(data);
    revers_vec(data);
    print_vec(data);
    std::cout << std::endl;

    merge_sort(data, 0, data.size()-1);
    print_vec(data);
    quick_sort(data, 0, data.size()-1);
    print_vec(data);
    insert_sort(data);
    print_vec(data);
    select_sort(data);
    print_vec(data);

    int elem = 0;
    while(std::cin >> elem){
        long index = bin_search(data, elem);
        if(index < 0)
            std::cout << "NOT FOUND!\n";
        else
            std::cout << "index = " << index << std::endl;
    }
    return 0;
}

/*function fuzzysearch (needle, haystack) {
  var hlen = haystack.length;
  var nlen = needle.length;
  if (nlen > hlen) {
    return false;
  }
  if (nlen === hlen) {
    return needle === haystack;
  }
  outer: for (var i = 0, j = 0; i < nlen; i++) {
    var nch = needle.charCodeAt(i);
    while (j < hlen) {
      if (haystack.charCodeAt(j++) === nch) {
        continue outer;
      }
    }
    return false;
  }
  return true;
}

t.equal(fuzzysearch('car', 'cartwheel'), true);
t.equal(fuzzysearch('cwhl', 'cartwheel'), true);
t.equal(fuzzysearch('cwheel', 'cartwheel'), true);
t.equal(fuzzysearch('cartwheel', 'cartwheel'), true);
t.equal(fuzzysearch('cwheeel', 'cartwheel'), false);
t.equal(fuzzysearch('lw', 'cartwheel'), false);*/
