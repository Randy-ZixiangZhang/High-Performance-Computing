#include "demo_lib.h"

// These functionalities are only required inside of the definition, not during the declaration (i.e. in the header)
// Include it here and keep the header (which will be visible to others) clean
#include <algorithm>
#include <numeric>

void min_max_mean(const std::vector<unsigned int>& page_count,
                  unsigned int& min_pages, unsigned int& max_pages, unsigned int& mean_pages)
{
  if (page_count.size() == 0)
  {
    min_pages = 0;
    max_pages = 0;
    mean_pages = 0;
  }

  // We could do this with a single loop over the elements, but lets keep the code short.

  // Min max element
  std::pair<std::vector<unsigned int>::const_iterator, std::vector<unsigned int>::const_iterator> min_max = std::minmax_element(page_count.begin(), page_count.end());

  // Copy values from adress pointed to by the iterator
  min_pages = *min_max.first;
  max_pages = *min_max.second;

  // Mean
  mean_pages = std::accumulate(page_count.begin(), page_count.end(), 0) / page_count.size();
  
  return;
}