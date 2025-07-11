// Copyright (C) 2006  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


// GCC 4.8 gives false alarms about some matrix operations going out of bounds.  Disable
// these false warnings.

namespace ireclib
{

// ----------------------------------------------------------------------------------------

    /*!
        A matrix layout object is any object that contains a templated class called "layout"
        with an interface identical to one below:
        (Note that all the template arguments are just the template arguments from the ireclib::matrix 
        object and the member functions are defined identically to the ones with the same 
        signatures inside the matrix object.)

        struct matrix_layout
        {
            template <
                typename T,
                long num_rows,
                long num_cols,
                typename mem_manager
                >
            class layout 
            {
            public:

                T& operator() (
                    size_t r, 
                    size_t c
                );

                const T& operator() (
                    size_t r, 
                    size_t c
                );

                T& operator() (
                    size_t i 
                );

                const T& operator() (
                    size_t i
                ) const;

                void swap(
                    layout& item
                );

                long nr (
                ) const;

                long nc (
                ) const;

                void set_size (
                    size_t nr_,
                    size_t nc_
                );
            };
        };
    !*/

// ----------------------------------------------------------------------------------------

    struct row_major_layout
    {
        // if a matrix is bigger than this many bytes then don't put it on the stack
        const static size_t max_stack_based_size = 256;

        // this is a hack to avoid a compile time error in visual studio 8.  I would just 
        // use sizeof(T) and be done with it but that won't compile.  The idea here 
        // is to avoid using the stack allocation of the layout object if it 
        // is going to contain another matrix and also avoid asking for the sizeof()
        // the contained matrix.
        template <typename T>
        struct get_sizeof_helper
        {
            const static std::size_t val = sizeof(T);
        };

        template <typename T, long NR, long NC, typename mm, typename l>
        struct get_sizeof_helper<matrix<T,NR,NC,mm,l> >
        {
            const static std::size_t val = 1000000;
        };

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager,
            int val = static_switch <
                // when the sizes are all non zero and small
                (num_rows*num_cols*get_sizeof_helper<T>::val <= max_stack_based_size) && (num_rows != 0 && num_cols != 0),
            // when the sizes are all non zero and big 
            (num_rows*num_cols*get_sizeof_helper<T>::val >  max_stack_based_size) && (num_rows != 0 && num_cols != 0),
            num_rows == 0 && num_cols != 0,
            num_rows != 0 && num_cols == 0,
            num_rows == 0 && num_cols == 0
            >::value
            >
        class layout ;
        /*!
            WHAT THIS OBJECT REPRESENTS
                This object represents the actual allocation of space for a matrix.
                Small matrices allocate all their data on the stack and bigger ones
                use a memory_manager to get their memory.
        !*/

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,1> : noncopyable // when the sizes are all non zero and small
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout() {}

