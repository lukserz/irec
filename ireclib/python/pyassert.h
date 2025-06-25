// Copyright (C) 2013  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


    {if ( !(_exp) )                                                         \
    {                                                                       \
        namespace py = pybind11;                                            \
        PyErr_SetString( PyExc_ValueError, _message );                      \
        throw py::error_already_set();                                      \
    }}


