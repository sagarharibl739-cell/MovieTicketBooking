#include<iostream>
#include"Movie.h"
int main(){Movie m("Avengers",100);m.bookTicket(10);std::cout<<m.getMovieName()<<" "<<m.getAvailableSeats()<<"\n";}