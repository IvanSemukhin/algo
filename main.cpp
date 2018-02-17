#include <iostream>
#include <random>
#include <vector>
#include <string>

#include "tfunc.h"
#include "func.h"

int main()
{
	std::cout << "-----------------------------------------------------\n";
    std::cout << std::boolalpha;
    std::cout << "fuzzy_search(\"car\", \"cartwheel\") is ";
    std::cout << fuzzy_search("car", "cartwheel") << std::endl;
    
    std::cout << "fuzzy_search(\"cwhl\", \"cartwheel\") is ";
    std::cout << fuzzy_search("cwhl", "cartwheel") << std::endl;
    
    std::cout << "fuzzy_search(\"cwheel\", \"cartwheel\") is ";
    std::cout << fuzzy_search("cwheel", "cartwheel") << std::endl;
    
    std::cout << "fuzzy_search(\"cartwheel\", \"cartwheel\") is ";
    std::cout << fuzzy_search("cartwheel", "cartwheel") << std::endl;
    
    std::cout << "fuzzy_search(\"cwheeel\", \"cartwheel\") is ";
    std::cout << fuzzy_search("cwheeel", "cartwheel") << std::endl;
    
    std::cout << "fuzzy_search(\"lw\", \"cartwheel\") is ";
    std::cout << fuzzy_search("lw", "cartwheel") << std::endl;
    
    std::cout << "fuzzy_search(\"l\", \"cartwheel\") is ";
    std::cout << fuzzy_search("l", "cartwheel") << std::endl;
    
    std::cout << "fuzzy_search(\"cl\", \"cartwheel\") is ";
    std::cout << fuzzy_search("cl", "cartwheel") << std::endl;
	std::cout << "-----------------------------------------------------\n";
    unsigned length = 0;
    std::cout << "E(923, 598) = "
			  << (length = E(923, 598)) << std::endl;
			  
    std::cout << "factorial(" << length << ") = "
			  << factorial(length) << std::endl;
	std::cout << "-----------------------------------------------------\n";
    std::vector<int> data;
    init_vec(data, length);
    std::cout << "source array: ";
    print_vec(data);
    revers_vec(data);
    std::cout << "revers array: ";
    print_vec(data);
    std::cout << std::endl;

    merge_sort(data, 0, data.size()-1);
    std::cout << "merge_sort:  ";
    print_vec(data);
    
    quick_sort(data, 0, data.size()-1);
    std::cout << "quick_sort:  ";
    print_vec(data);
    
    insert_sort(data);
    std::cout << "insert_sort: ";
    print_vec(data);
    
    select_sort(data);
    std::cout << "select_sort: ";
    print_vec(data);
	std::cout << "-----------------------------------------------------\n";
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
