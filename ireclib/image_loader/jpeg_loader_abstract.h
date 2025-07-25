// Copyright (C) 2010  Davis E. King (davis@ireclib.net), Nils Labugt
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

    class jpeg_loader : noncopyable
    {
        /*!
            INITIAL VALUE
                Defined by the constructors

            WHAT THIS OBJECT REPRESENTS
                This object represents a class capable of loading JPEG image files.
                Once an instance of it is created to contain a JPEG file from
                disk you can obtain the image stored in it via get_image().
        !*/

    public:

        jpeg_loader( 
            const char* filename 
        );
        /*!
            ensures
                - loads the JPEG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given JPEG file.
        !*/

        jpeg_loader( 
            const std::string& filename 
        );
        /*!
            ensures
                - loads the JPEG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given JPEG file.
        !*/

        jpeg_loader( 
            const ireclib::file& f 
        );
        /*!
            ensures
                - loads the JPEG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given JPEG file.
        !*/

        jpeg_loader( 
            const unsigned char* imgbuffer,
            size_t buffersize
        );
        /*!
            ensures
                - loads the JPEG from memory imgbuffer of size buffersize into this object
            throws
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given JPEG buffer.
        !*/

        ~jpeg_loader(
        );
        /*!
            ensures
                - all resources associated with *this has been released
        !*/

        bool is_gray(
        ) const;
        /*!
            ensures
                - if (this object contains a grayscale image) then
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
                - loads the JPEG image stored in this object into img
        !*/

    };

// ----------------------------------------------------------------------------------------

    template <
        typename image_type
        >
    void load_jpeg (
        image_type& image,
        const std::string& file_name
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h 
        ensures
            - performs: jpeg_loader(file_name).get_image(image);
    !*/

    template <
        typename image_type
        >
    void load_jpeg (
        image_type& image,
        const unsigned char* imgbuff,
        size_t imgbuffsize
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h 
        ensures
            - performs: jpeg_loader(imgbuff, imgbuffsize).get_image(image);
    !*/

    template <
        typename image_type
        >
    void load_jpeg (
        image_type& image,
        const char* imgbuff,
        size_t imgbuffsize
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h 
        ensures
            - performs: jpeg_loader((unsigned char*)imgbuff, imgbuffsize).get_image(image);
    !*/

// ----------------------------------------------------------------------------------------

}


