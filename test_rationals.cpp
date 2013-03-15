#include <iostream>
#include "rationals.hpp"
#include "list.hpp"

int main ()
{
    using namespace std;
    using namespace lego::meta::rationals;
    using namespace lego::meta::list;
    // using namespace lego::units;

    // using t1 = append_n< append_n< list<>, 3, rational<2,1> >::type, 2, rational< 1,4 > >::type;
    // using t2 = append_n< append_n< list<>, 3, rational<1,2> >::type, 2, rational< 2,3 > >::type;
    using t1 = rational<2,1>;
    using t2 = rational<1,4>;
    cout << t1() << " + " << t2() 
         <<  " = " << add_rationals< t1, t2 >::type() 
         << "(" << (t1()+t2()) << ")" << endl;
    cout << t1() << " - " << t2() 
         <<  " = " << subtract_rationals< t1, t2 >::type()
         << "(" << (t1()-t2()) << ")" << endl;
    cout << t1() << " * " << t2() 
         <<  " = " << multiply_rationals< t1, t2 >::type()
         << "(" << (t1()*t2()) << ")" << endl;
    cout << t1() << " / " << t2() 
         <<  " = " << divide_rationals< t1, t2 >::type() 
         << "(" << (t1()/t2()) << ")" << endl;

    cout << "-------------------------" << endl;

    using l1 = append_n< append_n< list<>, 3, rational<2,1> >::type, 2, rational< 1,4 > >::type;
    using l2 = append_n< append_n< list<>, 3, rational<1,2> >::type, 2, rational< 2,3 > >::type;

    cout << "element wise list operations +,-,*,/ " << endl;

    cout << "   " << l1() << endl
         << " + " << l2() << endl
         << "------------------------" << endl
         << " = " << add_list_elements< l1, l2 >::type() << endl
         << "^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

    cout << "   " << l1() << endl
         << " - " << l2() << endl
         << "------------------------" << endl
         << " = " << subtract_list_elements< l1, l2 >::type() << endl
         << "^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

    cout << "   " << l1() << endl
         << " * " << l2() << endl
         << "------------------------" << endl
         << " = " << multiply_list_elements< l1, l2 >::type() << endl
         << "^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

    cout << "   " << l1() << endl
         << " / " << l2() << endl
         << "------------------------" << endl
         << " = " << divide_list_elements< l1, l2 >::type() << endl
         << "^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    // using t3 = add_list_elements< t1, t2 >::type;
    // cout << t3() << endl;
//     cout << -10/gcd(meta::abs(-10),5) << endl;
    // cout << list<t,rational<1,2> >()  << endl;
    cout << "done." << endl;
    return 0;
}
// eof
