#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

using namespace std;


int ia[] = {29,23,20,22,17,15,26,51,19,12,35,40,15};
int seq[] = {22,17,15};
vector<int> ivec(ia, ia+sizeof(ia)/sizeof(ia[0]));
list<int> ilist(ia, ia+sizeof(ia)/sizeof(ia[0]));

string sa[] = {"The", "light", "untonsured", "hair", "grained", "and", "hued", "like", "pale", "oak"};
vector<string> svec(sa, sa+sizeof(sa)/sizeof(sa[0]));
list<string> slist(sa, sa+sizeof(sa)/sizeof(sa[0]));

int set1[] = {0,1,2,3};
int set2[] = {0,2,4,6};

vector<int> vec_result;

class TwiceOver
{
    public:
    bool operator()(int val1, int val2)
    {
        return val1 == val2/2 ? true : false;
    }
};

class Even
{
    public:
    bool operator()(int val)
    {
        return val % 2;
    }
};

class EqualAndOdd
{
    public:
    bool operator()(int val1, int val2)
    {
        return (val1 == val2) && (val1 %2);
    }
};

class GenByTwo
{
    public:
    int operator()()
    {
        static int _seed = -1;
        return _seed += 2;
    }
};

class gen_by_two
{
    public:
    gen_by_two(int seed = 0):_seed(seed){}
    int operator()()
    {
        return _seed += 2;
    }
    private:
    int _seed;
};

class size_compare
{
    public:
    bool operator()(const string& str1, const string& str2)
    {
        return str1.length() < str2.length();
    }
};

bool CompSize(const string& str1, const string& str2)
{
    return str1.length() < str2.length();
}

int dobule_val(int val){return val+val;}

