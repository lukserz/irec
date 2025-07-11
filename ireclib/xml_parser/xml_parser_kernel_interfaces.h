// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    class xml_attribute_list_error : public ireclib::error 
    {
        /*!
            WHAT THIS OBJECT REPRESENTS
                This is an exception object thrown by attribute_list objects if you try to
                access a non-existent attribute.
        !*/
    public:
        xml_attribute_list_error(const std::string& msg) : ireclib::error(msg){}
    };

// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------

    class attribute_list : public enumerable<map_pair<std::string,std::string> >
    {

        /*!                
            WHAT THIS OBJECT REPRESENTS
                this object represents a list of the attributes found in
                an XML element.  each attribute is associated with a value.
        !*/


    public:

        inline virtual ~attribute_list (
        ) =0;


        virtual bool is_in_list (
            const std::string& key
        ) const =0;
        /*!
            ensures
                - returns true if there is an attribute named key in the list 
                - returns false
        !*/

        virtual const std::string& operator[] (
            const std::string& key
        ) const =0;
        /*!
            ensures
                if (is_in_list(key) == true) then
                    - returns a const reference to the value associated with the attribute
                      named key.
                - else
                    - throws xml_attribute_list_error
        !*/

    protected:

        // restricted functions
        attribute_list& operator=(attribute_list&) {return *this;}
    };

// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------

    class document_handler
    {
        /*!                
            EXCEPTIONS
                a document_handler is allowed to throw any exception


            WHAT THIS OBJECT REPRESENTS
                this object is an interface for handling the basic events
                generated by an XML parser
        !*/


    public:

        inline virtual ~document_handler (
        ) =0;

        virtual void start_document (
        )=0;
        /*!
            requires
                - is called when the document parsing begins
        !*/

        virtual void end_document (
        )=0;
        /*!
            requires
                - is called after the document parsing has ended.  note that this
                  is always called, even if an error occurs.
        !*/

        virtual void start_element ( 
            const unsigned long line_number,
            const std::string& name,
            const ireclib::attribute_list& atts
        )=0;
        /*!
            requires
                - is called when an opening element tag is encountered.
                - line_number == the line number where the opening tag for this element 
                  was encountered.
                - name == the name of the element encountered 
                - atts == a list containing all the attributes in this element and their 
                  associated values
        !*/

        virtual void end_element ( 
            const unsigned long line_number,
            const std::string& name
        )=0;
        /*!
            requires
                - is called when a closing element tag is encountered. (note that this
                  includes tags such as <example_tag/>.  I.e. the previous tag would
                  trigger a start_element() callback as well as an end_element() callback)
                - line_number == the line number where the closing tag for this 
                  element was encountered and
                - name == the name of the element encountered
        !*/

        virtual void characters ( 
            const std::string& data
        )=0;
        /*!
            requires
                - is called just before we encounter a start_element, end_element, or 
                  processing_instruction tag but only if there was data between the 
                  last and next tag.  
                  (i.e. data will never be "")
                - data == all the normal non-markup data and CDATA between the next and
                  last tag in the document.  
        !*/

        virtual void processing_instruction (
            const unsigned long line_number,
            const std::string& target,
            const std::string& data
        )=0;
        /*!
            requires
                - is called when a processing instruction is encountered
                - line_number == the line number where this processing instruction
                  was encountered 
                - target == the target value for this processing instruction 
                - data == the data value for this processing instruction
        !*/

    protected:

        // restricted functions
        document_handler& operator=(document_handler&) { return *this; }
    };


// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------

    class error_handler
    {
        /*!                
            EXCEPTIONS
                an error_handler is allowed to throw any exception


            WHAT THIS OBJECT REPRESENTS
                this object is an interface for handling the error/warning
                events generated by an XML parser
        !*/

    public:

        inline virtual ~error_handler (
        ) =0;

        virtual void error (
            const unsigned long line_number
        )=0;
        /*!
            requires
                - is called when an error that does NOT require the parser to halt
                  is encountered. (i.e. somewhat minor errors in the input)
                - line_number == the line number where this error was encountered

            the following events trigger an error:
                an invalid processing instruction
        !*/

        virtual void fatal_error (
            const unsigned long line_number
        )=0;
        /*!
            requires
                - is called when an error that requires the parser to abort its parsing
                  is encountered (i.e. fatal errors in the input) 
                - line_number == the line number where this fatal error was encountered

            the following events trigger a fatal_error:
                Everything other than the events listed above for error. 
                Also note that encountering an entity reference other than the 
                predefined ones listed in xml_parser_kernel_abstract is a fatal_error.
                Hitting EOF before the closing tag for the document is also a fatal_error.
        !*/

    protected:

        // restricted functions
        error_handler& operator=(error_handler&) { return *this;}
    };

// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------

    document_handler::~document_handler (
    ){}
    attribute_list::~attribute_list (
    ){}
    error_handler::~error_handler (
    ){}

}


