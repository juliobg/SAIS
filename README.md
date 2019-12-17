# C++14 SA-IS algorithm implementation

A suffix array is a sorted array of all suffixes of a string. This an implementation of the SA-IS algorithm to built a suffix array. For example, just calling:

    std::string str("thisastringfortesting");
    auto sa = sais_suffix_array(str);

will produce the following array:

    04 astringfortesting
    15 esting
    11 fortesting
    20 g
    10 gfortesting
    01 hisastringfortesting
    18 ing
    08 ingfortesting
    02 isastringfortesting
    19 ng
    09 ngfortesting
    12 ortesting
    07 ringfortesting
    13 rtesting
    03 sastringfortesting
    16 sting
    05 stringfortesting
    14 testing
    00 thisastringfortesting
    17 ting
    06 tringfortesting

Any string-like or array-like list of integral types that provides its usual operations (i.e, operator[], .size() and range-based for loops) can be used, e.g.:

    std::vector<char> str {'a', 'b', 'c'};
    auto sa = sais_suffix_array(str);
