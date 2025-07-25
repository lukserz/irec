// Copyright (C) 2008  Davis E. King (davis@ireclib.net), Nils Labugt
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

    class png_loader : noncopyable
    {
        /*!
            INITIAL VALUE
                Defined by the constructors

            WHAT THIS OBJECT REPRESENTS
                This object represents a class capable of loading PNG image files.
                Once an instance of it is created to contain a PNG file from
                disk you can obtain the image stored in it via get_image().
        !*/

    public:

        png_loader( 
            const char* filename 
        );
        /*!
            ensures
                - loads the PNG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG file.
        !*/

        png_loader( 
            const std::string& filename 
        );
        /*!
            ensures
                - loads the PNG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG file.
        !*/

        png_loader( 
            const ireclib::file& f 
        );
        /*!
            ensures
                - loads the PNG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG file.
        !*/

        png_loader( 
            const unsigned char* image_buffer,
            size_t buffer_size
        );
        /*!
            ensures
                - loads the PNG from memory image_buffer of size buffer_size into this object
            throws
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG buffer.
        !*/

        png_loader( 
            std::istream& in
        );
        /*!
            ensures
                - loads the PNG file from the c++ IO stream into this object
            throws
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG buffer.
        !*/

        ~png_loader(
        );
        /*!
            ensures
                - all resources associated with *this has been released
        !*/

        bool is_gray(
        ) const;
        /*!
            ensures
                - if (this object contains a grayscale image without an alpha channel) then
                    - returns true
                - else
                    - returns false
        !*/
        
        bool is_graya(
        ) const;
        /*!
            ensures
                - if (this object contains a grayscale image with an alpha channel) then
                    - returns true
                - else
                    - returns false
        !*/
        
        bool is_rgb(
        ) const;
        /*!
            ensures
                - if (this object contains a 3 channel RGB image) then
                    - returns true
                - else
                    - returns false
        !*/

        bool is_rgba(
        ) const;
        /*!
            ensures
                - if (this object contains a 4 channel RGB alpha image) then
                    - returns true
                - else
                    - returns false
        !*/

        unsigned int bit_depth (
        ) const;
        /*!
            ensures
                - returns the number of bits per channel in the image contained by this
                  object.  The possible values are 8 or 16.
        !*/

        long nr (
        ) const;
        /*!
            ensures
                - returns the number of rows (height) of the image contained by this
                  object.
        !*/

        long nc (
        ) const;
        /*!
            ensures
                - returns the number of colums (width) of the image contained by this
                  object.
        !*/

        template<
            typename image_type 
            >
        void get_image( 
            image_type& img
        ) const;
        /*!
            requires
                - image_type == an image object that implements the interface defined in
                  ireclib/image_processing/generic_image.h 
            ensures
                - loads the PNG image stored in this object into img
        !*/

    };

// ----------------------------------------------------------------------------------------

    template <
        typename image_type
        >
    void load_png (
        image_type& image,
        const std::string& file_name
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h 
        ensures
            - performs: png_loader(file_name).get_image(image);
    !*/

// ----------------------------------------------------------------------------------------

    template <
        typename image_type,
        typename Byte
        >
    void load_png (
        image_type& image,
        const Byte* image_buffer,
        size_t buffer_size
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h 
            - Byte is either char, int8_t, uint8_t or std::byte
        ensures
            - performs: png_loader(image_buffer, buffer_size).get_image(image);
    !*/
    
// ----------------------------------------------------------------------------------------

    template <
      class image_type
    >
    void load_png (
        image_type& img,
        std::istream& in
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h 
            - in is an input stream containing a complete PNG encoded image
        ensures
            - Reads and ecodes the PNG file located in stream
    !*/

// ----------------------------------------------------------------------------------------

}

