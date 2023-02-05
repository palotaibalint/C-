#ifndef MAPARRAY_H
#define MAPARRAY_H


#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <map>


template <typename a, typename b,typename Comparator = std::less<a>>
class map_array_util
{
  private:
    std::map<a,b,Comparator> *current_map;
  public:
    map_array_util( std::map<a,b,Comparator> &m)
    {
     current_map=&m;
    }
    
     void operator=(const b* arr)
    {
      int size=(int)sizeof(arr)/(int)sizeof(int);
      int minimum=std::min(size,(int)current_map->size());
      typename std::map<a,b,Comparator>::iterator it=current_map->begin();
      for(int i=0;i<minimum;i++)
      {
          it->second=arr[i];
          it++;
      }
    }

     bool equals( b C[],int max) const
    {
      bool exit=true;
      int num=0;
      if(max!=(int)current_map->size())
      {
          exit=false;
      }
      for(typename std::map<a,b,Comparator>::const_iterator it=
        current_map->begin();it!=current_map->end() && exit;++it)
      {
        if(it->second!=C[num]){
          exit=false;
        }
        else{
          num++;
        }
      }
      return exit;
    }

    void copy( b C[],int min)
    {
        int minimum=std::min(min,(int)current_map->size());
      typename std::map<a,b,Comparator>::iterator it=current_map->begin();
      for(int i=0;i<minimum;++i)
      {
        it->second=C[i];
        ++it;
      }
    }

    void swap(b arr[],int interval)
    {
      b current_value;
      typename std::map<a,b,Comparator>::iterator it=current_map->begin();
      for(int i=0;i<interval;++i)
      {
        current_value=it->second;
        it->second=arr[i];
        arr[i]=current_value;
        ++it;
      }
    }

     bool permutation( b arr[],int interval) const
    {
        if(interval!=(int)current_map->size())
        {
            return false;
        }
      typename std::map<a,b,Comparator>::const_iterator it=current_map->begin();
      b curr_arr[interval];
      for(int i=0;i<interval;++i)
      {
        curr_arr[i]=it->second;
        ++it;
      }
      Comparator comp;
      std::sort(curr_arr,curr_arr+interval,comp);
      std::sort(arr,arr+interval,comp);
      bool equal=true;
      for(int i=0;i<interval && equal;i++)
      {
        if(arr[i]!=curr_arr[i])
        {
          equal=false;
        }
      }
      return equal;
    }

};
#endif //MAPARRAY_H


