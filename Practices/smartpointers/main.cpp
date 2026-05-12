//
//  main.cpp
//  cs204smartPointers
//
//  Created by Eralp  Kızıloğlu on 19.11.2022.
//

#include <iostream>
using namespace std;


/*
int main() {
    
    
  unique_ptr<int> ptr_1 = make_unique<int>(15);
  cout << "*ptr_1: "<< *ptr_1<< endl;

  unique_ptr<string> ptr_2 = make_unique<string>("hello");
  cout<< "*ptr_2: "<< *ptr_2 << endl;

  unique_ptr<int> ptr_3 = make_unique<int>();
  cout << "*ptr_3: "<< *ptr_3<< endl; //0 as default

  unique_ptr<string> ptr_4 = make_unique<string>();
  cout<< "*ptr_4: "<< *ptr_4 << endl; // "" as default

  *ptr_4 += "hello";
  cout<< "*ptr_4: "<< *ptr_4 << endl;

  *ptr_2 += " cs204";
  cout<< "*ptr_2: " << *ptr_2 << endl;
    
    


  
  return 0;
}
 */
 
/*
int main(){
  shared_ptr<int> ptr_1 = make_shared<int>(15);
  cout << "*ptr_1: "<< *ptr_1<< endl;

  shared_ptr<string> ptr_2 = make_shared<string>("hello");
  cout<< "*ptr_2: "<< *ptr_2 << endl;

  shared_ptr<int> ptr_3 = make_shared<int>();
  cout << "*ptr_3: "<< *ptr_3<< endl; //0 as default

  shared_ptr<string> ptr_4 = make_shared<string>();
  cout<< "*ptr_4: "<< *ptr_4 << endl; // "" as default
  *ptr_4 += "hello";
  cout<< "*ptr_4: "<< *ptr_4 << endl;

  return 0;
}
 */



int main(){
    shared_ptr<int>ptr_1 ; //if we give int value depending on the assigning to each other the value of the right one is taken
    shared_ptr<int> ptr_2 = make_shared<int>(25);
    
    
    cout<<"Addresses:"<<"\nobj. of ptr1: "<<ptr_1<<"\nobj. of ptr2: "<<ptr_2<<endl;
    
    
    ptr_1 = ptr_2;
    
    cout<<"Addresses:"<<"\nobj. of ptr1: "<<ptr_1<<"\nobj. of ptr2: "<<ptr_2<<endl;

    cout<<"Values:"<<"\nobj. of ptr1: "<<*ptr_1<< "\nobj. of ptr2: "<<*ptr_2<<endl;

    
    
    
    return 0;
}


/*
int main() {

{
    shared_ptr<MyClass> ptr_1;
    {
      shared_ptr<MyClass> ptr_2 = make_shared<MyClass>();
      cout<<ptr_2.use_count() <<endl;
        ptr_1=ptr_2;
        cout<<ptr_2.use_count() <<endl;
    }
cout<<ptr_1.use_count() <<endl;
}
return 0;
}
*/

/*
int main() {

{
    shared_ptr<int> ptr_1 = make_shared<int>(15);
    shared_ptr<int> ptr_2;
    ptr_2=ptr_1;
    cout<<"ptr_1 count: "<<ptr_1.use_count() <<endl;
    shared_ptr<int> ptr_3 = make_shared<int>(45);
    ptr_3.swap(ptr_1); //keeps reference counting at 2
    cout<< "ptr_1 count: " << ptr_1.use_count()
    <<" ptr_3 count: "<<ptr_3.use_count()<<endl;
    
    cout<<*ptr_1<<endl; //45
    cout<<*ptr_3<<endl; //15
    cout<<*ptr_2<<endl; //15
    
}
return 0;
 
 
}

*/
