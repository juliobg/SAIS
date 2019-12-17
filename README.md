# C++14 SA-IS algorithm implementation

A suffix array is a sorted array of all suffixes of a string. This an implementation of the SA-IS algorithm to built a suffix array in linear time. For example, just calling:

    std::string str("thisastringfortesting");
    std::vector<int> sa = sais_suffix_array(str);

will produce the following array:

    { 21, 0, 4, 15, 11, 20, 10, 1, 18, 8, 2, 19, 9, 12, 7, 13, 3, 16, 5, 14, 0, 17, 6 }

which corresponds to the suffixes (note empty suffix is also included in the array):

    21
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
