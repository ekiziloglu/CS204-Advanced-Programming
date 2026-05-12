#include <thread>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <stdio.h>  
#include <string.h>  

using namespace std;

void count1m(int id, struct tm *ptm) {
  // wait until ready
  this_thread::sleep_until(chrono::system_clock::from_time_t (mktime(ptm)));
  for (int i=0; i < 1000000; ++i) {}
  cout << id;
}

int main () {
  //current time in time_t
  time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());

  //new time structs
  struct tm *ptm = std::localtime(&tt);
  cout << "A time to born " << std::put_time(ptm, "%X") << endl;

  ptm->tm_min++; ptm->tm_sec=0; //add 1 minute to that
  cout << "A time to race " << std::put_time(ptm, "%X") << endl;

  //create the threads
  thread threads[10];
  cout << "To the race - turn, turn, turn:\n";
  for (int i=0; i<10; ++i) {threads[i] = thread(count1m, i, ptm);}
  for (thread& th : threads) {th.join();}
  return 0;
}
