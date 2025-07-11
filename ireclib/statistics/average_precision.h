// Copyright (C) 2013  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



namespace ireclib
{
    namespace impl
    {
        inline bool get_bool_part (
            const bool& b
        ) { return b; }

        template <typename T>
        bool get_bool_part(const std::pair<T,bool>& item) { return item.second; }
    }

// ----------------------------------------------------------------------------------------

    template <typename T, typename alloc>
    double average_precision (
        const std::vector<T,alloc>& items,
        unsigned long missing_relevant_items = 0
    )
    {
        using namespace ireclib::impl;
        double relevant_count = 0;
        // find the precision values
        std::vector<double> precision;
        for (unsigned long i = 0; i < items.size(); ++i)
        {
            if (get_bool_part(items[i]))
            {
                ++relevant_count;
                precision.push_back(relevant_count / (i+1));
            }
        }

        double precision_sum = 0;
        double max_val = 0;
        // now sum over the interpolated precision values
        for (std::vector<double>::reverse_iterator i = precision.rbegin(); i != precision.rend(); ++i)
        {
            max_val = std::max(max_val, *i);
            precision_sum += max_val;
        }


        relevant_count += missing_relevant_items;

        if (relevant_count != 0)
            return precision_sum/relevant_count;
        else
            return 1; 
    }

// ----------------------------------------------------------------------------------------

}


