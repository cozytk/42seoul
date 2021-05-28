#ifndef REQUEST_INSPECT_HPP
# define REQUEST_INSPECT_HPP

# include "ParsedRequest.hpp"

class RequestInspect
{
	private:
		ParsedRequest *	_req;

		RequestInspect();

		bool			isValidStart();
		bool			isValidType();
		bool			isValidPath();
		bool			isValidVersion();

		// bool			isValidContent();
		bool			isAllowedMethod();
	public:
		RequestInspect(const RequestInspect& copy);
		RequestInspect& operator=(const RequestInspect& obj);
		virtual ~RequestInspect();

		RequestInspect(ParsedRequest *req);

		bool				isValid();
};

#endif
