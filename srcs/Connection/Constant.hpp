#ifndef CONSTANT_HPP
# define CONSTANT_HPP
# include <string>

namespace ft
{
	#define OK					200
	#define BAD_REQUEST			400
	#define NOT_FOUND			404
	#define VERSION_NOT_SUPPORT	505 // server connection number check
	#define SERVICE_UNAVAILABLE	503

	enum		METHODS
	{
		GET,
		HEAD,
		POST,
		PUT,
		DELETE,
		CONNECT,
		OPTIONS,
		TRACE
	};
	std::string	methods[8] = {
		"GET",
		"HEAD",
		"POST",
		"PUT",
		"DELETE",
		"CONNECT",
		"OPTIONS",
		"TRACE"
	};
} // namespace ft

#endif
