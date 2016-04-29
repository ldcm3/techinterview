
/* A data structure for Least Recently Used (LRU) cache

   Lucas Mendes

*/
#include <list>

int cap = 0;
map<int,list<pair<int, int> >::iterator> mem;
list<pair<int, int> > cache;

LRUCache::LRUCache(int capacity) 
{
    cap = capacity;
    cache.clear();
    mem.clear();
}

// Update position of value in the cache
void updateCache(int key, int value, list<pair<int, int> > :: iterator it)
{
  cache.erase(it);
  cache.push_front(make_pair(key,value));
  mem[key] = cache.begin();
}

int LRUCache::get(int key) 
{
  // if key has been found
  if(mem.find(key) != mem.end())
  {
    // Find iterator of key
    list<pair<int, int> > :: iterator it = mem[key];
      // Value of key
      int tmp = (*it).second;
      
      updateCache(key, tmp, it);
      return tmp;
    }
    // if doesnt exist
    else
        return -1;
}

void LRUCache::set(int key, int value) 
{
  // Key has already been used
  if(mem.find(key) != mem.end())
  {
      list<pair<int, int> > :: iterator it = mem[key];
      updateCache(key,value,it);
  }
  // new key
  else
  {
		
      cache.push_front(make_pair(key,value));
      mem[key] = cache.begin();

      // memory already full
      if(cache.size() > cap)
      {
			
        int tmp = cache.back().first;
			
        // delete oldest cache
        cache.pop_back();
		    mem.erase(tmp);

        }
    }	
}
