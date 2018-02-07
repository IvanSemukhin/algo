#ifndef MYFUNCTION_H
#define MYFUNCTION_H

const double PI = 3.1415926535;

//work with vector section-----------------------------------------------------

template <class X> void print_vec(const std::vector<X>& vec){
    for(auto& elem : vec)
        std::cout << elem << ' ';
    std::cout << std::endl;
}

template <class X> void init_vec(std::vector<X>& vec, unsigned kol){
    vec.clear();
    std::mt19937 gen;
    std::uniform_int_distribution<> uid(0, 30);
    for(unsigned i = 0; i < kol; i++)
        vec.push_back(uid(gen) / PI);
}

template <class X> void revers_vec(std::vector<X>& vec){
    unsigned start = 0;
    unsigned end = vec.size()-1;
    while(start < end)
        std::swap(vec[start++], vec[end--]);
}
//-----------------------------------------------------------------------------

//sort function section--------------------------------------------------------

template <class X> void merge_sort(std::vector<X>& vec, long left, long right){
    if(left < right){
        long half = (right+left)/2;
        merge_sort(vec, left, half);
        merge_sort(vec, half+1, right);
        long pos1 = left;
        long pos2 = half+1;
        long pos3 = 0;
        long size = right-left+1;
        std::vector<X> tmp(size);
        while(pos1 <= half && pos2 <= right)
            if(vec[pos1] < vec[pos2])
                tmp[pos3++] = vec[pos1++];
            else
                tmp[pos3++] = vec[pos2++];
        while(pos1 <= half)
            tmp[pos3++] = vec[pos1++];
        while(pos2 <= right)
            tmp[pos3++] = vec[pos2++];
        for(pos3 = 0; pos3 < size; pos3++)
            vec[left+pos3] = tmp[pos3];
        tmp.clear();
    }
}

template <class X> void quick_sort(std::vector<X>& vec, long left, long right){
    if(left < right){
        long sup = left;
        for(long i = left; i < right; i++)
            if(vec[i] < vec[right])
                std::swap(vec[i], vec[sup++]);
        std::swap(vec[sup], vec[right]);
        quick_sort(vec, left, sup-1);
        quick_sort(vec, sup+1, right);
    }
}

template <class X> void insert_sort(std::vector<X>& vec){
    unsigned len = vec.size();
    for(unsigned i = 1; i < len; i++){
        X elem = vec[i];
        unsigned j = i-1;
        for(;j >= 0 && vec[j] > elem; j--)
            vec[j+1] = vec[j];
        vec[j+1] = elem;
    }
}

template <class X> void select_sort(std::vector<X>& vec){
    unsigned len = vec.size();
    for(unsigned i = 0; i < len-1; i++)
        for(unsigned j = i+1; j< len; j++)
            if(vec[i] > vec[j])
                std::swap(vec[i], vec[j]);
}
//-----------------------------------------------------------------------------

//search function section------------------------------------------------------

template <class X> long bin_search(const std::vector<X>& vec, X elem){
    long left = 0;
    long right = vec.size()-1;
    while(left <= right){
        long half = (left+right)/2;
        if(vec[half] == elem)
            return half;
        else
            vec[half] > elem ? right=half-1 : left=half+1;
    }
    return -1;
}

template <class X> long lin_search(std::vector<X>& vec, X elem){
    long right = vec.size()-1;
    X last = vec[right];
    vec[right] = elem;
    long index = 0;
    while(vec[index] != elem)
        index++;
    vec[right] = last;
    if(index < right || vec[right] == elem)
        return index;
    return -1;
}

bool fuzzy_search(const std::string& chunk, const std::string& text){
	if(chunk.length() > text.length())
		return false;
	if(chunk.length() == text.length())
		return chunk == text;
	for(long i=0, index=0;i<chunk.length();i++, index++)
		if(std::string::npos == (index = text.find(chunk.at(i), index)))
			return false;
	return true;
}
//-----------------------------------------------------------------------------

template <class IntType> IntType E(IntType a, IntType b){
    return b ? E(b, a%b) : a;
}

#endif // MYFUNCTION_H
