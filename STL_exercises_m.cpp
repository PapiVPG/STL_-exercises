#include "STL_exercises_h.h"

int main()
{
    /* 1
    vector<int> vi0;

    for (int i = 0; i<1000000;++i)
        vi0.push_back(rand()%100+1);
    
    vector<int>vi;
    vi.insert(vi.begin(),vi0.begin(),vi0.end());
    list<int>li(vi0.begin(),vi0.end());
    

    clock_t start = clock(); 
    sort(vi.begin(),vi.end());
    clock_t finish = clock();
    double doneTime = double(finish-start)/double(CLOCKS_PER_SEC);
    cout<<doneTime<<endl;

    clock_t start2 = clock(); 
    li.sort();
    clock_t finish2 = clock();
    double doneTime2 = double(finish2-start2)/double(CLOCKS_PER_SEC);
    cout<<doneTime2<<endl;

    li.clear();
    li.insert(li.begin(),vi0.begin(),vi0.end());

    clock_t start3 = clock();
    copy(li.begin(),li.end(),vi.begin());
    clock_t finish3 = clock();
    double donetime3 = double(finish3-start3)/double(CLOCKS_PER_SEC);
    cout<<donetime3<<endl;

    clock_t start4 = clock();
    sort(vi.begin(),vi.end());
    clock_t finish4 = clock();
    double donetime4 = double(finish4-start4)/double(CLOCKS_PER_SEC);
    cout<<donetime4<<endl;

    clock_t start5 = clock();
    li.insert(li.begin(),vi.begin(),vi.end());
    clock_t finish5 = clock();
    double donetime5= double(finish5-start5)/double(CLOCKS_PER_SEC);
    cout<<donetime5<<endl;
    */
    //for_each(vi.begin(),vi.end(),outint);
    //cout<<endl;
    //for_each(li.begin(),li.end(),outint);
    //cout<<endl;

    /*
    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp(new Review);
    
    while (FillReview(temp))
    {
        books.push_back(temp);
        temp = makerev();
    }
    if (books.size() > 0)
    {
        int x;
        cout<<"Thanks you got "<<books.size() <<" ratings:\n"<<"Rating \tBook\tPrice\n";
        for_each(books.begin(),books.end(),ShowReview);
        show_menu();
        while(cin>>x && (x>0 && x<=5) ){
        switch (x)
        {
        case 1:
            cout<<"Sorted by title:\nTitle\tBook\tPrice\n";
            sort(books.begin(),books.end());
            break;
        case 2:
            cout<<"Sorted by ratings:\nRating\tBook\tPrice\n";
            sort(books.begin(),books.end(),worseThan);
            break;
        case 3:
            cout<<"Sorted by price:\nRating\tBook\tPrice\n";
            sort(books.begin(),books.end(),worse);
        case 4:
            cout<<"Sorted by ratings (descending):\nRating\tBook\tPrice\n";
            sort(books.begin(),books.end(),worseThand);
            break;
        case 5:
            cout<<"Sorted by price (descending):\nRating\tBook\tPrice\n";
            sort(books.begin(),books.end(),worsed);
            break;
        default:
            cout<<"Wrong value"<<endl;

            break;

        }
        
        for_each(books.begin(),books.end(),ShowReview);
        }
        //random_shuffle(books.begin(),books.end());
        //cout<<"After random shuffle:\nRating\tBook\tPrice\n";
    }else
    {
        cout<<"No data"<<endl;
    }
    
    cout<<"Bye!"<<endl;
    */

    ifstream file("words.txt");
    if (!file.good())
    {
        cout<<"Unable to open"<<endl;
        exit(EXIT_FAILURE);
    }
    vector<string> wordlist;
    string word;
    while (file>>word)
    {
        wordlist.push_back(word);
    }
    file.close();
    int NUM = wordlist.size();

    for_each(wordlist.begin(),wordlist.end(),tolow);
    
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                    continue;
            }
            long loc = target.find(letter);
            if (loc == (long) string::npos)
            {
                cout << "Oh, bad !\n";
                --guesses;
                badchars += letter; 
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc]=letter;
                loc = target.find(letter, loc + 1);
                while (loc != (long) string::npos)
                {
                    attempt[loc]=letter;
                    loc = target.find(letter, loc + 1);
                }
           }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";   
    return 0;
}