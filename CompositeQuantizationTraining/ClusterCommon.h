#pragma once

#include <exception>
#include <vector>
#include <string>
#include <iostream>

namespace KMC
{
	typedef unsigned char byte;
	typedef float FloatType;
	typedef byte IntegerType;

#define FloatData
#define ConsoleOutput

#ifdef FloatData
	typedef FloatType DataType;
	typedef FloatType CenterType;
#else
	typedef IntegerType DataType;
	typedef FloatType CenterType;
#endif // FloatData
	
	const FloatType MaxDist = 1e20f;

  /*
	class KMCException: public std::exception
    {
    public:
        KMCException() {}

        KMCException(const char * const & info)
            :exception(info)
        {
        }

        KMCException(const std::string& info)
            :exception(info.c_str())
        {
        }
    };
  */
  class IOException : public std::exception
  {
    const char* info_;
  public:
    IOException(const char* const& info)
      : info_(info)
    {
    }
    IOException(const std::string& info)
      : info_(info.c_str())
    {
    }
    virtual const char* what() const throw()
    {
      return info_;
    }
  };
  class KMCException: public std::exception
  {
    const char* info_;
  public:
    KMCException(const char* const& info)
      : info_(info)
    {
    }
    KMCException(const std::string& info)
      : info_(info.c_str())
    {
    }
    virtual const char* what() const throw()
    {
      return info_;
    }
  };

    struct KeyScorePair
    {
        int Key;
        FloatType Score;
        KeyScorePair(int _key = -1, FloatType _score = 0)
            :Key(_key), Score(_score)
        {}
        //__forceinline static bool Compare (KeyScorePair i,KeyScorePair j) { return (i.Score < j.Score || i.Score == j.Score && i.Key < j.Key); }
        inline static bool Compare (KeyScorePair i,KeyScorePair j) { return (i.Score < j.Score || i.Score == j.Score && i.Key < j.Key); }
    };

    template<typename T>
    T StringToValue(const std::string& str);

    template<> std::string StringToValue<std::string>(const std::string& str);
    template<> int StringToValue<int>(const std::string& str);
    template<> float StringToValue<float>(const std::string& str);
    template<> double StringToValue<double>(const std::string& str);
    std::vector<std::string> StringSplit(const std::string &str,const std::string &sep);
}
