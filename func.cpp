#include <string>
#include "func.h"

bool fuzzy_search(const std::string& chunk, const std::string& text){
	if(chunk.length() > text.length())
		return false;
	if(chunk.length() == text.length())
		return chunk == text;
	for(size_t i=0, index=0;i<chunk.length();i++, index++)
		if(std::string::npos == (index = text.find(chunk.at(i), index)))
			return false;
	return true;
}

ULLONG factorial(ULLONG n){
	return (0 == n || 1 == n) ? 1 : factorial(n-1)*n;
}