            T& operator() (
                size_t r, 
                size_t c
            ) { return *(data+r*num_cols + c); }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return *(data+r*num_cols + c); }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                for (long r = 0; r < num_rows; ++r)
                {
                    for (long c = 0; c < num_cols; ++c)
                    {
                        exchange((*this)(r,c),item(r,c));
                    }
                }
            }

            long nr (
            ) const { return num_rows; }

            long nc (
            ) const { return num_cols; }

            void set_size (
                size_t ,
                size_t 
            )
            {
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:
            T data[num_rows*num_cols];
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,2> : noncopyable // when the sizes are all non zero and big 
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ) { data = pool.allocate_array(num_rows*num_cols); }

            ~layout ()
            { pool.deallocate_array(data); }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[r*num_cols + c]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[r*num_cols + c]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                pool.swap(item.pool);
            }

            long nr (
            ) const { return num_rows; }

            long nc (
            ) const { return num_cols; }

            void set_size (
                size_t ,
                size_t 
            )
            {
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:

            T* data;
            typename mem_manager::template rebind<T>::other pool;
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,3> : noncopyable // when num_rows == 0 && num_cols != 0,
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ):data(0), nr_(0) { }

            ~layout ()
            { 
                if (data) 
                    pool.deallocate_array(data); 
            }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[r*num_cols + c]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[r*num_cols + c]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                std::swap(item.nr_,nr_);
                pool.swap(item.pool);
            }

            long nr (
            ) const { return nr_; }

            long nc (
            ) const { return num_cols; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (data) 
                {
                    pool.deallocate_array(data);
                }
                data = pool.allocate_array(nr*nc);
                nr_ = nr;
            }

            std::unique_ptr<T[]> steal_memory()
            {
                auto ret = pool.extract_array(data);
                data = nullptr;
                nr_ = 0;
                return ret;
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:

            T* data;
            long nr_;
            typename mem_manager::template rebind<T>::other pool;
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,4> : noncopyable // when num_rows != 0 && num_cols == 0
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ):data(0), nc_(0) { }

            ~layout ()
            { 
                if (data) 
                {
                    pool.deallocate_array(data);
                }
            }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[r*nc_ + c]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[r*nc_ + c]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                std::swap(item.nc_,nc_);
                pool.swap(item.pool);
            }

            long nr (
            ) const { return num_rows; }

            long nc (
            ) const { return nc_; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (data) 
                {
                    pool.deallocate_array(data);
                }
                data = pool.allocate_array(nr*nc);
                nc_ = nc;
            }

            std::unique_ptr<T[]> steal_memory()
            {
                auto ret = pool.extract_array(data);
                data = nullptr;
                nc_ = 0;
                return ret;
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:

            T* data;
            long nc_;
            typename mem_manager::template rebind<T>::other pool;
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,5> : noncopyable // when num_rows == 0 && num_cols == 0
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ):data(0), nr_(0), nc_(0) { }

            ~layout ()
            { 
                if (data) 
                {
                    pool.deallocate_array(data);
                }
            }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[r*nc_ + c]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[r*nc_ + c]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                std::swap(item.nc_,nc_);
                std::swap(item.nr_,nr_);
                pool.swap(item.pool);
            }

            long nr (
            ) const { return nr_; }

            long nc (
            ) const { return nc_; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (data) 
                {
                    pool.deallocate_array(data);
                }
                data = pool.allocate_array(nr*nc);
                nr_ = nr;
                nc_ = nc;
            }

            std::unique_ptr<T[]> steal_memory()
            {
                auto ret = pool.extract_array(data);
                data = nullptr;
                nr_ = 0;
                nc_ = 0;
                return ret;
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }
        private:
            T* data;
            long nr_;
            long nc_;
            typename mem_manager::template rebind<T>::other pool;
        };

    };

