/*
  Chapter 10 (Sorting and Searching) Problem 2
*/
#include <string>
#include <vector>
#include <utility>


auto associateAnagrams (std::vector<std::string> &list) {
    std::vector<std::pair<int, std::string>> list2;
    int i = 0;
    std::transform(list.begin(), list.end(), std::back_inserter(list2), [&i] (std::string el) { return std::make_pair(i++, el); });

    for (auto &i : list2) {
        std::sort(i.second.begin(), i.second.end());
    }
    std::sort(list2.begin(), list2.end(), [] (auto &el1, auto &el2) { return el1.second < el2.second; });

    std::vector<std::string> result;
    std::transform(list2.begin(), list2.end(), std::back_inserter(result), [list] (auto &el) {return list[el.first];} );
    return list2;
}


int main () {
    std::vector<std::string> list {"ba", "abb", "bab", "fe", "fee", "eef", "eff", "fee", "ffe"};
    auto list2 = associateAnagrams(list);

}