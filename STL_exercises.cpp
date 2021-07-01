#include "STL_exercises_h.h"

bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->rating < r2->rating)
        return true;
    else 
        return false;
}
bool worse(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->price < r2->price)
        return true;
    else 
        return false;
}

bool worseThand(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->rating < r2->rating)
        return false;
    else 
        return true;
}
bool worsed(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->price < r2->price)
        return false;
    else 
        return true;
}

bool FillReview(shared_ptr<Review> &rr)
{
    cout<<"Enter title of book (\"end\" to quit): ";
    getline(cin,rr->title);
    if (rr->title == "end")
        return false;
    cout<<"Enter raiting of book: ";
    cin>>rr->rating;
    if (!cin)
        return false;
    while (cin.get()!='\n')
        continue;
    cout<<"Enter price of book: ";
    cin>>rr->price;
    if (!cin)
        return false;
    while (cin.get()!='\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review> &rr)
{
    cout<<rr->rating<<"\t"<<rr->title<<"\t"<<rr->price<<endl;
}

shared_ptr<Review> makerev()
{
    return shared_ptr<Review>(new Review);
}

void outint(int n){cout<<n<<" ";}

void show_menu()
{
    cout<<"1 to sort by title, 2 to sort by ratings (growing), 3 to sort by price (growing)"<<endl;
    cout<<"4 to sort by rating (descending), 5 to sort by price (descending), Other value to quit "<<endl;
}
void tolow(string & data)
{
    transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
}    