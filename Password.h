#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>
#include <vector>
using std::string;

class Password
{
    public:
      Password();
      bool set(string);
      bool authenticate(string);

      int count_leading_characters(string);
      bool has_mixed_case(string);

    private:
      std::vector<string> pass_history;
};
#endif
