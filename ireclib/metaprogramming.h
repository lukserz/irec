// Copyright (C) 2017  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{
// ----------------------------------------------------------------------------------------

    template <size_t... n>
    struct compile_time_integer_list 
    {
        /*!
            WHAT THIS OBJECT REPRESENTS
                The point of this type is to, as the name suggests, hold a compile time list of integers.
                As an example, here is something simple you could do with it:
                    template <size_t... ints>
                    void print_compile_time_ints (
                        compile_time_integer_list<ints...>
                    )
                    {
                        print(ints...);
                    }
                    int main()
                    {
                        print_compile_time_ints(compile_time_integer_list<0,4,9>());
                    }
                Which just calls: print(0,4,9);
                This is a simple example, but this kind of thing is useful in larger and
                more complex template metaprogramming constructs.
        !*/

        template <size_t m>
        struct push_back
        {
            typedef compile_time_integer_list<n..., m> type;
        };
    };

// ----------------------------------------------------------------------------------------

    template <size_t max>
    struct make_compile_time_integer_range
    {
        /*!
            WHAT THIS OBJECT REPRESENTS
                This object makes a compile_time_integer_list containing the integers in the range [1,max] inclusive.
                For example:
                    make_compile_time_integer_range<4>::type
                evaluates to:
                    compile_time_integer_list<1,2,3,4>
        !*/

        typedef typename make_compile_time_integer_range<max-1>::type::template push_back<max>::type type;
    };
    // base case
    template <> struct make_compile_time_integer_range<0> { typedef compile_time_integer_list<> type; };

// ----------------------------------------------------------------------------------------

    template <typename Funct, typename... Args>
    bool call_if_valid(Funct&& f, Args&&... args) 
    /*!
        ensures
            - if f(std::forward<Args>(args)...) is a valid expression then we evaluate it and return
              true.  Otherwise we do nothing and return false.
    !*/
    {
        return switch_(bools(is_invocable<Funct, Args...>{}),
            [&](true_t, auto _) {
                _(std::forward<Funct>(f))(std::forward<Args>(args)...);
                return true;
            },
            [](auto...) {
                return false;
            }
        );
    }

// ----------------------------------------------------------------------------------------

}



