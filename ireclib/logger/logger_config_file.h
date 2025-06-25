// Copyright (C) 2007  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


// ----------------------------------------------------------------------------------------

namespace ireclib
{
    class logger_config_file_error : public error 
    {
        /*!
            WHAT THIS OBJECT REPRESENTS
                This is the exception class used by the configure_loggers_from_file()
                function defined below.
        !*/
    public: 
        logger_config_file_error(const std::string& s):error(s){}
    };

    void configure_loggers_from_file (
        const std::string& file_name
    );
    /*!
        ensures
            - configures the loggers with the contents of the file_name file
        throws
            - ireclib::logger_config_file_error
                this exception is thrown if there is a problem reading the config file
    !*/

    void configure_loggers_from_file (
        const config_reader& cr 
    );
    /*!
        ensures
            - configures the loggers with the contents of cr.  This function is just like
              the above version that reads from a file except that it reads from an in-memory
              config_reader instead.
        throws
            - ireclib::logger_config_file_error
                this exception is thrown if there is a problem reading the config file
    !*/

// ----------------------------------------------------------------------------------------

    /*!  

        

        logger_config
        {
            logging_level = info


            parent_logger 
            {
                logging_level = none
            }


            parent_logger2
            {
                output = file out.txt 

                child_logger
                {
                    logging_level = all

                }
            }
        }

    !*/


}

// ----------------------------------------------------------------------------------------





