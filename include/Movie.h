#ifndef MOVIE_H
#define MOVIE_H
#include <string>
class Movie{std::string n;int t,b;public:Movie(std::string,int);std::string getMovieName()const;int getAvailableSeats()const;bool bookTicket(int);bool cancelTicket(int);};
#endif