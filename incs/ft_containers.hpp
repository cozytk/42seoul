#ifndef FT_CONTAINERS_HPP
#define FT_CONTAINERS_HPP

/*
 * STD Library
 */

#include <memory>

/*
 * ft Library
 */

#include <Vector.hpp>
//#include <iterator.hpp>

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

#endif