// ----------------------------------------------------------------------------------------

    struct column_major_layout
    {
        // if a matrix is bigger than this many bytes then don't put it on the stack
        const static size_t max_stack_based_size = 256;


        // this is a hack to avoid a compile time error in visual studio 8.  I would just 
        // use sizeof(T) and be done with it but that won't compile.  The idea here 
        // is to avoid using the stack allocation of the layout object if it 
        // is going to contain another matrix and also avoid asking for the sizeof()
        // the contained matrix.
        template <typename T>
        struct get_sizeof_helper
        {
            const static std::size_t val = sizeof(T);
        };

        template <typename T, long NR, long NC, typename mm, typename l>
        struct get_sizeof_helper<matrix<T,NR,NC,mm,l> >
        {
            const static std::size_t val = 1000000;
        };

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager,
            int val = static_switch <
                // when the sizes are all non zero and small
                (num_rows*num_cols*get_sizeof_helper<T>::val <= max_stack_based_size) && (num_rows != 0 && num_cols != 0),
            // when the sizes are all non zero and big 
            (num_rows*num_cols*get_sizeof_helper<T>::val > max_stack_based_size) && (num_rows != 0 && num_cols != 0),
            num_rows == 0 && num_cols != 0,
            num_rows != 0 && num_cols == 0,
            num_rows == 0 && num_cols == 0
            >::value
            >
        class layout ;
        /*!
            WHAT THIS OBJECT REPRESENTS
                This object represents the actual allocation of space for a matrix.
                Small matrices allocate all their data on the stack and bigger ones
                use a memory_manager to get their memory.
        !*/

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,1> : noncopyable // when the sizes are all non zero and small
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout() {}

            T& operator() (
                size_t r, 
                size_t c
            ) { return *(data+c*num_rows + r); }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return *(data+c*num_rows + r); }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                for (long r = 0; r < num_rows; ++r)
                {
                    for (long c = 0; c < num_cols; ++c)
                    {
                        exchange((*this)(r,c),item(r,c));
                    }
                }
            }

            long nr (
            ) const { return num_rows; }

            long nc (
            ) const { return num_cols; }

            void set_size (
                size_t,
                size_t 
            )
            {
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:
            T data[num_cols*num_rows];
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,2> : noncopyable // when the sizes are all non zero and big 
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ) { data = pool.allocate_array(num_rows*num_cols); }

            ~layout ()
            { pool.deallocate_array(data); }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[c*num_rows + r]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[c*num_rows + r]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                pool.swap(item.pool);
            }

            long nr (
            ) const { return num_rows; }

            long nc (
            ) const { return num_cols; }

            void set_size (
                size_t ,
                size_t 
            )
            {
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:

            T* data;
            typename mem_manager::template rebind<T>::other pool;
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,3> : noncopyable // when num_rows == 0 && num_cols != 0,
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ):data(0), nr_(0) { }

            ~layout ()
            { 
                if (data) 
                    pool.deallocate_array(data); 
            }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[c*nr_ + r]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[c*nr_ + r]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                std::swap(item.nr_,nr_);
                pool.swap(item.pool);
            }

            long nr (
            ) const { return nr_; }

            long nc (
            ) const { return num_cols; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (data) 
                {
                    pool.deallocate_array(data);
                }
                data = pool.allocate_array(nr*nc);
                nr_ = nr;
            }

            std::unique_ptr<T[]> steal_memory()
            {
                auto ret = pool.extract_array(data);
                data = nullptr;
                nr_ = 0;
                return ret;
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:

            T* data;
            long nr_;
            typename mem_manager::template rebind<T>::other pool;
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,4> : noncopyable // when num_rows != 0 && num_cols == 0
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ):data(0), nc_(0) { }

            ~layout ()
            { 
                if (data) 
                {
                    pool.deallocate_array(data);
                }
            }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[c*num_rows + r]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[c*num_rows + r]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                std::swap(item.nc_,nc_);
                pool.swap(item.pool);
            }

            long nr (
            ) const { return num_rows; }

            long nc (
            ) const { return nc_; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (data) 
                {
                    pool.deallocate_array(data);
                }
                data = pool.allocate_array(nr*nc);
                nc_ = nc;
            }

            std::unique_ptr<T[]> steal_memory()
            {
                auto ret = pool.extract_array(data);
                data = nullptr;
                nc_ = 0;
                return ret;
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

        private:

            T* data;
            long nc_;
            typename mem_manager::template rebind<T>::other pool;
        };

    // ------------------------------------------------------------------------------------

        template <
            typename T,
            long num_rows,
            long num_cols,
            typename mem_manager
            >
        class layout<T,num_rows,num_cols,mem_manager,5> : noncopyable // when num_rows == 0 && num_cols == 0
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ):data(0), nr_(0), nc_(0) { }

            ~layout ()
            { 
                if (data) 
                {
                    pool.deallocate_array(data);
                }
            }

            T& operator() (
                size_t r, 
                size_t c
            ) { return data[c*nr_ + r]; }

            const T& operator() (
                size_t r, 
                size_t c
            ) const { return data[c*nr_ + r]; }

            T& operator() (
                size_t i 
            ) { return data[i]; }

            const T& operator() (
                size_t i 
            ) const { return data[i]; }

            void swap(
                layout& item
            )
            {
                std::swap(item.data,data);
                std::swap(item.nc_,nc_);
                std::swap(item.nr_,nr_);
                pool.swap(item.pool);
            }

            void _private_set_mxArray ( mxArray* ) { IRECLIB_CASSERT(false, "This function should never be called."); }
            mxArray* _private_release_mxArray(){IRECLIB_CASSERT(false, "This function should never be called."); }
            void _private_mark_owned_by_matlab() {IRECLIB_CASSERT(false, "This function should never be called."); } 
            bool _private_is_owned_by_matlab() const { return false; }

            long nr (
            ) const { return nr_; }

            long nc (
            ) const { return nc_; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (data) 
                {
                    pool.deallocate_array(data);
                }
                data = pool.allocate_array(nr*nc);
                nr_ = nr;
                nc_ = nc;
            }

            std::unique_ptr<T[]> steal_memory()
            {
                auto ret = pool.extract_array(data);
                data = nullptr;
                nr_ = 0;
                nc_ = 0;
                return ret;
            }

        private:
            T* data;
            long nr_;
            long nc_;
            typename mem_manager::template rebind<T>::other pool;
        };

        template <
            long num_rows,
            long num_cols
            >
        class layout<double,num_rows,num_cols,default_memory_manager,5> : noncopyable // when num_rows == 0 && num_cols == 0
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ): data(0), nr_(0), nc_(0), owned_by_matlab(false),set_by_private_set_mxArray(false),mem(0) { }

            ~layout ()
            { 
                if (owned_by_matlab)
                {
                    if (!set_by_private_set_mxArray && mem) 
                    {
                        mxDestroyArray(mem); 
                        mem = 0;
                        data = 0;
                    }
                }
                else if (data)
                {
                    delete [] data;
                    data = 0;
                }
            }

            double& operator() (
                size_t r, 
                size_t c
            ) { return data[c*nr_ + r]; }

            const double& operator() (
                size_t r, 
                size_t c
            ) const { return data[c*nr_ + r]; }

            double& operator() (
                size_t i 
            ) { return data[i]; }

            const double& operator() (
                size_t i 
            ) const { return data[i]; }

            void _private_set_mxArray (
                mxArray* mem_
            )
            {
                IRECLIB_CASSERT(mem == 0 && data == 0,"You can't call this function on an already allocated matrix.");
                // We don't own the pointer, so make note of that so we won't try to free
                // it.
                set_by_private_set_mxArray = true;
                owned_by_matlab = true;
                mem = mem_;
                data = mxGetPr(mem);
                nr_ = mxGetM(mem);
                nc_ = mxGetN(mem);
            }

            mxArray* _private_release_mxArray()
            {
                IRECLIB_CASSERT(owned_by_matlab,"");
                mxArray* temp = mem;
                mem = 0;
                set_by_private_set_mxArray = false;
                data = 0;
                nr_ = 0;
                nc_ = 0;
                return temp;
            }

            void _private_mark_owned_by_matlab()
            {
                IRECLIB_CASSERT(mem == 0 && data == 0,"You can't say a matrix should be owned by matlab after it's been allocated.");
                owned_by_matlab = true;
            }
            bool _private_is_owned_by_matlab() const
            {
                return owned_by_matlab;
            }

            void swap(
                layout& item
            )
            {
                std::swap(item.owned_by_matlab,owned_by_matlab);
                std::swap(item.set_by_private_set_mxArray,set_by_private_set_mxArray);
                std::swap(item.mem,mem);
                std::swap(item.data,data);
                std::swap(item.nc_,nc_);
                std::swap(item.nr_,nr_);
            }

            long nr (
            ) const { return nr_; }

            long nc (
            ) const { return nc_; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (owned_by_matlab)
                {
                    if (!set_by_private_set_mxArray && mem) 
                    {
                        mxDestroyArray(mem); 
                        mem = 0;
                        data = 0;
                    }
                    set_by_private_set_mxArray = false;

                    mem = mxCreateDoubleMatrix(nr, nc, mxREAL);
                    if (mem == 0)
                        throw std::bad_alloc();
                    data = mxGetPr(mem);
                }
                else
                {
                    if (data)
                        delete [] data;
                    data = new double[nr*nc];
                }
                nr_ = nr;
                nc_ = nc;
            }

            std::unique_ptr<double[]> steal_memory()
            {
                IRECLIB_CASSERT(!owned_by_matlab, "You can't steal the memory from a matrix if it's owned by MATLAB.");
                std::unique_ptr<double[]> ret(data);
                data = nullptr;
                nr_ = 0;
                nc_ = 0;
                return ret;
            }

        private:
            double* data;
            long nr_;
            long nc_;
            bool owned_by_matlab;
            bool set_by_private_set_mxArray;
            mxArray* mem;
        };

        template <
            long num_rows,
            long num_cols
            >
        class layout<float,num_rows,num_cols,default_memory_manager,5> : noncopyable // when num_rows == 0 && num_cols == 0
        {
        public:
            const static long NR = num_rows;
            const static long NC = num_cols;

            layout (
            ): data(0), nr_(0), nc_(0), owned_by_matlab(false),set_by_private_set_mxArray(false),mem(0) { }

            ~layout ()
            { 
                if (owned_by_matlab)
                {
                    if (!set_by_private_set_mxArray && mem) 
                    {
                        mxDestroyArray(mem); 
                        mem = 0;
                        data = 0;
                    }
                }
                else if (data)
                {
                    delete [] data;
                    data = 0;
                }
            }

            float& operator() (
                size_t r, 
                size_t c
            ) { return data[c*nr_ + r]; }

            const float& operator() (
                size_t r, 
                size_t c
            ) const { return data[c*nr_ + r]; }

            float& operator() (
                size_t i 
            ) { return data[i]; }

            const float& operator() (
                size_t i 
            ) const { return data[i]; }

            void _private_set_mxArray (
                mxArray* mem_
            )
            {
                IRECLIB_CASSERT(mem == 0 && data == 0,"You can't call this function on an already allocated matrix.");
                // We don't own the pointer, so make note of that so we won't try to free
                // it.
                set_by_private_set_mxArray = true;
                owned_by_matlab = true;
                mem = mem_;
                data = (float*)mxGetData(mem);
                nr_ = mxGetM(mem);
                nc_ = mxGetN(mem);
            }

            mxArray* _private_release_mxArray()
            {
                IRECLIB_CASSERT(owned_by_matlab,"");
                mxArray* temp = mem;
                mem = 0;
                set_by_private_set_mxArray = false;
                data = 0;
                nr_ = 0;
                nc_ = 0;
                return temp;
            }

            void _private_mark_owned_by_matlab()
            {
                IRECLIB_CASSERT(mem == 0 && data == 0,"You can't say a matrix should be owned by matlab after it's been allocated.");
                owned_by_matlab = true;
            }
            bool _private_is_owned_by_matlab() const
            {
                return owned_by_matlab;
            }

            void swap(
                layout& item
            )
            {
                std::swap(item.owned_by_matlab,owned_by_matlab);
                std::swap(item.set_by_private_set_mxArray,set_by_private_set_mxArray);
                std::swap(item.mem,mem);
                std::swap(item.data,data);
                std::swap(item.nc_,nc_);
                std::swap(item.nr_,nr_);
            }

            long nr (
            ) const { return nr_; }

            long nc (
            ) const { return nc_; }

            void set_size (
                size_t nr,
                size_t nc
            )
            {
                if (owned_by_matlab)
                {
                    if (!set_by_private_set_mxArray && mem) 
                    {
                        mxDestroyArray(mem); 
                        mem = 0;
                        data = 0;
                    }
                    set_by_private_set_mxArray = false;

                    mem = mxCreateNumericMatrix(nr, nc, mxSINGLE_CLASS, mxREAL);
                    if (mem == 0)
                        throw std::bad_alloc();
                    data = (float*)mxGetData(mem);
                }
                else
                {
                    if (data)
                        delete [] data;
                    data = new float[nr*nc];
                }
                nr_ = nr;
                nc_ = nc;
            }

            std::unique_ptr<float[]> steal_memory()
            {
                IRECLIB_CASSERT(!owned_by_matlab, "You can't steal the memory from a matrix if it's owned by MATLAB.");
                std::unique_ptr<float[]> ret(data);
                data = nullptr;
                nr_ = 0;
                nc_ = 0;
                return ret;
            }

        private:
            float* data;
            long nr_;
            long nc_;
            bool owned_by_matlab;
            bool set_by_private_set_mxArray;
            mxArray* mem;
        };

    };

// ----------------------------------------------------------------------------------------

}



