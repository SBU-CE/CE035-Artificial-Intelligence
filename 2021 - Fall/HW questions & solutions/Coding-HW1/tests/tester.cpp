#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream> // std::stringstream, std::stringbuf
#include <string>

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>


using namespace std;


// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

int main(int argc, char const* argv[])
{
    ifstream test_in(argv[1]);  /* This stream reads from test's input file   */
    ifstream test_out(argv[2]); /* This stream reads from test's output file  */
    ifstream user_out(argv[3]); /* This stream reads from user's output file  */

    /* Your code here */
    /* If user's output is correct, return 0, otherwise return 1       */
    string user_ans((istreambuf_iterator<char>(user_out)),
        istreambuf_iterator<char>());
    user_ans = trim(user_ans);
    // std::cout << "user ans : " << user_ans << std::endl;

    string test_ans((istreambuf_iterator<char>(test_out)),
        istreambuf_iterator<char>());
    test_ans = trim(test_ans);
    // std::cout << "test ans : " << test_ans << std::endl;


    // istream& s = test_out;

    stringstream s(test_ans);

    string line_ans;
    while(getline(s, line_ans, '\n')){
        if(line_ans == user_ans){
            return 0;
        }
    }

    return user_ans != test_ans;
}
