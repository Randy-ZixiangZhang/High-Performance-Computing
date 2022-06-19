#ifndef DEMO_LIB_H

#include <vector>

/// \brief Calcuates min, max and mean value of the given vector
/// \param page_count a std::vector containing the data
/// \param min_pages the smallest value in the data
/// \param max_pages the largest value in the data
/// \param mean_pages the average value in the data
///
/// Calculates the min, max and mean value.
/// Complexity is O(2*N) where N is the size of the vecotr (yes this is stupid)
/// The mean value is not rounded, Fractions are lost.
void min_max_mean(const std::vector<unsigned int>& page_count,
                  unsigned int& min_pages,
                  unsigned int& max_pages,
                  unsigned int& mean_pages);

#endif // !DEMO_LIB_H
