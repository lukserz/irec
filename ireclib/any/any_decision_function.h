// Copyright (C) 2010  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    template <class sample_type, class result_type = double>
    using any_decision_function = any_function<result_type(const sample_type&)>;

// ----------------------------------------------------------------------------------------

}


