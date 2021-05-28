#ifndef REQUEST_INSPECT_HPP
# define REQUEST_INSPECT_HPP

# include "ParsedRequest.hpp"
# include <array>

class RequestInspect
{
	private:
		ParsedRequest				*_req;
		Config::node				*_serv_node;
		Config::node				*_loc_node;
		std::string					_root;
		std::string					_index;
		std::vector<std::string>	_allow_methods;

		RequestInspect();

		bool			isValidStart();
		bool			isValidType();
		bool			isValidPath();
		bool			isValidVersion();

		// bool			isValidContent();
		bool			isAllowedMethod();

		void			configRoot(Config::node* node_ptr);
		void			configMethod(Config::node* node_ptr);
	public:
		RequestInspect(const RequestInspect& copy);
		RequestInspect& operator=(const RequestInspect& obj);
		virtual ~RequestInspect();

		RequestInspect(ParsedRequest *req);

		bool				isValid();
};

#endif
