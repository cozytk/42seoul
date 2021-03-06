#ifndef REQUEST_INSPECT_HPP
# define REQUEST_INSPECT_HPP

#include "RequestConfig.hpp"

class RequestInspect
{
	private:
		ParsedRequest	*_req;

		RequestInspect();
		bool			isValidType();
		bool			isValidPath();
		bool			isValidVersion();

		bool			isAllowedMethod();
		bool			isExistResource(std::string path, std::string index);
		bool			isAuthorized();
		bool			isValidSize();
		bool			isRedirect();
	public:
		RequestInspect(const RequestInspect& copy);
		RequestInspect(RequestConfig con);
		RequestInspect(ParsedRequest *req);
		RequestInspect& operator=(const RequestInspect& obj);
		virtual ~RequestInspect();

		bool				isValid();
		RequestConfig const	&getConfig();
};

#endif
