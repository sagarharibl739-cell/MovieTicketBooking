#include "Movie.h"
Movie::Movie(std::string x,int s):n(x),t(s),b(0){}
std::string Movie::getMovieName()const{return n;} int Movie::getAvailableSeats()const{return t-b;} bool Movie::bookTicket(int s){if(b+s>t)return false;b+=s;return true;} bool Movie::cancelTicket(int s){if(s>b)return false;b-=s;return true;}