#include "ClusterCommon.h"
#include <string>

using namespace std;

namespace KMC
{
    template<> std::string StringToValue<std::string>(const std::string& str)
    {
        return str;
    }

    template<> int StringToValue<int>(const std::string& str)
    {
        return atoi(str.c_str());
    }

    template<> float StringToValue<float>(const std::string& str)
    {
        return float(atof(str.c_str()));
    }

    template<> double StringToValue<double>(const std::string& str)
    {
        return atof(str.c_str());
    }

    /*
    std::vector<std::string> StringSplit(const std::string &str,const std::string &sep)
    {
        char* cstr=const_cast<char*>(str.c_str());
        char* current;
        char* context = NULL;

        std::vector<std::string> arr;
        current=strtok_s(cstr,sep.c_str(), &context);
        while(current!=NULL){
            arr.push_back(current);
            current=strtok_s(NULL,sep.c_str(), &context);
        }
        return arr;
    }
    */
    vector<string> StringSplit(const string& str, const std::string& delim)
    {
      string s(str);
      vector<string> result;
      size_t pos(0);
      string token;
      size_t delimSize(delim.size());
      while ((pos = s.find(delim)) != string::npos) {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimSize);
      }
      return result;
    }

}
