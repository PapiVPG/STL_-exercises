#ifndef STL_EXERCISES_H
#define STL_EXERCISES_H

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

const int MIN_PER_HR = 60;



struct Review
{
    string title;
    int rating;
    double price;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseThand(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worse(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worsed(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool FillReview(shared_ptr<Review> &rr);
void ShowReview(const shared_ptr<Review> &rr);
shared_ptr<Review> makerev();
void outint(int n);
void show_menu();
void tolow(string & data);
   



#endif