int difference(int val1, int val2){return abs(val1 - val2);}
// void print(int x){cout<<"The number is :"<<x<<endl;}
int main()
{
    
    typedef vector<int>::const_iterator Iterator;

    //accumulate
    // int iresult = accumulate(ivec.begin(), ivec.end(), 1, multiplies<int>());
    // cout<<iresult<<endl;
    // iresult = accumulate(ia, ia+12,0);
    // cout<<iresult<<endl;

    //adjacent_difference
    // adjacent_difference(ivec.begin(), ivec.end(),back_inserter(vec_result),multiplies<int>());


    //adjacent_find
    // Iterator it = adjacent_find(ivec.begin(), ivec.end(), TwiceOver());
    // if (it == ivec.end())
    // {
    //     cout<<"not found!\n";
    // }
    // else
    // {
    //     cout <<"found it :"<<*it<<endl;
    // }
    

    //binary_search
    // sort(ivec.begin(), ivec.end());
    // bool result = binary_search(ivec.begin(), ivec.end(),40);
    // cout<< result <<endl;

    //copy
    // copy(ivec.begin(), ivec.end(), back_inserter(vec_result));

    //count
    //cout<<count(ivec.begin(), ivec.end(), 15);

    //count_if
    //cout<<count_if(ivec.begin(), ivec.end(),Even());
    //cout<<count_if(ivec.begin(), ivec.end(),bind2nd(less<int>(),20));
    
    // equal
    // cout<<equal(ivec.begin(), ivec.end(), ilist.begin(),EqualAndOdd());

    // fill
    // fill(ivec.begin(), ivec.begin() + 5, 10);

    //fill_n
    // fill_n(ivec.begin(),5 ,10);

    // find
    // Iterator it = find(ivec.begin(), ivec.end(),40);
    // if (it != ivec.end())
    // {
    //     cout<<"found : "<<*it<<endl;
    // }

    // find_end
    // Iterator it = find_end(ivec.begin(), ivec.end(), seq,seq+3);
    // if (it != ivec.end())
    // {
    //     cout << "found : " << *it << endl;
    // }

    // find_first_of
    // Iterator it = find_first_of(ivec.begin(), ivec.end(),seq,seq+3);
    
    // if (it != ivec.end())
    // {
    //     cout << "found : " << *it << endl;
    // }

    // find_if
    // Iterator it = find_if(ivec.begin(), ivec.end(),bind2nd(less_<int>(),15));
    // if (it != ivec.end())
    // {
    //     cout << "found : " << *it << endl;
    // }

    // generate  generate_n
    // generate(ivec.begin(), ivec.end(),gen_by_two(100));

    // includes
    // sort(ivec.begin(), ivec.end());
    // sort(seq,seq+3);
    // cout<<includes(ivec.begin(), ivec.end(),seq,seq+3);

    // nth_element
    //nth_element(ia, ia+6, ia+12, greater<int>());

    // inner_product
    //cout<<inner_product(ivec1.begin(),ivec1.end(),ivec2.begin(),0,minus<int>(), plus<int>())<<endl;

    // iter_swap
    // iter_swap(ivec.begin(),ivec.begin()+1);

    // max/min
    // cout<<max(12,30)<<endl;

    // min_element/max_element
    // vector<int>::const_iterator iter = min_element(ivec1.begin(),ivec1.end());
    // cout<<*iter<<endl;

    //sort stable_sort
    // sort(ivec1.begin(),ivec1.end());
    // sort(ivec2.begin(),ivec2.end());

    //merge
    // merge(ivec1.begin(),ivec1.end(),ivec2.begin(),ivec2.end(),back_inserter(ivec3));

    // inplace_merge
    // sort(ia, ia + 5);
    // sort(ia + 5, ia+13);
    // inplace_merge(ia, ia + 5, ia+13);

    // for_each
    // for_each(ivec.begin(), ivec.end(),print);

    // lexicographical_compare
    // string sa1[] = {"Piglet", "Pooh", "Tigger"};
    // string sa2[] = {"Piglet", "Pooch", "Eeyore"};
    // cout<<lexicographical_compare(sa1,sa1+3,sa2,sa2+3,CompSize);

    // partial_sort
    // partial_sort(ia, ia+8, ia+13);

    // partial_sum
    // partial_sum(ia, ia+5, back_inserter(vec_result),multiplies<int>());

    // partition stable_partition
    // partition(ivec.begin(), ivec.end(), bind2nd(less<int>(),20));

    // random_shuffle
    // random_shuffle(ivec.begin(), ivec.end());

    // remove remove_if remove_copy remove_copy_if
    // Iterator it = remove_if(ivec.begin(), ivec.end(), bind2nd(less<int>(),20));
    // ivec.erase(it, ivec.end());

    // replace replace_if replace_copy replace_copy_if
    // replace_if(ivec.begin(), ivec.end(), bind2nd(less<int>(),20), 100);

    // reverse
    // reverse(ivec.begin(), ivec.end());

    // rotate
    // rotate(svec.begin(), svec.begin()+3, svec.end());

    // search search_n
    // char str[] = "a fine and private pplace";
    // char ch = 'p';
    // char* p = search_n(str, str+26, 2, ch);
    // cout<<p<<endl;

    // set_difference
    // set_difference(set1,set1+4,set2,set2+4, back_inserter(vec_result));
    // set_intersection
    // set_intersection(set1,set1+4,set2,set2+4, back_inserter(vec_result));
    // set_symmetric_difference
    // set_symmetric_difference(set1,set1+4,set2,set2+4, back_inserter(vec_result));
    // set_union
    // set_union(set1,set1+4,set2,set2+4, back_inserter(vec_result));

    // transform
    // int ia[] = {3,5,8,13,21};
    // vector<int> vec(5), vec2(5);
    // transform(ia, ia+5,vec.begin(),dobule_val);
    // transform(ia,ia+5,vec.begin(),vec2.begin(),difference);

    // unique
    // sort(ivec.begin(),ivec.end());
    // Iterator it = unique(ivec.begin(),ivec.end());
    // ivec.erase(it, ivec.end());

    ostream_iterator<int> os(cout, " ");
    copy(ivec.begin(), ivec.end(), os);
    cout<<endl;


    return 0;
}
