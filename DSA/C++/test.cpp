// erasing from list
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^

  it2=mylist.insert(it2,1);
  std::cout <<"IT1: "<< *it1<<"\n";
  std::cout <<"IT2: "<< *it2<<"\n";
  it1--;
  std::cout <<"IT1: "<< *it1<<"\n";
  
  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  return 0;
}